// i am going to bash my head into a wall

#include <iostream>
#include "Flashlight.h"
#include "Addons.h"
#include <string.h>
#include <algorithm>
#include <fstream>
#include <vector>

// ptr original vars
unsigned short userInput = 0;
std::string userInputString = "";
unsigned short numAddons = 0;

static std::string capitalizeString(std::string s)
{
  transform(s.begin(), s.end(), s.begin(), 
    [](unsigned char c){ return toupper(c); });
  return s;
}

static void inputReset()
{
  std::cin.ignore(10000, '\n');
  std::cin.clear();
}

static void vectorPrinter(std::vector<float> vec)
{
  for(float i : vec)
    {
      if(vec.back() == i)
      {
        std::cout << i < std::endl;
      }
      else
      {
        std::cout << i << ", ";
      }
    }
}
static void vectorPrinter(std::vector<std::string> vec)
{
  for(std::string i : vec)
    {
      if(vec.back() == i)
      {
        std::cout << i < std::endl;
      }
      else
      {
        std::cout << i << ", ";
      }
}

int main() {

  // user input ptrs
	unsigned short* ptr = &userInput;
	std::string* ptrTwo = &userInputString;
	unsigned short* ptrThree = &numAddons;

  // switch case entering into what item you would like to examine
	std::cout << "What would you like to customize? \n1 | Medkit \n2 | Toolbox \n 3 | Key \n 4 | Map \n 5 | Flashlight \n 6 | Exit Program" << std::endl;
	std::cin >> *ptr;
	while(true)
	{
		switch(*ptr) {
			case 1: {

			}
			case 2: {

			}
			case 3: {

			}
			case 4: {

			}
			case 5: {
        
				bool addonPresent = false;
        bool validAddon = true;
    
				std::cout << "What type of flashlight is it? 1 | Brown \n 2 | Yellow \n 3 | Green \n 4 | Purple" << std::endl;
				std::cin >> *ptr;
        switch(*ptr){
					case 1: {
						N::Flashlight flashlight;
            flashlight.flashlightTypeSetter(1);
            break;
					}
					case 2: {
						N::Flashlight flashlight;
            flashlight.flashlightTypeSetter(2);
            break;
					}
          case 3: {
            N::Flashlight flashlight;
            flashlight.flashlightTypeSetter(3);
            break;
          }
          case 4: {
            N::Flashlight flashlight;
            flashlight.flashlightTypeSetter(4);
            break;
          }
          case 5: {
            N::Flashlight flashlight;
            flashlight.flashlightTypeSetter(5);
            break;
          }
					default: {
						std::cout << "Please only input valid numerical inputs!" << '\n';
            inputReset();
            continue;
					}
				}

        // this is very spaghetti
				std::cout << "Are there any addons on it? If so, type the first name below, otherwise type N/A." << std::endl;
				std::cin >> *ptrTwo;
        if(!(hash(capitalizeString(*ptrTwo), sizeof(*ptrTwo)) == hash("N/A", sizeof("N/A"))
        {
          std::ifstream AddonList_file("AddonList.json", std::ifstream::binary);
          AddonList >> aL
          Addons() newAddon;
          while(true) {
            // tries to find addon in JSON, if it cant it catches the exception and continues onwards, and has the user reinput.
            try {
              newAddon.defineAddon(1, *ptrTwo);
            }
            catch {
              inputClear();
              validAddon = false;
              continue;
            }
            if(validAddon == true)
            {   
              flashlight.setAddon(0, newAddon);
            }
            else {
              std::cout << "Please only input valid addons!" << '\n';
              validAddon = true;
            }
            // check for the pass command
            if(hash(capitalizeString(*ptrTwo), sizeof(*ptrTwo)) == hash("N/A", sizeof("N/A")))
            {
              break;
            }
            
            else if(addonPresent == true)
            {
              break;
            }
          }
        }
        else {
          addonPresent = false;
        }
        // spaghetti cont.
        std::cout << "Is there a second addon present? If so, type the second name below, otherwise type N/A." << std::endl;
	    	std::cin >> *ptrTwo;
        // immediately checks for a pass cmd, if not one it continues
        if(!(hash(capitalizeString(*ptrTwo), sizeof(*ptrTwo)) == hash("N/A", sizeof("N/A"))
        {
          while(true) {
            bool invalidInput = false;
            addonPresent = false;
            // verifies addon is not the same as the first
            else if(flashlight.getAddons(0).getName() == capitalizeString(*ptrTwo))
            {
              std::cout << "You can't have two of the same addon on one item!" << '\n';
              inputClear();
              invalidInput = true;
            }
            //if pass cmd is not found, iterates again through list, verifies the name is the same, and a check for invalid input is run, if passed checks then it will continue to scan for the addon listed
             try {
              newAddon.defineAddon(1, *ptrTwo);
            }
            catch {
              inputClear();
              validAddon = false;
              continue;
            }
            if(validAddon == true)
            {   
              flashlight.setAddon(0, newAddon);
            }
            else {
              std::cout << "Please only input valid addons!" << '\n';
              validAddon = true;
            }
            // standard break statements from the first addon set
            if(!(hash(capitalizeString(*ptrTwo), sizeof(*ptrTwo)) == hash("N/A", sizeof("N/A"))
            {
              break;
            }
            else if(addonPresent == true)
            {
              break;
            }
          }
            // i think this is an effect calculator???
          if (addonPresent == true)
          {
            
          while(true)
            {
              *ptrTwo = "";
              *ptr = 0;
              boolean effectFound = false;
              for(int i = 0; i < sizeof(flashlight.getAddOn[*ptr].getEffects()); i++)
                {
                  if(flashlight.getAddon[*ptr].getEffects()[*ptr] != ' ')
                  {
                    *ptrTwo += flashlight.getAddon[*ptr].getEffects()[*ptr]
                  }
                  else
                  {
                    switch(hash(*ptrTwo, sizeof(*ptrTwo))) {
                      case hash("RANGE", sizeof("RANGE"): {
                        effectFound = true;
                        calculateEffects("range", flashlight.getAddon[*ptr].getEffectPotency[*ptr]))
                        break;
                      }
                      default: {
                        *ptrTwo = "";
                        break;
                      }
                  }
                  if(!(temp[i - 1] == ',') && effectFound == true;)
                  {
                    break;
                    *ptr++;
                  }
                }
              }
              if(*ptr == 2)
              {
                break;
              }
            }
          }
        std::cout << "Name: " << flashlight.getName() << "\nRarity: " << flashlight.getRarity() << "\nRange: " << flashlight.getRange() << "\nWidth: " << flashlight.getWidth() << "\nAccuracy: " << flashlight.getAccuracy() << "\nBrightness: " << flashlight.getBrightness() << "Blindness Duration: " << flashlight.getBlindnessDuration() << "\nUse Time: " << flashlight.getUseTime() << "\nOther Effects: " << vectorPrinter(flashlight.getOtherEffects()) << std::endl;
          // need to implement a way to print out the addons as well and their effects too, but i dont know atm how to check if an array is empty or not
			}
			case 6: {
				std::cout << "Thanks for using our program!" << std::endl;
				break;
			}
			default: {
				std::cout << "Please only insert numerical characters ranging between 1 and 5!" << std::endl;
				inputReset();
        continue;
			}
		}
	}
  return 0;
}