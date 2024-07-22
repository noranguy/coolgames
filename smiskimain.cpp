//
// Created by nguye on 6/19/2024.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "backgroundsmiski.h"
#include "smiski.h"

using namespace std;

int main() {
    sf::Vector2f scaleOfWindow = {1,1};
    //1024, 768 times 1.5 to make window bigger (4/3)
    sf::Vector2f windowSize = {1024, 768};
    vector<bool> firstifPresent {false, false, false, false, false, false};
    vector<bool> secondifPresent {false, false, false, false, false, false};
    vector<bool> thirdifPresent {false, false, false, false, false, false};
    bool displayText = false;
    string nameOfMain, nameOfCollection;
    int positionOfMain, redButtonSprite;
    float avgScale;
    sf::Sprite mainDisplay, emptySprite;
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Smiski Storage");
    background smiskiBack(windowSize, scaleOfWindow);
    smiski smiskiTest(scaleOfWindow);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            sf::Vector2i position = sf::Mouse::getPosition(window);
            position.x = position.x/scaleOfWindow.x; position.y = position.y/scaleOfWindow.y;
            if (event.type == sf::Event::Closed) {
                window.close();
            }else if(event.type == sf::Event::Resized){
                windowSize.x = window.getSize().x;
                windowSize.y = window.getSize().y;
                scaleOfWindow.x = windowSize.x / 1024;
                scaleOfWindow.y = windowSize.y / 768;
            } else if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    for(int i = 0; i< 6; i++){
                        if(smiskiTest.atWorkCollection[i].getGlobalBounds().contains(position.x,position.y)) {
                            if (firstifPresent[i]) {
                                nameOfCollection = "At Work Collection";
                                mainDisplay = smiskiTest.atWorkCollection[i];
                                nameOfMain = smiskiTest.locateName[i];
                                displayText = true;
                                positionOfMain = i + 1;
                            } else if (!firstifPresent[i]) {
                                firstifPresent[i] = true;
                            }
                        }else if(smiskiTest.cheerCollection[i].getGlobalBounds().contains(position.x,position.y)){
                            if (secondifPresent[i]) {
                                nameOfCollection = "Cheer Collection";
                                mainDisplay = smiskiTest.cheerCollection[i];
                                nameOfMain = smiskiTest.locateName[i+6];
                                displayText = true;
                                positionOfMain = i + 7;
                            } else if (!secondifPresent[i]) {
                                secondifPresent[i] = true;
                            }
                        }else if(smiskiBack.removeCollectionButton.getGlobalBounds().contains(position.x, position.y)){
                            redButtonSprite = 1;
                        }
                    }
                }
            } else if(event.type == sf::Event::MouseButtonReleased){
                if(smiskiBack.removeCollectionButton.getGlobalBounds().contains(position.x, position.y)){
                    mainDisplay = emptySprite;
                    //just first shelf
                    displayText = false;
                    redButtonSprite = 0;
                    if(positionOfMain>0 && positionOfMain<=6){
                        firstifPresent[positionOfMain-1] = false;
                    } else if(positionOfMain>6 && positionOfMain<=12){
                        secondifPresent[positionOfMain-7] = false;
                    }
                }
            }



            //debugging/ getting position
//            cout<<position.x<<" ,"<<position.y<<endl;
//            cout<<window.getSize().x<<" ,"<<window.getSize().y<<endl;

            window.clear();
            window.draw(smiskiBack.smiskiBackgroundSprite);
            smiskiTest.drawTrueSmiski(window, firstifPresent, "At Work");
            smiskiTest.drawTrueSmiski(window, secondifPresent, "Cheer");
            smiskiTest.drawMainDisplay(window, mainDisplay);
            if(displayText){
                smiskiBack.mainDisplayTextFunc(window, nameOfCollection, nameOfMain, to_string(positionOfMain));
                smiskiBack.removeButtonDraw(window, redButtonSprite);
//                window.draw(smiskiBack.removeCollectionButton);
            }
            window.display();
        }
    }
    return 0;
}

