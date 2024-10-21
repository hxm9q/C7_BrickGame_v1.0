//
// Created by  Антон Шадрин on 03.07.2024.
//
#include "backend_test.h"

int main() {
  int errcode = 0;
  case_test(backendsuite(), &errcode);

  return 0;
}