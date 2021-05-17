#include "Encryptor.h"


std::string Encryptor::get_cipher_text() { 
	return cipher_text; 
}


Encryptor::Encryptor(std::string plain_text, std::string key, std::vector<char> lang) {
    this -> plain_text = plain_text;
    this -> key = key;
    this -> lang = lang;
}


void Encryptor::encrypt() {
    int one {0};
    int two {0};

    for (size_t i = 0, j = 0; i < this->plain_text.length(); ++i, j = (j+1) % this->key.length()) {
        one = int(this->plain_text[i]-97);
        two = int(this->key[j]-97);
        this->cipher_text.push_back(char((one + two) % 26 + 97));
    }
}
