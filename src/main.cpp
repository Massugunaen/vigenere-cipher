#include "Encryptor.h"
#include "Decryptor.h"
#include "Lang.h"
#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char *argv[]) {
	if (argc != 4) {
		cout << "usage: <script> <message> <key> <language>" << endl;
		exit(EXIT_FAILURE);
	}

    string plain_text = argv[1];
    string key = argv[2];
    string lang_choice = argv[3];

    Lang lang(lang_choice);   
    vector<char> chosen_language = lang.get_lang();

	Encryptor encryptor(plain_text, key, chosen_language);
	encryptor.encrypt_data();
	string cipher_text = encryptor.get_cipher_text();
	cout << "encrypted result: " << cipher_text << endl;

	Decryptor decryptor(cipher_text, key, chosen_language);
	decryptor.decrypt_data();
	string plain_text1 = decryptor.get_plain_text();
	cout << "decrypted result: " << plain_text << endl;

	exit(EXIT_SUCCESS);

}
