#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

class Game{
  public:
   void Objectdraw(sf::RenderWindow& window, sf::RectangleShape &box){
      box.setFillColor(sf::Color::White);
      box.setSize(sf::Vector2f(500.f, 200.f));
      box.setPosition(sf::Vector2f(100.f, 100.f));

      window.draw(box);
   }
};