#include "bird.h"
#include "draw.h"
#include <SFML/Graphics.hpp>

bird::bird(float y,sf::Texture* tex)
{
    spr.setPosition(57.5f,WINDOW::height*y);
    spr.setTexture(*tex);
    spr.setTextureRect(sf::IntRect(30,45,115,85));
    spr.setOrigin(57.5,42.5);

    col.setPosition(57.5f,WINDOW::height*y);
    col.setOrigin(57.5,42.5);
    col.setSize(sf::Vector2f(75.0f,75.0f));
}

void bird::setup()
{
    float pos = WINDOW::height * 0.5;
    vspd = 0;
    spr.setPosition(57.5f,pos);
    col.setPosition(57.5f,pos);
}

void bird::update()
{
    if(!fail){
        vspd = vspd + 0.25;
    }else{
        vspd = 0;
    }
    float pos = spr.getPosition().y + vspd;
    spr.setPosition(57.5f,pos);
    col.setPosition(57.5f,pos);
    float rot = vspd * 25;
    if(rot > 60){
        rot = 60;
    }else if(rot < -60){
        rot = -60;
    }
    spr.setRotation(rot);
    WINDOW::drawList.push_back(&spr);
}
