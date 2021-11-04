#include <stdio.h>

/**
 * MazeKind
 * PATH  = 迷路の道
 * WALL  = 迷路の壁
 * START = 迷路の始点
 * END   = 迷路の終点
 */
enum MazeKind { PATH, WALL, START, END };

/**
 * MazeFlag
 * 迷路の可視不可視
 */
enum MazeFlag { VISITED, UNVISITED };

/**
 * Maze
 * 迷路の構造体
 * MazeKind = 迷路の種類
 * MazeFlag = 迷路の可視不可視
 */
typedef struct {
    enum MazeKind kind; 
    enum MazeFlag flag; 
} MazeCell;

/**
 * 迷路の横幅
 */
#define MAZE_WIDTH  5

/**
 * 迷路の縦幅 
 */
#define MAZE_HEIGHT 5

/**
 * 迷路を表示する関数
 * 
 * @param maze 
 */
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
  // 迷路のデータ
  MazeCell maze[MAZE_WIDTH][MAZE_HEIGHT] =
    {
      { {START, VISITED}, {PATH, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED} },
      { {WALL, UNVISITED}, {WALL, UNVISITED}, {PATH, UNVISITED}, {WALL, UNVISITED}, {WALL, UNVISITED} },
      { {WALL, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED} },
      { {PATH, UNVISITED}, {PATH, UNVISITED}, {WALL, UNVISITED}, {WALL, UNVISITED}, {WALL, UNVISITED} },
      { {WALL, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED}, {END, VISITED} }
    };

  // 迷路を表示
  displayMaze(maze);

  return 0;
}

