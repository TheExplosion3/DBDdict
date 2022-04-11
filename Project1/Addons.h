#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <nlohmann/json.hpp>

const unsigned short hash(const std::string s) {
  std::size_t h1 = std::hash<std::string>{}(s);
  return h1;
}

// finds the index of an addon, by iterating through an array;
unsigned short addonIndexFinder(std::string name) {
  unsigned short ctr = 0;
  nlohmann::json aL;
  for(const auto& item : aL.items()) {
    ctr = 0;
    for(auto it = item.begin(); it = item.end(); it++) {
      if(name == item.at(it))
      {
        return ctr;
      }
      ctr++;
    }
  delete aL;
  }
}

// converts json arrays into c++ vectors
const std::vector<float> jsonConverter(nlohmann::json& j, unsigned short loc) {
  const std::vector<float> returnVar;
  for (auto it = j.at(4).begin(); it = j.at(4).end(); it++) {
    returnVar.push_back(it);
  }
  return returnVar;
}

namespace N
{
    class Addons {

        private:
            std::string name;
            std::string rarity;
            std::string forItem;
            std::string effects;
            std::vector<float> effectPotency;
        public:
            nlohmann::json AddonList;
            
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
// constructor based upon the JSON file, instead of directly defining the addons
            Addons(std::string name, unsigned short forItem)
            {
              nlohmann::json AddonList;
              addonIndex = addonIndexFinder(name);
                
              this -> name = name;
              switch(forItem) {
                case 1: {
                  this -> rarity = AddonList.at(0).at(addonIndex).at(1);
                  this -> forItem = AddonList.at(0).at(addonIndex).at(2);
                  this -> effects = AddonList.at(0).at(addonIndex).at(3);
                  this -> effectPotency = jsonConverter(AddonList.at(0).at(addonIndex).at(4));
                  break;
                }
                case 2: {
                  this -> rarity = AddonList.at(1).at(addonIndex).at(1);
                  this -> forItem = AddonList.at(1).at(addonIndex).at(2);
                  this -> effects = AddonList.at(1).at(addonIndex).at(3);
                  this -> effectPotency = jsonConverter(AddonList.at(1).at(addonIndex).at(4));
                  break;
                }
                case 3: {
                  this -> rarity = AddonList.at(2).at(addonIndex).at(1);
                  this -> forItem = AddonList.at(2).at(addonIndex).at(2);
                  this -> effects = AddonList.at(2).at(addonIndex).at(3);
                  this -> effectPotency = jsonConverter(AddonList.at(2).at(addonIndex).at(4));
                  break;
                }
                case 4: {
                  this -> rarity = AddonList.at(3).at(addonIndex).at(1);
                  this -> forItem = AddonList.at(3).at(addonIndex).at(2);
                  this -> effects = AddonList.at(3).at(addonIndex).at(3);
                  this -> effectPotency = jsonConverter(AddonList.at(3).at(addonIndex).at(4));
                  break;
                }
                case 5: {
                  this -> rarity = AddonList.at(4).at(addonIndex).at(1);
                  this -> forItem = AddonList.at(4).at(addonIndex).at(2);
                  this -> effects = AddonList.at(4).at(addonIndex).at(3);
                  this -> effectPotency = jsonConverter(AddonList.at(4).at(addonIndex).at(4));
                  break;
                }
                default: {
                  break;
                }
              }
              AddonList.close();
            }
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
            void defineAddon(unsigned short itemType, std::string name)
            {
              nlohmann::json addonList;
              bool vAddonListidity = false;

              for(const auto& item : AddonList.items()) {
                for(const auto& addonItem : item.items()) {
                  if(item == name) {
                  vAddonListidity = true;
                  break;
                  }
                }
              }
              if(vAddonListidity = false) {
                return;
              }
              
              switch(itemType) {
                case 1: {
                  this -> name = AddonList["flashlight addons"][name]["name"];
                  this -> rarity = AddonList["flashlight addons"][name]["rarity"];
                  this -> forItem = AddonList["flashlight addons"][name]["forItem"];
                  this -> effects = AddonList["flashlight addons"][name]["effects"];
                  this -> effectPotency = AddonList["flashlight addons"][name]["effectPotency"];
                  break;
                }
                case 2: {
                  this -> name = AddonList["key addons"][name]["name"];
                  this -> rarity = AddonList["key addons"][name]["rarity"];
                  this -> forItem = AddonList["key addons"][name]["forItem"];
                  this -> effects = AddonList["key addons"][name]["effects"];
                  this -> effectPotency = AddonList["key addons"][name]["effectPotency"];
                  break;
                }
                case 3: {
                  this -> name = AddonList["map addons"][name]["name"];
                  this -> rarity = AddonList["map addons"][name]["rarity"];
                  this -> forItem = AddonList["map addons"][name]["forItem"];
                  this -> effects = AddonList["map addons"][name]["effects"];
                  this -> effectPotency = AddonList["map addons"][name]["effectPotency"];
                  break;
                }
                case 4: {
                  this -> name = AddonList["medkit addons"][name]["name"];
                  this -> rarity = AddonList["medkit addons"][name]["rarity"];
                  this -> forItem = AddonList["medkit addons"][name]["forItem"];
                  this -> effects = AddonList["medkit addons"][name]["effects"];
                  this -> effectPotency = AddonList["medkit addons"][name]["effectPotency"];
                  break;
                }
                case 5: {
                  this -> name = AddonList["toolbox addons"][name]["name"];
                  this -> rarity = AddonList["toolbox addons"][name]["rarity"];
                  this -> forItem = AddonList["toolbox addons"][name]["forItem"];
                  this -> effects = AddonList["toolbox addons"][name]["effects"];
                  this -> effectPotency = AddonList["toolbox addons"][name]["effectPotency"];
                  break;
                }
                default: {
                  break;
                }
              }
              delete addonList;
            }
    };
}