#ifndef PLAYER_H
#define PLAYER_H

#include "../block/block.h"
#include "../board/board.h"

#define PLAYER_POS_X (3)
#define PLAYER_POS_Y (0)

#define NEXT_PLAYER_POS_X (16)
#define NEXT_PLAYER_POS_Y (1)

typedef struct {
  int x_;
  int y_;
  Block_type block_type;
  Block_rotation block_rotation;
  playerboard board;
} Player;

void create_player(Player *player);
void create_next_player(Player *player);
void copy_player(Player *player_dest, Player player_src);
void create_player_position(Player *player);
void set_player_block_type(Player *player, Block_type block_type);
void set_player_block_rotation(Player *player, Block_rotation block_rotation);
void set_player_next_block_rotation(Player *player);
void set_player_prev_block_rotation(Player *player);
void update_player_board(Player *player);
void set_next_player_color(Player *player);

void move_player_dX_dY(Player *player, int d_x, int d_y);
void move_player_up(Player *player);
void move_player_down(Player *player);
void move_player_left(Player *player);
void move_player_right(Player *player);

#endif
