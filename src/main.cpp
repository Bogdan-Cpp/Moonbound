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
#include "levels.h"

int main(){
    bool isStartMenu = true;
    bool isGameMenu = false;
    bool isInfoMenu = false;
    bool isPauseMenu = false;
    bool isBluescreen = false;
    bool devMode = true;

    int setLevel = 0;

    long long count = 0;
    long long prev = 0;
    long long best = 0;
    float prevSpeed;

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Moonbound");
    window.setFramerateLimit(120);
    window.setVerticalSyncEnabled(true);

    //class apelation
    Level lv;
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
    sf::View camera(sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(1920.f, 1080.f)));
    sf::Music *startMusic = new sf::Music();
    int x = 3000;
    std::vector<GPU> graphics;
    std::vector<CPU> centralUnit;
    std::vector<MB> motherboard;
    
    std::vector<Ssd> storage2;
    std::vector<GPU> graphics2;
    std::vector<CPU> centralUnit2;
    std::vector<MB> motherboard2;
    std::srand(std::time(nullptr));
   
    lv.level1(x, gpuTexture, graphics, cpuTexture, centralUnit, count, motherboard, mbTexture);
    lv.level2(storage2, x, ssdTexture, gpuTexture, graphics2, cpuTexture, centralUnit2, count, motherboard2, mbTexture);
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
            std::cout << getX << '\n';
            
            if(isBluescreen){
                //if is bluescreen
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
                //normal
                prevSpeed = 10.f;
                py.speed = prevSpeed;
                
                if(getX < 15000){
                    setLevel = 1;
                }
                else if(getX > 15000){
                    setLevel = 2;
                }      
                if(getX > 15000 && !graphics.empty() && !centralUnit.empty() && !motherboard.empty()){
                    graphics.clear();
                    centralUnit.clear();
                    motherboard.clear();
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
            
            //coliziune
            if(devMode){
                switch(setLevel){
                    case 1:
                    for(auto &obstacle2 : graphics){
                        obstacle2.gpuColide(player, sr, isGameMenu, count, prev, best, isBluescreen);
                    }
                    for(auto &obstacle2 : centralUnit){
                        obstacle2.cpuColide(player, sr, isGameMenu, count, prev, best, isBluescreen);
                    }
                    for(auto &obstacle4 : motherboard){
                        obstacle4.mbColide(player, sr, isGameMenu, count, prev, best, isBluescreen);
                    }
                    break;

                    case 2:
                    for(auto &obstacle1 : storage2){
                        obstacle1.ssdColide(player, sr, isGameMenu, count, prev, best, isBluescreen);
                    }
                    for(auto &obstacle2 : graphics2){
                        obstacle2.gpuColide(player, sr, isGameMenu, count, prev, best, isBluescreen);
                    }
                    for(auto &obstacle2 : centralUnit2){
                        obstacle2.cpuColide(player, sr, isGameMenu, count, prev, best, isBluescreen);
                    }
                    for(auto &obstacle4 : motherboard2){
                        obstacle4.mbColide(player, sr, isGameMenu, count, prev, best, isBluescreen);
                    }
                    break;
                    //level3
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
            switch(setLevel){
                case 1:
                for(auto &graphic : graphics){
                    graphic.drawGpu(window);
                }
                for(auto &procesores : centralUnit){
                    procesores.drawCpu(window);
                }
                for(auto &motherboards : motherboard){
                    motherboards.drawMb(window);
                }
                break;

                case 2:
                for(auto &storages : storage2){
                    storages.drawSsd(window);
                }
                for(auto &graphic : graphics2){
                    graphic.drawGpu(window);
                }
                for(auto &procesores : centralUnit2){
                    procesores.drawCpu(window);
                }
                for(auto &motherboards : motherboard2){
                    motherboards.drawMb(window);
                }
                break;
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