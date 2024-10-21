#include "block.h"

Block_type get_random_block_type() {
  Block_type block_type = rand() % (Block6 + 1);

  return block_type;
}

Block_rotation get_next_block_rotation(Block_rotation block_rotation) {
  Block_rotation next_block_rotation = Block_rotation0;
  switch (block_rotation) {
    case Block_rotation0:
      next_block_rotation = Block_rotation1;
      break;
    case Block_rotation1:
      next_block_rotation = Block_rotation2;
      break;
    case Block_rotation2:
      next_block_rotation = Block_rotation3;
      break;
    case Block_rotation3:
      next_block_rotation = Block_rotation0;
      break;
    default:
      break;
  }

  return next_block_rotation;
}

Block_rotation get_prev_block_rotation(Block_rotation block_rotation) {
  Block_rotation previous_block_rotation = Block_rotation0;
  switch (block_rotation) {
    case Block_rotation0:
      previous_block_rotation = Block_rotation3;
      break;
    case Block_rotation1:
      previous_block_rotation = Block_rotation0;
      break;
    case Block_rotation2:
      previous_block_rotation = Block_rotation1;
      break;
    case Block_rotation3:
      previous_block_rotation = Block_rotation2;
      break;
    default:
      break;
  }

  return previous_block_rotation;
}

Block_colortype get_block_color(Block_type block_type) {
  Block_colortype block_colortype = {0};
  block_colortype = kBlockColors[block_type];

  return block_colortype;
}