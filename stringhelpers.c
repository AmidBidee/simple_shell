#include "main.h"

/**
 *_strcat - This adds the content of source to destination
 *@dest: this is the string that gets added to
 *@src: this is the string to be added
 *Return: returns a pointer to the final value
 */
char *_strcat(char *dest, char *src)
{
int length, srclength = 0;
char *finalptr = dest;
for (length = 0; dest[length] != '\0'; length++)
{
}
for (srclength = 0; src[srclength] != '\0'; srclength++)
{
dest[length] = src[srclength];
length++;
}
dest[length] = '\0';
return (finalptr);
}

/**
 * _strstr - this locates a substring
 * @needle: the substring to be found
 * @haystack: the string to find the occurence
 * Return: Returns a pointer to the beginning of the located substring
 */
char *_strstr(char *haystack, char *needle)
{
char *finalptr = '\0';
char *ptrcache = needle;
char *checker = haystack;
int check = 0, len = 0;
while (*needle)
{
len++;
needle++;
}
needle = ptrcache;
while (*haystack)
{
checker = haystack;
while (*needle)
{
if (*checker++ == *needle++)
{
check++;
}
else
{
check = 0;
break;
}
}
if (check != len)
{
needle = ptrcache;
haystack++;
}
else
{
finalptr = haystack;
break;
}
}
return (finalptr);
}

/**
 * _strcpy - this copies a string from src to destination
 * @src: this is the source string to be copied
 * @dest: this is where the string would be copied to
 * Return: This returns the pointer to the destination
 */
char *_strcpy(char *dest, char *src)
{
char *ptr = dest;

while (*src != '\0')
{
*dest = *src;
dest++;
src++;
}
*dest = '\0';
return (ptr);
}

/**
 *_strcmp - This compares two char arrays
 *@s2: First String for comparision
 *@s1: Second String for comparison
 *Return: returns 1 if s1 greater than s2, -1 if otherwise ekse 0
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
