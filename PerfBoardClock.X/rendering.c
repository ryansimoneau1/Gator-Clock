/* 
 includes all functions required to render text to the LED Display
 
 
 
 
 
 */

#include "rendering.h"

extern BlockSet NumberBlocks = { // Struct containing building blocks to construct display numbers
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

Uint8 Hour_deconstruct(const Uint8 access_line, const Uint8 hours){
    static Uint8 Output = 0;

    if(access_line < 6){    // 10s place of Hr to be displayed
        Output = hours / 10;
    }
    else{                   // 1s place of Hr to be displayed
        Output = hours % 10;
    }
    return Output;
}

Uint8 Character_Line(const Uint8 access_line){
    static Uint8 character_line = 0; // Accounts for Access line offset

    if(access_line < 6){    // 10s place of Hr to be displayed
        character_line = access_line;
    }
    else{                   // 1s place of Hr to be displayed
        character_line = access_line - 6;
    }
    
    character_line += 2; // characters are 6 bit wide. accounts for upper 2 MSbs
    return character_line;
}

//Uint8 StructData(const BlockSet *Block){
//    static Uint8 Data = 0;
//    
//    Data  = ((Block->ABlock << (2)) & 0b10000000);
//    Data >>= 1;
//    Data |= ((Block->BBlock << (2)) & 0b10000000);
//    Data >>= 1;
//    Data |= ((Block->BBlock << (2)) & 0b10000000);
//    Data >>= 1;
//    Data |= ((Block->BBlock << (2)) & 0b10000000);
//    Data >>= 1;
//    Data |= ((Block->BBlock << (2)) & 0b10000000);
//    Data >>= 1;
//    Data |= ((Block->BBlock << (2)) & 0b10000000);
//    Data >>= 1;
//    Data |= ((Block->BBlock << (2)) & 0b10000000);
//    Data >>= 1;
//    Data |= ((Block->BBlock << (2)) & 0b10000000);
//    Data >>= 1;
//    Data |= ((Block->ABlock << (2)) & 0b10000000);
//    
//    return Data;
//}

// Number Builder for the left half of the display
Uint8 LHalf_NumBuilder(const Uint8 character_line,const BlockSet *Block, const Uint8 hours){
    static Uint8 Output = 0;
    /*
     Clock sends time in HrHr:MinMin format (ex. 1230)
     * based on Access Line number, NumBuilder determines what number to construct
     *      ex: AcLn = 7 => the # 2 from 1230 at the 2nd column
     * NumBuilder then bit manipulates Number Blocks associated with the number 2
     *      find the appropriate logical shift value by considering the Access Line offset due to the number's position on the screen and the extra 2 most significant bits in the Number Blocks
     
     */
    
    if(hours == 0){
       Output = ((Block->ABlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->ABlock << (character_line)) & 0b10000000);
    }

    if(hours == 1){

       Output = ((Block->FBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->CBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->CBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->CBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->CBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->EBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->DBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->CBlock << (character_line)) & 0b10000000);

    }
    if(hours == 2){

       Output = ((Block->FBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->HBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->SBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->DBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->GBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->ABlock << (character_line)) & 0b10000000);

    }
    if(hours == 3){

       Output = ((Block->ABlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->JBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->IBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->EBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->GBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->FBlock << (character_line)) & 0b10000000);

    }
    if(hours == 4){

       Output = ((Block->GBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->GBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->GBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->FBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->NBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->MBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->LBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->KBlock << (character_line)) & 0b10000000);

    }
    if(hours == 5){

       Output = ((Block->ABlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->JBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->JBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->OBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->HBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->HBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->FBlock << (character_line)) & 0b10000000);

    }
    if(hours == 6){

       Output = ((Block->ABlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->QBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->PBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->HBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->ABlock << (character_line)) & 0b10000000);

    }
    if(hours == 7){

       Output = ((Block->HBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->HBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->SBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->RBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->CBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->GBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->JBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->FBlock << (character_line)) & 0b10000000);

    }
    if(hours == 8){

       Output = ((Block->ABlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->ABlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->ABlock << (character_line)) & 0b10000000);

    }
    if(hours == 9){

       Output = ((Block->ABlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->JBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->UBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->TBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->BBlock << (character_line)) & 0b10000000);
       Output >>= 1;
       Output |= ((Block->ABlock << (character_line)) & 0b10000000);
    }

    return Output;

}
// Number Builder for the right half of the display
Uint8 RHalf_NumBuilder(Uint8 access_line,const BlockSet *Block, Uint8 minutes){
    
}

// Brightness control for the left half of the display

// Brightness control for the right half of the display


// Renderer. Takes in info from left/right number builders and brightness control to determine what data to send out per tick of the Timer 1 clock
