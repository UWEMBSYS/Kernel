#pragma once
#include <stdint.h>
#include <errors.h>

///
/// Mutex handle count is determined at compile time
/// Each handle is setup during initialize and is subsequently ready for use. 
/// There is no concept of open or close as the resources are statically allocated
/// To prevent deadlock all threads should unlock all resources before exit
///

namespace Mutex
{
 
// Forward declare the opaque handle
typedef Handle_t;

///
/// Setup initial state for the mutex class. 
/// Subsequent calls will be benign
///
/// \return SUCCESS Setup succeeded or did so earlier
///
Errors::Err_t   Initialize(void); 

///
/// Block until the resource has been released.
/// The mutex will be held be the caller upon successful return
///
/// \param handle - The mutex handle
/// \return SUCCESS     Lock is held by caller
///         PARAMETER   A bad handle was supplied
///
Errors::Err_t   Lock(Handle_t&  handle);

///
/// Block until the resource has been release or a period has passed.
/// The mutex will be held be the caller upon successful return
///
/// \param  handle      The mutex handle
/// \param  timeout     Millisecond count to wait for the resource
/// \return SUCCESS     Lock is held by caller
///         PARAMETER   A bad handle was supplied
///         TIMEOUT     The timer expired before the resource was released
///
Errors::Err_t   TimedLock(Handle_t&  handle, uint32_t timeout);

///
/// Release a lock held on a mutex. 
/// \return SUCCESS     The lock was released by this thread
///         PARAMETER   The handle was bad
///         FAILED      Lock was not heald by this thread
///
Errors::Err_t   Unlock(Handle_t& handle);

}

