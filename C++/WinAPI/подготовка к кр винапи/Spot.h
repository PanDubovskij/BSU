#pragma once
#include "framework.h"

class Spot {
 public:
  int x_;
  int y_;
  int type;
  COLORREF color_;
  Spot() = default;
  Spot(int _x, int _y) : x_(_x), y_(_y) {  }
};
