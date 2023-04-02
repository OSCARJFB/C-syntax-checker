/*
    Writen by: Oscar Bergström
    https://github.com/OSCARJFB
*/

#ifndef VALIDATEKEYWORDS_H
#define VALIDATEKEYWORDS_H

#include "main.h"

enum storageClasses
{
    kw_register = 869,   // Can't be used with functions.    
    kw_extern = 662,         
    kw_static = 648,         
    kw_auto = 441,           
};

enum properties
{
    kw_const = 551,        
    kw_signed = 634,         
    kw_unsigned = 861,             
};

enum dataTypes
{
    kw_void = 434,        
    kw_char = 414,         
    kw_int = 331,            
    kw_float = 534,  
    kw_long = 432,
    kw_double = 653,             
};

int validateKeyWords(char buffer[BUFFER_SIZE], char err_msg[MSG_SIZE]);
inline int getKeyWordValue(const char *keyWord);

#endif // VALIDATEKEYWORDS_H