#include "engine/engine.hpp"

GameEngine::GameEngine(int pscreenWidth, int pscreenHeight)
    : screenWidth(pscreenWidth), screenHeight(pscreenHeight) {
  window = SDL_CreateWindow("dawn-lite", 0, 0, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  if (!window || !renderer) {
    printf("Failed to initialize renderer or window. Error: %s\n", SDL_GetError());
  }
}

GameEngine::~GameEngine() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

void GameEngine::start() {
  while (running) {
    handleEvents();
    update();
    render();
  }
}

void GameEngine::handleEvents() {
  while (SDL_PollEvent(&evt)) {
    switch (evt.type) {
    case SDL_QUIT:
      running = false;
      break;
    case SDL_KEYDOWN:
      switch (evt.key.keysym.sym) {
      case SDLK_w:
        testAnimatedSprite.setFacing(Facing::UP);
        break;
      case SDLK_a:
        testAnimatedSprite.setFacing(Facing::LEFT);
        break;
      case SDLK_s:
        testAnimatedSprite.setFacing(Facing::DOWN);
        break;
      case SDLK_d:
        testAnimatedSprite.setFacing(Facing::RIGHT);
        break;
      }
    }
  }
}

void GameEngine::update() {}

void GameEngine::render() {
  SDL_RenderClear(renderer);
  testAnimatedSprite.drawAt(renderer, 4, 4);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderPresent(renderer);
}