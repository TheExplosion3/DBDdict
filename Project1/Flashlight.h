#include <iostream>
#include <string>
#include <vector>
#include "Addons.h"

namespace N
{
    class Flashlight
    {
        private:
            std::string rarity;
            std::string name;
            std::vector<string> otherEffects
            unsigned short accuracy;
            unsigned short width;
            unsigned short range;
            unsigned short brightness;
            unsigned short useTime;
            Addons addOns[2];
        public:

            Flashlight() {
                rarity = "";
                name = "Flashlight";
                accuracy = 100;
                width = 100;
                range = 100;
                brightness = 100;
                useTime = 0;
            }
            Flashlight(std::string rarity, std::string name, std::vector<string> otherEffects, unsigned short accuracy, unsigned short width, unsigned short range, unsigned short brightness, unsigned short useTime, Addons addOnOne, Addons addOnTwo) {
                this -> rarity = rarity;
                this -> name = name;
                this -> otherEffects = otherEffects;
                this -> accuracy = accuracy;
                this -> width = width;
                this -> range = range;
                this -> brightness = brightness;
                this -> useTime = useTime;
                addOns[1] = addOnOne;
                addOns[2] = addOnTwo;
            }
            Flashlight(std::string rarity, std::string name, std::srting otherEffects, unsigned short accuracy, unsigned short width, unsigned short range, unsigned short brightness, unsigned short useTime, Addons addOnOne) {
                this -> rarity = rarity;
                this -> name = name;
                this -> otherEffects = otherEffects;
                this -> accuracy = accuracy;
                this -> width = width;
                this -> range = range;
                this -> brightness = brightness;
                this -> useTime = useTime;
                addOns[1] = addOnOne;
            }
            Flashlight(std::string rarity, std::string name, std::vector<string> otherEffects, unsigned short accuracy, unsigned short width, unsigned short range, unsigned short brightness, unsigned short useTime) {
                this -> rarity = rarity;
                this -> name = name;
                this -> otherEffects = otherEffects;
                this -> accuracy = accuracy;
                this -> width = width;
                this -> range = range;
                this -> brightness = brightness;
                this -> useTime = useTime;
            }

            void setName(std::string name) {
              this -> name = name;
            }
            std::string getName() {
              return name;
            }
            void setRarity(std::string rarity) {
              this -> rarity = rarity;
            }
            std::string getRarity() {
              return rarity;
            }
            void setOtherEffects(std::vector<string> otherEffects) {
              this -> otherEffects = otherEffects;
            }
            std::vector<string> getOtherEffects() {
              return otherEffects;
            }
            void setAccuracy(unsigned short accuracy) {
              this -> accuracy = accuracy;
            }
            unsigned short getAccuracy() {
              return accuracy;
            }
            void setWidth(unsigned short width) {
              this -> width = width;
            }
            unsigned short getWidth() {
              return width;
            }
            void setRange(unsigned short range) {
              this -> range = range;
            }
            unsigned short getRange() {
              return range;
            }
            void setBrightness(unsigned short Brightness) {
              this -> brightness = brightness;
            }
            unsigned short getBrightness() {
              return brightness;
            }
            void setUseTime(unsigned short useTime) {
              this -> useTime = useTime;
            }
            unsigned short getUseTime() {
              return useTime;
            }
            void setAddOns(unsigned short index, Addons addon) {
              this -> addOns[index] = addon;
            }
            Addons getAddOn(unsigned short index) {
              return addOns[index];
            }

            void calculateEffects(std::string effectType, float effectPotency) {
              switch(hash(effectType)) {
                case hash("accuracy"): {
                  this -> accuracy = this -> accuracy * effectPotency;
                  continue;
                }
                case hash("width"): {
                  this -> width = this -> width * effectPotency;
                  continue;
                }
                case hash("range"): {
                  this -> range = this -> range * effectPotency;
                }
                case hash("usetime"): {
                  if(effectPotency - (short)effectPotency == 0)
                  {
                    this -> useTime = this -> useTime + effectPotency;
                  }
                  else
                  {
                    this -> useTime = this -> useTime * effectPotency;
                  }
                }
                case hash("brightness"): {
                  this -> brightness = this -> brightness * effectPotency;
                }
                default: {
                  continue;
                }
              }
            }
            void addOtherEffects(std::string altEffect) {
              this -> otherEffects.push_back(altEffect);
            }
  

            
    };
}