#include "Bat.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pong", sf::Style::Default);
    int score = 0;
    int lives = 3;

    Bat bat(1920/2, 1080 - 20);

    sf::Text hud;
    sf::Font font;
    font.loadFromFile("../fonts/DS-DIGIT.TTF");
    hud.setFont(font);
    hud.setCharacterSize(75);

    hud.setFillColor(sf::Color::White);
    hud.setPosition(20,20);

    sf::Clock clock;
    while (window.isOpen())
    {
    // Handle Player Input Section
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Q)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                bat.moveLeft();
            else
                bat.stopLeft();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                bat.moveRight();
            else
                bat.stopRight();
        }
    // Update the bat, the ball, and hud
        sf::Time dt = clock.restart();
        bat.update(dt);
        std::stringstream ss;
        ss << "Score: " << score << "\nLives: " << lives;
        hud.setString(ss.str());

    // Draw the bat, ball, hud
        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.display();
    }
    return 0;
}
