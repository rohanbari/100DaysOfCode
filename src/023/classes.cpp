/**
 * @file classes.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program is to illustrate the basic format of a C++ class, the
 * implementation of the initialization-list to initialize the fields. This
 * introduces the concept of default constructors.
 *
 * @version 0.1
 * @date 2021-02-23
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <cmath>
#include <iostream>

// Instead of applying statement like: using namespace std, it's better to use
// specifically required namespace members
using std::cout;
using std::endl;
using std::ostream;

/**
 * @brief The Graph class.
 */
class Graph {
  int x;
  int y;

public:
  /**
   * @brief Explicitly shown constructors a new Graph object.
   */
  Graph() {}
  Graph(int a, int b) : x(a), y(b) {}

  /**
   * @brief Function to obtain the hypotenuse of a triangle of (X, Y) coords.
   * from the origin axis.
   *
   * @return Square root of addition of X^2 and Y^2
   */
  double hypotenuse(void);

  /**
   * @brief Overloading the std::ostream operator<< with reference to it.
   *
   * @param os Output stream
   * @param graph Instance of the Graph object
   * @return The initialized 'os' (type of std::ostream&)
   */
  friend ostream &operator<<(ostream &os, const Graph &graph) {
    return os << "X: " << graph.x << " and Y: " << graph.y << endl;
  }
};

double Graph::hypotenuse(void) {
  // Following the formula: sqrt(x^2 + y^2)
  double exp = sqrt(pow(this->x, 2) + pow(this->y, 2));
  return exp;
}

int main(void) {
  // Declaring and initializing a Graph object
  Graph g(1, 4);
  // Calling the overloaded operator<< definition
  cout << g;

  // Displaying the final results
  cout << "x^2 + y^2 gives " << g.hypotenuse() << std::endl;

  return 0;
}