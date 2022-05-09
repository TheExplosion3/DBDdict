#pragma once
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
            mutable float accuracy;
            mutable float width;
            mutable float range;
            mutable float brightness;
            mutable float blindnessDuration;
            mutable float useTime;
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
            
            Flashlight(std::string rarity, std::string name, std::vector<std::string> otherEffects, float accuracy, float width, float range, float brightness, float useTime, float blindnessDuration, Addons addOnOne, Addons addOnTwo) {
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

            Flashlight(std::string rarity, std::string name, std::vector<std::string> otherEffects, float accuracy, float width, float range, float brightness, float useTime, float blindnessDuration, Addons addOnOne) {
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

            Flashlight(std::string rarity, std::string name, std::vector<std::string> otherEffects, float accuracy, float width, float blindnessDuration, float range, float brightness, float useTime) {
              this -> rarity = rarity;
              this -> name = name;
              this -> otherEffects = otherEffects;
              this -> accuracy = accuracy;
              this -> width = width;
              this -> range = range;
              this -> brightness = brightness;
              this -> useTime = useTime;
              this -> blindnessDuration = blindnessDuration;
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
              this -> blindnessDuration = other.getBlindnessDuration();
            }

            // getters and setters
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
            void setAccuracy(float accuracy) {
              this -> accuracy = accuracy;
            }
            float getAccuracy() const {
              return accuracy;
            }
            void setWidth(float width) {
              this -> width = width;
            }
            float getWidth() const {
              return width;
            }
            void setRange(float range) {
              this -> range = range;
            }
            float getRange() const {
              return range;
            }
            void setBrightness(float brightness) {
              this -> brightness = brightness;
            }
            float getBrightness() const {
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
            void setBlindnessDuration(float blindnessDuration) {
              this -> blindnessDuration = blindnessDuration;
            }
            float getBlindnessDuration() const {
              return blindnessDuration;
            }
            // calculates the effects that an addon has on a flashlight, via input of the effect potency and effect type as parameters.
            void calculateEffects(unsigned short effectType, float effectPotency) {
              switch(effectType) {
                case 1: {
                  this -> accuracy *= effectPotency;
                  break;
                }
                case 2: {
                  this -> width *= effectPotency;
                  break;
                }
                case 3: {
                  this -> range *= effectPotency;
                  break;
                }
                case 4: {
                  if(effectPotency - (short)effectPotency == 0)
                  {
                    this -> useTime += effectPotency;
                  }
                  else
                  {
                    this -> useTime += effectPotency;
                  }
                  break;
                }
                case 5: {
                  this -> brightness *= effectPotency;
                  break;
                }
                case 6: {
                  this -> blindnessDuration *= effectPotency;
                  break;
                }
                default: {
                  break;
                }
              }
            }
            // Sets the flashlight's base stats via its rarity, inputted as an float which increases/decreases based upon rarity.
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
          // Adds another miscellaneous effect to the otherEffects vector
          void addOtherEffects(std::string altEffect) {
            this -> otherEffects.push_back(altEffect);
          }
          // prints the primary flashlight object
          void printFLO() {
            std::cout << this -> name << '\n' << "Rarity: " << this -> rarity << '\n' << "Accuracy: " << this -> accuracy << '\n' << "Width: " << this -> width << '\n' << "Range: " << this -> range << '\n' << "Brightness: " << this -> brightness << '\n' << "Blindness Duration: " << this -> blindnessDuration << '\n' << "Use Time: " << this -> useTime << '\n' << "Other Effects: " << vectorPrinter(this -> otherEffects) << std::endl;
          }
          // prints an addon for the flashlight, specified via unsigned short idx.
          void printFLA(unsigned short idx) {
            std::string temp = "";
            Addons* ptr = &addOns.at(idx);
            
            for(char &i : ptr->getEffects()) {
              if(i != '&') {
                temp += i;
              }
            }
            std::cout << "Name: " << ptr->getName() << '\n' << "Rarity: " << ptr->getRarity() << '\n' << "Effects: " << temp << std::endl;
          }
  

  };
};