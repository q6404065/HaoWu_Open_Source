//
// Created by 55047 on 2019/2/26.
//

#include "Hashing.h"
#include <vector>
#include <iostream>
#include <string>

using namespace Botan;

// As example of Botan library
// Function 'create' creates SHA-256 temple
// Output is equal to string type of std::vector<uint8_t>
void SHA_256(const std::string &Input, std::string &Output) {
    std::unique_ptr<HashFunction> hash1(HashFunction::create("SHA-256"));
    Output = hex_encode(hash1->process(Input));
}

// Iterated SHA-256
// rep is the number of the Iterated.
// Simple loop to iterate itself
// Controlled rep >0
void iterated_SHA_256(const std::string &Input, std::string &Output, int rep) {
    if (rep > 0) {
        std::unique_ptr<HashFunction> hash1(HashFunction::create("SHA-256"));
        Output = hex_encode(hash1->process(Input));
        for (int i = 0; i < rep - 1; i++) {
            Output = hex_encode(hash1->process(Output));
        }
    } else {
        return;
    }
}

// Use Autoseeded_RNG to create a random rng
// 12 rounds, a modes
// Password and Output is reference to mini memory
// The output should be the random after third $
void Bcrypt(const std::string &Password, std::string &Output) {
    AutoSeeded_RNG rng;
    Output = generate_bcrypt(Password, rng);
}
