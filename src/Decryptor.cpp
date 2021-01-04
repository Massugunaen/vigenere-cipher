#include "Decryptor.h"


string Decryptor::get_plain_text() { 
	return plain_text; 
}


Decryptor::Decryptor(string cipher_text, string key, vector<char> lang) {
    this -> cipher_text = cipher_text;
    this -> key = key;
    this -> lang = lang;
}


void Decryptor::decrypt_data() {
    vector<char> vert_lang = lang;
	
    char letter_for_decrypted_message;
    int index = 0, index1 = 0;

    for (int i = 0; i < cipher_text.size(); i++) {
        for (int j = 0; j < lang.size(); j++) {
            if (cipher_text[i] == lang[j]) {
                for (int k = 0; k < key.size();) {
                    for (int l = 0; l < vert_lang.size(); l++) {
                        if (key[k] == vert_lang[l]) {
                            rotate(vert_lang.begin(), vert_lang.begin() + l, vert_lang.end());
                            for (int m = index1; m < cipher_text.size();) {
                                for (int n = 0; n < vert_lang.size(); ++n) {
                                    if (cipher_text[m] == vert_lang[n]) { 
                                        letter_for_decrypted_message = lang[n];
                                        plain_text.push_back(letter_for_decrypted_message);
                                    }
                                }
                                if (index1 == (cipher_text.size() - 1)) {
                                    index1 = 0;
                                } else {
                                    index1++;
                                }
                                break;
                            }
                            vert_lang = lang;
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
