//
//  Node.hpp
//  LinkedList
//

#ifndef Node_h
#define Node_h

#include <iostream>

///////////////////////////////////////////
//Node Class Declaration

template<typename T>
class Node {
public:
  // Constructors:
  Node();                     // default
  Node(const Node& copy);     // copy
  Node(const T value);        // with paramaters
  
  // Destructor:
  ~Node();
  
  // Data
  Node<T>* pNext;   // Pointer to the Next node
  Node<T>* pPrev;   // Pointer to the Prev node
  T item;           // Node data
  
  // Assignment operator
  Node& operator= (const Node& node);
  
  // Print node
  void print();
};

#endif /* Node_h */

