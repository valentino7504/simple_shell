#include "main.h"
/**
 * _strcat - concatenates strings
 * @dest: the destination string
 * @src: the source string
 * Return: the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int i = _strlen(dest);
	int j;

	for (j = 0; j < _strlen(src); j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: the difference between the two
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}

	if (_strlen(s1) != _strlen(s2))
	{
		return (s1[i] - s2[i]);
	}
	return (0);
}
/**
 * _strlen - find the length of a string
 * @s: the string
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * _strdup - copies a string
 * @str: the string to copy
 * Return: NULL or a pointer to the string
 */
char *_strdup(char *str)
{
	int length;
	int i = 0;
	char *copy;

	if (str == NULL)
	{
		return (NULL);
	}
	length = _strlen(str);
	copy = malloc((sizeof(char) * length) + 1);
	if (copy == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= length; i++)
	{
		copy[i] = str[i];
	}
	return (copy);
}
/**
 * _strcpy - to copy a string
 * @dest: destination string
 * @src: source string
 * Return: the final string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; i < _strlen(src); i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
