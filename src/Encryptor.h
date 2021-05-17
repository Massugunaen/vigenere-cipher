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

        inline int convert_to_int(const char a) { return int(a - 97); }
        inline char convert_to_char(const int a) { return char(a + 97); }

        void encrypt();

    public:
        Encryptor(std::string, std::string, std::vector<char>);

        std::string get_cipher_text();
};

#endif
