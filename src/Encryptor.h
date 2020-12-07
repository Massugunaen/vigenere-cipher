#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H


class Encryptor {
    private:
        std::string plain_text;
        std::string key;
        std::string cipher_text;
		
        std::vector<char>lang;

    public:
        Encryptor(std::string, std::string, std::vector<char>);

        void encrypt_data();

        std::string get_cipher_text();
};

#endif
