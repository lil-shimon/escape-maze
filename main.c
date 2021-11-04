#include <stdio.h>

/// one block of maze
enum MazeKind { PATH, WALL, START, END }; // kind of maze
enum MazeFlag { VISITED, UNVISITED };     // flag of maze

typedef struct {
    enum MazeKind kind; // kind of maze
    enum MazeFlag flag; // flag of maze (visited or not)
} MazeCell;

#define MAZE_WIDTH  5 // width of maze
#define MAZE_HEIGHT 5 // height of maze

void displayMaze(MazeCell maze[MAZE_WIDTH][MAZE_HEIGHT]) {
  int i, j;

  for(i = 0; i < MAZE_WIDTH; i++) { // row
    for( j = 0; j < MAZE_HEIGHT; j++) { // column
      if (maze[i][j].flag == UNVISITED) {
          printf("?");
      } else {
        switch(maze[i][j].kind) {
          case WALL:
            printf("■");
            break;
          case END:
            printf("◉");
            break;
          default:
            printf(" ");
            break;
        }
      }
    }
    printf("\n");
  }
};

int main(void) {
  // maze
  MazeCell maze[MAZE_WIDTH][MAZE_HEIGHT] =
    {
      { {START, VISITED}, {PATH, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED} },
      { {WALL, UNVISITED}, {WALL, UNVISITED}, {PATH, UNVISITED}, {WALL, UNVISITED}, {WALL, UNVISITED} },
      { {WALL, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED} },
      { {PATH, UNVISITED}, {PATH, UNVISITED}, {WALL, UNVISITED}, {WALL, UNVISITED}, {WALL, UNVISITED} },
      { {WALL, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED}, {END, VISITED} }
    };

  displayMaze(maze);

  return 0;
}

