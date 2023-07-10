#include "main.h"

/**
 * strip_whitespace - remove the white spaces surrounding input
 * @input: input
 *
 * Return: striped string
*/
char *strip_whitespace(char *input)
{
	size_t i, j, len;
	char *result;

	if (input == NULL)
		return (NULL); /* Handle NULL input */

	len = strlen(input);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL); /* Failed to allocate memory */

	i = 0, j = len - 1;

	/* Skip leading white spaces */
	while (input[i] == ' ')
		i++;

	/* Skip trailing white spaces */
	while (j > i && input[j] == ' ')
		j--;

	/* Copy non-whitespace characters to result */
	strncpy(result, &input[i], j - i + 1);
	result[j - i + 1] = '\0'; /* Null-terminate the result */

	return (result);
}
