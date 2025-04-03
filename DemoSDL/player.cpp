#include "player.h"

void Player::handleKeyPress(SDL_Event &e, SDL_Rect &rect) {
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_A]) {
        rect.x -= 10;
        if (rect.x < 0) rect.x = 0;
    } else if (state[SDL_SCANCODE_D]) {
        rect.x += 10;
        if (rect.x + rect.w > 800) rect.x = 800 - rect.w;
    }
}

void Player::shootArrow(SDL_Rect &rect) {
    SDL_Rect arrow = {rect.x + rect.w / 2 - 5, rect.y, 10, 20};
    arrows.push_back(arrow);
}

void Player::applyPowerUp(PowerUp &powerUp) {
    powerUp.applyEffect();
}

void Player::renderArrows(SDL_Renderer* renderer) {
    for (auto& arrow : arrows) {
        arrow.y -= 10; // Move arrow up
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // Yellow color
        SDL_RenderFillRect(renderer, &arrow);
    }
    arrows.erase(remove_if(arrows.begin(), arrows.end(), [](SDL_Rect& arrow) { return arrow.y < 0; }), arrows.end());
}
