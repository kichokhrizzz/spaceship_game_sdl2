#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include <string>

class Enemy
{
public:
    Enemy(int x, int y, int size, SDL_Color color, SDL_Renderer *renderer, const std::string &texturePath);
    void move(int targetX, int targetY);
    void render(SDL_Renderer *renderer);
    bool checkCollision(int projX, int projY, int projRadius);
    int getX() const { return posX; }
    int getY() const { return posY; }
    int getSize() const { return size; }

private:
    int posX, posY;
    int size;
    SDL_Color color;
    SDL_Texture *texture;
    SDL_Renderer *renderer;
    SDL_Texture *loadTexture(const std::string &path);
};

#endif