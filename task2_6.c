#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y){
    unsigned partition = 0;
    //We retrieve the n long part from y or the y itself if n > than log2(y) 
    for(int i = 0; i < n && y != 0; ++i){
        partition = partition << 1;
        //we add 1 or 0 depending on what the value of the last bit of y is
        partition += (y % 2 == 0) ? 0 : 1;
        y = y >> 1;
    }
    for(int i = 0; i < p-(n-1); ++i) partition = partition << 1;
    //Or-ing with 0 will return the other value, and the partition has 
    //non 0 values only in the from p, n number of bits set to values it will only change
    //The desired bits in x
    x |= partition;

    return x;
}

int main(void){

    unsigned ret = setbits(12U, 7, 2, 3U);
    printf("%u\n", ret);
    return 0;
}