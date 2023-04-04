/*
    Writen by: Oscar Bergström
    https://github.com/OSCARJFB
*/

#ifndef C_KEYWORDS_H
#define C_KEYWORDS_H

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
    kw_short = 560,            
    kw_float = 534,  
    kw_long = 432,
    kw_double = 653,             
};

/* More to be added. */

#endif // C_KEYWORDS_H