#include "Lang.h"


Lang::Lang(std::string lang_choice) {
	if (lang_choice == "english") {
		this->requested_language = this->english_alphabet;
	} else {
		std::cout << "No such language is available" << std::endl;
		std::cout << "Available language options are: english" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}


std::vector<char> Lang::get_lang() {
	return this-> requested_language;
}
