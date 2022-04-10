#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <niohmann/json.hpp>

const unsigned short hash(const std::string s) {
  std::size_t h1 = std::hash<std::string>{}(s);
  return h1;
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
            // lists of all addons available, used primarily by the defineAddon method
            
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
              std::ifstream AddonList_file("AddonList.json", std::ifstream::binary);
              AddonList >> aL;
                
              this -> name = name;
              switch(forItem) {
                case 1: {
                  this -> rarity = aL["flashlight addons"][name]["rarity"];
                  this -> forItem = aL["flashlight addons"][name]["forItem"];
                  this -> effects = aL["flashlight addons"][name]["effects"];
                  this -> effectPotency = aL["flashlight addons"][name]["effectPotency"];
                  break;
                }
                case 2: {
                  this -> rarity = aL["medkit addons"][name]["rarity"];
                  this -> forItem = aL["medkit addons"][name]["forItem"];
                  this -> effects = aL["medkit addons"][name]["effects"];
                  this -> effectPotency = aL["medkit addons"][name]["effectPotency"];
                  break;
                }
                case 3: {
                  this -> rarity = aL["key addons"][name]["rarity"];
                  this -> forItem = aL["key addons"][name]["forItem"];
                  this -> effects = aL["key addons"][name]["effects"];
                  this -> effectPotency = aL["key addons"][name]["effectPotency"];
                  break;
                }
                case 4: {
                  this -> rarity = aL["map addons"][name]["rarity"];
                  this -> forItem = aL["map addons"][name]["forItem"];
                  this -> effects = aL["map addons"][name]["effects"];
                  this -> effectPotency = aL["map addons"][name]["effectPotency"];
                  break;
                }
                case 5: {
                  this -> rarity = aL["toolbox addons"][name]["rarity"];
                  this -> forItem = aL["toolbox addons"][name]["forItem"];
                  this -> effects = aL["toolbox addons"][name]["effects"];
                  this -> effectPotency = aL["toolbox addons"][name]["effectPotency"];
                  break;
                }
                default: {
                  break;
                }
              }
              aL.close();
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
              bool validity = false;
              std::ifstream AddonList_file("AddonList.json", std::ifstream::binary);
              AddonList >> aL;

              for(const auto& item : aL.items()) {
                for(const auto& addonItem : item.items()) {
                  if(item == name) {
                  validity = true;
                  break;
                  }
                }
              }
              if(validity = false) {
                return;
              }
              
              switch(itemType) {
                case 1: {
                  this -> name = aL["flashlight addons"][name]["name"];
                  this -> rarity = aL["flashlight addons"][name]["rarity"];
                  this -> forItem = aL["flashlight addons"][name]["forItem"];
                  this -> effects = aL["flashlight addons"][name]["effects"];
                  this -> effectPotency = aL["flashlight addons"][name]["effectPotency"];
                  break;
                }
                case 2: {
                  this -> name = aL["key addons"][name]["name"];
                  this -> rarity = aL["key addons"][name]["rarity"];
                  this -> forItem = aL["key addons"][name]["forItem"];
                  this -> effects = aL["key addons"][name]["effects"];
                  this -> effectPotency = aL["key addons"][name]["effectPotency"];
                  break;
                }
                case 3: {
                  this -> name = aL["map addons"][name]["name"];
                  this -> rarity = aL["map addons"][name]["rarity"];
                  this -> forItem = aL["map addons"][name]["forItem"];
                  this -> effects = aL["map addons"][name]["effects"];
                  this -> effectPotency = aL["map addons"][name]["effectPotency"];
                  break;
                }
                case 4: {
                  this -> name = aL["medkit addons"][name]["name"];
                  this -> rarity = aL["medkit addons"][name]["rarity"];
                  this -> forItem = aL["medkit addons"][name]["forItem"];
                  this -> effects = aL["medkit addons"][name]["effects"];
                  this -> effectPotency = aL["medkit addons"][name]["effectPotency"];
                  break;
                }
                case 5: {
                  this -> name = aL["toolbox addons"][name]["name"];
                  this -> rarity = aL["toolbox addons"][name]["rarity"];
                  this -> forItem = aL["toolbox addons"][name]["forItem"];
                  this -> effects = aL["toolbox addons"][name]["effects"];
                  this -> effectPotency = aL["toolbox addons"][name]["effectPotency"];
                  break;
                }
                default: {
                  break;
                }
              }
              aL.close();
            }
    };
}