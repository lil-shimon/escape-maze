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
 * プレイヤー構造体
 * width  = プレイヤーがどこのマスにいるか(行)
 * height = プレイヤーがどこのマスにいるか(列)
 */
typedef struct {
  int width;
  int height;
} MazePlayer;

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
 * @param playerWidth int プレイヤーの位置(行)
 * @param playerHeight int プレイヤーの位置(列)
 * @param maze MazeCell 迷路データ
 */
void displayMaze(int playerWidth, int playerHeight, MazeCell maze[MAZE_WIDTH][MAZE_HEIGHT]) {
  int i, j;

  for(i = 0; i < MAZE_WIDTH; i++) { // row
    for( j = 0; j < MAZE_HEIGHT; j++) { // column
      if (i == playerWidth && j == playerHeight) {
          printf("P");
      } else if (maze[i][j].flag == UNVISITED) {
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

/**
 * 引数のplayerWidth, playerHeightに開始地点の行と列データを入れる
 * @param playerWidth  intへのポインタ型　プレイヤーがどこのマスにいるか(行)
 * @param playerHeight intへのポインタ型　プレイヤーがどこのマスにいるか(列)
 * @param maze 迷路データ
 * @return int 成功判定 0:成功 -1:失敗
 */
int InitMazePlayer(int *playerWidth, int *playerHeight, MazeCell maze[MAZE_WIDTH][MAZE_HEIGHT]) {
  int i, j;
  for (i = 0; i < MAZE_WIDTH; i++) {
    for (j = 0; j < MAZE_HEIGHT; j++) {
      /// スタート地点を探す
      /// スタート地点の場合、widthとheightを設定する
      if (maze[i][j].kind == START) {
        *playerWidth = i;
        *playerHeight = j;
        return 0;
      }
    }
  }

  /// 見つからない場合はこの処理
  printf("STARTが見つかりませんでした\n");
  return -1;
}

int main(void) {

  /**
   * 迷路プレイヤー
   */
  MazePlayer player;

  // 迷路のデータ
  MazeCell maze[MAZE_WIDTH][MAZE_HEIGHT] =
    {
      { {START, VISITED}, {PATH, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED} },
      { {WALL, UNVISITED}, {WALL, UNVISITED}, {PATH, UNVISITED}, {WALL, UNVISITED}, {WALL, UNVISITED} },
      { {WALL, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED} },
      { {PATH, UNVISITED}, {PATH, UNVISITED}, {WALL, UNVISITED}, {WALL, UNVISITED}, {WALL, UNVISITED} },
      { {WALL, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED}, {PATH, UNVISITED}, {END, VISITED} }
    };
  
  // プレイヤーの初期化
  if (InitMazePlayer(&player.width, &player.height, maze) != 0) {
    return -1;
  }

  // 迷路を表示
  displayMaze(player.width, player.height, maze);

  return 0;
}

