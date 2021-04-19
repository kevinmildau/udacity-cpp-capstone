#ifndef POISON_H
#define POISON_H
#include "SDL.h"
class Poison {
	public:
	Poison(int x, int y) : x(x), y(y){
		// placement while loop taken care of in game.cpp; assume x and y are valid coord. 
		poison_graphic.x = x;
		poison_graphic.y = y;
	}
	void Update(float time_elapsed); // updated time left given float input in seconds
	SDL_Point poison_graphic; 
	float seconds_left = 6.0; // seconds left before Poison expires
};
#endif