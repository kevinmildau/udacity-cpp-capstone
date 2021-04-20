#ifndef GAME_H
#define GAME_H
#include <random>
#include <vector>
#include <memory>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "poison.h"
class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height, 
       std::size_t poison_lifetime, std::size_t spawn_cooldown,
       int max_number_poison);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
 private:
  Snake snake;
  SDL_Point food;

  // Add Poison Lifetime variable
  // Not that size_t are implicitly converted to int here
  int plifetime;
  int spawntime; // <- total number of frames until spawn
  int frames_until_spawn; // <-- spawn timer
  // Poison vector
  std::vector<Poison> all_poison;
  int max_poison;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  int score{0};
  void PlacePoison(); // <-- Adds poison item
  void PlaceFood();
  void Update();
};
#endif