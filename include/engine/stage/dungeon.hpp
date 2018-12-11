#pragma once
#include "../../util/rect.hpp"
#include "stageBuilder.hpp"

class Leaf;

class Dungeon : public StageBuilder {
public:
  Dungeon(Stage *stage);

  std::vector<Rect *> rooms;

  void generate();
  void createHall(const Rect *a, const Rect *b);
  void carveRoom(const Rect *r);
  int getMaxRoomSize() { return maxLeafSize; }

private:
  static const int maxLeafSize = 10;
  static const int minRoomSize = 5;
  static const int maxRoomSize = 9;

  void createVirTunnel(const Vec &a, const Vec &b);
  void createHorTunnel(const Vec &a, const Vec &b);
};

struct Leaf {
  Leaf(int x, int y, int width, int height);
  int x;
  int y;
  int width;
  int height;
  Leaf *child1 = nullptr;
  Leaf *child2 = nullptr;

  void draw(SDL_Renderer *r);
  bool split();
  void createRooms(Dungeon *dungeon);
  Rect *getRoom();

private:
  Rect *room = nullptr;
  static const int minSize = 5;
};