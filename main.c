#include <stdio.h>

#define BUFFER_SIZE 1000
#define MSG_SIZE 100

void getTextInput(char buffer[BUFFER_SIZE]);

int validateComments(char buffer[BUFFER_SIZE], char err_msg[MSG_SIZE]);
void readOneLiner(char buffer[BUFFER_SIZE]);
void readMultiLiner(char buffer[BUFFER_SIZE]);

int validateBrackets(char buffer[BUFFER_SIZE], char err_msg[MSG_SIZE]);
void findClosingBracket(char buffer[BUFFER_SIZE]);
int findOpeningBracket(char buffer[BUFFER_SIZE], int index, char bracket);
int bracketResult(char buffer[BUFFER_SIZE], char err_msg[MSG_SIZE]);

int validateQuates(char buffer[BUFFER_SIZE], char err_msg[MSG_SIZE]); 

int strlen_24(char msg[MSG_SIZE]);
void strncpy_24(char err_msg[MSG_SIZE], char msg[MSG_SIZE], int len);

int main(void)
{
	char buffer[BUFFER_SIZE], err_msg[MSG_SIZE] = "";
	int line = 0;

	getTextInput(buffer);

	line = validateComments(buffer, err_msg); 
	if(!line)
	{
		printf("%s%d", err_msg, line);
	}

	line = validateBrackets(buffer, err_msg);
	if (!line)
	{
		printf("%s%d", err_msg, line);
	}

	return 0;
}

void getTextInput(char buffer[BUFFER_SIZE])
{
	int c;

	for (int i = 0; (c = getchar()) != EOF && i < BUFFER_SIZE - 1; ++i)
	{
		buffer[i] = c;
		buffer[i + 1] = '\0';
	}
}

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
			len = strlen_24(msg1);
			if (len == -1)
			{
				puts("Error strlen_24 lenght of string couldn't be found.");
				return -1;
			}

			strncpy_24(err_msg, msg1, len);
			return line;
		}
		else if (buffer[i] == '(' || buffer[i] == ')')
		{
			len = strlen_24(msg2);
			if (len == -1)
			{
				puts("Error strlen_24 lenght of string couldn't be found.");
				return -1;
			}

			strncpy_24(err_msg, msg2, len);
			return line;
		}
		else if (buffer[i] == '[' || buffer[i] == ']')
		{
			len = strlen_24(msg3);
			if (len == -1)
			{
				puts("Error strlen_24 lenght of string couldn't be found.");
				return -1;
			}

			strncpy_24(err_msg, msg3, len);
			return line;
		}
	}

	return 0;
}

int strlen_24(char msg[MSG_SIZE])
{
	for (int i = 0;; ++i)
	{
		if (msg[i] == '\0')
		{
			return i;
		}
	}

	return -1;
}

void strncpy_24(char err_msg[MSG_SIZE], char msg[MSG_SIZE], int len)
{
	for (int i = 0; i < len; ++i)
	{
		err_msg[i] = msg[i];
		err_msg[i + 1] = '\0';
	}
}
