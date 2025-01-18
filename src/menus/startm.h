#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

class Start{
    public:
    void startButton(MenuS *&menuStart, sf::Music *&startMusic, bool &isStartMenu, bool &isStartGame, bool &isSettingsMenu, bool &isInfoButton, bool &canPressButton){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && canPressButton){
            isStartMenu = false;
            isSettingsMenu = false;
            isInfoButton = false;
            isStartGame = true;
        
            delete menuStart;
            delete startMusic;
            menuStart = nullptr;
            startMusic = nullptr;

            canPressButton = false;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !canPressButton){
            isStartGame = false;
            isStartMenu = true;
            canPressButton = true;
                
            menuStart = new MenuS();
        }
    }
};