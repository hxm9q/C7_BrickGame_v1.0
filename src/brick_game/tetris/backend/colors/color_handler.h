#ifndef COLOR_HANDLER_H
#define COLOR_HANDLER_H

#include <ncurses.h>

#include "colors.h"

#define BASE_COLOR_PAIR_INDEX (100)
#define RED_COLOR_PAIR_INDEX (BASE_COLOR_PAIR_INDEX + 0)
#define ORANGE_COLOR_PAIR_INDEX (BASE_COLOR_PAIR_INDEX + 1)
#define YELLOW_COLOR_PAIR_INDEX (BASE_COLOR_PAIR_INDEX + 2)
#define PINK_COLOR_PAIR_INDEX (BASE_COLOR_PAIR_INDEX + 3)
#define GREEN_COLOR_PAIR_INDEX (BASE_COLOR_PAIR_INDEX + 4)
#define BLUE_COLOR_PAIR_INDEX (BASE_COLOR_PAIR_INDEX + 5)
#define PURPLE_COLOR_PAIR_INDEX (BASE_COLOR_PAIR_INDEX + 6)

#define Highscore_1_COLOR_PAIR_INDEX (BASE_COLOR_PAIR_INDEX + 7)
#define Highscore_2_COLOR_PAIR_INDEX (BASE_COLOR_PAIR_INDEX + 8)
#define Highscore_3_COLOR_PAIR_INDEX (BASE_COLOR_PAIR_INDEX + 9)
#define Highscore_4_5_COLOR_PAIR_INDEX (BASE_COLOR_PAIR_INDEX + 10)

#define CUSTOM_colorORANGE (BASE_COLOR_PAIR_INDEX + 11)
#define CUSTOM_colorPINK (BASE_COLOR_PAIR_INDEX + 12)
#define CUSTOM_colorPURPLE (BASE_COLOR_PAIR_INDEX + 13)
#define CUSTOM_colorBROWN (BASE_COLOR_PAIR_INDEX + 14)
#define CUSTOM_colorSILVER (BASE_COLOR_PAIR_INDEX + 15)
#define CUSTOM_colorYELLOW (BASE_COLOR_PAIR_INDEX + 16)
#define CUSTOM_colorRED (BASE_COLOR_PAIR_INDEX + 17)
#define CUSTOM_colorGREEN (BASE_COLOR_PAIR_INDEX + 18)
#define CUSTOM_colorBLUE (BASE_COLOR_PAIR_INDEX + 19)
#define CUSTOM_colorPREDICT (BASE_COLOR_PAIR_INDEX + 20)
#define CUSTOM_colorGRAY (BASE_COLOR_PAIR_INDEX + 21)

#define INIT_COLOR_PAIR (BASE_COLOR_PAIR_INDEX + 22)
#define PREDICT_COLOR_PAIR_INDEX (BASE_COLOR_PAIR_INDEX + 23)

static const int array_block_color_pairs[] = {
    RED_COLOR_PAIR_INDEX,    ORANGE_COLOR_PAIR_INDEX,  YELLOW_COLOR_PAIR_INDEX,
    PINK_COLOR_PAIR_INDEX,   GREEN_COLOR_PAIR_INDEX,   BLUE_COLOR_PAIR_INDEX,
    PURPLE_COLOR_PAIR_INDEX, PREDICT_COLOR_PAIR_INDEX,
};

void create_game_colors();

#endif
