#include "ui/tileRenderer.hpp"
#include "engine/stage/tiles.hpp"
#include "util/rng.hpp"
#include <array>
#include <cmath>
#include <stdio.h>

TileRenderer::TileRenderer() {}

void TileRenderer::applyTextures(Stage *stage) {
  for (int x = 0; x < stage->width; x++) {
    for (int y = 0; y < stage->height; y++) {
      auto pos = Vec(x, y);
      auto tile = stage->get(pos);
      auto interactable = stage->getInteractable(pos);
      if (tile->getType() == Tiles::wall) {
        int n = (int)std::pow(2.0, 0);
        int s = (int)std::pow(2.0, 1);
        int e = (int)std::pow(2.0, 2);
        int w = (int)std::pow(2.0, 3);

        std::array<TileType *, 8> neighbors = stage->getNeighboringWalls(pos);
        int textureVal = 0;
        if (neighbors[0]) {
          textureVal += n;
        }
        if (neighbors[1]) {
          textureVal += e;
        }
        if (neighbors[2]) {
          textureVal += s;
        }
        if (neighbors[3]) {
          textureVal += w;
        }

        tile->textureVal = textureVal;
        switch (textureVal) {
        case 0:
        case 1:
        case 2:
        case 8:
          tile->appearance = Textures::tiles["wallEW"][0];
          break;
        case 4:
        case 5:
        case 9:
          if (neighbors[0] && neighbors[3]) {
            tile->appearance = Textures::tiles["wallEW"][rng::item<int>(textureDist)];
          } else {
            tile->appearance = Textures::tiles["wallNS"][rng::item<int>(textureDist)];
          }
          break;
        case 12:
        case 13:
          tile->appearance = Textures::tiles["wallNS"][rng::item<int>(textureDist)];
          break;
        case 14:
          tile->appearance = Textures::tiles["wallNS"][rng::item<int>(textureDist)];
          break;
        case 3:
        case 6:
        case 7:
          if (neighbors[1] && neighbors[2]) {
            tile->appearance = Textures::tiles["wallNS"][rng::item<int>(textureDist)];
          } else if (neighbors[0] && neighbors[2]) {
            tile->appearance = Textures::tiles["wallEW"][rng::item<int>(textureDist)];
          } else {
            tile->appearance = Textures::tiles["wallNS"][0];
          }
          break;
        case 10:
        case 11:
          tile->appearance = Textures::tiles["wallEW"][rng::item<int>(textureDist)];
          break;
        case 15:
          if (!neighbors[4] && !neighbors[5] && !neighbors[6] && !neighbors[7]) {
            tile->appearance = Textures::tiles["wallNS"][0];
          } else if (neighbors[0] && neighbors[3] && !neighbors[4]) {
            tile->appearance = Textures::tiles["wallEW"][0];
          } else if (neighbors[0] && neighbors[2] && !neighbors[5]) {
            tile->appearance = Textures::tiles["wallEW"][0];
          } else {
            tile->appearance = &Textures::voidTile;
          }
          break;
        default:
          tile->appearance = Textures::tiles["carpet"][rng::item<int>(textureDist)];
          break;
        }
      } else if (tile->getType() == Tiles::floor) {
        tile->appearance = Textures::tiles["stoneTile"][rng::item<int>(textureDist)];
      } else {
        tile->appearance = Textures::tiles["carpet"][0];
      }

      if (interactable && interactable->getType() == Tiles::open_door) {
        int n = (int)std::pow(2.0, 0);
        int s = (int)std::pow(2.0, 1);
        int e = (int)std::pow(2.0, 2);
        int w = (int)std::pow(2.0, 3);

        std::array<TileType *, 8> neighbors = stage->getNeighboringWalls(pos);
        int textureVal = 0;
        if (neighbors[0]) {
          textureVal += n;
        }
        if (neighbors[1]) {
          textureVal += e;
        }
        if (neighbors[2]) {
          textureVal += s;
        }
        if (neighbors[3]) {
          textureVal += w;
        }
        interactable->textureVal = textureVal;
        printf("Texture Val: %d\n", textureVal);
        switch (textureVal) {
        case 5:
          tile->appearance = Textures::interactable["woodenDoorNS"][1];
          break;
        case 10:
          tile->appearance = Textures::interactable["woodenDoorEW"][1];
          break;
        default:
          tile->appearance = Textures::tiles["stoneTile"][0];
          break;
        }
      }
    }
  }
}

void TileRenderer::drawStageTo(SDL_Renderer *r, Stage *stage, int offsetX, int offsetY) {
  for (int x = 0; x < stage->width; x++) {
    for (int y = 0; y < stage->height; y++) {
      auto pos = Vec(x, y);
      auto tile = stage->get(pos);
      auto interactable = stage->getInteractable(pos);
      if (tile->appearance) {
        tile->appearance->drawAt(r, x + offsetX, y + offsetY);
      }
      if (interactable && interactable->appearance) {
        tile->appearance->drawAt(r, x + offsetX, y + offsetY);
        interactable->appearance->drawAt(r, x + offsetX, y + offsetY);
      }
    }
  }
}