/* 
 includes all functions required to render text to the LED Display
 
 
 */

#include "rendering.h"

const BlockSet NumberBlocks = { // Struct containing building blocks to construct display numbers
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
    .QBlock = 0b00110001,
    .RBlock = 0b00001000,
    .SBlock = 0b00010000,
    .TBlock = 0b00100011,
    .UBlock = 0b00011101,
};
CharacterSet Characters = {

.CharacterZero = {
    0b00011110,
    0b00100001,
    0b00100001,
    0b00100001,
    0b00100001,
    0b00100001,
    0b00100001,
    0b00011110},

.CharacterOne = {
    0b00000100,
    0b00001100,
    0b00010100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00111111},
    
.CharacterTwo = {
    0b00011110,
    0b00100001,
    0b00100001,
    0b00000010,
    0b00001100,
    0b00010000,
    0b00100000,
    0b00111111},

.CharacterThree = {
    0b00111111,
    0b00000010,
    0b00000100,
    0b00001110,
    0b00000001,
    0b00100001,
    0b00100001,
    0b00011110},

.CharacterFour = {
    0b00000110,
    0b00001010,
    0b00010010,
    0b00100010,
    0b00111111,
    0b00000100,
    0b00000100,
    0b00000100},

.CharacterFive = {
    0b00111111,
    0b00100000,
    0b00100000,
    0b00111110,
    0b00000001,
    0b00000001,
    0b00100001,
    0b00011110},

.CharacterSix = {
    0b00011110,
    0b00100001,
    0b00100000,
    0b00101110,
    0b00110001,
    0b00100001,
    0b00100001,
    0b00011110},

.CharacterSeven = {
    0b00111111,
    0b00000001,
    0b00000010,
    0b00000100,
    0b00001000,
    0b00010000,
    0b00100000,
    0b00100000},

.CharacterEight = {
    0b00011110,
    0b00100001,
    0b00100001,
    0b00011110,
    0b00100001,
    0b00100001,
    0b00100001,
    0b00011110},

.CharacterNine = {
    0b00011110,
    0b00100001,
    0b00100001,
    0b00100011,
    0b00011101,
    0b00000001,
    0b00100001,
    0b00011110}
};


const Uint8 DigitOne[8]

extern TensOnes tod_outputs = {
    .HourOnes = 0,
    .HourTens = 0,
    .MinuteOnes = 0,
    .MinuteTens = 0
};


// Takes time and breaks into 10s and 1s place
Uint8 Time_deconstruct(const Uint8 access_line, const Uint8 hours, const Uint8 minutes, TensOnes *output){
   static Uint8 character_line = 0; // Accounts for Access line offset

   if(access_line < 6){
      character_line = access_line;
      output->HourTens = hours / 10;
      output->MinuteTens = minutes / 10;
   }
   else{
      character_line = access_line - 6;
      output->HourOnes = hours % 10;
      output->MinuteOnes = minutes % 10;
   }
   return character_line;
}

// Constructs the digits to be rendered on the display based on primitives contained within BlockSet
Uint8 DigitAssembler(const Uint8 character_line,const BlockSet *Block, const Uint8  digit){
    Uint8 Output = 0;

   //  if( digit == 0){
   //     Output = ((Block->ABlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->ABlock << (character_line)) & 0b10000000);
   //  }

   //  if( digit == 1){

   //     Output = ((Block->FBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->CBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->CBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->CBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->CBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->EBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->DBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->CBlock << (character_line)) & 0b10000000);

   //  }
   //  if( digit == 2){

   //     Output = ((Block->FBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->HBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->SBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->DBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->GBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->ABlock << (character_line)) & 0b10000000);

   //  }
   //  if( digit == 3){

   //     Output = ((Block->ABlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->JBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->IBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->EBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->GBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->FBlock << (character_line)) & 0b10000000);

   //  }
   //  if( digit == 4){

   //     Output = ((Block->GBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->GBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->GBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->FBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->NBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->MBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->LBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->KBlock << (character_line)) & 0b10000000);

   //  }
   //  if( digit == 5){

   //     Output = ((Block->ABlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->JBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->JBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->OBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->HBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->HBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->FBlock << (character_line)) & 0b10000000);

   //  }
   //  if( digit == 6){

   //     Output = ((Block->ABlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->QBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->PBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->HBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->ABlock << (character_line)) & 0b10000000);

   //  }
   //  if( digit == 7){

   //     Output = ((Block->HBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->HBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->SBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->RBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->CBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->GBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->JBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->FBlock << (character_line)) & 0b10000000);

   //  }
   //  if( digit == 8){

   //     Output = ((Block->ABlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->ABlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->ABlock << (character_line)) & 0b10000000);

   //  }
   //  if( digit == 9){

   //     Output = ((Block->ABlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->JBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->UBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->TBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->BBlock << (character_line)) & 0b10000000);
   //     Output >>= 1;
   //     Output |= ((Block->ABlock << (character_line)) & 0b10000000);
   //  }

    return Output;

}

// Adjusts the PWM depending on LED Color
DisplayBrightness BrightnessCTRL(Uint8 AccessLine){
    DisplayBrightness LEDBrightness = {
    .LED_Left_Brightness     = ORANGE,
    .LED_Right_Brightness    = BLUE
    };
    if(AccessLine > 5){
        LEDBrightness.LED_Left_Brightness   = BLUE;
    }
    if(AccessLine == 12){
        LEDBrightness.LED_Left_Brightness   = WHITE;
    }
    if(AccessLine < 7){
        LEDBrightness.LED_Right_Brightness  = ORANGE;
    }
    if(AccessLine == 0){
        LEDBrightness.LED_Right_Brightness  = WHITE;
    }
    return LEDBrightness;
}

Uint8 FlipByte(Uint8 byte){
    Uint8 FlippedByte = 0;

}

// Inputs from Digit Assembler and brightness control to determine what data to send out per tick of the Timer 1 clock
RendererOutputs Renderer(Uint8 access_line, Uint8 time_Slot, DisplayBrightness *LEDBrightness){

    Uint8 Left_Test_LEDData = 0b01000000; // Constant Test Data to send to the Display Common Line Registers
    Uint8 Right_Test_LEDData = 0b0000010;

RendererOutputs LED_Data = {
    .Left_Common_Line_Data  = 0,
    .Right_Common_Line_Data = 0,
    .AccessLine.Full_Access_Line = (1 >> access_line)

};

if(LEDBrightness->LED_Left_Brightness >= time_Slot){
    LED_Data.Left_Common_Line_Data  = Left_Test_LEDData;

}else{
    LED_Data.Left_Common_Line_Data = 0;
}

if(LEDBrightness->LED_Right_Brightness >= time_Slot){
    LED_Data.Right_Common_Line_Data  = Right_Test_LEDData;

}else{
    LED_Data.Right_Common_Line_Data = 0;
}

    return LED_Data;
}