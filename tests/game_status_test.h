#ifndef GAME_STATUS_TEST_H
#define GAME_STATUS_TEST_H

#ifndef TEST_HEADER
#define TEST_HEADER
#include "../src/brick_game/tetris/backend/backend.h"
#include "test.h"
#endif

START_TEST(create_game_statusTest) {
  Game_status game_status = {0};
  create_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 0);
  ck_assert_int_eq(game_status.level, 0);
}
END_TEST

START_TEST(add_score_game_statusTest1) {
  Game_status game_status = {0};
  create_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 0);
  ck_assert_int_eq(game_status.level, 0);

  add_score_game_status(&game_status, 1);
  ck_assert_int_eq(game_status.score, 100);
  add_score_game_status(&game_status, 1);
  ck_assert_int_eq(game_status.score, 200);
  add_score_game_status(&game_status, 1);
  ck_assert_int_eq(game_status.score, 300);
  add_score_game_status(&game_status, 1);
  ck_assert_int_eq(game_status.score, 400);
  add_score_game_status(&game_status, 1);
  ck_assert_int_eq(game_status.score, 500);
}
END_TEST

START_TEST(add_score_game_statusTest2) {
  Game_status game_status = {0};
  create_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 0);
  ck_assert_int_eq(game_status.level, 0);

  add_score_game_status(&game_status, 1);
  ck_assert_int_eq(game_status.score, 100);
  add_score_game_status(&game_status, 2);
  ck_assert_int_eq(game_status.score, 400);
  add_score_game_status(&game_status, 1);
  ck_assert_int_eq(game_status.score, 500);
  add_score_game_status(&game_status, 2);
  ck_assert_int_eq(game_status.score, 800);
  add_score_game_status(&game_status, 1);
  ck_assert_int_eq(game_status.score, 900);
}
END_TEST

START_TEST(add_score_game_statusTest3) {
  Game_status game_status = {0};
  create_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 0);
  ck_assert_int_eq(game_status.level, 0);

  add_score_game_status(&game_status, 1);
  ck_assert_int_eq(game_status.score, 100);
  add_score_game_status(&game_status, 2);
  ck_assert_int_eq(game_status.score, 400);
  add_score_game_status(&game_status, 3);
  ck_assert_int_eq(game_status.score, 1100);
  add_score_game_status(&game_status, 4);
  ck_assert_int_eq(game_status.score, 2600);
  add_score_game_status(&game_status, 5);
  ck_assert_int_eq(game_status.score, 4100);
}
END_TEST

START_TEST(add_score_game_statusupdate_game_statusTest1) {
  Game_status game_status = {0};
  create_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 0);
  ck_assert_int_eq(game_status.level, 0);

  add_score_game_status(&game_status, 1);
  update_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 100);
  ck_assert_int_eq(game_status.level, 0);
  add_score_game_status(&game_status, 2);
  update_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 400);
  ck_assert_int_eq(game_status.level, 0);
  add_score_game_status(&game_status, 1);
  update_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 500);
  ck_assert_int_eq(game_status.level, 0);
  add_score_game_status(&game_status, 2);
  update_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 800);
  ck_assert_int_eq(game_status.level, 1);
  add_score_game_status(&game_status, 1);
  update_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 900);
  ck_assert_int_eq(game_status.level, 1);
}
END_TEST

START_TEST(add_score_game_statusupdate_game_statusTest2) {
  Game_status game_status = {0};
  create_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 0);
  ck_assert_int_eq(game_status.level, 0);

  add_score_game_status(&game_status, 1);
  update_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 100);
  ck_assert_int_eq(game_status.level, 0);
  add_score_game_status(&game_status, 2);
  update_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 400);
  ck_assert_int_eq(game_status.level, 0);
  add_score_game_status(&game_status, 3);
  update_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 1100);
  ck_assert_int_eq(game_status.level, 1);
  add_score_game_status(&game_status, 4);
  update_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 2600);
  ck_assert_int_eq(game_status.level, 4);
  add_score_game_status(&game_status, 5);
  update_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 4100);
  ck_assert_int_eq(game_status.level, 6);
}
END_TEST

START_TEST(add_score_game_statusNoChangesTest) {
  Game_status game_status = {0};
  create_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 0);
  ck_assert_int_eq(game_status.level, 0);

  add_score_game_status(&game_status, 0);
  ck_assert_int_eq(game_status.score, 0);
  ck_assert_int_eq(game_status.level, 0);
  add_score_game_status(&game_status, 0);
  ck_assert_int_eq(game_status.score, 0);
  ck_assert_int_eq(game_status.level, 0);
  add_score_game_status(&game_status, 0);
  ck_assert_int_eq(game_status.score, 0);
  ck_assert_int_eq(game_status.level, 0);
  add_score_game_status(&game_status, 0);
  ck_assert_int_eq(game_status.score, 0);
  ck_assert_int_eq(game_status.level, 0);
}
END_TEST

START_TEST(add_score_game_statusInvalidArgumentTest) {
  Game_status game_status = {0};
  create_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 0);
  ck_assert_int_eq(game_status.level, 0);

  add_score_game_status(&game_status, -1);
  ck_assert_int_eq(game_status.score, 0);
  ck_assert_int_eq(game_status.level, 0);
  add_score_game_status(&game_status, -100);
  ck_assert_int_eq(game_status.score, 0);
  ck_assert_int_eq(game_status.level, 0);
}
END_TEST

START_TEST(add_score_game_statusupdate_game_statusMaxLevelExceedTest) {
  Game_status game_status = {0};
  create_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 0);
  ck_assert_int_eq(game_status.level, 0);

  add_score_game_status(&game_status, 4);
  update_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 1500);
  ck_assert_int_eq(game_status.level, 2);

  add_score_game_status(&game_status, 4);
  update_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 3000);
  ck_assert_int_eq(game_status.level, 5);

  add_score_game_status(&game_status, 4);
  update_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 4500);
  ck_assert_int_eq(game_status.level, 7);

  add_score_game_status(&game_status, 4);
  update_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 6000);
  ck_assert_int_eq(game_status.level, 10);

  add_score_game_status(&game_status, 4);
  update_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 7500);
  ck_assert_int_eq(game_status.level, 10);

  add_score_game_status(&game_status, 4);
  update_game_status(&game_status);
  ck_assert_int_eq(game_status.score, 9000);
  ck_assert_int_eq(game_status.level, 10);
}
END_TEST

Suite *game_status_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("game status suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, create_game_statusTest);
  tcase_add_test(tc_core, add_score_game_statusTest1);
  tcase_add_test(tc_core, add_score_game_statusTest2);
  tcase_add_test(tc_core, add_score_game_statusTest3);
  tcase_add_test(tc_core, add_score_game_statusupdate_game_statusTest1);
  tcase_add_test(tc_core, add_score_game_statusupdate_game_statusTest2);
  tcase_add_test(tc_core, add_score_game_statusNoChangesTest);
  tcase_add_test(tc_core, add_score_game_statusInvalidArgumentTest);
  tcase_add_test(tc_core,
                 add_score_game_statusupdate_game_statusMaxLevelExceedTest);
  suite_add_tcase(s, tc_core);

  return s;
}

#endif