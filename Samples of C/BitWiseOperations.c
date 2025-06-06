// Online C compiler to run C program online
#include <stdio.h>
#include <stdint.h>

#define NIBBLESWAP(X) (X>>4|X<<4)
#define ENDIANSWAP(X) (X>>4|X<<4)

#define TABLE_LENGTH 256
uint8_t LookUpTable[256];

void LookUpTableInit(void)
{
    uint32_t Index = 0;
    
    for(Index = 0; Index < TABLE_LENGTH; Index++)
    {
        LookUpTable[Index] = (Index & 0x01) + LookUpTable[Index/2];
        //printf("%02X:%d\n", Index, LookUpTable[Index]);
    }
}

uint32_t CountSetBits(uint32_t Data)
{
    return LookUpTable[0xFF & Data >> 0  ]+
           LookUpTable[0xFF & Data >> 8  ]+
           LookUpTable[0xFF & Data >> 16 ]+
           LookUpTable[0xFF & Data >> 24 ];
}

void main(void)
{
    printf("NIBBLESWAP : %X\n", (uint32_t)NIBBLESWAP(0xABABABAB));
    printf("NIBBLESWAP : %X\n", (uint16_t)NIBBLESWAP(0xABAB));
    printf("NIBBLESWAP : %X\n", (uint8_t)NIBBLESWAP(0xAB));
    
    LookUpTableInit();
    uint32_t Data = 0xF;
    printf("Count Set Bits : %02d\n", CountSetBits(Data));
    printf("Count Clr Bits : %02d\n", sizeof(uint32_t)*8-CountSetBits(Data));
    
    return;
}
