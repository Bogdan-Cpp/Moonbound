#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

class Start{
    public:
    void startButton(MenuS &menuStart, sf::Music *&startMusic, bool &isStartMenu, bool &isStartGame, bool &isInfoButton, bool &canPressButton){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && canPressButton){
            isStartMenu = false;
            isInfoButton = false;
            isStartGame = true;
            canPressButton = false;
        
            delete startMusic;
            startMusic = nullptr;
        }
    }
};