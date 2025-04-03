#include "powerup.h"

PowerUp::PowerUp(int x, int y) {
    rect.x = x;
    rect.y = y;
    rect.w = 30;
    rect.h = 30;
    speed = 3;
}

void PowerUp::move() {
    rect.y += speed;
}

bool PowerUp::checkCollision(SDL_Rect& playerRect) {
    return SDL_HasIntersection(&rect, &playerRect);
}

bool PowerUp::isOffScreen() {
    return rect.y > SCREEN_HEIGHT;
}

void PowerUp::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue color
    SDL_RenderFillRect(renderer, &rect);
}

void PowerUp::applyEffect() {
    // Implement the effect of the power-up, e.g., increase player speed, health, etc.
}
