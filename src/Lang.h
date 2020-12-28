#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#ifndef LANG_H
#define LANG_H


class Lang {
    private:
        std::string lang_choice;

        std::vector<char>english_alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

        std::vector<char>requested_language;

    public:
        Lang(std::string);

        std::vector<char> get_lang();
};

#endif
