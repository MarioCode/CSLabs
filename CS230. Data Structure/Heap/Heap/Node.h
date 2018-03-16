//
//  Node.h
//  Heap
//

#ifndef Node_h
#define Node_h

#include <iostream>

template <typename K, typename V>
class Node
{
public:
  Node();
  Node(K key, V value);
  ~Node();
  
  K m_key;
  V m_value;
};

#endif /* Node_h */
