#include "palindrome.h"
/**
 * is_palindrome - Entry point
 *
 * @n: number to check
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int is_palindrome(unsigned long n)
{
	int div = 1, l, r;

	while (n / div >= 10)
	{
		div *= 10;
	}
	while (n != 0)
	{
		l = n / div;
		r = n % 10;
		if (l != r)
			return (0);
		n = (n % div) / 10;
		div /= 100;
	}
	return (1);
}
