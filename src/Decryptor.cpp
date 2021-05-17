#include "Decryptor.h"


std::string Decryptor::get_plain_text() { 
	return plain_text; 
}


Decryptor::Decryptor(std::string cipher_text, std::string key, std::vector<char> lang) {
    this -> cipher_text = cipher_text;
    this -> key = key;
    this -> lang = lang;
}


void Decryptor::decrypt() {
    int one {0};
    int two {0};

    for (size_t i = 0, j = 0; i < this->cipher_text.length(); ++i, j = (j+1) % this->key.length()) {
        one = int(this->cipher_text[i]-97);
        two = int(this->key[j]-97);
        this->plain_text.push_back(char((one - two + 26) % 26 + 97));
    }
}
