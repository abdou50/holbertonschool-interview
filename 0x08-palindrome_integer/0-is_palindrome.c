#include "palindrome.h"
/**
 * is_palindrome - Entry point
 *
 * @n: number to check
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int is_palindrome(unsigned long n)
{
	unsigned long l = 0, r, o;

	o = n;
	while (n != 0)
	{
		r = n % 10;
		l = l * 10 + r;
		n /= 10;
	}
	printf("%ld\n", o);
	printf("%ld\n", r);
	printf("%ld\n", l);
	printf("%ld\n", n);
	return (o == l);
}
