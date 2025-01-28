#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include "player.h"

class Ssd{
    public:
    sf::RectangleShape ssd;
    float xPoz;
    float yPoz;
    
    Ssd(float xPoz, float yPoz){
        this->xPoz = xPoz;
        this->yPoz = yPoz;

        ssd.setFillColor(sf::Color::Green);
        ssd.setSize(sf::Vector2f(20.f, 40.f));
        ssd.setPosition(sf::Vector2f(xPoz, yPoz));
    }

    void drawSsd(sf::RenderWindow& window){
        window.draw(ssd);
    }

    void ssdColide(sf::RectangleShape &player, Start *&sr, bool &isGameMenu, long long &count, long long &prev, long long &best){
        if(player.getGlobalBounds().intersects(ssd.getGlobalBounds())){
            isGameMenu = false;
            delete sr;
            sr = nullptr;

            prev = count;
            if(count > best){
                best = count;
            }
            
            player.setPosition(sf::Vector2f(100.f, 1950.f));
            sr = new Start();
            isGameMenu = true;
            count = 0;
        }
    }
};