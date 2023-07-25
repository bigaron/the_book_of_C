#include <stdio.h>
#include <stdbool.h>

unsigned invert(unsigned x, int p, int n){
    unsigned res = 0;
    unsigned cntr = 0;
    unsigned val;
    bool finished = false;
    //The start of the bits that need to be inverted
    int start = p - (n-1);
    int flag = 0;

    for(int i = 0; true; ++i){
        //If we are in the area that needs to be inverted we set the flag to 1
        //Otherwise we set it to 0
        if(i >= start && i <= p) flag = 1;
        else flag = 0;

        //If you XOR a bit with 1 you invert it
        //If you XOR it with a 0 you get the other bit back
        val = ((x % 2 == 0) ? 0 : 1) ^ flag;
        for(int j = 0; val != 0 && j < cntr; j++) val = val << 1;
        cntr++;
        res += val;   
        if(finished) break;
        x = x >> 1;
        if(x == 0 && i > p) finished = true;
    }

    return res;
}

int main(void){
    printf("%u\n", invert(14U, 4, 5));
    return 0;
}