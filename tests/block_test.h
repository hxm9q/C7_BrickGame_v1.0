#ifndef BLOCK_TEST_H
#define BLOCK_TEST_H
#ifndef TEST_HEADER
#define TEST_HEADER

#include "test.h"

#endif

START_TEST(get_random_block_typeTest) {
  Block_type block_type = {0};
  block_type = get_random_block_type();
  ck_assert_int_ge(block_type, 0);
}
END_TEST

START_TEST(get_next_block_rotationTest) {
  Block_rotation block_rotation = Block_rotation0;
  block_rotation = get_next_block_rotation(block_rotation);
  ck_assert_int_eq(block_rotation, Block_rotation1);
  block_rotation = get_next_block_rotation(block_rotation);
  ck_assert_int_eq(block_rotation, Block_rotation2);
  block_rotation = get_next_block_rotation(block_rotation);
  ck_assert_int_eq(block_rotation, Block_rotation3);
}
END_TEST

START_TEST(get_prev_block_rotationTest) {
  Block_rotation block_rotation = Block_rotation0;
  block_rotation = get_prev_block_rotation(block_rotation);
  ck_assert_int_eq(block_rotation, Block_rotation3);
  block_rotation = get_prev_block_rotation(block_rotation);
  ck_assert_int_eq(block_rotation, Block_rotation2);
  block_rotation = get_prev_block_rotation(block_rotation);
  ck_assert_int_eq(block_rotation, Block_rotation1);
  block_rotation = get_prev_block_rotation(block_rotation);
  ck_assert_int_eq(block_rotation, Block_rotation0);
}
END_TEST

Suite *block_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("block suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, get_random_block_typeTest);
  tcase_add_test(tc_core, get_next_block_rotationTest);
  tcase_add_test(tc_core, get_prev_block_rotationTest);
  suite_add_tcase(s, tc_core);

  return s;
}

#endif