#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <optional>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "menus/mainm.h"
#include "menus/infom.h"
#include "menus/startm.h"
#include "Ssd.h"
#include "player.h"
#include "pausem.h"

void obstacleAlgorithm(std::vector<Ssd> &storage, int &x);

int main(){
    bool isStartMenu = true;
    bool isGameMenu = false;
    bool isInfoMenu = false;
    bool isPauseMenu = false;

    long long count = 0;
    long long prev = 0;
    long long best = 0;

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Moonbound");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    //class apelation
    Start *sr = new Start();
    Info *in = new Info();
    MenuS *ms = new MenuS();
    Pause *pa = new Pause();
    
    delete sr;
    delete in;
    delete pa;
    sr = nullptr;
    in = nullptr;
    pa = nullptr;
    
    Player py;
    sf::Image image;
    sf::Font fStart;
    sf::RectangleShape player;
    sf::RectangleShape floor1;
    sf::View camera(sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(1920.f, 1080.f)));
    sf::Music *startMusic = new sf::Music();
    int x = 1000;
    std::vector<Ssd> storage;
    std::srand(std::time(nullptr));
   
    obstacleAlgorithm(storage, x);
    
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

            if(!isPauseMenu){
                count += 1;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                isPauseMenu = true;
                pa = new Pause();
                py.speed = 0.f;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && isPauseMenu){
                isPauseMenu = false;
                delete pa;
                pa = nullptr;
                py.speed = 5.f;
            }

            for(auto &stor : storage){
                stor.ssdColide(player, sr, isGameMenu, count, prev, best);
            }
        }
        
        //draw
        window.clear(sf::Color::Black);

        if(isStartMenu && ms != nullptr){
            ms->startMenu(window, fStart);
        }
        
        else if(isGameMenu && sr != nullptr){
            sr->Scor(fStart, window, getX, count, prev, best);
            sr->ObjectDraw(window, floor1, player);
            for(auto &storages : storage){
                storages.drawSsd(window);
            }
            if(isPauseMenu){
                pa->drawPause(fStart, window, getX);
            }
        }

        else if(isInfoMenu && in != nullptr){
            in->infoMenuDraw(window, fStart);
        }

        window.display();
    }
    
    return 0;
}

void obstacleAlgorithm(std::vector<Ssd> &storage, int &x){\
    int prev = 0;
    int random = x;
    int level1;

    for(int i = 0; i <= 100; i++){
        storage.push_back(Ssd(random, 1960));
        if(x < 100000){
            level1 = std::rand() % 5;
            prev = x;
            x = random;

            switch(level1){
               case 0:
                prev += 200;
                x += 300;
                break;
               
               case 1:
                prev += 250;
                x += 400;
                break;

               case 2:
                prev += 100;
                x += 200;
                break;
               
               case 3:
                prev += 400;
                x += 200;
                break;

               case 4:
                prev += 100;
                x += 450;
                break;
            }

            if(x > prev){random = prev + (std::rand() % (x - prev + 1));}
            else{random = prev;}
        }
    }
}