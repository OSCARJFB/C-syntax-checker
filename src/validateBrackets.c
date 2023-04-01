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
	int line = 1, len = 0, err = 0;

	const char *msg1 = "No matching opening/closing {} on line: \0";
	const char *msg2 = "No matching opening/closing () on line: \0";
	const char *msg3 = "No matching opening/closing [] on line: \0";

	for (int i = 0; i < BUFFER_SIZE - 1 && buffer[i] != '\0'; ++i)
	{
		line += buffer[i] == '\n' ? 1 : 0;

		if (buffer[i] == '{' || buffer[i] == '}')
		{
			len = strlen(msg1);
			strncpy(err_msg, msg1, len);
			err = 1; 
		}
		else if (buffer[i] == '(' || buffer[i] == ')')
		{
			len = strlen(msg2);
			strncpy(err_msg, msg2, len);
			err = 1; 
		}
		else if (buffer[i] == '[' || buffer[i] == ']')
		{
			len = strlen(msg3);
			strncpy(err_msg, msg3, len);
			err = 1; 
		}
	}

	msg1 = msg2 = msg3 = NULL; 
	return err ? line : 0;	
}