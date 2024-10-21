#ifndef DEFINES_H
#define DEFINES_H

#include <string.h>

#define WIN_INIT(time)    \
  {                       \
    initscr();            \
    noecho();             \
    curs_set(0);          \
    keypad(stdscr, TRUE); \
    timeout(time);        \
  }

#define GET_USER_INPUT getch()

#define MVPRINTW(y, x, ...) \
  mvprintw(BOARDS_BEGIN + (y), BOARDS_BEGIN + (x), __VA_ARGS__)
#define MVADDCH(y, x, c) mvaddch(BOARDS_BEGIN + (y), BOARDS_BEGIN + (x), c)

#define BOARDS_BEGIN (2)

#define boardHEIGHT (20)
#define boardWIDTH (10)
#define HUD_WIDTH (12)

#define DELETE (127)
#define ESCAPE (27)
#define ENTER_KEY (10)
#define PAUSE_KEY ('p')

#endif