#ifndef HIGHSCORES_TEST_H
#define HIGHSCORES_TEST_H

#ifndef TEST_HEADER_
#define TEST_HEADER_
#include "../src/brick_game/tetris/backend/backend.h"
#include "test.h"
#endif

START_TEST(HighscoresAddSaveLoadTest1) {
  Highscores highscores = {0};
  Highscores highscores2 = {0};
  create_highscores(&highscores);
  create_highscores(&highscores2);

  add_highscore(&highscores, "Anton1", 500);
  add_highscore(&highscores, "Anton2", 600);
  add_highscore(&highscores, "Anton3", 700);
  add_highscore(&highscores, "Anton4", 800);
  add_highscore(&highscores, "Anton5", 900);
  add_highscore(&highscores, "Anton6", 1000);

  save_highscore(&highscores, HIGHSCORES_FILE);
  load_highscore(&highscores2, HIGHSCORES_FILE);
  for (int i = 0; i < HIGHSCORES_COUNT; ++i) {
    ck_assert_int_eq(highscores.highscores[i].is_current_player,
                     highscores2.highscores[i].is_current_player);
    ck_assert_int_eq(highscores.highscores[i].score,
                     highscores2.highscores[i].score);
    ck_assert_str_eq(highscores.highscores[i].name,
                     highscores2.highscores[i].name);
  }
}
END_TEST

START_TEST(HighscoresAddSaveLoadTest2) {
  Highscores highscores = {0};
  Highscores highscores2 = {0};
  create_highscores(&highscores);
  create_highscores(&highscores2);

  add_highscore(&highscores, "Anton", 500);
  add_highscore(&highscores, "Anton", 600);

  save_highscore(&highscores, HIGHSCORES_FILE);
  load_highscore(&highscores2, HIGHSCORES_FILE);
  for (int i = 0; i < HIGHSCORES_COUNT; ++i) {
    ck_assert_int_eq(highscores.highscores[i].is_current_player,
                     highscores2.highscores[i].is_current_player);
    ck_assert_int_eq(highscores.highscores[i].score,
                     highscores2.highscores[i].score);
    ck_assert_str_eq(highscores.highscores[i].name,
                     highscores2.highscores[i].name);
  }
}
END_TEST

START_TEST(HighscoresAddSaveLoadTest3) {
  Highscores highscores = {0};
  Highscores Highscores2 = {0};
  create_highscores(&highscores);
  create_highscores(&Highscores2);

  add_highscore(&highscores, "Anton", 500);
  add_highscore(&highscores, "Anton", 600);
  add_highscore(&highscores, "Anton", 500);
  add_highscore(&highscores, "Anton", 600);
  remove_highscore(&highscores, "Anton");

  for (int i = 0; i < HIGHSCORES_COUNT; ++i) {
    ck_assert_int_eq(highscores.highscores[i].score, 0);
    ck_assert_int_eq(highscores.highscores[i].is_current_player, false);
    ck_assert_str_eq(highscores.highscores[i].name, "");
  }
}
END_TEST

START_TEST(HighscoresAddSaveLoadTest4) {
  Highscores highscores = {0};
  Highscores Highscores2 = {0};
  create_highscores(&highscores);
  create_highscores(&Highscores2);

  add_highscore(&highscores, "Anton8", 1200);
  add_highscore(&highscores, "Anton7", 1100);
  add_highscore(&highscores, "Anton6", 1000);
  add_highscore(&highscores, "Anton5", 900);
  add_highscore(&highscores, "Anton4", 800);
  add_highscore(&highscores, "Anton3", 700);
  add_highscore(&highscores, "Anton2", 600);
  add_highscore(&highscores, "Anton1", 500);

  ck_assert_int_eq(highscores.highscores[0].score, 1200);
  ck_assert_str_eq(highscores.highscores[0].name, "Anton8");
}
END_TEST

Suite *highscoressuite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("Highscores suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, HighscoresAddSaveLoadTest1);
  tcase_add_test(tc_core, HighscoresAddSaveLoadTest2);
  tcase_add_test(tc_core, HighscoresAddSaveLoadTest3);
  tcase_add_test(tc_core, HighscoresAddSaveLoadTest4);
  suite_add_tcase(s, tc_core);

  return s;
}

#endif