#include "Lang.h"

using namespace std;


Lang::Lang(string lang_choice) {
	if (lang_choice == "english") {
		this->requested_language = this->english_alphabet;
	} else {
		cout << "No such language is available" << endl;
		cout << "Available language options are: english" << endl;
		exit(EXIT_FAILURE);
	}
}


vector<char> Lang::get_lang() {
	return this-> requested_language;
}
