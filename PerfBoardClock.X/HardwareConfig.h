#ifndef HARDWARECONFIG_H
#define HARDWARECONFIG_H

#include <xc.h>
#include "device_config.h"
#include "pin_manager.h"
#include <stdint.h>
#include <stdbool.h>
#include <conio.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SRC_SRCLR aliases
#define SRC_SRCLR_TRIS                 TRISAbits.TRISA0
#define SRC_SRCLR_LAT                  LATAbits.LATA0
#define SRC_SRCLR_PORT                 PORTAbits.RA0
#define SRC_SRCLR_ANS                  ANSELAbits.ANSA0
#define SRC_SRCLR_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SRC_SRCLR_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SRC_SRCLR_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SRC_SRCLR_GetValue()           PORTAbits.RA0
#define SRC_SRCLR_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SRC_SRCLR_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SRC_SRCLR_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define SRC_SRCLR_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

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

// get/set SRC_OE aliases
#define SRC_OE_TRIS                 TRISAbits.TRISA2
#define SRC_OE_LAT                  LATAbits.LATA2
#define SRC_OE_PORT                 PORTAbits.RA2
#define SRC_OE_ANS                  ANSELAbits.ANSA2
#define SRC_OE_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define SRC_OE_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define SRC_OE_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define SRC_OE_GetValue()           PORTAbits.RA2
#define SRC_OE_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define SRC_OE_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define SRC_OE_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define SRC_OE_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set SNK_LE aliases
#define SNK_LE_TRIS                 TRISAbits.TRISA3
#define SNK_LE_LAT                  LATAbits.LATA3
#define SNK_LE_PORT                 PORTAbits.RA3
#define SNK_LE_ANS                  ANSELAbits.ANSA3
#define SNK_LE_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define SNK_LE_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define SNK_LE_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define SNK_LE_GetValue()           PORTAbits.RA3
#define SNK_LE_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define SNK_LE_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define SNK_LE_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define SNK_LE_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set SNK_OE aliases
#define SNK_OE_TRIS                 TRISAbits.TRISA4
#define SNK_OE_LAT                  LATAbits.LATA4
#define SNK_OE_PORT                 PORTAbits.RA4
#define SNK_OE_ANS                  ANSELAbits.ANSA4
#define SNK_OE_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define SNK_OE_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define SNK_OE_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define SNK_OE_GetValue()           PORTAbits.RA4
#define SNK_OE_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define SNK_OE_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define SNK_OE_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define SNK_OE_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

#define EUSART_DataReady  (EUSART_is_rx_ready())

typedef union {
    struct {
        unsigned perr : 1;
        unsigned ferr : 1;
        unsigned oerr : 1;
        unsigned reserved : 5;
    };
    uint8_t status;
}eusart_status_t;

// Pins
void PIN_MANAGER_Initialize (void);
void PIN_MANAGER_IOC(void);

// System
void SYSTEM_Initialize(void);
void OSCILLATOR_Initialize(void);
void WDT_Initialize(void);

// Timer 1
void TMR1_Initialize(void);
void TMR1_StartTimer(void);
void TMR1_StopTimer(void);
// Must write to for timer to start
void TMR1_WriteTimer(uint16_t timerVal);
// put in main for clearity
void TMR1_SetInterruptHandler(void (* InterruptHandler)(void));
// needed for erroneous interrupts
void TMR1_DefaultInterruptHandler(void);


// USART
void EUSART_Initialize(void);
bool EUSART_is_tx_ready(void);
bool EUSART_is_tx_done(void);
void EUSART_Write(uint8_t txData);
eusart_status_t EUSART_get_last_status(void);



#endif