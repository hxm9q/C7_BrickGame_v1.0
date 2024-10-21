#ifndef COLORS_H
#define COLORS_H

#ifndef colorBLACK
#define colorBLACK (0)
#endif

typedef enum {
  kBlockColorI = 0,
  kBlockColorJ = 1,
  kBlockColorL = 2,
  kBlockColorO = 3,
  kBlockColorS = 4,
  kBlockColorT = 5,
  kBlockColorZ = 6,
  kBlockColorPredict = 7,
} Block_colortype;

static const Block_colortype kBlockColors[] = {0, 1, 2, 3, 4, 5, 6, 7};

#endif
