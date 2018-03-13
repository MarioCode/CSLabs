//
//  Stack.cpp
//  3.StackQueue
//

#include "Stack.h"

// Queue - (LIFO, Last In — First Out)
// Push - 1
// Push - 2
// Push - 3
// Push - 4
// Pop(Head - First) - 4


///////////////////////////////////////////
// Add new items to a stack
// LI - Last In
template<typename T>
void Stack<T>::push(T item)
{
  // Add a new item to the top of the stack
  LList<T>::addToHead(item);
}


///////////////////////////////////////////
// Add new items to a stack
// First Out
template <typename T>
T Stack<T>::pop()
{
  // Take the first (head) element from the Stack (list)
  T item = LList<T>::peekAtHead();
  // And remove it from the list
  LList<T>::removeAtHead();
  
  return item;
}

// Top stack element
template <typename T>
T Stack<T>::peek()
{
  // Return the first (head) element from the Stack (list)

  return LList<T>::peekAtHead();
}

