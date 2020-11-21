#include "encrypt_data.h"
#include "decrypt_data.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


string data_input(string phrase) {
	cout << phrase << endl;
	string imposed_data;
    getline(cin, imposed_data);
    transform(imposed_data.begin(), imposed_data.end(), imposed_data.begin(), ::tolower);
    return imposed_data;
}


string recurcive_mode_input() {
    string data;
    getline(cin, data);
    if (data == "-e" || data == "--encr") {
        cout << "\nYou chose encrypting mode" << endl;
        return "encrypting";
    } else if (data == "-d" || data == "--decr") {
        cout << "\nYou chose decrypting mode" << endl;
        return "decrypting";
    } else if (data == "-h" || data == "--help") {
    	cout << "\nAvailable args: [--help] [-e | --encr] [-d | --decr]" << endl;
        cout << "  -h | --help \tDisplay this message" << endl;
        cout << "  -e | --encr \tEnter encrypting mode" << endl;
        cout << "  -d | --decr \tEnter decrypting mode\n" << endl;
        return recurcive_mode_input();
    } else {
        cout << "\nMistake in choosing mode, please try again" << endl;
        cout << "Type -h for help\n" << endl;
        return recurcive_mode_input();
    }
}


int main (int argc, char *argv[]) {
	if (argc != 4) {
		cout << "usage <script> <mode> <key> <message>" << endl;
		cout << "type -h for help and usage examples" << endl;
		return 1;
	}

    vector<char> english_language = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                                          'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<char> *_ptr_english_language = &english_language;
	
    string chosen_mode = argv[1];
	
    string(*_ptr_data_input)(string);
    _ptr_data_input = &data_input;
	
    if (chosen_mode == "encrypting") {
        string imposed_key = (*_ptr_data_input)("Input key:");

        string imposed_message = (*_ptr_data_input)("Input your message:"); 
		
        encrypting_algorithm(imposed_key, imposed_message, english_language);

        return EXIT_SUCCESS;
    } else if (chosen_mode == "decrypting") {
        string imposed_key = (*_ptr_data_input)("Input key:");
        
        string imposed_message = (*_ptr_data_input)("Input your message:"); 

        decrypting_algorithm(imposed_key, imposed_message, *_ptr_english_language);

        return EXIT_SUCCESS;
    }

}

