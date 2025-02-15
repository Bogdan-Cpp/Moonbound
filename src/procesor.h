#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include "player.h"

class CPU{
    public:
    sf::Sprite cpu;
    float xPoz;
    float yPoz;
    
    CPU(float xPoz, float yPoz, sf::Texture &cpuTexture){
        this->xPoz = xPoz;
        this->yPoz = yPoz;

        if(!cpuTexture.loadFromFile("../assets/cpu1.png")){
            throw std::runtime_error("ssd texture was not found!");
        }
        this->cpu.setTexture(cpuTexture);
        cpu.setScale(1.6f, 1.7f);
        cpu.setPosition(sf::Vector2f(xPoz, yPoz));
    }

    void drawCpu(sf::RenderWindow& window){
        window.draw(cpu);
    }

    void cpuColide(sf::RectangleShape &player, Start *&sr, bool &isGameMenu, long long &count, long long &prev, long long &best, bool &isBluescreen){
        if(player.getGlobalBounds().intersects(cpu.getGlobalBounds())){
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