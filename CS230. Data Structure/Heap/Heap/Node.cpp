//
//  Node.cpp
//  Heap
//

#include "Node.h"

template <typename K, typename V>
Node<K,V>::Node()
{
  m_key = 0;
}

template <typename K, typename V>
Node<K, V>::Node(K key, V value)
{
  m_key = key;
  m_value = value;
}

template <typename K, typename V>
Node<K,V>::~Node()
{

}
