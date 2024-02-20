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


typedef uint8_t Uint8;
typedef uint16_t Uint16;
typedef uint32_t Uint32;

typedef struct Render{
    Uint8 Common_Line_One;
    Uint8 Common_Line_Two;
    Uint8 Access_Line_one;
    Uint8 Access_Line_Two;
}Render;

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

typedef struct TensOnes{
    Uint8 HourOnes;
    Uint8 HourTens;
    Uint8 MinuteOnes;
    Uint8 MinuteTens;
}TensOnes;

extern Render renderer_outputs;
extern TensOnes tod_outputs;
extern BlockSet NumberBlocks;


Uint8 Time_deconstruct(const Uint8 access_line, const Uint8 hours, const Uint8 minutes, TensOnes *output);


Uint8 DigitAssembler(const Uint8 character_line,const BlockSet *Block, const Uint8 time);


Uint8 Brightness(Uint8 access_line);


void Renderer(Uint8 left_common_line, Uint8 right_common_line, Uint8 access_line, Render *shift_reg_outputs);
# 7 "rendering.c" 2


extern BlockSet NumberBlocks = {
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

extern TensOnes tod_outputs = {
    .HourOnes = 0,
    .HourTens = 0,
    .MinuteOnes = 0,
    .MinuteTens = 0
};

extern Render renderer_outputs = {
   .Common_Line_One = 0,
   .Common_Line_Two = 0,
   .Access_Line_one = 0,
   .Access_Line_Two = 0
};


Uint8 Time_deconstruct(const Uint8 access_line, const Uint8 hours, const Uint8 minutes, TensOnes *output){
   static Uint8 character_line = 0;

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


Uint8 DigitAssembler(const Uint8 character_line,const BlockSet *Block, const Uint8 digit){
    Uint8 Output = 0;
# 257 "rendering.c"
    return Output;

}





void Renderer(Uint8 left_common_line, Uint8 right_common_line, Uint8 access_line, Render *shift_reg_outputs){

   if(access_line < 8){
      shift_reg_outputs->Access_Line_one = 0b10000000 >> access_line;
      shift_reg_outputs->Access_Line_Two = 0;
   }else{
      shift_reg_outputs->Access_Line_one = 0;
      shift_reg_outputs->Access_Line_Two = 0b10000000 >> (access_line - 8);
   }

   shift_reg_outputs->Common_Line_One = left_common_line;
   shift_reg_outputs->Common_Line_Two = right_common_line;

}
