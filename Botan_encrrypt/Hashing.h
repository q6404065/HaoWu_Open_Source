//
// Created by 55047 on 2019/2/12.
//
#ifndef ASSIGNMENT_4_HASHING_H
#define ASSIGNMENT_4_HASHING_H

#include <string>
#include <botan/hash.h>
#include <botan/hex.h>
#include <botan/pwdhash.h>
#include <botan/bcrypt.h>
#include <botan/auto_rng.h>
#include <botan/scrypt.h>

void SHA_256(const std::string &Input, std::string &Output);

void iterated_SHA_256(const std::string &Input, std::string &Output, int rep);

void PBKDF2(const std::string &Password, const std::string &Salt, std::string &Output, const size_t &out_len,
            const size_t &it);

void Bcrypt(const std::string &Password, std::string &Output);

void Scrypt(const std::string &Password, const std::string &Salt, std::string &Output, const size_t &out_len,
            const size_t &N, const size_t &R, const size_t &P);

#endif //ASSIGNMENT_4_HASHING_H


