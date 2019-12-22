#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


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



std::string data_input(std::string phrase) {
	std::cout << phrase << std::endl;
	std::string imposed_phrase;
    getline(std::cin, imposed_phrase); 
  	return imposed_phrase;
}

