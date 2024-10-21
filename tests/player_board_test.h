#ifndef C7_BRICK_GAME_V_1_0_1_TESTS_playerboardTEST_H_
#define C7_BRICK_GAME_V_1_0_1_TESTS_playerboardTEST_H_

#ifndef TEST_HEADER_
#define TEST_HEADER_
#include "../src/brick_game/tetris/backend/backend.h"
#include "test.h"
#endif

START_TEST(set_playerboard_blockTestIFirstRotation) {
  playerboard playerboard = {0};
  set_playerboard_block(&playerboard, Block0, Block_rotation0);

  for (int i = 0; i < playerBOARD_SIZE; ++i) {
    for (int j = 0; j < playerBOARD_SIZE; ++j) {
      if (j == 1) {
        ck_assert_int_eq(playerboard.board[i][j].is_set, true);
      } else {
        ck_assert_int_eq(playerboard.board[i][j].is_set, false);
      }
    }
  }
}
END_TEST

START_TEST(set_playerboard_blockTestISecondRotation) {
  playerboard playerboard = {0};
  set_playerboard_block(&playerboard, Block0, Block_rotation1);

  for (int i = 0; i < playerBOARD_SIZE; ++i) {
    for (int j = 0; j < playerBOARD_SIZE; ++j) {
      if (i == 2) {
        ck_assert_int_eq(playerboard.board[i][j].is_set, true);
      } else {
        ck_assert_int_eq(playerboard.board[i][j].is_set, false);
      }
    }
  }
}
END_TEST

START_TEST(set_playerboard_blockTestIThirdRotation) {
  playerboard playerboard = {0};
  set_playerboard_block(&playerboard, Block0, Block_rotation2);

  for (int i = 0; i < playerBOARD_SIZE; ++i) {
    for (int j = 0; j < playerBOARD_SIZE; ++j) {
      if (j == 1) {
        ck_assert_int_eq(playerboard.board[i][j].is_set, true);
      } else {
        ck_assert_int_eq(playerboard.board[i][j].is_set, false);
      }
    }
  }
}
END_TEST

START_TEST(set_playerboard_blockTestIForthRotation) {
  playerboard playerboard = {0};
  set_playerboard_block(&playerboard, Block0, Block_rotation3);

  for (int i = 0; i < playerBOARD_SIZE; ++i) {
    for (int j = 0; j < playerBOARD_SIZE; ++j) {
      if (i == 2) {
        ck_assert_int_eq(playerboard.board[i][j].is_set, true);
      } else {
        ck_assert_int_eq(playerboard.board[i][j].is_set, false);
      }
    }
  }
}
END_TEST

START_TEST(create_playerboardTest) {
  playerboard playerboard = {0};
  create_playerboard(&playerboard);

  for (int i = 0; i < playerBOARD_SIZE; ++i) {
    for (int j = 0; j < playerBOARD_SIZE; ++j) {
      ck_assert_int_eq(playerboard.board[i][j].color, colorBLACK);
      ck_assert_int_eq(playerboard.board[i][j].is_set, false);
    }
  }
}
END_TEST

START_TEST(copy_playerboardTest) {
  playerboard playerboard1 = {0};
  playerboard playerboard2 = {0};
  create_playerboard(&playerboard1);
  create_playerboard(&playerboard2);

  for (int i = 0; i < playerBOARD_SIZE; i += 2) {
    for (int j = 0; j < playerBOARD_SIZE; j += 2) {
      playerboard1.board[i][j].is_set = true;
    }
  }
  copy_playerboard(&playerboard2, playerboard1);

  for (int i = 0; i < playerBOARD_SIZE; ++i) {
    for (int j = 0; j < playerBOARD_SIZE; ++j) {
      ck_assert_int_eq(playerboard1.board[i][j].is_set,
                       playerboard2.board[i][j].is_set);
      ck_assert_int_eq(playerboard1.board[i][j].color,
                       playerboard2.board[i][j].color);
    }
  }
}
END_TEST

Suite *playerboardsuite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("player board suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, set_playerboard_blockTestIFirstRotation);
  tcase_add_test(tc_core, set_playerboard_blockTestISecondRotation);
  tcase_add_test(tc_core, set_playerboard_blockTestIThirdRotation);
  tcase_add_test(tc_core, set_playerboard_blockTestIForthRotation);
  tcase_add_test(tc_core, create_playerboardTest);
  tcase_add_test(tc_core, copy_playerboardTest);
  suite_add_tcase(s, tc_core);

  return s;
}

#endif
