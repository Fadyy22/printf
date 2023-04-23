#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define F_MINUS 1
int _printf(const char *format, ...);

/** functions0.c */
int print_char(va_list type, char buff[],
	int flag, int width, int precision, int size);
int print_string(va_list type, char buff[],
	int flag, int width, int precision, int size);
int print_percent(va_list type, char buff[],
	int flag, int width, int precision, int size);
int handle_write_char(char c, char buff[],
	int flag, int width, int precision, int size);


/** functions1.c */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/** functions2.c */
int print_non_printable(va_list type, char buff[],
	int flag, int width, int precision, int size);



/** UTILS */
int is_printable(char);
int append_hexa_code(char, char[], int);



int print_hexa(va_list types, char map_to[],
	char buffer[], int flags, char flag_ch, int width, int precision, int size);

#endif
