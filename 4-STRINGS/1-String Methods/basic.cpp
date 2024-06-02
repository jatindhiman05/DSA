#include <iostream>
using namespace std;

int main()
{
  string str;

  cout << "Enter String: ";
  cin >> str;

  // length of string
  cout << "Length of string: " << str.length() << endl;

  // Check if string is empty or not
  cout << "String is empty or not: " << str.empty() << endl;

  // access string elements
  cout << "Character at position 3 is: " << str.at(3) << endl;

  // get the front character of string
  cout << "Front character of string is: " << str.front() << endl;

  // get the last character of string -> back()
  cout << "Last character of string is: " << str.back() << endl;

  // apppend
  string str1 = "Jatin";
  string str2 = "Dhiman";
  cout << "Before appending" << endl;
  cout << str1 << endl;
  cout << str2 << endl;

  str1.append(str2);

  cout << "After appending" << endl;
  cout << str1 << endl;
  cout << str2 << endl;

  // erase in string
  string desc = "This is a car";
  desc.erase(4, 3);
  cout << desc << endl;

  // insert function
  string str4 = "Jatin Dhiman";
  string middle = "Ji";
  str4.insert(5, middle);
  cout << "Printing str4:  " << str4 << endl;

  // find -> Finds the first occurrence of a specified substring.
  string str6 = "Hello World ";
  string str7 = "rld";

  if (str6.find(str2) == string::npos)
  {
    // not found
    cout << "Not FOund" << endl;
  }
  else
  {
    cout << "Found" << endl;
  }

  string str8 = "Jatin Dhiman";
  string str9 = "Kamal Dhiman";

  // Compares two strings lexicographically.
  if (str1.compare(str2) == 0)
  {
    cout << "Matching" << endl;
  }
  else
  {
    cout << "Not matching " << endl;
  }

  // substr -> Returns a substring starting from a specified position.
  string desc1 = "Today is a good day isn't it ?";
  cout << desc1.substr(11, 5) << endl;

  return 0;
}