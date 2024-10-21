#ifndef BOARD_TEST_H
#define BOARD_TEST_H

#ifndef TEST_HEADER_
#define TEST_HEADER_
#include "../src/brick_game/tetris/backend/backend.h"
#include "test.h"
#endif

START_TEST(handle_boardcomplete_linesTest) {
  Board board = {0};
  board.width = 10;
  board.height = 20;

  for (int i = 0; i < board.width; ++i) board.cells[19][i].is_set = true;

  for (int i = 0; i < board.width; ++i) board.cells[18][i].is_set = true;

  for (int i = 0; i < board.width; i++) board.cells[17][i].is_set = true;

  for (int i = 0; i < board.width; i += 2) board.cells[16][i].is_set = true;

  int complete_lines = handle_boardcomplete_lines(&board);
  ck_assert_int_eq(complete_lines, 3);
}
END_TEST

Suite *boardsuite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("board suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, handle_boardcomplete_linesTest);
  suite_add_tcase(s, tc_core);

  return s;
}

#endif
