/*
    Writen by: Oscar Bergström
    https://github.com/OSCARJFB
*/

#include "validateFunctions.h"
#include "c_KeyWords.h"
#include "main.h"

typedef struct func
{
    int line;
    const char *funcName;
    struct func *next;
} func;

typedef struct var
{
    int line, isGlobal; 
    const char *varName; 
    struct func *next;
} var;

int validateFunctions(char buffer[BUFFER_SIZE], char err_msg[MSG_SIZE])
{
    // Should create a special scenario for long long. 
    int sc = 0, dt = 0, isConst = 0, isSigned = 0, isUnsigned = 0, name = 0; 
    const int whitespace = 32; 
    int ascii = 0;

    for (int i = 0; buffer[i] != '\0'; ++i)
    {
        if (buffer[i] != whitespace)
        {
            ascii += (int)buffer[i];
            continue;
        }

        if (ascii > 0)
        {
            findFunctionKeyWord(ascii);
            ascii = 0;
        }

        // Done add variable to list. 
        if(buffer[i] == ';' || buffer[i] == ',')
        {
            
        }
    }

    return 0;
}

int findFunctionKeyWord(int ascii)
{
    switch (ascii)
    {
    case kw_register:
        break;
    case kw_extern:
        break;
    case kw_static:
        break;
    case kw_auto:
        break;
    case kw_const:
        break;
    case kw_unsigned:
        break;
    case kw_signed:
        break;
    case kw_void:
        break;
    case kw_char:
        break;
    case kw_short:
        break;
    case kw_int:
        break;
    case kw_float:
        break;
    case kw_long:
        break;
    case kw_double:
        break;
    default: 
        /* Is user naming */
        break; 
    }
}
