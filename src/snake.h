#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include "SDL.h"
class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };
  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}
  void Update();
  void GrowBody();
  bool SnakeCellProxCheck(int x, int y);
  Direction direction = Direction::kUp; // snake movement initialized to up direction.
  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;  // Snake body vector
 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);
  bool growing{false};
  int grid_width;
  int grid_height;
};
#endif
/*
--> Snake class
- Snake Constructor puts snake head into center of map. Direction defaults to up until set 
  otherwise.
- Body of snake is a vector of coordinates (SDL-Point).
- Private member variables include grid width and grid height for dimension knowledge of snake 
  environment.
- used an enum called Direction to organize the four possible movement directions.
*/