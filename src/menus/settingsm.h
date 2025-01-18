#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

class Settings{
    public:
    void settingsButton(MenuS *&menuStart, bool &isSettingsMenu, bool &isStartMenu, bool &isInfoButton, bool &canPressButton){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R) && canPressButton){
            isStartMenu = false;
            isInfoButton = false;
            isSettingsMenu = true;

            delete menuStart;
            menuStart = nullptr;

            canPressButton = false;
        }
    }
    
    void settingsMenuDraw(sf::RenderWindow& window, sf::Font fStart){
        sf::Text info("in working..", fStart, 50);
        info.setFillColor(sf::Color::White);
        info.setPosition(sf::Vector2f(500.f, 500.f));

        window.draw(info);
    }
};