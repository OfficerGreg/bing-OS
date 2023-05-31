#include "string.h"


void int_to_ascii(int n, char str[]){
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
    int length = str_len(str);

    for(int i = 0; i < length/2; i++){
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int str_len(char str[]){
    int count; 
    for(count = 0; str[count] != '\0'; count++); 
    
    return count;
}

void backspace(char str[]) {
    int len = str_len(str);
    str[len-1] = '\0';
}

char chrupper(char chr) {
  if((chr>96) && (chr<123)) chr ^=0x20;
  return chr;
}

void append(char str[], char n) {
    int len = str_len(str);
    str[len] = n;
    str[len+1] = '\0';
}

int str_cmp(char str_1[], char str_2[]) {
    int i;
    for (i = 0; str_1[i] == str_2[i]; i++) {
        if (str_1[i] == '\0') return 0;
    }
    return str_1[i] - str_2[i];
}