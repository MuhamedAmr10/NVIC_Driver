/******************************************************************************
 *
 * Module: NVIC
 *
 * File Name: NVIC.h
 *
 * Description: Header file for the ARM Cortex M4 NVIC driver
 *
 * Author: Mohamed Tarek (Edges For Training)
 *
 *******************************************************************************/

#ifndef NVIC_H_
#define NVIC_H_

/*******************************************************************************
 *                                Inclusions                                   *
 *******************************************************************************/
#include "std_types.h"

/*******************************************************************************
 *                           Preprocessor Definitions                          *
 *******************************************************************************/

#define MEM_FAULT_PRIORITY_MASK              0x000000E0
#define MEM_FAULT_PRIORITY_BITS_POS          5

#define BUS_FAULT_PRIORITY_MASK              0x0000E000
#define BUS_FAULT_PRIORITY_BITS_POS          13

#define USAGE_FAULT_PRIORITY_MASK            0x00E00000
#define USAGE_FAULT_PRIORITY_BITS_POS        21

#define SVC_PRIORITY_MASK                    0xE0000000
#define SVC_PRIORITY_BITS_POS                29

#define DEBUG_MONITOR_PRIORITY_MASK          0x000000E0
#define DEBUG_MONITOR_PRIORITY_BITS_POS      5

#define PENDSV_PRIORITY_MASK                 0x00E00000
#define PENDSV_PRIORITY_BITS_POS             21

#define SYSTICK_PRIORITY_MASK                0xE0000000
#define SYSTICK_PRIORITY_BITS_POS            29

#define MEM_FAULT_ENABLE_MASK                0x00010000
#define BUS_FAULT_ENABLE_MASK                0x00020000
#define USAGE_FAULT_ENABLE_MASK              0x00040000
#define DEBUG_MONITOR_ENABLE_MASK            0x00010000






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
typedef uint8 NVIC_IRQType;

typedef uint8 NVIC_IRQPriorityType;

typedef enum
{
    EXCEPTION_RESET_TYPE,
    EXCEPTION_NMI_TYPE,
    EXCEPTION_HARD_FAULT_TYPE,
    EXCEPTION_MEM_FAULT_TYPE,
    EXCEPTION_BUS_FAULT_TYPE,
    EXCEPTION_USAGE_FAULT_TYPE,
    EXCEPTION_SVC_TYPE,
    EXCEPTION_DEBUG_MONITOR_TYPE,
    EXCEPTION_PEND_SV_TYPE,
    EXCEPTION_SYSTICK_TYPE
}NVIC_ExceptionType;

typedef uint8 NVIC_ExceptionPriorityType;



/*************************************************************************************
* Service Name   : NVIC_EnableIRQ
* Parameters (in): IRQ_Num - Number of the IRQ from the target vector table
* Description    : Enables Interrupt request for a specific IRQ
**************************************************************************************/
extern void NVIC_EnableIRQ(NVIC_IRQType IRQ_Num);

/*************************************************************************************
* Service Name   : NVIC_DisableIRQ
* Parameters (in): IRQ_Num - Number of the IRQ from the target vector table
* Description    : Disables Interrupt request for a specific IRQ
**************************************************************************************/
extern void NVIC_DisableIRQ(NVIC_IRQType IRQ_Num);

/*************************************************************************************
* Service Name   : NVIC_SetPriorityIRQ
* Parameters (in): IRQ_Num - Number of the IRQ from the target vector table , IRQ_Priority Number of the priority from the target
* Description    : Set a priority  for a specific IRQ
**************************************************************************************/
extern void NVIC_SetPriorityIRQ(NVIC_IRQType IRQ_Num, NVIC_IRQPriorityType IRQ_Priority);


/*************************************************************************************
* Service Name   : NVIC_EnableException
* Parameters (in): Exception_Num - Number of the Exception Reserved for ARM
* Description    : Enables Exception request for a specific Exception
**************************************************************************************/
extern void NVIC_EnableException(NVIC_ExceptionType Exception_Num);

/*************************************************************************************
* Service Name   : NVIC_DisableException
* Parameters (in): Exception_Num - Number of the Exception Reserved for ARM
* Description    : Disables Exception request for a specific Exception
**************************************************************************************/
extern void NVIC_DisableException(NVIC_ExceptionType Exception_Num);

/*************************************************************************************
* Service Name   : NVIC_SetPriorityException
* Parameters (in): Exception_Num - Number of the Exception Reserved for ARM , Exception_Priority Number of the priority from the target
* Description    : Set a priority  for a specific Exception
**************************************************************************************/
extern void NVIC_SetPriorityException(NVIC_ExceptionType Exception_Num, NVIC_ExceptionPriorityType Exception_Priority);



/************************************************************************************
 *                                 End of File                                      *
 ************************************************************************************/

#endif /* NVIC_H_ */
