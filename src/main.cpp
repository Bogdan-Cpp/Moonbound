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
#include <filesystem>
#include "menus/mainm.h"
#include "menus/infom.h"
#include "menus/startm.h"
#include "player.h"
#include "obstacle.h"

void Algorithm(bool &yes, sf::Texture &winTexture1, sf::Texture &winTexture2,
    sf::Texture &winTexture3, sf::Texture &winTexture4, sf::Texture &cpuTexture,
    sf::Texture &gpuTexture, sf::Texture &ssdTexture, sf::Texture &mbTexture,
    sf::Texture &virusTexture, sf::Texture &virusTexture2, sf::Texture &winTexture5,
    sf::Texture &winTexture6, sf::Texture &winTexture7, sf::Texture &winTexture8,
    sf::Texture &winTexture9, float &x, std::vector<OBS> &obstacle);

int main(){
    bool isStartMenu = true;
    bool isGameMenu = false;
    bool isInfoMenu = false;
    bool isPauseMenu = false;
    bool isBluescreen = false;
    bool yes = true;
    bool shouldChange = true;
    bool devMode = false;

    int setLevel = 0;

    long long count = 0;
    long long prev = 0;
    long long best = 0;
    float playerSize = 50.f;
    int stage = 1;

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Moonbound");
    window.setFramerateLimit(120);
    window.setVerticalSyncEnabled(true);

    //class apelation
    Start *sr = new Start();
    Info *in = new Info();
    MenuS *ms = new MenuS();
    sf::Music gameMusic;
    sf::Music *bluescreenMusic = new sf::Music();
    
    delete sr;
    delete in;
    delete bluescreenMusic;
    bluescreenMusic = nullptr;
    sr = nullptr;
    in = nullptr;
    
    sf::Texture cpuTexture;
    sf::Texture gpuTexture;
    sf::Texture ssdTexture;
    sf::Texture bluescreenTexture;
    sf::Texture mbTexture;
    sf::Texture virusTexture;
    sf::Texture virusTexture2;
    sf::Texture winTexture1;
    sf::Texture winTexture2;
    sf::Texture winTexture3;
    sf::Texture winTexture4;
    sf::Texture winTexture5;
    sf::Texture winTexture6;
    sf::Texture winTexture7;
    sf::Texture winTexture8;
    sf::Texture winTexture9;
    sf::Texture moonTexture;
    sf::Texture pauseTexture;
    sf::Texture backgroundT;
    sf::Texture backgroundT2;
    sf::Texture backgroundT3;
    sf::Sprite back;
    sf::Sprite back2;
    sf::Sprite back3;
    sf::Font fStart;
    sf::Font fPause;
    sf::RectangleShape player;
    sf::RectangleShape floor1;
    sf::Sprite blueScreen;
    sf::Sprite moonbound;
    sf::Sprite pause;
    Player py;
    sf::View camera(sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(1920.f, 1080.f)));
    sf::Music *startMusic = new sf::Music();
    sf::Image image;
    bool isTrue = false;
    float x = 2000;
    float backSpeed = 0;
    float remember1 = 35000;
    float remember2 = 70000;
    float remember3 = 105000;
    int a = 35000;
    int b = 70000;
    int c = 105000;
    
    std::vector<OBS> obstacle;

    std::srand(std::time(nullptr));

    py.PlayerBuild(player, playerSize);
    float yPoz = player.getPosition().y;

    //file verification
    if(!fStart.loadFromFile("../assets/startFont.ttf")){
        if(!fStart.loadFromFile("../share/startFont.ttf")){
            return -1;
        }
    }
    if(!fPause.loadFromFile("../assets/pauseFont.ttf")){
        if(!fPause.loadFromFile("../share/pauseFont.ttf")){
            return -1;
        }
    }
    if(!startMusic->openFromFile("../assets/music.ogg")){
        if(!startMusic->openFromFile("../share/music.ogg")){
            return -1;
        }
    }
    if(!gameMusic.openFromFile("../assets/gameMusic2.ogg")){
        if(!gameMusic.openFromFile("../share/gameMusic2.ogg")){
            return -1;
        }
    }
    if(!image.loadFromFile("../assets/gameIcon.png")){
        if(!image.loadFromFile("../share/gameIcon.png")){
            return -1;
        }
    }
    if(!bluescreenTexture.loadFromFile("../assets/bluescreen1.png")){
        if(!bluescreenTexture.loadFromFile("../share/bluescreen1.png")){
            return -1;
        }
    }
    if(!moonTexture.loadFromFile("../assets/moonbound.png")){
        if(!moonTexture.loadFromFile("../share/moonbound.png")){
            return -1;
        }
    }
    if(!pauseTexture.loadFromFile("../assets/pause.png")){
        if(!pauseTexture.loadFromFile("../share/pause.png")){
            return -1;
        }
    }
    if(!backgroundT.loadFromFile("../assets/spacedraw3.png")){
        if(!backgroundT.loadFromFile("../share/spacedraw3.png")){
            return -1;
        }
    }
    if(!backgroundT2.loadFromFile("../assets/spacedraw2.png")){
        if(!backgroundT2.loadFromFile("../share/spacedraw2.png")){
            return -1;
        }
    }
    if(!backgroundT3.loadFromFile("../assets/spacedraw1.png")){
        if(!backgroundT3.loadFromFile("../share/spacedraw1.png")){
            return -1;
        }
    }

    window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
    startMusic->play();
    blueScreen.setTexture(bluescreenTexture);
    blueScreen.setScale(1.f, 1.f);
    moonbound.setTexture(moonTexture);
    moonbound.setScale(1.5f, 1.5f);
    moonbound.setPosition(1000.f, 150.f);
    pause.setTexture(pauseTexture);
    pause.setScale(1.f, 1.f);
    back.setTexture(backgroundT);
    back.setScale(1.f, 1.f);
    back2.setTexture(backgroundT2);
    back2.setScale(1.f, 1.f);
    back3.setTexture(backgroundT3);
    back3.setScale(1.f, 1.f);

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
            sr->Background(backSpeed, getX, a, b, c, back, back2, back3);
            sr->Pozitioning(window, py, camera, player, yPoz, getX, playerSize, floor1, sr, blueScreen);
        
            if(getX <= x && yes){
               Algorithm(yes, winTexture1, winTexture2, winTexture3, winTexture4, cpuTexture, gpuTexture, ssdTexture, mbTexture, virusTexture, virusTexture2, winTexture5, winTexture6, winTexture7, winTexture8, winTexture9, x, obstacle);
            }
            
            if(getX >= x && !yes){
                obstacle.clear();
                yes = true;
                x += 50;
                py.speed += 1;
            }

            if(isBluescreen){
                sr->blueScreen(bluescreenMusic, count, isBluescreen, gameMusic, py);
            }
            else{
                count += 1;
                if(!devMode){
                    for(auto &obstacle1 : obstacle){
                        obstacle1.obsColide(player, sr, isGameMenu, count, prev, best, isBluescreen, x);
                    }
                }
                if(gameMusic.getStatus() != sf::Music::Playing){gameMusic.play();}
            }
        }
        
        //draw
        window.clear(sf::Color::Black);
        if(isStartMenu && ms != nullptr){
            window.draw(moonbound);
            ms->startMenu(window, fStart);
        }
        
        else if(isGameMenu && sr != nullptr){
            window.draw(back);
            window.draw(back2);
            window.draw(back3);
            sr->Scor(fStart, window, getX, count, prev, best);
            sr->ObjectDraw(window, floor1, player);
            
            for(auto &obs : obstacle){
                obs.drawObs(window);
            }
            if(isPauseMenu){
                window.draw(pause);
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

void Algorithm(bool &yes, sf::Texture &winTexture1, sf::Texture &winTexture2,
    sf::Texture &winTexture3, sf::Texture &winTexture4, sf::Texture &cpuTexture,
    sf::Texture &gpuTexture, sf::Texture &ssdTexture, sf::Texture &mbTexture,
    sf::Texture &virusTexture, sf::Texture &virusTexture2, sf::Texture &winTexture5,
    sf::Texture &winTexture6, sf::Texture &winTexture7, sf::Texture &winTexture8,
    sf::Texture &winTexture9, float &x, std::vector<OBS> &obstacle){
    
    x += 1000;
    yes = false;
    for(int i = 0; i <= 20; i++){
        int position = std::rand() % 3;
                
        obstacle.push_back(OBS(x, 1920, winTexture1, winTexture2, winTexture3, winTexture4, cpuTexture,
        gpuTexture, ssdTexture, mbTexture, virusTexture, virusTexture2, winTexture5, winTexture6,
        winTexture7, winTexture8, winTexture9));
                
        switch(position){
            case 0: x += 1000; break;
            case 1: x += 600; break;
            case 2: x += 900; break;
        }
    }
}