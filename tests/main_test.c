#include "main_test.h"

int main() {
  int errcode = 0;
  case_test(block_suite(), &errcode);
  case_test(playerboardsuite(), &errcode);
  case_test(boardsuite(), &errcode);
  case_test(highscoressuite(), &errcode);
  case_test(playersuite(), &errcode);
  case_test(game_status_suite(), &errcode);
  case_test(collisions_checker_suite(), &errcode);
  case_test(colorhandlersuite(), &errcode);
  case_test(backendsuite(), &errcode);

  return errcode;
}