//
// Created by  Антон Шадрин on 03.07.2024.
//
#ifndef COLOR_HANDLER_TEST_H
#define COLOR_HANDLER_TEST_H

#ifndef TEST_HEADER_
#define TEST_HEADER_
#include "../src/brick_game/tetris/backend/color_handler.h"
#include "test.h"
#endif

START_TEST(create_game_colorsTest) {
  initscr();
  start_color();

  create_game_colors();

  short r, g, b;
  color_content(CUSTOM_colorPINK, &r, &g, &b);
  ck_assert_int_eq(r, 980);
  ck_assert_int_eq(g, 600);
  ck_assert_int_eq(b, 790);

  color_content(CUSTOM_colorORANGE, &r, &g, &b);
  ck_assert_int_eq(r, 1000);
  ck_assert_int_eq(g, 392);
  ck_assert_int_eq(b, 0);

  short fg, bg;
  pair_content(RED_COLOR_PAIR_INDEX, &fg, &bg);
  ck_assert_int_eq(fg, CUSTOM_colorRED);
  ck_assert_int_eq(bg, CUSTOM_colorRED);

  pair_content(ORANGE_COLOR_PAIR_INDEX, &fg, &bg);
  ck_assert_int_eq(fg, CUSTOM_colorORANGE);
  ck_assert_int_eq(bg, CUSTOM_colorORANGE);

  endwin();
}
END_TEST

Suite *colorhandlersuite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("color handler suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, create_game_colorsTest);
  suite_add_tcase(s, tc_core);

  return s;
}

#endif
