//
// Created by Hao on 2019/3/16.
//

#ifndef ASSIGNMENT_5_BRUTEFORCE_H
#define ASSIGNMENT_5_BRUTEFORCE_H

#include <iterator>
#include <string>
#include <mutex>

class BruteForceIterator {
public:

    using iterator_category = std::forward_iterator_tag;
    using value_type = std::string;
    using difference_type = size_t;
    using pointer = std::string *;
    using reference = std::string &;

    BruteForceIterator(std::string alphabet, std::string::size_type length, bool at_end = false);

    bool operator==(const BruteForceIterator &other) const;

    bool operator!=(const BruteForceIterator &other) const;

    const std::string &operator*() const;

    BruteForceIterator &operator++();

    BruteForceIterator &operator++(int);

private:

    void goto_end_of_sequence();

    bool at_end_of_sequence();

    void goOntoTheNextOneAlready();

    std::string::size_type length;
    std::string alphabet;
    std::string element;
    std::string::size_type element_index;
    std::string::size_type alphabet_index;
    bool at_end;
};

class BruteForce {
public:
    BruteForce(std::string alphabet, std::string::size_type length);

    BruteForceIterator begin() const;

    BruteForceIterator end() const;

private:
    const std::string alphabet;
    const std::string::size_type length;
};


#endif //ASSIGNMENT_5_BRUTEFORCE_H
