#include <stdio.h>
#include <stdbool.h>

bool containedChar(const char c, const char arr[]){
    int i = 0;
    while(arr[i] != '\0') if(arr[i++] == c) return true;

    return false;
}

void squeeze(char src[], const char set[]){
    int i, j;
    for(i = j = 0; src[i] != '\0'; i++)
        if(!containedChar(src[i], set)) 
            src[j++] = src[i];

    src[j] = '\0';
}

int main(void){
    char src[] = "alma";
    squeeze(src, "a");
    printf("%s\n", src);
    return 0;
}