#include "board.h"

void create_cell(Cell *cell) {
  cell->is_set = false;
  cell->color = colorBLACK;
}

void copy_cell(Cell *cell_dest, Cell cell_src) {
  cell_dest->color = cell_src.color;
  cell_dest->is_set = cell_src.is_set;
}

void create_board(Board *board) {
  board->width = boardWIDTH;
  board->height = boardHEIGHT;
  for (int i = 0; i < board->height; ++i) {
    for (int j = 0; j < board->width; ++j) {
      create_cell(&board->cells[i][j]);
    }
  }
}

int handle_boardcomplete_lines(Board *board) {
  int complete_lines_count = 0;
  for (int row = board->height; row >= 0; --row) {
    for (int row_2 = board->height; row_2 >= 0; --row_2) {
      bool flag = check_boardcomplete_line(board, row);
      if (flag) {
        complete_lines_count++;
        remove_boardline(board, row);
        apply_physics(board);
      }
    }
  }

  return complete_lines_count;
}
void remove_boardline(Board *board, int line_index) {
  for (int column = 0; column < boardWIDTH; ++column)
    create_cell(&board->cells[line_index][column]);
}

bool check_boardcomplete_line(Board *board, int row) {
  bool flag = true;
  for (int column = 0; column < boardWIDTH; ++column) {
    if (!board->cells[row][column].is_set) flag = false;
  }

  return flag;
}

void apply_physics(Board *board) {
  for (int row = board->height - 1; row >= 0; --row) {
    bool empty_line_flag = true;
    for (int column = 0; column < board->width && empty_line_flag; ++column) {
      if (board->cells[row][column].is_set) empty_line_flag = false;
    }
    if (empty_line_flag) shift_boarddown(board, row);
  }
}

void shift_boarddown(Board *board, int empty_row) {
  for (int row = empty_row; row > 1; --row) copy_boardline(board, row, row - 1);
}

void copy_boardline(Board *board, int index_dest, int index_src) {
  for (int i = 0; i < boardWIDTH; ++i)
    copy_cell(&board->cells[index_dest][i], board->cells[index_src][i]);
}

void create_playerboard(playerboard *playerboard) {
  for (int i = 0; i < playerBOARD_SIZE; ++i) {
    for (int j = 0; j < playerBOARD_SIZE; ++j)
      create_cell(&playerboard->board[i][j]);
  }
}

void copy_playerboard(playerboard *playerboard_dest,
                      playerboard playerboard_src) {
  for (int i = 0; i < playerBOARD_SIZE; ++i) {
    for (int j = 0; j < playerBOARD_SIZE; ++j)
      copy_cell(&playerboard_dest->board[i][j], playerboard_src.board[i][j]);
  }
}

void set_playerboard_block(playerboard *playerboard, Block_type block_type,
                           Block_rotation block_rotation) {
  Block_colortype block_colortype = get_block_color(block_type);
  int mask = 0b1000000000000000;

  for (int row = 0; row < playerBOARD_SIZE; row++) {
    for (int column = 0; column < playerBOARD_SIZE; column++) {
      playerboard->board[row][column].color = block_colortype;
      if (blocks_bitmask[block_type][block_rotation] & mask) {
        playerboard->board[row][column].is_set = true;
      } else {
        create_cell(&playerboard->board[row][column]);
      }
      mask >>= 1;
    }
  }
}
