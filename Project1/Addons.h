#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <nlohmann/json.hpp>



// finds the index of an addon, by iterating through an array;
short addOnIndexFinder(std::string name) {
  nlohmann::json AddonList;
  unsigned short idx;
  for(auto& it : AddonList) {
    idx = 0;
    for(auto& et : it) {
      if(name == et["name"]) {
        return idx;
      }
      idx++;
    }
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
              unsigned short itemType;  
              // determines which type it is for the switch case
              if(type == "flashlight") {
                itemType = 1;
              }
              else if(type == "medkit") {
                itemType = 2;
              }
              else if(type == "key") {
                itemType = 3;
              }
              else if(type == "map") {
                itemType = 4;
              }
              else if(type == "toolbox"){
                itemType = 5;
              }
              // verifies that the item is actually present
              nlohmann::json AddonList;
              type += " addons";
              if(!(AddonList[type].contains(name))) {
                return;
              }
            
              // actual addon definition
              switch(itemType) {
                case 1: {
                  this -> name = AddonList["flashlight addons"]["name"];
                  this -> rarity = AddonList["flashlight addons"]["rarity"];
                  this -> forItem = AddonList["flashlight addons"]["forItem"];
                  this -> effects = AddonList["flashlight addons"]["effects"];
                  this -> effectPotency = jsonConverter(AddonList["flashlight addons"]["effectPotency"]);
                  break;
                }
                case 2: {
                  this -> name = AddonList["medkit addons"]["name"];
                  this -> rarity = AddonList["medkit addons"]["rarity"];
                  this -> forItem = AddonList["medkit addons"]["forItem"];
                  this -> effects = AddonList["medkit addons"]["effects"];
                  this -> effectPotency = jsonConverter(AddonList["medkit addons"]["effectPotency"]);
                  break;
                }
                case 3: {
                  this -> name = AddonList["key addons"]["name"];
                  this -> rarity = AddonList["key addons"]["rarity"];
                  this -> forItem = AddonList["key addons"]["forItem"];
                  this -> effects = AddonList["key addons"]["effects"];
                  this -> effectPotency = jsonConverter(AddonList["key addons"]["effectPotency"]);
                  break;
                }
                case 4: {
                  this -> name = AddonList["map addons"]["name"];
                  this -> rarity = AddonList["map addons"]["rarity"];
                  this -> forItem = AddonList["map addons"]["forItem"];
                  this -> effects = AddonList["map addons"]["effects"];
                  this -> effectPotency = jsonConverter(AddonList["map addons"]["effectPotency"]);
                  break;
                }
                case 5: {
                  this -> name = AddonList["map addons"]["name"];
                  this -> rarity = AddonList["map addons"]["rarity"];
                  this -> forItem = AddonList["map addons"]["forItem"];
                  this -> effects = AddonList["map addons"]["effects"];
                  this -> effectPotency = jsonConverter(AddonList["map addons"]["effectPotency"]);
                  break;
                }
              }
            }
    };
}