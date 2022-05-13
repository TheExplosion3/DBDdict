#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "Addons.h"

namespace O {
  class Item {
    public:
      std::string name;
      std::string rarity;
      std::array<Addons, 2> addOns;
      std::vector<std::string> otherEffects;
      float useTime;
    public:
      Item() {
        name = "";
        rarity = "";
        useTime = 0;
        
      }

      Item(const Item& other) {
        this -> name = other.getName();
        this -> rarity = other.getRarity();
        this -> otherEffects = other.getOtherEffects();
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
      void setUseTime(float useTime) {
        this -> useTime = useTime;
      }
      float getUseTime() const {
        return useTime;
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
  
      // Adds another miscellaneous effect to the otherEffects vector
      void addOtherEffects(std::string altEffect) {
        if(otherEffects.at(0) == "") {
          otherEffects.clear();
          otherEffects.push_back(altEffect);
          return;
        }
        this -> otherEffects.push_back(altEffect);
      }

      // Prints out the item obj, mainly used as a base function for the actual items.
      virtual void printObj() {
        std::cout << "Name: " << this->name << "\nRarity: " << this->rarity << "\nUse Time: " << useTime << "\nOther Effects: " << vectorPrinter(this->otherEffects);
      }

      // Prints out an addon, at the index idx.
      void printA(unsigned short idx) {
        std::string temp = "";
        Addons* ptr = &addOns.at(idx);
        
        for(char &i : ptr->getEffects()) {
          if(i != '&') {
            temp += i;
          }
        }
        std::cout << "Name: " << ptr -> getName() << '\n' << "Rarity: " << ptr -> getRarity() << '\n' << "Effects: " << temp << std::endl;
      }
  };
};