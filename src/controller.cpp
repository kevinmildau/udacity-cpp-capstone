#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"
void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}
void Controller::HandleInput(bool &running, Snake &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;
        case SDLK_DOWN:
          ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;
        case SDLK_LEFT:
          ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;
        case SDLK_RIGHT:
          ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
      }
    }
  }
}
/*
-> ChangeDirection()
Simple movement direction control: if direction is opposite, the snake would turn into itself. This 
is an illegal move. Moreover, if the snake is size 1, it cannot turn onto itself and hence any 
movement is legal. 
--> HandleInput()
interface between valid control input and changeDirection based on SDL2 library. Takes a snake
reference as an input, as well as a reference to a boolean called running. Running is defined as 
true in front of the gameloop in game.cpp. Unless the gameloop is terminated, it will always be
true.
*/