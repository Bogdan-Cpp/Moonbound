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

    void startMenuDraw(sf::RenderWindow& window, sf::Font fStart){
        sf::Text info("start Menu", fStart, 50);

        info.setFillColor(sf::Color::White);
        info.setPosition(sf::Vector2f(500.f, 500.f));

        window.draw(info);
    }
};