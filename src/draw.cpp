#include "draw.h"
#include <vector>
#include <iostream>

#define HEIGHT 720
#define WIDTH 405
#define NAME "Flappy Bird"


namespace WINDOW{
    sf::RectangleShape floor(sf::Vector2f(WIDTH,10.0f));
    sf::RectangleShape ceil(sf::Vector2f(WIDTH,10.0f));
    std::vector<sf::Drawable*> drawList;
    int height = HEIGHT;
    int width = WIDTH;
    sf::RenderWindow renderWindow(sf::VideoMode(WIDTH, HEIGHT), NAME);

    void setup(){
        renderWindow.setFramerateLimit(60);
        renderWindow.setKeyRepeatEnabled(false);
        floor.setPosition(0.0f,HEIGHT-10.0f);
        ceil.setPosition(0.0f,0.0f);
    }

    void draw(){
        renderWindow.clear();
        for (unsigned int i = 0; i < drawList.size(); i++){
            if(drawList[i]){
                renderWindow.draw(*drawList[i]);
                //std::cout<<drawList.size()<<std::endl;
            }
        }
        renderWindow.display();
        drawList.clear();
    }

    void drawBackground(){
        drawList.push_back(&floor);
        drawList.push_back(&ceil);
    }
}
