//
//  Heap.h
//  Heap
//

#ifndef Heap_h
#define Heap_h

#include <iostream>
#include "Node.cpp"

template <typename K, typename V>
class Heap
{
public:
  // Constructor / Desctructor
  Heap(int capacity);
  ~Heap();
  
  // Max - Heap behavior
  // For inserting
  void insert(K key, V value);
  void bubbleUp();

  // Remove element
  V remove();
  void bubbleDown();
  
  // Helper (swap and get max value)
  void swap(int A, int B);
  V getMaxValue();
  int getHeapSize();
  
  // Data members
  Node<K, V> *m_pArr;
  int m_itemCount;
  int m_capacityHeap;
  
private:
  int getParentIdx(int Idx);
  int getLeftChild(int Idx);
  int getRightChild(int Idx);
};

#endif /* Heap_h */
