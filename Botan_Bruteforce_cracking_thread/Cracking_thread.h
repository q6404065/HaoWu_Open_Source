//
// Created by 55047 on 2019/3/16.
//

#ifndef FINAL_PROJECT_CRACKING_THREAD_H
#define FINAL_PROJECT_CRACKING_THREAD_H

#include <atomic>
#include <functional>
#include <thread>
#include <vector>
#include "Bruteforce.h"
#include "Hashing.h"
#include <string>
#include "SharedQueue.h"
#include <memory>
#include <mutex>

int Cracking_SHA_256_thread(std::string &Hash, const std::string::size_type &length);

int Cracking_SHA_256_it_thread(std::string &Hash, const std::string::size_type &length, const int &ite);

int Cracking_bcrypt_thread(std::string &Hash, const std::string::size_type &length);

std::string Estimate_time_thread(const std::string &hash, const std::string::size_type &length, const std::string &mode,
                                 const int &ite);

class ThreadPool {
public:
    explicit ThreadPool(unsigned num_thread);

    ThreadPool();

    ~ThreadPool();

    template<typename FunctionType>
    void submit(FunctionType f);

    void wait_for_empty();

private:

    void worker();

    class ThreadJoiner {
    public:
        explicit ThreadJoiner(std::vector<std::thread> &threads);

        ~ThreadJoiner();

    private:
        std::vector<std::thread> &threads;
    };

    std::vector<std::thread> pool;
    SharedQueue<std::function<void()>> queue;
    std::atomic_bool done;

    // The ThreadJoiner must appear after the pool and queue
    ThreadJoiner joiner;

};

// Definition

template<typename FunctionType>
void ThreadPool::submit(FunctionType f) {
    queue.push(std::function<void()>(f));
}


#endif //FINAL_PROJECT_CRACKING_THREAD_H
