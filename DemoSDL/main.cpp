#include <iostream>
#include <cstdlib>
#include <ctime>
#include "graphics.h"
#include "defs.h"
#include "player.h"
#include "enemy.h"
#include "powerup.h"

using namespace std;

int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    Graphics graphics;
    Player player;
    graphics.init();

    SDL_Texture* background = graphics.loadTexture("image/bikiniBottom.jpg");

    SDL_Rect rect = {SCREEN_WIDTH / 2 - 25, SCREEN_HEIGHT - 100, 50, 50};

    SDL_Rect redrect = {500, 500, 50, 50}; // Rectangle position and size

    bool quit = false;
    SDL_Event e;
    int backgroundY = 0;
    vector<Enemy> enemies;
    vector<PowerUp> powerUps;
    int playerHealth = 100;
    int bossCount = 0;
    const int bossThreshold = 5;
    Uint32 lastArrowTime = 0;
    const Uint32 arrowInterval = 500; // Time interval between arrows in milliseconds

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN){
                player.handleKeyPress(e, rect);
            }
        }

        // Automatic shooting
        Uint32 currentTime = SDL_GetTicks();
        if (currentTime > lastArrowTime + arrowInterval) {
            player.shootArrow(rect);
            lastArrowTime = currentTime;
        }

        // Handle enemy spawning, movement, and collision
        if (rand() % 100 < 2) { // Random chance to spawn an enemy
            enemies.push_back(Enemy(rand() % SCREEN_WIDTH, 0));
        }

        for (auto& enemy : enemies) {
            enemy.move();
            if (enemy.checkCollision(rect)) {
                playerHealth -= enemy.getDamage();
                if (playerHealth <= 0) {
                    quit = true;
                    break;
                }
            }
            if (enemy.isOffScreen()) {
                enemies.erase(remove(enemies.begin(), enemies.end(), enemy), enemies.end());
            }
        }

        // Handle power-ups
        if (rand() % 1000 < 1) { // Random chance to spawn a power-up
            powerUps.push_back(PowerUp(rand() % SCREEN_WIDTH, 0));
        }

        for (auto& powerUp : powerUps) {
            powerUp.move();
            if (powerUp.checkCollision(rect)) {
                player.applyPowerUp(powerUp);
                powerUps.erase(remove(powerUps.begin(), powerUps.end(), powerUp), powerUps.end());
            }
            if (powerUp.isOffScreen()) {
                powerUps.erase(remove(powerUps.begin(), powerUps.end(), powerUp), powerUps.end());
            }
        }

        // Boss fight logic
        if (currentTime > 50000 && bossCount < bossThreshold) {
            // Spawn and handle boss
            // ...
        }

        // Di chuyển background xuống dưới
        backgroundY += 2;
        if (backgroundY >= SCREEN_HEIGHT) {
            backgroundY = 0;
        }
        SDL_RenderClear(graphics.renderer);
        // Vẽ background hai lần để tạo hiệu ứng liên tục
        SDL_Rect renderQuad = {0, backgroundY, SCREEN_WIDTH, SCREEN_HEIGHT};

        SDL_RenderCopy(graphics.renderer, background, nullptr, &renderQuad);

        renderQuad.y = backgroundY - SCREEN_HEIGHT;
        SDL_RenderCopy(graphics.renderer, background, nullptr, &renderQuad);

        // Render rectangle
        SDL_SetRenderDrawColor(graphics.renderer, 255, 0, 0, 255); // Red color
        SDL_RenderFillRect(graphics.renderer, &redrect);
        // Render enemies
        for ( auto& enemy : enemies) {
            enemy.render(graphics.renderer);
        }

        // Render power-ups
        for (auto& powerUp : powerUps) {
            powerUp.render(graphics.renderer);
        }

        graphics.presentScene();

        SDL_Delay(16); // Delay to control the speed of movement
        }

    SDL_DestroyTexture(background);
    background = NULL;
    graphics.quit();
    return 0;
}
