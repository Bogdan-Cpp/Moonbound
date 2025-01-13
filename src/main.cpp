#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <optional>
#include "startm.h"

int main(){
    //variabile generale
    bool isStartMusic = true;
    bool isStartMenu = true;

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Moonbound");
    window.setFramerateLimit(60);
    
    //class apelation
    MenuS *menuStart = new MenuS();
    sf::Music startMusic;
    sf::Image image;
    
    //file verification
    if(!startMusic.openFromFile("C:/Users/leita/Documents/Moonbound/src/music.ogg")){return -1;}
    if(!image.loadFromFile("C:/Users/leita/Documents/Moonbound/src/gameIcon.png")){return -1;}

    if(isStartMusic){
        //music
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
            delete menuStart;
            menuStart = nullptr;
            startMusic.stop();
        }
        window.clear(sf::Color::Black);
        
        if(isStartMenu && menuStart != nullptr){
            menuStart->startMenu(window);
        }
        window.display();
    }
    return 0;
}