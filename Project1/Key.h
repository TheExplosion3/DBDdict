#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Addons.h"

namespace O {
  class Key : public Item {
    protected:
      float range;
      float obsessionChance;
      bool canOpenHatch;
    public:

    Key() {
      name = "";
      rarity = "";
      useTime = 0;
      range = 0;
      obsessionChance = 100;
    }

    virtual ~Key() {}

    Key(const Key& other) {
      this -> name = other.getName();
      this -> rarity = other.getRarity();
      this -> obsessionChance = other.getObsessionChance();
      this -> range = other.getRange();
      this -> otherEffects = other.getOtherEffects();
    }

    void setRange(float range) {
      this -> range = range;
    }
    float getRange() const {
      return range;
    }
    void setObsessionChance(float obsessionChance) {
      this -> obsessionChance = obsessionChance;
    }
    float getObsessionChance() const {
      return obsessionChance;
    }
    void setHatch(bool canOpenHatch) {
      this -> canOpenHatch = canOpenHatch;
    }
    bool getHatch() const {
      return canOpenHatch;
    }

    void keyTypeSetter(unsigned short type) {
      switch(type) {
        case 1: {
          setName("Broken Key");
          setRarity("Rare");
          setHatch(false);
          setUseTime(10);
          break;
        }
        case 2: {
          setName("Dull Key");
          setRarity("Very Rare");
          setHatch(true);
          setUseTime(5);
          break;
        }
        case 3: {
          setName("Skeleton Key");
          setRarity("Ultra Rare");
          setHatch(true);
          setUseTime(20);
          break;
        }
        default: {
          break;
        }
      }
    }

    void calculateEffects(unsigned short effectType, float effectPotency) {
      switch(effectType) {
        case 1: {
          if(effectPotency - (short)effectPotency == 0) {
            this -> useTime += effectPotency;
          }
          else {
            this -> useTime *= effectPotency;
          }
          break;
        }
        case 2: {
          if(effectPotency == 12) {     
            this -> range += effectPotency;
          }
          else {
            if(range < effectPotency) {
              this -> range = effectPotency;
            }
          }
          break;
        }
        case 3: {
          obsessionChance = 0;
          break;
        }
        default: {
          break;
        }
      }
    }

    virtual void printObj() override {
      O::Item::printObj();
      std::cout << "Range: " << this -> range << "\nObsession Chance" << this -> obsessionChance << '\n' << std::endl;
    }
  };
}