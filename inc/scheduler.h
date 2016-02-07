#pragma once
#include <queue.h>

///
/// The scheduler queues the tasks according to their state
/// READY       The task is waiting to execute
/// BLOCKED     The task is waiting for a resource. When the resource is available it will be moved to the ready queue
/// RUNNING     The task is executing
/// 

