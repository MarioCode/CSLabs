//
//  BSTree.cpp
//  BSTree
//

#include "BSTree.h"

///////////////////////////////////////////
// Initialize the BSTree default constructor
template<typename T>
BSTree<T>::BSTree()
{
  sizeNodes = 0;
  pRoot = NULL;
}

///////////////////////////////////////////
// Copy constructor
template<typename T>
BSTree<T>::BSTree(const BSTree<T>& tree)
{
  //sizeNodes = 0;
  //pRoot = NULL;
  copy(tree.pRoot);
}


///////////////////////////////////////////
// Assignment operator
template<typename T>
BSTree<T>& BSTree<T>::operator= (const BSTree& tree)
{
  if (this == &tree)
    return *this;
  
  copy(tree.pRoot);
  
  return *this;
}

template<class T>
inline void BSTree<T>::copy(const Node<T>* node)
{
  if (node != NULL)
    insert(node->m_key, node->data);
  
  if (node->pLeft != NULL)
    copy(node->pLeft);
  
  if (node->pRight != NULL)
    copy(node->pRight);
}


///////////////////////////////////////////
//            Base Methods               //
///////////////////////////////////////////


///////////////////////////////////////////
// Insert a new node to the tree
template<typename T>
void BSTree<T>::insert(int key, T item)
{
  Node<T> *pNew;
  Node<T> *pNewParent;
  
  //The BST is Empty...
  if(pRoot == NULL)
  {
    Node<T>* newNode = new Node<T>(key, item);
    pRoot = newNode;
    pNew = pRoot;
  }
  // Traversing the tree to find the insertion point
  else
  {
    pNew = pRoot;
    
    while(pNew != NULL)
    {
      // To check for duplicates
      if(pNew->m_key == key)
      {
        pNew->data = item;
        return;
      }
      
      if(key < pNew->m_key)
      {
        pNewParent = pNew;
        pNew = pNew->pLeft;
      } else {
        pNewParent = pNew;
        pNew = pNew->pRight;
      }
    }
    
    Node<T>* newNode = new Node<T>(key, item);
    
    // Checking for parent value to determine if
    // the Node is a left or right child
    
    if(key < pNewParent->m_key)
      pNewParent->pLeft = newNode;
    else
      pNewParent->pRight = newNode;
  }
  
  sizeNodes++;
  return ;
}


///////////////////////////////////////////
// Delete a node from a tree by key
template<typename T>
void BSTree<T>::remove(int key)
{
  Node<T>* temp = pRoot;
  Node<T>* parent = NULL;
  
  while (temp != NULL)
  {
    if (key > temp->m_key)
    {
      parent = temp;
      temp = temp->pRight;
    }
    else if (key < temp->m_key)
    {
      parent = temp;
      temp = temp->pLeft;
    }
    else
    {
      if (temp->pLeft == NULL && temp->pRight == NULL)
      {
        if (parent->pLeft == temp)
          parent->pLeft = NULL;
        else
          parent->pRight = NULL;
        
        sizeNodes--;
        delete temp;
        temp = NULL;
        break;
      }
      else if (temp->pLeft == NULL || temp->pRight == NULL)
      {
        if (temp->pLeft != NULL)
          parent->pLeft = temp->pLeft;
        else
          parent->pRight = temp->pRight;
        delete temp;
      }
      else
      {
        Node<T> *temp2 = temp->pRight;
        
        while (temp2->pLeft != NULL) {
          temp2 = temp2->pLeft;
        }
        temp->m_key = temp2->m_key;
        delete temp;
      }
      break;
    }
  }
}

///////////////////////////////////////////
// Delete a node value from a tree by key
template<typename T>
T BSTree<T>::getAt(int key)
{
  Node<T> *pNew = pRoot;
  
  while (pNew != nullptr)
  {
    if (key > pNew->m_key)
    {
      pNew = pNew->pRight;
    }
    else if (key < pNew->m_key)
    {
      pNew = pNew->pLeft;
    }
    else
    {
      return pNew->data;
    }
  }
  
  return -1;
}

///////////////////////////////////////////
// Print all node's keys using the Breadthwise method
template<typename T>
void BSTree<T>::printKeys()
{
  std::queue <Node<T>*> queue;
  Node<T> *pNew = pRoot;
  
  if (pNew == nullptr)
    return;
  
  queue.push(pNew);
  
  while(queue.empty() == false)
  {
    Node<T> *node = queue.front();
    std::cout << "Key = " << node->m_key << ", Value = " << node->data << std::endl;
    queue.pop();
    
    if (node->pLeft != NULL) queue.push(node->pLeft);
    if (node->pRight != NULL) queue.push(node->pRight);
  }
}

///////////////////////////////////////////
// Completely clean the tree
template<typename T>
void BSTree<T>::clear(Node<T>* root)
{
  if (root == NULL) return;
  
  /* first delete both subtrees */
  clear(root->pLeft);
  clear(root->pRight);
  
  /* then delete the node */
  delete root;
  
  sizeNodes--;
  if (sizeNodes == 0)
    pRoot = NULL;
}

///////////////////////////////////////////
// Additional traversal trees (output values)

template<typename T>
void BSTree<T>::preOrder(Node<T>* pRoot)
{
  if (pRoot == NULL)
    return;
  
  std::cout << "Key = " << pRoot->m_key << ", Value = " << pRoot->data << std::endl;
  preOrder(pRoot->pLeft);
  preOrder(pRoot->pRight);
}

template<typename T>
void BSTree<T>::inOrder(Node<T>* pRoot)
{
  if (pRoot == NULL) return;
  inOrder(pRoot->pLeft);
  std::cout << "Key = " << pRoot->m_key << ", Value = " << pRoot->data << std::endl;
  inOrder(pRoot->pRight);
}

template<typename T>
void BSTree<T>::postOrder(Node<T>* pRoot)
{
  if (pRoot == NULL) return;
  postOrder(pRoot->pLeft);
  postOrder(pRoot->pRight);
  std::cout << "Key = " << pRoot->m_key << ", Value = " << pRoot->data << std::endl;
}

///////////////////////////////////////////
// Destructor

template<typename T>
void BSTree<T>::destroyRecursive(Node<T> *node)
{
  if (node)
  {
    destroyRecursive(node->pLeft);
    destroyRecursive(node->pRight);
    
    delete node;
  }
}

template<typename T>
BSTree<T>::~BSTree()
{
  destroyRecursive(pRoot);
}
