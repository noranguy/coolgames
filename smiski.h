//
// Created by nguye on 6/22/2024.
//
#include <iostream>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
using namespace std;

#ifndef SFMLTRAINING_SMISKI_H
#define SFMLTRAINING_SMISKI_H
class smiski{
private:
    //dont edit size (texture)
    int size = 195;
    float smallScale = .475;
    float mainScale = 1.25;
    sf::Vector2f mainDisplay = {800, 300};
    sf::Vector2f firstShelfPos={110,115};
    sf::Vector2f secondShelfPos={110,275};
    sf::Vector2f thirdShelfPos = {110, 435};
    int spacing = 95;
public:
    sf::Texture atWorktexture, cheerTexture, dressTexture;
    sf::Sprite work1Smiski, work2Smiski,work3Smiski, work4Smiski, work5Smiski, work6Smiski,
    cheer1Smiski,cheer2Smiski,cheer3Smiski,cheer4Smiski,cheer5Smiski,cheer6Smiski,
    dress1Smiski,dress2Smiski,dress3Smiski,dress4Smiski,dress5Smiski,dress6Smiski;
    vector<sf::Sprite> atWorkCollection = {work1Smiski, work2Smiski,work3Smiski, work4Smiski, work5Smiski, work6Smiski};
    vector<sf::Sprite> cheerCollection = {cheer1Smiski,cheer2Smiski,cheer3Smiski,cheer4Smiski,cheer5Smiski,cheer6Smiski};
    vector<sf::Sprite> dressCollection = {dress1Smiski,dress2Smiski,dress3Smiski,dress4Smiski,dress5Smiski,dress6Smiski};
    map<int, string> locateName = {{0,"Approving"},{1,"Researching"}, {2, "Presenting"},{3,"Good Idea"}, {4, "On the Road"},{5,"Little Group Think"},
                                   {6,"On Your Side"},{7,"Dancing"}, {8, "Cheerleading"},{9,"Marching"}, {10, "On Drums"},{11,"Cheering"},
                                    {12, "Underpants"}, {13,"Struggling"},{14, "Loose Pants"},{15,"Putting On Socks"},{16, "Sweater"},{17,"Tight Pants"}};
    smiski(sf::Vector2f scaleOfwindow) {
        setScale(scaleOfwindow);
        atWorktexture.loadFromFile("./smiskiTextures/atWorkSeriesedited.png");
        cheerTexture.loadFromFile("./smiskiTextures/cheerSmiskis.png");
        dressTexture.loadFromFile("./smiskiTextures/dressingSmiskisedited.png");
        loadTextures(atWorkCollection, atWorktexture);
        loadTextures(cheerCollection, cheerTexture);
        loadTextures(dressCollection, dressTexture);
        loadSmiski(atWorkCollection, firstShelfPos);
        loadSmiski(cheerCollection, secondShelfPos);
        loadSmiski(dressCollection, thirdShelfPos);
    }
    void setScale(sf::Vector2f scaleWindow){
        float avgwindowScale = (scaleWindow.x+scaleWindow.y)/2;
        smallScale = smallScale*avgwindowScale;
        mainScale = mainScale*avgwindowScale;
        firstShelfPos.x = firstShelfPos.x *scaleWindow.x;
        firstShelfPos.y = firstShelfPos.y *scaleWindow.y;
        secondShelfPos.x = secondShelfPos.x *scaleWindow.x;
        secondShelfPos.y = secondShelfPos.y *scaleWindow.y;
        thirdShelfPos.x = thirdShelfPos.x *scaleWindow.x;
        thirdShelfPos.y = thirdShelfPos.y *scaleWindow.y;
        mainDisplay.x = mainDisplay.x *scaleWindow.x;
        mainDisplay.y = mainDisplay.y *scaleWindow.y;
        spacing = spacing*avgwindowScale;
    }
    void loadTextures(vector<sf::Sprite>& collection, sf::Texture& texture){
        //top left, middle, right, bottom left, middle, right
        vector<vector<int>> coordOnTexture {{22,65}, {240, 65}, {458,65}, {22,342},{240,342},{458,342}};
        for(int i = 0; i<collection.size(); i++){
            collection[i].setTexture(texture);
            collection[i].setTextureRect(sf::IntRect (coordOnTexture[i][0], coordOnTexture[i][1],size,size));
        }
    }
    void loadSmiski(vector<sf::Sprite>& collection, sf::Vector2f& position){
        for(int i = 0; i<collection.size(); i++){
            collection[i].scale(sf::Vector2f(smallScale,smallScale));
            collection[i].setOrigin(size/2,size/2);
            collection[i].setPosition(position.x+i*spacing, position.y);
        }
    }
    void drawTrueSmiski(sf::RenderWindow& window, vector<bool> ifTrue, string collection){
        for(int i = 0; i<ifTrue.size(); i++){
            if(collection == "At Work" && ifTrue[i]){
                window.draw(atWorkCollection[i]);
            } else if (collection == "Cheer" && ifTrue[i]) {
                window.draw(cheerCollection[i]);
            } else if (collection == "Dressing" && ifTrue[i]){
                window.draw(dressCollection[i]);
            }
        }
    }
    void drawMainDisplay(sf::RenderWindow& window, sf::Sprite sprite2Display){
        sf::Sprite mainDisplaySprite = sprite2Display;
        //670, 100
        mainDisplaySprite.setScale(mainScale,mainScale);
        mainDisplaySprite.setPosition(mainDisplay.x,mainDisplay.y);
        window.draw(mainDisplaySprite);
    }
};
#endif //SFMLTRAINING_SMISKI_H
