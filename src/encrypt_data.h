#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


class Encryptor {
    private:
        std::string plain_text;
        std::string key;
        std::string lang_choice;
        std::string cipher_text;
		sdt::vector<char> alphabet;

		// availabe languages
		std::array<char, 26>english_alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 
			'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    public:
        void set_plain_text(std::string plain_text) { this -> plain_text = plain_text; }
        std::string get_plain_text() { return plain_text; }

        void set_key(std::string key) { this -> key = key; }
        std::string get_key() { return key; }

        void set_language(std::string language) { this -> language = language; }
        std::string get_language() { return language; }

        std::string encrypt(std::string, std::string, std::vector<char>);

        std::string get_cipher_text() { return cipher_text; }

        Encryptor(std::string, std::string, std::vector<char>);
};


Encryptor::Encryptor(std::string plain_text, std::string key, std::vector<char> lang_choice) {
    this -> plain_text = plain_text;
    this -> key = key;
    this -> alphabet = alphabet;
}


std::string Encryptor::encrypt(std::string imposed_key, std::string imposed_message, std::vector<char> english_language) {
    std::vector<char> rotated_english_language = english_language;
    
    std::string encrypted_message; 

    char letter_for_encrypted_message;
    int index = 0;

    for (int i = 0; i < imposed_message.length(); i++) {
        for (int j = 0; j < english_language.size(); j++) {
            if (imposed_message[i] == english_language[j]) {
                for (int k = index; k < imposed_key.length();) {
                    for (int l = 0; l < rotated_english_language.size(); l++) {
                        if (imposed_key[k] == rotated_english_language[l]) {
                            std::rotate(rotated_english_language.begin(), 
                            rotated_english_language.begin() + l, rotated_english_language.end());
                            letter_for_encrypted_message = rotated_english_language[j];
                            encrypted_message.push_back(letter_for_encrypted_message);
                            rotated_english_language = english_language;
                        }
                    }
                    if (index == (imposed_key.length() - 1)) {
                        index = 0;
                    } else {
                        index++;
                    } break;
                }
            }
        }
    }

    return encrypted_message;
}
