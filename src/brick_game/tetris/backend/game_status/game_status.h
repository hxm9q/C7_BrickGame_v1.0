#ifndef GAME_STATUS_H
#define GAME_STATUS_H

#define MAX_LEVEL (10)
#define MAX_AVAILABLE_COMPLETE_LINES_COUNT (4)
#define scorePER_LEVEL (600)

static const int complete_lines_array[4] = {100, 300, 700, 1500};

typedef struct {
  int score;
  int level;
} Game_status;

void create_game_status(Game_status *game_status);
void add_score_game_status(Game_status *game_status, int complete_lines_count);
void update_game_status(Game_status *game_status);

#endif
