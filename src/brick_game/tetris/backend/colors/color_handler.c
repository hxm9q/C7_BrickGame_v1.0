#include "color_handler.h"

void create_game_colors() {
  init_color(CUSTOM_colorPINK, 980, 600, 790);
  init_color(CUSTOM_colorORANGE, 1000, 392, 0);
  init_color(CUSTOM_colorBROWN, 592, 337, 290);
  init_color(CUSTOM_colorSILVER, 752, 752, 752);
  init_color(CUSTOM_colorYELLOW, 1000, 843, 0);
  init_color(CUSTOM_colorPURPLE, 500, 0, 500);
  init_color(CUSTOM_colorRED, 1000, 0, 0);
  init_color(CUSTOM_colorGREEN, 0, 500, 0);
  init_color(CUSTOM_colorBLUE, 25, 25, 830);
  init_color(CUSTOM_colorPREDICT, 150, 150, 150);
  init_color(CUSTOM_colorGRAY, 500, 500, 500);

  init_pair(RED_COLOR_PAIR_INDEX, CUSTOM_colorRED, CUSTOM_colorRED);
  init_pair(ORANGE_COLOR_PAIR_INDEX, CUSTOM_colorORANGE, CUSTOM_colorORANGE);
  init_pair(YELLOW_COLOR_PAIR_INDEX, CUSTOM_colorYELLOW, CUSTOM_colorYELLOW);
  init_pair(PINK_COLOR_PAIR_INDEX, CUSTOM_colorPINK, CUSTOM_colorPINK);
  init_pair(GREEN_COLOR_PAIR_INDEX, CUSTOM_colorGREEN, CUSTOM_colorGREEN);
  init_pair(BLUE_COLOR_PAIR_INDEX, CUSTOM_colorBLUE, CUSTOM_colorBLUE);
  init_pair(PURPLE_COLOR_PAIR_INDEX, CUSTOM_colorPURPLE, CUSTOM_colorPURPLE);
  init_pair(PREDICT_COLOR_PAIR_INDEX, CUSTOM_colorPREDICT, CUSTOM_colorPREDICT);

  init_pair(Highscore_1_COLOR_PAIR_INDEX, CUSTOM_colorYELLOW, colorBLACK);
  init_pair(Highscore_2_COLOR_PAIR_INDEX, CUSTOM_colorSILVER, colorBLACK);
  init_pair(Highscore_3_COLOR_PAIR_INDEX, CUSTOM_colorBROWN, colorBLACK);
  init_pair(Highscore_4_5_COLOR_PAIR_INDEX, CUSTOM_colorGRAY, colorBLACK);

  init_pair(INIT_COLOR_PAIR, colorBLACK, colorBLACK);
}
