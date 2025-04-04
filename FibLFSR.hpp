// "Copyright 2025 <Ansh Patel>"

#pragma once

#include <iostream>
#include <string>

namespace PhotoMagic {
class FibLFSR {
 public:
    explicit FibLFSR(const std::string& seed);
    explicit FibLFSR(unsigned int seed);  // Optional

    static FibLFSR fromPassword(const std::string& password);  // Optional

    int step();
    int generate(int k);
    const std::string& getSeed() const { return seed; }  // Get Seed
 private:
    std::string seed;
};

std::ostream& operator<<(std::ostream& out, const FibLFSR& lfsr);
}  // namespace PhotoMagic
