/* 
 includes all functions required to render text to the LED Display
 
 
 */

#include "rendering.h"
const CharacterSet Characters = { // could these all be flipped on their side to make the digit assembler implementation more simple?

.CharacterZero = {
    0b01111110,
    0b10000001,
    0b10000001,
    0b10000001,
    0b10000001,
    0b01111110},

.CharacterOne = {
    0b10000000,
    0b10000100,
    0b10000010,
    0b11111111,
    0b10000000,
    0b10000000}, 
    
.CharacterTwo = {
    0b11000110,
    0b10100001,
    0b10010001,
    0b10010001,
    0b10001001,
    0b10000110},

.CharacterThree = {
    0b01100001,
    0b10000001,
    0b10001001,
    0b10001101,
    0b10001011,
    0b01110001},

.CharacterFour = {
    0b00011000,
    0b00010100,
    0b00010010,
    0b00010001,
    0b11111111,
    0b00010000},

.CharacterFive = {
    0b01001111,
    0b10001001,
    0b10001001,
    0b10001001,
    0b10001001,
    0b01110001},

.CharacterSix = {
    0b01111110,
    0b10010001,
    0b10001001,
    0b10001001,
    0b10001001,
    0b01110010},

.CharacterSeven = {
    0b11000001,
    0b00100001,
    0b00010001,
    0b00001001,
    0b00000101,
    0b00000011},

.CharacterEight = {
    0b01110110,
    0b10001001,
    0b10001001,
    0b10001001,
    0b10001001,
    0b01110110},

.CharacterNine = {
    0b01001110,
    0b10010001,
    0b10010001,
    0b10010001,
    0b10001001,
    0b01111110},
.CharacterDots = 0b01100110
};

// extern TensOnes tod_outputs = {
//     .HourOnes = 0,
//     .HourTens = 0,
//     .MinuteOnes = 0,
//     .MinuteTens = 0
// };


// Takes time and breaks into 10s and 1s place
// Uint8 Time_deconstruct(const Uint8 access_line, const Uint8 hours, const Uint8 minutes, TensOnes *output){
//    static Uint8 character_line = 0; // Accounts for Access line offset

//    if(access_line < 6){
//       character_line = access_line;
//       output->HourTens = hours / 10;
//       output->MinuteTens = minutes / 10;
//    }
//    else{
//       character_line = access_line - 6;
//       output->HourOnes = hours % 10;
//       output->MinuteOnes = minutes % 10;
//    }
//    return character_line;
// }

// Constructs the digits to be rendered on the display based on primitives contained within BlockSet
void DisplayBuffGen(const CharacterSet* Characters, Uint8 digit, Uint8 *DisplayBuffer){ // Under Construction :}
    Uint8* Ptr = 0;

    for(Uint8 i = 0; i < 26; i++){
        DisplayBuffer[i] = 0;
    }

    switch (digit){
        case Zero:
            Ptr = Characters->CharacterZero;
        case One:
            Ptr = Characters->CharacterOne;
        case Two:
            Ptr = Characters->CharacterTwo;
        case Three:
            Ptr = Characters->CharacterThree;
        case Four:
            Ptr = Characters->CharacterFour;
        case Five:
            Ptr = Characters->CharacterFive;
        case Six:
            Ptr = Characters->CharacterSix;
        case Seven:
            Ptr = Characters->CharacterSeven;
        case Eight:
            Ptr = Characters->CharacterEight;
        case Nine:
            Ptr = Characters->CharacterNine;
        case Dots:
            Ptr = Characters->CharacterDots;    
    }

    for(Uint8 i = 0; i < 26; i++){
        DisplayBuffer[i] = Ptr[i];
    }

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

Uint8 ReverseByte(Uint8 byte){
    Uint8 ReversedByte = 0;

    for(Uint8 i = 0; i < 8; i++){
        if(byte & (1 << i)){
            ReversedByte |= (1 << (7-i));
        }
    }
    return ReversedByte;
}

// Inputs from Digit Assembler and brightness control to determine what data to send out per tick of the Timer 1 clock
RendererOutputs Renderer(Uint8 access_line, Uint8 time_Slot, Uint8 *DisplayBuffer){

RendererOutputs LED_Data = {
    .Left_Common_Line_Data  = 0,
    .Right_Common_Line_Data = 0,
    .AccessLine.Full_Access_Line = (1 << access_line)

};

Uint8 Left_DisplayData[13]  = {0}; // Constant Test Data to send to the Display Common Line Registers
Uint8 Right_DisplayData[13] = {0};

for(Uint8 i = 0; i < 13; i++){
    Left_DisplayData[i]     = DisplayBuffer[i];
    Right_DisplayData[i]    = DisplayBuffer[i + 13];
}

DisplayBrightness LEDBrightness = BrightnessCTRL(access_line);

if(LEDBrightness.LED_Left_Brightness >= time_Slot){
    LED_Data.Left_Common_Line_Data  = Left_DisplayData[access_line];

}else{
    LED_Data.Left_Common_Line_Data = 0;
}

if(LEDBrightness.LED_Right_Brightness >= time_Slot){
    LED_Data.Right_Common_Line_Data  = Right_DisplayData[access_line];

}else{
    LED_Data.Right_Common_Line_Data = 0;
}

// Reverse the order of all bytes to prepare for USART transmission
LED_Data.Left_Common_Line_Data                          = ReverseByte(LED_Data.Left_Common_Line_Data);
LED_Data.Right_Common_Line_Data                         = ReverseByte(LED_Data.Right_Common_Line_Data);
LED_Data.AccessLine.AccessLineMembers.Access_Line_High  = ReverseByte(LED_Data.AccessLine.AccessLineMembers.Access_Line_High);
LED_Data.AccessLine.AccessLineMembers.Access_Line_Low   = ReverseByte(LED_Data.AccessLine.AccessLineMembers.Access_Line_Low);

    return LED_Data;
}