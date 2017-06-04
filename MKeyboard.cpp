/*
Copyright 2017 Code Decay
Authors: Renan Yuri Lino, Douglas Navarro
Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "MKeyboard.h"
using namespace std;

MKeyboard::MKeyboard(int l1, int l2, int l3, int l4, int c1, int c2, int c3, int c4) {
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);

  pinMode(c1, INPUT);
  pinMode(c2, INPUT);
  pinMode(c3, INPUT);
  pinMode(c4, INPUT);

  l[0] = l1; l[1] = l2; l[2] = l3; l[3] = l4;
  c[0] = c1; c[1] = c2; c[2] = c3; c[3] = c4;
}

MKeyboard::~MKeyboard() {}

int MKeyboard::read() {
    int value = -1;
    int line;
    for (int i = 0; i < 4; i++) {
      line = l[i];
      digitalWrite(l[0], LOW);
      digitalWrite(l[1], LOW);
      digitalWrite(l[2], LOW);
      digitalWrite(l[3], LOW);
      digitalWrite(line, HIGH);

      //Verifica se alguma tecla da coluna 1 foi pressionada
      if (digitalRead(c[0]) == HIGH)
      {
        if (i == 0) value = 1;
        else if (i == 1) value = 4;
        else if (i == 2) value = 7;
        else if (i == 3) value = 14;
        while(digitalRead(c[0]) == HIGH){}
      }

      //Verifica se alguma tecla da coluna 2 foi pressionada
      if (digitalRead(c[1]) == HIGH)
      {
        if (i == 0) value = 2;
        else if (i == 1) value = 5;
        else if (i == 2) value = 8;
        else if (i == 3) value = 0;
        while(digitalRead(c[1]) == HIGH){};
      }

      //Verifica se alguma tecla da coluna 3 foi pressionada
      if (digitalRead(c[2]) == HIGH)
      {
        if (i == 0) value = 3;
        else if (i == 1) value = 6;
        else if (i == 2) value = 9;
        else if (i == 3) value = 15;
        while(digitalRead(c[2]) == HIGH){}
      }

      //Verifica se alguma tecla da coluna 4 foi pressionada
      if (digitalRead(c[3]) == HIGH)
      {
        if (i == 0) value = 10;
        else if (i == 1) value = 11;
        else if (i == 2) value = 12;
        else if (i == 3) value = 13;
        while(digitalRead(c[3]) == HIGH){}
      }
   }
   return value;
}
