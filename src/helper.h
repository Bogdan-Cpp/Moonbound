#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

class Helper{
    public:
    sf::RectangleShape plane;

    Helper(float sizeX, float pozX){
        this->sizeX = sizeX;
        this->sizeY = sizeY;
        this->pozX = pozX;

        plane.setFillColor(sf::Color(120.f, 120.f, 120.f));
        plane.setSize(sf::Vector2f(sizeX, 30));
        plane.setPosition(pozX, 1890);
    }

    void drawPlane(sf::RenderWindow& window){
        window.draw(plane);
    }
};