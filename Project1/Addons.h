#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <json.h>

const unsigned short hash(const std::string s) {
  std::size_t h1 = std::hash<std::string>{}(s);
  return h1;
}

namespace N
{
    class Addons
    {
        private:
            std::string name;
            std::string rarity;
            std::string forItem;
            std::string effects;
            std::vector<float> effectPotency;
            unsigned short totalOfEffects;
        public:
            // lists of all addons available, used primarily by the defineAddon method
            
    
            Addons()
            {
                name = "";
                rarity = "";
                forItem = "";
                effects = "";
                effectPotency = {0};
                totalOfEffects = 0;
            }
            Addons(std::string name, std::string rarity, std::string forItem, std::string effects, std::vector<float> effectPotency)
            {
                this -> name = name;
                this -> rarity = rarity;
                this -> forItem = forItem;
                this -> effects = effects;
                this -> effectPotency = effectPotency;
                for(int i = 0; i < effects.length(); i++)
                {
                    if(effects[i] == ',')
                    {
                        totalOfEffects++;
                    }
                }
                totalOfEffects++;
            }
            Addons(const N::Addons& other) {
              this -> name = other.getName();
              this -> rarity = other.getRarity();
              this -> forItem = other.getForItem();
              this -> effects = other.getEffects();
              this -> effectPotency = other.getEffectPotency();
              this -> totalOfEffects = other.getTotalOfEffects();
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
            void setTotalOfEffects(unsigned short totalOfEffects) {
              this -> totalOfEffects = totalOfEffects;
            }
            unsigned short getTotalOfEffects() const {
              return totalOfEffects;
            }

            // defines addon via method, reassigning mainly the default constructor as that is the primary one.
            void defineAddon(unsigned short itemType, unsigned short index)
            {
              switch(itemType) {
                case 1: {
                  this -> name = flashlightAddonsList[index].getName();
                  this -> rarity = flashlightAddonsList[index].getRarity();
                  this -> forItem = flashlightAddonsList[index].getForItem();
                  this -> effects = flashlightAddonsList[index].getEffects();
                  this -> effectPotency = flashlightAddonsList[index].getEffectPotency();
                  this -> totalOfEffects = flashlightAddonsList[index].getTotalOfEffects();
                }
                case 2: {
                  this -> name = keyAddonsList[index].getName();
                  this -> rarity = keyAddonsList[index].getRarity();
                  this -> forItem = keyAddonsList[index].getForItem();
                  this -> effects = keyAddonsList[index].getEffects();
                  this -> effectPotency = keyAddonsList[index].getEffectPotency();
                  this -> totalOfEffects = keyAddonsList[index].getTotalOfEffects();
                }
                case 3: {
                  this -> name = mapAddonsList[index].getName();
                  this -> rarity = mapAddonsList[index].getRarity();
                  this -> forItem = mapAddonsList[index].getForItem();
                  this -> effects = mapAddonsList[index].getEffects();
                  this -> effectPotency = mapAddonsList[index].getEffectPotency();
                  this -> totalOfEffects = mapAddonsList[index].getTotalOfEffects();
                }
                case 4: {
                  this -> name = mapAddonsList[index].getName();
                  this -> rarity = mapAddonsList[index].getRarity();
                  this -> forItem = mapAddonsList[index].getForItem();
                  this -> effects = mapAddonsList[index].getEffects();
                  this -> effectPotency = mapAddonsList[index].getEffectPotency();
                  this -> totalOfEffects = mapAddonsList[index].getTotalOfEffects();
                }
                case 5: {
                  this -> name = toolboxAddonsList[index].getName();
                  this -> rarity = toolboxAddonsList[index].getRarity();
                  this -> forItem = toolboxAddonsList[index].getForItem();
                  this -> effects = toolboxAddonsList[index].getEffects();
                  this -> effectPotency = toolboxAddonsList[index].getEffectPotency();
                  this -> totalOfEffects = toolboxAddonsList[index].getTotalOfEffects();
                }
                default: {
                  break;
                }
              }
            }
    };
}