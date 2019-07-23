//
// Created by 55047 on 2019/3/16.
//

#ifndef FINAL_PROJECT_SHAREQUEUE_H
#define FINAL_PROJECT_SHAREQUEUE_H

#include <queue>
#include <mutex>

template<typename T>
class SharedQueue {
public:
    void push(T item);

    bool pop(T &item);

    bool empty() const;

private:
    std::queue<T> items;
    mutable std::mutex lock;
};

// Definitions
template<typename T>
void SharedQueue<T>::push(T item) {
    std::lock_guard<std::mutex> guard(lock);
    items.push(item);
}

template<typename T>
bool SharedQueue<T>::pop(T &item) {
    std::lock_guard<std::mutex> guard(lock);

    if (items.empty()) {
        return false;
    }

    item = std::move(items.front());
    items.pop();

    return true;
}

template<typename T>
bool SharedQueue<T>::empty() const {
    std::lock_guard<std::mutex> guard(lock);

    return items.empty();
}

#endif //FINAL_PROJECT_SHAREQUEUE_H
