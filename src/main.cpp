#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <optional>
#include "menus/startm.h"
#include "player.h"
#include "map/ground.h"

void settingsButton(MenuS *&menuStart, bool &isSettingsMenu, bool &isStartMenu);
void startButton(MenuS *&menuStart, sf::Music *startMusic, bool &isStartMenu, bool &isStartGame);

int main(){
    //variabile generale
    bool isStartMenu = true;
    bool isStartGame = false;
    bool isSettingsMenu = false;

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Moonbound");
    window.setFramerateLimit(60);

    //class apelation
    Player py;
    Ground gr;
    sf::Image image;
    sf::Font fStart;
    sf::RectangleShape box;
    sf::RectangleShape ground1;
    sf::View camera(sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(1920.f, 1080.f)));
    MenuS *menuStart = new MenuS();
    sf::Music *startMusic = new sf::Music();

    //function declaration
    py.PlayerBuild(box);
    
    //file verification
    if(!fStart.openFromFile("../materials/startFont.ttf")){return -1;}
    if(!startMusic->openFromFile("../materials/music.ogg")){return -1;}
    if(!image.loadFromFile("../materials/gameIcon.png")){return -1;}

    window.setIcon(image);
    startMusic->play();

    while(window.isOpen()){

        while(const std::optional event = window.pollEvent()){

            if(event->is<sf::Event::Closed>()){
                window.close();
            }
        }
        
        if(isStartGame){
            py.PlayerMove(box);
            camera.setCenter(box.getPosition());
            window.setView(camera);
        }

        //function
        settingsButton(menuStart, isSettingsMenu, isStartMenu);
        startButton(menuStart, startMusic, isStartMenu, isStartGame);

        window.clear(sf::Color::Black);
        
        if(isStartMenu && menuStart != nullptr){
            menuStart->startMenu(window, fStart);
        }

        if(isStartGame){
            gr.Object(window, ground1);
            py.PlayerDeclaration(window, box);
        }
        window.display();
    }

    if(menuStart != nullptr){
        delete menuStart;
        menuStart = nullptr;
    }
    return 0;
}

void settingsButton(MenuS *&menuStart, bool &isSettingsMenu, bool &isStartMenu){
   if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::R)){
        isStartMenu = false;
        isSettingsMenu = true;

        delete menuStart;
        menuStart = nullptr;
    }
}

void startButton(MenuS *&menuStart, sf::Music *startMusic, bool &isStartMenu, bool &isStartGame){
   if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::E)){
        isStartMenu = false;
        isStartGame = true;

        delete menuStart;
        delete startMusic;
        menuStart = nullptr;
        startMusic = nullptr;
    }
}