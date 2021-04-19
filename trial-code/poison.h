#ifndef POISON_H
#define POISON_H

class Poison {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };
  Poison(int x, int y) : x(x), y(y){
  	// placement while loop taken care of in game.cpp; assume x and y are valid coord. 
  	int life_left = 6; // seconds left before Poison expires
  }
  void Update(); // <- not implemented
  int size{1};
  bool alive{true};
};
#endif