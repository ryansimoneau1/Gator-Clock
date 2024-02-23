# 1 "rendering.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.45\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "rendering.c" 2






# 1 "./rendering.h" 1
# 11 "./rendering.h"
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.45\\pic\\include\\c99\\stdint.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.45\\pic\\include\\c99\\musl_xc8.h" 1 3
# 5 "C:\\Program Files\\Microchip\\xc8\\v2.45\\pic\\include\\c99\\stdint.h" 2 3
# 26 "C:\\Program Files\\Microchip\\xc8\\v2.45\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.45\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 133 "C:\\Program Files\\Microchip\\xc8\\v2.45\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned short uintptr_t;
# 148 "C:\\Program Files\\Microchip\\xc8\\v2.45\\pic\\include\\c99\\bits/alltypes.h" 3
typedef short intptr_t;
# 164 "C:\\Program Files\\Microchip\\xc8\\v2.45\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 194 "C:\\Program Files\\Microchip\\xc8\\v2.45\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 235 "C:\\Program Files\\Microchip\\xc8\\v2.45\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 27 "C:\\Program Files\\Microchip\\xc8\\v2.45\\pic\\include\\c99\\stdint.h" 2 3

typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 148 "C:\\Program Files\\Microchip\\xc8\\v2.45\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.45\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 149 "C:\\Program Files\\Microchip\\xc8\\v2.45\\pic\\include\\c99\\stdint.h" 2 3
# 11 "./rendering.h" 2
# 31 "./rendering.h"
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
# 59 "./rendering.h"
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







void DisplayBuffGen(const CharacterSet* Characters, Uint8 digit, Uint8 *DisplayBuffer);


DisplayBrightness BrightnessCTRL(Uint8 access_line);


Uint8 ReverseByte(Uint8 byte);


RendererOutputs Renderer(Uint8 access_line, Uint8 time_Slot, Uint8 *DisplayBuffer);
# 7 "rendering.c" 2

const CharacterSet Characters = {

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
# 118 "rendering.c"
void DisplayBuffGen(const CharacterSet* Characters, Uint8 digit, Uint8 *DisplayBuffer){
    Uint8* Ptr = 0;

    for(Uint8 i = 0; i < 26; i++){
        DisplayBuffer[i] = 0;
    }

    switch (digit){
        case 0:
            Ptr = Characters->CharacterZero;
        case 1:
            Ptr = Characters->CharacterOne;
        case 2:
            Ptr = Characters->CharacterTwo;
        case 3:
            Ptr = Characters->CharacterThree;
        case 4:
            Ptr = Characters->CharacterFour;
        case 5:
            Ptr = Characters->CharacterFive;
        case 6:
            Ptr = Characters->CharacterSix;
        case 7:
            Ptr = Characters->CharacterSeven;
        case 8:
            Ptr = Characters->CharacterEight;
        case 9:
            Ptr = Characters->CharacterNine;
        case 10:
            Ptr = Characters->CharacterDots;
    }

    for(Uint8 i = 0; i < 26; i++){
        DisplayBuffer[i] = Ptr[i];
    }

}


DisplayBrightness BrightnessCTRL(Uint8 AccessLine){
    DisplayBrightness LEDBrightness = {
    .LED_Left_Brightness = 2,
    .LED_Right_Brightness = 3
    };
    if(AccessLine > 5){
        LEDBrightness.LED_Left_Brightness = 3;
    }
    if(AccessLine == 12){
        LEDBrightness.LED_Left_Brightness = 1;
    }
    if(AccessLine < 7){
        LEDBrightness.LED_Right_Brightness = 2;
    }
    if(AccessLine == 0){
        LEDBrightness.LED_Right_Brightness = 1;
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


RendererOutputs Renderer(Uint8 access_line, Uint8 time_Slot, Uint8 *DisplayBuffer){

RendererOutputs LED_Data = {
    .Left_Common_Line_Data = 0,
    .Right_Common_Line_Data = 0,
    .AccessLine.Full_Access_Line = (1 << access_line)

};

Uint8 Left_DisplayData[13] = {0};
Uint8 Right_DisplayData[13] = {0};

for(Uint8 i = 0; i < 13; i++){
    Left_DisplayData[i] = DisplayBuffer[i];
    Right_DisplayData[i] = DisplayBuffer[i + 13];
}

DisplayBrightness LEDBrightness = BrightnessCTRL(access_line);

if(LEDBrightness.LED_Left_Brightness >= time_Slot){
    LED_Data.Left_Common_Line_Data = Left_DisplayData[access_line];

}else{
    LED_Data.Left_Common_Line_Data = 0;
}

if(LEDBrightness.LED_Right_Brightness >= time_Slot){
    LED_Data.Right_Common_Line_Data = Right_DisplayData[access_line];

}else{
    LED_Data.Right_Common_Line_Data = 0;
}


LED_Data.Left_Common_Line_Data = ReverseByte(LED_Data.Left_Common_Line_Data);
LED_Data.Right_Common_Line_Data = ReverseByte(LED_Data.Right_Common_Line_Data);
LED_Data.AccessLine.AccessLineMembers.Access_Line_High = ReverseByte(LED_Data.AccessLine.AccessLineMembers.Access_Line_High);
LED_Data.AccessLine.AccessLineMembers.Access_Line_Low = ReverseByte(LED_Data.AccessLine.AccessLineMembers.Access_Line_Low);

    return LED_Data;
}
