#include "encrypt_data.h"
#include "decrypt_data.h"
#include <iostream>
#include <vector>
#include <string>
#include <array>


int main(int argc, char *argv[]) {
	if (argc != 3) {
		std::cout << "usage <script> <message> <key>" << std::endl;
		std::exit(EXIT_FAILURE);
	}

    std::string plain_text = argv[1];
    std::string key = argv[2];

	Encryptor encryptor(plain_text, key);

	encryptor.encrypt_data();

	std::cout << encryptor.get_cipher_text() << std::endl;

	std::exit(EXIT_SUCCESS);

}
