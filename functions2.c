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

	UNUSED(flags);
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

