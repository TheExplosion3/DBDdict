#include <iostream>
#include <string.h>
#include <limits>

namespace F {
  // Resets the input stream
  void inputReset() {
  std::cin.ignore(10000, 'n');
  std::cin.clear();
  }

// User input verifiers
  // For unsigned shorts
  void userInputVerify(unsigned short var) {
    while(true) {
      if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please only enter numerical values.\n" << std::endl;
        std::cin >> var;
      }
      if(!std::cin.fail()) {
        break;
      }
    }
  }
  // For strings
  void userInputVerify(std::string var) {
    while(true) {
      if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please only enter valid characters.\n" << std::endl;
        std::cin >> var;
      }
      if(!std::cin.fail()) {
        break;
      }
    }
  }
  // For booleans
  void userInputVerify(bool var) {
    while(true) {
      if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please only enter true/false.\n" << std::endl;
        std::cin >> var;
      }
      if(!std::cin.fail()) {
        break;
      }
    }
  }
}