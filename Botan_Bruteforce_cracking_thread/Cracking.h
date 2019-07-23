//
// Created by Hao on 2019/3/16.
//

#ifndef ASSIGNMENT_5_CRACKING_H
#define ASSIGNMENT_5_CRACKING_H

#include "Bruteforce.h"
#include "Hashing.h"
#include <string>
#include <botan/bcrypt.h>

void Cracking_SHA_256(std::string &Hash, const std::string::size_type &length);

void Cracking_bcrypt(std::string &Hash, const std::string::size_type &length);

void Cracking_SHA_256_salt(std::string &Hash, const std::string salt, const std::string::size_type &length);

#endif //ASSIGNMENT_5_CRACKING_H
