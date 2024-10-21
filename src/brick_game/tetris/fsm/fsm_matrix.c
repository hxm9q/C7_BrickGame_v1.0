#include <time.h>

#include "fsm.h"

action_callback fsm_table[7][8] = {
    {NULL, NULL, NULL, NULL, NULL, action_exit_state, action_spawn, NULL},
    {action_spawn, action_spawn, action_spawn, action_spawn, action_spawn,
     action_spawn, action_spawn, NULL},
    {NULL, action_move_up, action_move_down, action_move_left,
     action_move_right, action_exit_state, NULL, action_pause},
    {action_collide, action_collide, action_collide, action_collide,
     action_collide, action_collide, action_collide, action_collide},
    {action_game_over, action_game_over, action_game_over, action_game_over,
     action_game_over, action_game_over, action_spawn, action_collide},
    {action_exit_state, action_exit_state, action_exit_state, action_exit_state,
     action_exit_state, action_exit_state, action_exit_state,
     action_exit_state},
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, action_pause},
};

void signal_action(Signal_type signal, Parameters *parameters) {
  action_callback act = fsm_table[*parameters->player_state][signal];

  if (act) act(parameters);

  bool flag_print_game = (*parameters->player_state != (START));
  flag_print_game &= (*parameters->player_state != (PAUSE));
  if (flag_print_game) print_game(parameters);

  long long time_in_ms = get_time_ms();

  if (*parameters->player_state == MOVING) {
    long long time_step = get_time_step_ms(parameters->game_status);
    if (time_in_ms - *parameters->last_moved_time > time_step) {
      *parameters->last_moved_time = time_in_ms;
      action_move_down(parameters);
    }
  }
}

Signal_type get_signal(int user_input, bool hold, bool *key_held) {
  Signal_type signal = NO_SIGNAL;

  if (hold) {
    *key_held = true;
  } else {
    switch (user_input) {
      case KEY_UP:
        signal = SIGNAL_MOVE_UP;
        break;
      case KEY_DOWN:
        signal = SIGNAL_MOVE_DOWN;
        break;
      case KEY_LEFT:
        signal = SIGNAL_MOVE_LEFT;
        break;
      case KEY_RIGHT:
        signal = SIGNAL_MOVE_RIGHT;
        break;
      case ESCAPE:
        signal = SIGNAL_ESCAPE_BUTTON;
        break;
      case ENTER_KEY:
        signal = SIGNAL_ENTER_BUTTON;
        break;
      case PAUSE_KEY:
        signal = SIGNAL_PAUSE_BUTTON;
        break;
      default:
        signal = NO_SIGNAL;
        break;
    }
    *key_held = false;
  }

  return signal;
}

bool check_collisions(Parameters *parameters) {
  bool flag = false;

  if (check_future_collide_with_down(parameters->player, parameters->board)) {
    *parameters->player_state = COLLIDE;
    flag = true;
  } else if (check_collide_with_blocks(parameters->player, parameters->board)) {
    *parameters->player_state = COLLIDE;
    flag = true;
  }

  return flag;
}

void action_spawn(Parameters *parameters) {
  create_player(parameters->player);
  create_player_position(parameters->player);

  Block_type next_block_type = parameters->next_player->block_type;
  set_player_block_type(parameters->player, next_block_type);
  if (check_collisions(parameters)) {
    *parameters->player_state = GAME_OVER;
  } else {
    update_predict_player(parameters->predict_player, *parameters->player,
                          parameters->board);

    set_player_block_type(parameters->next_player, get_random_block_type());

    *parameters->player_state = MOVING;
  }
}

void action_move_up(Parameters *parameters) {
  set_player_next_block_rotation(parameters->player);
  if (check_collide(parameters->player, parameters->board))
    set_player_prev_block_rotation(parameters->player);

  update_predict_player(parameters->predict_player, *parameters->player,
                        parameters->board);
  check_collisions(parameters);
}

void action_move_down(Parameters *parameters) {
  move_player_down(parameters->player);

  check_collisions(parameters);
}

void action_move_left(Parameters *parameters) {
  bool flag_ok =
      !check_future_collide_with_left(parameters->player, parameters->board);
  flag_ok &= !check_future_collide_with_blocks_left(parameters->player,
                                                    parameters->board);
  if (flag_ok) move_player_left(parameters->player);

  update_predict_player(parameters->predict_player, *parameters->player,
                        parameters->board);
  check_collisions(parameters);
}

void action_move_right(Parameters *parameters) {
  bool flag_ok =
      !check_future_collide_with_right(parameters->player, parameters->board);
  flag_ok &= !check_future_collide_with_blocks_right(parameters->player,
                                                     parameters->board);
  if (flag_ok) move_player_right(parameters->player);

  update_predict_player(parameters->predict_player, *parameters->player,
                        parameters->board);
  check_collisions(parameters);
}

void action_collide(Parameters *parameters) {
  board_overlay_block(parameters->player, parameters->board);

  *parameters->player_state = SPAWN;

  int complete_lines_count = handle_boardcomplete_lines(parameters->board);

  if (complete_lines_count > 0) {
    add_score_game_status(parameters->game_status, complete_lines_count);
    update_game_status(parameters->game_status);
    add_highscore(parameters->highscores, "Unnamed",
                  parameters->game_status->score);
  }
}

void action_game_over(Parameters *parameters) {
  char name[14] = {0};
  get_player_name(name);

  remove_highscore(parameters->highscores, "Unnamed");
  add_highscore(parameters->highscores, name, parameters->game_status->score);

  create_board(parameters->board);
  create_game_status(parameters->game_status);
  *parameters->player_state = START;

  print_begin();
}

void action_exit_state(Parameters *parameters) {
  save_highscore(parameters->highscores, HIGHSCORES_FILE);
  *parameters->player_state = EXIT_STATE;
}
void action_pause(Parameters *parameters) {
  if (*parameters->player_state != PAUSE) {
    *parameters->player_state = PAUSE;
    print_pause();
  } else {
    *parameters->player_state = MOVING;
  }
}