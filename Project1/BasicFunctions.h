#pragma once
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

// Addon adders
  // Adds an addon with the name under the parameter, to the target object parameter.
  template <typename T>
  bool addonAdder(std::string name, T& addonTarget, unsigned short targetIndex) {
    while(true) {
      std::string tempName = lowercaseString(name);
      
      if(addOnIndexFinder(tempName) != -1 && name != "n/a") {
        O::Addons newAddon;
        newAddon.defineAddon(camelCase(name));
        addonTarget.setAddOn(targetIndex, newAddon);
        return true;
      }
      else if(tempName == "n/a") {
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

  // calculates an addon's effects on the main flashlight
  void effectCalculator(short addonCount, O::Flashlight& target) {
    if(target.getAddOn(0).getName() == "placeholder") {
      return;
    }
    if(target.getAddOn(1).getName() == "placeholder") {
      return;
    }
    std::string temp;
    unsigned short ctr = 0;
    unsigned short idx = 0;
    unsigned short fallback = 0;
    bool cont;

    // iterate through addons
    for(auto &it : target.getAddOns()) {
      // reset counter before going to a new addon
      ctr = 0;
      // iterate through string until break is called
      while(true) {
        fallback++;
        // iterate through effects string
        for(auto &et : it.getEffects()) {
          idx++;
          // check if ctr is larger or equal to size of effectpotency vector, break if true.
          if(ctr >= it.getEffectPotency().size()) {
            break;
          }
          // next 3 if statements are to append to temp str, and to check whether or not it should keep appending to said string.
          if(et != ' ') {
            temp += et;
          }
          else {
            temp = "";
          }
          if(it.getEffects().find(",") != std::string::npos) {
            if(it.getEffects().find(",") < idx) {
              cont == false;
            }
            else {
              cont = true;
            }
          }
          else if(et != ',') {
            cont = false;
          }
          
          temp = lowercaseString(temp);
          // if temp is larger than 2, it will begin checking for effects.
          if(temp.length() > 2) {
            if(temp.substr(1, temp.length()).compare("accuracy") == 0) {
              target.calculateEffects(1, it.getEffectPotency().at(ctr));
              // this is more of a fallback; if ctr + 1 is larger than effect potency's size it will break.
              if(it.getEffectPotency().size() < ctr + 1) {
                break;
              }
              else
              {     
                ctr++;
              }
            }
            else if(temp.substr(1, temp.length()).compare("width") == 0) {
              target.calculateEffects(2, it.getEffectPotency().at(ctr));
              if(it.getEffectPotency().size() < ctr + 1) {
                break;
              }
              else
              {     
                ctr++;
              }
            }
            else if(temp.substr(1, temp.length()).compare("range") == 0) {
              target.calculateEffects(3, it.getEffectPotency().at(ctr));
              if(it.getEffectPotency().size() < ctr + 1) {
                break;
              }
              else
              {     
                ctr++;
              }
            }
            else if(temp.substr(1, temp.length()).compare("use") == 0 || temp.substr(1, temp.length()).compare("depletion") == 0) {
              target.calculateEffects(4, it.getEffectPotency().at(ctr));
              if(it.getEffectPotency().size() < ctr + 1) {
                break;
              }
              else
              {     
                ctr++;
              }
            }
            else if(temp.substr(1, temp.length()).compare("brightness") == 0) {
              target.calculateEffects(5, it.getEffectPotency().at(ctr));
              if(it.getEffectPotency().size() < ctr + 1) {
                return;
              }
              else
              {     
                ctr++;
              }
            }
            else if(temp.substr(1, temp.length()).compare("duration") == 0) {
              target.calculateEffects(6, it.getEffectPotency().at(ctr));
              if(it.getEffectPotency().size() < ctr + 1) {
                return;
              }
              else
              {     
                ctr++;
              }
            }
              // verifies if temp is equal to & to make sure string isnt cluttered
            else if(temp[0] != '&' || et == ' ') {
              temp = "";
              continue;
            }
          }
          // for alternate effects
          if(!it.getEffects().find("accuracy") || !it.getEffects().find("width") || !it.getEffects().find("range") || !it.getEffects().find("use") || !it.getEffects().find("brightness") || !it.getEffects().find("depletion") || !it.getEffects().find("duration")) {
            target.addOtherEffects(temp);
          }                
        }
        // i dont know why i put this here but im leaving it just so i dont break it.
        if(addonCount > target.getAddOns().size()) {
          return;
        }
        if(cont == false) {
          break;
        }
        else if(fallback >= 3) {
          return;
        }
      }
    }
  }
}