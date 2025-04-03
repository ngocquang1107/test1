#ifndef POWERUP_H
#define POWERUP_H

#include "defs.h"
#include "graphics.h"

class PowerUp {
public:
    PowerUp(int x, int y);
    void move();
    bool checkCollision(SDL_Rect& playerRect);
    bool isOffScreen();
    void render(SDL_Renderer* renderer);
    void applyEffect();
    int id;

    bool operator==(const PowerUp& other) const {
        return this->id == other.id; // Compare relevant attributes
    }
private:
    SDL_Rect rect;
    int speed;
};

#endif // POWERUP_H
