//
//  Heap.cpp
//  Heap
//

#include "Heap.h"

// Constructor with parameter (size heap)
template <typename K, typename V>
Heap<K,V>::Heap(int capacity)
{
  m_itemCount = 0;
  m_capacityHeap = capacity;
  m_pArr = new Node<K, V> [m_capacityHeap];
}

// Destructor (delete heap)
template <typename K, typename V>
Heap<K,V>::~Heap()
{
  delete[] m_pArr;
}

////////////////////////////////////////////////
//////////////// Base methods //////////////////

// 1. INSERT
// 1.1 Insert new node to heap
template <typename K, typename V>
void Heap<K, V>::insert(K key, V value)
{
  if (m_itemCount == m_capacityHeap)
  {
    std::cout << "Heap is full" << std::endl;
    return;
  }
  
  m_pArr[m_itemCount].m_key = key;
  m_pArr[m_itemCount].m_value = value;
  
  bubbleUp();
}

// 1.2 After inserting, push up the maximum element
template <typename K, typename V>
void Heap<K, V>::bubbleUp()
{
  int m_curIdx = m_itemCount++;
  int m_parentIdx = getParentIdx(m_curIdx);
  
  while (m_pArr[m_curIdx].m_key > m_pArr[m_parentIdx].m_key)
  {
    swap(m_curIdx, m_parentIdx);
    m_curIdx = m_parentIdx;
    m_parentIdx = getParentIdx(m_curIdx);
  }
}


// 2. REMOVE
// 2.1 Remove node
template <typename K, typename V>
V Heap<K, V>::remove()
{
  if (m_itemCount == 0)
  {
    std::cout << "Error remove: Heap is empty" << std::endl;
    return "Heap is empty\n";
  }
  
  if (m_itemCount == 1)
  {
    m_itemCount--;
    return m_pArr[0].m_value;
  }
  
  // Changing element to the last and gradually rebuilding the tree
  
  V m_maxItem = m_pArr[0].m_value;
  m_pArr[0] = m_pArr[m_itemCount - 1];
  m_pArr[m_itemCount - 1].m_key = 0;
  m_itemCount--;
  
  // Dropping a small element down, and a big raise

  if (m_itemCount > 0)
    bubbleDown();
  
  return m_maxItem;
}


// Sieve, restoration of a tree
template <typename K, typename V>
void Heap<K, V>::bubbleDown()
{
  int m_parent = 0;
  
  while (1) {
    int leftChildIndex = getLeftChild(m_parent);
    int rightChildIndex = getRightChild(m_parent);
    int minIndex = m_parent;
    
    if (leftChildIndex < m_itemCount && m_pArr[leftChildIndex].m_key > m_pArr[minIndex].m_key)
      minIndex = leftChildIndex;
    
    if (rightChildIndex < m_itemCount && m_pArr[rightChildIndex].m_key > m_pArr[minIndex].m_key)
      minIndex = rightChildIndex;
    
    if (minIndex != m_parent)
    {
      swap(minIndex, m_parent);
      m_parent = minIndex;
    }
    else
      break;
  }
}


// 3. GET NODES
// 3.1 Get node of parent
template <typename K, typename V>
int Heap<K, V>::getParentIdx(int Idx) {
  return (Idx - 1) / 2;
}

// 3.2 Get left child node
template <typename K, typename V>
int Heap<K, V>:: getLeftChild(int Idx) {
  return Idx * 2 + 1;
}

// 3.3 Get right child node
template <typename K, typename V>
int Heap<K, V>::getRightChild(int Idx) {
  return getLeftChild(Idx) + 1;
}


// Swap two elements
template <typename K, typename V>
void Heap<K, V>::swap(int A, int B)
{
  Node<K, V> tmp = m_pArr[A];
  m_pArr[A] = m_pArr[B];
  m_pArr[B] = tmp;
}


// Get max element ( O(1) )
template <typename K, typename V>
V Heap<K, V>::getMaxValue() {
  if (m_itemCount != 0) {
    return m_pArr[0].m_value;
  }
  
  return "Heap is empty\n";
}

// Get heap size
template <typename K, typename V>
int Heap<K, V>::getHeapSize() {
  return m_itemCount;
}
