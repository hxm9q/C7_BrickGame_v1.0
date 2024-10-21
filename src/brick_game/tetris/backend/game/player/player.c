#include "player.h"

void create_player(Player *player) {
  create_playerboard(&player->board);
  set_player_block_type(player, get_random_block_type());
}

void create_next_player(Player *player) {
  create_player(player);
  player->x_ = NEXT_PLAYER_POS_X;
  player->y_ = NEXT_PLAYER_POS_Y;
}

void create_player_position(Player *player) {
  player->x_ = PLAYER_POS_X;
  player->y_ = PLAYER_POS_Y;
}

void copy_player(Player *player_dest, Player player_src) {
  player_dest->x_ = player_src.x_;
  player_dest->y_ = player_src.y_;
  player_dest->block_type = player_src.block_type;
  player_dest->block_rotation = player_src.block_rotation;
  player_dest->board = player_src.board;
}

void set_player_block_type(Player *player, Block_type block_type) {
  player->block_type = block_type;
  update_player_board(player);
}

void set_player_block_rotation(Player *player, Block_rotation block_rotation) {
  player->block_rotation = block_rotation;
  update_player_board(player);
}

void set_player_next_block_rotation(Player *player) {
  Block_rotation block_rotation = player->block_rotation;

  Block_rotation next_block_rotation = get_next_block_rotation(block_rotation);

  set_player_block_rotation(player, next_block_rotation);
  set_playerboard_block(&player->board, player->block_type,
                        player->block_rotation);
}

void set_player_prev_block_rotation(Player *player) {
  Block_rotation block_rotation = player->block_rotation;

  Block_rotation previous_block_rotation =
      get_prev_block_rotation(block_rotation);

  set_player_block_rotation(player, previous_block_rotation);
  set_playerboard_block(&player->board, player->block_type,
                        player->block_rotation);
}

void update_player_board(Player *player) {
  set_playerboard_block(&player->board, player->block_type, Block_rotation0);
}

void move_player_dX_dY(Player *player, int d_x, int d_y) {
  player->x_ += d_x;
  player->y_ += d_y;
}

void move_player_up(Player *player) { move_player_dX_dY(player, 0, -1); }
void move_player_down(Player *player) { move_player_dX_dY(player, 0, 1); }
void move_player_left(Player *player) { move_player_dX_dY(player, -1, 0); }
void move_player_right(Player *player) { move_player_dX_dY(player, 1, 0); }

void set_next_player_color(Player *player) {
  for (int i = 0; i < playerBOARD_SIZE; ++i) {
    for (int j = 0; j < playerBOARD_SIZE; ++j) {
      if (player->board.board[i][j].is_set)
        player->board.board[i][j].color = kBlockColorPredict;
    }
  }
}