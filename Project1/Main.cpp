#include <iostream>
#include "Flashlight.h"
#include "Addons.h"
#include "BasicFunctions.h"
#include <string.h>
#include <vector>
#include <nlohmann/json.hpp>

// user input variables, will get reused
unsigned short userInputUS;
std::string userInputS;
bool userInputB;

int main()  {
  // gets initial user input for switch statement
  std::cout << "Hello! Which item would you like to use?\n\n1 | Flashlight\n2 | Medkit\n3 | Key\n4 | Map\n5 | Toolbox\n6 | Exit\n" << std::endl;
  std::cin >> userInputUS;
  std::cout << '\n';
  F::userInputVerify(userInputUS);

  while(true) {
      switch(userInputUS) {
      case 0: {
        // gets user input if input was invalid, or after a previous segment executes.
        std::cout << "Hello! Which item would you like to use?\n\n1 | Flashlight\n2 | Medkit\n3 | Key\n4 | Map\n5 | Toolbox\n6 | Exit\n" << std::endl;
        std::cin >> userInputUS;
        std::cout << '\n';
        F::userInputVerify(userInputUS);
        continue;
      }
      // case for flashlight
      case 1: {
        // defines the flashlight object, and then its rarity immediately afterwards via user input
        O::Flashlight fObject;
        std::cout << "Which rarity is it?\n\n1 | Uncommon\n2 | Rare\n3 | Very Rare\n4 | Event (Will O' Wisp)\n5 | Event (Anniversary Flashlight)\n" << std::endl;
        std::cin >> userInputUS;
        std::cout << '\n';
        F::userInputVerify(userInputUS);
        // verifies that the number is in bounds for the cases within the flashlight function
        while(true) {
          if(!(userInputUS > 0 && userInputUS < 6)) {
            std::cout << "Please only input valid numerical inputs between 1 and 5.\n" << std::endl;
            std::cin.ignore(10000, '\n');
            std::cin >> userInputUS;
          }
          else {
            break;
          }
        }
        
        fObject.O::Flashlight::flashlightTypeSetter(userInputUS);

        std::cout << "If there is an addon, what is it's name? If there is not one, then type N/A" << std::endl;
        F::inputResetSync();
        std::getline(std::cin, userInputS);
        bool addonsPresent;
        
        addonsPresent = F::addonAdder(userInputS, fObject);

        userInputUS = 0;
        std::cout << '\n';
        continue;
      }
      case 2: {
        std::cout << "test" << std::endl;
        userInputUS = 0;
        std::cout << '\n';
        continue;
      }
      case 3: {
        std::cout << "test" << std::endl;
        userInputUS = 0;
        std::cout << '\n';
        continue;
      }
      case 4: {
        std::cout << "test" << std::endl;
        userInputUS = 0;
        std::cout << '\n';
        continue;
      }
      case 5: {
        std::cout << "test" << std::endl;
        userInputUS = 0;
        std::cout << '\n';
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
