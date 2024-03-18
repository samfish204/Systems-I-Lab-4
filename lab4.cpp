// Copyright 2020
// Edited by: Samuel Fisher
// CSE278 - Section B
// Professor Vendome
// September 15, 2020
#include <iostream>
#include <string>
#include <unordered_map>

// Takes a reference to an unordered weekMap, and adds the correct
// keys and values into the map
void createWeekMap(std::unordered_map<std::string, int> &weekMap) {
  // Create an unordered map of the days of the week to integers
  // Sunday should be one, etc.  Make sure to capitalize the names of the
  // days.
  weekMap = {{"Sunday", 1}, {"Monday", 2}, {"Tuesday", 3}, {"Wednesday", 4},
  {"Thursday", 5}, {"Friday", 6}, {"Saturday", 7}};
}

// Takes a reference to an unordered monthMap, and adds the correct
// keys and values into the map
void createMonthMap(std::unordered_map<std::string, int> &monthMap) {
  // Create an unordered map of the months of the year to integers
  // January should be zero, etc.  Make sure to capitalize the names of the
  // Months.
  monthMap = {{"January", 1}, {"February", 2}, {"March", 3},
  {"April", 4}, {"May", 5}, {"June", 6}, {"July", 7},
  {"August", 8}, {"September", 9}, {"October", 10}, 
  {"November", 11}, {"December", 12}};
}

int main() {
  // Create an appropriate unordered_map that will map a std::string to
  // an int
  using StrIntMap = std::unordered_map<std::string, int>;

  // Declare instances of the map called weekMap and monthMap
  StrIntMap weekMap; StrIntMap monthMap;

  // Invoke the function that will populate your week map
  createWeekMap(weekMap);
  
  // Invoke the function that will populate your month map  
  createMonthMap(monthMap);

  // Variables to track different words
  std::string currentWord1; std::string currentWord2;

  // Prompt the user for a month and day of the week continuously
  // (i.e. in a loop) until both of them are valid keys.  That is, the
  // user enters a valid month and day of the week.  You should use
  // an appropriate method acting on your week and month map instances
  // to determine whether their input is valid or not.
  int i = 1;
  while (i >= 0) {
      i = 1;
      std::cout << "Enter a month and weekday: ";
      std::string output; std::getline(std::cin, output);

      // Separate the current words
      currentWord1 = output.substr(0, output.find(' '));
      currentWord2 = output.substr(output.find(' ') + 1, output.size() - 1);

  // If the user enters an incorrect month, inform them with a message to
  // standard error with this format:
  //    "The month " << monthTheyEntered << " is not valid\n";
  // Otherwise, If the user enters an incorrect day of the week,
  // inform them with a message to standard error with this format:
  //    "The day " << dayTheyEntered << " is not valid\n";

      if (monthMap.find(currentWord1) == monthMap.end()) {
          std::cerr << "The month " << currentWord1 << " is not valid\n";
          i++;
      } else if (weekMap.find(currentWord2) == weekMap.end()) {
          std::cerr << "The day " << currentWord2 << " is not valid\n";
          i++;
      }
      i = i - 2;
  }
  // Once both the month and day are valid, write the mapping of their
  // month and day to the appropriate integer value.  The output should
  // look like this (without the quotes): "March, Tuesday => 3, 3"
  std::cout << currentWord1 << ", " << currentWord2 << " => " <<
  monthMap.at(currentWord1) << ", " << weekMap.at(currentWord2) << "\n";

  return 0;
}
