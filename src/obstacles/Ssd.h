#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

class Ssd{
    public:
    float l = 100.f;
    float L = 100.f;
    float xPoz;
    float yPoz;

    Ssd(sf::RectangleShape &ssd, float xPoz, float yPoz){
        this->xPoz = xPoz;
        this->yPoz = yPoz;

        ssd.setFillColor(sf::Color::Green);
        ssd.setSize(sf::Vector2f(l, L));
        ssd.setPosition(sf::Vector2f(xPoz, yPoz));
    }
};