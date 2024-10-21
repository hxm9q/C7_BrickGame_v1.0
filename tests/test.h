#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/brick_game/tetris/backend/colors/color_handler.h"
#include "../src/brick_game/tetris/tetris/tetris.h"

#ifndef CASE_TEST
#define CASE_TEST

void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  enum fork_status fork_status = CK_NOFORK;
  srunner_set_fork_status(runner, fork_status);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

#endif

#endif