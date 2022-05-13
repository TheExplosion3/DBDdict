#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Addons.h"

namespace O {
  class Medkit : public Item {
    protected:
      float pHealSpeed;
      float aHealSpeed;
      float healTime;
      float bonusBP;
      float goodSkillcheckSize;
      float greatSkillcheckSize;
      float skillcheckProgression;
    public:
      Medkit() {
        name = "";
        rarity = "";
        goodSkillcheckSize = 0;
        greatSkillcheckSize = 0;
        bonusBP = 0;
        useTime = 0;
        pHealSpeed = 0;
        aHealSpeed = 0;
        healTime = 0;
        skillcheckProgression = 0;
      }

      Medkit(const Medkit& other) {
        this -> name = other.getName();
        this -> rarity = other.getRarity();
        this -> useTime = other.getUseTime();
        this -> pHealSpeed = other.getPHealSpeed();
        this -> aHealSpeed = other.getAHealSpeed();
        this -> healTime = other.getHealTime();
        this -> goodSkillcheckSize = other.getGoodSkillcheckSize();
        this -> greatSkillcheckSize = other.getGreatSkillcheckSize();
        this -> skillcheckProgression = other.getSkillcheckProgression();
        this -> otherEffects = other.getOtherEffects();
      }

      virtual ~Medkit() {}

      void setPHealSpeed(float pHealSpeed) {
        this -> pHealSpeed = pHealSpeed;
      }
      float getPHealSpeed() const {
        return pHealSpeed;
      }
      void setAHealSpeed(float aHealSpeed) {
        this -> aHealSpeed = aHealSpeed;
      }
      float getAHealSpeed() const {
        return aHealSpeed;
      }
      void setHealTime(float healTime) {
        this -> healTime = healTime;
      }
      float getHealTime() const {
        return healTime;
      }
      void setGoodSkillcheckSize(float goodSkillcheckSize) {
        this -> goodSkillcheckSize = goodSkillcheckSize;
      }
      float getGoodSkillcheckSize() const {
        return goodSkillcheckSize;
      }
      void setGreatSkillcheckSize(float greatSkillcheckSize) {
        this -> greatSkillcheckSize = greatSkillcheckSize;
      }
      float getGreatSkillcheckSize() const {
        return greatSkillcheckSize;
      }
      void setSkillcheckProgression(float skillcheckProgression) {
        this -> skillcheckProgression = skillcheckProgression;
      }
      float getSkillcheckProgression() const {
        return skillcheckProgression;
      }
      void setBonusBP(float bonusBP) {
        this -> bonusBP = bonusBP;
      }
      float getBonusBP() const {
        return bonusBP;
      }

      void medkitTypeSetter(unsigned short type) {
        switch(type) {
          case 1: {
            setName("Camping Aid Kit");
            setRarity("Common");
            setUseTime(16);
            setPHealSpeed(100);
            setAHealSpeed(125);      
            setBonusBP(0);
            setGoodSkillcheckSize(100);
            setGreatSkillcheckSize(100);
            setSkillcheckProgression(0.05);
            break;
          }
          case 2: {
            setName("First Aid Kit");
            setRarity("Uncommon");
            setUseTime(24);
            setPHealSpeed(100);
            setAHealSpeed(135);      
            setBonusBP(0);
            setGoodSkillcheckSize(100);
            setGreatSkillcheckSize(100);
            setSkillcheckProgression(0.05);
            break;
          }
          case 3: {
            setName("Emergency Med-Kit");
            setRarity("Rare");
            setUseTime(16);
            setPHealSpeed(150);
            setAHealSpeed(150);      
            setBonusBP(0);
            setGoodSkillcheckSize(114);
            setGreatSkillcheckSize(115);
            setSkillcheckProgression(0.05);
            break;
          }
          case 4: {
            setName("Ranger Med-Kit");
            setRarity("Very Rare");
            setUseTime(32);
            setPHealSpeed(100);
            setAHealSpeed(150);      
            setBonusBP(0);
            setGoodSkillcheckSize(100);
            setGreatSkillcheckSize(100);
            setSkillcheckProgression(0.05);
            break;
          }
          case 5: {
            setName("All Hallows' Eve Lunchbox");
            setRarity("Event");
            setUseTime(24);
            setPHealSpeed(100);
            setAHealSpeed(135);      
            setBonusBP(0);
            setGoodSkillcheckSize(100);
            setGreatSkillcheckSize(100);
            setSkillcheckProgression(0.05);
            otherEffects.clear();
            otherEffects.push_back("Makes you more visible");
            break;
          }
          case 6: {
            setName("Anniversary Med-Kit");
            setRarity("Event");
            setUseTime(24);
            setPHealSpeed(100);
            setAHealSpeed(135);      
            setBonusBP(0);
            setGoodSkillcheckSize(100);
            setGreatSkillcheckSize(100);
            setSkillcheckProgression(0.05);
            otherEffects.clear();
            otherEffects.push_back("Explodes with confetti upon fully healing a survivor.");
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
            this -> pHealSpeed *= effectPotency;
            break;
          }
          case 3: {
            this -> aHealSpeed *= effectPotency;
          }
          case 4: {
            this -> bonusBP *= bonusBP;
          }
          case 5: {
            if(effectPotency - (short)effectPotency == 0) {
              this -> healTime += effectPotency;
            }
            else {
              this -> healTime *= effectPotency;
            }
            break;
          }
          case 6: {
            this -> skillcheckProgression *=  effectPotency;
            break;
          }
          case 7: {
            this -> goodSkillcheckSize *= effectPotency;
            break;
          }
          case 8: {
            this -> greatSkillcheckSize *= effectPotency;
            break;
          }
          default: {
            break;
          }
        }
      }
      virtual void printObj() override {
        O::Item::printObj();
        std::cout << "Personal Heal Speed: " << pHealSpeed << "\nAltruistic Heal Speed: " << aHealSpeed << "\nBonus Bloodpoints: " << bonusBP << std::endl;
        if(addOns[0].getName() == "Anti Hemmhoragic Syringe" || addOns[0].getName() == "Anti Hemmhoragic Syringe") {
          std::cout << "Heal Time: " << healTime << std::endl;
        }
        std::cout << "Great Skillcheck Progression Bonus: " << skillcheckProgression << "\nGood Skillcheck Zone Size: " << goodSkillcheckSize << "\nGreat Skillcheck Zone Size: " << greatSkillcheckSize << std::endl;
      }
  };
}