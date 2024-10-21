#include "highscores.h"

void create_highscores(Highscores *highscores) {
  for (int i = 0; i < HIGHSCORES_COUNT; ++i) {
    highscores->highscores[i].is_current_player = false;
    highscores->highscores[i].score = 0;
    highscores->highscores[i].name[0] = '\0';
  }
}

void add_highscore(Highscores *highscores, const char *name, int score) {
  if (strlen(name) == 0) return;

  bool flag_handled = false;
  for (int i = 0; i < HIGHSCORES_COUNT; ++i) {
    if (strcmp(highscores->highscores[i].name, name) == 0) {
      if (score > highscores->highscores[i].score)
        highscores->highscores[i].score = score;

      flag_handled = true;
    }
  }

  int position = HIGHSCORES_COUNT;
  for (int i = HIGHSCORES_COUNT - 1; i >= 0 && !flag_handled; --i) {
    if (score > highscores->highscores[i].score) {
      position = i;
    } else {
      break;
    }
  }

  for (int i = HIGHSCORES_COUNT - 1; i > position && !flag_handled; --i)
    highscores->highscores[i] = highscores->highscores[i - 1];

  if (!flag_handled) {
    highscores->highscores[position].is_current_player = true;
    highscores->highscores[position].score = score;
    snprintf(highscores->highscores[position].name, 18, "%s", name);
  }
  sort_highscore(highscores);
  save_highscore(highscores, HIGHSCORES_FILE);
  load_highscore(highscores, HIGHSCORES_FILE);
}

void remove_highscore(Highscores *highscores, const char *name) {
  bool found = false;
  int i;

  for (i = 0; i < HIGHSCORES_COUNT; ++i) {
    if (strcmp(highscores->highscores[i].name, name) == 0) {
      found = true;
      break;
    }
  }

  if (found) {
    for (int j = i; j < HIGHSCORES_COUNT - 1; ++j)
      highscores->highscores[j] = highscores->highscores[j + 1];

    highscores->highscores[HIGHSCORES_COUNT - 1].is_current_player = false;
    highscores->highscores[HIGHSCORES_COUNT - 1].score = 0;
    highscores->highscores[HIGHSCORES_COUNT - 1].name[0] = '\0';
  }
  sort_highscore(highscores);
  save_highscore(highscores, HIGHSCORES_FILE);
  load_highscore(highscores, HIGHSCORES_FILE);
}

bool save_highscore(const Highscores *highscores, const char *filename) {
  FILE *file = fopen(filename, "wb");
  if (!file) return false;

  size_t num_written = fwrite(highscores, sizeof(Highscores), 1, file);
  fclose(file);

  return num_written == 1;
}

bool load_highscore(Highscores *highscores, const char *filename) {
  FILE *file = fopen(filename, "rb");
  if (!file) return false;

  size_t num_read = fread(highscores, sizeof(Highscores), 1, file);
  fclose(file);

  return num_read == 1;
}

void sort_highscore(Highscores *highscores) {
  bool swapped = false;

  do {
    swapped = false;
    for (int i = 0; i < HIGHSCORES_COUNT - 1; ++i) {
      if (highscores->highscores[i].score <
          highscores->highscores[i + 1].score) {
        Highscore temp_Highscore = highscores->highscores[i];
        highscores->highscores[i] = highscores->highscores[i + 1];
        highscores->highscores[i + 1] = temp_Highscore;
        swapped = true;
      }
    }
  } while (swapped);
}