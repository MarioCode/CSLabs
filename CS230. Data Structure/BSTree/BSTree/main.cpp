//
//  main.cpp
//  BSTree
//

#include <iostream>
#include "BSTree.cpp"
#include <time.h>

int main(int argc, const char * argv[]) {
  srand(time(NULL));
  
  int countNodes = 10;
  BSTree<int> bst;
  
  // The test for adding and displaying various traversals
  // Generate nodes or write with hands
  
  //  for (int i = 0; i < countNodes; i++)
  //  {
  //    int randomKey = rand() % 20;
  //    int randomValue = rand() % 100;
  //
  //    bst.insert(randomKey, randomValue);
  //  }
  
  bst.insert(5, 50);
  bst.insert(3, 30);
  bst.insert(2, 20);
  bst.insert(4, 40);
  bst.insert(7, 70);
  bst.insert(6, 60);
  bst.insert(8, 80);
  bst.insert(4, 100);
  bst.insert(7, 77);

  std::cout << " -- START Testing different traversals -- \n\n";
  std::cout << " Breadth-Keys Traversal \n";
  std::cout << " -------------------" << std::endl;
  bst.printKeys();

  std::cout << "\n In-Order Traversal \n";
  std::cout << " -------------------" << std::endl;
  bst.inOrder(bst.pRoot);

  std::cout << "\n Pre-Order Traversal \n";
  std::cout << " -------------------" << std::endl;
  bst.preOrder(bst.pRoot);

  std::cout << "\n Post-Order Traversal \n";
  std::cout << " ---------------------"  << std::endl;
  bst.postOrder(bst.pRoot);

  std::cout << "\n -- END Testing different traversals -- \n\n";

  
  // Test getAt method
  int randKey = rand() % 15;
  int treeGetAt = bst.getAt(randKey);
  std::cout << "\nTest Get method: getAt(key)\n";
  std::cout << " -----------------------------" << std::endl;
  if (treeGetAt == -1)
    std::cout << "Value for key " << randKey << " not found \n";
  else
    std::cout << "Value for key " << randKey << ": " << treeGetAt << std::endl;
  
  // The test operator and copy constructor
  BSTree<int> bst2 (bst);
  BSTree<int> bst3 = bst2;
  
  std::cout << "\nTest copy operator through the copy constructor (print third tree)\n";
  std::cout << " ---------------------------------------------------------------------" << std::endl;
  bst3.inOrder(bst3.pRoot);

  std::cout << "\nTest remove nodes:" << std::endl;
  std::cout << " -------------------" << std::endl;
  bst.remove(6);
  bst.remove(2);
  bst.remove(8);
  bst.inOrder(bst.pRoot);
  
  // Clear test
  std::cout << "\nClear test (after try print this tree = none result)\n";
  std::cout << " --------------------------------------------------------" << std::endl;
  bst.clear(bst.pRoot);
  bst.postOrder(bst.pRoot);
  std::cout << "Node's count = " << bst.sizeNodes << std::endl;

  return 0;
}
