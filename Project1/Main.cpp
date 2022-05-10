#include <iostream>
#include <string.h>
#include <algorithm>
#include <nlohmann/json.hpp>
#include "Medkit.h"
#include "Flashlight.h"
#include "Addons.h"
#include "BasicFunctions.h"

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
          if(userInputUS < 0 && userInputUS > 6) {
            std::cout << "Please only input valid numerical inputs between 1 and 5.\n" << std::endl;
            F::inputReset();
            std::cin >> userInputUS;
          }
          else {
            break;
          }
        }
        
        fObject.O::Flashlight::flashlightTypeSetter(userInputUS);
        // checks for if therse an addon or not, then adds it if present. if there is no addon, it bypasses this step and the next one as well
        std::cout << "If there is an addon, what is it's name? If there is not one, then type N/A\n" << std::endl;
        std::cin.clear();
        std::getline(std::cin >> std::ws, userInputS);
        if(userInputS.compare("N/A") == 0) {
          fObject.O::Flashlight::printFLO();
          userInputUS = 0;
          continue;
        }
        else {
          addonsPresent = F::addonAdder(userInputS, fObject, 0);
        }
        if(fObject.getAddOn(0).getForItem() != "Flashlight") {
          while(true) {
            F::addonAdder("Placeholder", fObject, 0);
            std::cout << "\nPlease only input addons for Flashlights. Alternatively, type N/A to exit.\n" << std::endl;
            std::getline(std::cin >> std::ws, userInputS);
            F::addonAdder(userInputS, fObject, 0);
            if(fObject.getAddOn(0).getForItem() == "Flashlight") {
              break;
            }
            else if(lowercaseString(userInputS).compare("n/a") == 0) {
              F::effectCalculator(1, fObject);
              fObject.O::Flashlight::printFLO();
              goto bypass;
            }
          }
        }


        // same as previous comment
        if(addonsPresent == true) {
          std::cout << "If there is a second addon, what is it's name? If there is not one, then type N/A\n" << std::endl;
          std::cin.clear();
          std::getline(std::cin >> std::ws, userInputS);
          std::cout << '\n';
          // verifies addon is not the same, and if it is then it will proceed to alert the user about it, otherwise it continues.
          
          userInputS = lowercaseString(userInputS);
          
          // if N/A is found, prints the object and the first addon, and returns to the main program.
          
          if(lowercaseString(userInputS).compare("n/a") == 0) {
            F::effectCalculator(1, fObject);
            fObject.O::Flashlight::printFLO();
            fObject.O::Flashlight::printFLA(0);
            goto bypass;
          }
          
          // verifies that user input for the addon isnt the same as the first addon already entered
          while(true) {
            if(lowercaseString(fObject.getAddOn(0).getName()).compare(lowercaseString(userInputS)) == 0) {
              F::addonAdder("Placeholder", fObject, 1);
              std::cout << "You can't have 2 of the same addon, type a different one or type N/A to exit." << std::endl;
              std::cin.clear();
              std::getline(std::cin >> std::ws, userInputS);
              bool temp = F::addonAdder(userInputS, fObject, 1);
              if(temp != true) {
                std::cout << '\n' << std::endl;
                F::effectCalculator(1, fObject);
                fObject.O::Flashlight::printFLO();
                fObject.O::Flashlight::printFLA(0);
                goto bypass;
              }
              if(lowercaseString(fObject.getAddOn(0).getName()).compare(lowercaseString(userInputS)) != 0) {
                break;
              }
              else if(lowercaseString(userInputS).compare("n/a") == 0) {
                std::cout << '\n' << std::endl;
                F::effectCalculator(1, fObject);
                fObject.O::Flashlight::printFLO();
                fObject.O::Flashlight::printFLA(0);
                goto bypass;
              }
            }
            else {
              break;
            }
          }
          F::addonAdder(userInputS, fObject, 1);
          
          if(fObject.getAddOn(1).getForItem() != "Flashlight") {
            while(true) {
              F::addonAdder("Placeholder", fObject, 1);
              std::cout << "Please only input addons for Flashlights. Alternatively, type N/A to exit.\n" << std::endl;
              std::getline(std::cin >> std::ws, userInputS);
              
              bool temp = F::addonAdder(userInputS, fObject, 1);
              
              if(temp != true) {
                std::cout << '\n' << std::endl;
                F::effectCalculator(1, fObject);
                fObject.O::Flashlight::printFLO();
                fObject.O::Flashlight::printFLA(0);
                goto bypass;
              }
              if(fObject.getAddOn(1).getForItem() == "Flashlight") {
                break;
              }
              else if(lowercaseString(userInputS).compare("n/a") == 0) {
                std::cout << '\n' << std::endl;
                F::effectCalculator(1, fObject);
                fObject.O::Flashlight::printFLO();
                fObject.O::Flashlight::printFLA(0);
                goto bypass;
              }
            }
          }
        }
        
        // checks if one addon is present, or two, single addon check is for safety and fallback measures
        if(addonsPresent == true) {
          if(fObject.getAddOn(1).getName().compare(" ") == 0) {
            F::effectCalculator(1, fObject);
          }
          else {
            F::effectCalculator(2, fObject);
          }
        }
        
        // prints flashlight object and both addons, with spaces inbetween each addon and the flashlight itself
        fObject.O::Flashlight::printFLO();
        std::cout << '\n';
        fObject.O::Flashlight::printFLA(0);
        std::cout << '\n';
        fObject.O::Flashlight::printFLA(1);
        std::cout << '\n';

        // label for goto statements, needs to have something in it so i just replicated what was there before
        bypass:
          userInputUS = 0;
          continue;
        
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
