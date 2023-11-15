#include "shell.h"

/**
 *_eputs - Prints an input string
 * @str: The string to be printed
 * Return: Nothing
 */

void _eputs(char *str)
{
	int n = 0;

	if (!str)
		return;
	while (str[n] != '\0')
	{
		_eputchar(str[n]);
		n++;
	}
}





/**
 * _eputchar - Writes the character c to stderr
 * @c: The character to print
 * Return: On success 1, -1 if not
 */

int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}





/**
 * _putfdt - Writes the character c to given fdt
 * @c: The character to print
 * @fdt: The filedescriptor to write to
 * Return: On success 1, -1 if not.
 */

int _putfdt(char c, int fdt)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fdt, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}





/**
 *_putsfdt - Prints an input string
 * @str: the string to be printed
 * @fdt: The filedescriptor to write to
 * Return: The number of chars put
 */

int _putsfdt(char *str, int fdt)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfdt(*str++, fdt);
	}
	return (i);
}
