/*
 * SYSTICK.c
 *
 *  Created on: Jul 29, 2024
 *      Author: Muhamed Amr
 */

#include "tm4c123gh6pm_registers.h"
#include "SYSTICK.h"

static volatile uint32 SysTick_OVF_Count = 0; 
static volatile uint32 SysTick_Reload_Value = 0;
static volatile void (*UserFunctionOVF)(void) = NULL_PTR;


/*************************************************************************************
* Service Name      : SysTick_Init
* Sync/Async        : Synchronous
* Reentrancy        : Unreentrant
* Parameters (in)   : a_TimeInMilliSeconds - User desired time in milli-second
* Parameters (inout): None
* Parameters (out)  : None
* Return value      : None
* Description       : Initialize the SysTick timer with the specified time in milliseconds using interrupts.
**************************************************************************************/
void SysTick_Init(uint16 a_TimeInMilliSeconds)
{
    float32 Tick_Time ;
    float32 OVFTime;

    SYSTICK_CTRL_REG    = 0; /* Disable the SysTick Timer by Clear the ENABLE Bit */

    Tick_Time = (float32)1/F_CPU; /* The time required for one pulse */
    OVFTime   = Tick_Time * 16777216;  /* The time required for SysTick counter to overflow */


    SysTick_OVF_Count = ((float32)a_TimeInMilliSeconds / 1000) / OVFTime; /* The number of times the counter is repeated to obtain the desired time  */
    SysTick_Reload_Value = (a_TimeInMilliSeconds % ((uint32)(OVFTime * 1000))) / (Tick_Time * 1000); /* The value to be set in Reload register to obtain desired time*/


    SYSTICK_RELOAD_REG  =  SysTick_Reload_Value; /* Set Reload Value in SYSTICK_RELOAD_REG */
    SYSTICK_CURRENT_REG =  0 ;/* Clear the Current Register value */

       /* Configure the SysTick Control Register
        * Enable SysTick Interrupt (INTEN = 1)
        * Choose the clock source to be System Clock (CLK_SRC = 1) 
        * Enable SysTick Timer */
    SYSTICK_CTRL_REG   |= SYSTICK_CLK_SRC_MASK | SYSTICK_INTERRUPT_ENABLE_MASK |SYSTICK_TIMER_ENABLE_MASK ;
}

/*************************************************************************************
* Service Name      : SysTick_StartBusyWait
* Sync/Async        : Synchronous
* Reentrancy        : Unreentrant
* Parameters (in)   : Ia_TimeInMilliSeconds - User desired time in milli-second 
* Parameters (inout): None
* Parameters (out)  : None
* Return value      : None
* Description       : initialize the SysTick timer with the specified time in milliseconds using polling or busy-wait technique.
**************************************************************************************/
void SysTick_StartBusyWait(uint16 a_TimeInMilliSeconds)
{
    float32 Tick_Time;
    float32 OVFTime;

    uint16 Counter =0;

    SYSTICK_CTRL_REG    = 0; /* Disable the SysTick Timer by Clear the ENABLE Bit */

    Tick_Time = (float32)1/F_CPU; /* The time required for one pulse */
    OVFTime   = Tick_Time * 16777216;   /* The time required for SysTick counter to overflow */
    SysTick_OVF_Count = ((float32)a_TimeInMilliSeconds / 1000) / OVFTime; /* The number of times the counter is repeated to obtain the desired time  */
    SysTick_Reload_Value = (a_TimeInMilliSeconds % ((uint32)(OVFTime * 1000))) / (Tick_Time * 1000) ; /* The value to be set in Reload register to obtain desired time*/


    SYSTICK_RELOAD_REG  =  SysTick_Reload_Value; /* Set Reload Value in SYSTICK_RELOAD_REG */
    SYSTICK_CURRENT_REG =  0; /* Clear the Current Register value */


    /* Configure the SysTick Control Register
     * Disable SysTick Interrupt (INTEN = 0)
     * Choose the clock source to be System Clock (CLK_SRC = 1)
     * Enable SysTick Timer  */
    SYSTICK_CTRL_REG    = (SYSTICK_CTRL_REG & ~SYSTICK_INTERRUPT_ENABLE_MASK) | SYSTICK_CLK_SRC_MASK | SYSTICK_INTERRUPT_ENABLE_MASK ;

    while(Counter != SysTick_OVF_Count + 1)
    {
        if(0 != (SYSTICK_CTRL_REG & (1<<16)))
        {
            Counter++;
        }
    }
    SYSTICK_CTRL_REG = 0; /* Stop SysTick by disable it */
}


/*************************************************************************************
* Service Name      : SysTick_Handler
* Sync/Async        : Asynchronous
* Reentrancy        : Unreentrant
* Parameters (in)   : None
* Parameters (inout): None
* Parameters (out)  : None
* Return value      : None
* Description       : Handler for SysTick interrupt use to call the call-back function.
**************************************************************************************/
void SysTick_Handler(void)
{
    static volatile uint16 Counter = 0;
    Counter++;
    if(Counter == SysTick_OVF_Count + 1)
    {
        SYSTICK_CURRENT_REG = 0; /* Clearing SYSTICK_CURRENT_REG as writing any value to this register clear it */
        SYSTICK_RELOAD_REG  =  SysTick_Reload_Value; /* Reset Reload Value */
        Counter = 0; /* Reset Counter value */
        if(UserFunctionOVF != NULL_PTR)
        {
            (*UserFunctionOVF)(); /* Call User Function */
        }
        else
        {
            /* Do nothig*/
        }
    }

}

/*************************************************************************************
* Service Name      : SysTick_SetCallBack
* Sync/Async        : Synchronous
* Reentrancy        : Unreentrant
* Parameters (in)   : Ptr2Func - The Pointer to function that will be executed in SysTick Handler 
* Parameters (inout): None
* Parameters (out)  : None
* Return value      : None
* Description       : Function to setup the SysTick Timer call back to be executed in SysTick Handler
**************************************************************************************/

void SysTick_SetCallBack(volatile void (*Ptr2Func) (void))
{
    UserFunctionOVF = Ptr2Func;

}

/*************************************************************************************
* Service Name      : SysTick_Stop
* Sync/Async        : Synchronous
* Reentrancy        : Reentrant
* Parameters (in)   : None 
* Parameters (inout): None
* Parameters (out)  : None
* Return value      : None
* Description       : Stop the SysTick timer.
**************************************************************************************/
void SysTick_Stop(void)
{
    SYSTICK_CTRL_REG &= ~(SYSTICK_TIMER_ENABLE_MASK); /* Disable SysTick Timer */
}

/*************************************************************************************
* Service Name      : SysTick_Start
* Sync/Async        : Synchronous
* Reentrancy        : Reentrant
* Parameters (in)   : None 
* Parameters (inout): None
* Parameters (out)  : None
* Return value      : None
* Description       : Start/Resume the SysTick timer.
**************************************************************************************/
void SysTick_Start(void)
{
    SYSTICK_CTRL_REG |= SYSTICK_TIMER_ENABLE_MASK; /* Enable SysTick Timer */
}

/*************************************************************************************
* Service Name      : SysTick_DeInit
* Sync/Async        : Synchronous
* Reentrancy        : Reentrant
* Parameters (in)   : None 
* Parameters (inout): None
* Parameters (out)  : None
* Return value      : None
* Description       : Function to De-initialize the SysTick Timer.
**************************************************************************************/
void SysTick_DeInit(void)
{
    SYSTICK_CTRL_REG    = 0; /* Clear CTRL_REG */
    SYSTICK_CURRENT_REG = 0; /* Clear SysTick Counter value */
    UserFunctionOVF=NULL_PTR; /* Clear call back function */
}

