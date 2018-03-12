//
//  List.hpp
//  LinkedList
//

#ifndef List_h
#define List_h

#include "Node.cpp"
#include <iostream>

///////////////////////////////////////////
//LList Class Declaration

template<typename T>
class LList{
public:
  
  // Constructors:
  LList();                    // default
  LList(const LList& copy);   // copy
  
  // Destructor
  ~LList();
  
  // Data
  Node<T>* pHead;         // Pointer to the beginning(head) of the list
  Node<T>* pTail;         // Pointer to the end(tail) of the list
  int itemCount;          // Number of all elements
  
  // Assignment operator
  LList& operator= (const LList& list);

  // Adding nodes to the list LinkList (Head, Tail)
  void addToHead(T item);
  void addToTail(T item);
  
  // Get list's node from head or tail
  T peekAtHead();
  T peekAtTail();
  
  // Remove nodes from head or tail
  void removeAtHead();
  void removeAtTail();
  
  // Clear all list
  void clear();
  
  // Get size of list and check for empty
  int getItemCount();
  bool isEmpty();
  
  // Print linked list
  void print();
};

#endif /* List_h */
