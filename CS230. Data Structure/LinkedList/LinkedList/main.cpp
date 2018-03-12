//
//  main.cpp
//  LinkedList
//

#include <iostream>
#include "List.cpp"
#include <time.h>
#include <list>

void test_llist(int randArray[]);
void test_stl_list(int randArray[]);

int main(int argc, const char * argv[]) {
  srand(time(NULL));
  
  int array[100] = { 0 };
  
  for (int i = 0; i < 100; i++)
    array[i] = rand() % 100;
  
  // Test custom Linked List
  test_llist(array);
  
  // Test STL List
  test_stl_list(array);

  system("pause");
  return 0;
}


void test_llist(int randArray[]) {
  // First Linked List (default constructor)
  LList<int> firstList;
  
  
  // Testing list methods //
  
  
  // Adding the first part of the array to the tail of LList
  for (int i = 0; i < 50; i++)
    firstList.addToTail(randArray[i]);
  
  // Adding the second part of the array to the head of LList
  for (int i = 50; i < 100; i++)
    firstList.addToHead(randArray[i]);
  
  // Remove multiple items from different sides
  firstList.removeAtHead();
  firstList.removeAtTail();
  firstList.removeAtHead();
  firstList.removeAtTail();
  firstList.removeAtTail();
  
  // Output of general information about the list (size, empty, head and tail elements)
  std::cout << "List size: " << firstList.getItemCount() << std::endl;
  std::cout << "List is empty: ";
  firstList.isEmpty() ? (std::cout << "Yes" << std::endl) : (std::cout << "No" << std::endl);
  std::cout << "Head's value: " << firstList.peekAtHead() << std::endl;
  std::cout << "Tail's value: " << firstList.peekAtTail() << std::endl;
  
  // Printing a list, cleaning and re-checking the print (must be empty)
  firstList.print();
  firstList.clear();
  firstList.print();
  
  // Adding multiple items at the tail
  firstList.addToTail(rand() % 100);
  firstList.addToTail(rand() % 100);
  firstList.addToTail(rand() % 100);
  firstList.addToTail(rand() % 100);
  firstList.addToTail(rand() % 100);
  firstList.addToTail(rand() % 100);
  firstList.addToTail(rand() % 100);
  
  // Create a second list and check the copy constructor
  std::cout << "\nSecond List: (Copy constructor)";
  LList<int> secondList(firstList);
  secondList.print();
  
  //Creating a third list and check the assignment operator (+ remove 2 elements)
  std::cout << "\nSecond List: (Assignment operator)";
  LList<int> thirdLis;
  thirdLis = secondList;
  thirdLis.removeAtHead();
  thirdLis.removeAtTail();
  thirdLis.print();
  
  secondList.clear();
  thirdLis.clear();
  
  secondList.print();
  thirdLis.print();
  std::cout << "List(3) size: " << thirdLis.getItemCount() << std::endl;
}

void test_stl_list(int randArray[]) {
  std::cout << "\n\nSTL List\n";
  std::list<int> stlList;         // STL List
  std::list<int>::iterator it;    // Iterator
  int count = 1;
  
  // Filling STL List container values from an array
  for (int i = 0; i < 100; i++)
    stlList.push_back(randArray[i]);
 
  // addToTail == push_back
  // addToHead == push_front
  // stlList.begin() == peekAtHead()
  // stlList.end() == peekAtTail()
  
  // Output of list values from the beginning to the end
  for (it = stlList.begin(); it != stlList.end(); it++) {
    std::cout << "Node(" << count++ << ") - " << *it << std::endl;
  }
}

