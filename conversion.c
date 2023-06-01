#include "printf.h"

/**
 * int_to_str - converts an integer to a string
 *
 * @n: The integer to be converted tro a string
 *
 * Return: converted string
 */

char *int_to_str(int n)
{
	char *str;
	int i = 0, rm;

	str = malloc(12);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[i++] = '-';
		n = n * -1;
	}
	do{
		rm = n % 10;
		str[i++] = rm + '0';
		n /= 10;
	} while (n > 0);
	str[i] = '\0';
	return (reverse_str(str, strlen(str), 1));
}

/**
 * unsigned_int_to_str - converts unsigned integer to a string
 *
 * @n: The unsigned integer to be converted
 *
 * Return: The converted string
 */

char *unsigned_int_to_str(unsigned int n)
{
	char *str;
	unsigned int i = 0, rm;

	str = malloc(12);
	if (str == NULL)
		return (NULL);
	do{
		rm = n % 10;
		str[i++] = rm + '0';
		n /= 10;
	} while (n > 0);
	str[i] = '\0';
	return(reverse_str(str, strlen(str), 1));
}

/**
 * int_to_hex - converts integer to hexadecimal format
 *
 * @n: The integer to be converted
 * @x: Hexadecima	l format specifier
 *
 * Return: The string of hex number
 */

char *int_to_hex(int n, char c)
{
	char* hex;
	int i;
	char *hex_char = "0123456789ABCDEF";

	hex = malloc(sizeof(int) * 2 + 1);
	if (hex == NULL)
		return (NULL);
	if (c == 'x')
		hex_char = "0123456789abcdef";
	for (i = sizeof(int) * 2 - 1; i >= 0; i--)
	{
		int digit = (n >> (i * 4)) & 0xF;
		hex[sizeof(int) * 2 - i - 1] = hex_char[digit];
	}
	hex[sizeof(int) * 2] = '\0';
	return(hex);
}

/**
 * int_to_oct - converts integer to octaldecima	l format
 *
 * @n: The integer to be converted
 *
 * Return: The string of octal nummber
 */

char *int_to_oct(unsigned int n)
{
	char* str;
	int i = 0;
	unsigned int quotient, remainder;
	char num_char[9] = "01234567";

	str = malloc(13);
	if (str == NULL)
		return (NULL);
	do{
		remainder = n % 8;
		quotient = (n - remainder) / 8;
		str[i] = num_char[remainder];
		i++;
		n = quotient;
	} while (n > 0);
	return (reverse_str(str, strlen(str), 1));
}

/**
 * ptr_to_hex - ges the hex value of a pointer
 *
 * @ptr: the pointer
 *
 * Return: the string of hex value created
 */

char *ptr_to_hex(void* ptr)
{
	const uint64_t p = (uint64_t) ptr;
	const size_t hex_size = sizeof(uint64_t) * 2;

	char* hex_str = malloc(hex_size + 1);
	if (hex_str == NULL)
		return (NULL);
	char* p_hex = &hex_str[hex_size - 1];
	for (int i = 0; i < hex_size; i++)
	{
		const uint8_t digit = (p >> (i * 4)) & 0xF;
		*p_hex-- = "0123456789abcdef"[digit];
	}
	hex_str[hex_size] = '\0';
	return hex_str;
}
