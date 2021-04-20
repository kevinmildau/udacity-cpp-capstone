#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kPoisonLifeTime{kFramesPerSecond * 20}; // 20 seconds lifetime
  constexpr std::size_t kSpawnTime{kFramesPerSecond * 1}; // new poison spawn every 1 seconds
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  constexpr int kMaxNumberPoison{10}; // maximum number of poison blocks on map

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight, kPoisonLifeTime, kSpawnTime, kMaxNumberPoison);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  // -> add read file & save to file for high scores.
  return 0;
}