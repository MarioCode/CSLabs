//
//  main.cpp
//  StringMatching
//

#include <iostream>
#include <string>


// Prototype
void string_match(std::string baseStr, std::string pattern);


// Main function
int main(int argc, const char * argv[]) {
  std::string baseStr, patternStr;
  
  // Interactive input:
  std::cout << "Enter base string: ";
  std::getline(std::cin, baseStr);
  
  std::cout << "Enter pattern string: ";
  std::getline(std::cin, patternStr);
  
  // Get result
  string_match(baseStr, patternStr);
  return 0;
}


// Base string matching algorithm
void string_match(std::string baseStr, std::string pattern)
{
  unsigned long strLength = baseStr.length();
  unsigned long patternLength = pattern.length();
  bool isMatch = false;
  int countMatch = 0;
  
  for(int i = 0 ; i <= strLength - patternLength ; i++)
  {
    int j = 0;
    
    while(j < patternLength && pattern[j] == baseStr[i + j])
    {
      j = j + 1;
    }
    
    if(j == patternLength)
    {
      isMatch = true;
      countMatch++;
      std::cout << "Strings match starting with " << i << " index" << std::endl;
    }
  }
  
  if (!isMatch)
    std::cout << "Strings no match =(" << std::endl;
  else
    std::cout << "Total found: " << countMatch << " match!" << std::endl;
    
  return;
}



