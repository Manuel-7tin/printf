#include "printf.h"

/**
 * print_str - Prints a string to the console
 *
 * @s: The string to be printed
 *
 * Return: int, length of string
 */

int print_str(char *s)
{
	if (s == NULL)
		return (1);
	write(1, s, strlen(s));
	return (strlen(s));
}

/**
 * reverse_str - reverses a string
 *
 * @s: The string to b reversed
 * @l: length of string
 * @num: to know if @s is a string of numbers or words
 *
 * Return: The resulting string
 */

char *reverse_str(char *s, int j, int num)
{
	int n, i = 0;
	char k;

	if (num && s[i] == '-')
		i++;
	for (n = 0; n < j; n++)
	{
		k = s[i];
		s[i] = s[j - 1];
		s[j - 1] = k;
		j--;
		i++;
	}
	return (s);
}
