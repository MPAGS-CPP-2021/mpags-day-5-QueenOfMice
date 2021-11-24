#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

bool testCipher( const Cipher& cipher, const CipherMode mode, const std::string& inputText, const std::string& outputText) {

    std::string testOutputText = cipher.applyCipher(inputText, mode);

    if (testOutputText == outputText) return true;
    else return false;

}


TEST_CASE("Caesar Cipher encryption and decryption", "[caesar]") {
  CaesarCipher cc{10};
  const std::string inCae = "HELLOWORLD";
  const std::string outCae = "ROVVYGYBVN";
  REQUIRE (testCipher(cc, CipherMode::Encrypt, inCae, outCae));
  REQUIRE (testCipher(cc, CipherMode::Decrypt, outCae, inCae));
}

TEST_CASE("Playfair Cipher encryption and decryption", "[playfair]") {
  PlayfairCipher cc{"hello"};
  const std::string inPlayf = "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING";
  const std::string outPlayf = "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA";
  REQUIRE (testCipher(cc, CipherMode::Encrypt, inPlayf, outPlayf));
  REQUIRE (testCipher(cc, CipherMode::Decrypt, outPlayf, inPlayf));
}

TEST_CASE("Vigenere Cipher encryption and decryption", "[vigenere]") {
  VigenereCipher cc{"abc"};
  const std::string inVig = "1Te!sSt;";
  const std::string outVig = "OOGTFUSU";
  REQUIRE (testCipher(cc, CipherMode::Encrypt, inVig, outVig));
  REQUIRE (testCipher(cc, CipherMode::Decrypt, outVig, "ONETESST"));
}