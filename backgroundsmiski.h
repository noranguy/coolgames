//
// Created by nguye on 6/19/2024.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
using namespace std;
#ifndef SFMLTRAINING_BACKGROUNDSMISKI_H
#define SFMLTRAINING_BACKGROUNDSMISKI_H
class background{
private:
    float scale = .765;
    sf::Vector2i imagePos = {1342,1004};
    int textSize = 18;
    int space = 25;
    sf::Vector2f textPosition = {680,520};
    int redButtonSize = 50;
    sf::Vector2f buttonPosition = {800,632};
    //texture dont edit
    sf::Vector2i unClickedRedButton = {243,116};
    sf::Vector2i clickedRedButton = {293,116};
public:
    sf::Texture smiskiBackgroundTexture, removeCollectionTexture;
    sf::Sprite smiskiBackgroundSprite, removeCollectionButton;
    sf::Font mainDisplayfont;
    sf::Text collection, title, positionText;
    vector<sf::Text> mainDisplayText = {collection, title, positionText};
    background(sf::Vector2f windowSize, sf::Vector2f scaleOfwindow){
        float avgwindowScale = (scaleOfwindow.x+scaleOfwindow.y)/2;
        textSize = textSize*avgwindowScale;
        textPosition.x = textPosition.x*scaleOfwindow.x;
        textPosition.y = textPosition.y*scaleOfwindow.y;
        space = space* avgwindowScale;
        buttonPosition.x = buttonPosition.x*scaleOfwindow.x;
        buttonPosition.y = buttonPosition.y*scaleOfwindow.y;
        makeBackground(windowSize);
        makeRemove(scaleOfwindow);
        makeText();
    };
    void makeBackground(sf::Vector2f windowSize){
        //smiski background
        smiskiBackgroundTexture.loadFromFile("./smiskiTextures/smiskibackground.jpg");
        smiskiBackgroundSprite.setTexture(smiskiBackgroundTexture);
        smiskiBackgroundSprite.setPosition(windowSize.x/2,windowSize.y/2);
        smiskiBackgroundSprite.setOrigin(imagePos.x/2,imagePos.y/2);
        smiskiBackgroundSprite.scale(scale,scale);
    }
    void makeRemove(sf::Vector2f windowScale) {
        //remove button
        removeCollectionTexture.loadFromFile("./smiskiTextures/redButtonsprites.png");
        removeCollectionButton.setTexture(removeCollectionTexture);
        removeCollectionButton.setTextureRect(
                sf::IntRect(unClickedRedButton.x, unClickedRedButton.y, redButtonSize, redButtonSize));
        removeCollectionButton.setOrigin(redButtonSize / 2, redButtonSize / 2);
        removeCollectionButton.scale(windowScale.x, windowScale.y);
        removeCollectionButton.setPosition(buttonPosition.x, buttonPosition.y);
    }
    void makeText(){
        //font
        mainDisplayfont.loadFromFile("./fonts/arial.ttf");
        for(int i = 0; i<mainDisplayText.size();i++){
            mainDisplayText[i].setFont(mainDisplayfont);
            mainDisplayText[i].setCharacterSize(textSize);
            mainDisplayText[i].setFillColor(sf::Color::Black);
            mainDisplayText[i].setPosition(textPosition.x,textPosition.y);
            mainDisplayText[i].setStyle(sf::Text::Bold);
            textPosition.y = textPosition.y + space;
        }
    }
    void mainDisplayTextFunc(sf::RenderWindow& window,string collectionName, string textTitle, string position){
        string titleString = "Smiski "+ textTitle;
        string positionString = "Position: "+ position;
        mainDisplayText[0].setString(collectionName);
        mainDisplayText[1].setString(titleString);
        mainDisplayText[2].setString(positionString);
        for (int i = 0; i<mainDisplayText.size();i++){
            window.draw(mainDisplayText[i]);
        }
    }
    void removeButtonDraw(sf::RenderWindow& window, int redButton2Display){
        if(redButton2Display==0){
            removeCollectionButton.setTextureRect(sf::IntRect(unClickedRedButton.x, unClickedRedButton.y, redButtonSize,redButtonSize));
        } else{
            removeCollectionButton.setTextureRect(sf::IntRect(clickedRedButton.x, clickedRedButton.y, redButtonSize,redButtonSize));
        }
        window.draw(removeCollectionButton);
    }
};
#endif //SFMLTRAINING_BACKGROUNDSMISKI_H
