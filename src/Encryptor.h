#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

using namespace std;


class Encryptor {
    private:
        string plain_text;
        string key;
        string cipher_text;
		
        vector<char>lang;

    public:
        Encryptor(string, string, vector<char>);

        void encrypt_data();

        string get_cipher_text();
};

#endif
