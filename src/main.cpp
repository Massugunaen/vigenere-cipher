#include "Encryptor.h"
#include "Decryptor.h"
#include <iostream>
#include <vector>

using namespace std;

std::vector<char>g_eng_lang {{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                              'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}};


int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "usage: <script> <message> <key>" << endl;
        exit(EXIT_FAILURE);
    }

    string plain_text = argv[1];
    string key = argv[2];

    Encryptor encryptor(plain_text, key, g_eng_lang);
    encryptor.encrypt_data();
    string cipher_text = encryptor.get_cipher_text();
    cout << "encrypted result: " << cipher_text << endl;

    Decryptor decryptor(cipher_text, key, g_eng_lang);
    decryptor.decrypt_data();
    string plain_text1 = decryptor.get_plain_text();
    cout << "decrypted result: " << plain_text << endl;

    exit(EXIT_SUCCESS);
}
