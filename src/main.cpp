#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <optional>
#include "startm.h"
#include "mainGame.h"

int main(){
    //variabile generale
    bool isStartMusic = true;
    bool isStartMenu = true;
    bool isStartGame = false;

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Moonbound");
    window.setFramerateLimit(60);

    //class apelation
    Game start;
    MenuS *menuStart = new MenuS();
    sf::Music startMusic;
    sf::Image image;
    sf::Font fStart;
    sf::RectangleShape box;
    
    //file verification
    if(!fStart.openFromFile("../materials/startFont.ttf")){return -1;}
    if(!startMusic.openFromFile("../materials/music.ogg")){return -1;}
    if(!image.loadFromFile("../materials/gameIcon.png")){return -1;}

    if(isStartMusic){
        startMusic.play();
    }
    window.setIcon(image);

    while(window.isOpen()){

        while(const std::optional event = window.pollEvent()){

            if(event->is<sf::Event::Closed>()){
                window.close();
            }
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::E)){
            isStartMenu = false;
            isStartGame = true;
            delete menuStart;
            menuStart = nullptr;
            startMusic.stop();
        }

        window.clear(sf::Color::Black);
        
        if(isStartMenu && menuStart != nullptr){
            menuStart->startMenu(window, fStart);
        }

        if(isStartGame){
            start.Objectdraw(window, box);
        }
        window.display();
    }

    if(menuStart != nullptr){
        delete menuStart;
        menuStart = nullptr;
    }
    return 0;
}