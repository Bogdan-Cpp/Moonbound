#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <optional>
#include <chrono>
#include <thread>
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
#include "graphicscard.h"
#include "procesor.h"

void obstacleAlgorithm(std::vector<Ssd> &storage, int &x, sf::Texture &ssdTexture, sf::Texture &gpuTexture, std::vector<GPU> &graphics, sf::Texture &cpuTexture, std::vector<CPU> &centralUnit, long long &count);

int main(){
    bool isStartMenu = true;
    bool isGameMenu = false;
    bool isInfoMenu = false;
    bool isPauseMenu = false;
    bool isBluescreen = false;
    bool devMode = true;

    long long count = 0;
    long long prev = 0;
    long long best = 0;
    float prevSpeed;

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Moonbound");
    window.setFramerateLimit(120);
    window.setVerticalSyncEnabled(true);

    //class apelation
    Start *sr = new Start();
    Info *in = new Info();
    MenuS *ms = new MenuS();
    Pause *pa = new Pause();
    sf::Music gameMusic;
    sf::Music *bluescreenMusic = new sf::Music();
    
    delete sr;
    delete in;
    delete pa;
    delete bluescreenMusic;
    bluescreenMusic = nullptr;
    sr = nullptr;
    in = nullptr;
    pa = nullptr;

    sf::Texture cpuTexture;
    sf::Texture gpuTexture;
    sf::Texture ssdTexture;
    sf::Texture bluescreenTexture;
    sf::Font fStart;
    sf::Font fPause;
    sf::RectangleShape player;
    sf::RectangleShape floor1;
    sf::Sprite blueScreen;
    Player py;
    sf::Image image;
    sf::Text oc("Overclocking: an extreme sport\n for PCs!", fPause, 40);
    sf::View camera(sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(1920.f, 1080.f)));
    sf::Music *startMusic = new sf::Music();
    int x = 1000;
    std::vector<Ssd> storage;
    std::vector<GPU> graphics;
    std::vector<CPU> centralUnit;
    std::srand(std::time(nullptr));
   
    obstacleAlgorithm(storage, x, ssdTexture, gpuTexture, graphics, cpuTexture, centralUnit, count);
    py.PlayerBuild(player);
    float yPoz = player.getPosition().y;

    //file verification
    if(!fStart.loadFromFile("../assets/startFont.ttf")){return -1;}
    if(!fPause.loadFromFile("../assets/pauseFont.ttf")){return -1;}
    if(!startMusic->openFromFile("../assets/music.ogg")){return -1;}
    if(!gameMusic.openFromFile("../assets/gameMusic2.ogg")){return -1;}
    if(!image.loadFromFile("../assets/gameIcon.png")){return -1;}
    if(!bluescreenTexture.loadFromFile("../assets/bluescreen1.png")){return -1;}

    window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
    startMusic->play();
    oc.setPosition(12000.f, 1700.f);
    blueScreen.setTexture(bluescreenTexture);
    blueScreen.setScale(1.f, 1.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {window.close();}
        }
        float getX = player.getPosition().x;
        float getY = player.getPosition().y;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && isStartMenu){sr->startMenuButton(startMusic, sr, ms, isStartMenu, isGameMenu);}
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::I) && isStartMenu){in->infoMenuButton(in, ms, isInfoMenu, isStartMenu);}
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !isStartMenu && isInfoMenu){in->infoMenuQuit(in, ms, isInfoMenu, isStartMenu);}
        
        if(isGameMenu){
            camera.setCenter(player.getPosition().x + 250, yPoz);
            window.setView(camera);
            sr->ObjectPosition(floor1);
            py.PlayerMove(player);
            py.playerCrouch(player);
            blueScreen.setPosition(getX - 710.f, 1410);
            if(!isPauseMenu){count += 1;}
            
            if(isBluescreen){
                gameMusic.stop();
                bluescreenMusic = new sf::Music();
                if(!bluescreenMusic->openFromFile("../assets/bluescreenM.ogg")){return -1;}
                if(bluescreenMusic->getStatus() != sf::Music::Playing){bluescreenMusic->play();}
                
                py.speed = 0;
                count += 0;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                
                isBluescreen = false;
                delete bluescreenMusic;
                bluescreenMusic = nullptr;
            }
            else{
                if(count > 2000){
                    prevSpeed = 8.f;
                    py.speed = prevSpeed;
                }
                else{
                    prevSpeed = 7.f;
                    py.speed = prevSpeed;
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
                    py.speed = prevSpeed;
                }
                if(gameMusic.getStatus() != sf::Music::Playing){gameMusic.play();}
            }
            //object cliding
            if(devMode){
                for(auto &stor : storage){
                    stor.ssdColide(player, sr, isGameMenu, count, prev, best, isBluescreen);
                }
                for(auto &stor1 : graphics){
                    stor1.gpuColide(player, sr, isGameMenu, count, prev, best, isBluescreen);
                }
                for(auto &stor2 : centralUnit){
                    stor2.cpuColide(player, sr, isGameMenu, count, prev, best, isBluescreen);
                }
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
            window.draw(oc);
            for(auto &storages : storage){
                storages.drawSsd(window);
            }
            for(auto &graphic : graphics){
                graphic.drawGpu(window);
            }
            for(auto &procesores : centralUnit){
                procesores.drawCpu(window);
            }
            if(isPauseMenu){
                pa->drawPause(fPause, window, getX);
            }
            if(isBluescreen){
                window.draw(blueScreen);
            }
        }

        else if(isInfoMenu && in != nullptr){
            in->infoMenuDraw(window, fStart);
        }

        window.display();
    }
    
    return 0;
}

void obstacleAlgorithm(std::vector<Ssd> &storage, int &x, sf::Texture &ssdTexture, sf::Texture &gpuTexture, std::vector<GPU> &graphics, sf::Texture &cpuTexture, std::vector<CPU> &centralUnit, long long &count){
    int prev = 0;
    int random = x;
    int level1;
    int obstacle;
    int yRandom;
    //at poz.x 30.000
    for(int i = 0; i <= 100; i++){
        obstacle = std::rand() % 4;
        yRandom = std::rand() % 3;

        //choose an obstacle
        if(obstacle == 1){
            storage.push_back(Ssd(random, 1960, ssdTexture));
        }
        else if(obstacle == 2){
            graphics.push_back(GPU(random, 1910, 0, gpuTexture));
        }
        else if(obstacle == 3){
            graphics.push_back(GPU(random, 1920, 90, gpuTexture));
        }
        else if(obstacle == 0){
            switch(yRandom){
                case 0:
                 centralUnit.push_back(CPU(random, 1945, cpuTexture));
                break;

                case 1:
                 centralUnit.push_back(CPU(random, 1920, cpuTexture));
                break;

                case 2:
                 centralUnit.push_back(CPU(random, 1890, cpuTexture));
                break;
            }
        }
        level1 = std::rand() % 5;
        prev = x;
        x = random;

        switch(level1){
            case 0:
             prev += 400;
             x += 350;
            break;
               
            case 1:
             prev += 400;
             x += 310;
            break;

            case 2:
             prev += 400;
             x += 370;
            break;
               
            case 3:
             prev += 400;
             x += 300;
            break;

            case 4:
             prev += 400;
             x += 400;
            break;
        }
        if(x > prev){random = prev + (std::rand() % (x - prev + 1));}
        else{random = prev;}
    }
}