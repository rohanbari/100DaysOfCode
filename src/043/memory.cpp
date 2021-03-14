/**
 * @file memory.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Memory management is a fundamental technique that every C/C++
 * programmer should be aware of. This program elegantly illustrates about the
 * three types of memory - including a C++ standardized std::shared_ptr<>
 * template.
 *
 * @version 0.1
 * @date 2021-03-15
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>
#include <memory>

// Forward declaration of the class Memory
class Memory;

const int MAXELEMS = 5;
// Aliasing the std::shared_ptr<> declaration to increase readability
using SharedMemory = std::shared_ptr<Memory>;

/**
 * @brief The Memory class.
 *
 */
class Memory {
  int number;

public:
  // The default constructor
  Memory() = default;
  // List-initializer invoker
  Memory(int x) : number(x) {}
  // Rule-of-Three: The copy constructor
  Memory(const Memory &rhs) = default;
  // Rule-of-Three: The copy assignment overload
  Memory &operator=(const Memory &rhs) = default;
  // Rule-of-Three: The default destructor
  ~Memory() = default;

  // Overload to the put-to operator
  friend std::ostream &operator<<(std::ostream &out, const Memory &rhs) {
    return out << rhs.number;
  }
};

/**
 * @brief This subroutine describes about the memory management of stacks.
 */
void stackMemory(void) {
  // These variables are stored in the stack memory
  char ch = 'm';
  uint16_t age = 32;
  double salary = 100;

  std::cout << ch << '\n' << age << '\n' << salary << std::endl;

  // Variables declared onto the stack don't need to be freed manually
}

/**
 * @brief This subroutine describes about the memory management of heaps.
 */
void heapMemory(void) {
  // Declaration of the heap memory
  Memory *mem = new Memory[MAXELEMS];

  // Calling the operator=() overload and pushing the values onto the object
  // 'mem' pointer that is stored in the heap - to initialize the elements
  mem[0] = 10;
  mem[1] = 20;
  mem[2] = 20;
  mem[3] = 30;
  mem[4] = 40;

  // Displaying the results on the screen
  for (int i = 0; i < MAXELEMS; i++)
    std::cout << mem[i] << std::endl;

  // Deleting the memory - needs to be done MANUALLY
  delete mem;
  mem = nullptr;

  // NOTE:  Uncommenting the code below will result a segfault, because the
  //        memory pointed to mem was deallocated.

  // for (int i = 0; i < 5; i++)
  //   std::cout << mem[i] << std::endl;
}

/**
 * @brief This subroutine describes the implementation of the shared memory
 * that don't need to be freed manually.
 */
void sharedMemory(void) {
  SharedMemory sMem{new Memory(100)};
  std::cout << *sMem << std::endl;

  // 'sMem' automatically frees as soon as it goes out of scope
}

int main(void) {
  stackMemory();
  heapMemory();
  sharedMemory();

  return 0;
}