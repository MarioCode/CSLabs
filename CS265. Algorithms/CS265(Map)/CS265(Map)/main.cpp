//
//  main.cpp
//  CS265(Map)
//
//

#include <iostream>
#include <map>

//Function Prototypes

void printNonRecurring(std::string strIn, int);


int main(int argc, const char * argv[]) {
  
  std::string str = "test for string";
  int strSize = str.length();
  
  // Test the printNonRecurring Algorytm.
  printNonRecurring(str, strSize);
  
  return 0;
}



void printNonRecurring(std::string str, int strSize)
{
  //Initialize a set of key-value pairs.
  std::map<char, int> charCounts;
  
  //Ensure the incoming string is all lower-case.
  for (int i = 0; i < strSize - 1; i++)
    str[i] = tolower(str[i]);
  
  //Iterate through each character of the string.
  //Increment the count of each character in a Map.
  for (int i = 0; i < strSize - 1; i++)
    charCounts[str[i]]++;
  
  //Iterate through the Map.
  std::cout << "Non-repeating characters: \n[ ";
  for (std::map<char, int>::iterator itr = charCounts.begin(); itr != charCounts.end(); itr++)
  {
    //Pring the key of each character with a value of exactly 1.
    if (itr->second == 1)
      std::cout << itr->first << " ";
  }
  
  std::cout << "]\n\nRepeating characters: \n";
  for (std::map<char, int>::iterator itr = charCounts.begin(); itr != charCounts.end(); itr++)
    if (itr->second != 1)
      std::cout << itr->first << " - " << itr->second << " times \n";
  
  std::cout << std::endl;
}
