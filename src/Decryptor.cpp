#include "Decryptor.h"


std::string Decryptor::get_plain_text() { 
	return plain_text; 
}


Decryptor::Decryptor(std::string cipher_text, std::string key, std::vector<char> lang) {
    this->cipher_text = cipher_text;
    this->key = key;
    this->lang = lang;
    this->decrypt();
}

void Decryptor::decrypt() {
    int intermediate_a {0};
    int intermediate_b {0};

    for (size_t i = 0, j = 0; i < this->cipher_text.length(); ++i, j = (j+1) % this->key.length()) {
        intermediate_a = this->convert_to_int(this->cipher_text[i]);
        intermediate_b = this->convert_to_int(this->key[j]);
        this->plain_text.push_back(this->convert_to_char((intermediate_a - intermediate_b + 26) % 26));
    }
}
