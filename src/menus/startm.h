#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

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
};