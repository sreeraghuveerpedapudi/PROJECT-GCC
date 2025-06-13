// Online C compiler to run C program online
#include <stdio.h>
#include <stdint.h>

#define MODIFY_REG(REG, CLEARMASK, SETMASK) ((REG & ~(CLEARMASK)) | (SETMASK))
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
    printf("SET AND CLEAR BITS OF A REGISTER : %X\n", MODIFY_REG(0xFFFF0000, 0xFFFF0000, 0x0000FFFF));
    
    printf("NIBBLESWAP : %X\n", NIBBLESWAP32(0x12345678U));
    printf("NIBBLESWAP : %X\n", NIBBLESWAP16(0x1234));
    printf("NIBBLESWAP : %X\n", NIBBLESWAP08(0x12));
    
    printf("ENDIANSWAP : %X\n", ENDIANSWAP16(0x1234));
    printf("ENDIANSWAP : %X\n", ENDIANSWAP32(0x12345678U));
    
    LookUpTableInit();
    uint32_t Data = 0x3;
    printf("Count Set Bits : %02d\n", CountSetBits(Data));
    printf("Count Clr Bits : %02d\n", sizeof(uint32_t)*8-CountSetBits(Data));
    
    return;
}

/* ------OUTPUT------

NIBBLESWAP : 21436587
NIBBLESWAP : 2143
NIBBLESWAP : 21
ENDIANSWAP : 3412
ENDIANSWAP : 78563412
Count Set Bits : 02
Count Clr Bits : 30

------OUTPUT------ */
