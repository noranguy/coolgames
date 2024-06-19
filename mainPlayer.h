//
// Created by nguye on 6/17/2024.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef SFMLTRAINING_MAINPLAYER_H
#define SFMLTRAINING_MAINPLAYER_H

class player{
private:
    int movementMultiplier = 25;
    int spriteSizeX = 460;
    int spriteSizeY = 600;
    float spriteScale = 0.3;

public:
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    player(int windowX, int windowY){
        playerSprite.setOrigin(spriteSizeX/2, spriteSizeY/2);
        playerSprite.setPosition(windowX/2, windowY/2);
        playerSprite.scale(sf::Vector2f(spriteScale,spriteScale));
        loadTextures();
    };
    void loadTextures(){
        playerTexture.loadFromFile("./playertextures/mainplayerTest.png");
    }
    void loadSprite(int xPos, int yPos){
        playerSprite.setTexture(playerTexture);
        playerSprite.setTextureRect(sf::IntRect(spriteSizeX* xPos,spriteSizeY*yPos,spriteSizeX,spriteSizeY));
    }
    void moveSprite(int x, int y){
        sf::Vector2f position = playerSprite.getPosition();
        playerSprite.setPosition(position + sf::Vector2f(x*movementMultiplier, y*movementMultiplier));
    }
    void drawSprite(bool cond, sf::RenderWindow& window){
        if (cond){
            window.draw(playerSprite);
        }
    }
};
#endif //SFMLTRAINING_MAINPLAYER_H
