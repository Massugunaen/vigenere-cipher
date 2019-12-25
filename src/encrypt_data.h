#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


void encrypting_algorithm(std::string imposed_key, std::string imposed_message, 
        std::vector<char> english_language) {
    
    std::vector<char> rotated_english_language = english_language;

    std::vector<char> encrypted_message;
    encrypted_message.reserve(0);

    char letter_for_encrypted_message;
    int index(0);
    
    for (int i = 0; i < imposed_message.length(); i++) {
            for (int j = 0; j < english_language.size(); j++) {
                if (imposed_message[i] == english_language[j]) {
                    for (int k(index); k < imposed_key.length();) {
                        for (int l = 0; l < rotated_english_language.size(); l++) {
                            if (imposed_key[k] == rotated_english_language[l]) {
                                std::rotate(rotated_english_language.begin(),
                                        rotated_english_language.begin() + l, 
                                        rotated_english_language.end());
                                letter_for_encrypted_message = rotated_english_language[j];
                                encrypted_message.push_back(letter_for_encrypted_message);
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
        encrypted_message.shrink_to_fit();

        std::cout << "Your encrypted result: ";
        for (size_t i(0); i < encrypted_message.size(); i++) {
            std::cout << encrypted_message[i];
        }

}

