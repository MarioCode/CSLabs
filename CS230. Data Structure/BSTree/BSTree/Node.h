//
//  Node.h
//  BSTree
//

#ifndef Node_h
#define Node_h

#include <stdio.h>

///////////////////////////////////////////
//Node Class Declaration

template<typename T>
class Node {
public:
  // Constructors:
  Node();                             // default
  Node(const Node& copy);             // copy
  Node(const int key, const T item);  // with parameters
 
   // Destructor:
  ~Node();
  
  // Assignment operator
  Node& operator= (const Node& node);
  
  // Data members
  T data;          // node's value
  int m_key;       // node's key
  Node<T>* pLeft;  // pointer to the left node (left side)
  Node<T>* pRight; // pointer to the right node (right side)
  
  // Print node
  void print();
};

#endif /* Node_h */
