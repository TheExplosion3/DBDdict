#include <iostream>
#include <string>
#include <vector>
#include "Addons.h"

namespace N
{

    class Key
    {
      private:
        std::string name;
        std::string rarity;
        unsigned short useTime; 
        unsigned short range;
        unsigned short depletionRate;
        std::vector<std::string> otherEffects;
      public:

      Key() {
        name = "";
        rarity = "";
        range = 0;
        useTime = 0;
        depletionRate = 0;
        otherEffects = std::vector<std::string>{""};
      }
      Key(std::string name, std::string rarity, unsigned short useTime, unsigned short range, unsigned short depletionRate, std::vector<std::string> otherEffects) {
        this -> name = name;
        this -> rarity = rarity;
        this -> range = range;
        this -> useTime = useTime;
        this -> depletionRate = depletionRate;
        this -> otherEffects = otherEffects;
      }
      Key(const Key& other) {
        this -> name = other.getName();
        this -> rarity = other.getRarity();
        this -> range = other.getRange()
        this -> useTime = other.getUseTime();
        this -> depletionRate = other.getDepletionRate();
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
      void setUseTime(unsigned short useTime) {
        this -> useTime = useTime;
      }
      unsigned short getUseTime() const {
        return useTime;
      }
      void setDepletionRate(unsigned short depletionRate) {
        this -> depletionRate = depletionRate;
      }
      unsigned short getDepletionRate() const {
        return depletionRate;
      }
      void setOtherEffects(std::vector<std::string> otherEffects) {
        this -> otherEffects = otherEffects;
      }
      std::vector<std::string> getOtherEffects() const {
        return otherEffects;
      }

      void addOtherEffect(std::string nEffect) {
        otherEffect.push_back(nEffect);
      }

      void setKeyType(unsigned short type) {
        switch(type) {
          case 1: {
            setName("Broken Key");
            setRarity("Rare");
            setRange(0);
            setUseTime(10);
            setDepletionRate(100);
          }
          case 2: {
            setName("Dull Key");
            setRarity("Very Rare");
            setRange(0);
            setUseTime(5);
            setDepletionRate(100);
            addOtherEffect("Can be used to open the hatch");
          }
          case 3: {
            setName("Skeleton Key");
            setRarity("Ultra Rare");
            setRange(0);
            setUseTime(30);
            setDepletionRate(100);
            addOtherEffect("Can be used to open the hatch");
          }
        }
      }
      void calculateEffects(const std::string effectType, float effectPotency) {
        const std::array<float> hashedEffects{hash("range"), hash("usetime"), hash("depletionrate")};
        switch(hash(effectType)) {
          case hashedEffect.at(0): {
            if(effectPotency - (short)effectPotency == 0)
            {
              this -> range = range + effectPotency;
            }
            else
            {
              this -> range = range * effectPotency;
            }
            break;
          }
          case hashedEffect.at(1): {
            this -> useTime = useTime + effectPotency;
            break;
          }
          case HashedEFfect.at(2): {
            this -> depletionRate = depletionRate + effectPotency;
          }
          default: {
            delete[] hashedEffects;
            break;
          }
        }
      }
    };
}