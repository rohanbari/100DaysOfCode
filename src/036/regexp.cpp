/**
 * @file regexp.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief The Regular Expression (also called "regex") is not a programming
 * language, but supported by them. These are heavily used to play with patterns
 * in walls of texts.
 *
 * This program demonstrates some examples of the regular expressions.
 *
 * @version 0.1
 * @date 2021-03-08
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iostream>
#include <regex>

// Only using for sake of simplicity
using namespace std;

int main(void) {
  string text = "The quick brown fox jumps over a lazy dog. I went to the "
                "market to buy some cold drinks and pizzas. The dog outside is "
                "barking too much. I have found my watch that was lost a year "
                "ago. It's just a basic tub-dub-doo string.";
  regex exp1("(.*)(too)(.*)");

  if (regex_match(text, regex("(.*)(too)(.*)")))
    cout << "Regex match found!" << endl;

  if (regex_match(text.begin(), text.end(), exp1))
    cout << "Matches found (full string checkup)." << endl;

  return 0;
}