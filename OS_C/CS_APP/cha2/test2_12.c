/* mask */
#include<stdio.h>

int main() {
    int x = 0x87654321;
    //0x00000021
    //x = x & 0xFF;
    //0x789ABC21
    //x = x^~0xFF;
    //0x876543FF
    x = x | 0xFF;
    printf("%X\n",x);

    return 0;
}
