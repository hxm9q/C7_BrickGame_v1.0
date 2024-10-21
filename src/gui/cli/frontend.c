#include "frontend.h"

void print_overlay(void) {
  print_borders(0, boardHEIGHT + 1, 0, boardWIDTH + 1);
  print_borders(0, boardHEIGHT + 1, boardWIDTH + 2, boardWIDTH + HUD_WIDTH + 3);

  print_borders(1, 6, boardWIDTH + 3, boardWIDTH + HUD_WIDTH + 2);

  print_borders(7, 9, boardWIDTH + 3, boardWIDTH + HUD_WIDTH + 2);
  print_borders(10, 12, boardWIDTH + 3, boardWIDTH + HUD_WIDTH + 2);

  MVPRINTW(1, boardWIDTH + 5, "Next");
  MVPRINTW(7, boardWIDTH + 5, "Score");
  MVPRINTW(10, boardWIDTH + 5, "Level");
}

void print_username_prompt() {
  print_borders(boardHEIGHT / 2 - 5, boardHEIGHT / 2 + 5, BOARDS_BEGIN,
                BOARDS_BEGIN + boardWIDTH * 2);
  for (int i = boardHEIGHT / 2 - 5 + 1; i < boardHEIGHT / 2 - 5 + 1 + 9; ++i) {
    for (int j = BOARDS_BEGIN + 1; j < BOARDS_BEGIN + 1 + 19; ++j)
      MVPRINTW(i, j, " ");
  }

  MVPRINTW(7, 5, "Enter your name:");
}

void print_borders(int top_y, int bottom_y, int left_x, int right_x) {
  MVADDCH(top_y, left_x, ACS_ULCORNER);

  int i = left_x + 1;

  for (; i < right_x; i++) MVADDCH(top_y, i, ACS_HLINE);
  MVADDCH(top_y, i, ACS_URCORNER);

  for (int i_2 = top_y + 1; i_2 < bottom_y; i_2++) {
    MVADDCH(i_2, left_x, ACS_VLINE);
    MVADDCH(i_2, right_x, ACS_VLINE);
  }

  MVADDCH(bottom_y, left_x, ACS_LLCORNER);
  i = left_x + 1;
  for (; i < right_x; i++) MVADDCH(bottom_y, i, ACS_HLINE);
  MVADDCH(bottom_y, i, ACS_LRCORNER);
}

void print_game_status(Game_status *game_status) {
  MVPRINTW(8, boardWIDTH + 5, "%7d", game_status->score);
  MVPRINTW(11, boardWIDTH + 5, "%7d", game_status->level);
}

void clear_game() {
  for (int row = 0; row < 24; ++row) {
    for (int column = 0; column < 28; ++column) {
      attron(COLOR_PAIR(INIT_COLOR_PAIR));
      mvprintw(row + BOARDS_BEGIN + 1, column + BOARDS_BEGIN + 1, " ");
      attroff(COLOR_PAIR(INIT_COLOR_PAIR));
    }
  }
}

void print_game(Parameters *parameters) {
  clear_game();
  print_overlay();
  print_board(parameters->board);
  print_game_status(parameters->game_status);
  print_highscores(parameters);
  print_block(parameters->predict_player);
  print_block(parameters->player);
  print_block(parameters->next_player);
}

void print_board(Board *board) {
  for (int row = 0; row < 20; ++row) {
    for (int column = 0; column < 10; ++column) {
      if (board->cells[row][column].is_set) {
        int color = board->cells[row][column].color;
        attron(COLOR_PAIR(array_block_color_pairs[color]));
        mvprintw(row + BOARDS_BEGIN + 1, column + BOARDS_BEGIN + 1, "S");
        attroff(COLOR_PAIR(array_block_color_pairs[color]));
      } else {
        attron(COLOR_PAIR(INIT_COLOR_PAIR));
        mvprintw(row + BOARDS_BEGIN + 1, column + BOARDS_BEGIN + 1, " ");
        attroff(COLOR_PAIR(INIT_COLOR_PAIR));
      }
    }
  }
}

void print_block(Player *player) {
  int playerpos_x = player->x_;
  int playerpos_y = player->y_;
  playerboard playerboard = player->board;

  for (int row = 0; row < playerBOARD_SIZE; ++row) {
    for (int column = 0; column < playerBOARD_SIZE; ++column) {
      int print_y = playerpos_y + BOARDS_BEGIN + 1 + row;
      int print_x = playerpos_x + BOARDS_BEGIN + 1 + column;
      if (playerboard.board[row][column].is_set) {
        int color = playerboard.board[row][column].color;
        attron(COLOR_PAIR(array_block_color_pairs[color]));
        mvprintw(print_y, print_x, "F");
        attroff(COLOR_PAIR(array_block_color_pairs[color]));
      }
    }
  }
}

void get_player_name(char str[]) {
  print_username_prompt();
  int ch;
  int i = 0;

  flushinp();

  refresh();
  while ((ch = getch()) != '\n') {
    if (ch == ERR) {
      continue;
    } else if (ch == KEY_BACKSPACE || ch == DELETE) {
      if (i > 0) {
        i--;
        str[i] = '\0';
        mvprintw(12, 6, "%*s", MAX_LENGTH_NAME + 8, " ");
        mvprintw(12, 6, "%s", str);
        move(MAX_LENGTH_NAME, 6 + i);
        refresh();
      }
    } else if (i < MAX_LENGTH_NAME - 1 && isprint(ch)) {
      str[i++] = ch;
      str[i] = '\0';
      mvprintw(12, 6, "%s", str);
      refresh();
    }
  }
  getch();
}

void print_begin() {
  clear_game();

  print_borders(0, BOARDS_BEGIN + boardHEIGHT - 1, 0,
                BOARDS_BEGIN + boardWIDTH + HUD_WIDTH + 1);
  mvprintw(12, 8, "Press Enter");
}

void print_pause() {
  print_borders(0 + 8, BOARDS_BEGIN + boardHEIGHT - 1 - 8, 0 + 4,
                BOARDS_BEGIN + boardWIDTH + HUD_WIDTH + 1 - 4);
  for (int i = 11; i < 15; ++i) {
    for (int j = 7; j < 23; ++j) {
      mvprintw(i, j, " ");
    }
  }
  mvprintw(12, 8, "Game is paused");
}

void clear_highscores() {}

void print_highscores(Parameters *parameters) {
  clear_highscores();
  print_borders(13, 20, 13, 24);
  mvprintw(15, 17, "Highscores");

  attron(COLOR_PAIR(Highscore_1_COLOR_PAIR_INDEX));
  mvprintw(16, 16, "1. %7d", parameters->highscores->highscores[0].score);
  attron(COLOR_PAIR(Highscore_1_COLOR_PAIR_INDEX));
  attron(COLOR_PAIR(Highscore_2_COLOR_PAIR_INDEX));
  mvprintw(17, 16, "2. %7d", parameters->highscores->highscores[1].score);
  attroff(COLOR_PAIR(Highscore_2_COLOR_PAIR_INDEX));
  attron(COLOR_PAIR(Highscore_3_COLOR_PAIR_INDEX));
  mvprintw(18, 16, "3. %7d", parameters->highscores->highscores[2].score);
  attroff(COLOR_PAIR(Highscore_3_COLOR_PAIR_INDEX));

  attron(COLOR_PAIR(Highscore_4_5_COLOR_PAIR_INDEX));
  mvprintw(19, 16, "4. %7d", parameters->highscores->highscores[3].score);
  attroff(COLOR_PAIR(Highscore_4_5_COLOR_PAIR_INDEX));
  attron(COLOR_PAIR(Highscore_4_5_COLOR_PAIR_INDEX));
  mvprintw(20, 16, "5. %7d", parameters->highscores->highscores[4].score);
  attroff(COLOR_PAIR(Highscore_4_5_COLOR_PAIR_INDEX));
}
