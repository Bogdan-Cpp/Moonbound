#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include "player.h"

class MB{
    public:
    sf::Sprite motherBoard;
    float xPoz;
    float yPoz;
    
    MB(float xPoz, float yPoz, sf::Texture &mbTexture){
        this->xPoz = xPoz;
        this->yPoz = yPoz;

        if(!mbTexture.loadFromFile("../assets/motherboard1.png")){
            throw std::runtime_error("motherboard texture was not found!");
        }
        this->motherBoard.setTexture(mbTexture);
        motherBoard.setScale(1.6f, 1.7f);
        motherBoard.setPosition(sf::Vector2f(xPoz, yPoz));
    }

    void drawMb(sf::RenderWindow& window){
        window.draw(motherBoard);
    }

    void mbColide(sf::RectangleShape &player, Start *&sr, bool &isGameMenu, long long &count, long long &prev, long long &best, bool &isBluescreen, bool &biosUpdate, bool &windowsUpdate, bool &buildPc){
        if(player.getGlobalBounds().intersects(motherBoard.getGlobalBounds())){
            isGameMenu = false;
            delete sr;
            sr = nullptr;

            prev = count;
            if(count > best){
                best = count;
            }
            isBluescreen = true;

            player.setPosition(sf::Vector2f(100.f, 1950.f));
            sr = new Start();
            isGameMenu = true;
            count = 0;
            biosUpdate = false;
            windowsUpdate = false;
            buildPc = false;
        }
    }
};