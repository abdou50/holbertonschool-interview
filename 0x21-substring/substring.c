#include <stdlib.h>
#include <stdio.h>

#include "substring.h"
/**
 *find_substring - function
 *@s: is the string to scan
 *@words: is the array of words all substrings must be a concatenation
 *@nb_words: is the number of elements in the array words
 *@n: holds the address at which to store the number of elements
 * Return: 1 or 0
 **/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int len, word_len, j, i = 0, k;
	int *substrings, *found;

	if (!s)
		return (NULL);

	*n = 0;
	len = strlen(s);
	word_len = strlen(words[0]);

	found = malloc(nb_words * sizeof(int));
	substrings = malloc(len * sizeof(int));

	while (i <= len - nb_words * word_len)
	{
		for (j = 0; j < nb_words; j++)
			found[j] = 0;
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				if (found[k] == 0 && strncmp(s + i + j *
					word_len, words[k], word_len) == 0)
				{
					found[k] = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			substrings[(*n)++] = i;
		i++;
	}
	free(found);
	return (substrings);
}
