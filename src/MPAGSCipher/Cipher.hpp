#ifndef CIPHER_HPP
#define CIPHER_HPP

#include <string>

#include "CipherMode.hpp"

class Cipher {
    public:
        Cipher() = default;
        Cipher(const Cipher& rhs) = default; // copy constructor
        Cipher(Cipher&& rhs) = default; // move constructor
        Cipher& operator=(const Cipher& rhs) = default; // copy assignment operator
        Cipher& operator=(Cipher&& rhs) = default; // move assignment operator
        virtual ~Cipher() = default; // destructor

        virtual std::string applyCipher( const std::string& input, const CipherMode mode ) const = 0;
};

#endif