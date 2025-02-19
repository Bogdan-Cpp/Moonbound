#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include "player.h"

class Ssd{
    public:
    sf::Sprite ssd;
    float xPoz;
    float yPoz;
    float rotation;
    
    Ssd(float xPoz, float yPoz, sf::Texture &ssdTexture){
        this->xPoz = xPoz;
        this->yPoz = yPoz;

        if(!ssdTexture.loadFromFile("../assets/ssd1.png")){
            throw std::runtime_error("ssd texture was not found!");
        }
        this->ssd.setTexture(ssdTexture);
        ssd.setScale(1.6f, 1.7f);
        ssd.setPosition(sf::Vector2f(xPoz, yPoz));
    }

    void drawSsd(sf::RenderWindow& window){
        window.draw(ssd);
    }

    void ssdColide(sf::RectangleShape &player, Start *&sr, bool &isGameMenu, long long &count, long long &prev, long long &best, bool &isBluescreen){
        if(player.getGlobalBounds().intersects(ssd.getGlobalBounds())){
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
        }
    }
};