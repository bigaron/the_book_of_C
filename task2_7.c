#include <stdio.h>

unsigned invert(unsigned x, int p, int n){
    unsigned res = 0;
    //The start of the bits that need to be inverted
    int start = p - (n-1);
    int flag = 0;

    for(int i = 0; x != 0; ++i){
        //If we are in the area that needs to be inverted we set the flag to 1
        //Otherwise we set it to 0
        if(i >= start && i <= p) flag = 1;
        else flag = 0;

        //If you XOR a bit with 1 you invert it
        //If you XOR it with a 0 you get the other bit back
        res = res << 1;
        res += ((x % 2 == 0) ? 0 : 1) ^ flag;   
        x = x >> 1;
    }

    return res;
}

int main(void){
    printf("%u\n", invert(29U, 2, 3));
    return 0;
}