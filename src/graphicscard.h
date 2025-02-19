#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include "player.h"

class GPU{
    public:
    sf::Sprite gpu;
    float xPoz;
    float yPoz;
    float rotation;
    
    GPU(float xPoz, float yPoz, float rotation, sf::Texture &gpuTexture){
        this->xPoz = xPoz;
        this->yPoz = yPoz;
        this->rotation = rotation;

        if(!gpuTexture.loadFromFile("../assets/gpu1.png")){
            throw std::runtime_error("ssd texture was not found!");
        }
        this->gpu.setTexture(gpuTexture);
        gpu.setScale(1.4f, 1.4f);
        gpu.setRotation(rotation);
        gpu.setPosition(sf::Vector2f(xPoz, yPoz));
    }

    void drawGpu(sf::RenderWindow& window){
        window.draw(gpu);
    }

    void gpuColide(sf::RectangleShape &player, Start *&sr, bool &isGameMenu, long long &count, long long &prev, long long &best, bool &isBluescreen){
        if(player.getGlobalBounds().intersects(gpu.getGlobalBounds())){
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