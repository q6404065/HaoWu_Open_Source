//
// Created by Hao on 2019/3/16.
//

#include "Cracking.h"
#include <chrono>
#include <ctime>
#include <math.h>
#include <iostream>


// Use bruteforce to check every element.
// Every element needs to be hashed.
// If we find the password, output something to inform
// Use wall time easy to control cracking time.
// Return cracking number. If it doesn't work, return 0.
void Cracking_SHA_256(std::string &Hash, const std::string::size_type &length) {
    const std::string alphabet = "!@#$%^&*()-_=+[{]}|;:,<.>/?";
    std::string Output;
    BruteForce bf(alphabet, length);
    for (auto i = bf.begin(); i != bf.end(); i++) {
        SHA_256(*i, Output);
        if (Output == Hash) {
            Hash = *i;
            return;
            // We find password
        }
    }
    Hash = "We don't find it";
}

void Cracking_SHA_256_salt(std::string &Hash, const std::string salt, const std::string::size_type &length) {
    std::cout << "SHA-256 with salt cracking is running: \n";
    int num = 0;
    const std::string alphabet = "!@#$%^&*()-_=+";
    std::string Output;
    BruteForce bf(alphabet, length);
    for (auto i = bf.begin(); i != bf.end(); i++) {
        SHA_256(salt + (*i), Output);
        if (Output == Hash) {
            std::cout << "Correct password is: " << *i << "\n";
            return;
            // We find password
        }
        if (num % 1000000 == 0) {
            std::cout << "Current cracking is: " << *i << "\n";
        }
        num++;
    }
    Hash = "We don't find it";
}

void Cracking_bcrypt(std::string &Hash,
                     const std::string::size_type &length) {
    std::cout << "Bcrypt cracking running\n";
    int num = 0;
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string Output;
    BruteForce bf(alphabet, length);
    for (auto i = bf.begin(); i != bf.end(); i++) {
        if (Botan::check_bcrypt(*i, Hash)) {
            std::cout << "Correct password is: " << *i << "\n";
            return;
            // We find password
        }
        if (num % 10000 == 0) {
            std::cout << "Current cracking is: " << *i << "\n";
        }
        num++;
    }
    Hash = "We don't find it";
}
