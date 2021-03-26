/**
 * @file numeric_limits.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief The numeric_limits class template provides a standardized way to query
 * various properties of arithmetic types (e.g. the largest possible value for
 * type int is std::numeric_limits<int>::max()).
 *
 * This program provides several examples where numeric_limits could be applied.
 *
 * @version 0.1
 * @date 2021-03-26
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>
#include <limits>

using namespace std;

/**
 * @brief Some situation comes where one needs to keep asking the user for a
 * valid input. In C++, using std::cin will likely to become a headache.
 */
void ignoreMalformedInput(void) {
    int input;

    cout << "Try any input that is not an integer: ";

    // Looping until  input  is not an integer
    while (!(cin >> input)) {
        cerr << "The input was not an integer.\nTry again: ";

        // To clear the previous buffer
        cin.clear();
        // To discard the newline
        cin.ignore(numeric_limits<int>::max(), '\n');
    }
}

/**
 * @brief When a programmer needs to know about the max/min values to be known,
 * std::numeric_limits is used for this purpose. Their ranges may vary since the
 * capacities of different data types are implementation-defined.
 */
void printLowestMinMax(void) {
    cout << "\ntype\tlowest()\tmin()\t\tmax()\n\n"
         << "bool\t" << numeric_limits<bool>::lowest() << "\t\t"
         << numeric_limits<bool>::min() << "\t\t" << numeric_limits<bool>::max()
         << '\n'
         << "uchar\t" << +numeric_limits<unsigned char>::lowest() << "\t\t"
         << +numeric_limits<unsigned char>::min() << "\t\t"
         << +numeric_limits<unsigned char>::max() << '\n'
         << "int\t" << numeric_limits<int>::lowest() << '\t'
         << numeric_limits<int>::min() << '\t' << numeric_limits<int>::max()
         << '\n'
         << "float\t" << numeric_limits<float>::lowest() << '\t'
         << numeric_limits<float>::min() << '\t' << numeric_limits<float>::max()
         << '\n'
         << "double\t" << numeric_limits<double>::lowest() << '\t'
         << numeric_limits<double>::min() << '\t'
         << numeric_limits<double>::max() << '\n';
}

int main(void) {
    ignoreMalformedInput();
    printLowestMinMax();

    return 0;
}