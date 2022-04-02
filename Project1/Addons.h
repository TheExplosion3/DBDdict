#include <iostream>
#include <string>

namespace N
{
    class Addons
    {
        private:
            std::string name;
            std::string rarity;
            std::string forItem;
            std::string effects;
            std::string effectPotency;
            unsigned short totalOfEffects;
        public:
            Addons()
            {
                name = "";
                rarity = "";
                forItem = "";
                effects = "";
                effectPotency = "";
                totalOfEffects = 0;
            }
            Addons(std::string name, std::string rarity, std::string forItem, std::string effects, std::string effectPotency)
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
            }
    };
}