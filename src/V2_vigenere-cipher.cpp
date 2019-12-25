#include "input_data.h"
#include "encrypt_data.h"
#include "decrypt_data.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


int main () {
    std::vector<char> english_language = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l','m', 'n','o', 'p', 
                                                'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    std::vector<char> *english_language_ptr = &english_language;
    std::cout << "Your working language is English" << std::endl;
    
    std::cout << "Choose working mode\nSupported modes are: -e, --encr || -d, --decr" << std::endl;
    std::string chosen_mode = Rdata_input();
    
    //better make mode input through recursion input
    if (chosen_mode == "-e" || chosen_mode == "--encr") {
        std::cout << "You chose encrypting mode" << std::endl;

        std::string imposed_key = data_input("Input your key:");

        std::string imposed_message = data_input("Input your message:"); 
       
        encrypting_algorithm(imposed_key, imposed_message, *english_language_ptr);
        
        return EXIT_SUCCESS;

    } else if (chosen_mode == "-d" || chosen_mode == "--decr") {
        std::cout << "You chose decrypting mode" << std::endl;
        
        std::string imposed_key = data_input("Input your prediction key:");

        std::string imposed_message = data_input("Input your message:"); 


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
    } else {
    std::cout << "Mistake in choosing mode, please try again" << std::endl;
        EXIT_FAILURE;
    }
}
