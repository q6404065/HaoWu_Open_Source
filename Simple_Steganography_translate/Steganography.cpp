// Builded by Hao Wu, DU ID 973405636
// Date: 05-10-2018
// C++ is Hellllllllllllll;

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

std::string read_file(std::string filename);

std::string encode_char(std::string block, char payload);

char decode_char(std::string block);

int find_boundary(std::string message, int start);

std::string encode_string(std::string message, std::string payload);

std::string decode_string(std::string message);

std::string read_file(std::string filename);

void write_file(std::string filename, std::string message);


int main() {
    std::string payload;
    std::string message;
    std::string New_message;
    std::string pay_message;
    try {
        payload = read_file("payload.txt");
    } catch (std::runtime_error e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    try {
        message = read_file("textbook.txt");
    } catch (std::runtime_error e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    try {
        New_message = encode_string(message, payload);
    } catch (std::runtime_error e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    try {
        write_file("New_text.txt", New_message);
    } catch (std::runtime_error e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    try {
        pay_message = read_file("New_text.txt");
    } catch (std::runtime_error e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    try {
        std::cout << decode_string(pay_message) << "\n";
    } catch (std::runtime_error e) {
        std::cout << "Error: " << e.what() << "\n";
    }
    return 0;
}


std::string encode_char(std::string block, char payload) {
    int length = block.length();
    unsigned current = 0;
    int ASCI = 0;
    int i = 0;
    int remianing = 8;
    while (remianing > 0) {
        if ((current >= length) | length < 8) {
            throw std::runtime_error("Above the length or length is lower than Eight");
        }
        if ((current < length) & (std::isalpha(block[current]) == 0)) {
            current++;
            i++;
        } else if (std::isalpha(block[current]) != 0) {
            remianing--;
            current++;
        }
        ASCI = payload;
        unsigned ASCII = ASCI;
        if (((unsigned{ASCII} >> (7 + i - current)) & 1) == 1) {
            block[current] = std::toupper(block[current]);
        } else {
            block[current] = std::tolower(block[current]);
        }
    }
    return block;
}

char decode_char(std::string block) {
    int remianing = 8;
    int length = block.length();
    int current = 0;
    int ret = 0;
    int i = 0;
    while (remianing > 0) {
        if (length < 8) {
            throw std::runtime_error("length is lower than Eight");
        }
        if ((current < length) & (std::isalpha(block[current]) == 0)) {
            current++;
            i++;
        } else if (std::isalpha(block[current]) != 0) {
            remianing--;
            current++;
        }
        if ((std::isupper(block[current]) != 0)) {
            ret += 1 << (7 + i - current);
        }

    }
    return ret;
}

int find_boundary(std::string message, int start) {
    int offset = 0;
    int remaining = 8;
    int i = 0;
    while (remaining > 0) {
        if ((start + offset) >= message.length()) {
            return -1;
        } else if ((std::isalpha(message[start + offset])) != 0) {
            remaining--;
            offset++;
        } else if ((std::isalpha(message[start + offset])) == 0) {
            offset++;
        }
    }
    return offset;
}

std::string encode_string(std::string message, std::string payload) {
    std::string ret = "";
    std::string block = "";
    int start = 0;
    int start_2 = 0;
    unsigned long length = payload.length();
    for (int i = 0; i < length; i++) {
        int block_length = find_boundary(message, start);
        if (block_length == -1) {
            throw std::runtime_error("length is not enough");
        }
        block = message.substr(start, block_length);
        ret += encode_char(block, payload[i]);
        start += block_length;
    }
    int block_length = find_boundary(message, start);
    if (block_length == -1) {
        throw std::runtime_error("length is not enough");
    }
    block = message.substr(start, block_length);
    ret += encode_char(block, '\0');
    std::string remainder = "\n" + message;
    ret += remainder;
    return ret;
}

void write_file(std::string filename, std::string message) {
    std::ofstream out(filename);

    if (!out.is_open()) {
        throw std::runtime_error("Failed to open file for writing");
    }

    out << message;

    out.close();
}

std::string decode_string(std::string message) {
    std::string ret = "";
    int start = 0;
    for (;;) {
        int block_length = find_boundary(message, start);
        std::string block = message.substr(start, block_length);
        char c;
        c = decode_char(block);
        if (c == '\0') {
            break;
        }
        ret += c;
        start += block_length;
        if (block_length == -1) {
            throw std::runtime_error("Don't have enough space to make a block");
        }

    }
    return ret;
}

std::string read_file(std::string filename) {
    std::string ret;

    std::ifstream in(filename);

    if (!in.is_open()) {
        throw std::runtime_error("Couldn't open file");
    }

    while (!in.eof()) {
        char c = in.get();

        if (in.gcount() != 1) {
            break;
        }
        ret += c;
    }
    in.close();

    return ret;
}