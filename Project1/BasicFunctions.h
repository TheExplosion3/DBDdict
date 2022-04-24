#include <iostream>
#include <string.h>
#include <limits>
#include "Addons.h"

namespace F {
  // Resets the input stream
  void inputReset() {
  std::cin.ignore(10000, '\n');
  std::cin.clear();
  }

  // Clears input stream, syncs as well
  void inputResetSync() {
    std::cin.clear();
    std::cin.sync();
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

  std::string camelCase(std::string str) {
    str[0] = toupper(str[0]);
  
    int len = str.length();
    
    for (int i = 0; i < len; i++) {
      if (str[i - 1] == ' ') {
        str[i] = toupper(str[i]);
      }
    }
    return str;
  }

// Addon adders
  // Adds an addon with the name under the parameter, to the target object parameter.
  bool addonAdder(std::string name, O::Flashlight& addonTarget, unsigned short targetIndex) {
    while(true) {
      std::string tempName = lowercaseString(name);
      
      if(addOnIndexFinder(tempName) != -1 && name != "N/A") {
        O::Addons newAddon;
        newAddon.defineAddon(name);
        addonTarget.setAddOn(targetIndex, newAddon);
        return true;
      }
      else if(name == "N/A") {
        return false;
      }
      else {
        std::cout << "Make sure you typed the addon's name correctly, or type N/A to skip this step." << std::endl;
        std::cin.clear();
      }
      std::getline(std::cin, name);
    }
    return false;
  }
  
  void effectCalculator(short addonCount, O::Flashlight& target) {
    std::string temp;
    unsigned short ctr = 0;
    bool cont;
    for(int i = 0; i < addonCount; i++) {
      for(auto &it : target.getAddOns()) {
        while(true) {
          for(auto &et : it.getEffects()) {
            if(et != ' ') {
              temp += et;
            }
            else if(et == ',') {
              cont = true;
            }
            else if(et != ',') {
              cont = false;
            }
            else {
              temp = lowercaseString(temp);
              if(temp.compare("accuracy") == 0) {
                target.calculateEffects(1, it.getEffectPotency().at(ctr));
                ctr++;
              }
              else if(temp.compare("width") == 0) {
                target.calculateEffects(2, it.getEffectPotency().at(ctr));
                ctr++;
              }
              else if(temp.compare("range") == 0) {
                target.calculateEffects(3, it.getEffectPotency().at(ctr));
                ctr++;
              }
              else if(temp.compare("use") == 0) {
                target.calculateEffects(4, it.getEffectPotency().at(ctr));
                ctr++;
              }
              else if(temp.compare("brightness") == 0) {
                target.calculateEffects(5, it.getEffectPotency().at(ctr));
                ctr++;
              }
              else if(temp.compare("duration") == 0) {
                target.calculateEffects(6, it.getEffectPotency().at(ctr));
                ctr++;
              }
                // yes i know this is scuffed shut up
              else if(temp.compare("by") == 0 || temp.compare("increases") == 0 || temp.compare(",") == 0 || temp.compare(" , ") == 0 || temp.compare(" ,") == 0 || temp.compare(", ") == 0 || temp.compare("40%,") == 0 || temp.compare("blindness") == 0) {
                temp = "";
                continue;
              }
              else {
                target.addOtherEffects(temp);
              }
              temp = "";
            }
          }
          
          if(cont == false) {
            break;
          }
        }
      }
    } 
  }
}