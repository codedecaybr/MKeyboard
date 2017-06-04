#ifndef MKEYBOARD_H
#define MKEYBOARD_H

#include "Arduino.h"

class MKeyboard {
public:
  MKeyboard(int l1 = 4, int l2 = 5, int l3 = 6, int l4 = 7, int c1 = 8, int c2 = 9, int c3 = 10, int c4 = 11);
  ~MKeyboard();
  int read();
private:
  int l[4], c[4];
};

#endif
