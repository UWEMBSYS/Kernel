#pragma once
#include <errors.h>

namespace CriticalSection
{  
    typedef unsigned long LockVal_t;
    typedef LockVal_t* Lock_t;
    
    
    ///
    /// Attempt the lock a critical section
    /// \param lock     A lock object for the region to be protected
    /// \return     SUCCESS     Lock was taken
    ///             BUSY        The lock is held already
    ///
    Errors::Err_t   Enter(Lock_t& lock);
    
    ///
    /// Release a previosly held critical section
    /// \param lock The lock object for the protected region
    /// \return     SUCCESS The lock was released
    ///
    Errors::Err_t   Leave(Lock_t& lock);
    
}
