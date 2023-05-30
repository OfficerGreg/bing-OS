#include "util.h"

void memory_copy(char* source, char* dest, int n_bytes){
    for(int i = 0; i < n_bytes; i++){
        *(dest + i) = *(source+i);
    }
}

void int_to_ascii(int n, char str[]) {
    int i, sign;
    if ((sign = n) < 0) n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';
}

void ascii_to_int(int n, char str[]){
    
}

void str_rev(char str[]){
    int length = str_length(str);

    for(int i = 0; i < length/2; i++){
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int str_length(char str[]){
    int count;
    for(count = 0; str[count] != '\0'; count++);

    return count;
}