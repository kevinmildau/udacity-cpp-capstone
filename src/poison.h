#ifndef POISON_H
#define POISON_H
#include "SDL.h"

class Poison {
	public:
	Poison(int x, int y, int poison_lifetime){
		// placement while loop taken care of in game.cpp; assume x and y are valid coord. 
		poison_graphic.x = x;
		poison_graphic.y = y;
		frames_left = poison_lifetime;
	};
	void Update(){
		// Update frames_left by -1. Set alive to false if frames left reaches 0 or lower.
	  frames_left = frames_left - 1;
	  if (frames_left <= 0){
	    alive = false;
	  }
	};
  bool alive = true;
	SDL_Point poison_graphic; 
	int frames_left; // frames left before Poison expires
};
#endif