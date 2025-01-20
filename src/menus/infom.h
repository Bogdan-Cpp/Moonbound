#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

class Info{
    public:
    void infoMenuButton(Info *&in, MenuS *&ms, bool &isInfoMenu, bool &isStartMenu){
        isInfoMenu = true;
        isStartMenu = false;

        delete ms;
        ms = nullptr;
        in = new Info();
    }

    void infoMenuQuit(Info *&in, MenuS *&ms, bool &isInfoMenu, bool &isStartMenu){
        isInfoMenu = false;
        isStartMenu = true;

        delete in;
        in = nullptr;
        ms = new MenuS();
    }

    void infoMenuDraw(sf::RenderWindow& window, sf::Font fStart){
        sf::Text info("info menu", fStart, 50);

        info.setFillColor(sf::Color::White);
        info.setPosition(sf::Vector2f(500.f, 500.f));

        window.draw(info);
    }
};