/*
    Writen by: Oscar Bergström
    https://github.com/OSCARJFB
*/

#include "validateKeyWords.h"
#include "main.h"

int validateKeyWords(char buffer[BUFFER_SIZE], char err_msg[MSG_SIZE])
{
    // Native Data types
    const char *k_void = "void", *k_char = "char", *k_short = "short", *k_int = "int", *k_float = "float", *k_long = "long", *k_double = "double";

    // Properties. 
    const char *k_register = "register", *k_extern = "extern", *k_static = "static", *k_auto = "auto", *k_const = "const", *k_unsigned = "unsigned", *k_signed = "unsigned";;

    // Control flow statements
    const char *k_if = "if", *k_else = "else", *k_switch = "switch", *k_case = "case", *k_default = "default", k_break = "break"; 

    // Loops 
    const char *k_do = "do", *k_while = "while", *k_for = "for", *k_continue = "continue";

    // return 
    const char *k_return = "return"; 

    // sizeof
    const char *k_sizeof = "sizeof";
    
    // Labels
    const char *k_goto = "goto";

    // typedef
    const char k_tDef = "typedef";

    // Struct and Union
    const char *k_struct = "struct", *k_union = "union"; 

    return 0;
}