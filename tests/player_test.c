#include "player_test.h"

int main() {
  int errcode = 0;
  case_test(playersuite(), &errcode);

  return 0;
}