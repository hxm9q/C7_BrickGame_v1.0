#ifndef HIGHSCORES_H
#define HIGHSCORES_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define HIGHSCORES_COUNT (5)
#define HIGHSCORES_FILE "highscores.highscores"

typedef struct {
  bool is_current_player;
  char name[20];
  int score;
} Highscore;

typedef struct {
  Highscore highscores[HIGHSCORES_COUNT];
} Highscores;

void create_highscores(Highscores *highscores);

void add_highscore(Highscores *highscores, const char *name, int score);
void remove_highscore(Highscores *highscores, const char *name);

bool save_highscore(const Highscores *highscores, const char *filename);

bool load_highscore(Highscores *highscores, const char *filename);

void sort_highscore(Highscores *highscores);

#endif
