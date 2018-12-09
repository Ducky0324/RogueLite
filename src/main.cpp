#include "engine/engine.hpp"
#include "stdio.h"
#include <cstring>
#include <string>

int main(int argc, char *argv[]) {
  int screenWidth;
  int screenHeight;
  if (argc > 1) {
    screenWidth = std::stoi(argv[1]);
    screenHeight = std::stoi(argv[2]);
  } else {
    screenWidth = 800;
    screenHeight = 600;
  }

  auto game = GameEngine(screenWidth, screenHeight);
  game.start();
}