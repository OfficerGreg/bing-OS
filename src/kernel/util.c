#include "util.h"
#include "types.h"

void memory_copy(char* source, char* dest, int n_bytes){
    for(int i = 0; i < n_bytes; i++){
        *(dest + i) = *(source+i);
    }
}

void memory_set(u8 *dest, u8 val, u32 len){
    u8 * temp = (u8 *)dest;
    for(len; len != 0; len--){
        *temp++ = val;
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