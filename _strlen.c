#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "holberton.h"
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
