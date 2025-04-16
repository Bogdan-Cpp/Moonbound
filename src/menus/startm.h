#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include <string>
#include "../player.h"

class Start{
    public:
    void startMenuButton(sf::Music *&startMusic, Start *&sr, MenuS *&ms, bool &isStartMenu, bool &isGameMenu){
        isStartMenu = false;
        isGameMenu = true;

        delete startMusic;
        delete ms;

        startMusic = nullptr;
        ms = nullptr;

        sr = new Start();
    }

    void ObjectPosition(sf::RectangleShape &floor1, float &getX){
        floor1.setFillColor(sf::Color::White);
        floor1.setSize(sf::Vector2f(3000.f, 500.f));
        floor1.setPosition(sf::Vector2f(getX - 1000.f, 2000.f));
    }

    void ObjectDraw(sf::RenderWindow& window, sf::RectangleShape &floor1, sf::RectangleShape &player){
        window.draw(floor1);
        window.draw(player);
    }

    void Scor(sf::Font fStart, sf::RenderWindow &window, float &getX, long long &count, long long &prev, long long &best){
        sf::Text scor("Scor " + std::to_string(count), fStart, 40);
        scor.setFillColor(sf::Color::White);
        scor.setPosition(sf::Vector2f(getX + 100, 1400.f));

        sf::Text prevScor("Preveous: " + std::to_string(prev), fStart, 40);
        prevScor.setFillColor(sf::Color::White);
        prevScor.setPosition(sf::Vector2f(100, 1920.f));
        
        sf::Text bestScor("Best: " + std::to_string(best), fStart, 40);
        bestScor.setFillColor(sf::Color::White);
        bestScor.setPosition(sf::Vector2f(550, 1920.f));
        
        window.draw(scor);
        window.draw(prevScor);
        window.draw(bestScor);
    }

    void Background(float &backSpeed, float &getX, int &a, int &b, int &c,
        sf::Sprite &back, sf::Sprite &back2, sf::Sprite &back3){
        float backPoz1 = (getX - 750) - backSpeed;
        float backPoz2 = (getX - 750) - backSpeed;
        float backPoz3 = (getX - 750) - backSpeed;
        backSpeed += 0.5f;
        std::cout << getX << '\n';
            
        if (getX >= a) {
            backPoz1 += 1920 * 3; 
        }
        if(getX >= b){
            backPoz2 += 1920 * 3;
        }
        if(getX >= c){
            backPoz3 += 1920 * 3;
        }

        back.setPosition(backPoz1, 1400.f);
        back2.setPosition(backPoz2 + 1920, 1400.f);
        back3.setPosition(backPoz3 + 3840, 1400.f);
    }

    void blueScreen(sf::Music *&bluescreenMusic, long long &count, bool &isBluescreen, sf::Music &gameMusic, Player &py){
        gameMusic.stop();
        bluescreenMusic = new sf::Music();
        if(!bluescreenMusic->openFromFile("../assets/bluescreenM.ogg")){
            if(!bluescreenMusic->openFromFile("../share/bluescreenM.ogg")){
                throw std::runtime_error("blueScreen Music was not found!");
            }
        }
        if(bluescreenMusic->getStatus() != sf::Music::Playing){bluescreenMusic->play();}
                
        py.speed = 0;
        count += 0;
        std::this_thread::sleep_for(std::chrono::seconds(2));
                
        isBluescreen = false;
        delete bluescreenMusic;
        bluescreenMusic = nullptr;
        py.speed = 8.f;
    }

    void Pozitioning(sf::RenderWindow &window, Player &py, sf::View &camera,
        sf::RectangleShape &player, float &yPoz, float &getX, float &playerSize,
        sf::RectangleShape &floor1, Start *&sr, sf::Sprite &blueScreen){
        
        camera.setCenter(player.getPosition().x + 250, yPoz);
        window.setView(camera);
        sr->ObjectPosition(floor1, getX);
        py.PlayerMove(player);
        py.playerCrouch(player, playerSize);
        blueScreen.setPosition(getX - 710.f, 1410.f);
    }
};