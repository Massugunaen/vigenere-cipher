#include "Encryptor.h"
#include "Decryptor.h"
#include <iostream>
#include <vector>


int main(int argc, char *argv[]) {
	if (argc != 3) {
		std::cout << "usage <script> <message> <key>" << std::endl;
		std::exit(EXIT_FAILURE);
	}

    std::string plain_text = argv[1];
    std::string key = argv[2];

	Encryptor encryptor(plain_text, key);
	encryptor.encrypt_data();
	std::string cipher_text = encryptor.get_cipher_text();
	std::cout << "encrypted result: " << cipher_text << std::endl;


	Decryptor decryptor(cipher_text, key);
	decryptor.decrypt_data();
	std::string plain_text1 = decryptor.get_plain_text();
	std::cout << "decrypted result: " << plain_text << std::endl;

	std::exit(EXIT_SUCCESS);

}
