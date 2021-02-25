/**
 * @file idealClass.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Classes are one of the elementary concept introduced in Object-
 * oriented paradigm, abbreviated as OOP. This program thoroughly
 * explains about the basic features of classes in C++ with some of their
 * general rules followed during defining them.
 *
 * @note This program does not inform anything about achieving Polymorphism,
 * late-binding (a.k.a. dynamic binding), Inheritance, etc. They will be
 * explained in the upcoming program.
 *
 * @version 0.1
 * @date 2021-02-25
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

class IdealClass {
  // NOTE: The scope of these attributes, also called as fields are by default
  // private to the outside, i.e. only visible till the scope of the class.
  // This is how we achieve Encapsulation theory of Object-oriented paradigm.
  //
  // It is considered good to keep the class fields unexposed to the outside
  // part of the code, they must be initialized before their usage, otherwise,
  // their direct usage will invoke an undefined-behavior later.

  int attribute;    // The attributes of the class,
  double field;     // also abbreviated as fields
  string memberVar; // or member variables of the class

public:
  // The default constructor
  IdealClass() {}
  // List initialization type constructor
  IdealClass(int attr, double fld, string mVar)
      : attribute(attr), field(fld), memberVar(mVar) {}
  // The default destructor
  ~IdealClass() {}

  // Overloading the operator '<<' to invoke this in file streams or the
  // instances of the type std::ostream& to display the results on the screen
  friend ostream &operator<<(ostream &out, const IdealClass &iC) {
    return out << iC.attribute << ' ' << iC.field << ' ' << iC.memberVar;
  }
};

int main(void) {
  // Creating an instance (object) of IdealClass [calling IdealClass() {}]
  // constructor
  IdealClass idealClass;

  // Creating an pointer-to-object of type IdealClass
  IdealClass *idealClassPtr = new IdealClass;

  // Creating an instance of IdealClass and initializing the class fields
  // by calling the initialization-list type constructor
  IdealClass idealClassInit(3, 4.2, "hello");

  // C++ automatically defines constructors (copy constructor called here) and
  // destructors to reduce the code complexity
  idealClassPtr = &idealClassInit;

  cout << "Defined fields with the generated copy constructor: "
       << *idealClassPtr << endl;

  return 0;
}