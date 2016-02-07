#pragma once


namespace Errors
{
    
typedef enum {
    SUCCESS=0,      //!< No error occurred. This is set to zero to simplify logic.
    UNSUPPORTED,    //!< Used in skeleton/placeholder code 
    BUSY
} Err_t;

}