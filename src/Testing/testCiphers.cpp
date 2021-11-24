#define CATCH_CONFIG_MAIN

#include <vector> 

#include "catch.hpp"
#include "Cipher.hpp"
#include "CipherFactory.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

bool testCipher( const Cipher& cipher, const CipherMode mode, const std::string& inputText, const std::string& outputText) {

    std::string testOutputText = cipher.applyCipher(inputText, mode);

    if (testOutputText == outputText) return true;
    else return false;

}

std::vector<std::unique_ptr<Cipher>> inventory = new std::vector<std::unique_ptr<Cipher>>;
inventory->push_back( cipherFactory( CipherTypes::Caesar, 10 ) );
inventory->push_back( cipherFactory( CipherTypes::Playfair, "hello" ) );
inventory->push_back( cipherFactory( CipherTypes::Vigenere, "abc" ) );

std::vector<std::string> in;
in->push_back("HELLOWORLD");
in->push_back("BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING");
in->push_back("ONETESST");

std::vector<std::string> out;
out->push_back("ROVVYGYBVN");
out->push_back("FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA");
out->push_back("OOGTFUSU");

std::cassert (inventory.size() == in.size());
std::cassert (out.size() == in.size());

for (int i = 0; i < inventory.size(), i++) {
    TEST_CASE("test case") {
        REQUIRE (testCipher(inventory->at(i), CipherMode::Encrypt, in->at(i), out->.at(i)));
        REQUIRE (testCipher(inventory->at(i), CipherMode::Decrypt, out->.at(i), in->.at(i)));
    }

}
