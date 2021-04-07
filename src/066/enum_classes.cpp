/**
 * @file enum_classes.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief C++20 introduces a new feature for using enumerations. It is to bring
 * an enum's members into scope to remove redundant code to increase
 * readability.
 *
 * @version 0.1
 * @date 2021-04-07
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>
#include <string_view>

enum ColorChannel { red, green, blue };

namespace EnumClass {
    std::string_view selectChannel(const ColorChannel &channel) {
        switch (channel) {
            // Without using: using enum ColorChannel
            case red: return "red";
            case green: return "green";
            case blue: return "blue";
            default: return "error";
        }
    }
} // namespace EnumClass

int main(void) {
    std::cout << "selectChannel(): "
              << EnumClass::selectChannel(ColorChannel::green) << std::endl;
    return 0;
}