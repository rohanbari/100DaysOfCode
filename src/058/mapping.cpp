/**
 * @file mapping.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief The std::map is a type of a container that accesses an element with
 * a key. Thus, to use std::map, a key to access its relative value. There is a
 * variety of other member functions that helps to manipulate it efficiently.
 *
 * @version 0.1
 * @date 2021-03-30
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>

#define ALIAS std::string, int

// Type-alias to represent the type of the map to be used
using Map = std::map<ALIAS>;

class UseMap {
    Map instance;

    void display(void) {
        for (auto&& it : instance)
            std::cout << it.first << ' ';
        std::cout << std::endl;
    }

  public:
    UseMap() = default;
    UseMap(const Map& map) : instance(map) {}
    UseMap(const UseMap& useMap) = default;
    UseMap& operator=(const UseMap& rhs) = default;
    ~UseMap() = default;

    void testPrint(void) {
        // Tries to access the value located at key Five
        std::cout << instance["Five"] << std::endl;
    }

    void testEmplace(void) {
        // Emplacing a pair (and not pushing back)
        auto pair = std::pair<ALIAS>("Six", 6);
        instance.emplace(pair);

        display();
    }

    void findIterator(void) {
        auto iter = instance.find("Zero");

        if (iter != instance.end())
            std::cout << "Found key: " << iter->first << std::endl;
    }
};

int main(void) {
    Map map = {
        std::pair<ALIAS>("Three", 3), std::pair<ALIAS>("One", 1),
        std::pair<ALIAS>("Two", 2),   std::pair<ALIAS>("Four", 4),
        std::pair<ALIAS>("Five", 5),  std::pair<ALIAS>("Zero", 0),
    };

    UseMap testInstance{map};

    testInstance.testPrint();
    testInstance.testEmplace();

    return 0;
}
