#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include <thread>
#include <chrono>

class Player{
  public:
  int speed = 6.f;
  bool isJumping = false;
  float gravity = -1.67f;
  float temp = 25.f;
  float jumpSpeed = 0.f;
  float groundLevel = 1950.f;
  float jumpingAnimation = 0;
  
   void PlayerBuild(sf::RectangleShape &player){
      player.setFillColor(sf::Color(120, 120, 120));
      player.setSize(sf::Vector2f(50.f, 50.f));
      player.setPosition(sf::Vector2f(15000.f, 1950.f));
   }

   void playerCrouch(sf::RectangleShape &player){
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
         player.setSize(sf::Vector2f(25.f, 25.f));
         player.setOrigin(0.f, -25.f);
      }
      else{
         player.setSize(sf::Vector2f(50.f, 50.f));
         player.setOrigin(0.f, 0.f);
      }
   }

   void PlayerMove(sf::RectangleShape &player){
      player.move(sf::Vector2f(speed, 0.f));

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping){
         isJumping = true;
         jumpSpeed = temp;
      }

      if(isJumping) {
        player.move(0.f, -jumpSpeed); 
        jumpSpeed += gravity;
        
         if(player.getPosition().y >= groundLevel) {
            player.setPosition(player.getPosition().x, groundLevel);
            isJumping = false; 
            jumpSpeed = 0.f;

            player.setRotation(std::round(player.getRotation() / 90) * 90);
         }
      }
   }
};