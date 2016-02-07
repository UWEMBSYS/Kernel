#include <config.h>
#include <mutex.h>
#include <thread.h>
#include <criticalregion.h>


typedef struct {
    Thread::Id_t    LockId;         //!< The container for the thread ID that owns the lock. 
    uint32_t        Count;          //!< The number of locks this thread has requested. Unlock when this reaches zero.  
} Mutex_t;

typedef unsigned int                    Handle_t;                   //!< Used to identify the mutex
static Mutex_t                          Mutexes[MUTEX_MAX_COUNT];   //!< The collection of mutex objects
static CriticalRegion::Lock_t           Initialized = 0;            //!< Indicates that the mutex system is ready to use

Errors::Err_t   Initialize(void)
{
  
  return Errors::UNSUPPORTED;
}

Errors::Err_t   Lock(Handle_t&  handle)
{
  return Errors::UNSUPPORTED;
}

Errors::Err_t   TimedLock(Handle_t&  handle, uint32_t timeout);
{
  return Errors::UNSUPPORTED;
}

Errors::Err_t   Unlock(Handle_t& handle);
{
  return Errors::UNSUPPORTED;
}

