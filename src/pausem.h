#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include "player.h"

class Pause{
    public:
    void drawPause(sf::Font &fStart, sf::RenderWindow &window, float getX){
        sf::View pauseCamera(sf::FloatRect(sf::Vector2f(getX, 540.f), sf::Vector2f(1920.f, 1080.f)));
        sf::Vector2f cameraCenter = pauseCamera.getCenter();
        window.setView(pauseCamera);
        sf::RectangleShape pauseMenu;
        sf::Text resume("Resume(r)", fStart, 30);

        resume.setFillColor(sf::Color::Blue);
        resume.setPosition(sf::Vector2f(500.f, 500.f));
        pauseMenu.setFillColor(sf::Color::Black);
        pauseMenu.setSize(sf::Vector2f(1920.f, 1080.f));
        pauseMenu.setPosition(cameraCenter - sf::Vector2f(960.f, 540.f));

        window.draw(pauseMenu);
        window.draw(resume);
    }
};