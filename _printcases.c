#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "holberton.h"
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
*print_int - 0
*@n: int
*Return: num of written chars
*/
int print_int(int n)
{
	long int i, r, j = 0, t = 0;

	i = n;
	r = 0;
	if (n > 0)
	{
		i = n;
	}
	else if (n < 0)
	{
		i = -n;
		_putchar('-');
		j++;
		t++;
	}
	if (n != 0)
	{
		while (i > 0)
		{
			r = (r * 10) + (i % 10);
			i = i / 10;
			j++;
			t++;
		}
		while (r > 0)
		{
			_putchar(r % 10 + '0');
			r = r / 10;
			j--;
		}
	}
	else
	{
		_putchar('0');
		t++;
	}
	return (t);

}
