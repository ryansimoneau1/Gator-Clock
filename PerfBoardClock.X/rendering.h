/* 
 * File:   functions.h
 * Author: Projects
 *
 * Created on December 11, 2023, 7:28 PM
 */

#ifndef RENDERING_H
#define	RENDERING_H

#include <stdint.h>

typedef uint8_t Uint8;
typedef uint16_t Uint16;
typedef uint32_t Uint32;


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

extern BlockSet NumberBlocks;

// Returns which part of the Hour is being displayed during the current scanning period (10s or 1s place)
Uint8 Hour_deconstruct(const Uint8 access_line, const Uint8 hours);
// Removes access_line offset for constructing common line data
Uint8 Character_Line(const Uint8 access_line);

// example of what the numberbuilder is pulling from the number block struct
//Uint8 StructData(const BlockSet *Block);

// Number Builder for the left half of the display.
Uint8 LHalf_NumBuilder(const Uint8 character_line,const BlockSet *Block, const Uint8 hours);
// Number Builder for the right half of the display
Uint8 RHalf_NumBuilder(Uint8 access_line,const BlockSet *Block, Uint8 minutes);

// Brightness control for the left half of the display
Uint8 LHalf_Brightness(Uint8 access_line);
// Brightness control for the right half of the display
Uint8 RHalf_Brightness(Uint8 access_line);

// Renderer. Takes in info from left/right number builders and brightness control to determine what data to send out per tick of the Timer 1 clock
Uint32 Renderer(Uint8 LH_Num, Uint8 RH_Num, Uint8 LH_Bright, Uint8 RH_Bright);

#endif	/* FUNCTIONS_H */

