#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "_printf.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
*_strlen - 0
*@s: char
*Return:: i
*/
int _strlen(const char *s)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}
/**
*print_str - 0
*@str: char
*
*/
void print_str(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
/**
*_printf - 0
*@s: char
*Return: length
*/
int _printf(const char *s, ...)
{
	va_list ap;

	va_start(ap, 0);
	for (int i = 0; i < _strlen(s); ++i)
	{
		if (s[i] == '%')
		{
			switch (s[i + 1])
			{
				case 'c':
					_putchar(va_arg(ap, int));
					i += 2;
					break;
				case 's':
					print_str(va_arg(ap, char*));
					i += 2;
					break;
			}
		}
		_putchar(s[i]);
	}
	va_end(ap);
	return (_strlen(s));
}
