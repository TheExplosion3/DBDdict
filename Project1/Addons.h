#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <nlohmann/json.hpp>



// finds the index of an addon, by iterating through an array;
short addOnIndexFinder(std::string name) {
  std::ifstream i("Project1/AddonList.json");
  nlohmann::json AddonList;
  i >> AddonList;
  unsigned short idx;
  std::string temp;
  for(auto& it : AddonList.items()) {
    temp = it.key();
    
    std::transform(temp.begin(), temp.end(), temp.begin(),
    [](unsigned char c){ return std::tolower(c); });
    
    if(name.compare(temp) == 0) {
      return idx;
    }
    idx++;
  }
  return -1;
}

// converts json arrays into c++ vectors
const std::vector<float> jsonConverter(nlohmann::json& j) {
  const std::vector<float> returnVar;
  return returnVar;
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
            
              this -> name = AddonList["name"];
              this -> rarity = AddonList["rarity"];
              this -> forItem = AddonList["forItem"];
              this -> effects = AddonList["effects"];
              this -> effectPotency = jsonConverter(AddonList["effectPotency"]);
            }
    };
}