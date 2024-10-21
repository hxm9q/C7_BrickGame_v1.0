#include "tetris.h"

int main(void) {
  WIN_INIT(50);
  setlocale(LC_ALL, "");
  srand(time(NULL));

  initscr();
  noecho();
  nodelay(stdscr, TRUE);
  start_color();

  game();

  endwin();

  return 0;
}

void game() {
  Board board = {0};
  create_board(&board);

  Game_status game_status = {0};
  create_game_status(&game_status);

  Player player = {0};
  Player next_player = {0};
  Player predict_player = {0};
  create_player(&player);
  create_next_player(&next_player);

  Player_state state = START;
  print_begin();

  bool break_flag = FALSE;
  bool key_held = false;
  int user_input = 0;

  Highscores Highscores = {0};

  long long time_in_secs = get_time_ms();

  Parameters parameters = {0};
  parameters.game_status = &game_status;
  parameters.player_state = &state;
  parameters.board = &board;
  parameters.player = &player;
  parameters.next_player = &next_player;
  parameters.predict_player = &predict_player;
  parameters.last_moved_time = &time_in_secs;
  parameters.highscores = &Highscores;

  load_highscore(parameters.highscores, HIGHSCORES_FILE);

  create_game_colors();

  while (!break_flag) {
    if (state == EXIT_STATE) break_flag = TRUE;

    Signal_type signal = get_signal(user_input, 0, &key_held);
    signal_action(signal, &parameters);

    user_input = GET_USER_INPUT;
  }
}