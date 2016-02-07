#pragma once

///
/// A generic queue API
///

namespace Queue
{
  typedef Handle_t;
  typedef void* QueueEntry_t;
  
  ///
  /// Instantiate a queue of pointers 
  /// 
  /// \param depth  The number of entries in the queue
  /// \param buffer Sufficient memory to store the queue (width * depth bytes)
  /// \return   A handle to identify the queue
  ///
  Handle_t& Create( unsigned int depth, void* buffer);
   
  ///
  /// Put an entry at the back of the queue
  /// \param ptr        The object to push
  /// \return   SUCCESS The entry was added
  ///           FULL    The queue is full
  ///
  Error::Err_t  Push(QueueEntry_t& ptr);

  ///
  /// Remove an entry from the front of the queue
  ///
  /// \param ptr        The container for the object
  /// \return   SUCCESS The entry was retrieved
  ///           FULL    The queue was empty
  ///
   Error::Err_t  Pop(QueueEntry_t& ptr);
}
