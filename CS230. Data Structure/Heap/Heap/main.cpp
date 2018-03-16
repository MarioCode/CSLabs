//
//  main.cpp
//  Heap
//

#include <iostream>
#include <string>
#include "Heap.cpp"

int main() {
  
  //Create a heap
  Heap<int, std::string> myHeap(20);
  myHeap.insert(16, "16");
  myHeap.insert(14, "14");
  myHeap.insert(10, "10");
  myHeap.insert(8, "8");
  myHeap.insert(7, "7");
  myHeap.insert(9, "9");
  myHeap.insert(3, "3");
  myHeap.insert(2, "2");
  myHeap.insert(4, "4");
  myHeap.insert(1, "1");
  myHeap.insert(18, "18");
  myHeap.insert(11, "11");
  myHeap.insert(15, "15");
  
  std::cout << "Max Heap: \n";
  for (int i = 0; i < myHeap.getHeapSize(); i++)
    std::cout << myHeap.m_pArr[i].m_key << " ";
  
  myHeap.remove();
  myHeap.remove();
  myHeap.remove();

  std::cout << "\n\nAfter deleting..\n";
  
  for (int i = 0; i < myHeap.getHeapSize(); i++)
    std::cout << myHeap.m_pArr[i].m_key << " ";
  
  std::cout << "\n\nMax element (VALUE, not key) in heap: " << myHeap.getMaxValue();
  
  std::cout << "\n\nClear heap (delete all nodes):\n";
  myHeap.remove();
  myHeap.remove();
  myHeap.remove();
  myHeap.remove();
  myHeap.remove();
  myHeap.remove();
  myHeap.remove();
  myHeap.remove();
  myHeap.remove();
  myHeap.remove();
  myHeap.remove();
  myHeap.remove();

  system("pause");
  return 0;
}
