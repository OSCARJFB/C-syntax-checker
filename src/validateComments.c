/*
	Writen by: Oscar Bergström
	https://github.com/OSCARJFB
*/

#include "validateComments.h"
#include "main.h"

void removeComments(char buffer[BUFFER_SIZE])
{
	for (int i = 0; buffer[i] != '\0' && i < BUFFER_SIZE - 1; ++i)
	{
		if (buffer[i] == '/' && buffer[i + 1] == '/')
		{
			readOneLiner(buffer);
		}

		if (buffer[i] == '/' && buffer[i + 1] == '*')
		{
			readMultiLiner(buffer);
		}
	}
}

void readOneLiner(char buffer[BUFFER_SIZE])
{
	for (int i = 0; buffer[i] != '\0' && i < BUFFER_SIZE - 1; ++i)
	{
		if (buffer[i] == '\n')
		{
			return;
		}

		buffer[i] = ' ';
	}
}

void readMultiLiner(char buffer[BUFFER_SIZE])
{
	for (int i = 0; buffer[i] != '\0' && i < BUFFER_SIZE - 1; ++i)
	{
		if (buffer[i] == '*' && buffer[i + 1] == '/')
		{
			buffer[i] = buffer[i + 1] = ' ';
			break;
		}

		buffer[i] = ' ';
	}
}