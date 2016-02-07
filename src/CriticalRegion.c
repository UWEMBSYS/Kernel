#pragma once
#include <stdint.h>
#include <config.h>
#include <criticalregion.h>

namespace CriticalSection
{
  
LockVal_t const LOCKED      = 1;    //!< Memory location value when critical region is held
LockVal_t const UNLOCKED    = 0;    //!< Memory Location value when region if available

 
Errors::Err_t   Enter(Lock_t& lock)
{
  Errors::Err_t err = Errors::SUCCESS;
   LockVal_t lockVal =  __LDREXW(lock);
   if (UNLOCKED == lockVal) {
     if (__STREXW(LOCKED, lock)) {
       err = Errors::BUSY;
     }
   }
   return err;
}

Errors::Err_t   Leave(Lock_t& lock)
{
    *lock = UNLOCKED;
    
    return Errors::SUCCESS;
}

}
