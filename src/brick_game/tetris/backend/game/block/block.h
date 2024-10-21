#ifndef BLOCK_H
#define BLOCK_H

#include <stdlib.h>

#include "../../colors/colors.h"

static const int blocks_bitmask[][4] = {
    {0b0100010001000100, 0b0000000011110000, 0b0100010001000100,
     0b0000000011110000},  // I
    {0b0000001000100110, 0b0000010001110000, 0b0000001100100010,
     0b0000000001110001},  // J
    {0b0000001000100011, 0b0000000001110100, 0b0000011000100010,
     0b0000000101110000},  // L
    {0b0000011001100000, 0b0000011001100000, 0b0000011001100000,
     0b0000011001100000},  // O
    {0b0000000000110110, 0b0000010001100010, 0b0000000000110110,
     0b0000010001100010},  // S
    {0b0000001001110000, 0b0000001000110010, 0b0000000001110010,
     0b0000001001100010},  // T
    {0b0000000001100011, 0b0000001001100100, 0b0000000001100011,
     0b0000001001100100},  // Z
};

typedef enum {
  Block0 = 0,
  Block1 = 1,
  Block2 = 2,
  Block3 = 3,
  Block4 = 4,
  Block5 = 5,
  Block6 = 6,
} Block_type;

typedef enum {
  Block_rotation0 = 0,
  Block_rotation1 = 1,
  Block_rotation2 = 2,
  Block_rotation3 = 3,
} Block_rotation;

Block_type get_random_block_type();
Block_rotation get_next_block_rotation(Block_rotation block_rotation);
Block_rotation get_prev_block_rotation(Block_rotation block_rotation);
Block_colortype get_block_color(Block_type block_type);

#endif