#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

class Player{
  public:
  int speed = 4;
  
   void PlayerBuild(sf::RectangleShape &player){
      player.setFillColor(sf::Color::Blue);
      player.setSize(sf::Vector2f(50.f, 50.f));
      player.setPosition(sf::Vector2f(100.f, 1950.f));
   }

   void PlayerMove(sf::RectangleShape &player){
      player.move(sf::Vector2f(speed, 0.f));
   }
};