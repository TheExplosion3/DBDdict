#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Addons.h"

namespace O {
  class Map : public Item {
    protected:
      mutable float range;
      unsigned short totalObjectsTracked;
    public:

      Map() {
        name = "";
        rarity = "";
        range = 8;
        useTime = 20;
        totalObjectsTracked = 0;
      }

      virtual ~Map() {}

      Map(const Map& other) {
        this -> name = other.getName();
        this -> rarity = other.getRarity();
        this -> otherEffects = other.getOtherEffects();
        this -> range = other.getRange();
      }

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
      void setRange(float range) {
        this -> range = range;
      }
      float getRange() const {
        return range;
      }

      void calculateEffects(unsigned short effectType, float effectPotency) {
        switch(effectType) {
          case 1: {
            this -> range += effectPotency;
            break;
          }
          case 2: {
            if(effectPotency - (short)effectPotency == 0) {
              this -> useTime += effectPotency;
              break;
            }
            else {
              this -> useTime *= effectPotency;
              break;
            }
          }
        }
      }
      void addOtherEffects(std::string altEffect) {
        if(otherEffects.size() == 0) {
          otherEffects.clear();
          otherEffects.push_back(altEffect);
          return;
        }
        this -> otherEffects.push_back(altEffect);
      }
  };
}