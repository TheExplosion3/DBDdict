#include <iostream>
#include "Flashlight.h"
#include "Addons.h"
#include "BasicFunctions.h"
#include <string.h>
#include <vector>
#include <algorithm>
#include <nlohmann/json.hpp>

// user input variables, will get reused
unsigned short userInputUS;
std::string userInputS;
bool userInputB;

int main() {
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
        bool addonsPresent;
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
        // checks for if therse an addon or not, then adds it if present. if there is no addon, it bypasses this step and the next one as well
        std::cout << "If there is an addon, what is it's name? If there is not one, then type N/A" << std::endl;
        std::cin.clear();
        std::getline(std::cin >> std::ws, userInputS);
        addonsPresent = F::addonAdder(userInputS, fObject, 0);

        // same as previous comment
        if(addonsPresent == true) {
          std::cout << "If there is a second addon, what is it's name? If there is not one, then type N/A" << std::endl;
          std::cin.clear();
          std::getline(std::cin >> std::ws, userInputS);
          // verifies addon is not the same, and if it is then it will proceed to alert the user about it, otherwise it continues.
          
          std::transform(userInputS.begin(), userInputS.end(), userInputS.begin(),
    [](unsigned char c){ return std::tolower(c); });
          
          std::string adName = fObject.getAddOn(0).getName();
          
          std::transform(adName.begin(), adName.end(), adName.begin(),
    [](unsigned char c){ return std::tolower(c); });
          
          while(true) {
            if(adName == userInputS) {
              std::cout << "You can't have 2 of the same addons, type a different one or type N/A to exit." << std::endl;
              std::cin.clear();
              std::getline(std::cin >> std::ws, userInputS);
            }
            else {
              break;
            }
          }
          F::addonAdder(userInputS, fObject, 1);  
        }
        
        if(addonsPresent == true) {
          if(fObject.getAddOns().size() == 1) {
            F::effectCalculator(0, fObject);
          }
          else {
            F::effectCalculator(0, fObject);
            F::effectCalculator(1, fObject);
          }
        }
        

        std::cout << "placeholder" << std::endl;
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
