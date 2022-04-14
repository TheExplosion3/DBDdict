#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <nlohmann/json.hpp>

// finds the index of an addon, by iterating through an array;
unsigned short addOnIndexFinder(std::string name) {
  return 0;
}

// converts json arrays into c++ vectors
const std::vector<float> jsonConverter(nlohmann::json& j, unsigned short loc) {
  const std::vector<float> returnVar;
  return returnVar;
}

namespace N
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
            Addons()
            {
                name = "";
                rarity = "";
                forItem = "";
                effects = "";
                effectPotency = {0};
            }
// controlled param constructor
            Addons(std::string name, std::string rarity, std::string forItem, std::string effects, std::vector<float> effectPotency)
            {
                this -> name = name;
                this -> rarity = rarity;
                this -> forItem = forItem;
                this -> effects = effects;
                this -> effectPotency = effectPotency;
            }
// copy constructor
            Addons(const N::Addons& other) {
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
            void defineAddon(unsigned short itemType, std::string name) {
              unsigned short idx = 0;  
              nlohmann::json addonList;
              
              if(!(addonList.at(itemType - 1).contains(name))) {
                return;
              }

              for(auto it = addonList.begin(); it != addonList.end(); ++it) {
                for(auto et = it.value().begin(); et != it.value().end(); ++et) {
                  if(name == et.key()) {
                    break;
                  }
                  idx++;
                }
              }
            
              
              switch(itemType) {
                case 1: {
                  this -> name = addonList.at(0).at(idx);
                  this -> rarity = addonList.at(0).at(idx);
                  this -> forItem = addonList.at(0).at(idx);
                  this -> effects = addonList.at(0).at(idx);
                  this -> effectPotency = addonList.at(0).at(idx).get<std::vector<float>>();
                  break;
                }
                case 2: {
                  this -> name = addonList.at(1).at(idx);
                  this -> rarity = addonList.at(1).at(idx);
                  this -> forItem = addonList.at(1).at(idx);
                  this -> effects = addonList.at(1).at(idx);
                  this -> effectPotency = addonList.at(0).at(idx).get<std::vector<float>>();
                  break;
                }
                case 3: {
                  this -> name = addonList.at(2).at(idx);
                  this -> rarity = addonList.at(2).at(idx);
                  this -> forItem = addonList.at(2).at(idx);
                  this -> effects = addonList.at(2).at(idx);
                  this -> effectPotency = addonList.at(0).at(idx).get<std::vector<float>>();
                  break;
                }
                case 4: {
                  this -> name = addonList.at(3).at(idx);
                  this -> rarity = addonList.at(3).at(idx);
                  this -> forItem = addonList.at(3).at(idx);
                  this -> effects = addonList.at(3).at(idx);
                  this -> effectPotency = addonList.at(0).at(idx).get<std::vector<float>>();
                  break;
                }
                case 5: {
                  this -> name = addonList.at(4).at(idx);
                  this -> rarity = addonList.at(4).at(idx);
                  this -> forItem = addonList.at(4).at(idx);
                  this -> effects = addonList.at(4).at(idx);
                  this -> effectPotency = addonList.at(0).at(idx).get<std::vector<float>>();
                  break;
                }
                default: {
                  break;
                }
              }
            }
    };
}