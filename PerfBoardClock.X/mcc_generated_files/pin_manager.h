/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16LF1826
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SRC_OE aliases
#define SRC_OE_TRIS                 TRISAbits.TRISA0
#define SRC_OE_LAT                  LATAbits.LATA0
#define SRC_OE_PORT                 PORTAbits.RA0
#define SRC_OE_ANS                  ANSELAbits.ANSA0
#define SRC_OE_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SRC_OE_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SRC_OE_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SRC_OE_GetValue()           PORTAbits.RA0
#define SRC_OE_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SRC_OE_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SRC_OE_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define SRC_OE_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set SRC_RCLK aliases
#define SRC_RCLK_TRIS                 TRISAbits.TRISA1
#define SRC_RCLK_LAT                  LATAbits.LATA1
#define SRC_RCLK_PORT                 PORTAbits.RA1
#define SRC_RCLK_ANS                  ANSELAbits.ANSA1
#define SRC_RCLK_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define SRC_RCLK_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define SRC_RCLK_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define SRC_RCLK_GetValue()           PORTAbits.RA1
#define SRC_RCLK_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define SRC_RCLK_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define SRC_RCLK_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define SRC_RCLK_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set TIM0 aliases
#define TIM0_TRIS                 TRISAbits.TRISA4
#define TIM0_LAT                  LATAbits.LATA4
#define TIM0_PORT                 PORTAbits.RA4
#define TIM0_ANS                  ANSELAbits.ANSA4
#define TIM0_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define TIM0_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define TIM0_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define TIM0_GetValue()           PORTAbits.RA4
#define TIM0_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define TIM0_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define TIM0_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define TIM0_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set SNK_OE aliases
#define SNK_OE_TRIS                 TRISAbits.TRISA6
#define SNK_OE_LAT                  LATAbits.LATA6
#define SNK_OE_PORT                 PORTAbits.RA6
#define SNK_OE_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define SNK_OE_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define SNK_OE_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define SNK_OE_GetValue()           PORTAbits.RA6
#define SNK_OE_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define SNK_OE_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)

// get/set SNK_LE aliases
#define SNK_LE_TRIS                 TRISAbits.TRISA7
#define SNK_LE_LAT                  LATAbits.LATA7
#define SNK_LE_PORT                 PORTAbits.RA7
#define SNK_LE_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define SNK_LE_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define SNK_LE_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define SNK_LE_GetValue()           PORTAbits.RA7
#define SNK_LE_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define SNK_LE_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/