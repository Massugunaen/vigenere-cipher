#include "input_data.h"
#include "encrypt_data.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


int main () {
    const std::vector<char> english_language = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l','m', 'n','o', 'p', 
                                                'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    std::vector<char> rotated_english_language = english_language;
    std::cout << "You chose English as working language" << std::endl;
    std::cout << "Supported modes are: -e, --encr" << std::endl;

    std::string chosen_mode = data_input("Choose working mode");
    if (chosen_mode == "-e" || chosen_mode == "--encr") {
        std::cout << "You chose encrypt as working mode" << std::endl;

        std::string imposed_key = data_input("Input your key:");

        std::string imposed_message = data_input("Input your message for encryption:"); 

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
                                std::rotate(rotated_english_language.begin(), rotated_english_language.begin() + l, 
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

        std::cout << "Your encrypted phrase is the following line: ";
        for (size_t i(0); i < encrypted_message.size(); i++) {
            std::cout << encrypted_message[i];
        }
        return EXIT_SUCCESS;
    } 
   // else if (chosen_mode == "-d" || chosen_mode == "--decr") {
   //     std::cout << "You chose decrypting as working mode" << std::endl;
   //     std::vector<char> d_keyWord;
   //     d_keyWord.reserve(0);
   //     std::cout << "Please insert your key, use '.' at the end to stop the process" << std::endl;
   //     char letter_for_keyword;
   //     while (std::cin >> letter_for_keyword) {
   //         if (letter_for_keyword != '.') {
   //             d_keyWord.push_back(letter_for_keyword);
   //         } else {
   //             break;
   //         }
   //     }
   //     d_keyWord.shrink_to_fit();

   //     std::vector<char> message_to_decrypt;
   //     message_to_decrypt.reserve(0);
   //     std::cout << "Please insert your phrase, you want to encrypt use '.' at the end to stop the process"
   //     << std::endl;
   //     char letter_for_message_to_decrypt;
   //     while (std::cin >> letter_for_message_to_decrypt) {
   //         if (letter_for_message_to_decrypt != '.') {
   //             message_to_decrypt.push_back(letter_for_message_to_decrypt);
   //         } else {
   //             break;
   //         }
   //     }
   //     message_to_decrypt.shrink_to_fit();

   //     std::vector<char> decrypted_message;
   //     decrypted_message.reserve(0);

   //     char letter_for_decrypted_message;
   //     int index(0), index1(0);

   //     for (int i = 0; i < message_to_decrypt.size(); i++) {
   //         for (int j = 0; j < english_language.size(); j++) {
   //             if (message_to_decrypt[i] == english_language[j]) {
   //                 for (int k(index); k < d_keyWord.size();) {
   //                     for (int l = 0; l < rotated_english_language.size(); l++) {
   //                         if (d_keyWord[k] == rotated_english_language[l]) {
   //                             std::rotate(rotated_english_language.begin(),
   //                                     rotated_english_language.begin()+l,
   //                                     rotated_english_language.end());
   //                             for (int m(index1); m < message_to_decrypt.size();) {
   //                                 for (int n = 0; n < rotated_english_language.size(); ++n) {
   //                                     if (message_to_decrypt[m] == rotated_english_language[n]) {
   //                                         letter_for_decrypted_message = english_language[n];
   //                                         decrypted_message.push_back(letter_for_decrypted_message);
   //                                     }
   //                                 }
   //                                 if (index1 == (message_to_decrypt.size()-1)) {
   //                                     index1 = 0;
   //                                 } else {
   //                                     index1++;
   //                                 }
   //                                 break;
   //                             }
   //                             rotated_english_language = english_language;
   //                         }
   //                     }
   //                     if (index == (d_keyWord.size()-1)) {
   //                         index = 0;
   //                     } else {
   //                         index++;
   //                     }
   //                     break;
   //                 }
   //             }
   //         }
   //     }
   //     decrypted_message.shrink_to_fit();

   //     std::cout << "Your decrypted phrase is the following line: ";
   //     for (size_t i(0); i < decrypted_message.size(); i++) {
   //         std::cout << decrypted_message[i];
   //     }
   //     return EXIT_SUCCESS;
   // } else {
   // std::cout << "mistake in choosing mode, please try again" << std::endl;
   // //continue;
   // }
}
