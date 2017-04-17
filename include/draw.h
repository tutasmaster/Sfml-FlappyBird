#ifndef DRAW_H
#define DRAW_H
#include <SFML/Graphics.hpp>
namespace WINDOW{
    extern int height,width;
    extern std::vector<sf::Drawable*> drawList;
    extern sf::RenderWindow renderWindow;
    extern sf::RectangleShape floor;
    extern sf::RectangleShape ceil;

    extern void setup();
    extern void draw();
    extern void drawBackground();
}
#endif // DRAW_H
