/*
    Writen by: Oscar Bergström
    https://github.com/OSCARJFB
*/

#include "validateComments.h"
#include "main.h"

int validateComments(char buffer[BUFFER_SIZE], char err_msg[MSG_SIZE])
{
	int line = 0;
	const char msg1[MSG_SIZE] = "Unexpected /: \0";
	const char msg2[MSG_SIZE] = "Unexpected *: \0";

	for (int i = 0; buffer[i] != '\0' && i < BUFFER_SIZE - 1; ++i)
	{
		// One liner!
		if (buffer[i] == '/' && buffer[i + 1] == '/')
		{
			readOneLiner(buffer);
		}

		// Multiple lines!
		if (buffer[i] == '/' && buffer[i + 1] == '*')
		{
			readMultiLiner(buffer);
		}
	}

	return line;
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
