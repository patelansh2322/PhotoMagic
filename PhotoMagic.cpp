// "Copyright 2025 <Ansh Patel>"

#include <iostream>
#include "PhotoMagic.hpp"
#include "FibLFSR.hpp"
#include <SFML/Graphics.hpp>

void PhotoMagic::transform(sf::Image& img, PhotoMagic::FibLFSR* lfsr) {
    // Run loop to get X and Y coordinates of each pixels
    for (unsigned int x = 0; x < img.getSize().x; ++x) {
        for (unsigned int y = 0; y < img.getSize().y; ++y) {
            // Get the pixel color
            sf::Color c = img.getPixel(x, y);
            // Manipulate the rgb components
            c.r ^= lfsr->generate(8);
            c.g ^= lfsr->generate(8);
            c.b ^= lfsr->generate(8);
            // Set the new pixel color
            img.setPixel(x, y, c);
        }
    }
}
