/* 
 includes all functions required to render text to the LED Display
 
 
 
 
 
 */

#include "rendering.h"

BlockSet NumberBlocks = { // Struct containing building blocks to construct display numbers
    .ABlock = 0b00011110,
    .BBlock = 0b00100001,
    .CBlock = 0b00000100,
    .DBlock = 0b00001100,
    .EBlock = 0b00010100,
    .FBlock = 0b00111111,
    .GBlock = 0b00000010,
    .HBlock = 0b00100000,
    .IBlock = 0b00001110,
    .JBlock = 0b00000001,
    .KBlock = 0b00000110,
    .LBlock = 0b00001010,
    .MBlock = 0b00010010,
    .NBlock = 0b00100010,
    .OBlock = 0b00111110,
    .PBlock = 0b00101110,
    .QBlock = 0b00110000,
    .RBlock = 0b00001000,
    .SBlock = 0b00010000,
    .TBlock = 0b00100011,
    .UBlock = 0b00011101,
};

// Number Builder for the left half of the display
void LHalf_NumBuilder(Uint8 AcLn,const BlockSet *Block, Uint32 Tod){
    
    /*
     Clock sends time in HrHr:MinMin format (ex. 1230)
     * based on Access Line number, NumBuilder determines what number to construct
     *      ex: AcLn = 7 => the # 2 from 1230 at the 2nd column
     * NumBuilder then bit manipulates Number Blocks associated with the number 2
     *      find the appropriate logical shift value by considering the Access Line offset due to the number's position on the screen and the extra 2 most significant bits in the Number Blocks
     
     */
    
}
// Number Builder for the right half of the display
void RHalf_NumBuilder(Uint8 AcLn,const BlockSet *Block, Uint32 Tod){
    
}

// Brightness control for the left half of the display

// Brightness control for the right half of the display


// Renderer. Takes in info from left/right number builders and brightness control to determine what data to send out per tick of the Timer 1 clock
