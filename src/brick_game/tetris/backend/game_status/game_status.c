#include "game_status.h"

void create_game_status(Game_status* game_status) {
  game_status->level = 0;
  game_status->score = 0;
}

void add_score_game_status(Game_status* game_status, int complete_lines_count) {
  if (complete_lines_count <= 0) return;

  if (complete_lines_count > MAX_AVAILABLE_COMPLETE_LINES_COUNT)
    complete_lines_count = MAX_AVAILABLE_COMPLETE_LINES_COUNT;

  int earned_score = complete_lines_array[complete_lines_count - 1];
  game_status->score += earned_score;
}

void update_game_status(Game_status* game_status) {
  int current_level = (game_status->score / scorePER_LEVEL);

  if (current_level > MAX_LEVEL) current_level = MAX_LEVEL;

  game_status->level = current_level;
}