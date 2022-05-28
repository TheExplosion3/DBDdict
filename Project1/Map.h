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
        range = 0;
        useTime = 0;
        totalObjectsTracked = 0;
      }

      virtual ~Map() {}

      Map(const Map& other) {
        this -> name = other.getName();
        this -> rarity = other.getRarity();
        this -> otherEffects = other.getOtherEffects();
        this -> range = other.getRange();
      }

      void setRange(float range) {
        this -> range = range;
      }
      float getRange() const {
        return range;
      }
      void setObjectsTracked(unsigned short totalObjectsTracked) {
        this -> totalObjectsTracked = totalObjectsTracked;
      }
      unsigned short getObjectsTracked() const {
        return totalObjectsTracked;
      }
      
      void mapTypeSetter(unsigned short type) {
        switch(type) {
          case 1: {
            setName("Map");
            setRarity("Rare");
            setUseTime(20);
            setRange(8);
            setObjectsTracked(1);
            otherEffects.clear();
            otherEffects.push_back("Can track generators");
            break;
          }
          case 2: {
            setName("Rainbow Map");
            setRarity("Ultra Rare");
            setUseTime(20);
            setRange(8);
            setObjectsTracked(3);
            otherEffects.clear();
            otherEffects.push_back("Can track exit gates, generators, the hatch, killer belongings, as well as chests and totems tracked by Detective's Hunch.");
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
          case 3: {
            totalObjectsTracked++;
            break;
          }
          default: {
            break;
          }
        }
      }

      virtual void printObj() override {
        O::Item::printObj();
        std::cout << "Range: " << this -> range << "\nTotal Items Tracked: " << this -> totalObjectsTracked << '\n' << std::endl;
      }
  };
}