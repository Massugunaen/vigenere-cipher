#include <iostream>
#include <string>


std::string data_input(std::string phrase) {
	std::cout << phrase << std::endl;
	std::string imposed_phrase;
    getline(std::cin, imposed_phrase); 
  	
    return imposed_phrase;
}


std::string recurcive_mode_input() {
    std::string data;
    getline(std::cin, data);

    if (data == "-e" || data == "--encr") {
        return "encrypting";
    } else if (data == "-d" || data == "--decr") {
        return "decrypting";
    } else if (data == "-h" || data == "--help") {
        return "help";
    } else {
        std::cout << "Mistake in choosing mode, please try again" << std::endl;

        return recurcive_mode_input();
    }

}

