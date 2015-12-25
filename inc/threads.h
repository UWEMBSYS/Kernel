#pragma once
#include <errors.h>

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

typedef uint8_t Priority_t;     //!< Container for the priority level

extern const uint32_t       DEFAULT_STACK_SIZE; //!< The stack size for a task
extern const Priority_t     PRIORITY_HIGH;      //!< The highest task priority              
extern const Priority_t     PRIORITY_LOW;       //!< The lowest task priority

typedef uint32_t    StackPointer_t;             //!< Container for the stack pointer 
typedef uint16_t    Priority_t;                 //!< The task priority


///
/// Contains the information about each task
/// - The instruction pointer at the time of a context switch
/// - The stack pointer
/// - The run state
/// - Information about any blocking object
/// 
typedef struct {
    // These fields are set at creation time
    Id_t            Id;             //!< Unique task identifier
    State_t         State;          //!< The current task disposition
    uint32_t        EntryParam;     //!< Opaque variable passed to task Entry Point 
    Priority_t      Priority;       //!< Task Priority (currently unused)

    // These fields are updated at context switch time
    StackPointer_t          SP;     //!< sp to use at next scheduling of this task
} Context_t;


typedef (*Errors::Err_t)(uint32_t) EntryPoint_t;    //!< Protoype for a thread entry function, Err_t fn(uint32_t)
typedef uint32_t    Id_t;                           //!< Container for a thread identifier


///
/// Setup a thread context 
/// \param  handle      An opaque identifier for this context
/// \param  entry       The method to call when the task starts
/// \param  priority    A priority between PRI_MIN and PRI_MAX
Err_t   Create(Handle_t& handle, EntryPoint_t entry, Priority_t priority, uint32_t stackSize = DEFAULT_STACK_SIZE);

}
