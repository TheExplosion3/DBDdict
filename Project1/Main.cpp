#include <iostream>
#include "Flashlight.h"
#include "Addons.h"
#include "BasicFunctions.h"
#include <string.h>
#include <vector>
#include <limits>
#include <nlohmann/json.hpp>

// user input variables, will get reused
unsigned short userInputUS;
std::string userInputS;
bool userInputB;

int main()  {
  std::cout << "Hello! Which item would you like to use?\n\n1 | Flashlight\n2 | Medkit\n3 | Key\n4 | Map\n5 | Toolbox\n6 | Exit\n" << std::endl;
  std::cin >> userInputUS;
  std::cout << '\n';
  F::userInputVerify(userInputUS);

  while(true) {
      switch(userInputUS) {
      case 0: {
        std::cout << "Hello! Which item would you like to use?\n\n1 | Flashlight\n2 | Medkit\n3 | Key\n4 | Map\n5 | Toolbox\n6 | Exit\n" << std::endl;
        std::cin >> userInputUS;
        std::cout << '\n';
        F::userInputVerify(userInputUS);
        continue;
      }
      case 1: {
        std::cout << "test" << std::endl;
        userInputUS = 0;
        continue;
      }
      case 2: {
        std::cout << "test" << std::endl;
        userInputUS = 0;
        continue;
      }
      case 3: {
        std::cout << "test" << std::endl;
        userInputUS = 0;
        continue;
      }
      case 4: {
        std::cout << "test" << std::endl;
        userInputUS = 0;
        continue;
      }
      case 5: {
        std::cout << "test" << std::endl;
        userInputUS = 0;
        continue;
      }
      case 6: {
        std::cout << "Thanks for using our program!" << std::endl;
        break;
      }
      default: {
        userInputUS = 0;
        std::cout << "Please only input correct numerical values, ranging from 1 and 6.\n" << std::endl;
        continue;
      }
    }
    break;
  }
  
}
