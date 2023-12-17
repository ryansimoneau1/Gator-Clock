# 1 "rendering.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.45\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "rendering.c" 2
# 10 "rendering.c"
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


Uint8 Hour_deconstruct(const Uint8 access_line, const Uint8 hours);

Uint8 Character_Line(const Uint8 access_line);





Uint8 LHalf_NumBuilder(const Uint8 character_line,const BlockSet *Block, const Uint8 hours);

Uint8 RHalf_NumBuilder(Uint8 access_line,const BlockSet *Block, Uint8 minutes);


Uint8 LHalf_Brightness(Uint8 access_line);

Uint8 RHalf_Brightness(Uint8 access_line);


Uint32 Renderer(Uint8 LH_Num, Uint8 RH_Num, Uint8 LH_Bright, Uint8 RH_Bright);
# 10 "rendering.c" 2


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

Uint8 Hour_deconstruct(const Uint8 access_line, const Uint8 hours){
    static Uint8 Output = 0;

    if(access_line < 6){
        Output = hours / 10;
    }
    else{
        Output = hours % 10;
    }
    return Output;
}

Uint8 Character_Line(const Uint8 access_line){
    static Uint8 character_line = 0;

    if(access_line < 6){
        character_line = access_line;
    }
    else{
        character_line = access_line - 6;
    }

    character_line += 2;
    return character_line;
}
# 87 "rendering.c"
Uint8 LHalf_NumBuilder(const Uint8 character_line,const BlockSet *Block, const Uint8 hours){
    static Uint8 Output = 0;
# 98 "rendering.c"
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

Uint8 RHalf_NumBuilder(Uint8 access_line,const BlockSet *Block, Uint8 minutes){

}
