#ifndef UTIL_H
#define UTIL_H

#include "../cpu/types.h"

void memory_copy(char* source, char* dest, int n_bytes);
void memory_set(u8 *dest, u8 val, u32 len);

void int_to_ascii(int n, char str[]);
void ascii_to_int(int n, char str[]);

void str_rev(char str[]);

int str_len(char str[]);

#endif
