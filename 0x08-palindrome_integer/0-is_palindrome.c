#include "palindrome.h"
/**
 * is_palindrome - Entry point
 *
 * @n: number to check
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int is_palindrome(unsigned long n)
{
	unsigned long l, r;

	while (n != 0)
	{
		r = n % 10;
		l = l * 10 + r;
		n /= 10;
	}
	return (n == l);
}
