#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include "player.h"

class WIN{
    public:
    sf::Sprite winObstacle;
    float xPoz;
    float yPoz;
    float rotation;
    
    WIN(float xPoz, float yPoz, sf::Texture &winTexture1,sf::Texture &winTexture2,
        sf::Texture &winTexture3, sf::Texture &winTexture4){
        
        int texture = std::rand() % 4;
        int size = std::rand() % 3;

        this->xPoz = xPoz;
        this->yPoz = yPoz;

        switch(texture){
            case 0:
            if(!winTexture1.loadFromFile("../assets/win1.png")){throw std::runtime_error("win texture error!");}
            this->winObstacle.setTexture(winTexture1);
            break;

            case 1:
            if(!winTexture1.loadFromFile("../assets/win2.png")){throw std::runtime_error("win texture error!");}
            this->winObstacle.setTexture(winTexture2);
            break;

            case 2:
            if(!winTexture3.loadFromFile("../assets/win3.png")){throw std::runtime_error("win texture error!");}
            this->winObstacle.setTexture(winTexture3);
            break;

            case 3:
            if(!winTexture4.loadFromFile("../assets/win4.png")){throw std::runtime_error("win texture error!");}
            this->winObstacle.setTexture(winTexture4);
            break;
        }
        
        switch(size){
            case 0:
            if(texture == 0 || texture == 1 || texture == 2){winObstacle.setScale(0.2f, 0.2f);}
            else{winObstacle.setScale(1.f, 1.f);}
            break;

            case 1:
            if(texture == 0 || texture == 1 || texture == 2){winObstacle.setScale(0.1f, 0.1f);}
            else{winObstacle.setScale(2.f, 2.f);}
            break;
            
            case 2:
            if(texture == 0 || texture == 1){winObstacle.setScale(0.3f, 0.3f);}
            else if(texture == 2){winObstacle.setScale(0.2f, 0.2f);}
            else{winObstacle.setScale(3.f, 3.f);}
            break;
        }
        winObstacle.setPosition(sf::Vector2f(xPoz, yPoz));
    }

    void drawWin(sf::RenderWindow& window){
        window.draw(winObstacle);
    }

    void winColide(sf::RectangleShape &player, Start *&sr, bool &isGameMenu,
        long long &count, long long &prev, long long &best, bool &isBluescreen){
            
        sf::FloatRect newObstacle(
            winObstacle.getPosition().x + winObstacle.getGlobalBounds().width * 0.1f,  
            winObstacle.getPosition().y + winObstacle.getGlobalBounds().height * 0.1f, 
            winObstacle.getGlobalBounds().width * 0.8f,
            winObstacle.getGlobalBounds().height * 0.8f 
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
        }
    }
};