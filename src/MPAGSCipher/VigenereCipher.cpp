#include "VigenereCipher.hpp"

#include <algorithm>
#include <string> 


void VigenereCipher::setKey( const std::string& key ) {
    key_ = key;
}


VigenereCipher::VigenereCipher(const std::string& key) {
    this->setKey(key);
}


std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode /*cipherMode*/ ) const {
    // Create the output string, initially a copy of the input text
    std::string outputText{inputText};
    return outputText;
}

