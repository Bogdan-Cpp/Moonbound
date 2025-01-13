#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

class MenuS{
    public:
      void startMenu(sf::RenderWindow& window){
      //text
      sf::Font fStart;

      if(!fStart.openFromFile("C:/Users/leita/Documents/Moonbound/src/startFont.ttf")){return;}
      sf::Text title(fStart, "Moonbound", 100);
      title.setPosition(sf::Vector2f(150.f, 200.f));
      title.setFillColor(sf::Color::Yellow);

      sf::Text start(fStart, "Start(e)", 50);
      start.setPosition(sf::Vector2f(150.f, 600.f));
      start.setFillColor(sf::Color::White);

      sf::Text settings(fStart, "Settings(r)", 40);
      settings.setPosition(sf::Vector2f(150.f, 650.f));
      settings.setFillColor(sf::Color::White);

      sf::Text info(fStart, "Info(t)", 30);
      info.setPosition(sf::Vector2f(150.f, 700.f));
      info.setFillColor(sf::Color::White);

      window.draw(title);
      window.draw(start);
      window.draw(settings);
      window.draw(info);
    }
};