#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include "player.h"

class VIRUS1{
    public:
    sf::Sprite virus;
    float xPoz;
    float yPoz;
    
    VIRUS1(float xPoz, float yPoz, sf::Texture &virusTexture){
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

    void virusColide(sf::RectangleShape &player, Start *&sr, bool &isGameMenu, long long &count, long long &prev, long long &best, bool &isBluescreen){
        if(player.getGlobalBounds().intersects(virus.getGlobalBounds())){
            isGameMenu = false;
            delete sr;
            sr = nullptr;

            prev = count;
            if(count > best){
                best = count;
            }
            isBluescreen = true;

            player.setPosition(sf::Vector2f(35000.f, 1950.f));
            sr = new Start();
            isGameMenu = true;
            count = 0;
        }
    }
};