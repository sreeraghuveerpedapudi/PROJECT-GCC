/* Perform all types of Bit Wise Operations : */
/* Clear Bit, Set Bit, Nibble Swap, Byte Swap */

#include <stdint.h>
#include <stdio.h>

#define CLRBITSETBIT(X, CLR, SET) ((X & ~CLR) | SET)
#define NIBBLESWAP32(X) (X>>4&0x0F0F0F0F|X<<4&0xF0F0F0F0)
#define NIBBLESWAP16(X) (X>>4&0x0F0F|X<<4&0xF0F0)
#define NIBBLESWAP08(X) (X>>4&0x0F|X<<4&0xF0)
#define ENDIANSWAP16(X) (X>>8&0x00FF|X<<8&0xFF00)
#define ENDIANSWAP32(X) (X>>24&0x000000FF|X>>8&0x0000FF00|X<<8&0x00FF0000|X<<24&0xFF000000)

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
    printf("CLRBITSETBIT : %X\n", CLRBITSETBIT(0xFFFF0000, 0xFFFF0000, 0x0000FFFF));
    
    printf("NIBBLESWAP32 : %X\n", NIBBLESWAP32(0x12345678U));
    printf("NIBBLESWAP16 : %X\n", NIBBLESWAP16(0x1234));
    printf("NIBBLESWAP08 : %X\n", NIBBLESWAP08(0x12));
    
    printf("ENDIANSWAP16 : %X\n", ENDIANSWAP16(0x1234));
    printf("ENDIANSWAP32 : %X\n", ENDIANSWAP32(0x12345678U));
    
    LookUpTableInit();
    uint32_t Data = 0x3;
    printf("Count Set Bits : %02d\n", CountSetBits(Data));
    printf("Count Clr Bits : %02d\n", sizeof(uint32_t)*8-CountSetBits(Data));
    
    return;
}

/* ------OUTPUT------

CLRBITSETBIT : FFFF
NIBBLESWAP32 : 21436587
NIBBLESWAP16 : 2143
NIBBLESWAP08 : 21
ENDIANSWAP16 : 3412
ENDIANSWAP32 : 78563412
Count Set Bits : 02
Count Clr Bits : 30

------OUTPUT------ */
