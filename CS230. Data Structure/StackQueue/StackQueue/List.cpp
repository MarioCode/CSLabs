//
//  List.cpp
//  LinkedList
//

#include "List.h"

///////////////////////////////////////////
// Initialize the list default constructor
template<typename T>
LList<T>::LList()
{
  itemCount = 0;
  pHead = NULL;
  pTail = NULL;
}

///////////////////////////////////////////
// Copy constructor
template<typename T>
LList<T>::LList(const LList& copy)
{
  pHead = NULL;
  pTail = NULL;
  
  Node<T>* pTrav = copy.pHead;
  while(pTrav != NULL)
  {
    addToTail(pTrav->item);
    pTrav = pTrav->pNext;
  }
}

///////////////////////////////////////////
// Destructor
template<typename T>
LList<T>::~LList()
{
  clear();
}

///////////////////////////////////////////
// Assignment operator
template<typename T>
LList<T>& LList<T>::operator= (const LList& list)
{
  Node<T>* pTrav = list.pHead;
  
  while(pTrav != NULL)
  {
    addToTail(pTrav->item);
    pTrav = pTrav->pNext;
  }
  
  return *this;
}


///////////////////////////////////////////
//            Base Methods               //
///////////////////////////////////////////


///////////////////////////////////////////
// Adding nodes to the list LinkList (Head)
template<typename T>
void LList<T>::addToHead(T item)
{
  Node<T>* pNew = new Node<T>;   // Allocate memory for new node.
  pNew->item = item;             // Set the data item on the new node.
  
  // If list is empty (head == NULL)
  if(pHead == NULL)
  {
    pHead = pNew;
    pTail = pNew;
    itemCount++;
    
    return;
  }
  
  // 1. Head --- 2 --- 3 --- Tail
  // 2. pNew --- Head --- 2 --- 3 --- Tail
  
  pNew->pNext = pHead;
  pHead->pPrev = pNew;
  pHead = pNew;
  
  itemCount++;
}

///////////////////////////////////////////
// Adding nodes to the list LinkList (Tail)
template<typename T>
void LList<T>::addToTail(T item)
{
  Node<T>* pNew = new Node<T>;    // Allocate memory for new node.
  pNew->item = item;              // Set the data item on the new node.
  
  // If list is empty (head == NULL)
  if(pHead == NULL)
  {
    pHead = pNew;
    pTail = pNew;
    itemCount++;
    
    return;
  }
  
  // 1. Head --- 2 --- 3 --- Tail
  // 2. Head --- 2 --- 3 --- Tail --- pNew
  
  pNew->pPrev = pTail;
  pTail->pNext = pNew;
  pTail = pNew;
  
  itemCount++;
}

///////////////////////////////////////////
// Get list's node from head
template<typename T>
T LList<T>::peekAtHead()
{
  return pHead->item;
}

///////////////////////////////////////////
// Get list's node from tail
template<typename T>
T LList<T>::peekAtTail()
{
  return pTail->item;
}

///////////////////////////////////////////
// Remove a node at the head
template<typename T>
void LList<T>::removeAtHead()
{
  // If head == NULL, exit
  if(!pHead)
  {
    return;
  }
  
  // If contains only 1 element (head == tail)
  if(pHead == pTail)
  {
    delete pHead;
    pHead = NULL;
    pTail = NULL;
    
    // List is empty
  }
  else
  {
    pHead = pHead->pNext;
    delete pHead->pPrev;
    pHead->pPrev = NULL;
  }
  
  itemCount--;
}

///////////////////////////////////////////
// Remove a node at the tail
template<typename T>
void LList<T>::removeAtTail()
{
  // If head == NULL, exit
  if(!pHead)
  {
    return;
  }
  
  // If contains only 1 element (head == tail)
  if(pHead == pTail)
  {
    delete pHead;
    pHead = NULL;
    pTail = NULL;
    
    // List is empty
  }
  else
  {
    pTail = pTail->pPrev;
    delete pTail->pNext;
    pTail->pNext = NULL;
  }
  
  itemCount--;
}

///////////////////////////////////////////
// Clear all list
template<typename T>
void LList<T>::clear()
{
  // While list is not empty -> removing tail
  while(!isEmpty())
  {
    removeAtTail();
  }
}

///////////////////////////////////////////
// Get size of list
template<typename T>
int LList<T>::getItemCount()
{
  return itemCount;
}

///////////////////////////////////////////
// check for empty
template<typename T>
bool LList<T>::isEmpty()
{
  if(pHead == NULL)
  {
    return true;
  }
  return false;
}

///////////////////////////////////////////
// Print list
template<typename T>
void LList<T>::print()
{
  Node<T>* pNode = pHead;
  int count = 1;
  
  if (isEmpty())
  {
    std::cout << "\nIs empty." << std::endl;
    return;
  }
    
  // Start print from head
  while(pNode)
  {
    std::cout << pNode->item << std::endl;
    pNode = pNode->pNext;
  }
}

