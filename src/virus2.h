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
    float width;
    float height;
    
    VIRUS2(float xPoz, float yPoz, float width, float height, sf::Texture &virusTexture){
        this->xPoz = xPoz;
        this->yPoz = yPoz;
        this->width = width;
        this->height = height;

        if(!virusTexture.loadFromFile("../assets/virus.png")){
            throw std::runtime_error("virus texture was not found!");
        }
        this->virus.setTexture(virusTexture);
        virus.setScale(width, height);
        virus.setPosition(sf::Vector2f(xPoz, yPoz));
    }

    void drawVirus(sf::RenderWindow& window){
        window.draw(virus);
    }

    void virusColide(sf::RectangleShape &player, Start *&sr, bool &isGameMenu, long long &count, long long &prev, long long &best, bool &isBluescreen, int &stage){
        if(player.getGlobalBounds().intersects(virus.getGlobalBounds())){
            int choose = std::rand() % 3;

            switch(choose){
                case 0: stage = 1; break;
                case 1: stage = 2; break;
            }
        }
    }
};