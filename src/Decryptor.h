#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#ifndef DECRYPTOR_H
#define DECRYPTOR_H


class Decryptor {
    private:
        std::string cipher_text;
        std::string key;
        std::string plain_text;
		
        std::vector<char>lang;

    public:
        Decryptor(std::string, std::string, std::vector<char>);

        void decrypt_data();

        std::string get_plain_text();
};

#endif
