//
// Created by Hao on 2019/3/16.
//

#ifndef ASSIGNMENT_5_HASHING_H
#define ASSIGNMENT_5_HASHING_H

#include <string>
#include <botan/hash.h>
#include <botan/hex.h>
#include <botan/pwdhash.h>
#include <botan/bcrypt.h>
#include <botan/auto_rng.h>
#include <botan/scrypt.h>

void SHA_256(const std::string &Input, std::string &Output);

void iterated_SHA_256(const std::string &Input, std::string &Output, int rep);

void Bcrypt(const std::string &Password, std::string &Output);

#endif //ASSIGNMENT_5_HASHING_H
