#include "projectile.h"

Projectile::Projectile(int x, int y, int radius, int velY, SDL_Color color)
    : posX(x), posY(y), radius(radius), velY(velY), color(color)
{
}


void Projectile::move()
{
    posY += velY;
}

void Projectile::render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, posX + dx, posY + dy);
            }
        }
    }
}

bool Projectile::isOffScreen(int screenHeight)
{
    return posY + radius < 0 || posY - radius > screenHeight;
}