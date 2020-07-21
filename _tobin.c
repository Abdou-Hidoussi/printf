
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"
/**
*_tobin - 0
*@d: unsigned int
*Return: int
*/
int _tobin(unsigned int d)
{
    int i, j = 0;
    char *s;

    s = malloc(sizeof(char)*8);
    for (i = 0; d / 2 != 0; ++i)
    {
        s[i] = d % 2 + '0';
        d /= 2;
        j++;
    }
    s[i] = d % 2 + '0';
    for (; i >= 0; --i)
    {
        _putchar(s[i]);
    }
    free(s);
    return (j + 1);
}
