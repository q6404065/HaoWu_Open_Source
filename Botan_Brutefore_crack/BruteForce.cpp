//
// Created by 55047 on 2019/2/26.
//

#include "BruteForce.h"

BruteForceIterator::BruteForceIterator(std::string alphabet_, std::string::size_type length_, bool at_end_)
        : length(length_), alphabet(std::move(alphabet_)), element(),
          alphabet_index(0), element_index(length_ - 1), at_end(at_end_) {
    std::string::size_type initial = 0;
    if (at_end) {
        initial = alphabet.length() - 1;
    }
    for (int i = 0; i < length ; ++i) {
        element += alphabet[initial];
    }
}

void BruteForceIterator::goOntoTheNextOneAlready() {
    // Can only advance if not at end of sequence
    if (at_end_of_sequence()) {
        return;
    }

    ++alphabet_index;
    if (alphabet_index == alphabet.length()) {
        // Move element_index and reset to end
        while (element[element_index] == alphabet.back()) {
            if (element_index == 0) {
                // Have gone through entire sequence
                // Setup as end of sequence
                goto_end_of_sequence();
                return;
            }
            // otherwise go to next char
            --element_index;
        }

        // Increment char at element[element_index];
        auto alpha_idx = alphabet.find(element[element_index]);
        element[element_index] = alphabet[alpha_idx + 1];

        for (auto i = element_index + 1; i < element.length(); ++i) {
            element[i] = alphabet[0];
        }

        // Reset
        element_index = length - 1;
        alphabet_index = 0;
    } else {
        // Update char at element_index
        element[element_index] = alphabet[alphabet_index];
    }
}

void BruteForceIterator::goto_end_of_sequence() {
    // Setup sentinel value for end of sequence
    at_end = true;
}

bool BruteForceIterator::at_end_of_sequence() {
    // Check if we are in sentinel position set by
    // goto_end_of_sequence
    return at_end;
}

bool BruteForceIterator::operator==(const BruteForceIterator &other) const {
    // All three of at_end, element, and alphabet must be the same
    if (at_end != other.at_end) {
        return false;
    }
    if (element != other.element) {
        return false;
    }
    if (alphabet != other.alphabet) {
        return false;
    }
    return true;
}

bool BruteForceIterator::operator!=(const BruteForceIterator &other) const {
    return !(*this == other);
}

const std::string &BruteForceIterator::operator*() const {
    return element;
}

BruteForceIterator &BruteForceIterator::operator++() {
    goOntoTheNextOneAlready();
    return *this;
}

BruteForceIterator &BruteForceIterator::operator++(int) {
    goOntoTheNextOneAlready();
    return *this;
}


BruteForce::BruteForce(std::string alphabet_, std::string::size_type length_)
        : alphabet(std::move(alphabet_)), length(length_) {}

BruteForceIterator BruteForce::begin() const {
    return BruteForceIterator(alphabet, length);
}

BruteForceIterator BruteForce::end() const {
    bool at_end = true;
    return BruteForceIterator(alphabet, length, at_end);
}
