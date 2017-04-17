#include "Pipe.h"

Pipe::Pipe(float diff,bird* brd)
{
    setup(diff);
    ply = brd;
}

void Pipe::setup(float diff)
{
    px = diff;

    gap = 200.0f - (GameMaster::score*2);
    dev = std::rand()%200 - 100;
    col[0].setSize(sf::Vector2f(10,(WINDOW::height/2) + dev - gap/2));
    col[0].setFillColor(sf::Color(17,135,76,255));
    col[0].setOutlineColor(sf::Color(20,20,20,255));
    col[0].setOutlineThickness(3.0f);
    col[1].setSize(sf::Vector2f(10,(WINDOW::height/2) - dev - gap));
    col[1].setFillColor(sf::Color(17,135,76,255));
    col[1].setOutlineThickness(3.0f);
    col[1].setOutlineColor(sf::Color(20,20,20,255));
}

void Pipe::update()
{
    if(!fail){
        px += (GameMaster::score/50 + 1);
        col[0].setPosition(WINDOW::width - px,0);
        col[1].setPosition(WINDOW::width - px,(WINDOW::height/2) + dev + gap);
        if(ply->col.getPosition().x < col[0].getPosition().x + col[0].getSize().x && ply->col.getPosition().x > col[0].getPosition().x){
            if(col[0].getGlobalBounds().intersects(ply->col.getGlobalBounds()) || col[1].getGlobalBounds().intersects(ply->col.getGlobalBounds())){
                GameMaster::setFail(true);
            }
        }else if(ply->col.getPosition().x > col[0].getPosition().x + col[0].getSize().x && !score){
            GameMaster::addScore();
            score = true;
        }
    }

    if(col[0].getPosition().x < -81){
        setup(0.0f);
        score = false;
    }
    WINDOW::drawList.push_back(&col[0]);
    WINDOW::drawList.push_back(&col[1]);
}
