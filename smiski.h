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
struct smiskiProperties{
    sf::Sprite smiskiSpriteName;
    int positionOnShelf;
    string CollectionName;
    string title;
};
class smiski{
private:
    //dont edit size (texture)
    int size = 195;
    float smallScale = .475;
    float mainScale = 1.25;
    sf::Vector2f mainDisplay = {800, 300};
    sf::Vector2i firstShelfPos={110,115};
    sf::Vector2i secondShelfPos={110,275};
    int spacing = 95;
    smiskiProperties work1SmiskiDet, work2SmiskiDet, work3SmiskiDet, work4SmiskiDet, work5SmiskiDet, work6SmiskiDet,
            cheer1SmiskiDet, cheer2SmiskiDet, cheer3SmiskiDet, cheer4SmiskiDet, cheer5SmiskiDet, cheer6SmiskiDet;
    vector<smiskiProperties> workDetStructVector= {work1SmiskiDet, work2SmiskiDet, work3SmiskiDet, work4SmiskiDet, work5SmiskiDet, work6SmiskiDet};
    vector<smiskiProperties> cheerDetStructVector= {cheer1SmiskiDet, cheer2SmiskiDet, cheer3SmiskiDet, cheer4SmiskiDet, cheer5SmiskiDet, cheer6SmiskiDet};

public:
    sf::Texture atWorktexture, cheerTexture;
    sf::Sprite work1Smiski, work2Smiski,work3Smiski, work4Smiski, work5Smiski, work6Smiski,
    cheer1Smiski,cheer2Smiski,cheer3Smiski,cheer4Smiski,cheer5Smiski,cheer6Smiski;
    vector<sf::Sprite> atWorkCollection = {work1Smiski, work2Smiski,work3Smiski, work4Smiski, work5Smiski, work6Smiski};
    vector<sf::Sprite> cheerCollection = {cheer1Smiski,cheer2Smiski,cheer3Smiski,cheer4Smiski,cheer5Smiski,cheer6Smiski};
    map<int, string> locateName = {{0,"Approving"},{1,"Researching"}, {2, "Presenting"},{3,"Good Idea"}, {4, "On the Road"},{5,"Little Group Think"},
                                   {6,"On Your Side"},{7,"Dancing"}, {8, "Cheerleading"},{9,"Marching"}, {10, "On Drums"},{11,"Cheering"}};
    smiski(sf::Vector2f scaleOfwindow) {
        float avgwindowScale = (scaleOfwindow.x+scaleOfwindow.y)/2;
        smallScale = smallScale*avgwindowScale;
        mainScale = mainScale*avgwindowScale;
        firstShelfPos.x = firstShelfPos.x *scaleOfwindow.x;
        firstShelfPos.y = firstShelfPos.y *scaleOfwindow.y;
        secondShelfPos.x = secondShelfPos.x *scaleOfwindow.x;
        secondShelfPos.y = secondShelfPos.y *scaleOfwindow.y;
        mainDisplay.x = mainDisplay.x *scaleOfwindow.x;
        mainDisplay.y = mainDisplay.y *scaleOfwindow.y;
        spacing = spacing*avgwindowScale;
        atWorktexture.loadFromFile("./smiskiTextures/atWorkSeriesedited.png");
        cheerTexture.loadFromFile("./smiskiTextures/cheerSmiskis.png");
        loadTextures(atWorkCollection, atWorktexture);
        loadTextures(cheerCollection, cheerTexture);
        loadSmiski(atWorkCollection, firstShelfPos);
        loadSmiski(cheerCollection, secondShelfPos);
        details(workDetStructVector, atWorkCollection, "Work Series");
        details(cheerDetStructVector, cheerCollection, "Cheer Collection");
}
    void loadTextures(vector<sf::Sprite>& collection, sf::Texture& texture){
        //top left, middle, right, bottom left, middle, right
        vector<vector<int>> coordOnTexture {{22,65}, {240, 65}, {458,65}, {22,342},{240,342},{458,342}};
        for(int i = 0; i<collection.size(); i++){
            collection[i].setTexture(texture);
            collection[i].setTextureRect(sf::IntRect (coordOnTexture[i][0], coordOnTexture[i][1],size,size));
        }
    }
    void loadSmiski(vector<sf::Sprite>& collection, sf::Vector2i& position){
        for(int i = 0; i<collection.size(); i++){
            collection[i].scale(sf::Vector2f(smallScale,smallScale));
            collection[i].setOrigin(size/2,size/2);
            collection[i].setPosition(position.x+i*spacing, position.y);
        }
    }
    void drawTrueSmiski(sf::RenderWindow& window, vector<bool> ifTrue, string collection){
        for(int i = 0; i<ifTrue.size(); i++){
            if(collection == "At Work"){
                if(ifTrue[i]){
                    window.draw(atWorkCollection[i]);
                }
            } else if (collection == "Cheer"){
                if(ifTrue[i]){
                    window.draw(cheerCollection[i]);
                }
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
    void details(vector<smiskiProperties>& structure2Edit, vector<sf::Sprite>& sprite2Add, string collectionName) {
        for (int i = 0; i < structure2Edit.size(); i++) {
            structure2Edit[i].smiskiSpriteName = sprite2Add[i];
            if (collectionName == "Work Series") {
                structure2Edit[i].CollectionName = collectionName;
                structure2Edit[i].title = locateName[i];
                structure2Edit[i].positionOnShelf = i;
            }
        }
    }
};
#endif //SFMLTRAINING_SMISKI_H
