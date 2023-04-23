#include "main.h"
/**
* print_non_printable - Prints ascii codes in hexa of non printable chars
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
int print_non_printable(va_list type, char buff[],
	int flag, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(type, char *);

	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buff[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buff, i + offset);
		i++;
	}
	buff[i + offset] = '\0';

	return (write(1, buff, i + offset));
}

/**
* print_pointer - Prints the value of a pointer variable
*
* @type: List a of arguments
* @buff: Buffer array to handle print
* @flag: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
*
* Return: Number of chars printed.
*/
int print_pointer(va_list type, char buff[],
	int flag, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(type, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buff[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padd = '0';

	if (flag & F_PLUS)
		extra_c = '+', length++;
	else if (flag & F_SPACE)
		extra_c = ' ', length++;
	ind++;

	return (write_pointer(buff, ind, length,
		width, flag, padd, extra_c, padd_start));
}
