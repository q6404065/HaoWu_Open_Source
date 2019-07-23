//
// Created by 55047 on 2019/2/12.
//
#include <vector>
#include "Hashing.h"
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

// With standard PasswordHashFamily, create a PBKDF2 temple
// const reference every input to mini memory
// *out as new 256 memory and delete it in the end to mini memory
// Controlled every input is string and size_t to simplify the user action

void PBKDF2(const std::string &Password, const std::string &Salt, std::string &Output, const size_t &out_len,
            const size_t &it) {
    std::vector<uint8_t> salt = hex_decode(Salt);
    auto *out = new uint8_t[256];
    std::unique_ptr<PasswordHashFamily> hash1(PasswordHashFamily::create("PBKDF2(SHA-256)"));
    hash1->from_params(it)->derive_key(out, out_len, &Password[0], Password.size(), &salt[0], salt.size());
    Output = hex_encode(out, out_len);
    out = nullptr;
    delete[] out;
}

// Use Autoseeded_RNG to create a random rng
// 12 rounds, a modes
// Password and Output is reference to mini memory
// The output should be the random after third $
void Bcrypt(const std::string &Password, std::string &Output) {
    AutoSeeded_RNG rng;
    Output = generate_bcrypt(Password, rng);
}

// As a general recommendation, use N=32768, r=8, p=1
// Just run the void function scrypt because it can apply the NRP
// Use const reference and delete to mini memory
void Scrypt(const std::string &Password, const std::string &Salt, std::string &Output, const size_t &out_len,
            const size_t &N, const size_t &R, const size_t &P) {
    std::vector<uint8_t> salt = hex_decode(Salt);
    auto *out = new uint8_t[256];
    scrypt(out, out_len, Password, &salt[0], salt.size(), N, R, P);
    Output = hex_encode(out, out_len);
    out = nullptr;

    delete[] out;
}
