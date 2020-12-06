#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


class Encryptor {
    private:
        std::string plain_text;
        std::string key;
        std::string cipher_text;

		// availabe languages
		std::vector<char>english_alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 
			'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    public:
        void encrypt_data();

        std::string get_cipher_text() { return cipher_text; }

        Encryptor(std::string, std::string);
};


Encryptor::Encryptor(std::string plain_text, std::string key) {
    this -> plain_text = plain_text;
    this -> key = key;
}


void Encryptor::encrypt_data() {
	std::string key = this -> key;
	std::string plain_text = this -> plain_text;

    std::vector<char> rotated_english_language = this -> english_alphabet;

    char letter_for_encrypted_message;
    int index = 0;

    for (int i = 0; i < plain_text.length(); i++) {
        for (int j = 0; j < english_alphabet.size(); j++) {
            if (plain_text[i] == english_alphabet[j]) {
                for (int k = index; k < key.length();) {
                    for (int l = 0; l < rotated_english_language.size(); l++) {
                        if (key[k] == rotated_english_language[l]) {
                            std::rotate(rotated_english_language.begin(), 
                            rotated_english_language.begin() + l, rotated_english_language.end());
                            letter_for_encrypted_message = rotated_english_language[j];
                            cipher_text.push_back(letter_for_encrypted_message);
                            rotated_english_language = english_alphabet;
                        }
                    }
                    if (index == (key.length() - 1)) {
                        index = 0;
                    } else {
                        index++;
                    } break;
                }
            }
        }
    }

}
