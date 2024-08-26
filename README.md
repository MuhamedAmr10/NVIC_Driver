# NVIC-Driver for Tiva C Series
The NVIC-Driver for Tiva C Series is a software library designed to facilitate the configuration and management of the Nested Vectored Interrupt Controller (NVIC) in Tiva C Series microcontrollers. This driver provides a straightforward interface to handle interrupts and exceptions efficiently.

# Features
- Interrupt Handling: Easy configuration and management of interrupts.
- Priority Management: Control interrupt priorities with precision.
- Exception Handling: Simplified handling of exceptions and faults.
- Optimized Performance: Efficient low-level access to NVIC registers.

# Table of Contents
- ##### Features
- ##### Getting Started
- ##### Installation
- ##### Usage
- ##### License
- ##### Contact

# Getting Started
To get started with the NVIC-Driver for Tiva C Series, you'll need:
- Tiva C Series Microcontroller: [TM4C123GH6PM]
- Development Environment: [e.g., TI's Code Composer Studio, Keil uVision, etc.]
- Toolchain: [Code Composer Studio (CCS), TivaWare SDK , Compatible Compiler and Linker Tools]

# Usage
###### Here is a basic example of how to use the NVIC-Driver:

<pre style="background-color: #f4f4f4; padding: 10px; border-radius: 5px;">
<code>
<span style="color: #d14;">#include</span> <span style="color: #008000;">"tm4c123gh6pm_registers.h"</span>
<span style="color: #d14;">#include</span> <span style="color: #008000;">"nvic_driver.h"</span>


#define NVIC_ISQ_NUM 30

int main(void)
{
  NVIC_EnableIRQ(NVIC_ISQ_NUM); // you can choose IRQ Num form 0 to 138
  NVIC_SetPriorityIRQ(NVIC_ISQ_NUM , 7); // you can choose IRQ priority value form 0 to 7

/*
 code
*/
}

<code> 
</pre>

