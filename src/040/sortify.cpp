#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Person {
  string name;
  int32_t age;

public:
  Person() {}
  Person(string _name, int32_t _age) : name(_name), age(_age) {}
  Person(const Person &rhs) : name(rhs.name), age(rhs.age) {}
  Person &operator=(const Person &rhs) {
    this->name = rhs.name;
    this->age = rhs.age;

    return *this;
  }
  ~Person() noexcept {}

  friend ostream &operator<<(ostream& out, const Person &rhs) {
    return out << "Name : " << rhs.name << '\n' << "Age: " << rhs.age;
  }
};

int main(void) {
  vector<Person> people;
  int32_t number;
  string tempName;
  int32_t tempAge;

  cout << "How many people? ";
  cin >> number;

  for (int i = 0; i < number - 1; i++) {
    cout << "Name of the person " << i + 1 << ": ";
    getline(cin, tempName);

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Age of the person: ";
    cin >> tempAge;

    if (!cin.good()) {
      cerr << "The input is not a valid integer. Force Quit." << endl;
      return EXIT_FAILURE;
    }
  }

  cout << "How would you like to sort?" << endl
       << " 1 - By Name" << endl
       << " 2 - By Age" << endl;
  cin >> number;

  if (!cin.good()) {
    cerr << "The input must be a valid number. Data Discarded." << endl;
    return EXIT_FAILURE;
  }

  switch (number) {
    case 1: {
      sort(people.begin(), people.end());
      break;
    }
    case 2: {
      break;
    }
    default: {
      cerr << "No such option found. Quitting." << endl;
      return EXIT_FAILURE;
    }
  }

  for (const auto &it : people) {
    cout << it << endl;
  }

  return 0;
}