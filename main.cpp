#include <iostream>
#include <SFML/Graphics.hpp>
#include "mainPlayer.h"
#include "textbox.h"
using namespace std;



int main() {
    int windowSize_x = 1024;
    int windowSize_y = 1024;
    sf::RenderWindow window(sf::VideoMode(windowSize_x, windowSize_y), "SFML Works!");
    player mainPlayer(windowSize_x, windowSize_y);
    textboxclass textbox(windowSize_x,windowSize_y);
    text2display textShown(windowSize_x,windowSize_y);
    int x = 0;
    int y = 1;
    bool drawSpriteCon = true;
    bool drawText = false;
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            //player movement
            } else if(event.type == sf::Event::KeyPressed){
                // player moves down
                sf::Vector2f position = mainPlayer.playerSprite.getPosition();
                if(event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down){
                    mainPlayer.loadSprite(x,0);
                    mainPlayer.moveSprite(0,1);
                // player moves right
                } else if(event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right){
                    mainPlayer.loadSprite(x,1);
                    mainPlayer.moveSprite(1,0);
                // player moves left
                } else if(event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left){
                    mainPlayer.loadSprite(y,2);
                    mainPlayer.moveSprite(-1,0);
                //player moves up
                } else if(event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up){
                    mainPlayer.loadSprite(x,3);
                    mainPlayer.moveSprite(0,-1);
                } else if(event.key.code == sf::Keyboard::E){
                    drawSpriteCon = false;
                    textbox.loadSprite();
                    textShown.runSceneText(0);
                    drawText = true;
                }
            } else if (event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down){
                    mainPlayer.loadSprite(1,0);
                    // player moves right
                } else if(event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right){
                    mainPlayer.loadSprite(1,1);
                    // player moves left
                } else if(event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left){
                    mainPlayer.loadSprite(0,2);
                    //player moves up
                } else if(event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up){
                    mainPlayer.loadSprite(1,3);
                }
            }
        }
        if (x == 0){
            x = 2;
        }else if (x ==2){
            x = 0;
        }
        if (y == 1){
            y = 3;
        } else if (y ==3){
            y=1;
        }
        window.clear();
        mainPlayer.drawSprite(drawSpriteCon, window);
        textbox.drawSprite(drawText, window);
        textShown.drawText(drawText, window);
        window.display();
    }
    return 0;
}