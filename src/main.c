/*
    Writen by: Oscar Bergström
    https://github.com/OSCARJFB
*/

#include "main.h"
#include "validateComments.h"
#include "validateBrackets.h"
#include "validateFunctions.h"
#include <stdio.h>

int main(void)
{
	char buffer[BUFFER_SIZE], err_msg[MSG_SIZE] = "";
	int line = 0;

	getTextInput(buffer);
	removeComments(buffer);

	line = validateBrackets(buffer, err_msg);
	if (line)
	{
		printf("Bracket Err: %s%d\n", err_msg, line);
	}

	line = validateFunctions(buffer, err_msg);
	{
		printf("Bracket Err: %s%d\n", err_msg, line);
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

