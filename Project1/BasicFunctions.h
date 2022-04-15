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
  bool addonAdder(std::string name, O::Flashlight& addonTarget) {
    while(true) {
      if(!(addOnIndexFinder(name) == -1 && name == "N/A")) {
        O::Addons newAddon;
        newAddon.defineAddon("flashlight", name);
        addonTarget.setAddOn(0, newAddon);
        return true;
      }
      else if(name == "N/A") {
        return false;
        break;
      }
      else {
        std::cout << "Make sure you typed the addon's name correctly, or type N/A to skip this step." << '\n';
        inputResetSync();
        std::getline(std::cin , name);
      }
    }
    return false;
  }
}