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
#include "motherboard.h"

void level1(std::vector<Ssd> &storage, int &x, sf::Texture &ssdTexture, sf::Texture &gpuTexture, std::vector<GPU> &graphics, sf::Texture &cpuTexture, std::vector<CPU> &centralUnit, long long &count, std::vector<MB> &motherboard, sf::Texture &mbTexture);

int main(){
    std::string bios1 = "No";
    std::string windows1 = "No";
    std::string build1 = "No";

    bool isStartMenu = true;
    bool isGameMenu = false;
    bool isInfoMenu = false;
    bool isPauseMenu = false;
    bool isBluescreen = false;
    bool devMode = false;

    bool biosUpdate = false;
    bool windowsUpdate = false;
    bool buildPc = false;

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
    sf::Texture mbTexture;
    sf::Font fStart;
    sf::Font fPause;
    sf::RectangleShape player;
    sf::RectangleShape floor1;
    sf::Sprite blueScreen;
    Player py;
    sf::Image image;
    sf::Text oc("Overclocking: an extreme sport\n for PCs!", fPause, 40);
    sf::Text start("Update your BIOS! \n colect the TOOL", fPause, 30);
    sf::Text bios("Bios Updated: " + bios1, fPause, 20);
    sf::Text windows("Windows Updated: " + windows1, fPause, 20);
    sf::Text build("Build finished: " + build1, fPause, 20);
    sf::View camera(sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(1920.f, 1080.f)));
    sf::Music *startMusic = new sf::Music();
    int x = 3000;
    std::vector<Ssd> storage;
    std::vector<GPU> graphics;
    std::vector<CPU> centralUnit;
    std::vector<MB> motherboard;
    std::srand(std::time(nullptr));
   
    level1(storage, x, ssdTexture, gpuTexture, graphics, cpuTexture, centralUnit, count, motherboard, mbTexture);
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
    oc.setPosition(16000.f, 1700.f);
    start.setPosition(1500.f, 1920.f);
    blueScreen.setTexture(bluescreenTexture);
    blueScreen.setScale(1.f, 1.f);
    bios.setFillColor(sf::Color(120.f, 120.f, 120.f));
    windows.setFillColor(sf::Color(120.f, 120.f, 120.f));
    build.setFillColor(sf::Color(120.f, 120.f, 120.f));

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
            bios.setPosition(getX - 700.f, 2360.f);
            windows.setPosition(getX - 700.f, 2390.f);
            build.setPosition(getX - 700.f, 2420.f);
            
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
                    stor.ssdColide(player, sr, isGameMenu, count, prev, best, isBluescreen, biosUpdate, windowsUpdate, buildPc);
                }
                for(auto &stor1 : graphics){
                    stor1.gpuColide(player, sr, isGameMenu, count, prev, best, isBluescreen, biosUpdate, windowsUpdate, buildPc);
                }
                for(auto &stor2 : centralUnit){
                    stor2.cpuColide(player, sr, isGameMenu, count, prev, best, isBluescreen, biosUpdate, windowsUpdate, buildPc);
                }
                for(auto &stor3 : motherboard){
                    stor3.mbColide(player, sr, isGameMenu, count, prev, best, isBluescreen, biosUpdate, windowsUpdate, buildPc);
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
            window.draw(start);

            for(auto &storages : storage){
                storages.drawSsd(window);
            }
            for(auto &graphic : graphics){
                graphic.drawGpu(window);
            }
            for(auto &procesores : centralUnit){
                procesores.drawCpu(window);
            }
            for(auto &motherboards : motherboard){
                motherboards.drawMb(window);
            }

            if(isPauseMenu){
                pa->drawPause(fPause, window, getX);
            }
            if(isBluescreen){
                window.draw(blueScreen);
            }
            window.draw(bios);
            window.draw(windows);
            window.draw(build);
        }

        else if(isInfoMenu && in != nullptr){
            in->infoMenuDraw(window, fStart);
        }

        window.display();
    }
    
    return 0;
}

void level1(std::vector<Ssd> &storage, int &x, sf::Texture &ssdTexture, sf::Texture &gpuTexture, std::vector<GPU> &graphics, sf::Texture &cpuTexture, std::vector<CPU> &centralUnit, long long &count, std::vector<MB> &motherboard, sf::Texture &mbTexture){
    int prev = 0;
    int random = x;
    int level1;
    int obstacle;
    int yRandom;
    //at poz.x 30.000
    for(int i = 0; i <= 20; i++){
        obstacle = std::rand() % 4;
        
        switch(obstacle){
            case 0:
             motherboard.push_back(MB(random, 1920, mbTexture));
            break;

            case 1:
             motherboard.push_back(MB(random, 1920, mbTexture));
            break;

            case 2:
             motherboard.push_back(MB(random, 1920, mbTexture));
            break;
            
            case 3:
             graphics.push_back(GPU(random, 1920, 0, gpuTexture));
             centralUnit.push_back(CPU(random + 50, 1945, cpuTexture));
            break;
        }
        level1 = std::rand() % 5;
        prev = x;
        x = random;

        switch(level1){
            case 0:
             prev += 600;
             x += 400;
            break;
               
            case 1:
             prev += 560;
             x += 480;
            break;

            case 2:
             prev += 490;
             x += 560;
            break;
               
            case 3:
             prev += 670;
             x += 460;
            break;

            case 4:
             prev += 580;
             x += 400;
            break;
        }
        if(x > prev){random = prev + (std::rand() % (x - prev + 1));}
        else{random = prev;}
    }
}