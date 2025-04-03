#ifndef PLAYER_H
#define PLAYER_H

#include "defs.h"
#include "graphics.h"
#include "powerup.h"
#include <vector>

using namespace std;

class Player : public Graphics{
public:
    void handleKeyPress(SDL_Event &e, SDL_Rect &rect);
    const int MOVE_SPEED = 10;
    void shootArrow(SDL_Rect &rect);
    void applyPowerUp(PowerUp &powerUp);
    void renderArrows(SDL_Renderer* renderer);
    vector<SDL_Rect> arrows;
};

#endif // PLAYER_H
