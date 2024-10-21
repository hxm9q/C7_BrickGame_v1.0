#ifndef BACKEND_H
#define BACKEND_H

#include <string.h>

#include "../time/time.h"
#include "collisions/collisions.h"
#include "parameters/parameters.h"

#define MAX_LEVEL (10)

static const long long time_step_array[11] = {1000, 875, 625, 550, 425, 350,
                                              325,  300, 250, 200, 150};

void board_overlay_block(Player *player, Board *board);
void move_predict_player_down(Player *player, Board *board);
void update_predict_player(Player *player_dest, Player player_src,
                           Board *board);
long long int get_time_step_ms(Game_status *game_status);

#endif