//
//  DynamicArray.cpp
//  DynamicArray
//

#include "DynamicArray.h"
#include <iostream>

// Constructors
DynamicArray::DynamicArray()
{
  capacity = 5;
  initArray();
}

DynamicArray::DynamicArray(int _capacity)
{
  if (_capacity >= 0)
  {
    capacity = _capacity;
    initArray();
  }
  else
  {
    std::cout << "Incorrect Size inputted\n";
    exit(EXIT_FAILURE);
  }
}

void DynamicArray::initArray()
{
  itemCount = 0;
  array = new int[capacity]();
}

// Copy Constructor
DynamicArray::DynamicArray (const DynamicArray &fromArray)
{
  copyArray(fromArray);
}

// Copy assignment operator
DynamicArray DynamicArray::operator= (const DynamicArray &fromArray)
{
  copyArray(fromArray);
  return *this;
}

void DynamicArray::copyArray(const DynamicArray& fromArray)
{
  array = new int [fromArray.capacity];
  capacity = fromArray.capacity;
  itemCount = 0;
  
  for (int i = 0; i < fromArray.itemCount; i++)
    push_back(fromArray.array[i]);
}

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

// Clear data and firstly set to zero (0)
void DynamicArray::clear()
{
  for (int i = 0; i < itemCount; i++)
    array[i] = 0;
  
  // Set size to 0
  itemCount = 0;
}


// Add the item to the back of the array.
void DynamicArray::push_back(int element)
{
  // Before insertion - check for fullness.
  if (itemCount == capacity)
    resize(capacity * 2);
  
  array[itemCount++] = element;
}


// Remove the last item from the array and return it.
int DynamicArray::pop_back()
{
  int item = array[--itemCount];
  
  if (((float)(itemCount) / (float)capacity) * 100 <= 40)
    resize(capacity / 2);
  
  return item;
}

// Resize array
void DynamicArray::resize(int newCapacity)
{
  capacity = newCapacity;

  //1. Creat a new array at double the size.
  int *pNewArr = new int[capacity];
    
  //2. Copy the contents of the old array into the new.
  for (int i = 0; i < itemCount; i++)
    pNewArr[i] = array[i];
    
  // Deallocate the old memory.
  delete[] array;
    
  // Reset the array pointer reference to point at the new array.
  array = pNewArr;
}


// Print array
void DynamicArray::print()
{
  std::cout << "Size array: " << itemCount << "/" << capacity << std::endl;
  std::cout << "Array: [";
  
  for (int i = 0; i < itemCount - 1; i++)
    std::cout << array[i] << ", ";
  
  std::cout << array[itemCount - 1] <<  "] \n\n";
}


// Return size of array
int DynamicArray::getSize() {
  return itemCount;
}

// Destructor
DynamicArray::~DynamicArray()
{
  delete []array;
}

