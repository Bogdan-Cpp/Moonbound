#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include "player.h"

class Pause{
    public:
    void drawPause(sf::Font &fPause, sf::RenderWindow &window, float getX){
        sf::View pauseCamera(sf::FloatRect(sf::Vector2f(getX, 540.f), sf::Vector2f(1920.f, 1080.f)));
        sf::Vector2f cameraCenter = pauseCamera.getCenter();
        window.setView(pauseCamera);
        sf::RectangleShape pauseMenu;
        sf::Text title("Settings", fPause, 30);

        title.setFillColor(sf::Color::Blue);
        title.setPosition(sf::Vector2f(1300.f, 540.f));
        pauseMenu.setFillColor(sf::Color::Black);
        pauseMenu.setSize(sf::Vector2f(1920.f, 1080.f));
        pauseMenu.setPosition(cameraCenter - sf::Vector2f(960.f, 540.f));

        window.draw(pauseMenu);
        window.draw(title);
    }
};