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

        inline int convert_to_int(const char a) { return int(a - 97); }
        inline char convert_to_char(const int a) { return char(a + 97); }

        void decrypt();

    public:
        Decryptor(std::string, std::string, std::vector<char>);

        std::string get_plain_text();
};

#endif
