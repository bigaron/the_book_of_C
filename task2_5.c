#include <stdio.h>
#include <stdbool.h>

bool containsChar(char c, const char set[]){
    int i = 0;
    while(set[i] != '\0') if(set[i++] == c) return true;

    return false;
}

int any(const char src[], const char trgt[]){
    int i = 0;
    while(src[i] != '\0'){
        if(containsChar(src[i], trgt)) return i;
        i++;
    }

    return -1;
}

int main(void){
    printf("%d\n", any("alma", "bvc"));
    return 0;
}