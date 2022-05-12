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
        
      }

      Toolbox(const Toolbox& other) {
        
      }

      virtual ~Toolbox() {}

      void setGoodSkillcheckSize(float goodSkillcheckSize) {
        this -> goodSkillcheckSize = goodSkillcheckSize;
      }
      float getGoodSkillcheckSize() const {
        return goodSkillcheckSize;
      }
  };
}