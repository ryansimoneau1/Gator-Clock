/* 
 * File:   functions.h
 * Author: Projects
 *
 * Created on December 11, 2023, 7:28 PM
 */

#ifndef RENDERING_H
#define	RENDERING_H

#include <stdint.h>

#define ORANGE 2
#define BLUE 3
#define WHITE 1

#define Zero 0
#define One 1
#define Two 2
#define Three 3
#define Four 4
#define Five 5
#define Six 6
#define Seven 7
#define Eight 8
#define Nine 9
#define Dots 10



typedef uint8_t Uint8;
typedef uint16_t Uint16;
typedef uint32_t Uint32;

typedef struct CharacterSet{
    const Uint8 CharacterZero[6];
    const Uint8 CharacterOne[6];
    const Uint8 CharacterTwo[6];
    const Uint8 CharacterThree[6];
    const Uint8 CharacterFour[6];
    const Uint8 CharacterFive[6];
    const Uint8 CharacterSix[6];
    const Uint8 CharacterSeven[6];
    const Uint8 CharacterEight[6];
    const Uint8 CharacterNine[6];
    const Uint8 CharacterDots;
}CharacterSet;


// typedef struct TensOnes{
//     Uint8 HourOnes;
//     Uint8 HourTens;
//     Uint8 MinuteOnes;
//     Uint8 MinuteTens;
// }TensOnes;



typedef struct DisplayBrightness{
    Uint8 LED_Left_Brightness;
    Uint8 LED_Right_Brightness;
}DisplayBrightness;

typedef struct RendererOutputs{
    Uint8 Left_Common_Line_Data;
    Uint8 Right_Common_Line_Data;

    union AccessLine{
        Uint16 Full_Access_Line;
        struct AccessLineMembers{
            Uint8 Access_Line_Low;
            Uint8 Access_Line_High;
        }AccessLineMembers;
    }AccessLine;
}RendererOutputs;

// extern TensOnes tod_outputs;

// breaks down hours and minutes into 10s and 1s place values
// Uint8 Time_deconstruct(const Uint8 access_line, const Uint8 hours, const Uint8 minutes, TensOnes *output);

// Constructs the digits to be rendered on the display based on primitives contained within BlockSet
void DisplayBuffGen(const CharacterSet* Characters, Uint8 digit, Uint8 *DisplayBuffer);

// Controls the scan period PWM 
DisplayBrightness BrightnessCTRL(Uint8 access_line);

// Flips Display driver bytes to accomodate little endian USART
Uint8 ReverseByte(Uint8 byte);

// Inputs from Digit Assembler and brightness control to determine what data to send out per tick of the Timer 1 clock
RendererOutputs Renderer(Uint8 access_line, Uint8 time_Slot, Uint8 *DisplayBuffer);

#endif	/* FUNCTIONS_H */

