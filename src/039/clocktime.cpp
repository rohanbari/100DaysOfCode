/**
 * @file clocktime.cpp
 * @author Rohan Bari (rohanbari4@gmail.com)
 * @brief This program counts the time that acts like a stopwatch, except it
 * has no features to make checkpoints.
 *
 * @version 0.1
 * @date 2021-03-11
 *
 * @copyright Copyright (c) 2021 Rohan Bari
 *
 */

#include <iomanip>
#include <iostream>
#include <thread>

using namespace std::chrono;

/**
 * @brief The Timer class.
 */
class Timer {
  int hours = 0;
  int minutes = 0;
  int seconds = 0;
  int milliseconds = 0;

public:
  // Rule of Three: Copy constructor, copy assignment operator overload, and
  // the destructor
  Timer() {}
  Timer(int x, int y, int z, int p)
      : hours(x), minutes(y), seconds(z), milliseconds(p) {}
  Timer(const Timer &t)
      : hours(t.hours), minutes(t.minutes), seconds(t.seconds),
        milliseconds(t.milliseconds) {}

  Timer &operator=(const Timer &t) {
    this->hours = t.hours;
    this->minutes = t.minutes;
    this->seconds = t.seconds;
    this->milliseconds = t.milliseconds;

    return *this;
  }

  ~Timer() {}

  /**
   * @brief Initializes the counting process and the main code.
   */
  void start(void) {
    while (true) {
      std::this_thread::sleep_for(std::chrono::milliseconds(10));

      milliseconds++;

      if (milliseconds == 100) {
        seconds++;

        if (seconds == 60) {
          minutes++;

          if (minutes == 60) {
            hours++;
            minutes = 0;
          }
          seconds = 0;
        }
        milliseconds = 0;
      }

      // Updating the output every 10 milliseconds
      display();
    }
  }

  /**
   * @brief Displays the timer output.
   */
  void display(void) {
    std::cout << '\r';
    std::cout << std::setfill('0');
    std::cout << std::setw(2) << hours << " : " << std::setw(2) << minutes
              << " : " << std::setw(2) << seconds << " : " << std::setw(2)
              << milliseconds << std::flush;
  }
};

int main(void) {
  Timer timer;
  timer.start();

  return 0;
}