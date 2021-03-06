#include "game.h"
#include <iostream>
#include "SDL.h"
#include "poison.h"
// game constructor
Game::Game(std::size_t grid_width, std::size_t grid_height, 
           std::size_t poison_lifetime, std::size_t spawn_cooldown,
           int max_number_poison)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  plifetime = poison_lifetime;
  spawntime = spawn_cooldown; 
  frames_until_spawn = spawn_cooldown;
  max_poison = max_number_poison;
  PlaceFood();
}
void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  while (running) {
    frame_start = SDL_GetTicks();
    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, all_poison);
    frame_end = SDL_GetTicks();
    frame_count++;
    frame_duration = frame_end - frame_start;
    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }
    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}
void Game::PlacePoison(){
  // Method adds a poison item to the all_poison vector.
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    if (!snake.SnakeCellProxCheck(x, y)) {
      // No check for two poison on one spot; simply makes poison live longer.
      Poison poison(x,y,plifetime);
      all_poison.push_back(poison);
      return;
    }
  }
}
void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCellProxCheck(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}
void Game::Update() {
  if (!snake.alive) return;
  snake.Update();
  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);
  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.005; // slowed down speed increase
    if (score % 5 == 0){ // allow for more poison as score increases
      std::cout << "Increasing difficulty: max poison +1!\n"; 
      max_poison++;
    }
  }
  // Check if there's poison over here
  for (auto const &poison : all_poison){
    if (new_x == poison.poison_graphic.x && new_y == poison.poison_graphic.y) {
      snake.alive = false;
      std::cout << "Poison Consumed! GAME OVER!\n";
    }
  }
  // Update all_poison vector; remove frame from time_left and remove from all_poison if no time
  for (std::vector<Poison>::iterator poison=all_poison.begin(); poison!=all_poison.end();){
    poison->Update();
    if(poison->frames_left<=0) {
      poison -> alive = false; // not necessary...
      all_poison.erase(poison);
    } else {
      ++poison;
    }
  }
  // Next placement poison routine; first decrease frames until spawn by one
  frames_until_spawn--;
  // add new poison & reset frames until spawn
  if (frames_until_spawn <= 0 && size(all_poison) < max_poison){
    Game::PlacePoison();
    frames_until_spawn = spawntime;
  }
}
int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }