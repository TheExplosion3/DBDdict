#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Addons.h"

namespace O {
  class Map {
    protected:
      std::string name;
      std::string rarity;
      std::vector<std::string> otherEffects;
      mutable float useTime;
      mutable float range;
      unsigned short totalObjectsTracked;
      std::array<Addons, 2> addOns;
    public:

      Map() {
        name = "";
        rarity = "";
        range = 8;
        useTime = 20;
        totalObjectsTracked = 0;
      }

      virtual ~Map() {}

      Map(const &Map other) {
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
            if(effectPotency - (short)effectPotency == 0) {
              this -> range += effectPotency;
            }
            else {
              this -> range *= effectPotency;
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