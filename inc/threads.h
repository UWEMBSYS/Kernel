#pragma once
#include <errors.h>


///
/// A thread contains an execution entity. The word task is interchangeable with thread here. 
/// a task is what a thread does in this instance. 
///
namespace Thread
{
    
//!< Permissible thread states
typedef enum {
   UNINITIALIZED=0,     //!< The task has not been setup
   INITIALIZED,         //!< The task parameters have been setup but it has not been placed onto the run queue yet
   
   RUNNING,             //!< task is in the foreground.
   BLOCKED,             //!< task is waiting for a resource. Will transition to ready when the resource is available
   READY,               //!< task is ready to execute. task is on the run queue and will transition to running when scheduled
   
   EXITTED              //!< task execution ended, the exit code is available
} State_t;

extern const uint32_t       DEFAULT_STACK_SIZE; //!< The stack size for a task
extern const Priority_t     PRIORITY_HIGH;      //!< The highest task priority              
extern const Priority_t     PRIORITY_LOW;       //!< The lowest task priority

typedef uint32_t    StackPointer_t;             //!< Container for the stack pointer 
typedef uint16_t    Priority_t;                 //!< The task priority
typedef uint16_t    Id_t;                       //!< Unique Thread identifier
typedef (*Errors::Err_t)(uint32_t) EntryPoint_t;    //!< Protoype for a thread entry function, Err_t fn(uint32_t)
typedef uint32_t    Id_t;                           //!< Container for a thread identifier


///
/// Setup a thread context 
/// \param  handle      An opaque identifier for this context
/// \param  entry       The method to call when the task starts
/// \param  priority    A priority between PRI_MIN and PRI_MAX
/// \return SUCCESS     Thread was created
///
Err_t   Create(Handle_t& handle, EntryPoint_t entry, Priority_t priority, uint32_t stackSize = DEFAULT_STACK_SIZE);

}
