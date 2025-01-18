#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <optional>

#include "menus/mainm.h"
#include "menus/settingsm.h"
#include "menus/infom.h"
#include "menus/startm.h"

#include "player.h"
#include "map/ground.h"

int main(){
    //variabile generale
    bool isStartMenu = true;
    bool isStartGame = false;
    bool isSettingsMenu = false;
    bool isInfoButton = false;
    bool canPressButton = true;

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Moonbound");
    window.setFramerateLimit(60);

    //class apelation
    Start sr;
    Info in;
    Settings st;
    MenuS *menuStart = new MenuS();
    Player py;
    Ground gr;
    sf::Image image;
    sf::Font fStart;
    sf::RectangleShape box;
    sf::RectangleShape ground1;
    sf::View camera(sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(1920.f, 1080.f)));
    
    sf::Music *startMusic = new sf::Music();

    //function declaration
    py.PlayerBuild(box);
    
    //file verification
    if(!fStart.loadFromFile("../assets/startFont.ttf")){return -1;}
    if(!startMusic->openFromFile("../assets/music.ogg")){return -1;}
    if(!image.loadFromFile("../assets/gameIcon.png")){return -1;}

    window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
    startMusic->play();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        if(isStartGame){
            py.PlayerMove(box);
            camera.setCenter(box.getPosition());
            window.setView(camera);
        }

        //function
        st.settingsButton(menuStart, isSettingsMenu, isStartMenu, isInfoButton, canPressButton);
        in.infoButton(menuStart, isSettingsMenu, isInfoButton, isSettingsMenu, canPressButton);
        sr.startButton(menuStart, startMusic, isStartMenu, isStartGame, isSettingsMenu, isInfoButton, canPressButton);

        window.clear(sf::Color::Black);

        if(isStartMenu && menuStart != nullptr){
            menuStart->startMenu(window, fStart);
        }
        if(isStartGame){
            gr.Object(window, ground1);
            py.PlayerDeclaration(window, box);
        }
        if(isSettingsMenu){
            st.settingsMenuDraw(window, fStart);
        }
        if(isInfoButton){
            in.infoMenuDraw(window, fStart);
        } 

        window.display();
    }
    return 0;
}