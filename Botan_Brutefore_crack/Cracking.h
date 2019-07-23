//
// Created by 55047 on 2019/2/26.
//

#ifndef ASSIGNMENT_5_CRACKING_H
#define ASSIGNMENT_5_CRACKING_H

#include "BruteForce.h"
#include "Hashing.h"
#include <string>
#include <botan/bcrypt.h>

double Cracking_SHA_256(std::string &Hash,const long &time,const std::string::size_type &length);

double Cracking_SHA_256_it(std::string &Hash,const long &time,const std::string::size_type &length,const int &ite);

double Cracking_bcrypt(std::string &Hash,const long &time,const std::string::size_type &length);

std::string Estimate_time(const std::string &hash,const long&time,const std::string::size_type &length,const std::string &mode,const int &ite);
#endif //ASSIGNMENT_5_CRACKING_H
