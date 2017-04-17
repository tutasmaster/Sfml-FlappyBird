#include <SFML/Graphics.hpp>
#include <vector>
#include "include/bird.h"
#include "include/draw.h"
#include "include/Pipe.h"
#include "include/GameMaster.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <sstream>
void setup()
{

}

int main()
{
    sf::Font font;
    font.loadFromFile("font.ttf");
    sf::Text score;
    score.setString("10");
    score.setFont(font);
    score.setCharacterSize(34);
    score.setColor(sf::Color::White);
    score.setStyle(sf::Text::Bold);
    score.setOutlineColor(sf::Color::Black);
    score.setOutlineThickness(3.0f);
    score.setPosition(sf::Vector2f(5.0f,-4.0f));
    std::srand(std::time(0));
    unsigned int frame;
    WINDOW::setup();
    sf::Texture backTex;
    backTex.loadFromFile("background.jpg");
    sf::Sprite bg;
    bg.setTexture(backTex);
    bg.setScale(0.64,0.9);

    sf::Texture birdTex;
    birdTex.loadFromFile("Flappy_Bird.png");
    bird birdPly(0.5f,&birdTex);
    birdPly.spr.scale(0.5,0.5);
    birdPly.col.scale(0.5,0.5);
    GameMaster::failSettings.push_back(&birdPly.fail);
    Pipe pipe(0.0f,&birdPly);
    GameMaster::failSettings.push_back(&pipe.fail);
    Pipe pipe1(81.0f,&birdPly);
    GameMaster::failSettings.push_back(&pipe1.fail);
    Pipe pipe2(162.0f,&birdPly);
    GameMaster::failSettings.push_back(&pipe2.fail);
    Pipe pipe3(243.0f,&birdPly);
    GameMaster::failSettings.push_back(&pipe3.fail);
    Pipe pipe4(324.0f,&birdPly);
    GameMaster::failSettings.push_back(&pipe4.fail);
    Pipe pipe5(405.0f,&birdPly);
    GameMaster::failSettings.push_back(&pipe5.fail);
	// Start the game loop
    while (WINDOW::renderWindow.isOpen())
    {
        // Process events
        sf::Event event;
        while (WINDOW::renderWindow.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                WINDOW::renderWindow.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    if(GameMaster::fail == false){
                        birdPly.vspd -= 10.0f;
                    }else{
                        GameMaster::score = 0;
                        birdPly.setup();
                        pipe.setup(0.0f);
                        pipe1.setup(81.0f);
                        pipe2.setup(162.0f);
                        pipe3.setup(243.0f);
                        pipe4.setup(324.0f);
                        pipe5.setup(405.0f);
                        GameMaster::setFail(false);
                    }
                }
            }
        }
        WINDOW::drawList.push_back(&bg);
        /*WINDOW::drawBackground();*/
        pipe.update();
        pipe1.update();
        pipe2.update();
        pipe3.update();
        pipe4.update();
        pipe5.update();
        if(WINDOW::floor.getGlobalBounds().intersects(birdPly.col.getGlobalBounds()) || WINDOW::ceil.getGlobalBounds().intersects(birdPly.col.getGlobalBounds())){
            GameMaster::setFail(true);
        }
        birdPly.update();
        std::stringstream scr;
        scr << GameMaster::score;
        score.setString(scr.str());
        WINDOW::drawList.push_back(&score);
        WINDOW::draw();
    }

    return EXIT_SUCCESS;
}
