//
// Created by nguye on 6/18/2024.
//
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
#ifndef SFMLTRAINING_TEXTBOX_H
#define SFMLTRAINING_TEXTBOX_H

class textboxclass{
private:
//    float spriteScale = 0.5;
public:
    sf::Texture textboxTexture;
    sf::Sprite textboxSprite;
    textboxclass(int windowX, int windowY){
        textboxSprite.setPosition(0, windowY-400);
        textboxSprite.scale(sf::Vector2f(0.9,1));
        loadTextures();
    };
    void loadTextures(){
        textboxTexture.loadFromFile("./playertextures/textboxpng.png");

    }
    void loadSprite(){
        textboxSprite.setTexture(textboxTexture);
    }

    void drawSprite(bool cond, sf::RenderWindow& window){
        if (cond){
            window.draw(textboxSprite);
        }
    }
};
class text2display{
private:

public:
    int sceneNumber;
    sf::Font font;
    sf::Text text;

    text2display(int windowX, int windowY){
        font.loadFromFile("./fonts/SuperPixel-m2L8j.ttf");
        sceneNumber = 0;
        text.setPosition(150, windowY-300);
        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
    }
    int incSceneNumber(){
        sceneNumber++;
    }
    void runSceneText(int scene2display){
        string sceneTextReturn;
        if(scene2display == 0){
            sceneTextReturn = "first scene";
        }
        incSceneNumber();
        text.setString(sceneTextReturn);
    }
    void drawText(bool cond, sf::RenderWindow& window){
        if (cond){
            window.draw(text);
        }
    }

};
#endif //SFMLTRAINING_TEXTBOX_H
