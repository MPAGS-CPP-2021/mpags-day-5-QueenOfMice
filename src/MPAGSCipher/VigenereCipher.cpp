#include "VigenereCipher.hpp"

#include <algorithm>
#include <iostream> // can remove later xxx XXX TODO
#include <string> 


void VigenereCipher::setKey( const std::string& key ) {
    key_ = key;
    // Make sure the key is upper case
    std::transform(std::begin(key_), std::end(key_), std::begin(key_),
                   ::toupper);

    // Remove non-alphabet characters
    key_.erase(std::remove_if(std::begin(key_), std::end(key_),
                              [](char c) { return !std::isalpha(c); }),
               std::end(key_));

    // Check if the key is empty and replace with default if so
    if (key_ == "") {
        // xxx hardcoded default here -- better have this elsewhere or fine?
        key_ = "KEY";
    }
    // loop over key
    for (char& c : key_) {
        // find letter pos in alph
        auto it = find(Alphabet::alphabet.begin(), Alphabet::alphabet.end(), c);
        int index = -1;
 
        // If element was found
        if (it != Alphabet::alphabet.end())
        {
            index = it - Alphabet::alphabet.begin();
        }
        else {
            // If the element is not present in the vector
            std::cout << "Error: letter not present in alphabeth" << std::endl;
            break;
        }

        // create caesar cipher using this pos as key
        CaesarCipher cipher(index);

        // insert std::pair of letter and caes ciph into lookup
        charLookup_.insert(std::make_pair(c, cipher));
        
    }
}


VigenereCipher::VigenereCipher(const std::string& key) {
    this->setKey(key);
}


std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode /*cipherMode*/ ) const {

    // for each letter in input

        // find corr letter in key
        // repeating/trunctating as reuqired
        // find caes ciph from lookup
        // run de/en cryption
        // add result to output

    std::string outputText{inputText};
    return outputText;
}

