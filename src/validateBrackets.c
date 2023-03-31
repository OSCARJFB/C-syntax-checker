/*
    Writen by: Oscar Bergström
    https://github.com/OSCARJFB
*/

#include "validateBrackets.h"
#include "main.h"
#include <string.h>

int validateBrackets(char buffer[BUFFER_SIZE], char err_msg[MSG_SIZE])
{
	findClosingBracket(buffer);
	return bracketResult(buffer, err_msg);
}

void findClosingBracket(char buffer[BUFFER_SIZE])
{
	char bracket = ' ';

	for (int i = 0; i < BUFFER_SIZE - 1 && buffer[i] != '\0'; ++i)
	{
		if (buffer[i] == '}' || buffer[i] == ')' || buffer[i] == ']')
		{
			if (buffer[i] == '}')
			{
				bracket = '{';
			}
			else if (buffer[i] == ')')
			{
				bracket = '(';
			}
			else if (buffer[i] == ']')
			{
				bracket = '[';
			}

			if (findOpeningBracket(buffer, i, bracket))
			{
				buffer[i] = ' ';
			}
		}
	}
}

int findOpeningBracket(char buffer[BUFFER_SIZE], int index, char bracket)
{
	for (int i = index; i >= 0; --i)
	{
		if (buffer[i] == bracket)
		{
			buffer[i] = ' ';
			return 1;
		}
	}

	return 0;
}

int bracketResult(char buffer[BUFFER_SIZE], char err_msg[MSG_SIZE])
{
	int line = 1, len = 0;

	char msg1[MSG_SIZE] = "No matching opening/closing {} on line: \0";
	char msg2[MSG_SIZE] = "No matching opening/closing () on line: \0";
	char msg3[MSG_SIZE] = "No matching opening/closing [] on line: \0";

	for (int i = 0; i < BUFFER_SIZE - 1 && buffer[i] != '\0'; ++i)
	{
		line += buffer[i] == '\n' ? 1 : 0;

		if (buffer[i] == '{' || buffer[i] == '}')
		{
			len = strlen(msg1);
			strncpy(err_msg, msg1, len);
			return line;
		}
		else if (buffer[i] == '(' || buffer[i] == ')')
		{
			len = strlen(msg2);
			strncpy(err_msg, msg2, len);
			return line;
		}
		else if (buffer[i] == '[' || buffer[i] == ']')
		{
			len = strlen(msg3);
			strncpy(err_msg, msg3, len);
			return line;
		}
	}

	return 0;
}