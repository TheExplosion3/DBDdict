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
      public:
        Map() {
          useTime = 0;
          range = 0;
          name = "";
          rarity = "";
          otherEffects = std::vector<std::string>>{""};
        }
        Map(float useTime, unsigned short range, std::string name, std::string rarity, std::vector<std::string> otherEffects) {
          this -> useTime = useTime;
          this -> range = range;
          this -> name = name;
          this -> rarity = rarity;
          this -> otherEffects = otherEffects;
        }
        Map(const Map& other) {
          this -> useTime = other.getUseTime();
          this -> range = other.getRange()
          this -> name = other.getName();
          this -> rarity = other.getRarity();
          this -> otherEffects = other.getOtherEffects();
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

        void addOtherEffects(std::string nEffect) {
          otherEffects.push_back(nEffect);
        }
    };
}