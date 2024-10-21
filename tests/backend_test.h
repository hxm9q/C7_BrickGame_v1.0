//
// Created by  Антон Шадрин on 03.07.2024.
//
#ifndef BACKEND_TEST_H
#define BACKEND_TEST_H

#ifndef TEST_HEADER_
#define TEST_HEADER_
#include "../src/brick_game/tetris/backend/backend.h"
#include "test.h"
#endif

START_TEST(board_overlay_blockTest) {
  Player player = {0};
  Board board = {0};

  player.x_ = 5;
  player.y_ = 5;

  player.board.board[1][1].is_set = true;
  player.board.board[1][2].is_set = true;
  player.board.board[2][1].is_set = true;

  board_overlay_block(&player, &board);

  ck_assert(board.cells[5][6].is_set);
  ck_assert(board.cells[5][7].is_set);
  ck_assert(board.cells[6][6].is_set);
}
END_TEST

START_TEST(get_time_step_msTest) {
  Game_status game_status = {0};

  game_status.level = 5;
  long long int time_step = get_time_step_ms(&game_status);
  ck_assert_int_eq(time_step, time_step_array[5]);

  game_status.level = MAX_LEVEL + 1;
  time_step = get_time_step_ms(&game_status);
  ck_assert_int_eq(time_step, time_step_array[MAX_LEVEL]);
}
END_TEST

Suite *backendsuite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("backend suite");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, board_overlay_blockTest);
  tcase_add_test(tc_core, get_time_step_msTest);

  suite_add_tcase(s, tc_core);

  return s;
}

#endif
