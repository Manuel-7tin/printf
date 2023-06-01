#ifndef PRINTF_H
#define PRINTF_H
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h> 
#include <limits.h>
#include <stdint.h>

int _printf(char *l, ...);
int print_str(char *s);
char *int_to_str(int n);
char *unsigned_int_to_str(unsigned int n);
char *reverse_str(char *s, int j, int num);
char *int_to_hex(int n, char c);
char *int_to_oct(unsigned int n);
char *ptr_to_hex(void* ptr);
int add(int a, int b);
#endif /*PRINTF_H*/
