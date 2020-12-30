#include "Encryptor.h"
#include "Decryptor.h"
#include "Lang.h"
#include <iostream>
#include <vector>


int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cout << "usage: <script> <message> <key> <language>" << std::endl;
		std::exit(EXIT_FAILURE);
	}

    std::string plain_text = argv[1];
    std::string key = argv[2];
    std::string lang_choice = argv[3];

    Lang lang(lang_choice);   
    std::vector<char> chosen_language = lang.get_lang();

	Encryptor encryptor(plain_text, key, chosen_language);
	encryptor.encrypt_data();
	std::string cipher_text = encryptor.get_cipher_text();
	std::cout << "encrypted result: " << cipher_text << std::endl;

	Decryptor decryptor(cipher_text, key, chosen_language);
	decryptor.decrypt_data();
	std::string plain_text1 = decryptor.get_plain_text();
	std::cout << "decrypted result: " << plain_text << std::endl;

	std::exit(EXIT_SUCCESS);

}
