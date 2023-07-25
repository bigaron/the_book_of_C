#include <stdio.h>
#include <math.h>

int rightrot(int x, int n){
    //We get the length of the number in bits
    char len = (char)log2((double)x);
    int val;

    for(int i = 0; i < n; ++i){
        val = x % 2 == 0 ? 0 : 1;
        x = x >> 1;
        for(int j = 0; j < len; ++j) val = val << 1;
        x += val;
    }

    return x;
}

int main(void){
    printf("%d\n", rightrot(11, 4));

    return 0;
}