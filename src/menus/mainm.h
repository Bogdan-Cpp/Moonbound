#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

class MenuS{
  public:
  void startMenu(sf::RenderWindow& window, sf::Font &fStart){
    //text
    sf::Text title("Moonbound", fStart, 100); 
    title.setPosition(sf::Vector2f(150.f, 200.f));
    title.setFillColor(sf::Color::Yellow);

    sf::Text start("Start(e)", fStart, 50); 
    start.setPosition(sf::Vector2f(150.f, 600.f));
    start.setFillColor(sf::Color::White);

    sf::Text info("Info(t)", fStart, 30); 
    info.setPosition(sf::Vector2f(150.f, 650.f));
    info.setFillColor(sf::Color::White);

    window.draw(title);
    window.draw(start);
    window.draw(info);
  }
};