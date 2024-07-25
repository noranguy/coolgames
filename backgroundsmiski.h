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
    sf::Vector2f scale2window = {.765,.765};
    sf::Vector2f imagePos = {1342,1004};
    //text
    float textSize = 18;
    float space = 25;
    sf::Vector2f textPosition = {680,520};
    //red button (x & leave)
    float redButtonSize = 50;
    sf::Vector2f xbuttonPosition = {800,632};
    sf::Vector2f leaveButtonPosition = {75, 675};
    //start button
    sf::Vector2f startButtonSize = {370,100};
    sf::Vector2f startButtonPosition = {512, 400};
    //texture dont edit
    sf::Vector2i unClickedRedButton = {243,116};
    sf::Vector2i unClickedLeaveButton = {2,2};
public:
    sf::Texture smiskiBackgroundTexture, removeCollectionTexture, startButtonTexture, leaveButtonTexture;
    sf::Sprite smiskiBackgroundSprite, removeCollectionButton, startButton, leaveButton;
    sf::Font mainDisplayfont;
    sf::Text collection, title, positionText;
    vector<sf::Text> mainDisplayText = {collection, title, positionText};
    background(sf::Vector2f windowSize, sf::Vector2f scaleOfwindow){
        //Loading from File
        smiskiBackgroundTexture.loadFromFile("./smiskiTextures/smiskiBackground.jpg");
        removeCollectionTexture.loadFromFile("./smiskiTextures/redButtonsprites.png");
        startButtonTexture.loadFromFile("./smiskiTextures/startButton.png");
        leaveButtonTexture.loadFromFile("./smiskiTextures/redButtonsprites.png");
        //set scale
        setScale(scaleOfwindow);
        //initial background
        makeSprite(smiskiBackgroundSprite, smiskiBackgroundTexture,windowSize,imagePos,scale2window);
        //remove Button
        makeSprite(removeCollectionButton, removeCollectionTexture, xbuttonPosition, sf::Vector2f {redButtonSize/2, redButtonSize/2}, scaleOfwindow);
        removeCollectionButton.setTextureRect(sf::IntRect(unClickedRedButton.x, unClickedRedButton.y, redButtonSize, redButtonSize));
        //start button
        makeSprite(startButton, startButtonTexture, startButtonPosition, sf::Vector2f{startButtonSize.x/2, startButtonSize.y/2},scaleOfwindow);
        //leave button
        makeSprite(leaveButton, leaveButtonTexture, leaveButtonPosition, sf::Vector2f {redButtonSize/2, redButtonSize/2}, scaleOfwindow);
        leaveButton.setTextureRect(sf::IntRect(unClickedLeaveButton.x, unClickedLeaveButton.y, redButtonSize, redButtonSize));
        //make text
        makeText();
    };
    void setScale(sf::Vector2f scaleWindow){
        float avgwindowScale = (scaleWindow.x+scaleWindow.y)/2;
        textSize = textSize*avgwindowScale;
        textPosition.x = textPosition.x*scaleWindow.x;
        textPosition.y = textPosition.y*scaleWindow.y;
        space = space* avgwindowScale;
        xbuttonPosition.x = xbuttonPosition.x*scaleWindow.x;
        xbuttonPosition.y = xbuttonPosition.y*scaleWindow.y;
    }
    void makeSprite(sf::Sprite& sprite2Make, sf::Texture& texture2Use, sf::Vector2f position, sf::Vector2f origin,sf::Vector2f scale){
        sprite2Make.setTexture(texture2Use);
        sprite2Make.setPosition(position);
        sprite2Make.setOrigin(origin);
        sprite2Make.scale(scale);
    }
    void makeText(){
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
    void redButtonDraw(sf::RenderWindow& window, sf::Sprite& redButton, sf::Vector2i texturePosition, int redButton2Display){
        if(redButton2Display==0){
            redButton.setTextureRect(sf::IntRect(texturePosition.x, texturePosition.y, redButtonSize,redButtonSize));
        } else{
            redButton.setTextureRect(sf::IntRect(texturePosition.x+52, texturePosition.y, redButtonSize,redButtonSize));
        }
        window.draw(redButton);
    }
    void backgroundDraw(sf::RenderWindow& window, bool background2Display){
        if(background2Display){
            smiskiBackgroundTexture.loadFromFile("./smiskiTextures/smiskibackground.jpg");
        } else {
            smiskiBackgroundTexture.loadFromFile("./smiskiTextures/smiskiOpenScreen.png");
        }
        smiskiBackgroundSprite.setTexture(smiskiBackgroundTexture);
        window.draw(smiskiBackgroundSprite);
    }
    sf::Vector2i getTexture(int typeOftexture){
        if(typeOftexture == 0){
            return unClickedRedButton;
        } else if (typeOftexture == 1){
            return unClickedLeaveButton;
        }
    }
};
#endif //SFMLTRAINING_BACKGROUNDSMISKI_H
