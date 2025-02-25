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
  float groundLevel = 2000.f;
  float jumpingAnimation = 0;
  
   void PlayerBuild(sf::RectangleShape &player, float &playerSize){
      player.setFillColor(sf::Color(120, 120, 120));
      player.setSize(sf::Vector2f(playerSize, playerSize));
      player.setOrigin(0.f, playerSize);
      player.setPosition(sf::Vector2f(70000.f, groundLevel - playerSize));
   }

   void playerCrouch(sf::RectangleShape &player, float &playerSize){
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
         player.setSize(sf::Vector2f((playerSize / 2), (playerSize / 2)));
         player.setOrigin(0.f, (playerSize / 2));
      }
      else{
         player.setSize(sf::Vector2f(playerSize, playerSize));
         player.setOrigin(0.f, playerSize);
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
         }
      }
   }
};