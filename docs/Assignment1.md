Critical Region Protection
==========================

Any object that is shared needs to have its access protected to prevent manipluation be multiple sources concurrently. This region of access is referred to as a critical region. In general it is protected my a mutually exclusive lock and there may only be one holder of a lock to the critical region. This lock is often called a mutex -  a mutex is an algorithm used to protect the critical region. 

Any access that must run to completion once started is called an atomic access, that is it must occur without being disturbed.

The Assignment
==============
Create a Mutex class. The class will be used in a multi threaded system, therefore all methods must be thread safe.
The API is described in the class header.

Requirements:
=============
1. All APIs must be thread safe
	Any thread can call any API at anytime
2. The API must prevent concurrent access to a named region until the caller relinquishes access to that region.
3. A thread that already owns a mutex will be allowed to continue execution if it requests a further lock to the same region. (POSIX calls this concept a 'recursive' mutex)
	The lock will not be released until the unlock count matches the lock count for the thread holding the lock.
4. A thread that does not hold the lock cannot unlock the mutex.



Test
====
Prove that the requirements are all met. This is going to be a recurring theme.
	
	
