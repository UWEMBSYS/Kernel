#pragma once
#include <stdint.h>
#include <errors.h>
#include <threads.h>
#include <mutex.h>

///
/// The context switcher stores what the processor is currently doing and choose the next 
/// context that is ready to run.
/// The context chosen is done so by the scheduler
/// 
namespace Context
{

    ///
    /// Contains the information about each task
    /// - The instruction pointer at the time of a context switch
    /// - The stack pointer
    /// - The run state
    /// - Information about any blocking object
    /// 
    typedef struct {
        // These fields are set at thread creation time
        Id_t            Id;             //!< Unique task identifier
        State_t         State;          //!< The current task disposition
        uint32_t        EntryParam;     //!< Opaque variable passed to task Entry Point 
        Priority_t      Priority;       //!< Task Priority (currently unused)

        // These fields are updated at context switch time
        StackPointer_t          SP;     //!< sp to use at next scheduling of this task
    } Context_t;


    void Switch( Context_t& from, Context_t& to);
    

}
