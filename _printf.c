#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "holberton.h"
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
	while (*s != '\0' && s)
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
	int i, l = 0, r = 0;
	char *ch;
	va_list ap;

	l = _strlen(s);
	va_start(ap, 0);
	for (i = 0; i < l; i++)
	{
		if (s[i] != '%' || (s[i] == '%' && s[i + 1] == '\0'))
			_putchar(s[i]);
		else
		{
			switch (s[i + 1])
			{
				case 'c':
					_putchar(va_arg(ap, int));
					i += 1;
					r -= 1;
					break;
				case 's':
					ch = va_arg(ap, char*);
					print_str(ch);
					r += _strlen(ch);
					i += 1;
					r -= 2;
					break;
				case '%':
					_putchar('%');
					i += 1;
					r -= 1;
					break;
			}
		}
	}
	r += l;
	va_end(ap);
	return (r);
}
