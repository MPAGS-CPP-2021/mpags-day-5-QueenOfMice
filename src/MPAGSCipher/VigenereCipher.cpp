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
    // loop over each letter in the key
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


std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode mode) const {

    std::string outputText = "";

    // for each letter in input
    for (std::size_t count = 0; count < inputText.size(); count++) {
        // find corresponding letter in key
        // modulo takes care of repeating/trunctating as reuqired
        char lettInKey = key_.at(count%key_.size());

        // find caesar cipher from lookup
        CaesarCipher currCiph = charLookup_.find(lettInKey)->second;

        // get current letter in input as a string and run de/encryption
        std::string currStr = ""; 
        currStr += inputText.at(count);

        // add result to output
        outputText += currCiph.applyCipher(currStr, mode);  
    }
    return outputText;
}

