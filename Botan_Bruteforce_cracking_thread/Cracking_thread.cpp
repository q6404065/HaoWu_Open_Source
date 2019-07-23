//
// Created by 55047 on 2019/3/16.
//
#include "Cracking_thread.h"
#include <chrono>
#include <ctime>
#include <math.h>
#include <iostream>
#include <thread>
#include <vector>
#include <iterator>
#include <mutex>

ThreadPool::ThreadPool(unsigned num_thread) : pool(num_thread), joiner(pool), done(false) {
    try {
        for (unsigned int i = 0; i < num_thread; ++i) {
            pool.emplace_back(std::thread(&ThreadPool::worker, this));
        }
    } catch (...) {
        done = true;
        throw;
    }
}

ThreadPool::ThreadPool() : ThreadPool(std::thread::hardware_concurrency()) {}


ThreadPool::~ThreadPool() {
    done = true;
}

void ThreadPool::worker() {
    while (!done) {
        std::function<void()> task;
        bool success = queue.pop(task);

        if (!success) {
            std::this_thread::yield();
        } else {
            // Run the function
            task();
        }
    }
}


ThreadPool::ThreadJoiner::ThreadJoiner(std::vector<std::thread> &threads_) : threads(threads_) {}

ThreadPool::ThreadJoiner::~ThreadJoiner() {
    for (auto &i : threads) {
        if (i.joinable()) {
            i.join();
        }
    }
}

void ThreadPool::wait_for_empty() {
    while (!queue.empty()) {
        std::this_thread::yield();
    }
}

// Use bruteforce to check every element.
// Every element needs to be hashed.
// If we find the password, output something to inform
// Assign threads with your computer's core, and it is auto.
// Add thread_pool with average chunk_size, set limit as min of two elements for calculating
// Return number of threads
int Cracking_SHA_256_thread(std::string &Hash, const std::string::size_type &length) {
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()[]{};':<>?";
    std::string Output;
    std::string hash;
    BruteForce bf(alphabet, length);
    auto cores = std::thread::hardware_concurrency();// make number of thread with cores
    double limit = std::min(double(cores * 10000), pow(alphabet.size(), length));// limit is power size of length
    const double chunk_size = limit / cores;
    auto current_position = bf.begin();
    auto endd = bf.begin();
    std::advance(endd, limit);
    ThreadPool pool;
    std::mutex print_lock;
    SHA_256(Hash, hash);
    int task = 0;
    while (current_position != endd) {
        auto begin = current_position;
        std::advance(current_position, chunk_size);
        auto end = current_position;
        pool.submit([begin, &hash, &Hash, end, &Output, &print_lock]() {
            std::lock_guard<std::mutex> lock(print_lock);
            for (auto i = begin; i != end; ++i) {
                SHA_256(*i, Output);
                if (Output == hash) {
                    Hash = "Find it: " + *i;
                    // We do nothing here but it is necessary to simulate this step
                    // Return something
                }
            }
        });
        task++;
//        std::cout << "Thread: " << task << " is running\n";
    }
    pool.wait_for_empty();
    return task;
}


// Add iterated factor.
// Use bruteforce to check every element.
// Every element needs to be hashed.
// If we find the password, output something to inform
// Assign threads with your computer's core, and it is auto.
// Add thread_pool with average chunk_size, set limit as min of two elements for calculating
// Return number of threads
int Cracking_SHA_256_it_thread(std::string &Hash, const std::string::size_type &length, const int &ite) {
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()[]{};':<>?";
    std::string Output;
    std::string hash;
    BruteForce bf(alphabet, length);
    auto cores = std::thread::hardware_concurrency();// make number of thread with cores
    double limit = 0;
    if (ite <= 1000) {
        limit = std::min(double(cores * 100), pow(alphabet.size(), length));// limit is power size of length
    } else if (ite <= 10000) {
        limit = std::min(double(cores * 10), pow(alphabet.size(), length));// limit is power size of length
    } else if (ite <= 100000) {
        limit = std::min(double(cores), pow(alphabet.size(), length));// limit is power size of length
    }
    const double chunk_size = limit / cores;
    auto current_position = bf.begin();
    auto endd = bf.begin();
    std::advance(endd, limit);
    ThreadPool pool;
    std::mutex print_lock;
    iterated_SHA_256(Hash, hash, ite);
    int task = 0;
    while (current_position != endd) {
        auto begin = current_position;
        std::advance(current_position, chunk_size);
        auto end = current_position;
        pool.submit([begin, &hash, &Hash, end, &Output, &print_lock, &ite]() {
            for (auto i = begin; i != end; ++i) {
                std::lock_guard<std::mutex> lock(print_lock);
                iterated_SHA_256(*i, Output, ite);
                if (Output == hash) {
                    Hash = "Find it: " + *i;
                    // We do nothing here but it is necessary to simulate this step
                    // Return something
                }
            }
        });
        task++;
//        std::cout << "Thread: " << task << " is running\n";
    }
    pool.wait_for_empty();
    return task;
}

// Bcrypt is difficult to check if we dont't know this random salt.
// We just use botan function check the bcrypt.
// Use bruteforce to check every element.
// Every element needs to be hashed.
// If we find the password, output something to inform
// Assign threads with your computer's core, and it is auto.
// Add thread_pool with average chunk_size, set limit as min of two elements for calculating
// Return number of threads
int Cracking_bcrypt_thread(std::string &Hash, const std::string::size_type &length) {
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()[]{};':<>?";
    std::string hash;
    BruteForce bf(alphabet, length);
    auto cores = std::thread::hardware_concurrency();// make number of thread with cores
    double limit = std::min(double(cores), pow(alphabet.size(), length));// limit is power size of length
    const double chunk_size = limit / cores;
    auto current_position = bf.begin();
    auto endd = bf.begin();
    std::advance(endd, limit);
    ThreadPool pool;
    std::mutex print_lock;
    Bcrypt(Hash, hash);
    int task = 0;
    while (current_position != endd) {
        auto begin = current_position;
        std::advance(current_position, chunk_size);
        auto end = current_position;
        pool.submit([begin, &hash, &Hash, end, &print_lock]() {
            for (auto i = begin; i != end; ++i) {
                std::lock_guard<std::mutex> lock(print_lock);
                if (Botan::check_bcrypt(*i, hash)) {
                    Hash = "Find it: " + *i;
                    // We do nothing here but it is necessary to simulate this step
                    // Return something
                }
            }
        });
        task++;
//        std::cout << "Thread: " << task << " is running\n";
    }
    pool.wait_for_empty();
    return task;
}

std::string Estimate_time_thread(const std::string &hash, const std::string::size_type &length,
                                 const std::string &mode, const int &ite) {
    long msec;
    std::string Hash;
    auto cores = std::thread::hardware_concurrency();// make number of thread with cores
    if (mode == "SHA-256") {
        SHA_256(hash, Hash);
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        Cracking_SHA_256_thread(Hash, length);
        end = std::chrono::system_clock::now();
        msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        return "SHA-256 length " + std::to_string(length) + " should be cracked: " +
               std::to_string(
                       pow(56, length) / 1000 * double(msec) / std::min(double(10000 * cores), pow(56, length))) + "s";
    } else if (mode == "SHA-256-I") {
        iterated_SHA_256(hash, Hash, ite);
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        Cracking_SHA_256_it_thread(Hash, length, ite);
        end = std::chrono::system_clock::now();
        msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        if (ite <= 1000) {
            return "SHA-256 iterated " + std::to_string(ite) + " length " + std::to_string(length) +
                   " should be cracked: " +
                   std::to_string(
                           pow(56, length) / 1000 * double(msec) / std::min(double(cores * 100), pow(56, length))) +
                   "s";
        } else if (ite <= 10000 && ite > 1000) {
            return "SHA-256 iterated " + std::to_string(ite) + " length " + std::to_string(length) +
                   " should be cracked: " +
                   std::to_string(
                           pow(56, length) / 1000 * double(msec) / std::min(double(10 * cores), pow(56, length))) +
                   "s";
        } else if (ite <= 100000 && ite > 10000) {
            return "SHA-256 iterated " + std::to_string(ite) + " length " + std::to_string(length) +
                   " should be cracked: " +
                   std::to_string(pow(56, length) / 1000 * double(msec) / std::min(double(cores), pow(56, length))) +
                   "s";
        }
    } else if (mode == "Bcrypt") {
        Bcrypt(hash, Hash);
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        Cracking_bcrypt_thread(Hash, length);
        end = std::chrono::system_clock::now();
        msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        return "Bcrypt length " + std::to_string(length) + " should be cracked: " +
               std::to_string(pow(56, length) / 1000 * double(msec) / std::min(double(cores), pow(56, length))) + "s";
    }
    return "No matching mode";
}
