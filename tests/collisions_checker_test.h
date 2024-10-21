#ifndef COLLISIONS_CHECKER_TEST_H_
#define COLLISIONS_CHECKER_TEST_H_

#ifndef TEST_HEADER
#define TEST_HEADER
#include "../src/brick_game/tetris/backend/backend.h"
#include "test.h"
#endif

START_TEST(check_collideTest1) {
  Player player = {0};
  Board board = {0};
  create_player(&player);
  create_player_position(&player);

  create_board(&board);

  set_player_block_type(&player, Block5);
  set_player_block_rotation(&player, Block_rotation0);
  bool flag = check_collide(&player, &board);
  ck_assert_int_eq(flag, false);
}
END_TEST

START_TEST(check_future_collide_with_blocks_leftTest1) {
  Player player = {0};
  Board board = {0};
  create_player(&player);
  create_player_position(&player);

  create_board(&board);

  set_player_block_type(&player, Block5);
  set_player_block_rotation(&player, Block_rotation0);
  bool flag = check_future_collide_with_blocks_left(&player, &board);
  ck_assert_int_eq(flag, false);
}
END_TEST

START_TEST(check_future_collide_with_blocks_rightTest1) {
  Player player = {0};
  Board board = {0};
  create_player(&player);
  create_player_position(&player);

  create_board(&board);
  set_player_block_type(&player, Block5);
  set_player_block_rotation(&player, Block_rotation0);
  bool flag = check_future_collide_with_blocks_right(&player, &board);
  ck_assert_int_eq(flag, false);
}
END_TEST

START_TEST(check_future_collide_with_blocks_leftTest2) {
  Player player = {0};
  Board board = {0};
  create_player(&player);
  create_player_position(&player);

  create_board(&board);
  for (int i = 0; i < board.height; ++i) board.cells[i][0].is_set = true;

  set_player_block_type(&player, Block5);
  set_player_block_rotation(&player, Block_rotation0);

  move_player_left(&player);
  move_player_left(&player);
  move_player_left(&player);
  bool flag = check_future_collide_with_blocks_left(&player, &board);
  ck_assert_int_eq(flag, true);
}

END_TEST
START_TEST(check_future_collide_with_blocks_rightTest2) {
  Player player = {0};
  Board board = {0};
  create_player(&player);
  create_player_position(&player);

  create_board(&board);
  for (int i = 0; i < board.height; ++i) {
    board.cells[i][board.width - 1].is_set = true;
  }

  set_player_block_type(&player, Block5);
  set_player_block_rotation(&player, Block_rotation0);

  move_player_right(&player);
  move_player_right(&player);
  bool flag = check_future_collide_with_blocks_right(&player, &board);
  ck_assert_int_eq(flag, true);
}
END_TEST

START_TEST(check_future_collide_with_leftTest) {
  Player player = {0};
  Board board = {0};
  create_player(&player);
  create_player_position(&player);

  create_board(&board);

  set_player_block_type(&player, Block5);
  set_player_block_rotation(&player, Block_rotation0);
  move_player_left(&player);
  move_player_left(&player);
  move_player_left(&player);
  move_player_left(&player);

  bool flag = check_future_collide_with_left(&player, &board);
  ck_assert_int_eq(flag, true);
}
END_TEST

START_TEST(check_future_collide_with_rightTest) {
  Player player = {0};
  Board board = {0};
  create_player(&player);
  create_player_position(&player);

  create_board(&board);

  set_player_block_type(&player, Block5);
  set_player_block_rotation(&player, Block_rotation0);
  move_player_right(&player);
  move_player_right(&player);
  move_player_right(&player);

  bool flag = check_future_collide_with_right(&player, &board);
  ck_assert_int_eq(flag, true);
}
END_TEST

START_TEST(check_future_collide_with_upTest) {
  Player player = {0};
  Board board = {0};
  create_player(&player);
  create_player_position(&player);

  create_board(&board);

  set_player_block_type(&player, Block5);
  set_player_block_rotation(&player, Block_rotation0);
  move_player_right(&player);
  move_player_right(&player);
  move_player_right(&player);

  bool flag = check_future_collide_with_up(&player, &board);
  ck_assert_int_eq(flag, false);
}
END_TEST

START_TEST(check_future_collide_with_downTest) {
  Player player = {0};
  Board board = {0};
  create_player(&player);
  create_player_position(&player);

  create_board(&board);

  set_player_block_type(&player, Block5);
  set_player_block_rotation(&player, Block_rotation0);
  move_player_right(&player);
  move_player_right(&player);
  move_player_right(&player);

  bool flag = check_future_collide_with_down(&player, &board);
  ck_assert_int_eq(flag, false);
  move_player_down(&player);
  move_player_down(&player);
  move_player_down(&player);
  move_player_down(&player);
  move_player_down(&player);
  flag = check_future_collide_with_down(&player, &board);
  ck_assert_int_eq(flag, false);
  move_player_down(&player);
  move_player_down(&player);
  move_player_down(&player);
  move_player_down(&player);
  move_player_down(&player);
  flag = check_future_collide_with_down(&player, &board);
  ck_assert_int_eq(flag, false);
  move_player_down(&player);
  move_player_down(&player);
  move_player_down(&player);
  move_player_down(&player);
  move_player_down(&player);
  flag = check_future_collide_with_down(&player, &board);
  ck_assert_int_eq(flag, false);
  move_player_down(&player);
  move_player_down(&player);
  move_player_down(&player);
  flag = check_future_collide_with_down(&player, &board);
  ck_assert_int_eq(flag, true);
}
END_TEST

Suite *collisions_checker_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("collisions checker suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, check_collideTest1);
  tcase_add_test(tc_core, check_future_collide_with_blocks_leftTest1);
  tcase_add_test(tc_core, check_future_collide_with_blocks_rightTest1);
  tcase_add_test(tc_core, check_future_collide_with_blocks_leftTest2);
  tcase_add_test(tc_core, check_future_collide_with_blocks_rightTest2);
  tcase_add_test(tc_core, check_future_collide_with_leftTest);
  tcase_add_test(tc_core, check_future_collide_with_rightTest);
  tcase_add_test(tc_core, check_future_collide_with_upTest);
  tcase_add_test(tc_core, check_future_collide_with_downTest);
  suite_add_tcase(s, tc_core);

  return s;
}

#endif