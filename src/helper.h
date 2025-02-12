#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

class Helper{
    public:
    sf::RectangleShape plane;

    Helper(float sizeX, float sizeY, float pozX){
        
        plane.setFillColor(sf::Color(120.f, 120.f, 120.f));
        plane.setSize(sf::Vector2f())
    }
};