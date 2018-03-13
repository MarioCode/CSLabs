//
//  Stack.h
//  3.StackQueue
//
#ifndef Stack_h
#define Stack_h

#include "List.cpp"

template<typename T>
class Stack : public LList<T>
{
public:
  
  // Add new item to a stack
  void push(T item);
  
  // Remove item from the stack
  T pop();
  
  // Top stack element
  T peek();

};

#endif /* Stack_h */

