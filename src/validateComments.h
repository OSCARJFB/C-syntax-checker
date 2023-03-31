/*
    Writen by: Oscar Bergström
    https://github.com/OSCARJFB
*/

#ifndef VALIDATECOMMENTS_H
#define VALIDATECOMMENTS_H

#include "main.h"

int validateComments(char buffer[BUFFER_SIZE], char err_msg[MSG_SIZE]);
void readOneLiner(char buffer[BUFFER_SIZE]); 
void readMultiLiner(char buffer[BUFFER_SIZE]); 

#endif // VALIDATECOMMENTS_H