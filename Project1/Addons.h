#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <nlohmann/json.hpp>

// yes, these methods should be in basicfunctions, but they are needed there and here, so to prevent circular imports i have placed them here.

// very botched case changer
std::string lowercaseString(std::string str) {
  std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c){return std::tolower(c);});
  return str;
}

std::string camelCase(std::string str) {
  str[0] = toupper(str[0]);

  int len = str.length();
  
  for (int i = 0; i < len; i++) { 
    if (str[i + 1] == ' ') {
      str[i + 2] = toupper(str[i + 2]);
      if(i + 1 >= len) {
        break;
      }
      else {
        i += 2;
      }
    }
    else if (isupper(str[i]) > 0 && i > 0 && str[i - 1] != ' ') {
      str[i] = tolower(str[i]);
    }
  }
  return str;
}

// prints out vectors, separated by spaces
std::string vectorPrinter(std::vector<std::string> vec) {
  unsigned short ctr = 0;
  std::string returnVal = "";
  for(std::string str : vec) {
    if(ctr == vec.size() - 1) {
      returnVal += str + '\n';
    }
    else {
      returnVal += str + ", ";
    }
    ctr++;
  }
  return returnVal;
}
std::string vectorPrinter(std::vector<float> vec) {
  unsigned short ctr = 0;
  std::string returnVal = "";
  for(float f : vec) {
    if(ctr == vec.size() - 1) {
      returnVal += f + '\n';
    }
    else {
      returnVal += std::to_string(f) + ", ";
    }
    ctr++;
  }
  return returnVal;
}

// finds the index of an addon, by iterating through an array. binary search is overrated (even though i probably should be using it)
short addOnIndexFinder(std::string name) {
  std::ifstream i("Project1/AddonList.json");
  nlohmann::json AddonList;
  i >> AddonList;

  unsigned short idx;
  std::string temp;

  for(auto& it : AddonList.items()) {
    temp = lowercaseString(it.key());
    if(name.compare(temp) == 0) {
      i.close();
      return idx;
    }
    idx++;
  }
  i.close();
  return -1;
}

namespace O {
    class Addons {

        protected:
            std::string name;
            std::string rarity;
            std::string forItem;
            std::string effects;
            std::vector<float> effectPotency;
        public:
            
// base constructor
            Addons() {
                name = "";
                rarity = "";
                forItem = "";
                effects = "";
                effectPotency = {0};
            }
// controlled param constructor
            Addons(std::string name, std::string rarity, std::string forItem, std::string effects, std::vector<float> effectPotency) {
                this -> name = name;
                this -> rarity = rarity;
                this -> forItem = forItem;
                this -> effects = effects;
                this -> effectPotency = effectPotency;
            }
// copy constructor
            Addons(const O::Addons& other) {
              this -> name = other.getName();
              this -> rarity = other.getRarity();
              this -> forItem = other.getForItem();
              this -> effects = other.getEffects();
              this -> effectPotency = other.getEffectPotency();
            }
              
            void setName(std::string name) {
              this -> name = name;
            }
            std::string getName() const {
              return name;
            }
            void setRarity(std::string rarity) {
              this -> rarity = rarity;
            }
            std::string getRarity() const {
              return rarity;
            }
            void setEffects(std::string effects) {
              this -> effects = effects;
            }
            std::string getEffects() const {
              return effects;
            }
            void setForItem(std::string forItem) {
              this -> forItem = forItem;
            }
            std::string getForItem() const {
              return forItem;
            }
            void setEffectPotency(std::vector<float> effectPotency) {
              this -> effectPotency = effectPotency;
            }
            std::vector<float> getEffectPotency() const {
              return effectPotency;
            }

            // defines addon via method, reassigning mainly the default constructor as that is the primary one.
            void defineAddon(std::string name) {  
              std::ifstream i("Project1/AddonList.json");
              nlohmann::json AddonList;
              i >> AddonList;
              // verifies addon is actually in list
              if(AddonList.contains(camelCase(name))) {
                this -> name = AddonList[name]["name"];
                this -> rarity = AddonList[name]["rarity"];
                this -> forItem = AddonList[name]["forItem"];
                this -> effects = AddonList[name]["effects"];
                this -> effectPotency = AddonList[name]["effectPotency"].get<std::vector<float>>();
                i.close();
              }
              else {
                i.close();
                return;
              }
            }
    };
}