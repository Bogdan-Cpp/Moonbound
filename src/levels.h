#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include <vector>
#include "player.h"
#include "virus1.h"

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
                case 0: motherboard.push_back(MB(random, 1920, mbTexture)); break;
                case 1: motherboard.push_back(MB(random, 1920, mbTexture)); break;
                case 2: motherboard.push_back(MB(random, 1920, mbTexture)); break;
            
                case 3:
                graphics.push_back(GPU(random, 1920, 0, gpuTexture));
                centralUnit.push_back(CPU(random + 50, 1945, cpuTexture));
                break;
            }
            level1 = std::rand() % 5;
            prev = x;
            x = random;

            switch(level1){
                case 0: prev += 600; x += 400; break;
                case 1: prev += 560; x += 480; break;
                case 2: prev += 490; x += 560; break;
                case 3: prev += 670; x += 460; break;
                case 4: prev += 580; x += 400; break;
            }
            if(x > prev){random = prev + (std::rand() % (x - prev + 1));}
            else{random = prev;}
        }
    }

    void level2(std::vector<Ssd> &storage2, int &x, sf::Texture &ssdTexture, sf::Texture &gpuTexture, std::vector<GPU> &graphics2, sf::Texture &cpuTexture, std::vector<CPU> &centralUnit2, long long &count, std::vector<MB> &motherboard2, sf::Texture &mbTexture){
        x = 17500;
        int obstacle;
        int position;
        int random = x;
        int remember = 0;

        for(int i = 0; i <= 50; i++){
            obstacle = std::rand() % 3;

            switch(obstacle){
                case 0: storage2.push_back(Ssd(random, 1940, ssdTexture)); break;
                case 1: graphics2.push_back(GPU(random, 1920, 0, gpuTexture)); break;
                case 2: graphics2.push_back(GPU(random, 1910, 90, gpuTexture)); break;
            }
            position = std::rand() % 2;
            
            switch(position){
                case 0: random += 300; break;
                case 1: random += 350; break;
                case 2: random += 210; break;
                case 3: random += 270; break;
            }
        }
    }

    void level3(std::vector<CPU> &centralUnit3, int &x, sf::Texture &cpuTexture, sf::Texture &virusTexture, std::vector<VIRUS1> &vir1){
        x = 37500;
        int obstacle;
        int position;
        int random = x;

        for(int i = 0; i <= 80; i++){
            obstacle = std::rand() % 2;
            int size = std::rand() % 2;

            switch(obstacle){
                case 0:
                if(size == 0){vir1.push_back(VIRUS1(random, 1920, 0.2f, 0.2f, virusTexture));}
                else if(size == 1){vir1.push_back(VIRUS1(random, 1920, 0.1f, 0.1f, virusTexture));}
                break;
                case 1: centralUnit3.push_back(CPU(random, 1920, cpuTexture)); break;
            }

            position = std::rand() % 2;

            switch(position){
                case 0: random += 300; break;
                case 1: random += 450; break;
            }
        }
    }
};