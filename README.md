# CPPND: Capstone Snake Game Project
Based on Udacity capstone started code: https://github.com/udacity/CppND-Capstone-Snake-Game

The implemented game works similarly to the base snake game, but adds incrementially more abundant poison objects that need to be avoided. The poison landscape is continuously changing through a limited lifetime for each poison object.

# Code Overview

## Added poison class
I've added the poison.h file to the project. This file contains the Poison class container which contains an SDL_Point, a frames_left variable and update method to reduce frames_left during each game loop. The constructor creates the SDL point object using the input coordinates and initializes the frames left based on poison life time as specified in the main.cpp and incorporated as an member variable in the game class.

## Game Class changes
- Game::PlacePoison() & Game::PlaceFood: a method PlacePoison was added that, similarly to PlaceFood(), adds a poison block provided it doesn't overlap with the body of the snake. In order to further prevent any sudden death moments through the placement of poison right infront of the snake head, the SnakeCell() method was changed into a proximity check that assures the food and poison objects are at least a certain distance (1/5 of the grid width) away from the snake head.
- Game::Game() : added a number of variables as input to allow main game experience to be set in main.cpp
- Game::Update() : 
Poison object spawns and lifetime checks happen in the game::Update(). A frame based timer variable was added to game to allow poison to be placed gradually (1 per second max).
- Game class now contains a few new member variables: all_poison which is a vector for poison class objects, as well as a number of poison lifetime and spawn cycle related variables.

## Snake Class Changes
- Snake::SnakeCell() turned into Snake::SnakeCellProxCheck(): a proximity check that assures the food and poison objects are at least a certain distance (1/5 of the grid width) away from the snake head. For poison, this avoids any sudden deaths caused by poison to spawn right in front of the snake.

## Renderer Class Changes
- Renderer::Render() : now accepts all_poison vector as input and includes a render loop for the poison objects. Poison objects color is specified using int based RGB (light green).

## main.cpp changes
- a few new variables that are passed to the game class. All related to framerate and poison lifetime and spawn cycles. 
- a new read and write routine is added that keeps track of the highscore. 

# Fulfilled Project Rubrics
## Mandatory Rubrics

### Rubric Number 01 - Project compiles and runs.
- [x] project compiles
Running the following line of bash-code from build directory compiles the project and runs the game.

```bash
mkdir build && cd build
cmake.. && make && ./SnakeGame
```

## Additional Rubrics Satisfied 

### Rubric 1
The project uses Object Oriented Programming techniques. The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.

- Poison class added into Snake Game
- Poison class has a constructor and an update method.
- Poison is spawned and stored in game class methods. Poison is rendered in rendere class methods.

### Rubric 2
Classes use appropriate access specifiers for class members. All class data members are explicitly specified as public, protected, or private.
- Poison class members are explicitly specified as public. 

### Rubric 3
Classes abstract implementation details from their interfaces. All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.
- Poison class update and constructor methods have clear documentation and usage case.
- Poison class allows for both an SDL_Point to be stored, as well as for the addition of limited life time to the poison objects.

### Rubric 4
The project reads data from a file and process the data, or the program writes data to a file. The project reads data from an external file or writes data to a file as part of the necessary operation of the program.
- a high score is saved to file and replaced if game ends with higher score. 

### Rubric 5
The project demonstrates an understanding of C++ functions and control structures. A variety of control structures are used in the project. The project code is clearly organized into functions.
- all operations are conducted in relevant functions or class methods
- all_poison vector is traversed using loops, checked for expired poison and upated.

