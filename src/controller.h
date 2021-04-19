#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "snake.h"
class Controller {
 public:
  void HandleInput(bool &running, Snake &snake) const;
 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};
#endif
/*
Controller Class. 
-> Handles the user input & directs snake movement direction.
-> Snake is passed by reference.
*/