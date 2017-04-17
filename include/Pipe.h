#ifndef PIPE_H
#define PIPE_H
#include <SFML/Graphics.hpp>
#include "draw.h"
#include "bird.h"
#include "GameMaster.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
class Pipe
{
    public:
        bool fail = false;
        Pipe(float diff,bird* brd);
        void update();
        sf::RectangleShape col[2];
        float px = 0.0f;
        float gap = 0.0f;
        float dev = 0.0f;
        bird* ply;
        bool score = false;
        void setup(float diff);

    protected:

    private:
};

#endif // PIPE_H
