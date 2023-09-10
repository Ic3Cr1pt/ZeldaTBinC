# Zelda-like Text-Based RPG Game in C

## Description
This is a simple text-based RPG game inspired by Zelda. The game is created in C and utilizes the ncurses library for rendering. The game features a player, enemies, and items in a grid-based world.

## Features
- Player can move in four directions: up, down, left, and right.
- Enemies with basic AI.
- Inventory system for item collection.
- Simple combat and health mechanics.

## Dependencies
- gcc (GNU Compiler Collection)
- ncurses library

## How to Compile and Run

### Compile
Navigate to the directory where your `main.c` and other `.c` files are located, then run:
gcc main.c -lncurses -o game

### Run
After compilation, you can run the game using:
./game

## Controls
- Arrow keys for movement.
- 'q' to quit the game.

## TODO
- [ ] Add more enemies and items.
- [ ] Implement more advanced enemy AI.

## Contributing
Feel free to fork this repository and create a pull request if you have some improvements to suggest, or open an issue if you find a bug.

## License
MIT License