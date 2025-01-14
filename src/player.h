#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

class Player{
    public:
      int speed = 0;

    Player(int speed){
      this->speed = speed;
    }
};