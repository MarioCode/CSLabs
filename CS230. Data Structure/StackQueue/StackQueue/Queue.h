//
//  Queue.h
//  3.StackQueue
//
#ifndef Queue_h
#define Queue_h

#include "List.h"

template<typename T>
class Queue : public LList<T>
{
public:
  
  // Add new item to a Queue
  void enqueue(T item);
  
  // Remove item from the Queue
  T dequeue();
  
  // Provides access to the first element
  T getFront();
  
  // Provides access to the end element
  T getBack();
};

#endif /* Queue_h */

