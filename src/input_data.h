#include <iostream>
#include <string>
#include <algorithm>


std::string data_input(std::string phrase) {
	std::cout << phrase << std::endl;
	std::string imposed_phrase;
    getline(std::cin, imposed_phrase); 
    std::transform(imposed_phrase.begin(), imposed_phrase.end(), imposed_phrase.begin(), ::tolower);
  	
    return imposed_phrase;
}


std::string recurcive_mode_input() {
    std::string data;
    getline(std::cin, data);

    if (data == "-e" || data == "--encr") {
        std::cout << "\nYou chose encrypting mode" << std::endl;
        
        return "encrypting";
    } else if (data == "-d" || data == "--decr") {
        std::cout << "\nYou chose decrypting mode" << std::endl;
        
        return "decrypting";
    } else if (data == "-h" || data == "--help") {
        std::cout << "\nAvailable args: [--help] [-e | --encr] [-d | --decr]" << std::endl;
        std::cout << "  -h | --help \tDisplay this message" << std::endl;
        std::cout << "  -e | --encr \tEnter encrypting mode" << std::endl;
        std::cout << "  -d | --decr \tEnter decrypting mode\n" << std::endl;
        
        return recurcive_mode_input();
    } else {
        std::cout << "\nMistake in choosing mode, please try again" << std::endl;
        std::cout << "Type -h for help\n" << std::endl;

        return recurcive_mode_input();
    }

}
