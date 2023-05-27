#include "main.h"
/**
 * remove_comments - replace # with \0
 * @buf: input string
 *
 * Return: nothing
*/
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
