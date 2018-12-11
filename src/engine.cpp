#include "engine/engine.hpp"
#include "engine/stage/tiles.hpp"

GameEngine::GameEngine(int pscreenWidth, int pscreenHeight)
    : screenWidth(pscreenWidth), screenHeight(pscreenHeight) {
  window = SDL_CreateWindow("dawn-lite", 0, 0, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  if (!window || !renderer) {
    printf("Failed to initialize renderer or window. Error: %s\n", SDL_GetError());
  }

  testStage =
      Stage((int)(screenHeight / constants::TILE_SIZE), (int)(screenHeight / constants::TILE_SIZE));

  for (int x = 0; x < testStage.width; x++) {
    for (int y = 0; y < testStage.height; y++) {
      auto r = new Rect(x * constants::TILE_SIZE, y * constants::TILE_SIZE, constants::TILE_SIZE,
                        constants::TILE_SIZE);
      tileRects.push_back(r);
    }
  }
}

GameEngine::~GameEngine() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

void GameEngine::start() {
  printf("Generating Map..\n");
  dungeonGen.generate();
  printf("Map generated..\nApplying textures...\n");
  tileRender.applyTextures(&testStage);

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
    case SDL_MOUSEBUTTONDOWN:
      auto mousePos = Vec(evt.motion.x, evt.motion.y);
      for (auto rect : tileRects) {
        if (rect->contains(mousePos)) {
          testStage[Vec(rect->x / constants::TILE_SIZE, rect->y / constants::TILE_SIZE)]
              ->printTileInfo();
        }
      }
    }
  }
}

void GameEngine::update() {}

void GameEngine::render() {
  SDL_RenderClear(renderer);
  tileRender.drawStageTo(renderer, &testStage);
  SDL_SetRenderDrawColor(renderer, 255, 219, 209, 255);
  for (auto rect : dungeonGen.rooms) {
    rect->scale(constants::TILE_SIZE, constants::TILE_SIZE).draw(renderer);
  }
  SDL_SetRenderDrawColor(renderer, 51, 51, 51, 255);
  SDL_RenderPresent(renderer);
}