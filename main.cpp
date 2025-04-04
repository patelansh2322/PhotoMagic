// "Copyright 2025 <Ansh Patel>"

#include <iostream>
#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(int argc, char* argv[]) {
    // Take inputs from command line
    std::string input_file = argv[1];
    std::string output_file = argv[2];
    std::string seed = argv[3];

    // Load the image file
    sf::Image img;
    if (!img.loadFromFile(input_file)) {
        return 1;
    }

    // Create a copy display original vs encrypted
    sf::Image imgCopy = img;

    // Determine if the seed is a number or a binary string
    bool isInt = true;
    for (char c : seed) {
        if (!isdigit(c)) {
            isInt = false;
            break;
        }
    }

    // Initialize the lfsr object and the transform method
    PhotoMagic::FibLFSR lfsr = isInt ?  // Ternary operator
    PhotoMagic::FibLFSR(std::stoul(seed)) : PhotoMagic::FibLFSR(seed);  // True : False
    PhotoMagic::transform(imgCopy, &lfsr);

    // Save the encrypted image in the image copy
    if (!imgCopy.saveToFile(output_file)) {
        return 1;
    }

    // Create a texture out of the original image
    sf::Texture texture;
    if (!texture.loadFromImage(img)) {
        return 1;
    }

    // Use the texture to create a sprite to display
    sf::Sprite originalSprite;
    originalSprite.setTexture(texture);
    originalSprite.setPosition(0, 0);

    // Create a texture out of the encrypted image
    sf::Texture transformedTexture;
    if (!transformedTexture.loadFromImage(imgCopy)) {
        return 1;
    }

    // Use the texture to create a sprite to display
    sf::Sprite transformedSprite;
    transformedSprite.setTexture(transformedTexture);
    transformedSprite.setPosition(texture.getSize().x + 10, 0);

    // Initialize length and width of the display window
    int x = texture.getSize().x*2+10;
    int y = texture.getSize().y+50;
    // Create the window
    sf::RenderWindow window(sf::VideoMode(x, y), "PhotoMagic");

    // Load font to print text on window
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return 1;
    }

    // Create text object to display input file name
    sf::Text inputText(input_file, font, 20);
    inputText.setFillColor(sf::Color::White);
    inputText.setPosition(10, texture.getSize().y + 10);

    // Create text object to display output file name
    sf::Text outputText(output_file, font, 20);
    outputText.setFillColor(sf::Color::White);
    outputText.setPosition(texture.getSize().x + 20, texture.getSize().y + 10);

    // Initialize the window
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window and display the sprites and texts
        window.clear();
        window.draw(originalSprite);
        window.draw(transformedSprite);
        window.draw(inputText);
        window.draw(outputText);
        window.display();
    }

    return 0;
}
