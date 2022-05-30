#include <iostream>
#include <string.h>
#include <algorithm>
#include <nlohmann/json.hpp>
#include "Item.h"
#include "Addons.h"
#include "BasicFunctions.h"
#include "Medkit.h"
#include "Flashlight.h"
#include "Map.h"
#include "Key.h"
#include "Toolbox.h"

/*
  yeah i should refactor this but im kinda lazy and sorta just wanna finish this project,
  big O notation is only a theory and is a lie created by big code to make efficiency seem important haha funny
  (no seriously ive spent way too much time on this thing.)
*/

// user input variables, will get reused
unsigned short userInputUS = 0;
std::string userInputS = "";
// im only doing this for cleanliness and because it makes things look prettier, though im  not stupid enough to use using namespace std.
using namespace F;
using namespace O;

int main() {
  // gets initial user input for switch statement
  std::cout << "Hello! Which item would you like to use?\n\n1 | Flashlight\n2 | Map\n3 | Key\n4 | Medkit\n5 | Toolbox\n6 | Exit\n" << std::endl;
  std::cin >> userInputUS; 
  std::cout << '\n';
  userInputVerify(userInputUS);
  
  while(true) {
    switch(userInputUS) {
      case 0: {
        // label for goto statements, needs to have something in it so i just replicated what was there before. On top of that, I set it up in a false if statement so it doesn't interfere with the functionality of the primary program.;
        if(false) {  
          bypass:
            userInputUS = 0;
            continue;
        }
        
        // gets user input if input was invalid, or after a previous segment executes.
        std::cout << "Hello! Which item would you like to use?\n\n1 | Flashlight\n2 | Map\n3 | Key\n4 | Medkit\n5 | Toolbox\n6 | Exit\n" << std::endl;
        std::cin >> userInputUS;
        std::cout << '\n';
        userInputVerify(userInputUS);
        continue;
      }
      // case for flashlight
      case 1: {
        // defines the flashlight object, and then its rarity immediately afterwards via user input
        Flashlight fObject;
        
        bool addonsPresent = false;
        std::cout << "Which rarity is it?\n\n1 | Uncommon\n2 | Rare\n3 | Very Rare\n4 | Event (Will O' Wisp)\n5 | Event (Anniversary Flashlight)\n" << std::endl;
        std::cin >> userInputUS;
        std::cout << '\n';
        userInputVerify(userInputUS);
        // verifies that the number is in bounds for the cases within the flashlight function
        while(true) {
          if(userInputUS < 0 && userInputUS > 6) {
            std::cout << "Please only input valid numerical inputs between 1 and 5.\n" << std::endl;
            inputReset();
            std::cin >> userInputUS;
          }
          else {
            break;
          }
        }
        
        fObject.Flashlight::flashlightTypeSetter(userInputUS);
        // checks for if theres an addon or not, then adds it if present. if there is no addon, it bypasses this step and the next one as well. it also checks to make sure the addon is a valid flashlight addon, and if it isnt then it will bypass to the end of this segment of the program, and return to the main menu. this set of commands happens a lot, but too complicated to throw into a function.
        std::cout << "If there is an addon, what is it's name? If there is not one, then type N/A\n" << std::endl;
        std::cin.clear();
        std::getline(std::cin >> std::ws, userInputS);
        if(lowercaseString(userInputS).compare("n/a") == 0) {
          std::cout << '\n';
          printAll(fObject);
          goto bypass;
        }
        else {
          addonsPresent = addonAdder(userInputS, fObject, 0);
        }
        if(fObject.Item::getAddOn(0).getForItem() != "Flashlight") {
          while(true) {
            addonAdder("Placeholder", fObject, 0);
            std::cout << "\nPlease only input addons for Flashlights. Alternatively, type N/A to exit.\n" << std::endl;
            std::getline(std::cin >> std::ws, userInputS);
            addonAdder(userInputS, fObject, 0);
            if(fObject.getAddOn(0).getForItem() == "Flashlight") {
              break;
            }
            else if(lowercaseString(userInputS).compare("n/a") == 0) {
              printAll(fObject);
              goto bypass;
            }
          }
        }


        // same as previous comment
        if(addonsPresent == true) {
          std::cout << "\nIf there is a second addon, what is it's name? If there is not one, then type N/A\n" << std::endl;
          std::cin.clear();
          std::getline(std::cin >> std::ws, userInputS);
          std::cout << '\n';
          // verifies addon is not the same, and if it is then it will proceed to alert the user about it, otherwise it continues.
          
          userInputS = lowercaseString(userInputS);
          
          // if N/A is found, prints the object and the first addon, and returns to the main program.
          
          if(lowercaseString(userInputS).compare("n/a") == 0) {
            effectCalculator(1, fObject, 1);
            printAll(fObject, 1);
            goto bypass;
          }
          
          // verifies that user input for the addon isnt the same as the first addon already entered. if it is, then user can either add a new one, or exit to the main menu.
          while(true) {
            if(lowercaseString(fObject.Item::getAddOn(0).getName()).compare(lowercaseString(userInputS)) == 0) {
              addonAdder("Placeholder", fObject, 1);
              std::cout << "You can't have 2 of the same addon, type a different one or type N/A to exit.\n" << std::endl;
              std::cin.clear();
              std::getline(std::cin >> std::ws, userInputS);
              bool temp = addonAdder(userInputS, fObject, 1);
              if(temp != true) {
                printAll(fObject, 1);
                goto bypass;
              }
              if(lowercaseString(fObject.getAddOn(0).getName()).compare(lowercaseString(userInputS)) != 0) {
                break;
              }
              else if(lowercaseString(userInputS).compare("n/a") == 0) {
                effectCalculator(1, fObject, 1);
                printAll(fObject, 1);
                goto bypass;
              }
            }
            else {
              break;
            }
          }
          addonAdder(userInputS, fObject, 1);
          // checks if the add on is under the name flashlight, and if it isn't then it makes the user either print without a new addon, or enter a new one.
          if(fObject.getAddOn(1).getForItem() != "Flashlight") {
            while(true) {
              addonAdder("Placeholder", fObject, 1);
              std::cout << "Please only input addons for Flashlights. Alternatively, type N/A to exit.\n" << std::endl;
              std::getline(std::cin >> std::ws, userInputS);
              
              bool temp = addonAdder(userInputS, fObject, 1);
              
              if(temp != true) {
                printAll(fObject, 1);
                goto bypass;
              }
              if(fObject.getAddOn(1).getForItem() == "Flashlight") {
                break;
              }
              else if(lowercaseString(userInputS).compare("n/a") == 0) {
                effectCalculator(1, fObject, 1);
                printAll(fObject, 1);
                goto bypass;
              }
            }
          }
        }
        
        // checks if one addon is present, or two, single addon check is for safety and fallback measures
        
        if(addonsPresent == true) {
          if(fObject.getAddOn(1).getName().compare(" ") == 0) {
            effectCalculator(1, fObject, 0);
          }
          else {
            effectCalculator(2, fObject, 0);
          }
        }
        
        // prints flashlight object and both addons, with spaces inbetween each addon and the flashlight itself
        printAll(fObject, 2);
        
        userInputUS = 0;
        std::cout << '\n';
        continue;
      }
      case 2: {
        Map mapObject;
        
        bool addonsPresent = false;
        std::cout << "Which rarity is it?\n\n1 | Rare \n2 | Ultra Rare" << std::endl;
        std::cin >> userInputUS;
        std::cout << '\n';
        userInputVerify(userInputUS);
        // verifies that the number is in bounds for the cases within the flashlight function
        while(true) {
          if(userInputUS < 0 && userInputUS > 2) {
            std::cout << "Please only input either 1 or 2.\n" << std::endl;
            inputReset();
            std::cin >> userInputUS;
          }
          else {
            break;
          }
        }
        
        mapObject.Map::mapTypeSetter(userInputUS);
        // runs the addon check, similar to toolbox one but for maps
        std::cout << "If there is an addon, what is it's name? If there is not one, then type N/A\n" << std::endl;
        std::cin.clear();
        std::getline(std::cin >> std::ws, userInputS);
        if(lowercaseString(userInputS).compare("n/a") == 0) {
          std::cout << '\n';
          printAll(mapObject);
          goto bypass;
        }
        else {
          addonsPresent = addonAdder(userInputS, mapObject, 0);
        }
        if(mapObject.Item::getAddOn(0).getForItem() != "Map") {
          while(true) {
            addonAdder("Placeholder", mapObject, 0);
            std::cout << "\nPlease only input addons for Maps. Alternatively, type N/A to exit.\n" << std::endl;
            std::getline(std::cin >> std::ws, userInputS);
            addonAdder(userInputS, mapObject, 0);
            if(mapObject.getAddOn(0).getForItem() == "Map") {
              break;
            }
            else if(lowercaseString(userInputS).compare("n/a") == 0) {
              std::cout << '\n';
              printAll(mapObject);
              goto bypass;
            }
          }
        }

        if(addonsPresent == true) {
          std::cout << "\nIf there is a second addon, what is it's name? If there is not one, then type N/A\n" << std::endl;
          std::cin.clear();
          std::getline(std::cin >> std::ws, userInputS);
          std::cout << '\n';
          // verifies addon is not the same, and if it is then it will proceed to alert the user about it, otherwise it continues.
          
          userInputS = lowercaseString(userInputS);
          
          // if N/A is found, prints the object and the first addon, and returns to the main program.
          
          if(lowercaseString(userInputS).compare("n/a") == 0) {
            effectCalculator(1, mapObject, 1);
            printAll(mapObject, 1);
            goto bypass;
          }
          
          // verifies that user input for the addon isnt the same as the first addon already entered. if it is, then user can either add a new one, or exit to the main menu.
          while(true) {
            if(lowercaseString(mapObject.Item::getAddOn(0).getName()).compare(lowercaseString(userInputS)) == 0) {
              addonAdder("Placeholder", mapObject, 1);
              std::cout << "You can't have 2 of the same addon, type a different one or type N/A to exit.\n" << std::endl;
              std::cin.clear();
              std::getline(std::cin >> std::ws, userInputS);
              bool temp = addonAdder(userInputS, mapObject, 1);
              if(temp != true) {
                printAll(mapObject, 1);
                goto bypass;
              }
              if(lowercaseString(mapObject.getAddOn(0).getName()).compare(lowercaseString(userInputS)) != 0) {
                break;
              }
              else if(lowercaseString(userInputS).compare("n/a") == 0) {
                effectCalculator(1, mapObject, 1);
                printAll(mapObject, 1);
                goto bypass;
              }
            }
            else {
              break;
            }
          }
          addonAdder(userInputS, mapObject, 1);
          // checks if the add on is under the name map, and if it isn't then it makes the user either print without a new addon, or enter a new one.
          if(mapObject.getAddOn(1).getForItem() != "Map") {
            while(true) {
              addonAdder("Placeholder", mapObject, 1);
              std::cout << "Please only input addons for Maps. Alternatively, type N/A to exit.\n" << std::endl;
              std::getline(std::cin >> std::ws, userInputS);
              
              bool temp = addonAdder(userInputS, mapObject, 1);
              
              if(temp != true) {
                printAll(mapObject, 1);
                goto bypass;
              }
              if(mapObject.getAddOn(1).getForItem() == "Map") {
                break;
              }
              else if(lowercaseString(userInputS).compare("n/a") == 0) {
                effectCalculator(1, mapObject, 1);
                printAll(mapObject, 1);
                goto bypass;
              }
            }
          }
        }
        
        // checks if one addon is present, or two, single addon check is for safety and fallback measures
        
        if(addonsPresent == true) {
          if(mapObject.getAddOn(1).getName().compare(" ") == 0) {
            effectCalculator(1, mapObject, 1);
          }
          else {
            effectCalculator(2, mapObject, 1);
          }
        }
        
        // prints map object and both addons, with spaces inbetween each addon and the map itself
        printAll(mapObject, 2);
        
        userInputUS = 0;
        std::cout << '\n';
        continue;
      }
      case 3: {
        Key kObject;
        
        bool addonsPresent = false;
        std::cout << "Which rarity is it?\n\n1 | Rare \n2 | Very Rare \n3 | Ultra Rare" << std::endl;
        std::cin >> userInputUS;
        std::cout << '\n';
        userInputVerify(userInputUS);
        // verifies that the number is in bounds for the cases within the flashlight function
        while(true) {
          if(userInputUS < 0 && userInputUS > 3) {
            std::cout << "Please only a value ranging between 1 and 3.\n" << std::endl;
            inputReset();
            std::cin >> userInputUS;
          }
          else {
            break;
          }
        }
        
        kObject.Key::keyTypeSetter(userInputUS);
        // runs the addon check, similar to toolbox one but for keys
        std::cout << "If there is an addon, what is it's name? If there is not one, then type N/A\n" << std::endl;
        std::cin.clear();
        std::getline(std::cin >> std::ws, userInputS);
        if(lowercaseString(userInputS).compare("n/a") == 0) {
          std::cout << '\n';
          printAll(kObject);
          goto bypass;
        }
        else {
          addonsPresent = addonAdder(userInputS, kObject, 0);
        }
        if(kObject.Item::getAddOn(0).getForItem() != "Key") {
          while(true) {
            addonAdder("Placeholder", kObject, 0);
            std::cout << "\nPlease only input addons for keys. Alternatively, type N/A to exit.\n" << std::endl;
            std::getline(std::cin >> std::ws, userInputS);
            addonAdder(userInputS, kObject, 0);
            if(kObject.getAddOn(0).getForItem() == "Key") {
              break;
            }
            else if(lowercaseString(userInputS).compare("n/a") == 0) {
              std::cout << '\n';
              printAll(kObject);
              goto bypass;
            }
          }
        }

        if(addonsPresent == true) {
          std::cout << "\nIf there is a second addon, what is it's name? If there is not one, then type N/A\n" << std::endl;
          std::cin.clear();
          std::getline(std::cin >> std::ws, userInputS);
          std::cout << '\n';
          // verifies addon is not the same, and if it is then it will proceed to alert the user about it, otherwise it continues.
          
          userInputS = lowercaseString(userInputS);
          
          // if N/A is found, prints the object and the first addon, and returns to the main program.
          
          if(lowercaseString(userInputS).compare("n/a") == 0) {
            effectCalculator(1, kObject, 1);
            printAll(kObject, 1);
            goto bypass;
          }
          
          // verifies that user input for the addon isnt the same as the first addon already entered. if it is, then user can either add a new one, or exit to the main menu.
          while(true) {
            if(lowercaseString(kObject.Item::getAddOn(0).getName()).compare(lowercaseString(userInputS)) == 0) {
              addonAdder("Placeholder", kObject, 1);
              std::cout << "You can't have 2 of the same addon, type a different one or type N/A to exit.\n" << std::endl;
              std::cin.clear();
              std::getline(std::cin >> std::ws, userInputS);
              bool temp = addonAdder(userInputS, kObject, 1);
              if(temp != true) {
                printAll(kObject, 1);
                goto bypass;
              }
              if(lowercaseString(kObject.getAddOn(0).getName()).compare(lowercaseString(userInputS)) != 0) {
                break;
              }
              else if(lowercaseString(userInputS).compare("n/a") == 0) {
                effectCalculator(1, kObject, 1);
                printAll(kObject, 1);
                goto bypass;
              }
            }
            else {
              break;
            }
          }
          addonAdder(userInputS, kObject, 1);
          // checks if the add on is under the name key, and if it isn't then it makes the user either print without a new addon, or enter a new one.
          if(kObject.getAddOn(1).getForItem() != "Key") {
            while(true) {
              addonAdder("Placeholder", kObject, 1);
              std::cout << "Please only input addons for Keys. Alternatively, type N/A to exit.\n" << std::endl;
              std::getline(std::cin >> std::ws, userInputS);
              
              bool temp = addonAdder(userInputS, kObject, 1);
              
              if(temp != true) {
                printAll(kObject, 1);
                goto bypass;
              }
              if(kObject.getAddOn(1).getForItem() == "Key") {
                break;
              }
              else if(lowercaseString(userInputS).compare("n/a") == 0) {
                effectCalculator(1, kObject, 1);
                printAll(kObject, 1);
                goto bypass;
              }
            }
          }
        }
        
        // checks if one addon is present, or two, single addon check is for safety and fallback measures
        
        if(addonsPresent == true) {
          if(kObject.getAddOn(1).getName().compare(" ") == 0) {
            effectCalculator(1, kObject, 2);
          }
          else {
            effectCalculator(2, kObject, 2);
          }
        }
        
        // prints key object and both addons, with spaces inbetween each addon and the key itself
        printAll(kObject, 2);
        
        userInputUS = 0;
        std::cout << '\n';
        continue;
      }
      case 4: {
        Medkit medkitObject;
        
        bool addonsPresent = false;
        std::cout << "Which rarity is it?\n\n1 | Common \n2 | Uncommon \n3 | Rare \n4 | Very Rare \n5 | Ultra Rare" << std::endl;
        std::cin >> userInputUS;
        std::cout << '\n';
        userInputVerify(userInputUS);
        // verifies that the number is in bounds for the cases within the flashlight function
        while(true) {
          if(userInputUS < 0 && userInputUS > 5) {
            std::cout << "Please only input either 1 or 2.\n" << std::endl;
            inputReset();
            std::cin >> userInputUS;
          }
          else {
            break;
          }
        }
        
        medkitObject.Medkit::medkitTypeSetter(userInputUS);
        // runs the addon check, similar to toolbox one but for medkits
        std::cout << "If there is an addon, what is it's name? If there is not one, then type N/A\n" << std::endl;
        std::cin.clear();
        std::getline(std::cin >> std::ws, userInputS);
        if(lowercaseString(userInputS).compare("n/a") == 0) {
          std::cout << '\n';
          printAll(medkitObject);
          goto bypass;
        }
        else {
          addonsPresent = addonAdder(userInputS, medkitObject, 0);
        }
        if(medkitObject.Item::getAddOn(0).getForItem() != "Medkit") {
          while(true) {
            addonAdder("Placeholder", medkitObject, 0);
            std::cout << "\nPlease only input addons for medkits. Alternatively, type N/A to exit.\n" << std::endl;
            std::getline(std::cin >> std::ws, userInputS);
            addonAdder(userInputS, medkitObject, 0);
            if(medkitObject.getAddOn(0).getForItem() == "Medkit") {
              break;
            }
            else if(lowercaseString(userInputS).compare("n/a") == 0) {
              std::cout << '\n';
              printAll(medkitObject);
              goto bypass;
            }
          }
        }

        if(addonsPresent == true) {
          std::cout << "\nIf there is a second addon, what is it's name? If there is not one, then type N/A\n" << std::endl;
          std::cin.clear();
          std::getline(std::cin >> std::ws, userInputS);
          std::cout << '\n';
          // verifies addon is not the same, and if it is then it will proceed to alert the user about it, otherwise it continues.
          
          userInputS = lowercaseString(userInputS);
          
          // if N/A is found, prints the object and the first addon, and returns to the main program.
          
          if(lowercaseString(userInputS).compare("n/a") == 0) {
            effectCalculator(1, medkitObject, 1);
            printAll(medkitObject, 1);
            goto bypass;
          }
          
          // verifies that user input for the addon isnt the same as the first addon already entered. if it is, then user can either add a new one, or exit to the main menu.
          while(true) {
            if(lowercaseString(medkitObject.Item::getAddOn(0).getName()).compare(lowercaseString(userInputS)) == 0) {
              addonAdder("Placeholder", medkitObject, 1);
              std::cout << "You can't have 2 of the same addon, type a different one or type N/A to exit.\n" << std::endl;
              std::cin.clear();
              std::getline(std::cin >> std::ws, userInputS);
              bool temp = addonAdder(userInputS, medkitObject, 1);
              if(temp != true) {
                printAll(medkitObject, 1);
                goto bypass;
              }
              if(lowercaseString(medkitObject.getAddOn(0).getName()).compare(lowercaseString(userInputS)) != 0) {
                break;
              }
              else if(lowercaseString(userInputS).compare("n/a") == 0) {
                effectCalculator(1, medkitObject, 1);
                printAll(medkitObject, 1);
                goto bypass;
              }
            }
            else {
              break;
            }
          }
          addonAdder(userInputS, medkitObject, 1);
          // checks if the add on is under the name medkit, and if it isn't then it makes the user either print without a new addon, or enter a new one.
          if(medkitObject.getAddOn(1).getForItem() != "Medkit") {
            while(true) {
              addonAdder("Placeholder", medkitObject, 1);
              std::cout << "Please only input addons for Medkits. Alternatively, type N/A to exit.\n" << std::endl;
              std::getline(std::cin >> std::ws, userInputS);
              
              bool temp = addonAdder(userInputS, medkitObject, 1);
              
              if(temp != true) {
                printAll(medkitObject, 1);
                goto bypass;
              }
              if(medkitObject.getAddOn(1).getForItem() == "Medkit") {
                break;
              }
              else if(lowercaseString(userInputS).compare("n/a") == 0) {
                effectCalculator(1, medkitObject, 1);
                printAll(medkitObject, 1);
                goto bypass;
              }
            }
          }
        }
        
        // checks if one addon is present, or two, single addon check is for safety and fallback measures
        
        if(addonsPresent == true) {
          if(medkitObject.getAddOn(1).getName().compare(" ") == 0) {
            effectCalculator(1, medkitObject, 3);
          }
          else {
            effectCalculator(2, medkitObject, 3);
          }
        }
        
        // prints medkit object and both addons, with spaces inbetween each addon and the medkit itself
        printAll(medkitObject, 2);
        
        userInputUS = 0;
        std::cout << '\n';
        continue;
      }
      case 5: {
        Toolbox tObject;
        
        bool addonsPresent = false;
        std::cout << "Which rarity is it?\n\n1 | Rare \n2 | Ultra Rare" << std::endl;
        std::cin >> userInputUS;
        std::cout << '\n';
        userInputVerify(userInputUS);
        // verifies that the number is in bounds for the cases within the flashlight function
        while(true) {
          if(userInputUS < 0 && userInputUS > 2) {
            std::cout << "Please only input either 1 or 2.\n" << std::endl;
            inputReset();
            std::cin >> userInputUS;
          }
          else {
            break;
          }
        }
        
        tObject.Toolbox::toolboxTypeSetter(userInputUS);
        // runs the addon check, similar to toolbox one but for toolboxes
        std::cout << "If there is an addon, what is it's name? If there is not one, then type N/A\n" << std::endl;
        std::cin.clear();
        std::getline(std::cin >> std::ws, userInputS);
        if(lowercaseString(userInputS).compare("n/a") == 0) {
          std::cout << '\n';
          printAll(tObject);
          goto bypass;
        }
        else {
          addonsPresent = addonAdder(userInputS, tObject, 0);
        }
        if(tObject.Item::getAddOn(0).getForItem() != "Toolbox") {
          while(true) {
            addonAdder("Placeholder", tObject, 0);
            std::cout << "\nPlease only input addons for Toolboxes. Alternatively, type N/A to exit.\n" << std::endl;
            std::getline(std::cin >> std::ws, userInputS);
            addonAdder(userInputS, tObject, 0);
            if(tObject.getAddOn(0).getForItem() == "Toolbox") {
              break;
            }
            else if(lowercaseString(userInputS).compare("n/a") == 0) {
              std::cout << '\n';
              printAll(tObject);
              goto bypass;
            }
          }
        }

        if(addonsPresent == true) {
          std::cout << "\nIf there is a second addon, what is it's name? If there is not one, then type N/A\n" << std::endl;
          std::cin.clear();
          std::getline(std::cin >> std::ws, userInputS);
          std::cout << '\n';
          // verifies addon is not the same, and if it is then it will proceed to alert the user about it, otherwise it continues.
          
          userInputS = lowercaseString(userInputS);
          
          // if N/A is found, prints the object and the first addon, and returns to the main program.
          
          if(lowercaseString(userInputS).compare("n/a") == 0) {
            effectCalculator(1, tObject, 1);
            printAll(tObject, 1);
            goto bypass;
          }
          
          // verifies that user input for the addon isnt the same as the first addon already entered. if it is, then user can either add a new one, or exit to the main menu.
          while(true) {
            if(lowercaseString(tObject.Item::getAddOn(0).getName()).compare(lowercaseString(userInputS)) == 0) {
              addonAdder("Placeholder", tObject, 1);
              std::cout << "You can't have 2 of the same addon, type a different one or type N/A to exit.\n" << std::endl;
              std::cin.clear();
              std::getline(std::cin >> std::ws, userInputS);
              bool temp = addonAdder(userInputS, tObject, 1);
              if(temp != true) {
                printAll(tObject, 1);
                goto bypass;
              }
              if(lowercaseString(tObject.getAddOn(0).getName()).compare(lowercaseString(userInputS)) != 0) {
                break;
              }
              else if(lowercaseString(userInputS).compare("n/a") == 0) {
                effectCalculator(1, tObject, 1);
                printAll(tObject, 1);
                goto bypass;
              }
            }
            else {
              break;
            }
          }
          addonAdder(userInputS, tObject, 1);
          // checks if the add on is under the name toolbox, and if it isn't then it makes the user either print without a new addon, or enter a new one.
          if(tObject.getAddOn(1).getForItem() != "Toolbox") {
            while(true) {
              addonAdder("Placeholder", tObject, 1);
              std::cout << "Please only input addons for Toolboxes. Alternatively, type N/A to exit.\n" << std::endl;
              std::getline(std::cin >> std::ws, userInputS);
              
              bool temp = addonAdder(userInputS, tObject, 1);
              
              if(temp != true) {
                printAll(tObject, 1);
                goto bypass;
              }
              if(tObject.getAddOn(1).getForItem() == "Toolbox") {
                break;
              }
              else if(lowercaseString(userInputS).compare("n/a") == 0) {
                effectCalculator(1, tObject, 1);
                printAll(tObject, 1);
                goto bypass;
              }
            }
          }
        }
        
        // checks if one addon is present, or two, single addon check is for safety and fallback measures
        
        if(addonsPresent == true) {
          if(tObject.getAddOn(1).getName().compare(" ") == 0) {
            effectCalculator(1, tObject, 4);
          }
          else {
            effectCalculator(2, tObject, 4);
          }
        }
        
        // prints toolbox object and both addons, with spaces inbetween each addon and the toolbox itself
        printAll(tObject, 2);
        
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
