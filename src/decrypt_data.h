#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


void decrypting_algorithm(std::string imposed_key, std::string imposed_message, 
        std::vector<char> english_language) {

    std::vector<char> rotated_english_language = english_language;

    std::vector<char> decrypted_message;
    decrypted_message.reserve(0);

    char letter_for_decrypted_message;
    int index(0), index1(0);

    for (int i = 0; i < imposed_message.size(); i++) {
        for (int j = 0; j < english_language.size(); j++) {
            if (imposed_message[i] == english_language[j]) {
                for (int k(index); k < imposed_key.size();) {
                    for (int l = 0; l < rotated_english_language.size(); l++) {
                        if (imposed_key[k] == rotated_english_language[l]) {
                            std::rotate(rotated_english_language.begin(),
                                    rotated_english_language.begin()+l,
                                    rotated_english_language.end());
                            for (int m(index1); m < imposed_message.size();) {
                                for (int n = 0; n < rotated_english_language.size(); ++n) {
                                    if (imposed_message[m] == rotated_english_language[n]) {
                                        letter_for_decrypted_message = english_language[n];
                                        decrypted_message.push_back(letter_for_decrypted_message);
                                    }
                                }
                                if (index1 == (imposed_message.size()-1)) {
                                    index1 = 0;
                                } else {
                                    index1++;
                                }
                                break;
                            }
                            rotated_english_language = english_language;
                        }
                    }
                    if (index == (imposed_key.size()-1)) {
                        index = 0;
                    } else {
                        index++;
                    }
                    break;
                }
            }
        }
    }

    decrypted_message.shrink_to_fit();

    std::cout << "Your decrypted result: ";
    for (size_t i(0); i < decrypted_message.size(); i++) {
        std::cout << decrypted_message[i];
    }

}

