#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include "player.h"

class VIRUS2{
    public:
    sf::Sprite virus;
    float xPoz;
    float yPoz;
    
    VIRUS2(float xPoz, float yPoz, sf::Texture &virusTexture){
        this->xPoz = xPoz;
        this->yPoz = yPoz;

        if(!virusTexture.loadFromFile("../assets/virus.png")){
            throw std::runtime_error("virus texture was not found!");
        }
        this->virus.setTexture(virusTexture);
        virus.setScale(0.1f, 0.1f);
        virus.setPosition(sf::Vector2f(xPoz, yPoz));
    }

    void drawVirus(sf::RenderWindow& window){
        window.draw(virus);
    }

    void virusColide(sf::RectangleShape &player, Start *&sr, bool &isGameMenu, long long &count, long long &prev, long long &best, bool &isBluescreen, float &playerSize){
        if(player.getGlobalBounds().intersects(virus.getGlobalBounds())){
            int choose = std::rand() % 3;

            switch(choose){
                case 0: playerSize += 1.f; break;
                case 1: playerSize += 1.f; break;
                case 2: playerSize += 1.f; break;
            }
        }
    }
};