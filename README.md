# Game Overview
This program is a simple console-based maze game where the player navigates through a maze from a starting point to an end point.

## Features
- Various maze elements such as paths, walls, start and end points.
- Player movement with basic collision detection with walls.
- Maze visibility feature, where unvisited paths are unknown until the player moves to them.
- Simple menu to start the game or exit.

## Enums
- **MazeKind**: Specifies the type of cell in the maze (PATH, WALL, START, END).
- **MazeFlag**: Indicates the visibility of the maze cell (VISITED, UNVISITED).
- **MazeDirection**: Enumerates possible movement directions (UP, DOWN, LEFT, RIGHT).
- **Menu**: Defines the options available in the game's main menu (EASY, EXIT).

## Structures
- **MazeCell**: Holds information about a single cell in the maze, including its type and visibility.
- **MazePlayer**: Stores the player's current position within the maze.

## Functions
- `displayMaze()`: Renders the maze in the console, including the player, walls, and end point.
- `InitMazePlayer()`: Initializes the player's starting position at the start point of the maze.
- `MazePlayerMove()`: Handles player movement input and updates player position, considering collisions.
- `CheckMazeEnd()`: Checks if the player has reached the end point of the maze.
- `MazeTitle()`: Displays the game's title screen and menu options.
- `MazeGame()`: Main game loop that integrates all gameplay functionalities.

## How to Play
1. Clone the repository using the command provided above.
2. Run the game using the `bash run.sh` command.
3. Choose the desired option from the main menu by inputting the corresponding number.
4. Use the displayed control keys to move the player through the maze.
5. Navigate towards the goal while uncovering paths and avoiding walls.
6. The game concludes once you reach the end point.

## Development Environment
This game is developed in C and is intended to be run in a Unix-based terminal.

## Notes
- The game is text-based and doesn't feature graphical elements.
- The maze configuration (layout and size) is pre-defined in the code.
- The game includes basic error handling for unexpected input during navigation.

## Contributing
Feel free to clone the repository and enhance the game's features. Any contributions you make are greatly appreciated.
