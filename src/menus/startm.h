#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include <string>

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

    void ObjectPosition(sf::RectangleShape &floor1){
        floor1.setFillColor(sf::Color::White);
        floor1.setSize(sf::Vector2f(1000000.f, 500.f));
        floor1.setPosition(sf::Vector2f(0.f, 2000.f));
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
};