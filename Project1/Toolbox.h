#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Addons.h"

namespace O {
  class Toolbox : public Item {
    protected:
      float repairSpeed;
      float goodSkillcheckSize;
      float sabotageSpeed;
      float sabotageTimer;
    public:
      Toolbox() {
        name = "";
        rarity = "";
        useTime = 0;
        repairSpeed = 0;
        goodSkillcheckSize = 0;
        sabotageSpeed = 0;
        sabotageTimer = 0;
      }

      Toolbox(const Toolbox& other) {
        this -> name = other.getName();
        this -> rarity = other.getRarity();
        this -> useTime = other.getUseTime();
        this -> repairSpeed = other.getRepairSpeed();
        this -> goodSkillcheckSize = other.getGoodSkillcheckSize();
        this -> sabotageSpeed = other.getSabotageSpeed();
        this -> sabotageTimer = other.getSabotageTimer();
        this -> otherEffects = other.getOtherEffects();
      }

      virtual ~Toolbox() {}

      void setGoodSkillcheckSize(float goodSkillcheckSize) {
        this -> goodSkillcheckSize = goodSkillcheckSize;
      }
      float getGoodSkillcheckSize() const {
        return goodSkillcheckSize;
      }
      void setSabotageSpeed(float sabotageSpeed) {
        this -> sabotageSpeed = sabotageSpeed;
      }
      float getSabotageSpeed() const {
        return sabotageSpeed;
      }
      void setSabotageTimer(float sabotageTimer) {
        this -> sabotageTimer = sabotageTimer;
      }
      float getSabotageTimer() const {
        return sabotageTimer;
      }
      void setRepairSpeed(float repairSpeed) {
        this -> repairSpeed = repairSpeed;
      }
      float getRepairSpeed() const {
        return repairSpeed;
      }

      void toolboxTypeSetter(unsigned short type) {
        switch(type) {
          case 1: {
            setName("Worn-Out Tools");
            setRarity("Common");
            setUseTime(16);
            setRepairSpeed(150);
            setGoodSkillcheckSize(90);
            setSabotageSpeed(100);
            setSabotageTimer(30);
            break;
          }
          case 2: {
            setName("Toolbox");
            setRarity("Uncommon");
            setUseTime(20);
            setRepairSpeed(150);
            setSabotageSpeed(90);
            setSabotageTimer(30);
            break;
          }
          case 3: {
            setName("Mechanic's Toolbox");
            setRarity("Rare");
            setUseTime(16);
            setRepairSpeed(175);
            setSabotageSpeed(110);
            setSabotageTimer(30);
            break;
          }
          case 4: {
            setName("Commodious Toolbox");
            setRarity("Rare");
            setUseTime(32);
            setRepairSpeed(150);
            setSabotageSpeed(110);
            setSabotageTimer(30);
            break;
          }
          case 5: {
            setName("Engineer's Toolbox");
            setRarity("Very Rare");
            setUseTime(16);
            setRepairSpeed(200);
            setSabotageSpeed(75);
            setSabotageTimer(30);
            break;
          }
          case 6: {
            setName("Alex's Toolbox");
            setRarity("Very Rare");
            setUseTime(24);
            setRepairSpeed(110);
            setSabotageSpeed(150);
            setSabotageTimer(30);
          }
          case 7: {
            setName("Anniversary Toolbox");
            setRarity("Event");
            setUseTime(32);
            setRepairSpeed(150);
            setSabotageSpeed(100);
            setSabotageTimer(30);
            otherEffects.clear();
            otherEffects.push_back("Detonates a firework once depleted");
          }
          case 8: {
            setName("Festive Toolbox");
            setRarity("Event");
            setUseTime(32);
            setRepairSpeed(150);
            setSabotageSpeed(100);
            setSabotageTimer(30);
            otherEffects.clear();
            otherEffects.push_back("Succeeding a Great Skill Check detonates a small cluster of firecrackers");
            otherEffects.push_back("Missing a Skill Check detonates fireworks");
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
          this -> repairSpeed *= effectPotency;
          break;
        }
        case 3: {
          this -> sabotageSpeed *= sabotageSpeed;
          break;
        }
        case 4: {
          this -> sabotageTimer += sabotageTimer;
          break;
        }
        default: {
          break;
        }
      }
    }

    virtual void printObj() override {
      O::Item::printObj();
      std::cout << "Repair Speed: " << this -> repairSpeed << "\nSabotage Speed: " << this -> sabotageSpeed << "\nSabotage Timer: " << this -> sabotageTimer << std::endl;
    }
  };
}