# NVIC-Driver for Tiva C Series
The NVIC-Driver for Tiva C Series is a software library designed to facilitate the configuration and management of the Nested Vectored Interrupt Controller (NVIC) in Tiva C Series microcontrollers. This driver provides a straightforward interface to handle interrupts and exceptions efficiently.

# Features



- **Interrupt Handling**    : Easy configuration and management of interrupts.
- **Priority Management**   : Control interrupt priorities with precision.
- **Exception Handling**    : Simplified handling of exceptions and faults.
- **Optimized Performance** : Efficient low-level access to NVIC registers.
- **Unit Testing**          : Verify that each unit of the driver performs correctly 


# Table of Contents
- ##### Features
- ##### Getting Started
- ##### Installation
- ##### API Reference
- ##### Usage
- ##### License
- ##### Contact

# Getting Started
To get started with the NVIC-Driver for Tiva C Series, you'll need:
- Tiva C Series Microcontroller: [TM4C123GH6PM]
- Development Environment: [e.g., TI's Code Composer Studio, Keil uVision, etc.]
- Toolchain: [Code Composer Studio (CCS), TivaWare SDK , Compatible Compiler and Linker Tools]

# API Reference
### Enable Interrupt/Exception
```
NVIC_EnableIRQ(NVIC_IRQType IRQ_Num);
NVIC_EnableException(NVIC_ExceptionType Exception_Num);
```
Enable a specific interrupt/Exception.
###### Parameters:
- **IRQ_Num** : The interrupt number to enable
- **Exception_Num** : The Exception number to enable

  
### Disable Interrupt/Exception
```
NVIC_DisableIRQ(NVIC_IRQType IRQ_Num);
NVIC_DisableException(NVIC_ExceptionType Exception_Num);
```
Disable a specific interrupt/Exception.
###### Parameters:
- **IRQ_Num** : The interrupt number to disable
- **Exception_Num** : The Exception number to disable

### Set Priority Interrupt/Exception
```
NVIC_SetPriorityIRQ(NVIC_IRQType IRQ_Num, NVIC_IRQPriorityType IRQ_Priority);
NVIC_SetPriorityException(NVIC_ExceptionType Exception_Num, NVIC_ExceptionPriorityType Exception_Priority);
```
Set a specific interrupt/Exception priority.
###### Parameters:
- **IRQ_Num** : The interrupt number
- **IRQ_Priority** : The priority value for IRQ  
- **Exception_Num** : The Exception number
- **Exception_Priority** : The priority value for Exception  

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

# License
This project is licensed under Edges for trainning - see the [LICENSE](https://drive.google.com/file/d/18jCrTpFFtlCLnNwZPi9EXOUJyDeH7DTe/view?usp=drive_link) file for details.
# Contact
For any questions, feedback, or support requests, please contact us:
- **Email**: [support@example.com](muhamedamrrr@gmail.com)
- **GitHub Issues**: [Submit an issue](https://github.com/MuhamedAmr10/NVIC_Driver/issues)



