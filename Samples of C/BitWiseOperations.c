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

#define CLRREGISBITS(X, CLR) (X & ~CLR)
#define SETREGISBITS(X, SET) (X | SET)
#define TOGREGISBITS(X, TOG) (X ^ TOG)

#define CLRAREGISBIT(X, BIT) (~(1<<BIT) & X)
#define SETAREGISBIT(X, BIT) ( (1<<BIT) | X)
#define TOGAREGISBIT(X, BIT) ( (1<<BIT) ^ X)

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
    printf("INPUTDATABIT : 0x%08X\n", 0xFFFF0000);
    printf("CLRBITSETBIT : 0x%08X\n", CLRBITSETBIT(0xFFFF0000, 0xFFFF0000, 0x0000FFFF));
    printf("\n");
    printf("NIBBLESWAP32 : 0x%08X\n", NIBBLESWAP32(0x12345678U));
    printf("NIBBLESWAP16 : 0x%04X\n", NIBBLESWAP16(0x1234));
    printf("NIBBLESWAP08 : 0x%02X\n", NIBBLESWAP08(0x12));
    printf("\n");
    printf("ENDIANSWAP16 : 0x%04X\n", ENDIANSWAP16(0x1234));
    printf("ENDIANSWAP32 : 0x%08X\n", ENDIANSWAP32(0x12345678U));
    printf("\n");
    LookUpTableInit();
    uint32_t Data = 0x00A5A500;
    printf("COUNTSETBITS : 0x%02X\n", CountSetBits(Data));
    printf("COUNTCLRBITS : 0x%02X\n", sizeof(uint32_t)*8-CountSetBits(Data));
    printf("\n");
    printf("CLRREGISBITS : 0x%08X\n", CLRREGISBITS(0xFFFF0000, 0xFFFF0000));
    printf("SETREGISBITS : 0x%08X\n", SETREGISBITS(0xFFFF0000, 0x0000FFFF));
    printf("TOGREGISBITS : 0x%08X\n", TOGREGISBITS(0xFFFF0000, 0xFF00FF00));
    printf("\n");
    printf("CLRAREGISBIT : 0x%08X\n", CLRAREGISBIT(0xFFFF, 3));
    printf("SETAREGISBIT : 0x%08X\n", SETAREGISBIT(0xFFF7, 3));
    printf("TOGAREGISBIT : 0x%08X\n", TOGAREGISBIT(0xFFFF, 3));
    return;
}

/* ------OUTPUT------

INPUTDATABIT : 0xFFFF0000
CLRBITSETBIT : 0x0000FFFF

NIBBLESWAP32 : 0x21436587
NIBBLESWAP16 : 0x2143
NIBBLESWAP08 : 0x21

ENDIANSWAP16 : 0x3412
ENDIANSWAP32 : 0x78563412

COUNTSETBITS : 0x08
COUNTCLRBITS : 0x18

CLRREGISBITS : 0x00000000
SETREGISBITS : 0xFFFFFFFF
TOGREGISBITS : 0x00FFFF00

CLRAREGISBIT : 0x0000FFF7
SETAREGISBIT : 0x0000FFFF
TOGAREGISBIT : 0x0000FFF7

------OUTPUT------ */
