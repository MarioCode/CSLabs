//
//  main.cpp
//  DynamicArray
//

#include <iostream>
#include <time.h>
#include <vector>
#include "DynamicArray.h"

void printVector(std::vector<int> vector);

int main(int argc, const char * argv[]) {
  srand(time(NULL));
  
  int arraySize = 10;
  
  DynamicArray arr(arraySize);   // Create and fill first array (Class).
  //std::vector<int> arr;          // Create array as vector

  for (int i = 0; i < arraySize; i++)
    arr.push_back(rand() % 100);
  
  /////////////////////////////////////////////////////////////////////////////
  // DynamicArray (Comment this part, if using vector)
  
  DynamicArray arr2(arr);           // Create array. Copy using the constructor
  DynamicArray arr3 = arr2;         // Create array. Copy using operator =
  
  arr.print();
  arr2.print();
  arr3.print();
  
  arr2.clear();
  arr2.print();
  arr3.pop_back();
  
  /////////////////////////////////////////////////////////////////////////////
  // Vector. Print func
  
  //printVector(arr);
  
  system("pause");
  return 0;
}

void printVector(std::vector<int> vector)
{
  std::vector<int>::iterator it;
  
  std::cout << "Size vector: " << vector.size() << std::endl;
  std::cout << "Vector: [";
  
  if (vector.size() > 0)
  {
    for (it = vector.begin() ; it != vector.end() - 1; ++it)
      std::cout << *it << ", ";
  
    it = vector.end() - 1;
    std::cout << *it <<  "] \n\n";
  } else {
    std::cout << " Empty ] \n\n";
  }
}
