#include <iostream>
#include <string>


std::string data_input(std::string phrase) {
	std::cout << phrase << std::endl;
	std::string imposed_phrase;
    getline(std::cin, imposed_phrase); 
  	return imposed_phrase;
}

/*
 * This is test function for finding out if 
 * arg str is array of chars 
 */
void testString(std::string str) {

    for (int i = 0; i < str.length(); i++) {
        std::cout << str[i];
    }

}

