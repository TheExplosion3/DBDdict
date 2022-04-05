#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

const unsigned short hash(const std::string s) {
  std::size_t h1 = std::hash<std::string>{}(s);
  return h1;
}

namespace N
{
    class Addons
    {
        private:
            std::string name;
            std::string rarity;
            std::string forItem;
            std::string effects;
            std::vector<float> effectPotency;
            unsigned short totalOfEffects;
        public:
            // lists of all addons available, used primarily by the defineAddon method
            static Addons flashlightAddonsList[14] = {const N::Addons("Wide Lens", "Common", "Flashlight", "Increases width of beam by 15%, decreases beam range by 25%.", {1.15, 0.75}), const N::Addons("Power Bulb", "Common", "Flashlight", "Increases brightness of beam by 20%, increases blindness duration by 10%. ", {1.2, 1.1}), const N::Addons("Leather Grip", "Common", "Flashlight", "Increases accuracy by 20%", {1.2}), const N::Addons("Battery", "Common", "Flashlight", "Adds 2 seconds of use", {2}), const N::Addons("TIR Optic", "Uncommon", "Flashlight", "Increases brightness by 30%, increases blindness duration by 15%", {1.3, 1.15}), const N::Addons("Rubber Grip", "Uncommon", "Flashlight", "Increases accuracy by 40%", {1.4}), const N::Addons("Low Amp Filament", "Uncommon", "Flashlight", "Decreases depletion rate by 20%", {0.8}), const N::Addons("Heavy Duty Battery", "Uncommon", "Flashlight", "Adds 4 seconds of use", {4}), const N::Addons("Focus Lens", "Uncommon", "Flashlight", "Extends range by 25%, increases brightness by 20%, increases blindness by 10%, decreases width by 15", {1.25, 1.2, 1.1, 0.85}), const N::Addons("Long Life Battery", "Rare", "Flashlight", "Adds 6 seconds of use", {6}), const N::Addons("Intense Halogen", "Rare", "Flashlight", "Increases brightness by 40%, increases blindness duration by 20%", {1.4, 1.2}), const N::Addons("High-End Sapphire Lens", "Flashlight", "Very Rare", "Increases range by 25%, increases brightness by 30%, increases blindness duration by 15%, increases width by 25%", {1.25, 1.3, 1.15, 1.25}), const N::Addons("Odd Bulb", "Ultra Rare", "Flashlight", "Increases brightness by 50%, increases blindness duration by 25%, increases depletion rate by 14%", {1.5, 1.25, 0.86}), const N::Addons("Broken Bulb", "Event", "Flashlight", "Causes the flashlight to flicker, increases brightness by 30%, increases blindness duration by 15%, increases spookiness", {1.3, 1.15})};
            static Addons medkitAddonsList[14] = {const N::Addons("Rubber Gloves", "Common", "Medkit", "Increases the progression bonus of Great Skill Checks by 3%", {1.03}), const N::Addons("Butterfly Tape", "Common", "Medkit", "Increases healing speed by 5%", {1.05}), const N::Addons("Bandages", "Common", "Medkit", "Increases available charges by 8", {8}), const N::Addons("Sponge", "Uncommon", "Medkit", "Increases the progression bonus of Great Skill Checks by 5%", {1.05}), const N::Addons("Self Adherent Wrap", "Uncommon", "Medkit", "Increases available charges by 8, increases healing speed by 5%", {8, 1.05}), const N::Addons("Needle & Thread", "Uncommon", "Medkit", "Increases healing speed by 15%, increases trigger odds of Skill Checks by 10%, grants 100% bonus BP for Great Skill Checks", {1.15, 1.10, 100}), const N::Addons("Medical Scissors", "Uncommon", "Medkit", "Increases healing speed by 15%", {1.15}), const N::Addons("Gauze Roll", "Uncommon", "Medkit", "Increases available charges by 12", {12}), const N::Addons("Surgical Suture", "Rare", "Medkit", "Increases healing speed by 15%, increases trigger odds of Skill Checks by 15%, grants 150% bonus BP for Great Skill Checks", {1.15, 1.15, 150}), const N::Addons("Gel Dressings", "Rare", "Medkit", "Increases available charges by 16", {16}), const N::Addons("Abdominal Dressing", "Rare", "Medkit", "Increases healing speed by 25%, decreases available charges by 8", {1.25, 8}), const N::Addons("Styptic Agent", "Very Rare", "Medkit", "Applies the Endurance status effect for 8 seconds", {8}), const N::Addons("Anti-Hemorrhagic Syringe", "Ultra Rare", "Medkit", "Over 16 seconds the survivor will gain 1 health state | medkit is consumed on use, affected by healing speed modifiers and cancelled by change of health state | can be used on self or other survivors", {16}), const N::Addons("Refined Serum", "Event", "Medkit", "Increases movement speed by 5% for 16 seconds, leaves a Blight trail behind the affected survivor, consumes medkit on use and can be used on yourself or other survivors", {1.05, 16})};
            static Addons keyAddonsList[9] = {const N::Addons("Prayer Rope", "Common", "Key", "Adds 10 seconds of use", {10}), const N::Addons("Scratched Pearl", "Uncommon", "Key", "Increases Aura-reading range by 12", {12}), const N::Addons("Prayer Beads", "Uncommon", "Key", "Adds 15 seconds of use", {15}), const N::Addons("Eroded Token", "Uncommon", "Key", "Unlocks Aura reading ability to see all survivors within 24m", {24}), const N::Addons("Gold Token", "Rare", "Key", "Unlocks Aura reading ability to see all survivors within 48m", {48}), const N::Addons("Weaved Ring", "Very Rare", "Key", "On death, key is not lost, lose this addon instead.", {0}), const N::Addons("Milky Glass", "Very Rare", "Key", "Upon opening the hatch, key is not lost, lose this addon instead", {0}), const N::Addons("Blood Amber", "Very Rare", "Key", "Unlocks Aura reading ability to see the killer within 32m, increases depletion rate by 100%", {32, 100}), const N::Addons("Unique Wedding Ring", "Very Rare", "Key", "Unlocks Aura reading ability to see the Obsession within 32m, lowers odds of becoming the Obsession by 100%", {32, 100})};
            static Addons mapAddonsList[9] = {const N::Addons("Map Addendum", "Common", "Map", "Adds 5 seconds of use", {5}), const N::Addons("Yellow Wire", "Uncommon", "Map", "Unlocks the ability to track Exit Gates", {0}), const N::Addons("Unusual Stamp", "Uncommon", "Map", "Increases tracking range by 8m", {8}), const N::Addons("Retardant Jelly", "Uncommon", "Map", "Decreases depletion rate by 20%", {0.80}), const N::Addons("Red Twine", "Uncommon", "Map", "Unlocks the ability to track killer belongings", {0}), const N::Addons("Glass Bead", "Map", "Place a pillar of light at your current location that is visible to all survivors", {0}), const N::Addons("Odd Stamp", "Rare", "Map", "Increases tracking range by 12m", {12}), const N::Addons("Black Silck Cord", "Rare", "Map", "Unlocks the ability to track the hatch", {0}), const N::Addons("Crystal Bead", "Very Rare", "Map", "Reveals the Auras generated by the map to all survivors", {0})};
            static Addons toolboxAddonsList[11] = {const N::Addons("Scraps", "Common", "Toolbox", "Adds 8 available charges", {8}), const N::Addons("Instructions", "Common", "Toolbox", "Removes normal Skill Check Prompts", {0}), const N::Addons("Clean Rag", "Common", "Toolbox", "Increases repair speed by 20%". {1.2}), const N::Addons("Wire Spool", "Uncommon", "Toolbox", "Increases available charges by 12", {12}), const N::Addons("Spring Clamp", "Uncommon", "Toolbox", "Decreases distance repairs can be heard from by 8m", {-8}), const N::Addons("Socket Swivels", "Uncommon", "Toolbox", "Increases repair speed by 30%", {1.3}), const N::Addons("Protective Gloves", "Uncommon", "Toolbox", "Removes the Loud Noise Notification from sabotaging a hook", {0}), const N::Addons("Cutting Wire", "Uncommon", "Toolbox", "Increases sabotage speed by 15%", {1.15}), const N::Addons("Hacksaw", "Rare", "Toolbox", "Increases sabotage speed by 20%", {1.2}), const N::Addons("Grip Wrench", "Rare", "Toolbox", "Increases the auto repair timer for hooks sabotaged by 15 seconds", {15}), const N::Addons("Brand New Part", "Ultra Rare", "Toolbox", "Takes 5 seconds to install, adds 15% to generator progression. Triggers 2 difficult skillchecks during installation process, successful completion adds 5% extra progression up to a total of 25% progression", {5, 15, 5, 25})};
    
            Addons()
            {
                name = "";
                rarity = "";
                forItem = "";
                effects = "";
                effectPotency = {0};
                totalOfEffects = 0;
            }
            Addons(std::string name, std::string rarity, std::string forItem, std::string effects, std::vector<float> effectPotency)
            {
                this -> name = name;
                this -> rarity = rarity;
                this -> forItem = forItem;
                this -> effects = effects;
                this -> effectPotency = effectPotency;
                for(int i = 0; i < effects.length(); i++)
                {
                    if(effects[i] == ',')
                    {
                        totalOfEffects++;
                    }
                }
                totalOfEffects++;
            }
            Addons(const N::Addons& other) {
              this -> name = other.getName();
              this -> rarity = other.getRarity();
              this -> forItem = other.getForItem();
              this -> effects = other.getEffects();
              this -> effectPotency = other.getEffectPotency();
              this -> totalOfEffects = other.getTotalOfEffects();
            }
              
            void setName(std::string name) {
              this -> name = name;
            }
            std::string getName() const {
              return name;
            }
            void setRarity(std::string rarity) {
              this -> rarity = rarity;
            }
            std::string getRarity() const {
              return rarity;
            }
            void setEffects(std::string effects) {
              this -> effects = effects;
            }
            std::string getEffects() const {
              return effects;
            }
            void setForItem(std::string forItem) {
              this -> forItem = forItem;
            }
            std::string getForItem() const {
              return forItem;
            }
            void setEffectPotency(std::vector<float> effectPotency) {
              this -> effectPotency = effectPotency;
            }
            std::vector<float> getEffectPotency() const {
              return effectPotency;
            }
            void setTotalOfEffects(unsigned short totalOfEffects) {
              this -> totalOfEffects = totalOfEffects;
            }
            unsigned short getTotalOfEffects() const {
              return totalOfEffects;
            }

            // defines addon via method, reassigning mainly the default constructor as that is the primary one.
            void defineAddon(unsigned short itemType, unsigned short index)
            {
              switch(itemType) {
                case 1: {
                  this -> name = flashlightAddonsList[index].getName();
                  this -> rarity = flashlightAddonsList[index].getRarity();
                  this -> forItem = flashlightAddonsList[index].getForItem();
                  this -> effects = flashlightAddonsList[index].getEffects();
                  this -> effectPotency = flashlightAddonsList[index].getEffectPotency();
                  this -> totalOfEffects = flashlightAddonsList[index].getTotalOfEffects();
                }
                case 2: {
                  this -> name = keyAddonsList[index].getName();
                  this -> rarity = keyAddonsList[index].getRarity();
                  this -> forItem = keyAddonsList[index].getForItem();
                  this -> effects = keyAddonsList[index].getEffects();
                  this -> effectPotency = keyAddonsList[index].getEffectPotency();
                  this -> totalOfEffects = keyAddonsList[index].getTotalOfEffects();
                }
                case 3: {
                  this -> name = mapAddonsList[index].getName();
                  this -> rarity = mapAddonsList[index].getRarity();
                  this -> forItem = mapAddonsList[index].getForItem();
                  this -> effects = mapAddonsList[index].getEffects();
                  this -> effectPotency = mapAddonsList[index].getEffectPotency();
                  this -> totalOfEffects = mapAddonsList[index].getTotalOfEffects();
                }
                case 4: {
                  this -> name = mapAddonsList[index].getName();
                  this -> rarity = mapAddonsList[index].getRarity();
                  this -> forItem = mapAddonsList[index].getForItem();
                  this -> effects = mapAddonsList[index].getEffects();
                  this -> effectPotency = mapAddonsList[index].getEffectPotency();
                  this -> totalOfEffects = mapAddonsList[index].getTotalOfEffects();
                }
                case 5: {
                  this -> name = toolboxAddonsList[index].getName();
                  this -> rarity = toolboxAddonsList[index].getRarity();
                  this -> forItem = toolboxAddonsList[index].getForItem();
                  this -> effects = toolboxAddonsList[index].getEffects();
                  this -> effectPotency = toolboxAddonsList[index].getEffectPotency();
                  this -> totalOfEffects = toolboxAddonsList[index].getTotalOfEffects();
                }
                default: {
                  break;
                }
              }
            }
    };
}