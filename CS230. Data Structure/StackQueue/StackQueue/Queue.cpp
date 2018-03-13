//
//  Queue.cpp
//  3.StackQueue
//

#include "Queue.h"

// Queue - (FIFO, First In — First Out)
// Enqueue - 1
// Enqueue - 2
// Enqueue - 3
// Enqueue - 4
// Dequeue(Head - First) - 1


///////////////////////////////////////////
// Add new last item to a Queue.
// FI - First In
template<typename T>
void Queue<T>::enqueue(T item)
{
  // Add a new item to the end of the queue
  LList<T>::addToTail(item);
}


///////////////////////////////////////////
// Remove first item from a Queue
// FI - First Out
template <typename T>
T Queue<T>::dequeue()
{
  // Take the first (head) element from the Queue (list)
  T item = LList<T>::peekAtHead();
  // And remove it from the list
  LList<T>::removeAtHead();
  
  return item;
}

// Provides access to the first element
template <typename T>
T Queue<T>::getFront()
{
  return LList<T>::peekAtHead();
}

// Provides access to the end element
template <typename T>
T Queue<T>::getBack()
{
  return LList<T>::peekAtTail();
}
