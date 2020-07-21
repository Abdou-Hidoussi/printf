#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"
/**
*_print_o - 0
*@d: unsigned
*Return: int
*/
int _print_o(unsigned int d)
{
int i, j = 0;
char *s;

s = malloc(sizeof(char) * 8);
for (i = 0; d / 8 != 0; ++i)
{
s[i] = d % 8 + '0';
d /= 8;
j++;
}
s[i] = d % 8 + '0';
for (; i >= 0; --i)
{
_putchar(s[i]);
}
return (j + 1);
}
/**
*_print_x - 0
*@d: unsigned
*Return: int
*/
int _print_x(unsigned int d)
{
int i, j = 0;
char *s;

s = malloc(sizeof(char) * 8);
for (i = 0; d / 16 != 0; ++i)
{
if (d % 16 > 9)
{
s[i] = d % 16 + 'a' - 10;
}
else
{
s[i] = d % 16 + '0';
}
d /= 16;
j++;
}
if (d % 16 > 9)
{
s[i] = d % 16 + 'a' - 10;
}
else
{
s[i] = d % 16 + '0';
}
for (; i >= 0; --i)
{
_putchar(s[i]);
}
return (j + 1);
}
/**
*_print_x - 0
*@d: unsigned
*Return: int
*/
int _print_X(unsigned int d)
{
int i, j = 0;
char *s;

s = malloc(sizeof(char) * 8);
for (i = 0; d / 16 != 0; ++i)
{
if (d % 16 > 9)
{
s[i] = d % 16 + 'A' - 10;
}
else
{
s[i] = d % 16 + '0';
}
d /= 16;
j++;
}
if (d % 16 > 9)
{
s[i] = d % 16 + 'A' - 10;
}
else
{
s[i] = d % 16 + '0';
}
for (; i >= 0; --i)
{
_putchar(s[i]);
}
return (j + 1);
}
