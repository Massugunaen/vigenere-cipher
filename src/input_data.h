#include <iostream>
#include <string>


std::string data_input(std::string phrase) {
	std::cout << phrase << std::endl;
	std::string imposed_phrase;
    getline(std::cin, imposed_phrase); 
  	return imposed_phrase;
}


std::string Rmode_input() {
    std::string data;
    getline(std::cin, data);
    if (data == "-e" || data == "--encr") {
        return "encrypting";
    } else if (data == "-d" || data == "--decr") {
        return data;
    } else {
        std::cout << "Mistake in choosing mode, please try again" << std::endl;
        return Rmode_input();
    }
}

