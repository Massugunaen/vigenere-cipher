#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


std::string language_input() {
	std::cout << "Supported languages are: 'english'" << std::endl;
	std::string imposed_language;
    getline(std::cin, imposed_language); 
  	return imposed_language;
}


std::string mode_input() {
	std::cout << "Input your phrase to encrypt/decrypt" << std::endl;
	std::string mode_input;
    getline(std::cin, mode_input); 
  	return mode_input;
}

std::string key_input() {
	std::cout << "Please input your key" << std::endl;
	std::string imposed_key;
    getline(std::cin, imposed_key); 
  	return imposed_key;
}


std::string phrase_input() {
	std::cout << "Input your phrase to encrypt/decrypt" << std::endl;
	std::string imposed_phrase;
    getline(std::cin, imposed_phrase); 
  	return imposed_phrase;
}

