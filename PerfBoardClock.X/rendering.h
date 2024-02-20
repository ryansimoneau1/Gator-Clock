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


typedef uint8_t Uint8;
typedef uint16_t Uint16;
typedef uint32_t Uint32;

const Uint8 DigitZero[8];

typedef struct BlockSet{
    Uint8 ABlock;
    Uint8 BBlock;
    Uint8 CBlock;
    Uint8 DBlock;
    Uint8 EBlock;
    Uint8 FBlock;
    Uint8 GBlock;
    Uint8 HBlock;
    Uint8 IBlock;
    Uint8 JBlock;
    Uint8 KBlock;
    Uint8 LBlock;
    Uint8 MBlock;
    Uint8 NBlock;
    Uint8 OBlock;
    Uint8 PBlock;
    Uint8 QBlock;
    Uint8 RBlock;
    Uint8 SBlock;
    Uint8 TBlock;
    Uint8 UBlock;
}BlockSet;

typedef struct CharacterSet{
    const Uint8 CharacterZero[8];
    const Uint8 CharacterOne[8];
    const Uint8 CharacterTwo[8];
    const Uint8 CharacterThree[8];
    const Uint8 CharacterFour[8];
    const Uint8 CharacterFive[8];
    const Uint8 CharacterSix[8];
    const Uint8 CharacterSeven[8];
    const Uint8 CharacterEight[8];
    const Uint8 CharacterNine[8]
}CharacterSet;

typedef struct TensOnes{
    Uint8 HourOnes;
    Uint8 HourTens;
    Uint8 MinuteOnes;
    Uint8 MinuteTens;
}TensOnes;

typedef struct RendererOutputs{
    Uint8 Left_Common_Line_Data;
    Uint8 Right_Common_Line_Data;

    typedef union AccessLine{
        Uint16 Full_Access_Line;
        typedef struct AccessLineMembers{
            Uint8 Access_Line_Low;
            Uint8 Access_Line_High;
        }AccessLineMembers;
    }AccessLine;
}RendererOutputs;

typedef struct DisplayBrightness{
    Uint8 LED_Left_Brightness;
    Uint8 LED_Right_Brightness;
}DisplayBrightness;




extern TensOnes tod_outputs;
extern BlockSet NumberBlocks;

// breaks down hours and minutes into 10s and 1s place values
Uint8 Time_deconstruct(const Uint8 access_line, const Uint8 hours, const Uint8 minutes, TensOnes *output);

// Constructs the digits to be rendered on the display based on primitives contained within BlockSet
Uint8 DigitAssembler(const Uint8 character_line,const BlockSet *Block, const Uint8 time);

// Controls the scan period PWM 
DisplayBrightness BrightnessCTRL(Uint8 access_line);

// Flips Display driver bytes to accomodate little endian USART
Uint8 FlipByte(Uint8 byte);

// Inputs from Digit Assembler and brightness control to determine what data to send out per tick of the Timer 1 clock
RendererOutputs Renderer(Uint8 access_line, Uint8 time_Slot, DisplayBrightness *LEDBrightness);

#endif	/* FUNCTIONS_H */

