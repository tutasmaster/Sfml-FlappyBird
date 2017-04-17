#ifndef BIRD_H
#define BIRD_H
#include <SFML/Graphics.hpp>
#include "draw.h"


class bird
{

    public:
        bool fail = false;
        bird(float y,sf::Texture* tex);
        float vspd = 0.1f;
        float vel = 0.0f;
        sf::Sprite spr;
        sf::RectangleShape col;
        void update(void);
        void setup(void);

    protected:

    private:
};

#endif // BIRD_H
