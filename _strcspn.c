#include "main.h"

/**
 * _strcspn - a function that gets the length of a prefix substring.
 * @s: the string
 * @reject: the prefix string to search
 *
 * Return: the number of bytes in te initial segment of s
 * which consist only of bytes bytes not in reject.
*/
unsigned int _strcspn(char *s, char *reject)
{
	int i, j, found;
	unsigned int n;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		found = 1;
		while (reject[j] != '\0')
		{
			if (s[i] != reject[j])
			{
				found = 0;
				n++;
				break;
			}
			j++;
		}
		if (found)
			break;
		i++;
	}

	return (n);
}
