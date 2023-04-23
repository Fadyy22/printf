#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

int _printf(const char *format, ...);

/** functions0.c */
int print_char(va_list type, char buff[],
	int flag, int width, int precision, int size);
int print_string(va_list type, char buff[],
	int flag, int width, int precision, int size);
int print_percent(va_list type, char buff[],
	int flag, int width, int precision, int size);


/** functions1.c */
int print_int(va_list type, char buff[],
	int flag, int width, int precision, int size);
int print_binary(va_list type, char buff[],
	int flag, int width, int precision, int size);
int print_unsigned(va_list type, char buff[],
	int flag, int width, int precision, int size);
int print_octal(va_list type, char buff[],
	int flag, int width, int precision, int size);
int print_hexadecimal(va_list type, char buff[],
	int flag, int width, int precision, int size);
int print_hexa_upper(va_list type, char buff[],
	int flag, int width, int precision, int size);


/** functions2.c */
int print_non_printable(va_list type, char buff[],
	int flag, int width, int precision, int size);
int print_pointer(va_list type, char buff[],
        int flag, int width, int precision, int size);


int get_flags(const char *format, int *i);

/** UTILS */
int is_printable(char);
int append_hexa_code(char, char[], int);


int handle_write_char(char c, char buff[],
	int flag, int width, int precision, int size);
int write_number(int is_positive, int ind, char buff[],
	int flag, int width, int precision, int size);
int write_pointer(char buff[], int ind, int length,
	int width, int flag, char padd, char extra_c, int padd_start);
int print_hexa(va_list type, char map_to[],
	char buff[], int flag, char flag_ch, int width, int precision, int size);
/*
 **** Funciotns to handle other specifiers */
int get_size(const char *format, int *i);
#endif
