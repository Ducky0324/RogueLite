#pragma once
#include "stage.hpp"

class StageBuilder {
public:
  StageBuilder(Stage *stage);

  virtual void generate() = 0;

protected:
  Stage *stage = nullptr;
};