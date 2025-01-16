#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

class Player{
  public:
  int speed = 4;
  
   void PlayerBuild(sf::RectangleShape &box){
      box.setFillColor(sf::Color::White);
      box.setSize(sf::Vector2f(100.f, 100.f));
      box.setPosition(sf::Vector2f(100.f, 700.f));
   }

   void PlayerDeclaration(sf::RenderWindow& window, sf::RectangleShape &box){
      window.draw(box);
   }

   void PlayerMove(sf::RectangleShape &box){
      box.move(sf::Vector2f(speed, 0.f));
   }
};