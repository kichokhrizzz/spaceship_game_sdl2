#include "enemy.h"
#include <cmath>
#include <iostream> 
#include <SDL2/SDL_image.h>

Enemy::Enemy(int x, int y, int size, SDL_Color color, SDL_Renderer *renderer, const std::string &texturePath)
    : posX(x), posY(y), size(size), color(color), renderer(renderer), texture(nullptr)
{
    texture = loadTexture(texturePath);
    if (texture == nullptr)
    {
        std::cerr << "Failed to load enemy texture from " << texturePath << std::endl;
    }
    else
    {
        std::cout << "Successfully loaded enemy texture from " << texturePath << std::endl;
    }
}

SDL_Texture *Enemy::loadTexture(const std::string &path)
{
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr)
    {
        std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture *newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == nullptr)
    {
        std::cerr << "Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << std::endl;
    }

    SDL_FreeSurface(loadedSurface);
    return newTexture;
}


void Enemy::move(int targetX, int targetY)
{
    int deltaX = targetX - posX;
    int deltaY = targetY - posY;
    float length = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    if (length != 0)
    {
        posX += static_cast<int>((deltaX / length) * 1.2); // Adjust the speed as needed
        posY += static_cast<int>((deltaY / length) * 1.1); // Adjust the speed as needed
    }

    std::cout << "Enemy moved to position (" << posX << ", " << posY << ")" << std::endl; // Añadido para depuración
}

void Enemy::render(SDL_Renderer *renderer)
{
    SDL_Rect renderQuad = {posX, posY, size, size};
    if (texture != nullptr)
    {
        SDL_RenderCopy(renderer, texture, nullptr, &renderQuad);
        std::cout << "Rendering enemy at (" << posX << ", " << posY << ")" << std::endl;
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_Rect fillRect = {posX, posY, size, size};
        SDL_RenderFillRect(renderer, &fillRect);
    }
}

bool Enemy::checkCollision(int projX, int projY, int projRadius)
{
    int deltaX = projX - posX;
    int deltaY = projY - posY;
    int distance = static_cast<int>(std::sqrt(deltaX * deltaX + deltaY * deltaY));

    return distance < (size / 2 + projRadius);
}