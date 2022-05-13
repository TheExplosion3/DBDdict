#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "Item.h"
#include "Addons.h"

namespace O {
  class Flashlight : public Item {
    protected:
      mutable float accuracy;
      mutable float width;
      mutable float range;
      mutable float brightness;
      mutable float blindnessDuration;
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

      virtual ~Flashlight() {}

      Flashlight(const Flashlight& other) {
        this -> rarity = other.getRarity();
        this -> name = other.Item::getName();
        this -> otherEffects = other.Item::getOtherEffects();
        this -> accuracy = other.getAccuracy();
        this -> width = other.getWidth();
        this -> range = other.getRange();
        this -> brightness = other.getBrightness();
        this -> useTime = other.getUseTime();
        this -> blindnessDuration = other.getBlindnessDuration();
      }

      // getters and setters
      
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
            if(effectPotency - (short)effectPotency == 0) {
              this -> useTime += effectPotency;
            }
            else {
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
            otherEffects.clear();
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
            otherEffects.clear();
            otherEffects.push_back("Explodes with confetti upon blinding a killer");
            break;
          }
          default: {
            break;
          }
        }
      }

      // prints the primary flashlight object
      virtual void printObj() override {
        O::Item::printObj();
        std::cout << "Accuracy: " << this->accuracy << "\nWidth: " << this->width << "\nRange: " << this->range << "\nBrightness: " << this->brightness << "\nBlindness Duration: " << this->blindnessDuration << '\n' << std::endl;
      }
  };
};