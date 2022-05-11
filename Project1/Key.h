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
    public:

    Key() {
      name = "";
      rarity = "";
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

    void calculateEffects(unsigned short effectType, float effectPotency) {
      switch(effectType) {
        case 1: {
          if(useTime - (short)useTime == 0) {
            this -> useTime += effectPotency;
          }
          else {
            this -> useTIme *= effectPotency;
          }
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
        }
        case 3: {
          obsessionChance = 0;
        }
      }
    }
  };
}