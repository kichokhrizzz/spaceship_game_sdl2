#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include "projectile.h"
#include "enemy.h"

class Player
{
public:
    Player(int, int y, int size, SDL_Color color, SDL_Renderer *renderer, const std::string &texturePath);
    ~Player();
    void handleEvent(SDL_Event &e);
    void move();
    void render(SDL_Renderer *renderer, TTF_Font *font, SDL_Color textColor);
    void shoot();
    int getX() const { return posX; }
    int getY() const { return posY; }
    void addEnemy(SDL_Renderer *renderer, const std::string &texturePath);
    void handleEnemies(SDL_Renderer *renderer);
    int getScore() const { return score; }
    void checkCollisionWithEnemies();
    bool isGameOver() const { return gameOver; }

private:
    int posX, posY;
    int velX, velY;
    int size;
    SDL_Color color;
    static const int PLAYER_SPEED = 1;
    std::vector<Projectile> projectiles;
    void handleProjectiles(SDL_Renderer *renderer);
    std::vector<Enemy> enemies;
    int score;
    SDL_Texture *texture;
    SDL_Renderer *renderer;
    SDL_Texture *loadTexture(const std::string &path);
    bool gameOver;
};

#endif