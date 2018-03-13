//
//  main.cpp
//  LinkedList
//

#include <iostream>
#include <time.h>
#include <stack>
#include <queue>
#include "Queue.cpp"
#include "Stack.cpp"

// Prototypes of functions
void test_stack(int randArray[]);
void test_stl_stack(int randArray[]);

void test_queue(int randArray[]);
void test_stl_queue(int randArray[]);

int main(int argc, const char * argv[]) {
  srand(time(NULL));
  
  int array[100] = { 0 };
  
  for (int i = 0; i < 100; i++)
    array[i] = rand() % 100;
  
  test_stack(array);
  test_stl_stack(array);
  
  test_queue(array);
  test_stl_queue(array);
  
  return 0;
}


///////////////////////////////////////////
// 2 test functions for: STACK
//
// Custom stack
void test_stack(int randArray[])
{
  // Create a custom stack object
  Stack<int> stack;
  
  // !!!
  // Random returns 0 or 1.
  // If return 1, then add random element to the stack
  // Otherwise (if the stack is not empty), remove the item from the stack.
  
  // Similar logic is used in other test functions
  // !!!
  
  for (int i = 0; i < 20; i++)
  {
    if (rand() % 2)
      stack.push(randArray[rand()%100]);
    else if (!stack.isEmpty())
      stack.pop();
  }
  
  // Information about Stack.
  
  std::cout << "*** Custom stack ****" << std::endl;
  
  if (!stack.isEmpty())
  {
    std::cout << "Size = " << stack.itemCount << std::endl;
    std::cout << "Top stack = " << stack.peek() << std::endl;
    stack.print();
  }
  else
    std::cout << "Stack is empty" << std::endl;
}

// STL Stack
void test_stl_stack(int randArray[]) {
  std::stack<int> stlStack;
  
  for (int i = 0; i < 100; i++)
    stlStack.push(randArray[i]);
  
  std::cout << "\n\n*** STL Stack ****" << std::endl;
  
  if (!stlStack.empty())
  {
    std::cout << "Size = " << stlStack.size() << std::endl;
    std::cout << "Top stack = " << stlStack.top() << std::endl;
  }
  else
    std::cout << "Stack is empty" << std::endl;
  
  // !!!
  // A standard STL Stack container does not have a function to traverse elements (iterators),
  // respectively, can not be printed without using a second container.
  // The queue also does not have iterators.
}

///////////////////////////////////////////
// 2 test functions for: QUEUE
//
// Custom queue
void test_queue(int randArray[])
{
  Queue<int> queue;
  
  // The same logic of adding / removing, as in the stack
  for (int i = 0; i < 20; i++)
  {
    if (rand() % 2)
      queue.enqueue(randArray[rand()%100]);
    else if (!queue.isEmpty())
      queue.dequeue();
  }
  
  // Information about Queue.

  std::cout << "\n\n*** Custom queue ****" << std::endl;
  
  if (!queue.isEmpty())
  {
    std::cout << "Size = " << queue.itemCount << std::endl;
    std::cout << "Front item = " << queue.getFront() << std::endl;
    std::cout << "Back item = " << queue.getBack() << std::endl;
    queue.print();
  }
  else
    std::cout << "Queue is empty" << std::endl;
}

// STL Queue
void test_stl_queue(int randArray[])
{
  std::queue<int> stlQueue;     
  
  for (int i = 0; i < 100; i++)
    stlQueue.push(randArray[i]);

  std::cout << "\n\n*** STL Queue ****" << std::endl;
  
  if (!stlQueue.empty())
  {
    std::cout << "Size = " << stlQueue.size() << std::endl;
    std::cout << "Front item = " << stlQueue.front() << std::endl;
    std::cout << "Back item = " << stlQueue.back() << std::endl;
  }
  else
    std::cout << "Queue is empty" << std::endl;

  std::cout << std::endl;
}




