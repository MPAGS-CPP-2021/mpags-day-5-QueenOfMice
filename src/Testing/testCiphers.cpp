#define CATCH_CONFIG_MAIN

#include <cassert>
#include <vector> 

#include "catch.hpp"
#include "Cipher.hpp"
#include "CipherFactory.hpp"
#include "CipherType.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

bool testCipher( const Cipher& cipher, const CipherMode mode, const std::string& inputText, const std::string& outputText) {

    std::string testOutputText = cipher.applyCipher(inputText, mode);

    if (testOutputText == outputText) return true;
    else return false;

}

TEST_CASE("test case for de and encryption of various cipher types") {

    std::vector<std::unique_ptr<Cipher>> inventory;
    inventory.push_back(cipherFactory( CipherType::Caesar, "10" ));
    inventory.push_back(cipherFactory( CipherType::Playfair, "hello" ));
    inventory.push_back(cipherFactory( CipherType::Vigenere, "abc" ));

    std::vector<std::pair<std::string, std::string>> teststrings; 
    teststrings.push_back(std::make_pair("HELLOWORLD", "ROVVYGYBVN"));
    teststrings.push_back(std::make_pair("BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA"));
    teststrings.push_back(std::make_pair("ONETESST", "OOGTFUSU"));


    assert(teststrings.size() == inventory.size());

    for (std::size_t i = 0; i < inventory.size(); i++) {
        REQUIRE(testCipher(*inventory.at(i), CipherMode::Encrypt, teststrings.at(i).first, teststrings.at(i).second));
        REQUIRE(testCipher(*inventory.at(i), CipherMode::Decrypt, teststrings.at(i).second, teststrings.at(i).first));
    }

}
// ?) version 2 - why does the following implementation not work..?
// create a map of cipher, input string and output string

/*
TEST_CASE("test case for de and encryption of various cipher types - version 2") {
    std::map <std::unique_ptr<Cipher>, std::pair<std::string, std::string>> inventory { 
        {cipherFactory( CipherType::Caesar, "10" ), std::make_pair ("HELLOWORLD", "ROVVYGYBVN")},
        {cipherFactory( CipherType::Playfair, "hello" ), std::make_pair ("BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA")},
        {cipherFactory( CipherType::Vigenere, "abc" ), std::make_pair ("ONETESST", "OOGTFUSU")},
    };

    for (std::map <std::unique_ptr<Cipher>, std::pair<std::string, std::string>>::iterator it = inventory.begin(); it != inventory.end(); it++) {
        auto cc = it->first;
        auto val = it->second;
        std::string in = val.first;  
        std::string out = val.second;  

        // run tests
        REQUIRE (testCipher(it.first, CipherMode::Encrypt, in, out));
        REQUIRE (testCipher(it.first, CipherMode::Decrypt, out, in));
    }
}
*/
