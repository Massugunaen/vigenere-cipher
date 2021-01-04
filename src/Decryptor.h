#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#ifndef DECRYPTOR_H
#define DECRYPTOR_H

using namespace std;


class Decryptor {
    private:
        string cipher_text;
        string key;
        string plain_text;
		
        vector<char>lang;

    public:
        Decryptor(string, string, vector<char>);

        void decrypt_data();

        string get_plain_text();
};

#endif
