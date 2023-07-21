#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * returns true if the given number contains a valid hexnumber
 * If it is in the range of 0-9 or a-f
*/
bool ishex(const char c){
    if(isdigit(c)) return true;
    int numbersLen = 6;
    char numbers[] = {'a','b','c','d','e','f'};
    for(int i = 0; i < numbersLen; ++i) 
        if(c == numbers[i]) return true;

    return false;
}

/**
 * returns the value of the hexadecimal in decimal or null
 *  if it wasnt a valid value
*/
int hexval(const char c){
    if(isdigit(c)) return c - '0';
    int numbersLen = 6;
    char numbers[] = {'a','b','c','d','e','f'};
    for(int i = 0; i < numbersLen; ++i) 
        if(c == numbers[i]) return c - 'a' + 10;

    return -1;
}

/**
 * Converts the hexa number in s to integer and returns it
*/
int htoi(const char s[]){
    int i = 0;
    char curr;
    int result = 0;
    //We iterate through the string
    while(s[i] != '\0'){
        curr = (char)tolower(s[i]);
        i++;
        if(curr == 'x' && i > 1 && s[i - 2] == '0') continue;
    
        if(!ishex(curr)) return result;

        result = result * 16 + hexval(curr);
    }

    return result;
}

int main(void){

    printf("%d\n", htoi("0xFf"));

    return 0;
}