#include <iostream>
#include "Flashlight.h"
#include "Addons.h"
#include <string.h>
#include <algorithm>

unsigned short userInput = 0;
std::string userInputString = "";
unsigned short numAddons = 0;

std::string capitalizeString(std::string s)
{
    transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return toupper(c); });
    return s;
}



int main() {

	unsigned short* ptr = &userInput;
	std::string* ptrTwo = &userInputString;
	unsigned short* ptrThree = &numAddons;
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
				std::string tempName = "";
				bool addonPresent = false;

				std::cout << "What type of flashlight is it? 1 | Brown \n 2 | Yellow \n 3 | Green \n 4 | Purple" << std::endl;
				std::cin >> *ptr;
				std::cout << "Are there any addons on it? If so, add their names separated by commas. Otherwise, type N/A." << std::endl;
				std::cin >> *ptrTwo;
				if(capitalizeString(*ptrTwo) != "N/A")
				{
					addonPresent = true;
					tempName += *ptrTwo;
					std::string tempStr = *ptrTwo;
					for(int i = 0; i < tempStr.size(); i++)
					{
						if(tempStr[i] == ',')
						{
							*ptrThree++;
						}
						if(*ptrThree == 2)
						{
							break;
						}
					}
				}
				if(addonPresent == true)
				{
					std::cout << "What do these addons do? List them out, and separate effects they provide via commas." << std::endl;
					std::cin >> *ptrTwo;
				}

				// need to make it so type of flashlight is id'd via pointer number,  and that it auto sets in the flashlight class declaration for simplicity's sake
				switch(*ptrThree){
					case 1: {
						N::Flashlight flashlight();
					}
					case 2: {
						N::Flashlight flashlight;
					}
					default: {
						N::Flashlight flashlight;
					}
				}
				


			}
			case 6: {
				std::cout << "Thanks for using our program!" << std::endl;
				break;
			}
			default: {
				std::cout << "Please only insert numerical characters ranging between 1 and 5!" << std::endl;
				std::cin.ignore(10000, '\n');
				std::cin.clear();
				continue;
			}
		}
	}
}