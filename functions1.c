#include "main.h"

/**
* print_unsigned - Prints an unsigned number
*
* @type: List of arguments
* @buff: Buffer array to handle print
* @flag: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
*
* Return: Number of chars
*/
int print_unsigned(va_list type, char buff[],
	int flag, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);

	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buff[i--] = '0';
	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buff, flag, width, precision, size));
}

/**
* print_octal - Prints an unsigned number in octal notation
*
* @type: List of arguments
* @buff: Buffer array to handle print
* @flag: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
*
* Return: Number of chars
*/
int print_octal(va_list type, char buff[],
	int flag, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buff[i--] = '0';
	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flag & F_HASH && init_num != 0)
		buff[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buff, flag, width, precision, size));
}

/**
* print_hexadecimal - Prints an unsigned number in hexadecimal notation
*
* @type: List of arguments
* @buff: Buffer array to handle print
* @flag: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
*
* Return: Number of chars
*/
int print_hexadecimal(va_list type, char buff[],
	int flag, int width, int precision, int size)
{
	return (print_hexa(type, "0123456789abcdef", buff,
		flag, 'x', width, precision, size));
}

/**
* print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
*
* @type: List of arguments
* @buff: Buffer array to handle print
* @flag: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
*
* Return: Number of chars
*/
int print_hexa_upper(va_list type, char buff[],
	int flag, int width, int precision, int size)
{
	return (print_hexa(type, "0123456789ABCDEF", buff,
		flag, 'X', width, precision, size));
}

/**
* print_hexa - Prints a hexadecimal number in lower or upper
*
* @type: List of arguments
* @map_to: Array of values to map the number to
* @buff: Buffer array to handle print
* @flag: Calculates active flags
* @flag_ch: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* @size: Size specification
*
* Return: Number of chars
*/
int print_hexa(va_list type, char map_to[], char buff[],
	int flag, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buff[i--] = '0';
	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flag & F_HASH && init_num != 0)
	{
		buff[i--] = flag_ch;
		buff[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buff, flag, width, precision, size));
}
