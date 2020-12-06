#include "Encryptor.h"


std::string Encryptor::get_cipher_text() { 
	return cipher_text; 
}


Encryptor::Encryptor(std::string plain_text, std::string key) {
    this -> plain_text = plain_text;
    this -> key = key;
}


void Encryptor::encrypt_data() {
    std::vector<char> vert_lang = english_alphabet;

    char letter_for_encrypted_message;
    int index = 0;

    for (int i = 0; i < plain_text.length(); i++) {
        for (int j = 0; j < english_alphabet.size(); j++) {
            if (plain_text[i] == english_alphabet[j]) {
                for (int k = index; k < key.length();) {
                    for (int l = 0; l < vert_lang.size(); l++) {
                        if (key[k] == vert_lang[l]) {
                            std::rotate(vert_lang.begin(), vert_lang.begin() + l, vert_lang.end());
                            letter_for_encrypted_message = vert_lang[j];
                            cipher_text.push_back(letter_for_encrypted_message);
                            vert_lang = english_alphabet;
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
