/**
 * @file folding_expr.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief Folding expressions are one of the most efficient feature introduced
 * in C++17 that establishes and empowers the use of variadic templates.
 *
 * This program demonstrates how the variadic template parameter packs works.
 *
 * @note C++17 and higher is required to compile this.
 *
 * @version 0.1
 * @date 2021-04-04
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>

using std::cout;

namespace FoldingExpression {

    /**
     * @brief Accumulates the given value and returns it.
     *
     * @tparam  Args    Variadic template invoker
     * @param   values  The passed parameter pack as argument
     * @return  Sum of  "values"
     */
    template <typename... Args>
    auto addValues(Args... values) {
        // Expanding the parameter packs
        return (values + ... + 0);
    }

    /**
     * @brief Alternative equivalent to addValue().
     *
     * @tparam  Args    Variadic template invoker.
     * @param   values  The passed parameter pack as argument
     * @return  auto    Sum of "values"
     */
    template <typename... Args>
    auto accumulate(Args... values) {
        // Equivalent to addValues() except it doesn't add ZERO that has no
        // effect in the output
        return (values + ...);
    }
} // namespace FoldingExpression

int main(void) {
    auto val1 = FoldingExpression::addValues(10, 20, 30, 40);
    auto val2 = FoldingExpression::accumulate(10, 20, 30, 40, 50, -10);

    cout << "addValues(): " << val1 << std::endl;
    cout << "accumulate(): " << val2 << std::endl;

    return 0;
}