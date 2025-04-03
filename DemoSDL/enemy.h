#ifndef ENEMY_H
#define ENEMY_H

#include "defs.h"
#include "graphics.h"

class Enemy {
public:
    Enemy(int x, int y);
    void move();
    bool checkCollision(SDL_Rect& playerRect);
    bool isOffScreen();
    void render(SDL_Renderer* renderer);
    int getDamage() const;
    int id;

    bool operator==(const Enemy& other) const {
        return this->id == other.id; // Compare relevant attributes
    }
private:
    SDL_Rect rect;
    int speed;
    int damage;
};

#endif // ENEMY_H
