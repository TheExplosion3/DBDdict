#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "Addons.h"

namespace O
{
    class Flashlight
    {
        protected:
            std::string rarity;
            std::string name;
            std::vector<std::string> otherEffects;
            unsigned mutable short accuracy;
            unsigned mutable short width;
            unsigned mutable short range;
            unsigned mutable short brightness;
            unsigned mutable short blindnessDuration;
            float useTime;
            std::array<Addons, 2> addOns;
        public:
            Flashlight() {
                rarity = "";
                name = "Flashlight";
                accuracy = 100;
                width = 100;
                range = 100;
                brightness = 100;
                useTime = 0;
                otherEffects = std::vector<std::string>{""};
            }
            Flashlight(std::string rarity, std::string name, std::vector<std::string> otherEffects, unsigned short accuracy, unsigned short width, unsigned short range, unsigned short brightness, float useTime, unsigned short blindnessDuration, Addons addOnOne, Addons addOnTwo) {
                this -> rarity = rarity;
                this -> name = name;
                this -> otherEffects = otherEffects;
                this -> accuracy = accuracy;
                this -> width = width;
                this -> range = range;
                this -> brightness = brightness;
                this -> useTime = useTime;
                this -> blindnessDuration = blindnessDuration;
                addOns[0] = addOnOne;
                addOns[1] = addOnTwo;
            }
            Flashlight(std::string rarity, std::string name, std::vector<std::string> otherEffects, unsigned short accuracy, unsigned short width, unsigned short range, unsigned short brightness, float useTime, unsigned short blindnessDuration, Addons addOnOne) {
                this -> rarity = rarity;
                this -> name = name;
                this -> otherEffects = otherEffects;
                this -> accuracy = accuracy;
                this -> width = width;
                this -> range = range;
                this -> brightness = brightness;
                this -> useTime = useTime;
                this -> blindnessDuration = blindnessDuration;
                addOns[0] = addOnOne;
            }
            Flashlight(std::string rarity, std::string name, std::vector<std::string> otherEffects, unsigned short accuracy, unsigned short width, unsigned short range, unsigned short brightness, float useTime) {
                this -> rarity = rarity;
                this -> name = name;
                this -> otherEffects = otherEffects;
                this -> accuracy = accuracy;
                this -> width = width;
                this -> range = range;
                this -> brightness = brightness;
                this -> useTime = useTime;
            }
            virtual ~Flashlight() {}
            Flashlight(const Flashlight& other) {
              this -> rarity = other.getRarity();
              this -> name = other.getName();
              this -> otherEffects = other.getOtherEffects();
              this -> accuracy = other.getAccuracy();
              this -> width = other.getWidth();
              this -> range = other.getRange();
              this -> brightness = other.getBrightness();
              this -> useTime = other.getUseTime();
            }

            // why does OOP have to use so many getters and setters lmao
            void setName(std::string name) {
              this -> name = name;
            }
            std::string getName() const{
              return name;
            }
            void setRarity(std::string rarity) {
              this -> rarity = rarity;
            }
            std::string getRarity() const {
              return rarity;
            }
            void setOtherEffects(std::vector<std::string> otherEffects) {
              this -> otherEffects = otherEffects;
            }
            std::vector<std::string> getOtherEffects() const {
              return otherEffects;
            }
            void setAccuracy(unsigned short accuracy) {
              this -> accuracy = accuracy;
            }
            unsigned short getAccuracy() const {
              return accuracy;
            }
            void setWidth(unsigned short width) {
              this -> width = width;
            }
            unsigned short getWidth() const {
              return width;
            }
            void setRange(unsigned short range) {
              this -> range = range;
            }
            unsigned short getRange() const {
              return range;
            }
            void setBrightness(unsigned short Brightness) {
              this -> brightness = brightness;
            }
            unsigned short getBrightness() const {
              return brightness;
            }
            void setUseTime(float useTime) {
              this -> useTime = useTime;
            }
            float getUseTime() const {
              return useTime;
            }
            void setAddOn(unsigned short index, Addons addon) {
              this -> addOns[index] = addon;
            }
            Addons getAddOn(unsigned short index) const {
              return addOns[index];
            }
            void setAddOns(std::array<Addons, 2> addOns) {
              this -> addOns = addOns;
            }
            std::array<Addons, 2> getAddOns() {
              return addOns;
            }
            void setBlindnessDuration(unsigned short blindnessDuration) {
              this -> blindnessDuration = blindnessDuration;
            }
            unsigned short getBlindnessDuration() const {
              return blindnessDuration;
            }
            // i have no clue why but i cannot for the life of me get it to hash these strings and properly read them
            void calculateEffects(unsigned short effectType, float effectPotency) {
              
              switch(effectType) {
                case 1: {
                  this -> accuracy = this -> accuracy * effectPotency;
                }
                case 2: {
                  this -> width = this -> width * effectPotency;
                }
                case 3: {
                  this -> range = this -> range * effectPotency;
                }
                case 4: {
                  if(effectPotency - (short)effectPotency == 0)
                  {
                    this -> useTime = this -> useTime + effectPotency;
                  }
                  else
                  {
                    this -> useTime = this -> useTime * effectPotency;
                  }
                }
                case 5: {
                  this -> brightness = this -> brightness * effectPotency;
                }
                default: {
                  break;
                }
              }
            }

            void flashlightTypeSetter(unsigned short type) {
              switch(type) {
                case 1: {
                  setName("Flashlight");
                  setRarity("Uncommon");
                  setBrightness(100);
                  setAccuracy(100);
                  setWidth(100);
                  setRange(100);
                  setBlindnessDuration(100);
                  setUseTime(8);
                  break;
                }
                case 2: {
                  setName("Sport Flashlight");
                  setRarity("Rare");
                  setBrightness(100);
                  setAccuracy(120);
                  setWidth(100);
                  setBlindnessDuration(100);
                  setUseTime(7.12);
                  break;
                }
                case 3: {
                  setName("Utility Flashlight");
                  setRarity("Very Rare");
                  setBrightness(130);
                  setAccuracy(85);
                  setWidth(100);
                  setBlindnessDuration(115);
                  setUseTime(12);
                  break;
                }
                case 4: {
                  setName("Will O' Wisp");
                  setRarity("Event");
                  setBrightness(100);
                  setAccuracy(100);
                  setWidth(100);
                  setBlindnessDuration(100);
                  setUseTime(8);
                  otherEffects.push_back("More friendly ghosts in your life");
                  break;
                }
                case 5: {
                  setName("Anniversary Flashlight");
                  setRarity("Event");
                  setBrightness(100);
                  setAccuracy(100);
                  setWidth(100);
                  setBlindnessDuration(100);
                  setUseTime(8);
                  otherEffects.push_back("Explodes with confetti upon blinding a killer");
                  break;
                }
                default: {
                  break;
                }
              }
            }
          void addOtherEffects(std::string altEffect) {
            this -> otherEffects.push_back(altEffect);
          }
  

  };
};