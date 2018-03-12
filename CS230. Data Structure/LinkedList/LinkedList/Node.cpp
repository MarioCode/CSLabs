//
//  Node.cpp
//  LinkedList
//

#include "Node.h"

///////////////////////////////////////////
// Initialize the node default constructor

template<typename T>
Node<T>::Node()
{
  pNext = NULL;
  pPrev = NULL;
}

///////////////////////////////////////////
// Copy constructor

template<typename T>
Node<T>::Node(const Node& copy){
  pNext = copy.pNext;
  pPrev = copy.pPrev;
  item = copy.item;
  
  return *this;
}

///////////////////////////////////////////
// Constructor with parameter (user value)

template<typename T>
Node<T>::Node(const T value)
{
  pNext = NULL;
  pPrev = NULL;
  item = value;
}

///////////////////////////////////////////
// Assignment operator
template<typename T>
Node<T>& Node<T>::operator= (const Node& node)
{
  pNext = node.pNext;
  pPrev = node.pPrev;
  item = node.item;
  
  return *this;
}

///////////////////////////////////////////
// Destructor

template<typename T>
Node<T>::~Node(){
  pNext = NULL;
  pPrev = NULL;
}
