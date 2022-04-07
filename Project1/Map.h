#include <iostream>
#include <string>
#include <vector>
#include "Addons.h"

namespace N
{
    class Map
    {
      private:
        float useTime;
        unsigned short range;
        std::string name;
        std::string rarity;
        std::vector<std::string> otherEffects;
        std::array<Addons> addOns[2];
      public:
        Map() {
          useTime = 0;
          range = 0;
          name = "";
          rarity = "";
          otherEffects = std::vector<std::string>>{""};
        }
        Map(float useTime, unsigned short range, std::string name, std::string rarity, std::vector<std::string> otherEffects, std::array<Addons> addOns) {
          this -> useTime = useTime;
          this -> range = range;
          this -> name = name;
          this -> rarity = rarity;
          this -> otherEffects = otherEffects;
          this -> addOns = addOns;
        }
        virtual ~Map() {
          delete[] addOns;
        }
        Map(const Map& other) {
          this -> useTime = other.getUseTime();
          this -> range = other.getRange()
          this -> name = other.getName();
          this -> rarity = other.getRarity();
          this -> otherEffects = other.getOtherEffects();
          this -> addOns = other.getAddOns();
        }

        void setName(std::string name) {
          this -> name = name;
        }
        std::string getRarity() const {
          return Rarity;
        }
        void setRarity(std::string rarity) {
          this -> rarity = rarity;
        }
        std::string getName() const {
          return name;
        }
        void setRange(unsigned short range) {
          this -> range = range;
        }
        unsigned short getRange() const {
          return range;
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
        void setAddOns(std::array<Addons> addOns) {
          this -> addOns = addOns;
        }
        void setAddOn(unsigned short index, Addons addon) {
          this -> addOns[index] = addon;
        }
        Addons getAddOn(unsigned short index) const {
          return addOns[index];
        }
        std::array<Addons> getAddOns() const {
          return addOns;
        }

        void addOtherEffects(std::string nEffect) {
          otherEffects.push_back(nEffect);
        }
    };
}