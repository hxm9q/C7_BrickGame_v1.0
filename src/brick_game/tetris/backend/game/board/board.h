#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

#include "../../colors/defines.h"
#include "../block/block.h"

#define playerBOARD_SIZE (4)

typedef struct {
  unsigned char color;
  bool is_set;
} Cell;

typedef struct {
  int height;
  int width;
  Cell cells[boardHEIGHT][boardWIDTH];
} Board;

typedef enum {
  boardside_up = 0,
  boardside_down = 1,
  boardside_left = 2,
  boardside_right = 3,
} boardside;

typedef struct {
  Cell board[playerBOARD_SIZE][playerBOARD_SIZE];
} playerboard;

void create_cell(Cell *cell);
void copy_cell(Cell *cell_dest, Cell cell_src);

void create_board(Board *board);
int handle_boardcomplete_lines(Board *board);
void remove_boardline(Board *board, int line_index);
void apply_physics(Board *board);
void shift_boarddown(Board *board, int empty_row);
void copy_boardline(Board *board, int index_dest, int index_src);
bool check_boardcomplete_line(Board *board, int row);

void create_playerboard(playerboard *playerboard);
void copy_playerboard(playerboard *playerboard_dest,
                      playerboard playerboard_src);

void set_playerboard_block(playerboard *playerboard, Block_type block_type,
                           Block_rotation block_rotation);

#endif
