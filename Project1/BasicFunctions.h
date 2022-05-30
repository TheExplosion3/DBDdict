#pragma once
#include <iostream>
#include <string.h>
#include <limits>
#include "Item.h"
#include "Addons.h"
#include "Flashlight.h"
#include "Key.h"
#include "Map.h"
#include "Medkit.h"
#include "Toolbox.h"

using namespace O;

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

// Addon adders
  // Adds an addon with the name under the parameter, to the target object parameter.
  template <typename T>
  bool addonAdder(std::string name, T& addonTarget, unsigned short targetIndex) {
    while(true) {
      std::string tempName = lowercaseString(name);
      
      if(addOnIndexFinder(tempName) != -1 && name != "n/a") {
        Addons newAddon;
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
  
  /* calculates an addon's effects on the main flashlight
     note: dont even try to read this code it is a certified mess
     note 2: its worse i added switch statements so this can be 1 function without overloads becuase im lazy haha this is way too overcomplicated for my own good haha haha im funny and good at programming hahahaha
  */
  template <typename T>
  void effectCalculator(short addonCount, T& target, short switcher) {
    if(target.getAddOn(0).getName() == "placeholder" || target.getAddOn(1).getName() == "placeholder") {
      return;
    }
    
    std::string temp = "";
    unsigned short ctr = 0;
    unsigned short idx = 0;
    bool switchBreak = false;

    // iterate through addons
    for(auto &it : target.getAddOns()) {
      // reset counter before going to a new addon
      ctr = 0;
      // iterate through effects string
      for(auto &et : it.getEffects()) {
        idx++;
        // check if ctr is larger or equal to size of effectpotency vector, break if true.
        if(ctr >= it.getEffectPotency().size()) {
          break;
        }
        if(lowercaseString(target.getAddOn(1).getName()) == "broken bulb") {
          target.Item::addOtherEffects("Flashlight flickers, increased spookiness");
        }
      }
      case 1: {
        
      }
      case 2: {
        
      }
      case 3: {
        
      }
      case 4: {
        // same as the comment in case 0 lol
        if(lowercaseString(target.getAddOn(0).getName()) == "brand new part") {
          target.Item::addOtherEffects("Brand New Part: Takes 5 seconds to install, adds 15% to generator progression. Triggers 2 difficult skillchecks during installation process, successful completion adds 5% extra progression up to a total of 25% progression");
        }
        if(lowercaseString(target.getAddOn(1).getName()) == "brand new part") {
          target.Item::addOtherEffects("Brand New Part: Takes 5 seconds to install, adds 15% to generator progression. Triggers 2 difficult skillchecks during installation process, successful completion adds 5% extra progression up to a total of 25% progression"); 
        }
        if(lowercaseString(target.getAddOn(0).getName()) == "instructtions" || lowercaseString(target.getAddOn(1).getName()) == "instructions") {
          target.Item::addOtherEffects("No normal Skill Checks are present.");
        }
      }
        
      temp = lowercaseString(temp);
      // the way this is supposed to work is to swap over each type of item, depending on what it is identified as in the method definition.
      if(temp.length() > 2) {
        switch(switcher) {
          case 0: {
            if(temp.substr(1, temp.length()).compare("accuracy") == 0) {
              target.calculateEffects(1, it.getEffectPotency().at(ctr));
              // this is more of a fallback; if ctr + 1 is larger than effect potency's size it will break.
              if(it.getEffectPotency().size() < ctr + 1) {
                switchBreak = true;
                break;
              }
              else {     
                ctr++;
                break;
              }
            }
            else if(temp.substr(1, temp.length()).compare("width") == 0) {
              target.calculateEffects(2, it.getEffectPotency().at(ctr));
              if(it.getEffectPotency().size() < ctr + 1) {
                switchBreak = true;
                break;
              }
              else {     
                ctr++;
                break;
              }
            }
            else if(temp.substr(1, temp.length()).compare("range") == 0) {
              target.calculateEffects(3, it.getEffectPotency().at(ctr));
              if(it.getEffectPotency().size() < ctr + 1) {
                switchBreak = true;
                break;
              }
              else {     
                ctr++;
                break;
              }
            }
            else if(temp.substr(1, temp.length()).compare("use") == 0 || temp.substr(1, temp.length()).compare("depletion") == 0) {
              target.calculateEffects(4, it.getEffectPotency().at(ctr));
              if(it.getEffectPotency().size() < ctr + 1) {
                switchBreak = true;
                break;
              }
              else {     
                ctr++;
                break;
              }
            }
            else if(temp.substr(1, temp.length()).compare("brightness") == 0) {
              target.calculateEffects(5, it.getEffectPotency().at(ctr));
              if(it.getEffectPotency().size() < ctr + 1) {
                switchBreak = true;
                break;
              }
              else {     
                ctr++;
                break;
              }
            }
            else if(temp.substr(1, temp.length()).compare("duration") == 0) {
              target.calculateEffects(6, it.getEffectPotency().at(ctr));
              if(it.getEffectPotency().size() < ctr + 1) {
                switchBreak = true;
                break;
              }
              else {     
                ctr++;
                break;
              }
            }
            
            // verifies if temp is equal to & to make sure string isnt cluttered
            else if(temp[0] != '&' || et == ' ') {
              temp = "";
              continue;
            }
          }
            // debugging statement below vvvvvvvvvvvvvvv
            // std::cout << et << " | " << ctr << " | " << it.getEffectPotency().size() << " | " << temp << std::endl;
          case 1: {
            
          }
          case 2: {
    
          }
          case 3: {
            
          }
          case 4: {
            if(temp.substr(1, temp.length()).compare("charges") == 0 || temp.substr(1, temp.length()).compare("use") == 0) {
              target.calculateEffects(1, it.getEffectPotency().at(ctr));
              if(it.getEffectPotency().size() < ctr + 1) {
                switchBreak = true;
                break;
              }
              else {     
                ctr++;
                break;
              }
            }
            else if(temp.substr(1, temp.length()).compare("speed") == 0) {
              target.calculateEffects(2, it.getEffectPotency().at(ctr));
              // this is more of a fallback; if ctr + 1 is larger than effect potency's size it will break.
              if(it.getEffectPotency().size() < ctr + 1) {
                switchBreak = true;
                break;
              }
              else {     
                ctr++;
                break;
              }
            }
            else if(temp.substr(1, temp.length()).compare("sabotage") == 0) {
              target.calculateEffects(3, it.getEffectPotency().at(ctr));
              if(it.getEffectPotency().size() < ctr + 1) {
                switchBreak = true;
                break;
              }
              else {     
                ctr++;
                break;
              }
            }
            else if(temp.substr(1, temp.length()).compare("timer") == 0) {
              target.calculateEffects(4, it.getEffectPotency().at(ctr));
              if(it.getEffectPotency().size() < ctr + 1) {
                switchBreak = true;
                break;
              }
              else {     
                ctr++;
                break;
              }
            }
            
            // verifies if temp is equal to & to make sure string isnt cluttered
            else if(temp[0] != '&' || et == ' ') {
              temp = "";
              continue;
            }
          }
        }
      }
      if(switchBreak == true) {
        switchBreak = false;
        break;
      }
    }
  }

  // prints both addons and prinary object
  template <typename T>
  const void printAll(T& inputObject, unsigned short addonCount) {
    std::cout << '\n' << std::endl;
    effectCalculator(addonCount, inputObject);
    
    inputObject.T::printObj();
    
    if(addonCount > 0) {
      inputObject.T::printA(0);
      if(addonCount == 2) {
        inputObject.T::printA(1);
      }
    }
  }

  // overload for printing only the object, no addon objects. (yeah it makes the name misleading but idrc tbh.)
  template <typename T>
  const void printAll(T& inputObject) {
    std::cout << '\n' << std::endl;
    inputObject.T::printObj();
  }
}