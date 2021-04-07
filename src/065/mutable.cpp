/**
 * @file mutable.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief The 'mutable' keyword allows to modify the class attributes in from
 * const member functions. This program enlightens the importance of this
 * keyword.
 *
 * @version 0.1
 * @date 2021-04-06
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>

class TestClass {
    // Removing 'mutable' will make this code non-compileable for line 28
    mutable uint32_t member;

  public:
    TestClass() = default;
    TestClass(int _mem) : member(_mem){};
    ~TestClass() = default;

    void constSubroutine(void) const {
        member = 10;
        std::cout << "constSubroutine(): variable altered: " << member
                  << std::endl;
    }
};

int main(void) {
    // The initialized value was 100
    TestClass testClass(100);
    // That changes into 10
    testClass.constSubroutine();

    return 0;
}