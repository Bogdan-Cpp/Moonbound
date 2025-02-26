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
    
    VIRUS1(float xPoz, float yPoz, float width, float height, sf::Texture &virusTexture, sf::Texture &virusTexture2){
        int texture = std::rand() % 2;
        this->xPoz = xPoz;
        this->yPoz = yPoz;
        this->width = width;
        this->height = height;
        
        switch(texture){
            case 0:
            if(!virusTexture.loadFromFile("../assets/virus.png")){
                throw std::runtime_error("virus texture was not found!");
            }
            this->virus.setTexture(virusTexture);
            break;

            case 1:
            if(!virusTexture2.loadFromFile("../assets/virus2.png")){
                throw std::runtime_error("virus texture was not found!");
            }
            this->virus.setTexture(virusTexture2);
            break;
        }
        
        
        virus.setScale(width, height);
        virus.setPosition(sf::Vector2f(xPoz, yPoz));
    }

    void drawVirus(sf::RenderWindow& window){
        window.draw(virus);
    }

    void virusColide(sf::RectangleShape &player, Start *&sr, bool &isGameMenu, long long &count, long long &prev, long long &best, bool &isBluescreen, float &playerSize, int &stage){
        if(player.getGlobalBounds().intersects(virus.getGlobalBounds())){
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
            stage = 0;
        }
    }
};