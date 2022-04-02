#include <iostream>
#include <string>
#include "Addons.h"

namespace N
{
    class Flashlight
    {
        private:
            std::string rarity;
            std::string name;
            unsigned short accuracy;
            unsigned short width;
            unsigned short range;
            unsigned short brightness;
            unsigned short useTime;
            Addons addOns[2];
        public:
            Flashlight() {
                rarity = "";
                name = "";
                accuracy = 0;
                width = 0;
                range = 0;
                brightness = 0;
                useTime = 0;
            }
            Flashlight(std::string rarity, std::string name, unsigned short accuracy, unsigned short width, unsigned short range, unsigned short brightness, unsigned short useTime, Addons addOnOne, Addons addOnTwo) {
                this -> rarity = rarity;
                this -> name = name;
                this -> accuracy = accuracy;
                this -> width = width;
                this -> range = range;
                this -> brightness = brightness;
                this -> useTime = useTime;
                addOns[1] = addOnOne;
                addOns[2] = addOnTwo;
            }
            Flashlight(std::string rarity, std::string name, unsigned short accuracy, unsigned short width, unsigned short range, unsigned short brightness, unsigned short useTime, Addons addOnOne) {
                this -> rarity = rarity;
                this -> name = name;
                this -> accuracy = accuracy;
                this -> width = width;
                this -> range = range;
                this -> brightness = brightness;
                this -> useTime = useTime;
                addOns[1] = addOnOne;
            }
            Flashlight(std::string rarity, std::string name, unsigned short accuracy, unsigned short width, unsigned short range, unsigned short brightness, unsigned short useTime) {
                this -> rarity = rarity;
                this -> name = name;
                this -> accuracy = accuracy;
                this -> width = width;
                this -> range = range;
                this -> brightness = brightness;
                this -> useTime = useTime;
            }
            
    };
}