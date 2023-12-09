/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16LF1826
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include <xc.h>

// Variables

// Functions

void main() {
    // initialize the device
    SYSTEM_Initialize();
    // Initialize EUSART
    EUSART_Initialize();
    // Initialize Timer
    TMR1_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    // Start Timer 1
//    TMR1_StartTimer();
    
//    // Access Line test
//    while (1) {
//        while(1){
//        SNK_OE_SetHigh();
//        EUSART_Write(0x80); // Send Access Line Data
//        while(!EUSART_is_tx_done()); // Wait for data to finish sending
//        // Latch in Data
//        SNK_LE_SetHigh();
//        __delay_us(100);
//        SNK_LE_SetLow();
//        //Enable Register Output
//        SNK_OE_SetLow();
//        __delay_us(1000000);
//
//        SNK_OE_SetHigh();
//        EUSART_Write(0x40); // Send Access Line Data
//        while(!EUSART_is_tx_done()); // Wait for data to finish sending
//        // Latch in Data
//        SNK_LE_SetHigh();
//        __delay_us(100);
//        SNK_LE_SetLow();
//        //Enable Register Output
//        SNK_OE_SetLow();
//        __delay_us(1000000);
//        
//        SNK_OE_SetHigh();
//        EUSART_Write(0x20); // Send Access Line Data
//        while(!EUSART_is_tx_done()); // Wait for data to finish sending
//        // Latch in Data
//        SNK_LE_SetHigh();
//        __delay_us(100);
//        SNK_LE_SetLow();
//        //Enable Register Output
//        SNK_OE_SetLow();
//        __delay_us(1000000);
//        }
    
    // Matrix test
    while (1) {
        while(1){
        // SRC Reg Test
        SRC_OE_SetHigh();
        SNK_OE_SetHigh();
        EUSART_Write(0x20); // Send Access Line Data
        while(!EUSART_is_tx_done()); // Wait for data to finish sending
        __delay_us(100);
        EUSART_Write(0xE0); // Send Common Line Data
        while(!EUSART_is_tx_done()); // Wait for data to finish sending
        // Latch in Data
        SRC_RCLK_SetHigh();
        SNK_LE_SetHigh();
        __delay_us(100);
        SRC_RCLK_SetLow();
        SNK_LE_SetLow();
        //Enable Register Output
        SRC_OE_SetLow();
        SNK_OE_SetLow();
        __delay_us(100);
        
        SRC_OE_SetHigh();
        SNK_OE_SetHigh();
        EUSART_Write(0x40); // Send Access Line Data
        while(!EUSART_is_tx_done()); // Wait for data to finish sending
        __delay_us(100);
        EUSART_Write(0x40); // Send Common Line Data
        while(!EUSART_is_tx_done()); // Wait for data to finish sending
        // Latch in Data
        SRC_RCLK_SetHigh();
        SNK_LE_SetHigh();
        __delay_us(100);
        SRC_RCLK_SetLow();
        SNK_LE_SetLow();
        //Enable Register Output
        SRC_OE_SetLow();
        SNK_OE_SetLow();
        __delay_us(100);
        
        SRC_OE_SetHigh();
        SNK_OE_SetHigh();
        EUSART_Write(0x80); // Send Access Line Data
        while(!EUSART_is_tx_done()); // Wait for data to finish sending
        __delay_us(100);
        EUSART_Write(0xE0); // Send Common Line Data
        while(!EUSART_is_tx_done()); // Wait for data to finish sending
        // Latch in Data
        SRC_RCLK_SetHigh();
        SNK_LE_SetHigh();
        __delay_us(100);
        SRC_RCLK_SetLow();
        SNK_LE_SetLow();
        //Enable Register Output
        SRC_OE_SetLow();
        SNK_OE_SetLow();
        __delay_us(100);
        }

    }
}
/**
 End of File
 */