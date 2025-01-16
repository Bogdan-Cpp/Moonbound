#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

class Ground{
    public:
    void Object(sf::RenderWindow& window, sf::RectangleShape &ground1){
        ground1.setFillColor(sf::Color::Blue);
        ground1.setSize(sf::Vector2f(1920.f, 50.f));
        ground1.setPosition(sf::Vector2f(0.f, 800.f));

        window.draw(ground1);
    }
};