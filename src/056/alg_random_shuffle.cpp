/**
 * @file alg_random_shuffle.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief The STL provides std::random_shuffle to shuffle a container (to be
 * specific, its containing values) randomly.
 *
 * This program helps to grasp this concept in an elegant way.
 *
 * @version 0.1
 * @date 2021-03-28
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <vector>

using namespace std;

// Type-alias representing the default vector type used in this program
using Vector = vector<int>;

class RandomShuffle {
    Vector numbers;

  public:
    // The default constructor
    RandomShuffle() = default;
    // The default initializer-list overload
    RandomShuffle(const Vector& rhs) : numbers(rhs) {}
    // The default copy constructor
    RandomShuffle(const RandomShuffle& rhs) = default;
    // The default copy assignment operator overload
    RandomShuffle& operator=(const RandomShuffle& rhs) = default;
    // The default destructor
    ~RandomShuffle() = default;

    void sortList(void) {
        // Sort the container from lower to greater order
        sort(numbers.begin(), numbers.end());
    }

    void shuffle(void) {
        // Shuffle the container randomly using unique seeds
        srand(time(NULL));
        random_shuffle(numbers.begin(), numbers.end());
    }

    friend ostream& operator<<(ostream& out, const RandomShuffle& rhs) {
        out << "shuffle(): ";

        for (const auto& it : rhs.numbers)
            out << it << ' ';

        // To display the results
        return out;
    }
};

int main(void) {
    const initializer_list<int> values{10, -2, 4, 6, 1, 0};
    RandomShuffle randomShuffle{values};

    randomShuffle.sortList();
    randomShuffle.shuffle();

    cout << randomShuffle << endl;

    return 0;
}
