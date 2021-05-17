#include "Encryptor.h"
#include "Decryptor.h"
#include <iostream>
#include <vector>

using namespace std;


struct Langs {
    const std::vector<char>english {
        {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
         'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}
    };
} langs;


int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "usage: <script> <message> <key>" << endl;
        exit(EXIT_FAILURE);
    }

    string plain_text = argv[1];
    string key = argv[2];

    Encryptor encryptor(plain_text, key, langs.english);
    std::string encrypted_text = encryptor.get_cipher_text();
    cout << "encrypted result: " << encrypted_text << endl;

    Decryptor decryptor(encrypted_text, key, langs.english);
    string decrypted_text = decryptor.get_plain_text();
    cout << "decrypted result: " << decrypted_text << endl;

    exit(EXIT_SUCCESS);
}
