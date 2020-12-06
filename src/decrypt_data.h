#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


class Decryptor {
    private:
        std::string cipher_text;
        std::string key;
        std::string plain_text;

		// availabe languages
		std::vector<char>english_alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 
			'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    public:
        void decrypt_data();

        std::string get_plain_text() { return plain_text; }

        Decryptor(std::string, std::string);
};


Decryptor::Decryptor(std::string plain_text, std::string key) {
    this -> cipher_text = cipher_text;
    this -> key = key;
}


void Decryptor::decrypt_data() {
	std::string key = this -> key;
	std::string cipher_text = this -> cipher_text;

    std::vector<char> rotated_english_language = this->english_alphabet;

    char letter_for_decrypted_message;
    int index = 0, index1 = 0;

    for (int i = 0; i < cipher_text.size(); i++) {
        for (int j = 0; j < english_alphabet.size(); j++) {
            if (cipher_text[i] == english_alphabet[j]) {
                for (int k = 0; k < key.size();) {
                    for (int l = 0; l < rotated_english_language.size(); l++) {
                        if (key[k] == rotated_english_language[l]) {
                            std::rotate(rotated_english_language.begin(), rotated_english_language.begin() + l, rotated_english_language.end());
                            for (int m = index1; m < cipher_text.size();) {
                                for (int n = 0; n < rotated_english_language.size(); ++n) {
                                    if (cipher_text[m] == rotated_english_language[n]) { 
                                        letter_for_decrypted_message = english_alphabet[n];
                                        this->plain_text.push_back(letter_for_decrypted_message);
                                    }
                                }
                                if (index1 == (cipher_text.size() - 1)) {
                                    index1 = 0;
                                } else {
                                    index1++;
                                }
                                break;
                            }
                            rotated_english_language = english_alphabet;
                        }
                    }
                    if (index == (key.size() - 1)) {
                        index = 0;
                    } else {
                        index++;
                    }
                    break;
                }
            }
        }
    }

}

