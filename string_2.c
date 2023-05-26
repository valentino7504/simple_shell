#include "main.h"
/**
 * get_stop - gets the stop index
 * @s1: the og string
 * @s2: the string to be checked
 * Return: the nstop index
 */
int get_stop(char *s1, char *s2)
{
	int i, j;
	int flag = 0;

	for (i = 0; i < _strlen(s1); i++)
	{
		for (j = 0; j < _strlen(s2); j++)
		{
			if (s1[i] == s2[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
		{
			break;
		}
		flag = 0;
	}
	return (i);
}

/**
 * _strspn - Returns the number of bytes in s consisting of bytes from accept
 * @s: the string
 * @accept: the string to be used
 * Return: the number of bytes
 */
unsigned int _strspn(char *s, char *accept)
{
	int stop_index = get_stop(s, accept);
	int i, j;
	unsigned int count = 0;

	for (i = 0; i < _strlen(accept); i++)
	{
		for (j = 0; j <= stop_index; j++)
		{
			if (accept[i] == s[j])
			{
				count++;
			}
		}
	}
	return (count);
}
