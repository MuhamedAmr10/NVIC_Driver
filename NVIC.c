/*
 * NVIC.c
 *
 *  Created on: Jul 27, 2024
 *      Author: Muhamed Amr
 */

/*******************************************************************************
 *                                Inclusions                                   *
 *******************************************************************************/
#include "tm4c123gh6pm_registers.h"
#include "NVIC.h"




/*************************************************************************************
* Service Name      : NVIC_EnableIRQ
* Sync/Async        : Synchronous
* Reentrancy        : reentrant
* Parameters (in)   : IRQ_Num - Number of the IRQ from the target vector table
* Parameters (inout): None
* Parameters (out)  : None
* Return value      : None
* Description       : Function to Enables Interrupt request for a specific IRQ
**************************************************************************************/
extern void NVIC_EnableIRQ(NVIC_IRQType IRQ_Num)
{
    if(IRQ_Num <=31)
    {
        NVIC_EN0_REG |= (1 << IRQ_Num);
    }
    else if ((IRQ_Num > 31) && (IRQ_Num <=63))
    {
        IRQ_Num -=31;
        NVIC_EN1_REG |= (1 << IRQ_Num);
    }
    else if ((IRQ_Num > 63) && (IRQ_Num <=95))
    {
        IRQ_Num -=63;
        NVIC_EN2_REG |= (1 << IRQ_Num);
    }
    else if ((IRQ_Num > 95) && (IRQ_Num <=127))
    {
        IRQ_Num -=95;
        NVIC_EN3_REG |= (1 << IRQ_Num);
    }
    else if ((IRQ_Num > 127) && (IRQ_Num <=138))
    {
        IRQ_Num -=127;
        NVIC_EN4_REG |= (1 << IRQ_Num);
    }
    else
    {
        /* Report an Error*/
    }
}

/*************************************************************************************
* Service Name      : NVIC_DisableIRQ
* Sync/Async        : Synchronous
* Reentrancy        : reentrant
* Parameters (in)   : IRQ_Num - Number of the IRQ from the target vector table
* Parameters (inout): None
* Parameters (out)  : None
* Return value      : None
* Description       : Function to Disables Interrupt request for a specific IRQ
**************************************************************************************/
extern void NVIC_DisableIRQ(NVIC_IRQType IRQ_Num)
{
    if(IRQ_Num <=31)
       {
           NVIC_DIS0_REG |= (1 << IRQ_Num);
       }
       else if ((IRQ_Num > 31) && (IRQ_Num <=63))
       {
           IRQ_Num -=31;
           NVIC_DIS1_REG |= (1 << IRQ_Num);
       }
       else if ((IRQ_Num > 63) && (IRQ_Num <=95))
       {
           IRQ_Num -=63;
           NVIC_DIS2_REG |= (1 << IRQ_Num);
       }
       else if ((IRQ_Num > 95) && (IRQ_Num <=127))
       {
           IRQ_Num -=95;
           NVIC_DIS3_REG |= (1 << IRQ_Num);
       }
       else if ((IRQ_Num > 127) && (IRQ_Num <=138))
       {
           IRQ_Num -=127;
           NVIC_DIS4_REG |= (1 << IRQ_Num);
       }
       else
       {
           /* Report an Error*/
       }

  
}

/*************************************************************************************
* Service Name      : NVIC_SetPriorityIRQ
* Sync/Async        : Synchronous
* Reentrancy        : reentrant
* Parameters (in)   : IRQ_Num - Number of the IRQ from the target vector table , IRQ_Priority Number of the priority from the target
* Parameters (inout): None
* Parameters (out)  : None
* Return value      : None
* Description       : Set priority for a specific IRQ
**************************************************************************************/
extern void NVIC_SetPriorityIRQ(NVIC_IRQType IRQ_Num, NVIC_IRQPriorityType IRQ_Priority)
{
    if((IRQ_Num <=138)&&(IRQ_Priority <= 7))
    {
        volatile uint32 * Priority_Register_Pointer = ((volatile uint32 *)0xE000E400); /* Initialize pointer points to NVIC_PRIORITY_REG Base Address */
        uint8 Priority_Register_Num = (IRQ_Num / 4); /* Calculate Priority Register number */
        uint8 Priority_IRQ_Pos      = (IRQ_Num % 4)*8 + 5; /* Calculate IRQ position in Register */

        Priority_Register_Pointer  += Priority_Register_Num; /* Increment the pointer by Priority Register number(offset)  */
        *Priority_Register_Pointer  &= ~(7 << Priority_IRQ_Pos); /* Clear priority for desired IRQ */
        *Priority_Register_Pointer  |= (IRQ_Priority << Priority_IRQ_Pos); /* Set the priority for the desired IRQ */
    }
    else
    {
        /* Report an Error */
    }
}


/*************************************************************************************
* Service Name      : NVIC_EnableException
* Sync/Async        : Synchronous
* Reentrancy        : Reentrant
* Parameters (in)   : Exception_Num - Number of the Exception Reserved for ARM
* Parameters (inout): None
* Parameters (out)  : None
* Return value      : None
* Description       : Enables Exception request for a specific Exception
**************************************************************************************/
extern void NVIC_EnableException(NVIC_ExceptionType Exception_Num)
{
    switch(Exception_Num)
    {
    case EXCEPTION_RESET_TYPE         : break;
    case EXCEPTION_NMI_TYPE           : break;
    case EXCEPTION_SVC_TYPE           : break;
    case EXCEPTION_HARD_FAULT_TYPE    : break;
    case EXCEPTION_PEND_SV_TYPE       : break;
    case EXCEPTION_SYSTICK_TYPE       : break;
    case EXCEPTION_BUS_FAULT_TYPE     : NVIC_SYSTEM_SYSHNDCTRL |= BUS_FAULT_ENABLE_MASK;   break;
    case EXCEPTION_USAGE_FAULT_TYPE   : NVIC_SYSTEM_SYSHNDCTRL |= USAGE_FAULT_ENABLE_MASK; break;
    case EXCEPTION_MEM_FAULT_TYPE     : NVIC_SYSTEM_SYSHNDCTRL |= MEM_FAULT_ENABLE_MASK;   break;
    case EXCEPTION_DEBUG_MONITOR_TYPE : break;
    default                           : break; /* Report an Error */
    }
}

/*************************************************************************************
* Service Name      : NVIC_DisableException
* Sync/Async        : Synchronous
* Reentrancy        : Reentrant
* Parameters (in)   : Exception_Num - Number of the Exception Reserved for ARM
* Parameters (inout): None
* Parameters (out)  : None
* Return value      : None
* Description       : Disables Exception request for a specific Exception
**************************************************************************************/
extern void NVIC_DisableException(NVIC_ExceptionType Exception_Num)
{
    switch(Exception_Num)
    {
    case EXCEPTION_RESET_TYPE         : break;
    case EXCEPTION_NMI_TYPE           : break;
    case EXCEPTION_SVC_TYPE           : break;
    case EXCEPTION_HARD_FAULT_TYPE    : break;
    case EXCEPTION_PEND_SV_TYPE       : break;
    case EXCEPTION_SYSTICK_TYPE       : break;
    case EXCEPTION_BUS_FAULT_TYPE     : NVIC_SYSTEM_SYSHNDCTRL &= ~BUS_FAULT_ENABLE_MASK;   break;
    case EXCEPTION_USAGE_FAULT_TYPE   : NVIC_SYSTEM_SYSHNDCTRL &= ~USAGE_FAULT_ENABLE_MASK; break;
    case EXCEPTION_MEM_FAULT_TYPE     : NVIC_SYSTEM_SYSHNDCTRL &= ~MEM_FAULT_ENABLE_MASK;   break;
    case EXCEPTION_DEBUG_MONITOR_TYPE : break;
    default                           : break;
    }
}

/*************************************************************************************
* Service Name      : NVIC_SetPriorityException
* Sync/Async        : Synchronous
* Reentrancy        : Reentrant
* Parameters (in)   : Exception_Num - Number of the Exception Reserved for ARM , Exception_Priority - Number of the priority from the target
* Parameters (inout): None
* Parameters (out)  : None
* Return value      : None
* Description       : Set a priority  for a specific Exception
**************************************************************************************/
extern void NVIC_SetPriorityException(NVIC_ExceptionType Exception_Num, NVIC_ExceptionPriorityType Exception_Priority)
{
    switch(Exception_Num)
    {
    case EXCEPTION_SVC_TYPE           : NVIC_SYSTEM_PRI2_REG = (NVIC_SYSTEM_PRI2_REG & SVC_PRIORITY_MASK)           | (Exception_Priority << SVC_PRIORITY_BITS_POS);break;
    case EXCEPTION_PEND_SV_TYPE       : NVIC_SYSTEM_PRI3_REG = (NVIC_SYSTEM_PRI3_REG & PENDSV_PRIORITY_MASK)        | (Exception_Priority << PENDSV_PRIORITY_BITS_POS);break;
    case EXCEPTION_SYSTICK_TYPE       : NVIC_SYSTEM_PRI3_REG = (NVIC_SYSTEM_PRI3_REG & SYSTICK_PRIORITY_MASK)       | (Exception_Priority << SYSTICK_PRIORITY_BITS_POS);break;
    case EXCEPTION_BUS_FAULT_TYPE     : NVIC_SYSTEM_PRI1_REG = (NVIC_SYSTEM_PRI1_REG & BUS_FAULT_PRIORITY_MASK)     | (Exception_Priority << BUS_FAULT_PRIORITY_BITS_POS);break;
    case EXCEPTION_USAGE_FAULT_TYPE   : NVIC_SYSTEM_PRI1_REG = (NVIC_SYSTEM_PRI1_REG & USAGE_FAULT_PRIORITY_MASK)   | (Exception_Priority << USAGE_FAULT_PRIORITY_BITS_POS);break;
    case EXCEPTION_MEM_FAULT_TYPE     : NVIC_SYSTEM_PRI1_REG = (NVIC_SYSTEM_PRI1_REG & MEM_FAULT_PRIORITY_MASK)     | (Exception_Priority << MEM_FAULT_PRIORITY_BITS_POS);break;
    case EXCEPTION_DEBUG_MONITOR_TYPE : NVIC_SYSTEM_PRI3_REG = (NVIC_SYSTEM_PRI3_REG & DEBUG_MONITOR_PRIORITY_MASK) | (Exception_Priority << DEBUG_MONITOR_PRIORITY_BITS_POS);break;
    default                           : break;
    }
}
