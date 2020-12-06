#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


class Decryptor {
    private:
        std::string cipher_text;
        std::string key;
        std::string plain_text;

		// temp singular language 
		std::vector<char>english_alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 
			'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    public:
        void decrypt_data();

        std::string get_plain_text();

        Decryptor(std::string, std::string);
};
