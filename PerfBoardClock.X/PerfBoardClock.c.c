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
#include <stdio.h>

// Defines
#define ROWS 8
#define COLS 6

// Variables


volatile uint16_t timer1ReloadVal;

// Matrices are Row x column (mxn) in C: uint8_t matrix[m][n]


uint8_t NewDataFlag = 0; // Counts # of timer Overflows
uint8_t AccessLine = 0; // Data for the Access line Shift Register
volatile uint8_t CommonLine = 0; // Where Common Line data is stored
volatile uint8_t column = 2 ; // The Column to be illuminated. Stars at Col 0

// Functions

//uint8_t ComLn_Extract_Data(uint8_t Column,uint8_t Character[ROWS][COLS]){ // Extracts Common Line data from specified column
//    uint8_t ColData = 0;
//    for(uint8_t i = 0; i<ROWS; i++){
//        ColData = (ColData << 1) | (Character[i][Column]);
//    }
//    return ColData;
//}
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
//    uint8_t Col = 0;
//    uint8_t ColData = 0;
//    ColData = ComLn_Extract_Data(Col, ZeroChar);
//    printf("Data stored in Column zero: %d\n", ColData);
    while (1) {

    }
}

void TMR1_ISR(void)
{

    // Clear the TMR1 interrupt flag
    PIR1bits.TMR1IF = 0;
    TMR1_WriteTimer(timer1ReloadVal);

    NewDataFlag++;
    column++;
    if(column > 2){ // Reset column to illuminate
        column = 0;
    }
    
    if(TMR1_InterruptHandler)
    {
        TMR1_InterruptHandler();
    }
}
/**
 End of File
 */