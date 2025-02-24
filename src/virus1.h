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
    float width;
    float height;
    
    VIRUS1(float xPoz, float yPoz, float width, float height, sf::Texture &virusTexture){
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

    void virusColide(sf::RectangleShape &player, Start *&sr, bool &isGameMenu, long long &count, long long &prev, long long &best, bool &isBluescreen, float &playerSize){
        if(player.getGlobalBounds().intersects(virus.getGlobalBounds())){
            isGameMenu = false;
            delete sr;
            sr = nullptr;

            prev = count;
            if(count > best){
                best = count;
            }
            isBluescreen = true;

            player.setPosition(sf::Vector2f(70000.f, 1950.f));
            sr = new Start();
            isGameMenu = true;
            count = 0;
            playerSize = 50.f;
        }
    }
};