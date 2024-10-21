#include "backend.h"

void board_overlay_block(Player *player, Board *board) {
  playerboard *playerboard = &player->board;

  int playerpos_x = player->x_;
  int playerpos_y = player->y_ - 1;

  for (int row = 0; row < playerBOARD_SIZE; ++row) {
    for (int column = 0; column < playerBOARD_SIZE; ++column) {
      int cell_global_pos_x = playerpos_x + column;
      int cell_global_pos_y = playerpos_y + row;
      Cell *boardcell = &board->cells[cell_global_pos_y][cell_global_pos_x];
      Cell playercell = playerboard->board[row][column];

      if (playercell.is_set) copy_cell(boardcell, playercell);
    }
  }
}

void move_predict_player_down(Player *player, Board *board) {
  bool break_flag = false;
  while (!break_flag) {
    if (check_future_collide_with_down(player, board)) break_flag = true;

    if (check_collide_with_blocks(player, board)) break_flag = true;

    if (!break_flag) move_player_down(player);
  }
  move_player_up(player);
}

void update_predict_player(Player *player_dest, Player player_src,
                           Board *board) {
  copy_player(player_dest, player_src);
  move_predict_player_down(player_dest, board);
  set_next_player_color(player_dest);
}

long long int get_time_step_ms(Game_status *game_status) {
  if (game_status->level > MAX_LEVEL) game_status->level = MAX_LEVEL;

  return time_step_array[game_status->level];
}
