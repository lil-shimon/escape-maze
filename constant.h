#ifndef CONSTANT_H
#define CONSTANT_H

/**
 * 迷路の横幅
 */
#define MAZE_WIDTH  5

/**
 * 迷路の縦幅 
 */
#define MAZE_HEIGHT 5


#define MIN_WIDTH 0
#define MAX_WIDTH (MAZE_WIDTH - 1)
#define MIN_HEIGHT 0
#define MAX_HEIGHT (MAZE_HEIGHT - 1)

// MazeKindの定義
typedef enum {
    PATH,  // 迷路の道
    WALL,  // 迷路の壁
    START, // 迷路の始点
    END    // 迷路の終点
} MazeKind;

// MazeFlagの定義
typedef enum {
    VISITED,   // 迷路の訪問済み
    UNVISITED  // 迷路の未訪問
} MazeFlag;

// MazeDirectionの定義
typedef enum {
    UP,       // 上方向
    DOWN,     // 下方向
    LEFT,     // 左方向
    RIGHT,    // 右方向
    Invalid   // 無効な方向
} MazeDirection;

// Menuの定義
typedef enum {
    EASY,  // イージーモード
    EXIT   // 終了
} Menu;

#endif // CONSTANT_H