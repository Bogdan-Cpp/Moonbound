#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include "player.h"
#include "menus/startm.h"

class OBS{
    public:
    sf::Sprite obs;
    float xPoz;
    float yPoz;
    float rotation;
    
    OBS(float xPoz, float yPoz, sf::Texture &winTexture1,sf::Texture &winTexture2,
        sf::Texture &winTexture3, sf::Texture &winTexture4, sf::Texture &cpuTexture,
        sf::Texture &gpuTexture, sf::Texture &ssdTexture, sf::Texture &mbTexture, 
        sf::Texture &virusTexture, sf::Texture &virusTexture2, sf::Texture &winTexture5,
        sf::Texture &winTexture6, sf::Texture &winTexture7, sf::Texture &winTexture8,
        sf::Texture &winTexture9){
        
        int texture = std::rand() % 15;

        this->xPoz = xPoz;
        this->yPoz = yPoz;

        switch(texture){
            case 0:
            if(!winTexture1.loadFromFile("../assets/win1.png")){
                if(!winTexture1.loadFromFile("../share/win1.png")){
                    throw std::runtime_error("win texture error!");
                }
            }
            this->obs.setTexture(winTexture1);
            obs.setScale(0.2f, 0.2f);
            break;

            case 1:
            if(!winTexture2.loadFromFile("../assets/win2.png")){
                if(!winTexture2.loadFromFile("../share/win2.png")){
                    throw std::runtime_error("win texture error!");
                }
            }
            this->obs.setTexture(winTexture2);
            obs.setScale(0.1f, 0.1f);
            break;

            case 2:
            if(!winTexture3.loadFromFile("../assets/win3.png")){
                if(!winTexture3.loadFromFile("../share/win3.png")){
                    throw std::runtime_error("win texture error!");
                }
            }
            this->obs.setTexture(winTexture3);
            obs.setScale(0.2f, 0.2f);
            break;

            case 3:
            if(!winTexture4.loadFromFile("../assets/win5.png")){
                if(!winTexture4.loadFromFile("../share/win5.png")){
                    throw std::runtime_error("win texture error!");
                }
            }
            this->obs.setTexture(winTexture4);
            obs.setScale(0.2f, 0.2f);
            break;

            case 4:
            if(!cpuTexture.loadFromFile("../assets/gameIcon.png")){
                if(!cpuTexture.loadFromFile("../share/gameIcon.png")){
                    throw std::runtime_error("win texture error!");
                }
            }
            this->obs.setTexture(cpuTexture);
            obs.setScale(1.5f, 1.5f);
            break;

            case 5:
            if(!gpuTexture.loadFromFile("../assets/gpu1.png")){
                if(!gpuTexture.loadFromFile("../share/gpu1.png")){
                    throw std::runtime_error("win texture error!");
                }
            }
            this->obs.setTexture(gpuTexture);
            obs.setScale(1.4f, 1.4f);
            break;

            case 6:
            if(!ssdTexture.loadFromFile("../assets/ssd1.png")){
                if(!ssdTexture.loadFromFile("../share/ssd1.png")){
                    throw std::runtime_error("win texture error!");
                }
            }
            this->obs.setTexture(ssdTexture);
            obs.setScale(1.6f, 1.6f);
            break;

            case 7:
            if(!mbTexture.loadFromFile("../assets/motherboard1.png")){
                if(!mbTexture.loadFromFile("../share/motherboard1.png")){
                    throw std::runtime_error("win texture error!");
                }
            }
            this->obs.setTexture(mbTexture);
            obs.setScale(1.5f, 1.7f);
            break;

            case 8:
            if(!virusTexture.loadFromFile("../assets/virus.png")){
                if(!virusTexture.loadFromFile("../share/virus.png")){
                    throw std::runtime_error("win texture error!");
                }
            }
            this->obs.setTexture(virusTexture);
            obs.setScale(0.2f, 0.2f);
            break;

            case 9:
            if(!virusTexture2.loadFromFile("../assets/virus2.png")){
                if(!virusTexture2.loadFromFile("../share/virus2.png")){
                    throw std::runtime_error("win texture error!");
                }
            }
            this->obs.setTexture(virusTexture2);
            obs.setScale(0.2f, 0.2f);
            break;

            case 10:
            if(!winTexture5.loadFromFile("../assets/win6.png")){
                if(!winTexture5.loadFromFile("../share/win6.png")){
                    throw std::runtime_error("win texture error!");
                }
            }
            this->obs.setTexture(winTexture5);
            obs.setScale(0.7f, 0.7f);
            break;

            case 11:
            if(!winTexture6.loadFromFile("../assets/win7.png")){
                if(!winTexture6.loadFromFile("../share/win7.png")){
                    throw std::runtime_error("win texture error!");
                }
            }
            this->obs.setTexture(winTexture6);
            obs.setScale(0.7f, 0.7f);
            break;

            case 12:
            if(!winTexture7.loadFromFile("../assets/win8.png")){
                if(!winTexture7.loadFromFile("../share/win8.png")){
                    throw std::runtime_error("win texture error!");
                }
            }
            this->obs.setTexture(winTexture7);
            obs.setScale(0.7f, 0.7f);
            break;

            case 13:
            if(!winTexture8.loadFromFile("../assets/win9.png")){
                if(!winTexture8.loadFromFile("../share/win9.png")){
                    throw std::runtime_error("win texture error!");
                }
            }
            this->obs.setTexture(winTexture8);
            obs.setScale(0.7f, 0.7f);
            break;

            case 14:
            if(!winTexture9.loadFromFile("../assets/win10.png")){
                if(!winTexture9.loadFromFile("../share/win10.png")){
                    throw std::runtime_error("win texture error!");
                }
            }
            this->obs.setTexture(winTexture9);
            obs.setScale(0.7f, 0.7f);
            break;
        }
        obs.setPosition(sf::Vector2f(xPoz, yPoz));
    }

    void drawObs(sf::RenderWindow& window){
        window.draw(obs);
    }

    void obsColide(sf::RectangleShape &player, Start *&sr, bool &isGameMenu,
        long long &count, long long &prev, long long &best, bool &isBluescreen,
        float &x){
            
        sf::FloatRect newObstacle(
            obs.getPosition().x + obs.getGlobalBounds().width * 0.1f,  
            obs.getPosition().y + obs.getGlobalBounds().height * 0.1f, 
            obs.getGlobalBounds().width * 0.8f,
            obs.getGlobalBounds().height * 0.8f 
        );

        if(player.getGlobalBounds().intersects(newObstacle)){
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
            x = 2000;
        }
    }
};