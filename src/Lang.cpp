#include "Lang.h"


std::string Encryptor::get_cipher_text() {
	return cipher_text;
}


Encryptor::Encryptor(std::string plain_text, std::string key) {
    this -> plain_text = plain_text;
    this -> key = key;
}
