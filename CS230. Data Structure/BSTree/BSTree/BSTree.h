//
//  BSTree.h
//  BSTree
//

#ifndef BSTree_h
#define BSTree_h

#include <iostream>
#include "Node.cpp"
#include <queue>

///////////////////////////////////////////
//BSTree Class Declaration

template<typename T>
class BSTree {
public:
  // Constructors:

  BSTree();                     // default
  BSTree(const BSTree<T>& copy);  // copy
  inline void copy(const Node<T>* Node);

  // Destructor:
  ~BSTree();
  void destroyRecursive(Node<T>* Node);
  
  // Assignment operator
  BSTree& operator= (const BSTree& tree);
  
  // Data
  int sizeNodes;                 // Node's count
  Node<T>* pRoot;                // Tree's root

  // Tree operators
  void insert(int key, T itme);   // Inserting a new node into a tree
  void remove(int key);           // Removing the node
  void printKeys();               // Print all keys (Breadthwise method)
  void clear(Node<T>*);                   // clear all tree
  T getAt(int key);               // Get the value of the node

  // Additional tree walks
  void preOrder(Node<T>* pRoot);
  void inOrder(Node<T>* pRoot);
  void postOrder(Node<T>* pRoot);
};
#endif /* BSTree_h */
