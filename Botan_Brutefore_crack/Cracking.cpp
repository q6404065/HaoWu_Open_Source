//
// Created by 55047 on 2019/2/26.
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
double Cracking_SHA_256(std::string &Hash, const long &time,
                        const std::string::size_type &length) {
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()[]{};':<>?";
    std::string Output;
    BruteForce bf(alphabet, length);
    auto it = bf.begin();
    std::chrono::time_point<std::chrono::system_clock> start, end;
    int num = 0;
    start = std::chrono::system_clock::now();
    for (;;) {
        SHA_256(*it, Output);
        num++;
        if (Output == Hash) {
            Hash = "The step: " + std::to_string(num) + " found password is " + *it;
            // We do nothing here but it is necessary to simulate this step
            // Return something
        }
        it++;
        end = std::chrono::system_clock::now();
        if (num % 1000 == 0) {
            if (std::chrono::duration_cast<std::chrono::seconds>(end - start).count() >= time) {
                return num;
            }
        }
        if (std::chrono::duration_cast<std::chrono::seconds>(end - start).count() <= time&&it==bf.end()){
            it=bf.begin();
        }
    }
}

// Add iterated factor.
// Use bruteforce to check every element.
// Every element needs to be hashed.
// If we find the password, output something to inform
// Use wall time easy to control cracking time.
// Return cracking number. If it doesn't work, return 0.
double Cracking_SHA_256_it(std::string &Hash, const long &time,
                           const std::string::size_type &length, const int &ite) {
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()[]{};':<>?";
    std::string Output;
    BruteForce bf(alphabet, length);
    auto it = bf.begin();
    std::chrono::time_point<std::chrono::system_clock> start, end;
    int num = 0;
    start = std::chrono::system_clock::now();
    for (;;) {
        iterated_SHA_256(*it, Output, ite);
        num++;
        if (Output == Hash) {
            Hash = "The step: " + std::to_string(num) + " found password is " + *it;
            // It is necessary to simulate this step
            // Return something
        }
        it++;
        end = std::chrono::system_clock::now();
        if (ite >= 10000) {
            if (std::chrono::duration_cast<std::chrono::seconds>(end - start).count() >= time) {
                return num;
            } else if (std::chrono::duration_cast<std::chrono::seconds>(end - start).count() < time && it == bf.end()) {
                return 0;
            }
        }
        if (ite < 10000 && num % 10 == 0) {
            if (std::chrono::duration_cast<std::chrono::seconds>(end - start).count() >= time) {
                return num;
            } else if (std::chrono::duration_cast<std::chrono::seconds>(end - start).count() < time && it == bf.end()) {
                return 0;
            }
        }
    }
}

// Bcrypt is difficult to check if we dont't know this random salt.
// We just use botan function check the bcrypt.
// Use bruteforce to check every element.
// Every element needs to be hashed.
// If we find the password, output something to inform
// Use wall time easy to control cracking time.
// Return cracking number. If it doesn't work, return 0.
double Cracking_bcrypt(std::string &Hash, const long &time,
                       const std::string::size_type &length) {
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()[]{};':<>?";
    std::string Output;
    BruteForce bf(alphabet, length);
    auto it = bf.begin();
    std::chrono::time_point<std::chrono::system_clock> start, end;
    int num = 0;
    start = std::chrono::system_clock::now();
    for (;;) {
        num++;
        if (Botan::check_bcrypt(*it, Hash)) {
            Hash = "The step: " + std::to_string(num) + " found password is " + *it;
            // It is necessary to simulate this step
            // Return something
        }
        it++;
        end = std::chrono::system_clock::now();
        if (std::chrono::duration_cast<std::chrono::seconds>(end - start).count() >= time) {
            return num;
        } else if (std::chrono::duration_cast<std::chrono::seconds>(end - start).count() < time && it == bf.end()) {
            it=bf.begin();
        }
    }
}

std::string Estimate_time(const std::string &hash, const long &time, const std::string::size_type &length,const std::string &mode,const int &ite) {
    double num;
    std::string Hash;
    if(mode=="SHA-256") {
        SHA_256(hash, Hash);
        num = (double(time) / Cracking_SHA_256(Hash, time, length)) * pow(56, length);
        return "SHA-256 length "+ std::to_string(length)+ " should be cracked: "+ std::to_string(num)+ "s";
    } else if(mode=="SHA-256-I"){
        iterated_SHA_256(hash, Hash,ite);
        num = (double(time) / Cracking_SHA_256_it(Hash, time, length,ite)) * pow(56, length);
        return "SHA-256 iterated "+std::to_string(ite)+" length "+std::to_string(length)+ " should be cracked: "+ std::to_string(num)+ "s";
    } else if(mode=="Bcrypt"){
        Bcrypt(hash,Hash);
        num = (double(time) / Cracking_bcrypt(Hash, time, length)) * pow(56, length);
        return "Bcrypt length "+ std::to_string(length)+ " should be cracked: "+ std::to_string(num)+ "s";
    }
    return "No matching mode";
}
