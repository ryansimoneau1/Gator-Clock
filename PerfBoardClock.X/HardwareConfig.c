
#include "HardwareConfig.h"


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATA = 0x15;
    LATB = 0x00;

    /**
    TRISx registers
    */
    TRISA = 0xE0;
    TRISB = 0xFF;

    /**
    ANSELx registers
    */
    ANSELB = 0xFE;
    ANSELA = 0x00;

    /**
    WPUx registers
    */
    WPUB = 0x00;
    WPUA = 0x00;
    OPTION_REGbits.nWPUEN = 1;
    /**
    APFCONx registers
    */
    APFCON0 = 0x00;
    APFCON1 = 0x00;
}

void SYSTEM_Initialize(void)
{

    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    WDT_Initialize();
}

void OSCILLATOR_Initialize(void)
{
    // SCS FOSC; SPLLEN disabled; IRCF 250KHz_HF; 
    OSCCON = 0x48;
    // TUN 0; 
    OSCTUNE = 0x00;
    // SBOREN disabled; 
    BORCON = 0x00;
}

void WDT_Initialize(void)
{
    // WDTPS 1:65536; SWDTEN OFF; 
    WDTCON = 0x16;
}

void TMR1_Initialize(void)
{
    //Set the Timer to the options selected in the GUI

    //T1GSS T1G_pin; TMR1GE disabled; T1GTM disabled; T1GPOL low; T1GGO done; T1GSPM disabled; 
    T1GCON = 0x00;

    //TMR1H 252; 
    TMR1H = 0xFC;

    //TMR1L 24; 
    TMR1L = 0x18;

    // Clearing IF flag before enabling the interrupt.
    PIR1bits.TMR1IF = 0;

    // Load the TMR value to reload variable
    timer1ReloadVal=(uint16_t)((TMR1H << 8) | TMR1L);

    // Enabling TMR1 interrupt.
    PIE1bits.TMR1IE = 1;

    // Set Default Interrupt Handler
    // TMR1_SetInterruptHandler(TMR1_DefaultInterruptHandler); // change to non-default handler?

    // T1CKPS 1:1; T1OSCEN disabled; nT1SYNC synchronize; TMR1CS FOSC/4; TMR1ON enabled; 
    T1CON = 0x01;
}

void TMR1_StartTimer(void)
{
    // Start the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON = 1;
}

void TMR1_StopTimer(void)
{
    // Stop the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON = 0;
}

void TMR1_WriteTimer(uint16_t timerVal)
{
    if (T1CONbits.nT1SYNC == 1)
    {
        // Stop the Timer by writing to TMRxON bit
        T1CONbits.TMR1ON = 0;

        // Write to the Timer1 register
        TMR1H = (uint8_t)(timerVal >> 8);
        TMR1L = (uint8_t)timerVal;

        // Start the Timer after writing to the register
        T1CONbits.TMR1ON =1;
    }
    else
    {
        // Write to the Timer1 register
        TMR1H = (uint8_t)(timerVal >> 8);
        TMR1L = (uint8_t)timerVal;
    }
}

void TMR1_SetInterruptHandler(void (* InterruptHandler)(void)){
    TMR1_InterruptHandler = InterruptHandler; // is this needed?
}

// USART
void EUSART_Initialize(void)
{
    // Set the EUSART module to the options selected in the user interface.

    // ABDOVF no_overflow; SCKP Inverted; BRG16 16bit_generator; WUE disabled; ABDEN disabled; 
    BAUDCON = 0x18;

    // SPEN enabled; RX9 8-bit; CREN disabled; ADDEN disabled; SREN disabled; 
    RCSTA = 0x80;

    // TX9 8-bit; TX9D 0; SENDB sync_break_complete; TXEN enabled; SYNC synchronous; BRGH hi_speed; CSRC master; 
    TXSTA = 0xB4;

    // SPBRGL 0; 
    SPBRGL = 0x00;

    // SPBRGH 0; 
    SPBRGH = 0x00;


    // EUSART_SetFramingErrorHandler(EUSART_DefaultFramingErrorHandler);
    // EUSART_SetOverrunErrorHandler(EUSART_DefaultOverrunErrorHandler);
    // EUSART_SetErrorHandler(EUSART_DefaultErrorHandler); // Need to revisit

    eusartRxLastError.status = 0;

}

bool EUSART_is_tx_ready(void)
{
    return (bool)(PIR1bits.TXIF && TXSTAbits.TXEN);
}
bool EUSART_is_tx_done(void)
{
    return TXSTAbits.TRMT;
}
eusart_status_t EUSART_get_last_status(void){
    return eusartRxLastError;
}
void EUSART_Write(uint8_t txData)
{
    RCSTAbits.SREN = 0;
    RCSTAbits.CREN = 0;	
    while(0 == PIR1bits.TXIF)
    {
    }

    TXREG = txData;    // Write the data byte to the USART.
}