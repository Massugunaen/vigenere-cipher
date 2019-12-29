#include "input_data.h"
#include "encrypt_data.h"
#include "decrypt_data.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


int main (int argc, char *argv[]) {
    std::vector<char> english_language = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                                          'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    std::vector<char> *english_language_ptr = &english_language;
    
    std::cout << "English is operatable" << std::endl;
    std::cout << "Available modes: -e | -d" << std::endl;
    std::string chosen_mode = recurcive_mode_input();
    
    if (chosen_mode == "encrypting") {
        std::string imposed_key = data_input("Input your key:");

        std::string imposed_message = data_input("Input your message:"); 
       
        encrypting_algorithm(imposed_key, imposed_message, *english_language_ptr);
        
        return EXIT_SUCCESS;

    } else if (chosen_mode == "decrypting") {
        std::string imposed_key = data_input("Input your prediction key:");
        
        std::string imposed_message = data_input("Input your message:"); 

        decrypting_algorithm(imposed_key, imposed_message, *english_language_ptr);

        return EXIT_SUCCESS;
    }

}

