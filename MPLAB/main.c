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

volatile uint16_t timer1ReloadVal;

// Matricies are Row x column (mxn) in C: uint8_t matrix[m][n]
uint8_t CChar[3] = {
    0b101,
    0b101,
    0b111
};
uint8_t TChar[3] = {
    0b100,
    0b111,
    0b100
};
uint8_t IChar[3] = {
    0b101,
    0b111,
    0b101
};
uint8_t LChar[3] = {
    0b001,
    0b001,
    0b111
};
uint8_t HChar[3] = {
    0b111,
    0b010,
    0b111
};

uint8_t NewDataFlag = 0; // Counts # of timer Overflows
uint8_t AccessLine = 0; // Data for the Access line Shift Register
volatile uint8_t CommonLine = 0; // Where Common Line data is stored
volatile uint8_t column = 2 ; // The Column to be illuminated. Stars at Col 0

// Functions

uint8_t CommonLineData(uint8_t ComLinNum,uint8_t *TextMatrix){
    uint8_t Temp = 0;
    Temp = (TextMatrix[ComLinNum] << 5);
    return Temp;
}
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
    
    while (1) {
        while(1){
        // SRC Reg Test
        SRC_OE_SetHigh();
        EUSART_Write(0x80); // Send Common Line Data
        while(!EUSART_is_tx_done()); // Wait for data to finish sending
        // Latch in Data
        SRC_RCLK_SetHigh();
        __delay_us(100);
        SRC_RCLK_SetLow();
        //Enable Register Output
        SRC_OE_SetLow();
        __delay_us(100);
        
        SRC_OE_SetHigh();
        EUSART_Write(0x40); // Send Common Line Data
        while(!EUSART_is_tx_done()); // Wait for data to finish sending
        // Latch in Data
        SRC_RCLK_SetHigh();
        __delay_us(100);
        SRC_RCLK_SetLow();
        //Enable Register Output
        SRC_OE_SetLow();
        __delay_us(100);
        
        SRC_OE_SetHigh();
        EUSART_Write(0x20); // Send Common Line Data
        while(!EUSART_is_tx_done()); // Wait for data to finish sending
        // Latch in Data
        SRC_RCLK_SetHigh();
        __delay_us(100);
        SRC_RCLK_SetLow();
        //Enable Register Output
        SRC_OE_SetLow();
        __delay_us(100);
        }
        
        
//        if(NewDataFlag == 1){
            
//            switch(column){
//                case 2:
//                    // Disable Common Line and Access Line Registers
//                    SNK_OE_SetHigh();
//                    SRC_OE_SetHigh();
//                    
////                    AccessLine = 0b10000000;
////                    CommonLine = CommonLineData(column, TChar); // Get Common Line Data
////                    EUSART_Write(AccessLine);// Send Access Line Data
////                    while(!EUSART_is_tx_ready()); // Wait for data to finish sending
//                    EUSART_Write(0b10000000); // Send Common Line Data
//                    while(!EUSART_is_tx_ready()); // Wait for data to finish sending
//                     // Latch Data into Shift Registers
//                    SRC_RCLK_SetHigh();
////                    SNK_LE_SetLow();
//                    __delay_us(1000);
//                    // Reset Shift Register Latches
//                    SRC_RCLK_SetLow();
////                    SNK_LE_SetHigh();
//                     // Enable Common Line and Access Line Registers
////                    SNK_OE_SetLow();
//                    SRC_OE_SetLow();
//                    column--;
//                    __delay_us(10000);
//                case 1:
//                    // Disable Common Line and Access Line Registers
//                    SNK_OE_SetHigh();
//                    SRC_OE_SetHigh();
//                    
//                    AccessLine = 0b01000000;
//                    CommonLine = CommonLineData(column, TChar); // Get Common Line Data
//                    EUSART_Write(AccessLine);// Send Access Line Data
//                    while(!EUSART_is_tx_ready()); // Wait for data to finish sending
//                    EUSART_Write(CommonLine); // Send Common Line Data
//                    while(!EUSART_is_tx_ready()); // Wait for data to finish sending
//                     // Latch Data into Shift Registers
//                    SRC_RCLK_SetHigh();
//                    SNK_LE_SetLow();
//                    __delay_us(1000);
//                    // Reset Shift Register Latches
//                    SRC_RCLK_SetLow();
//                    SNK_LE_SetHigh();
//                     // Enable Common Line and Access Line Registers
//                    SNK_OE_SetLow();
//                    SRC_OE_SetLow();
//                    column--;
//                    __delay_us(10000);
//                case 0:
//                    // Disable Common Line and Access Line Registers
//                    SNK_OE_SetHigh();
//                    SRC_OE_SetHigh();
//                    
//                    AccessLine = 0b00100000;
//                    CommonLine = CommonLineData(column, TChar); // Get Common Line Data
//                    EUSART_Write(AccessLine);// Send Access Line Data
//                    while(!EUSART_is_tx_ready()); // Wait for data to finish sending
//                    EUSART_Write(CommonLine); // Send Common Line Data
//                    while(!EUSART_is_tx_ready()); // Wait for data to finish sending
//                     // Latch Data into Shift Registers
//                    SRC_RCLK_SetHigh();
//                    SNK_LE_SetLow();
//                    __delay_us(1000);
//                    // Reset Shift Register Latches
//                    SRC_RCLK_SetLow();
//                    SNK_LE_SetHigh();
//                     // Enable Common Line and Access Line Registers
//                    SNK_OE_SetLow();
//                    SRC_OE_SetLow();
//                    column = 2;
//                    __delay_us(10000);
//            }
            
//            NewDataFlag = 0; // Reset Data Flag
//        }

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