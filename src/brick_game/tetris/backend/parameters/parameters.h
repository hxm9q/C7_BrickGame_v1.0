#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <utime.h>

#include "../game/player/player.h"
#include "../game_status/game_status.h"
#include "../highscores/highscores.h"

typedef enum {
  START = 0,
  SPAWN = 1,
  MOVING = 2,
  COLLIDE = 3,
  GAME_OVER = 4,
  EXIT_STATE = 5,
  PAUSE = 6,
} Player_state;

typedef struct {
  Game_status *game_status;
  Player_state *player_state;
  Board *board;
  Player *player;
  Player *next_player;
  Player *predict_player;
  Highscores *highscores;
  long long *last_moved_time;
} Parameters;

#endif
