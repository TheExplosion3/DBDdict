#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <nlohmann/json.hpp>

// very botched case changer
std::string lowercaseString(std::string str) {
  std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c){return std::tolower(c);});
  return str;
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
      return idx;
    }
    idx++;
  }
  return -1;
}

namespace O
{
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
            void defineAddon(std::string type, std::string name) {   
              std::ifstream i("Project1/AddonList.json");
              nlohmann::json AddonList;
              i >> AddonList;

              // verifies addon is actually in list
              if(!(AddonList.contains(name))) {
                return;
              }
              
              this -> name = AddonList[name]["name"];
              this -> rarity = AddonList[name]["rarity"];
              this -> forItem = AddonList[name]["forItem"];
              this -> effects = AddonList[name]["effects"];
              this -> effectPotency = (std::vector<float>)AddonList[name]["effectPotency"];
            }
    };
}