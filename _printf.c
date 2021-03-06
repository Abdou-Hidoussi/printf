#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "holberton.h"
/**
*delcases - 0
*@ap: list of arguments
*@s: string
*@i: position of char
*@r: num written chars
*Return: length
*/
void delcases(va_list ap, const char *s, int *i, int *r)
{
	switch (s[*i + 1])
	{
		case 'i':
			*r += print_int(va_arg(ap, int));
			*i += 1;
			*r -= 2;
			break;
		case 'd':
			*r += print_int(va_arg(ap, int));
			*i += 1;
			*r -= 2;
			break;
		case 'b':
			*r += _tobin(va_arg(ap, int));
			*i += 1;
			*r -= 2;
			break;
		case 'o':
			*r += _print_o(va_arg(ap, int));
			*i += 1;
			*r -= 2;
			break;
		case 'x':
			*r += _print_x(va_arg(ap, int));
			*i += 1;
			*r -= 2;
			break;
		case 'X':
			*r += _print_X(va_arg(ap, int));
			break;
		default:
			_putchar(s[*i]);
			break;
	}
}
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
		default:
			delcases(ap, s, i, r);
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
