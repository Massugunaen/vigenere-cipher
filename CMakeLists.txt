cmake_minimum_required(VERSION 3.14)
project(Vigenere_cipher)

set(CMAKE_CXX_STANDARD 17)

add_executable(Vigenere_cipher vigenere_cipher.cpp testing_decrypting.cpp testing.cpp)