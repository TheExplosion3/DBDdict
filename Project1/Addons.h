#include <iostream>
#include <string>
#include <vector>

constexpr uint32_t hash(const char* data, size_t const size) noexcept{
    uint32_t hash = 5381;

    for(const char *c = data; c < data + size; ++c)
        hash = ((hash << 5) + hash) + (unsigned char) *c;

    return hash;
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
            static Addons flashlightAddonList[14] = {Addons("Wide Lens", "Common", "Flashlight", "Increases width of beam by 15%, decreases beam range by 25%.", {1.15, 0.75}), Addons("Power Bulb", "Common", "Flashlight", "Increases brightness of beam by 20%, increases blindness duration by 10%. ", {1.2, 1.1}), Addons("Leather Grip", "Common", "Flashlight", "Increases accuracy by 20%", {1.2}), Addons("Battery", "Common", "Flashlight", "Adds 2 seconds of use", {2}), Addons("TIR Optic", "Uncommon", "Flashlight", "Increases brightness by 30%, increases blindness duration by 15%", {1.3, 1.15}), Addons("Rubber Grip", "Uncommon", "Flashlight", "Increases accuracy by 40%", {1.4}), Addons("Low Amp Filament", "Uncommon", "Flashlight", "Decreases depletion rate by 20%", {0.8}), Addons("Heavy Duty Battery", "Uncommon", "Flashlight", "Adds 4 seconds of use", {4}), Addons("Focus Lens", "Uncommon", "Flashlight", "Extends range by 25%, increases brightness by 20%, increases blindness by 10%, decreases width by 15", {1.25, 1.2, 1.1, 0.85}), Addons("Long Life Battery", "Rare", "Flashlight", "Adds 6 seconds of use", {6}), Addons("Intense Halogen", "Rare", "Flashlight", "Increases brightness by 40%, increases blindness duration by 20%", {1.4, 1.2}), Addons("High-End Sapphire Lens", "Flashlight", "Very Rare", "Increases range by 25%, increases brightness by 30%, increases blindness duration by 15%, increases width by 25%", {1.25, 1.3, 1.15, 1.25}), Addons("Odd Bulb", "Ultra Rare", "Flashlight", "Increases brightness by 50%, increases blindness duration by 25%, increases depletion rate by 14%", {1.5, 1.25, 0.86}), Addons("Broken Bulb", "Event", "Flashlight", "Causes the flashlight to flicker, increases brightness by 30%, increases blindness duration by 15%, increases spookiness", {1.3, 1.15})};
            static Addons medkitAddonsList[14] = {Addons("Rubber Gloves", "Common", "Medkit", "Increases the progression bonus of Great Skill Checks by 3%", {1.03}), Addons("Butterfly Tape", "Common", "Medkit", "Increases healing speed by 5%", {1.05}), Addons("Bandages", "Common", "Medkit", "Increases available charges by 8", {8}), Addons("Sponge", "Uncommon", "Medkit", "Increases the progression bonus of Great Skill Checks by 5%", {1.05}), Addons("Self Adherent Wrap", "Uncommon", "Medkit", "Increases available charges by 8, increases healing speed by 5%", {8, 1.05}), Addons("Needle & Thread", "Uncommon", "Medkit", "Increases healing speed by 15%, increases trigger odds of Skill Checks by 10%, grants 100% bonus BP for Great Skill Checks", {1.15, 1.10, 100}), Addons("Medical Scissors", "Uncommon", "Medkit", "Increases healing speed by 15%", {1.15}), Addons("Gauze Roll", "Uncommon", "Medkit", "Increases available charges by 12", {12}), Addons("Surgical Suture", "Rare", "Medkit", "Increases healing speed by 15%, increases trigger odds of Skill Checks by 15%, grants 150% bonus BP for Great Skill Checks", {1.15, 1.15, 150}), Addons("Gel Dressings", "Rare", "Medkit", "Increases available charges by 16", {16}), Addons("Abdominal Dressing", "Rare", "Medkit", "Increases healing speed by 25%, decreases available charges by 8", {1.25, 8}), Addons("Styptic Agent", "Very Rare", "Medkit", "Applies the Endurance status effect for 8 seconds", {8}), Addons("Anti-Hemorrhagic Syringe", "Ultra Rare", "Medkit", "Over 16 seconds the survivor will gain 1 health state | medkit is consumed on use, affected by healing speed modifiers and cancelled by change of health state | can be used on self or other survivors", {16}), Addons("Refined Serum", "Event", "Medkit", "Increases movement speed by 5% for 16 seconds, leaves a Blight trail behind the affected survivor, consumes medkit on use and can be used on yourself or other survivors", {1.05, 16})};
            static Addons keyAddonsList[9] = {Addons("Prayer Rope", "Common", "Key", "Adds 10 seconds of use", {10}), Addons("Scratched Pearl", "Uncommon", "Key", "Increases Aura-reading range by 12", {12}), Addons("Prayer Beads", "Uncommon", "Key", "Adds 15 seconds of use", {15}), Addons("Eroded Token", "Uncommon", "Key", "Unlocks Aura reading ability to see all survivors within 24m", {24}), Addons("Gold Token", "Rare", "Key", "Unlocks Aura reading ability to see all survivors within 48m", {48}), Addons("Weaved Ring", "Very Rare", "Key", "On death, key is not lost, lose this addon instead.", {0}), Addons("Milky Glass", "Very Rare", "Key", "Upon opening the hatch, key is not lost, lose this addon instead", {0}), Addons("Blood Amber", "Very Rare", "Key", "Unlocks Aura reading ability to see the killer within 32m, increases depletion rate by 100%", {32, 100}), Addons("Unique Wedding Ring", "Very Rare", "Key", "Unlocks Aura reading ability to see the Obsession within 32m, lowers odds of becoming the Obsession by 100%", {32, 100})};
            static Addons mapAddonsList[9] = {Addons("Map Addendum", "Common", "Map", "Adds 5 seconds of use", {5}), Addons("Yellow Wire", "Uncommon", "Map", "Unlocks the ability to track Exit Gates", {0}), Addons("Unusual Stamp", "Uncommon", "Map", "Increases tracking range by 8m", {8}), Addons("Retardant Jelly", "Uncommon", "Map", "Decreases depletion rate by 20%", {0.80}), Addons("Red Twine", "Uncommon", "Map", "Unlocks the ability to track killer belongings", {0}), Addons("Glass Bead", "Map", "Place a pillar of light at your current location that is visible to all survivors", {0}), Addons("Odd Stamp", "Rare", "Map", "Increases tracking range by 12m", {12}), Addons("Black Silck Cord", "Rare", "Map", "Unlocks the ability to track the hatch", {0}), Addons("Crystal Bead", "Very Rare", "Map", "Reveals the Auras generated by the map to all survivors", {0})}
            static Addons toolboxAddonsList[11] = {Addons("Scraps", "Common", "Toolbox", "Adds 8 available charges", {8}), Addons("Instructions", "Common", "Toolbox", "Removes normal Skill Check Prompts", {0}), Addons("Clean Rag", "Common", "Toolbox", "Increases repair speed by 20%". {1.2}), Addons("Wire Spool", "Uncommon", "Toolbox", "Increases available charges by 12", {12}), Addons("Spring Clamp", "Uncommon", "Toolbox", "Decreases distance repairs can be heard from by 8m", {-8}), Addons("Socket Swivels", "Uncommon", "Toolbox", "Increases repair speed by 30%", {1.3}), Addons("Protective Gloves", "Uncommon", "Toolbox", "Removes the Loud Noise Notification from sabotaging a hook", {0}), Addons("Cutting Wire", "Uncommon", "Toolbox", "Increases sabotage speed by 15%", {1.15}), Addons("Hacksaw", "Rare", "Toolbox", "Increases sabotage speed by 20%", {1.2}), Addons("Grip Wrench", "Rare", "Toolbox", "Increases the auto repair timer for hooks sabotaged by 15 seconds", {15}), Addons("Brand New Part", "Ultra Rare", "Toolbox", "Takes 5 seconds to install, adds 15% to generator progression. Triggers 2 difficult skillchecks during installation process, successful completion adds 5% extra progression up to a total of 25% progression", {5, 15, 5, 25})};
    
            Addons()
            {
                name = "";
                rarity = "";
                forItem = "";
                effects = "";
                effectPotency = {0};
                totalOfEffects = 0;
            }
            Addons(std::string name, std::string rarity, std::string forItem, std::string effects, std::vector<short> effectPotency)
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
              
            void setName(std::string name) {
              this -> name = name;
            }
            std::string getName() {
              return name;
            }
            void setRarity(std::string rarity) {
              this -> rarity = rarity;
            }
            std::string getRarity() {
              return rarity;
            }
            void setEffects(std::string effects) {
              this -> effects = effects;
            }
            std::string getEffects() {
              return effects;
            }
            void setForItem(std::string forItem) {
              this -> forItem = forItem;
            }
            std::string getForItem() {
              return forItem;
            }
            void setEffectPotency(std::vector<float> effectPotency) {
              this -> effectPotency = effectPotency;
            }
            std::vector<float> getEffectPotency() {
              return effectPotency;
            }
            void setTotalOfEffects(unsigned short totalOfEffects) {
              this -> totalOfEffects = totalOfEffects;
            }
            unsigned short getTotalOfEffects() {
              return totalOfEffects;
            }

            // defines addon via method, reassigning mainly the default constructor as that is the primary one.
            public void defineAddon(std::string itemType, unsigned short index)
            {
              switch(hash(itemType)) {
                case hash("FLASHLIGHT"): {
                  this -> name = flashlightAddonList[index].getName();
                  this -> rarity = flashlightAddonList[index].getRarity();
                  this -> forItem = flashlightAddonList[index].getForItem();
                  this -> effects = flashlightAddonList[index].getEffects();
                  this -> effectPotency = flashlightAddonList[index].getEffectPotency();
                  this -> totalOfEffects = flashlightAddonList[index].getTotalOfEffects();
                  continue;
                }
                case hash("KEY"): {
                  this -> name = keyAddonList[index].getName();
                  this -> rarity = keyAddonList[index].getRarity();
                  this -> forItem = keyAddonList[index].getForItem();
                  this -> effects = keyAddonList[index].getEffects();
                  this -> effectPotency = keyAddonList[index].getEffectPotency();
                  this -> totalOfEffects = keyAddonList[index].getTotalOfEffects();
                  continue;
                }
                case hash("MAP"): {
                  this -> name = mapAddonList[index].getName();
                  this -> rarity = mapAddonList[index].getRarity();
                  this -> forItem = mapAddonList[index].getForItem();
                  this -> effects = mapAddonList[index].getEffects();
                  this -> effectPotency = mapAddonList[index].getEffectPotency();
                  this -> totalOfEffects = mapAddonList[index].getTotalOfEffects();
                  continue;
                }
                case hash("MEDKIT"): {
                  this -> name = mapAddonList[index].getName();
                  this -> rarity = mapAddonList[index].getRarity();
                  this -> forItem = mapAddonList[index].getForItem();
                  this -> effects = mapAddonList[index].getEffects();
                  this -> effectPotency = mapAddonList[index].getEffectPotency();
                  this -> totalOfEffects = mapAddonList[index].getTotalOfEffects();
                  continue;
                }
                case hash("TOOLBOX"): {
                  this -> name = toolboxAddonList[index].getName();
                  this -> rarity = toolboxAddonList[index].getRarity();
                  this -> forItem = toolboxAddonList[index].getForItem();
                  this -> effects = toolboxAddonList[index].getEffects();
                  this -> effectPotency = toolboxAddonList[index].getEffectPotency();
                  this -> totalOfEffects = toolboxAddonList[index].getTotalOfEffects();
                  continue;
                }
                default: {
                  continue;
                }
              }
            }
    };
}