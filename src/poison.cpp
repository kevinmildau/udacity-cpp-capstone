#include "poison.h"
void Update(){
  frames_left = frames_left - 1;
  if (frames_left <= 0){
    alive = false;
  }
}