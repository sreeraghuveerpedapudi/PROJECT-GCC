// Online C compiler to run C program online
#include <stdio.h>
#include <stdint.h>

// 2, 5, 6, 3, 8, 1 Output : 6

uint32_t FindSecondLargest(uint32_t *Array, uint8_t Length)
{
    uint32_t Second = Array[0], Largest = Array[0];
    uint8_t Index = 0;
    
    for(Index=1; Index<Length; Index++)
    {
        if(Largest < Array[Index])
        {
            Second = Largest;
            Largest = Array[Index];
        }
        else if(Second < Array[Index])
        {
            Second = Array[Index];
        }
    }
    
    return Second;
}

int main() {
    uint32_t Array[10] = {2, 5, 1, 3, 6, 8,};
    // Write C code here
    printf("Second Largest Number %d", FindSecondLargest(Array, 10));

    return 0;
}
