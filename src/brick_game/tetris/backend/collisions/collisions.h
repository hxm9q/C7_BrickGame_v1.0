#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "../game/player/player.h"

bool perform_collide_check_with_side(Board *board, boardside boardside, int x,
                                     int y);
bool check_collide_with_side(Player *player, Board *board, boardside boardside);
bool check_collide_with_up(Player *player, Board *board);
bool check_collide_with_down(Player *player, Board *board);
bool check_collide_with_left(Player *player, Board *board);
bool check_collide_with_right(Player *player, Board *board);
bool check_collide(Player *player, Board *board);

bool perform_future_collide_check_with_side(Board *board, boardside boardside,
                                            int x, int y);
bool check_future_collide_with_side(Player *player, Board *board,
                                    boardside boardside);
bool check_future_collide_with_up(Player *player, Board *board);
bool check_future_collide_with_down(Player *player, Board *board);
bool check_future_collide_with_left(Player *player, Board *board);
bool check_future_collide_with_right(Player *player, Board *board);

bool check_collide_with_blocks(Player *player, Board *board);

bool check_future_collide_with_blocks_left(Player *player, Board *board);
bool check_future_collide_with_blocks_right(Player *player, Board *board);

#endif
