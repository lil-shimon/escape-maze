#include <stdio.h>
#include "constants.h"

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

/**
 * プレイヤーを移動させる関数
 * 上の場合は、playerWidthを-1
 * 下の場合は、playerWidthを+1
 * 左の場合は、playerHeightを-1
 * 右の場合は、playerHeightを+1
 * 
 * @param playerWidth
 * @param playerHeight 
 */
void MazePlayerMove(int *playerWidth, int *playerHeight, MazeCell maze[MAZE_WIDTH][MAZE_HEIGHT]) {

    /// 入力した文字列を入れる変数
    char buf[100];

    /// 方向データを入れる変数
    int direction = -1;

    printf("%d: UP\n", UP);
    printf("%d: DOWN\n", DOWN);
    printf("%d: LEFT\n", LEFT);
    printf("%d: RIGHT\n", RIGHT);
    printf("数字を入力してください >>> ");

    /// 文字列で入力を読み込む
    fgets(buf, sizeof(buf), stdin);

    /// 数字にできるときは変換（できない場合は何もしない）
    sscanf(buf, "%d", &direction);

    while(direction < 0 || direction > (Invalid - 1)) {
        printf("入力された値は正しくないです\n再度入力してください");
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d", &direction);
    }

    /// 上下右左の処理はほとんど同じなので関数にした方がまとまるが
    /// 一つ一つ書いた方が後で見直ししやすそうなので別で書く
    switch(direction) {
        /// 上移動の場合
        case UP: {
            /// 迷路の範囲外ではないことを確認
            if (*playerWidth - 1 >= MIN_WIDTH) {

                /// 移動さきを見えるようにする
                maze[*playerWidth - 1][*playerHeight].flag = VISITED;

                /// 移動さきが壁かどうか
                if (maze[*playerWidth - 1][*playerHeight].kind != WALL) {

                    /// 壁でない場合、上に移動させる
                    *playerWidth -= 1;
                    printf("\n上に移動しました\n");
                } else {
                    printf("\n壁です\n");
                }
            } else {
                printf("\n範囲外です\n");
            }
        }
        break;

        /// 下移動の場合
        case DOWN: {
            /// 現在の位置の下が迷路の内あるかを確認
            if (*playerWidth + 1 <= MAX_HEIGHT) {

                /// 移動さきを見えるようにする
                maze[*playerWidth + 1][*playerHeight].flag = VISITED;

                /// 移動先が壁かを確認
                if (maze[*playerWidth + 1][*playerHeight].kind != WALL) {
                    *playerWidth += 1;
                    printf("\n下に移動しました\n");
                } else {
                    printf("\n壁です\n");
                }
            } else {
                printf("\n範囲外です\n");
            }
        }
        break;

        /// 左移動の場合
        case LEFT: {
            if (*playerHeight - 1 >= MIN_WIDTH) {
                maze[*playerWidth][*playerHeight - 1].flag = VISITED;
                if (maze[*playerWidth][*playerHeight - 1].kind != WALL) {
                    *playerHeight -= 1;
                    printf("\n左に移動しました\n");
                } else {
                    printf("\n左側は壁です\n");
                }
            } else {
                printf("\n左側は迷路の範囲外です\n");
            }
        }
        break;

        /// 右移動の場合
        case RIGHT: {
            if (*playerHeight + 1 <= MAX_WIDTH) {
                maze[*playerWidth][*playerHeight + 1].flag = VISITED;
                if (maze[*playerWidth][*playerHeight + 1].kind != WALL) {
                    *playerHeight += 1;
                    printf("\n右に移動しました。\n");
                } else {
                    printf("\n右は壁です\n");
                }
            } else {
                printf("\n右は迷路の範囲外です。");
            }
        }
        break;
    }
}
/**
 * ゴールしているかを確認する関数
 * @param int playerWidth
 * @param int playerHeight
 * @param MazeCell maze[MAZE_WIDTH][MAZE_HEIGHT]
 * @return int 0 | 1
 */
int CheckMazeEnd(int playerWidth, int playerHeight, MazeCell maze[MAZE_WIDTH][MAZE_HEIGHT]) {
    if (maze[playerWidth][playerHeight].kind == END) {
        printf("\nゴールしました\n");
        return 1;
    }
    return 0;
}

/**
 * タイトル画面
 * @return
 */
int MazeTitle() {
    char buf[100];
    int menu = -1;

    printf("\n\n>>>ESCAPE MAZE<<<\n\n");
    printf("\nゲームメニュー\n");
    printf("%d: 簡単\n", EASY);
    printf("%d: やめる\n", EXIT);

    printf("メニューを選んでください:");

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &menu);

    while (menu < 0 || menu > EXIT) {
        printf("予期しない入力です。再入力してください\n");
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d", &menu);
    }

    return menu;
}

/**
 * 迷路ゲーム関数
 */
void MazeGame(void) {

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
    return;
  }

  while(CheckMazeEnd(player.width, player.height, maze) != 1) {
    /// 迷路を表示
    displayMaze(player.width, player.height, maze);
    /// プレイヤーを移動
    MazePlayerMove(&player.width, &player.height, maze);
  }

  displayMaze(player.width, player.height, maze);
}

int main(void) {
    int menu;

    while(1) {
        /// メニュー選択
        menu = MazeTitle();
        printf("\n");

        if(menu == EXIT) {
            break;
        } else {
            /// 迷路ゲーム
            MazeGame();
        }
    }
    return 0;
}
