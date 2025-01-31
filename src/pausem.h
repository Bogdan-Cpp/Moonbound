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
        sf::RectangleShape pauseMenu;
        sf::Text title("Settings", fPause, 50);
        sf::Text resume("Resume(z)", fPause, 40);
        sf::Text music("Change Music:\n-moon(1)\n-happy(2)", fPause, 30);

        window.setView(pauseCamera);

        title.setFillColor(sf::Color::White);
        title.setPosition(sf::Vector2f(getX + 840.f, 540.f));
        
        pauseMenu.setFillColor(sf::Color::Black);
        pauseMenu.setSize(sf::Vector2f(1920.f, 1080.f));
        pauseMenu.setPosition(cameraCenter - sf::Vector2f(960.f, 540.f));

        resume.setFillColor(sf::Color::White);
        resume.setPosition(sf::Vector2f(getX + 870.f, 1500.f));

        music.setFillColor(sf::Color(120.f, 120.f, 120.f));
        music.setPosition(sf::Vector2f(getX + 100.f, 700.f));

        window.draw(pauseMenu);
        window.draw(title);
        window.draw(resume);
        window.draw(music);
    }
};