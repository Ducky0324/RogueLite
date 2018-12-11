#include "engine/stage/dungeon.hpp"
#include "engine/constants.hpp"
#include "engine/stage/tiles.hpp"
#include "util/rng.hpp"
#include <algorithm>
#include <stdio.h>
#include <vector>

Dungeon::Dungeon(Stage *stage) : StageBuilder(stage) {}

void Dungeon::generate() {
  stage->fill(Tiles::wall);

  std::vector<Leaf *> leaves;
  Leaf *root = new Leaf(0, 0, stage->width - 1, stage->height - 1);
  leaves.push_back(root);

  bool splitSuccessfully = true;
  while (splitSuccessfully) {
    splitSuccessfully = false;
    for (auto leaf : leaves) {
      if (!leaf->child1 && !leaf->child2) {
        if (leaf->width > maxLeafSize || leaf->height > maxLeafSize) {
          printf("Can create leaf->\nSplitting..\n");
          if (leaf->split()) {
            printf("Split was successful.\nAdding child1..\n");
            leaves.push_back(leaf->child1);
            printf("Adding child2\n");
            leaves.push_back(leaf->child2);
            splitSuccessfully = true;
          }
        }
      }
    }
  }
  printf("Done Splitting..\n");
  printf("Creating rooms..\n");
  root->createRooms(this);
}

void Dungeon::carveRoom(const Rect *room) {
  printf("Carving..\n");
  if (room) {
    for (int x = room->x + 1; x < room->right; x++) {
      for (int y = room->y + 1; y < room->bottom; y++) {
        Vec pos(x, y);
        stage->setTile(pos, Tiles::floor);
      }
    }
  }
}

void Dungeon::createHall(const Rect *a, const Rect *b) {
  auto posA = a->center();
  auto posB = b->center();
  if (rng::oneIn(2)) {
    createHorTunnel(posA, posB);
    createVirTunnel(posA, posB);
  } else {
    createVirTunnel(posA, posB);
    createHorTunnel(posA, posB);
  }
}

void Dungeon::createHorTunnel(const Vec &a, const Vec &b) {
  for (int x = std::min(a.x, b.x); x < (std::max(a.x, b.x)) + 1; x++) {
    Vec pos(x, a.y);
    if (*stage->getTile(pos) == Tiles::wall) {
      stage->setInteractable(pos, Tiles::open_door);
    }
    stage->setTile(pos, Tiles::floor);
  }
}

void Dungeon::createVirTunnel(const Vec &a, const Vec &b) {
  for (int y = std::min(a.y, b.y); y < (std::max(a.y, b.y)) + 1; y++) {
    Vec pos(a.x, y);
    if (*stage->getTile(pos) == Tiles::wall) {
      stage->setInteractable(pos, Tiles::open_door);
    }
    stage->setTile(pos, Tiles::floor);
  }
}

Leaf::Leaf(int x, int y, int width, int height) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
}

bool Leaf::split() {
  if (child1 || child2) {
    return false;
  }

  bool splitH = rng::oneIn(2);

  if ((width / height) >= 1.25) {
    splitH = false;
  } else if ((height / width) >= 1.25) {
    splitH = true;
  }

  int maxSplit;
  if (splitH) {
    maxSplit = height - minSize;
  } else {
    maxSplit = width - minSize;
  }

  if (maxSplit <= minSize) {
    return false;
  }

  int splitPoint = rng::range(minSize, maxSplit);

  if (splitH) {
    child1 = new Leaf(x, y, width, splitPoint);
    child2 = new Leaf(x, y + splitPoint, width, height - splitPoint);
  } else {
    child1 = new Leaf(x, y, splitPoint, height);
    child2 = new Leaf(x + splitPoint, y, width - splitPoint, height);
  }
  return true;
}

void Leaf::createRooms(Dungeon *dungeon) {
  if (child1 || child2) {
    if (child1) {
      printf("Creating rooms in the first child\n");
      child1->createRooms(dungeon);
    }
    if (child2) {
      printf("Creating rooms in the second child\n");
      child2->createRooms(dungeon);
    }

    if (child1 && child2) {
      printf("Connecting children\n");
      dungeon->createHall(child1->getRoom(), child2->getRoom());
    }
  } else {
    printf("Creating room for this leaf\n");
    int rw = width;
    int rh = height;
    room = new Rect(x, y, rw, rh);
    dungeon->rooms.push_back(new Rect(x + 1, y + 1, rw - 1, rh - 1));
    dungeon->carveRoom(room);
  }
}

Rect *Leaf::getRoom() {
  Rect *a = nullptr;
  Rect *b = nullptr;
  if (room) {
    return room;
  } else {
    if (child1) {
      a = child1->getRoom();
    }
    if (child2) {
      b = child2->getRoom();
    }
    if (!a && !b) {
      return nullptr;
    } else if (!b) {
      return a;
    } else if (!a) {
      return b;
    } else if (rng::oneIn(2)) {
      return b;
    } else {
      return a;
    }
  }
}

void Leaf::draw(SDL_Renderer *r) {
  SDL_Rect drawRect = SDL_Rect{x * constants::TILE_SIZE, y * constants::TILE_SIZE,
                               width * constants::TILE_SIZE, height * constants::TILE_SIZE};
  SDL_RenderDrawRect(r, &drawRect);
}