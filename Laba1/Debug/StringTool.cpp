#include "StringTool.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int len(const char* str)
{
	int i = 0;
	if (str == 0)
		return 0;
	while (str[i])
		i++;
	return i;
}
int searchStr(char* str, const char* tempstr)
{
	if (str == 0)
		return 0;
	return (strstr(str, tempstr) == 0) ? 0 : 1;
}

int notEmptyStr(char* str,const char* tempstr)
{
	if (str == 0)
		return 0;
	return (str[0] == 0) ? 0 : 1;
}
char* caps(char* str)
{
	int size = len(str)+1;
	if (size == 0)
		return 0;
	char* str1 = (char*)malloc(sizeof(char*) * size);
	if (str1 == 0)
		return 0;
	memset(str1, 0, size);
	if (str1 == 0)
		return 0;
	int i = 0;
	while (str[i]!=0)
	{
		str1[i] = toupper(str[i]);
		i++;
	}
	return str1;
}

char* rev(char* str)
{
	int size = len(str);
	if (size == 0)
		return 0;
	char* str1 = (char*)malloc(sizeof(char*) * size);
	if (str1 == 0)
		return 0;
	for (int i = 0; i < (size); i++)
		str1[i] = str[size - i-1];
	str1[size] = 0;
	return str1;
}


char* etoT(char* str)
{
	int size = len(str)+1;
	if (size == 0)
		return 0;
	char* str1 = (char*)malloc(sizeof(char) * size);
	if (str1 == 0)
		return 0;
	for (int i = 0; i < size; i++)
	{
		str1[i] = (str[i] == 'e' ? 'T' : str[i]);
	}
	return str1;
}

int strCmp(const char* str1, const char* str2)
{
	int len1, len2;
	len1 = len(str1);
	len2 = len(str2);
	if (len1 == 0)
		return 0;
	if (len1 != len2)
		return 0;
	for (int i = 0; i < len1;i++)
	{
		if (str1[i] != str2[i])
			return 0;
	}
	return 1;
}

int lenVolve( const char* str)
{
	int ch=0;
	int j=0;
	int i = 0;
	while (str[i]!=0)
	{
		ch = toupper(str[i]);
		if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
			j++;
		i++;
	}
	return j;
}