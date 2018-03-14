//
// CS265 Algorithms: Lab 3 - Search Algorithms
//

#include <chrono>      // For high-precision time
#include <iostream>    // cout
#include <string>      // string
#include <thread>      // Multi-threading
#include <time.h>      // random

void example();
void hello(std::string in_name);
void brute_force_search(int arr[], int size, int key, bool &p_bResult);
void divide_and_conquer(int arr[], int size, int key, bool &p_bResult);
void divide_and_conquer_recursion(int arr[], int l, int r, int key,  bool &p_bResult);
void printDuration(std::chrono::high_resolution_clock::time_point start, std::chrono::high_resolution_clock::time_point stop, std::string name, bool result = false);

int main(int argc, const char * argv[])
{
  srand(time(NULL));
  
  // **** START ASSIGNMENT ****
  
  std::chrono::high_resolution_clock::time_point t_start, t_stop;
  int randomArray[10000] = { 0 };
  int randomKey = rand() % 10000;
  bool result = false;
  
  for (int i = 0; i < 10000; i++)
    randomArray[i] = rand() % 10000;

  // BRUTE FORCE
  t_start = std::chrono::high_resolution_clock::now();
  brute_force_search(randomArray, 10000, randomKey, result);
  t_stop = std::chrono::high_resolution_clock::now();
  printDuration(t_start, t_stop, "Brute Force", result);
  result = false;
  
  
  // DIVIDE & CONQUER
  
  // Version 1. It is used to create two threads that use brute force (and copying two arrays)
  t_start = std::chrono::high_resolution_clock::now();
  divide_and_conquer(randomArray, 10000, randomKey, result);
  t_stop = std::chrono::high_resolution_clock::now();
  printDuration(t_start, t_stop, "Divide_and_conquer - Thread", result);
  result = false;

  //Version 2. Using a recursive algorithm (without threads)
  t_start = std::chrono::high_resolution_clock::now();
  divide_and_conquer_recursion(randomArray, 0, 10000, randomKey, result);
  t_stop = std::chrono::high_resolution_clock::now();
  printDuration(t_start, t_stop, "Divide_and_conquer - Recursion", result);
 
  // **** END ASSIGNMENT ****
  
  system("pause");
  
  return  0;
}

void brute_force_search(int arr[], int size, int key, bool &p_bResult)
{
  // Search through the array item-by-item until we find it.
  for (int i = 0; i < size; i++)
  {
    if (p_bResult || arr[i] == key)
    {
      // We found it! Exit the function now! :-)
      p_bResult = true;
      return;
    }
  }
  
  // We didn't find it... :-(
  p_bResult = false;
  return;
}

// NOTE: We'll start with just dividing the list in half,
//       but later, we will modify the function to break
//       up and multi-thread the list into any number of chunks.
void divide_and_conquer(int arr[], int size, int key, bool &p_bResult)
{
  int arr_1[5000] = { 0 };
  int arr_2[5000] = { 0 };

  for (int i = 0; i < 5000; i++)
  {
    arr_1[i] = arr[i];
    arr_2[i] = arr[i + 5000];
  }
  
  std::thread t1(brute_force_search, arr_1, 5000, key, std::ref(p_bResult));
  std::thread t2(brute_force_search, arr_2, 5000, key, std::ref(p_bResult));

  t1.join();
  t2.join();
}

// Divide and conquer with recursion
void divide_and_conquer_recursion(int arr[], int l, int r, int key,  bool &p_bResult) {
  if (l == r)
  {
    if (arr[l] == key)
      p_bResult = true;
    
    return;
  }
  
  if (p_bResult)
    return;
  
  int m = (l + r) / 2;
  divide_and_conquer_recursion(arr, l, m, key, p_bResult);
  divide_and_conquer_recursion(arr, m + 1, r, key, p_bResult);
  
  // Using recursion, but without threads.
  
  // I tried differently to use threads and recursion together,
  // but the result either was too long, or the compiler did not allow to start the recursion and the stream together.
  
  // std::thread t1(divide_and_conquer_recursion, arr, l, m, key, p_bResult);
  // t1.join();
}

// Print time difference (algorithm time)
void printDuration(std::chrono::high_resolution_clock::time_point start, std::chrono::high_resolution_clock::time_point stop, std::string name, bool result) {
  
  std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
  
  std::cout << "Time of: " << name << std::endl;
  std::cout << "It took me " << time_span.count() << " nanoseconds.";
  
  std::cout << "\nResult = ";
  if (result)
    std::cout << "true (number found)" << std::endl;
  else
    std::cout << "false (number not found)" << std::endl;
  
  std::cout << "\n\n";
}


/////////////////////////////////////////////////////
//  Example
/////////////////////////////////////////////////////


void example()
{
  // **** BEGIN EXAMPLE TIMER AND MULTI-THREADING CODE ****
  std::thread t1(hello, "Mikayla");
  std::thread t2(hello, "Glitch");
  
  // Start Timer
  std::chrono::high_resolution_clock::time_point t_start, t_stop;
  
  t_start = std::chrono::high_resolution_clock::now();
  
  // Start the threads.
  t1.join();
  t2.join();
  
  // Stop Timer
  t_stop = std::chrono::high_resolution_clock::now();
  
  // Report Timer Results
  printDuration(t_start, t_stop, "Test");
  
  // **** END EXAMPLE TIMER AND MULTI-THREADING CODE ****
}

void hello(std::string in_name)
{
  std::cout << "Hello, " << in_name.c_str() << "!\n";
}
