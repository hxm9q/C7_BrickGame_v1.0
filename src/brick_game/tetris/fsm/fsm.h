#ifndef FSM_H
#define FSM_H

#include <ncurses.h>

#include "../../../gui/cli/frontend.h"
#include "../backend/backend.h"
#include "../backend/collisions/collisions.h"
#include "../backend/parameters/parameters.h"

typedef enum {
  NO_SIGNAL = 0,
  SIGNAL_MOVE_UP = 1,
  SIGNAL_MOVE_DOWN = 2,
  SIGNAL_MOVE_LEFT = 3,
  SIGNAL_MOVE_RIGHT = 4,
  SIGNAL_ESCAPE_BUTTON = 5,
  SIGNAL_ENTER_BUTTON = 6,
  SIGNAL_PAUSE_BUTTON = 7,
} Signal_type;

typedef void (*action_callback)(Parameters *parameters);

Signal_type get_signal(int user_input, bool hold, bool *key_held);

void signal_action(Signal_type signal, Parameters *parameters);

void action_spawn(Parameters *parameters);

void action_move_up(Parameters *parameters);

void action_move_down(Parameters *parameters);

void action_move_right(Parameters *parameters);

void action_move_left(Parameters *parameters);

void action_collide(Parameters *parameters);

void action_game_over(Parameters *parameters);

void action_exit_state(Parameters *parameters);

void action_pause(Parameters *parameters);

bool check_collisions(Parameters *parameters);

#endif