#include "Encryptor.h"


std::string Encryptor::get_cipher_text() { 
	return cipher_text; 
}


Encryptor::Encryptor(std::string plain_text, std::string key, std::vector<char> lang) {
    this->plain_text = plain_text;
    this->key = key;
    this->lang = lang;
    this->encrypt();
}


void Encryptor::encrypt() {
    int intermediate_a {0};
    int intermediate_b {0};

    for (size_t i = 0, j = 0; i < this->plain_text.length(); ++i, j = (j+1) % this->key.length()) {
        intermediate_a = this->convert_to_int(this->plain_text[i]);
        intermediate_b = this->convert_to_int(this->key[j]);
        this->cipher_text.push_back(this->convert_to_char((intermediate_a+intermediate_b) % 26));
    }
}
