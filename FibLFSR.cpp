// "Copyright 2025 <Ansh Patel>"

#include "FibLFSR.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>
#include <bitset>

// Constructor
PhotoMagic::FibLFSR::FibLFSR(const std::string& seed) {
    // Checks the length of seed
    if (seed.size() > 16) {
        throw std::invalid_argument("Seed cannot be greater than 16");
    }
    // Check if the seed is negative
    if (seed[0] == '-') {
        throw std::invalid_argument("Seed cannot be negative");
    }
    // Check if the seed has any other character other than 0 or 1
    for (char c : seed) {
        if (c != '0' && c != '1') {
            throw std::invalid_argument("Seed must be a binary string");
        }
    }
    this->seed = seed;
}

// Optional constructor with unsigned int as seed
PhotoMagic::FibLFSR::FibLFSR(unsigned int seed) {
    // Check for negative value
    if (seed < 0) {
        throw std::invalid_argument("Seed cannot be negative");
    }
    // Convert the unsigned int to binary
    std::bitset<16> binary(seed);
    this->seed = binary.to_string();
}

// Function to generate the next bit
int PhotoMagic::FibLFSR::step() {
    // Convert the seed to an integer and XOR to get the new bit
    int result = (seed[0]-'0') ^ (seed[2]-'0') ^ (seed[3]-'0') ^ (seed[5]-'0');
    // Update the seed by shifting
    for (size_t i = 1; i < seed.size(); ++i) {
        seed[i -1] = seed[i];
    }
    // Update the rightmosr bit with a new bit
    seed[seed.size() - 1] = result+'0';
    return result;
}

// Calls step k times
int PhotoMagic::FibLFSR::generate(int k) {
    // Check if k is negative
    if (k < 0) {
        throw std::invalid_argument("k is greater than the seed length");
    }
    int result = 0;
    for (int i = 0; i < k; i++) {
        int newBit = step();
        // Shifts to left and adds a new bit
        result = result*2 + newBit;
    }
    return result;
}

// Overloading insertion operator
std::ostream& PhotoMagic::operator<<(std::ostream& out, const PhotoMagic::FibLFSR& lfsr) {
    out << lfsr.getSeed();
    return out;
}
