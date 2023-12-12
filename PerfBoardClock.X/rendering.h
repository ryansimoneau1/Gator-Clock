/* 
 * File:   functions.h
 * Author: Projects
 *
 * Created on December 11, 2023, 7:28 PM
 */

#ifndef RENDERING_H
#define	RENDERING_H

typedef uint8_t Uint8;
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

// Number Builder for the left half of the display
Uint8 LHalf_NumBuilder(Uint8 AcLn,const BlockSet *Block, Uint32 Tod);
// Number Builder for the right half of the display
Uint8 RHalf_NumBuilder(Uint8 AcLn,const BlockSet *Block, Uint32 Tod);

// Brightness control for the left half of the display
Uint8 LHalf_Brightness(Uint8 AcLn);
// Brightness control for the right half of the display
Uint8 RHalf_Brightness(Uint8 AcLn);

// Renderer. Takes in info from left/right number builders and brightness control to determine what data to send out per tick of the Timer 1 clock
Uint32 Renderer(Uint8 LH_Num, Uint8 RH_Num, Uint8 LH_Bright, Uint8 RH_Bright);

#endif	/* FUNCTIONS_H */

