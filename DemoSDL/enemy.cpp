#include "enemy.h"

Enemy::Enemy(int x, int y) {
    rect.x = x;
    rect.y = y;
    rect.w = 50;
    rect.h = 50;
    speed = 5;
    damage = 10;
}

void Enemy::move() {
    rect.y += speed;
}

bool Enemy::checkCollision(SDL_Rect& playerRect) {
    return SDL_HasIntersection(&rect, &playerRect);
}

bool Enemy::isOffScreen() {
    return rect.y > SCREEN_HEIGHT;
}

void Enemy::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green color
    SDL_RenderFillRect(renderer, &rect);
}

int Enemy::getDamage() const {
    return damage;
}
