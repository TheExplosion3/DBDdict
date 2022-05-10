#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "Items.h"
#include "Addons.h"

namespace O {
  class Item {
    protected:
      std::string name;
      std::string rarity;
      std::array<Addons, 2> addOns;
      std::vector<std::string> otherEffects;
      unsigned short useTime;
    public:
      Item() {
        name = "";
        rarity = "";
        useTime = 0;
      }

      Item(const &Item other) {
        this -> name = other.getName();
        this -> rarity = other.getRarity();
        this -> otherEffects = other.getOtherEffects();
        this -> addOns = other.getAddOns();
        this -> useTime = other.getUseTime();
      }

      virtual ~Item() {}


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
  };
}