#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define F_MINUS 1
#define BUFF_SIZE 1024
int _printf(const char *format, ...);
/**
 * function0.c
 */
int print_char(va_list type, char buff[],
	int flag, int width, int precision, int size);
int print_string(va_list type, char buff[],
	int flag, int width, int precision, int size);
int print_percent(va_list type, char buff[],
	int flag, int width, int precision, int size);
int handle_write_char(char c, char buff[],
	int flag, int width, int precision, int size);
int write_number(int is_positive, int ind, char buff[],
	int flag, int width, int precision, int size);


#endif
