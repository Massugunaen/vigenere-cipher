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
    
    std::string chosen_mode = recurcive_mode_input();

    std::cout << typeid(ci).name() << '\n';
    
    //if (chosen_mode == "-e") {
    //    std::string imposed_key = argv[2];

    //    std::string imposed_message = argv[3]; 
    //   
    //    encrypting_algorithm(imposed_key, imposed_message, *english_language_ptr);
    //    
    //    return EXIT_SUCCESS;
    //} else if (chosen_mode == "-d") {
    //    std::string imposed_key = argv[2];
    //    
    //    std::string imposed_message = argv[3]; 

    //    decrypting_algorithm(imposed_key, imposed_message, *english_language_ptr);

    //    return EXIT_SUCCESS;
    //}

}

