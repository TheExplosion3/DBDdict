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
  // note: dont even try to read this code it is a certified mess
  void effectCalculator(short addonCount, O::Flashlight& target) {
    if(lowercaseString(target.getAddOn(0).getName()) == "broken bulb") {
      target.O::Item::addOtherEffects("Flashlight flickers, increased spookiness");
    }
    if(lowercaseString(target.getAddOn(1).getName()) == "broken bulb") {
      target.O::Item::addOtherEffects("Flashlight flickers, increased spookiness");
    }
    if(lowercaseString(target.getAddOn(0).getName()) == "placeholder" || lowercaseString(target.getAddOn(1).getName()) == "placeholder") {
      return;
    }
    std::string temp = "";
    unsigned short ctr = 0;
    unsigned short idx = 0;
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
        // checks whether or not to keep appending string, sets string in all lowercase.
        if(et != ' ') {
          temp += et;
        }
        else {
          temp = "";
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
            else {     
              ctr++;
            }
          }
          else if(temp.substr(1, temp.length()).compare("width") == 0) {
            target.calculateEffects(2, it.getEffectPotency().at(ctr));
            if(it.getEffectPotency().size() < ctr + 1) {
              break;
            }
            else {     
              ctr++;
            }
          }
          else if(temp.substr(1, temp.length()).compare("range") == 0) {
            target.calculateEffects(3, it.getEffectPotency().at(ctr));
            if(it.getEffectPotency().size() < ctr + 1) {
              break;
            }
            else {     
              ctr++;
            }
          }
          else if(temp.substr(1, temp.length()).compare("use") == 0 || temp.substr(1, temp.length()).compare("depletion") == 0) {
            target.calculateEffects(4, it.getEffectPotency().at(ctr));
            if(it.getEffectPotency().size() < ctr + 1) {
              break;
            }
            else {     
              ctr++;
            }
          }
          else if(temp.substr(1, temp.length()).compare("brightness") == 0) {
            target.calculateEffects(5, it.getEffectPotency().at(ctr));
            if(it.getEffectPotency().size() < ctr + 1) {
              break;
            }
            else {     
              ctr++;
            }
          }
          else if(temp.substr(1, temp.length()).compare("duration") == 0) {
            target.calculateEffects(6, it.getEffectPotency().at(ctr));
            if(it.getEffectPotency().size() < ctr + 1) {
              break;
            }
            else {     
              ctr++;
            }
          }
          
          // verifies if temp is equal to & to make sure string isnt cluttered
          else if(temp[0] != '&' || et == ' ') {
            temp = "";
            continue;
          }
          // debugging statement below vvvvvvvvvvvvvvv
          // std::cout << et << " | " << ctr << " | " << it.getEffectPotency().size() << " | " << temp << std::endl;
        }
      }  
    }
  }

  // for Toolboxes
  void effectCalculator(short addonCounter, O::Toolbox& target) {
    if(lowercaseString(target.getAddOn(0).getName()) == "brand new part") {
      target.O::Item::addOtherEffects("Brand New Part: Takes 5 seconds to install, adds 15% to generator progression. Triggers 2 difficult skillchecks during installation process, successful completion adds 5% extra progression up to a total of 25% progression");
    }
    if(lowercaseString(target.getAddOn(1).getName()) == "brand new part") {
      target.O::Item::addOtherEffects("Brand New Part: Takes 5 seconds to install, adds 15% to generator progression. Triggers 2 difficult skillchecks during installation process, successful completion adds 5% extra progression up to a total of 25% progression");      
    }
    if(lowercaseString(target.getAddOn(0).getName()) == "instructtions" || lowercaseString(target.getAddOn(1).getName()) == "instructions") {
      target.O::Item::addOtherEffects("No normal Skill Checks are present.");
    }
    if(target.getAddOn(0).getName() == "placeholder" || target.getAddOn(1).getName() == "placeholder") {
      return;
    }
    std::string temp = "";
    unsigned short ctr = 0;
    unsigned short idx = 0;

    // iterate through addons
    for(auto &it : target.getAddOns()) {
      // reset counter before going to a new addon
      ctr = 0;
      // iterate through effects string
      for(auto &et : it.getEffects()) {
        idx++;

        if(ctr >= it.getEffectPotency().size()) {
          break;
        }
        if(et != ' ') {
          temp += et;
        }
        else {
          temp = "";
        }
        temp = lowercaseString(temp);

        // if temp is larger than 2, it will begin checking for effects.
        if(temp.length() > 2) {
          if(temp.substr(1, temp.length()).compare("charges") == 0 || temp.substr(1, temp.length()).compare("use") == 0) {
            target.calculateEffects(1, it.getEffectPotency().at(ctr));
            if(it.getEffectPotency().size() < ctr + 1) {
              break;
            }
            else {     
              ctr++;
            }
          }
          else if(temp.substr(1, temp.length()).compare("speed") == 0) {
            target.calculateEffects(2, it.getEffectPotency().at(ctr));
            // this is more of a fallback; if ctr + 1 is larger than effect potency's size it will break.
            if(it.getEffectPotency().size() < ctr + 1) {
              break;
            }
            else {     
              ctr++;
            }
          }
          else if(temp.substr(1, temp.length()).compare("sabotage") == 0) {
            target.calculateEffects(3, it.getEffectPotency().at(ctr));
            if(it.getEffectPotency().size() < ctr + 1) {
              break;
            }
            else {     
              ctr++;
            }
          }
          else if(temp.substr(1, temp.length()).compare("timer") == 0) {
            target.calculateEffects(4, it.getEffectPotency().at(ctr));
            if(it.getEffectPotency().size() < ctr + 1) {
              break;
            }
            else {     
              ctr++;
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
  template <typename T>
  const void printAll(T& inputObject) {
    std::cout << '\n' << std::endl;
    inputObject.T::printObj();
  }
}