#ifndef C7_BRICK_GAME_V_1_0_1_TESTS_playerTEST_H_
#define C7_BRICK_GAME_V_1_0_1_TESTS_playerTEST_H_

#ifndef TEST_HEADER_
#define TEST_HEADER_
#include "../src/brick_game/tetris/backend/backend.h"
#include "test.h"
#endif

START_TEST(create_playerTest) {
  Player player = {0};
  create_player(&player);
  ck_assert_int_eq(player.x_, 0);
  ck_assert_int_eq(player.y_, 0);
  ck_assert_int_ge(player.block_type, 0);
  ck_assert_int_ge(player.block_rotation, 0);
}
END_TEST

START_TEST(create_next_playerTest) {
  Player player = {0};
  create_next_player(&player);
  ck_assert_int_eq(player.x_, NEXT_PLAYER_POS_X);
  ck_assert_int_eq(player.y_, NEXT_PLAYER_POS_Y);
  ck_assert_int_ge(player.block_type, 0);
  ck_assert_int_ge(player.block_rotation, 0);
}
END_TEST

START_TEST(create_player_positionTest) {
  Player player = {0};
  create_player_position(&player);
  ck_assert_int_eq(player.x_, PLAYER_POS_X);
  ck_assert_int_eq(player.y_, PLAYER_POS_Y);
  ck_assert_int_ge(player.block_type, 0);
  ck_assert_int_ge(player.block_rotation, 0);
}
END_TEST

START_TEST(copy_playerTest) {
  Player player = {0};
  create_next_player(&player);
  Player player2 = {0};
  copy_player(&player2, player);

  ck_assert_int_eq(player2.x_, player.x_);
  ck_assert_int_eq(player2.y_, player.y_);
  ck_assert_int_eq(player2.block_type, player.block_type);
  ck_assert_int_eq(player2.block_rotation, player.block_rotation);
  for (int i = 0; i < playerBOARD_SIZE; ++i) {
    for (int j = 0; j < playerBOARD_SIZE; ++j) {
      ck_assert_int_eq(player.board.board[i][j].color,
                       player.board.board[i][j].color);
      ck_assert_int_eq(player.board.board[i][j].is_set,
                       player.board.board[i][j].is_set);
    }
  }
}
END_TEST

START_TEST(set_player_block_rotationTest) {
  Player player = {0};
  create_player(&player);
  set_player_block_rotation(&player, Block_rotation2);
  ck_assert_int_eq(player.block_rotation, Block_rotation2);
}
END_TEST

START_TEST(set_player_next_block_rotationTest) {
  Player player = {0};
  create_player(&player);
  set_player_block_rotation(&player, Block_rotation0);
  set_player_next_block_rotation(&player);
  ck_assert_int_eq(player.block_rotation, Block_rotation1);
  set_player_next_block_rotation(&player);
  ck_assert_int_eq(player.block_rotation, Block_rotation2);
  set_player_next_block_rotation(&player);
  ck_assert_int_eq(player.block_rotation, Block_rotation3);
  set_player_next_block_rotation(&player);
  ck_assert_int_eq(player.block_rotation, Block_rotation0);
}
END_TEST

START_TEST(set_player_prev_block_rotationTest) {
  Player player = {0};
  create_player(&player);
  set_player_block_rotation(&player, Block_rotation0);
  set_player_prev_block_rotation(&player);
  ck_assert_int_eq(player.block_rotation, Block_rotation3);
  set_player_prev_block_rotation(&player);
  ck_assert_int_eq(player.block_rotation, Block_rotation2);
  set_player_prev_block_rotation(&player);
  ck_assert_int_eq(player.block_rotation, Block_rotation1);
  set_player_prev_block_rotation(&player);
  ck_assert_int_eq(player.block_rotation, Block_rotation0);
  set_player_prev_block_rotation(&player);
  ck_assert_int_eq(player.block_rotation, Block_rotation3);
}
END_TEST

START_TEST(move_player_rightTest1) {
  Player player = {0};
  Player playerbefore = {0};
  create_player(&player);
  create_player(&playerbefore);
  create_player_position(&player);
  create_player_position(&playerbefore);

  move_player_right(&player);

  ck_assert_int_eq(player.x_, playerbefore.x_ + 1);
  ck_assert_int_eq(player.y_, playerbefore.y_);
}
END_TEST

START_TEST(move_player_rightTest2) {
  Player player = {0};
  Player playerbefore = {0};
  create_player(&player);
  create_player_position(&player);
  copy_player(&playerbefore, player);

  move_player_right(&player);
  move_player_right(&player);
  move_player_right(&player);
  ck_assert_int_eq(player.x_, playerbefore.x_ + 3);
  ck_assert_int_eq(player.y_, playerbefore.y_);
}
END_TEST

START_TEST(move_player_leftRightTest) {
  Player player = {0};
  Player playerbefore = {0};
  create_player(&player);
  create_player_position(&player);

  copy_player(&playerbefore, player);

  move_player_right(&player);
  move_player_left(&player);

  ck_assert_int_eq(playerbefore.x_, player.x_);
  ck_assert_int_eq(playerbefore.y_, player.y_);
  ck_assert_int_eq(playerbefore.block_type, player.block_type);
  ck_assert_int_eq(playerbefore.block_rotation, player.block_rotation);
  for (int i = 0; i < playerBOARD_SIZE; ++i) {
    for (int j = 0; j < playerBOARD_SIZE; ++j) {
      ck_assert_int_eq(player.board.board[i][j].color,
                       playerbefore.board.board[i][j].color);
      ck_assert_int_eq(player.board.board[i][j].is_set,
                       playerbefore.board.board[i][j].is_set);
    }
  }
}
END_TEST

START_TEST(move_player_upTest) {
  Player player = {0};
  Player playerbefore = {0};
  create_player(&player);
  create_player(&playerbefore);
  copy_player(&playerbefore, player);

  move_player_up(&player);

  ck_assert_int_eq(playerbefore.x_, player.x_);
  ck_assert_int_eq(playerbefore.y_, player.y_ + 1);
  ck_assert_int_eq(playerbefore.block_type, player.block_type);
  ck_assert_int_eq(playerbefore.block_rotation, player.block_rotation);
}
END_TEST

START_TEST(move_player_upDownTest) {
  Player player = {0};
  Player playerbefore = {0};
  create_player(&player);
  create_player_position(&player);
  copy_player(&playerbefore, player);

  move_player_up(&player);
  move_player_down(&player);

  ck_assert_int_eq(playerbefore.x_, player.x_);
  ck_assert_int_eq(playerbefore.y_, player.y_);
  ck_assert_int_eq(playerbefore.block_type, player.block_type);
  ck_assert_int_eq(playerbefore.block_rotation, player.block_rotation);

  for (int i = 0; i < playerBOARD_SIZE; ++i) {
    for (int j = 0; j < playerBOARD_SIZE; ++j) {
      ck_assert_int_eq(player.board.board[i][j].color,
                       playerbefore.board.board[i][j].color);
      ck_assert_int_eq(player.board.board[i][j].is_set,
                       playerbefore.board.board[i][j].is_set);
    }
  }
}
END_TEST

Suite *playersuite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("player suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, create_playerTest);
  tcase_add_test(tc_core, create_next_playerTest);
  tcase_add_test(tc_core, create_player_positionTest);
  tcase_add_test(tc_core, copy_playerTest);
  tcase_add_test(tc_core, set_player_block_rotationTest);
  tcase_add_test(tc_core, set_player_next_block_rotationTest);
  tcase_add_test(tc_core, set_player_prev_block_rotationTest);
  tcase_add_test(tc_core, move_player_rightTest1);
  tcase_add_test(tc_core, move_player_rightTest2);
  tcase_add_test(tc_core, move_player_leftRightTest);
  tcase_add_test(tc_core, move_player_upTest);
  tcase_add_test(tc_core, move_player_upDownTest);
  suite_add_tcase(s, tc_core);

  return s;
}

#endif
