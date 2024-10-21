#ifndef FRONTEND_H
#define FRONTEND_H

#include <ctype.h>
#include <ncurses.h>
#include <time.h>

#include "../../brick_game/tetris/backend/colors/color_handler.h"
#include "../../brick_game/tetris/backend/parameters/parameters.h"

#define MAX_LENGTH_NAME (10)

void print_username_prompt();
void print_overlay(void);
void print_borders(int top_y, int bottom_y, int left_x, int right_x);
void print_game_status(Game_status *game_status);
void print_game(Parameters *parameters);
void clear_game();
void print_block(Player *player);
void print_board(Board *board);
void get_player_name(char parameters[]);
void print_begin();
void print_pause();
void clear_highscores();
void print_highscores(Parameters *parameters);

#endif