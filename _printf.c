#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "holberton.h"
/**
*cases - 0
*@ap: list of arguments
*@s: string
*@i: position of char
*@r: num written chars
*Return: length
*/
void cases(va_list ap, const char *s, int *i, int *r)
{
	char *ch;

	switch (s[*i + 1])
	{
		case 'c':
			_putchar(va_arg(ap, int));
			*i += 1;
			*r -= 1;
			break;
		case 's':
			ch = va_arg(ap, char*);
			print_str(ch);
			*r += _strlen(ch);
			*i += 1;
			*r -= 2;
			break;
		case '%':
			_putchar('%');
			*i += 1;
			*r -= 1;
			break;
		case 'i':
			*r += print_int(va_arg(ap, int));
			*i += 1;
			*r -= 2;
			break;
		default:
			_putchar(s[*i]);
			break;
	}
}
/**
*_printf - 0
*@s: char
*Return: length
*/
int _printf(const char *s, ...)
{
	int i, l = _strlen(s), r = 0;
	va_list ap;

	va_start(ap, 0);
	for (i = 0; i < l; i++)
	{
		if (s[i] != '%' || (s[i] == '%' && s[i + 1] == '\0'))
			_putchar(s[i]);
		else
		{
			cases(ap, s, &i, &r);
		}
	}
	r += l;
	va_end(ap);
	return (r);
}
