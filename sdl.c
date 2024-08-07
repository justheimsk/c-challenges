#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

#define WINDOW_W 800
#define WINDOW_H 600

int main() {
  int quit = 0;
  SDL_Event event;
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window *window =
      SDL_CreateWindow("Simple SDL Window", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, WINDOW_W, WINDOW_H, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  int x = 10, y = 10, size = 10, speedX = 4, speedY = 4;
  while (quit == 0) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        quit = 1;
        break;
      }
    }

    x += speedX;
    y += speedY;
    if (x >= WINDOW_W - size || x <= 0)
      speedX *= -1;
    if (y >= WINDOW_H - size || y <= 0)
      speedY *= -1;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
    SDL_RenderFillRect(renderer, &(SDL_Rect){x, y, size, size});

    SDL_RenderPresent(renderer);

    // ~60 fps
    SDL_Delay(16);
  }

  return 0;
}
