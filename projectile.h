#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SDL2/SDL.h>

class Projectile
{
public:
    Projectile(int x, int y, int raidus, int velY, SDL_Color color);
    void move();
    void render(SDL_Renderer *renderer);
    bool isOffScreen(int screenHeight);
    int getX() const { return posX; }
    int getY() const { return posY; }
    int getRadius() const { return radius; }

private:
    int posX, posY;
    int radius;
    int velY;
    SDL_Color color;
};

#endif