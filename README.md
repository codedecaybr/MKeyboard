# Arduino Library for 4x4 Membrane Switch

## MKeyboard(int l1 = 4, int l2 = 5, int l3 = 6, int l4 = 7, int c1 = 8, int c2 = 9, int c3 = 10, int c4 = 11)

Constructor. Default digital pins are 4 to 11.

## read()

Return key number is a key is pressed. Return -1 if no key is pressed.
A = 10, B = 11, C = 12, D = 13, * = 14, # = 15

# Example

```Arduino

#include "MKeyboard.h"

// CONSTRUTORES
MKeyboard key; //Inicializa o teclado


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int tecla = key.read();
  if (tecla != -1) {
    Serial.print("Tecla pressionada: ");
    Serial.println(tecla);
  }
}


```
