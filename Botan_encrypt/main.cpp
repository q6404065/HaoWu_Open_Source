#include <iostream>
#include <string>
#include "Hashing.h"
#include <chrono>
#include <ctime>

int main() {

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    std::string input;
    input = "ABCD";
    std::string output;
    for(int i=0;i<100;i++) {
        SHA_256(input, output);
    }
    end = std::chrono::system_clock::now();
    std::cout << "SHA-256: " << output<<"\nrunning time is :"<<std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()/100<<"ns\n";

    start = std::chrono::system_clock::now();
    iterated_SHA_256(input, output, 100);
    end = std::chrono::system_clock::now();
    std::cout << "SHA-256 100th iterate: " << output<< "\n100 iterate running time is :"
    <<std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()<<"ns\n";

    size_t out_len = 48;
    size_t it = 10000;
    std::string Output;
    start = std::chrono::system_clock::now();
    PBKDF2("xyz", "0001020304050607", Output, out_len, it);
    end = std::chrono::system_clock::now();
    std::cout <<"PBKDF2: "<<Output<<"\n10000 iterate running time is :"
                          <<std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()<<"ms\n";

    std::string Output_;
    start = std::chrono::system_clock::now();
    Bcrypt("616263", Output_);
    end = std::chrono::system_clock::now();
    std::cout <<"Bcrypt: "<< Output_ <<"\nrunning time is :"
                         <<std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()<<"ms\n";

    std::string Output__;
    start = std::chrono::system_clock::now();
    for(int i=0;i<100;i++) {
        Scrypt("", "", Output__, 128, 16, 1, 1);
    }
    end = std::chrono::system_clock::now();
    std::cout <<"Scrypt: " <<Output__<<"\nrunning time is :"
                        <<std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()/100<<"ns\n";
}