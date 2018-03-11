//
//  DynamicArray.h
//  DynamicArray
//

#ifndef DynamicArray_h
#define DynamicArray_h

class DynamicArray {
  
  //Data Members
private:
  int *array;
  int capacity;
  int itemCount;
  
public:
  // Constructors & Destructor
  DynamicArray();                  // First (default) Constructor
  DynamicArray(int _capacity);     // Second Constructor
  DynamicArray (const DynamicArray &fromArray);  // Copy Constructor
  DynamicArray operator= (const DynamicArray &fromArray); // Copy assignment operator
  ~DynamicArray();

  // Basic methods
  void initArray();
  void clear();
  void push_back(int element);
  int pop_back();
  void copyArray(const DynamicArray& fromArray);
  
  // Helper's methods
  int getSize();
  void resize(int newCapacity);
  void print();
};

#endif /* DynamicArray_h */
