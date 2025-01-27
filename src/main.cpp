#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <optional>
#include <vector>

#include "menus/mainm.h"
#include "menus/infom.h"
#include "menus/startm.h"

#include "obstacles/Ssd.h"

#include "player.h"

int main(){
    bool isStartMenu = true;
    bool isGameMenu = false;
    bool isInfoMenu = false;

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Moonbound");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    //class apelation
    Start *sr = new Start();
    Info *in = new Info();
    MenuS *ms = new MenuS();
    
    delete sr;
    delete in;
    sr = nullptr;
    in = nullptr;

    Player py;
    sf::Image image;
    sf::Font fStart;
    sf::RectangleShape player;
    sf::RectangleShape floor1;
    sf::View camera(sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(1920.f, 1080.f)));
    sf::Music *startMusic = new sf::Music();
    
    std::vector<Ssd> storage = {
        Ssd(1000.f, 1960.f),
        Ssd(1400.f, 1960.f),
        Ssd(1900.f, 1960.f),
        Ssd(2300.f, 1960.f),
        Ssd(2600.f, 1960.f),
        Ssd(2800.f, 1960.f),
        Ssd(3000.f, 1960.f),
        Ssd(3200.f, 1960.f),
        //level 2
        Ssd(4000.f, 1960.f),
        Ssd(4300.f, 1960.f),
        Ssd(4500.f, 1960.f),
        Ssd(4700.f, 1960.f)
    };
    
    //function declaration
    py.PlayerBuild(player);

    float yPoz = player.getPosition().y;
    
    //file verification
    if(!fStart.loadFromFile("../assets/startFont.ttf")){return -1;}
    if(!startMusic->openFromFile("../assets/music.ogg")){return -1;}
    if(!image.loadFromFile("../assets/gameIcon.png")){return -1;}

    window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
    startMusic->play();
    py.PlayerBuild(player);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        float getX = player.getPosition().x;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && isStartMenu){sr->startMenuButton(startMusic, sr, ms, isStartMenu, isGameMenu);}
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::I) && isStartMenu){in->infoMenuButton(in, ms, isInfoMenu, isStartMenu);}
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !isStartMenu && isInfoMenu){in->infoMenuQuit(in, ms, isInfoMenu, isStartMenu);}
        
        if(isGameMenu){
            camera.setCenter(player.getPosition().x + 250, yPoz);
            window.setView(camera);
            sr->ObjectPosition(floor1);
            py.PlayerMove(player);

            for(auto &stor : storage){
                stor.ssdColide(player, sr, isGameMenu);
            }
            if(getX > 3400){
                py.speed = 5;
            }
        }
        
        //draw
        window.clear(sf::Color::Black);

        if(isStartMenu && ms != nullptr){
            ms->startMenu(window, fStart);
        }
        
        else if(isGameMenu && sr != nullptr){
            sr->ObjectDraw(window, floor1, player);
            for(auto &storages : storage){
                storages.drawSsd(window);
            }
            sr->Scor(fStart, window, getX);
        }

        else if(isInfoMenu && in != nullptr){
            in->infoMenuDraw(window, fStart);
        }

        window.display();
    }
    
    return 0;
}