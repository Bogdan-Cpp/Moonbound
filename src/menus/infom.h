#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

class Info{
    public:
    void infoButton(MenuS &menuStart, bool &isStartMenu, bool &isInfoButton, bool &canPressButton){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::T) && canPressButton){
            isStartMenu = false;
            isInfoButton = true;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !canPressButton){
            isInfoButton = false;
            isStartMenu = true;
            canPressButton = true;
        }
    }
    
    void infoMenuDraw(sf::RenderWindow& window, sf::Font fStart){
        sf::Text info("in working...", fStart, 50);

        info.setFillColor(sf::Color::White);
        info.setPosition(sf::Vector2f(500.f, 500.f));

        window.draw(info);
    }
};