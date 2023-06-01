#include "holberton.h"

/**
 * _puts - print each string number
 * @s: string. number
 * Return: void
 */
void _puts(char *s)
{
	if (*s != '\0')
	{
		_putchar(*s);
		puts(s + 1);
	}
}
/**
 * _isdigit - check if s is a number or not.
 * @s: string to check.
 * Return: 0 if s is a number otherwise 1.
 */
int _isdigit(char *s)
{
	int i, digit = 0;

	for (i = 0; s[i] && !digit; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			digit++;
	}
	return (digit);
}
/**
 * operations - multiplies, adds and stores the result in a string.
 * @num1: first number.
 * @num2: second number.
 * @length1: length of num1.
 * @length2: length of num2.
 * Return: result of multiplies.
 */
char *operations(char *num1, char *num2, int length1, int length2)
{
	char *result = NULL;
	int i, j, carry, len_total = (length1 + length2);

	result = malloc(sizeof(char) * len_total);
	if (!result)
	{
		_puts("Error");
		exit(98);
	}
	for (i = 0; i < len_total; i++)
		result[i] = '0';
	for (i = length1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = length2 - 1; j >= 0; j--)
		{
			carry += (num1[i] - '0') * (num2[j] - '0');
			carry += result[i + j + 1] - '0';
			result[i + j + 1] = (carry % 10) + '0';
			carry /= 10;
		}
		if (carry)
			result[i + j + 1] = (carry % 10) + '0';
	}
	return (result);
}
/**
 * main - multiplies two positive numbers.
 * @argv: arguments value (num1, num2)
 * @argc: arguments count
 * Return: 0 if success otherwise 98 and print Error.
 */
int main(int argc, char **argv)
{
	int len1 = 0, len2 = 0;
	char *num1 = argv[1], *num2 = argv[2], *result = NULL;

	if (argc != 3 || _isdigit(num1) || _isdigit(num2))
	{
		_puts("Error");
		exit(98);
	}
	if (argv[1][0] == 48 || argv[2][0] == 48)
	{
		_puts("0");
		exit(0);
	}
	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	result = operations(num1, num2, len1, len2);
	if (result[0] == '0')
		_puts(result + 1);
	else
		_puts(result);
	free(result);
	return (0);
}
