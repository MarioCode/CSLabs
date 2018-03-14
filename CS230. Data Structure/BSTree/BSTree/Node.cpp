//
//  Node.cpp
//  BSTree
//

#include "Node.h"

///////////////////////////////////////////
// Initialize the node default constructor

template<typename T>
Node<T>::Node()
{
  pLeft = NULL;
  pRight = NULL;
}

///////////////////////////////////////////
// Constructor with parameters (user value)

template<typename T>
Node<T>::Node(const int key, const T item)
{
  pLeft = NULL;
  pRight = NULL;
  m_key = key;
  data = item;
}

///////////////////////////////////////////
// Copy constructor

template<typename T>
Node<T>::Node(const Node& copy)
{
  pLeft = copy.pLeft;
  pRight = copy.pRight;
  m_key = copy.m_key;
  data = copy.data;
  
  return *this;
}

///////////////////////////////////////////
// Assignment operator

template<typename T>
Node<T>& Node<T>::operator= (const Node& node)
{
  pLeft = node.pLeft;
  pRight = node.pRight;
  m_key = node.m_key;
  data = node.data;
  
  return *this;
}

///////////////////////////////////////////
// Destructor

template<typename T>
Node<T>::~Node()
{
  pLeft = NULL;
  delete pLeft;
  
  pRight = NULL;
  delete pRight;
}
