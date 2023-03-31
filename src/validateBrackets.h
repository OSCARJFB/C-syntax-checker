/*
    Writen by: Oscar Bergström
    https://github.com/OSCARJFB
*/

#ifndef VALIDATEBRACKETS_H
#define VALIDATEBRACKETS_H

#include "main.h"

int validateBrackets(char buffer[BUFFER_SIZE], char err_msg[MSG_SIZE]); 
void findClosingBracket(char buffer[BUFFER_SIZE]); 
int findOpeningBracket(char buffer[BUFFER_SIZE], int index, char bracket);
int bracketResult(char buffer[BUFFER_SIZE], char err_msg[MSG_SIZE]); 

#endif // VALIDATEBRACKETS_H