#ifndef POISON_H
#define POISON_H
#include "SDL.h"

class Poison {
	public:
	Poison(int x, int y){
		// placement while loop taken care of in game.cpp; assume x and y are valid coord. 
		poison_graphic.x = x;
		poison_graphic.y = y;
	}
	void Update(); // update frames left by -1 frame; run each frame
  bool alive = true;
	SDL_Point poison_graphic; 
	std::size_t frames_left = kPoisonLifeTime; // seconds left before Poison expires; <-- not sure whether size_t is the right type here
};
#endif