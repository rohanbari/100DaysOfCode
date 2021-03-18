/**
 * @file smart_pointers.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief There are three smart pointers available in the C++ standard, i.e.
 * unique_ptr, shared_ptr and weak_ptr respectively. These the automated memory
 * managers that we don't need to use new and delete keywords. These are
 * designed to prevent the possible problems like memory leaks in huge programs.
 *
 * This program illustrates the various definitions of all the three types of
 * automated memory management systems.
 *
 * @version 0.1
 * @date 2021-03-18
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>
#include <memory>

// Forward declaration of the class for type aliasing
class Class;

// Using this to omit std:: prefix everywhere around
using namespace std;

// Type-aliasing for increasing readability
using UniquePtr = unique_ptr<Class>;
using SharedPtr = shared_ptr<Class>;
using WeakPtr = weak_ptr<Class>;

class Class {
  int member;

public:
  Class() { cout << "Constructing " << member << endl; }
  Class(int _mem) : member(_mem) {}
  ~Class() { cout << "Destructing " << member << endl; }

  void operator=(const Class &rhs) { this->member = rhs.member; }
  int getValue(void) const { return member; }
};

/**
 * @brief This is used in example_uniquePtr function.
 *
 * Passes-by-reference to test if the values are really transferred. Note that
 * pass-by-reference is NOT allowed programmatically.
 */
void uniquePtr_copy(UniquePtr &uniquePtr) {
  UniquePtr uPtr{make_unique<Class>()};
  *uPtr = 10;
  uPtr.swap(uniquePtr);

  cout << hex << showbase;
  cout << "uniquePtr_copy function's address: " << uPtr.get() << endl;

  cout << fixed << noshowbase;
}

/**
 * @brief This subroutine describes the proper instantiation of unique_ptr
 * template and their benefits.
 *
 * Unique pointers can only have single instances of objects, i.e. they cannot
 * be copied but transferred from one to another.
 */
void example_uniquePtr() {
  // The make_unique template handles calling new, and the unique_ptr object
  // handles calling delete when the unique_ptr instance goes out of scope.
  UniquePtr ptrInstance{make_unique<Class>()};
  std::cout << "Current address: " << ptrInstance.get() << std::endl;

  uniquePtr_copy(ptrInstance);
}

int main(void) {
  example_uniquePtr();

  return 0;
}