#include "boardtest.h"

int main() {
  int errcode = 0;
  case_test(boardsuite(), &errcode);

  return 0;
}