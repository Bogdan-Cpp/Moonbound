#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include "player.h"

class Level{
    public:
    void level1(int &x, sf::Texture &gpuTexture, std::vector<GPU> &graphics, sf::Texture &cpuTexture, std::vector<CPU> &centralUnit, long long &count, std::vector<MB> &motherboard, sf::Texture &mbTexture){
        int prev = 0;
        int random = x;
        int level1;
        int obstacle;
        int yRandom;
    
        for(int i = 0; i <= 20; i++){
            obstacle = std::rand() % 4;
        
            switch(obstacle){
                case 0:
                motherboard.push_back(MB(random, 1920, mbTexture));
                break;

                case 1:
                motherboard.push_back(MB(random, 1920, mbTexture));
                break;

                case 2:
                motherboard.push_back(MB(random, 1920, mbTexture));
                break;
            
                case 3:
                graphics.push_back(GPU(random, 1920, 0, gpuTexture));
                centralUnit.push_back(CPU(random + 50, 1945, cpuTexture));
                break;
            }
            level1 = std::rand() % 5;
            prev = x;
            x = random;

            switch(level1){
                case 0:
                prev += 600;
                x += 400;
                break;
               
                case 1:
                prev += 560;
                x += 480;
                break;

                case 2:
                prev += 490;
                x += 560;
                break;
               
                case 3:
                prev += 670;
                x += 460;
                break;

                case 4:
                prev += 580;
                x += 400;
                break;
            }
            if(x > prev){random = prev + (std::rand() % (x - prev + 1));}
            else{random = prev;}
        }
    }

    void level2(std::vector<Ssd> &storage2, int &x, sf::Texture &ssdTexture, sf::Texture &gpuTexture, std::vector<GPU> &graphics2, sf::Texture &cpuTexture, std::vector<CPU> &centralUnit2, long long &count, std::vector<MB> &motherboard2, sf::Texture &mbTexture){
        int prev = 0;
        x = 17000;
        int random = x;
        int level1;
        int obstacle;
        int yRandom;
        int positionType;
    
        for(int i = 0; i <= 100; i++){
            obstacle = std::rand() % 4;
        
            switch(obstacle){
                case 0:
                motherboard2.push_back(MB(random, 1920, mbTexture));
                break;

                case 1:
                motherboard2.push_back(MB(random, 1920, mbTexture));
                break;

                case 2:
                graphics2.push_back(GPU(random, 1920, 0, gpuTexture));
                break;
            
                case 3:
                centralUnit2.push_back(CPU(random + 50, 1945, cpuTexture));
                break;
            }
            level1 = std::rand() % 5;
            prev = x;
            x = random;

            switch(level1){
                case 0:
                prev += 200;
                x += 340;
                break;
               
                case 1:
                prev += 140;
                x += 360;
                break;

                case 2:
                prev += 240;
                x += 240;
                break;
               
                case 3:
                prev += 200;
                x += 460;
                break;

                case 4:
                prev += 580;
                x += 370;
                break;

                case 5:
                prev += 600;
                x += 400;
                break;
               
                case 6:
                prev += 560;
                x += 480;
                break;

                case 7:
                prev += 490;
                x += 560;
                break;
               
                case 8:
                prev += 670;
                x += 460;
                break;

                case 9:
                prev += 580;
                x += 400;
                break;
            }
            if(x > prev){random = prev + (std::rand() % (x - prev + 1));}
            else{random = prev;}

            if(random - x < 70){
                random += 100;
            }
        }
    }
};