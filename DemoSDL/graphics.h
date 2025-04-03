#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include "defs.h"

void foo();

class Graphics {
public:
    SDL_Renderer *renderer;
	SDL_Window *window;
	void logErrorAndExit(const char* msg, const char* error);
	void init();
	void prepareScene(SDL_Texture * background);
    void presentScene();
    SDL_Texture *loadTexture(const char *filename);
    void renderTexture(SDL_Texture *texture, int x, int y);
    void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);
    void quit();
    void waitUntilKeyPressed();
};

#endif // _GRAPHICS__H
