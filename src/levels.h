#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include <vector>
#include "player.h"
#include "virus1.h"
#include "virus2.h"

class Level{
    public:
    void level1(int &x, sf::Texture &gpuTexture, std::vector<GPU> &graphics,
        sf::Texture &cpuTexture, std::vector<CPU> &centralUnit, long long &count,
        std::vector<MB> &motherboard, sf::Texture &mbTexture){
        
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

    void level2(std::vector<Ssd> &storage2, int &x, sf::Texture &ssdTexture,
        sf::Texture &gpuTexture, std::vector<GPU> &graphics2,
        sf::Texture &cpuTexture, std::vector<CPU> &centralUnit2,
        long long &count, std::vector<MB> &motherboard2, sf::Texture &mbTexture){
        
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

    void level3(std::vector<CPU> &centralUnit3, int &x, sf::Texture &cpuTexture,
        sf::Texture &virusTexture, std::vector<VIRUS1> &vir1, std::vector<GPU> &graphics3,
        sf::Texture &gpuTexture, sf::Texture &virusTexture2){
        
        x = 38500;
        int obstacle;
        int position;
        int random = x;

        for(int i = 0; i <= 80; i++){
            obstacle = std::rand() % 6;
            int size = std::rand() % 2;

            switch(obstacle){
                case 0: vir1.push_back(VIRUS1(random, 1920, 0.2f, 0.2f, virusTexture, virusTexture2)); break;
                case 1: vir1.push_back(VIRUS1(random, 1920, 0.1f, 0.1f, virusTexture, virusTexture2)); break;
                case 2: centralUnit3.push_back(CPU(random, 1920, cpuTexture)); break;
                case 3: graphics3.push_back(GPU(random, 1925, 140, gpuTexture)); break;
                case 4: graphics3.push_back(GPU(random, 1940, 90, gpuTexture)); break;
                case 5: graphics3.push_back(GPU(random, 1925, 70, gpuTexture)); break;
            }
            position = std::rand() % 2;

            switch(position){
                case 0: random += 300; break;
                case 1: random += 450; break;
            }
        }
    }
    
    void level4(std::vector<VIRUS1> &vir2, std::vector<VIRUS2> &vir3, 
        sf::Texture &virusTexture, int &x, sf::Texture &virusTexture2){
        
        x = 72000;
        int obstacle;
        int position;
        int random = x;

        for(int i = 0; i <= 80; i++){
            obstacle = rand() % 12;
            
            switch(obstacle){
                case 0: vir2.push_back(VIRUS1(random, 1920, 0.2f, 0.2f, virusTexture, virusTexture2)); break;
                case 1: vir3.push_back(VIRUS2(random, 1920, 0.2f, 0.2f, virusTexture, virusTexture2)); break;
                case 2: vir2.push_back(VIRUS1(random, 1893, 0.2f, 0.2f, virusTexture, virusTexture2)); break;
                case 3: vir3.push_back(VIRUS2(random, 1893, 0.2f, 0.2f, virusTexture, virusTexture2)); break;
                case 4: vir2.push_back(VIRUS1(random, 1900, 0.1f, 0.1f, virusTexture, virusTexture2)); break;
                case 5: vir3.push_back(VIRUS2(random, 1900, 0.1f, 0.1f, virusTexture, virusTexture2)); break;
                case 6: vir2.push_back(VIRUS1(random, 1920, 0.1f, 0.1f, virusTexture, virusTexture2)); break;
                case 7: vir3.push_back(VIRUS2(random, 1920, 0.1f, 0.1f, virusTexture, virusTexture2)); break;

                case 8:
                vir2.push_back(VIRUS1(random, 1920, 0.2f, 0.2f, virusTexture, virusTexture2));
                vir2.push_back(VIRUS1(random + 2, 1910, 0.1f, 0.1f, virusTexture, virusTexture2));
                break;

                case 9:
                vir2.push_back(VIRUS1(random, 1920, 0.2f, 0.2f, virusTexture, virusTexture2));
                vir2.push_back(VIRUS1(random + 2, 1910, 0.1f, 0.1f, virusTexture, virusTexture2));
                vir2.push_back(VIRUS1(random + 45, 1907, 0.1f, 0.1f, virusTexture, virusTexture2));
                break;

                case 10:
                vir3.push_back(VIRUS2(random, 1920, 0.2f, 0.2f, virusTexture, virusTexture2));
                vir3.push_back(VIRUS2(random + 2, 1910, 0.1f, 0.1f, virusTexture, virusTexture2));
                vir3.push_back(VIRUS2(random + 45, 1907, 0.1f, 0.1f, virusTexture, virusTexture2));
                break;

                case 11:
                vir3.push_back(VIRUS2(random, 1893, 0.2f, 0.2f, virusTexture, virusTexture2));
                vir3.push_back(VIRUS2(random + 2, 1883, 0.1f, 0.1f, virusTexture, virusTexture2));
                vir3.push_back(VIRUS2(random + 45, 1880, 0.1f, 0.1f, virusTexture, virusTexture2));
                break;
            }

            

            if(obstacle == 4 || obstacle == 5 || obstacle == 6 || obstacle == 7){
                position = (rand() % 5) + 2;
            }
            else{
                position = rand() % 3;
            }

            switch(position){
                case 0: random += 340; break;
                case 1: random += 340; break;
                case 2: random += 430; break;
                case 3: random += 200; break;
                case 4: random += 210; break;
                case 5: random += 270; break;
                case 6: random += 180; break;
            }
        }
    }
};