/******************************************************************************
 *
 * Module: SysTick
 *
 * File Name: SYSTICK.h
 *
 * Description: Header file for the ARM Cortex M4 SysTick driver
 *
 * Author: Muhamed Amr
 *
 *******************************************************************************/

#ifndef SYSTICK_H_
#define SYSTICK_H_

/*******************************************************************************
 *                                Inclusions                                   *
 *******************************************************************************/
#include "std_types.h"

/*******************************************************************************
 *                           Preprocessor Definitions                          *
 *******************************************************************************/

#define F_CPU                             16000000UL

#define SYSTICK_COUNT_BIT_MASK            0x10000

#define SYSTICK_CLK_SRC_MASK              0x4
#define SYSTICK_INTERRUPT_ENABLE_MASK     0x2
#define SYSTICK_TIMER_ENABLE_MASK         0x1









/* Enable Exceptions ... This Macro enable IRQ interrupts, Programmable Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Enable_Exceptions()    __asm(" CPSIE I ")

/* Disable Exceptions ... This Macro disable IRQ interrupts, Programmable Systems Exceptions and Faults by setting the I-bit in the PRIMASK. */
#define Disable_Exceptions()   __asm(" CPSID I ")

/* Enable Faults ... This Macro enable Faults by clearing the F-bit in the FAULTMASK */
#define Enable_Faults()        __asm(" CPSIE F ")

/* Disable Faults ... This Macro disable Faults by setting the F-bit in the FAULTMASK */
#define Disable_Faults()       __asm(" CPSID F ")


/*******************************************************************************
 *                           Data Types Declarations                           *
 *******************************************************************************/



/*************************************************************************************
* Service Name   : SysTick_Init
* Parameters (in): a_TimeInMilliSeconds - Number of the IRQ from the target vector table
* Description    : Initialize Systick
**************************************************************************************/
extern void SysTick_Init(uint16 a_TimeInMilliSeconds);

extern void SysTick_StartBusyWait(uint16 a_TimeInMilliSeconds);

extern void SysTick_Handler(void);

extern void SysTick_SetCallBack(volatile void (*Ptr2Func) (void));

extern void SysTick_Stop(void);

extern void SysTick_Start(void);

extern void SysTick_DeInit(void);


#endif /* SYSTICK_H_ */
