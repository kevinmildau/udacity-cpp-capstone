#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int readHighScore(){
  // Reads oneline from txt file containing only one integer high score. 
  int score;
  std::ifstream input("high-score"); 
  input >> score; 
  //std::cout << score << "\n";
  return score;
}

void overwriteHighScore(int new_score){
  // Replace previous high score with new high score
  std::ofstream output_stream("high-score", std::ofstream::trunc);
  output_stream << new_score;
  output_stream.close();
}
void compareScore(int new_score){
  // Function compares new_score to score saved in file (file must be initialized with 0)
  float old_score = readHighScore();
  if (new_score > old_score){
    std::cout << "New High-Score! \n" << "New Score: " << new_score << 
      ", Old Score: " << old_score << "\n";
    overwriteHighScore(new_score);
  } else {
    std::cout << "No New High-Score :'( \n" << "Current Game-Score: " << new_score << 
      ", High-Score: " << old_score << "\n";
  }
}

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
  compareScore(game.GetScore());
  std::cout << "Game has terminated successfully!\n";
  //std::cout << "Current Game-End Score: " << game.GetScore() << "\n";
  //std::cout << "Current Size: " << game.GetSize() << "\n";
  return 0;
}