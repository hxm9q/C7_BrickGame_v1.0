#include "collisions.h"

bool check_future_collide_with_up(Player *player, Board *board) {
  return check_future_collide_with_side(player, board, boardside_up);
}
bool check_future_collide_with_down(Player *player, Board *board) {
  return check_future_collide_with_side(player, board, boardside_down);
}
bool check_future_collide_with_left(Player *player, Board *board) {
  return check_future_collide_with_side(player, board, boardside_left);
}
bool check_future_collide_with_right(Player *player, Board *board) {
  return check_future_collide_with_side(player, board, boardside_right);
}

bool check_collide_with_up(Player *player, Board *board) {
  return check_collide_with_side(player, board, boardside_up);
}
bool check_collide_with_down(Player *player, Board *board) {
  return check_collide_with_side(player, board, boardside_down);
}
bool check_collide_with_left(Player *player, Board *board) {
  return check_collide_with_side(player, board, boardside_left);
}
bool check_collide_with_right(Player *player, Board *board) {
  return check_collide_with_side(player, board, boardside_right);
}

bool check_collide(Player *player, Board *board) {
  bool flag = check_collide_with_up(player, board);
  flag |= check_collide_with_down(player, board);
  flag |= check_collide_with_left(player, board);
  flag |= check_collide_with_right(player, board);
  flag |= check_collide_with_blocks(player, board);

  return flag;
}

bool check_collide_with_side(Player *player, Board *board,
                             boardside boardside) {
  playerboard *playerboard = &player->board;
  for (int row = 0; row < playerBOARD_SIZE; ++row) {
    for (int column = 0; column < playerBOARD_SIZE; ++column) {
      if (playerboard->board[row][column].is_set) {
        int cell_global_pos_x = player->x_ + column;
        int cell_global_pos_y = player->y_ + row;
        bool flag = perform_collide_check_with_side(
            board, boardside, cell_global_pos_x, cell_global_pos_y);
        if (flag) return flag;
      }
    }
  }

  return false;
}

bool check_future_collide_with_side(Player *player, Board *board,
                                    boardside boardside) {
  playerboard *playerboard = &player->board;
  for (int row = 0; row < playerBOARD_SIZE; ++row) {
    for (int column = 0; column < playerBOARD_SIZE; ++column) {
      if (playerboard->board[row][column].is_set) {
        int cell_global_pos_x = player->x_ + column;
        int cell_global_pos_y = player->y_ + row;
        bool flag = perform_future_collide_check_with_side(
            board, boardside, cell_global_pos_x, cell_global_pos_y);
        if (flag) return flag;
      }
    }
  }

  return false;
}

bool perform_collide_check_with_side(Board *board, boardside boardside, int x,
                                     int y) {
  switch (boardside) {
    case boardside_up:
      if (y < 0) return true;

      break;
    case boardside_down:
      if (y > board->height) return true;

      break;
    case boardside_left:
      if (x <= -1) return true;

      break;
    case boardside_right:
      if (x >= board->width) return true;

      break;
    default:
      break;
  }

  return false;
}

bool perform_future_collide_check_with_side(Board *board, boardside boardside,
                                            int x, int y) {
  switch (boardside) {
    case boardside_up:
      if (y - 1 < 0) return true;

      break;
    case boardside_down:
      if (y + 1 > board->height) return true;

      break;
    case boardside_left:
      if (x - 1 < 0) return true;

      break;
    case boardside_right:
      if (x + 1 >= board->width) return true;

      break;
    default:
      break;
  }

  return false;
}

bool check_collide_with_blocks(Player *player, Board *board) {
  playerboard *playerboard = &player->board;

  for (int row = 0; row < playerBOARD_SIZE; ++row) {
    for (int column = 0; column < playerBOARD_SIZE; ++column) {
      if (playerboard->board[row][column].is_set) {
        int cell_global_pos_x = player->x_ + column;
        int cell_global_pos_y = player->y_ + row;
        bool flag = board->cells[cell_global_pos_y][cell_global_pos_x].is_set;
        if (flag) return flag;
      }
    }
  }

  return false;
}
bool check_future_collide_with_blocks_left(Player *player, Board *board) {
  playerboard *playerboard = &player->board;

  for (int row = 0; row < playerBOARD_SIZE; ++row) {
    for (int column = 0; column < playerBOARD_SIZE; ++column) {
      if (playerboard->board[row][column].is_set) {
        bool flag = false;
        int cell_global_pos_x = player->x_ + column - 1;
        int cell_global_pos_y = player->y_ + row;
        if (cell_global_pos_x < -1 || cell_global_pos_x > 8) {
          flag |= true;
        }
        flag |= board->cells[cell_global_pos_y][cell_global_pos_x].is_set;
        if (flag) return flag;
      }
    }
  }

  return false;
}
bool check_future_collide_with_blocks_right(Player *player, Board *board) {
  playerboard *playerboard = &player->board;

  for (int row = 0; row < playerBOARD_SIZE; ++row) {
    for (int column = 0; column < playerBOARD_SIZE; ++column) {
      if (playerboard->board[row][column].is_set) {
        int cell_global_pos_x = player->x_ + column + 1;
        int cell_global_pos_y = player->y_ + row;
        bool flag = board->cells[cell_global_pos_y][cell_global_pos_x].is_set;
        if (flag) return flag;
      }
    }
  }

  return false;
}