#include <Arduino.h>

const int cols[3] = {5, 6, 7};
const int lins[3] = {8, 9, 10};

const bool matrix[3][3] = {
  {true, false, true},
  {false, true, false},
  {true, false, true}
};

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(cols[i], OUTPUT);
    pinMode(lins[i], OUTPUT);
    // Desliga tudo no início
    digitalWrite(cols[i], HIGH); // Colunas em HIGH (desligadas se forem catodo)
    digitalWrite(lins[i], LOW);  // Linhas em LOW (desligadas se forem anodo)
  }
}


void loop() {
  for (int f = 0; f < 600; f++) {

        for (int c = 0; c < 3; c++) {
            digitalWrite(cols[c], LOW);

        for (int l = 0; l < 3; l++) {
            digitalWrite(lins[l], matrix[l][c]);
        }

        delay(2);

        digitalWrite(cols[c], HIGH);
            for (int l = 0; l < 3; l++) {
                digitalWrite(lins[l], LOW);
            }
        }
  }
  for (int f = 0; f < 600; f++) {

  for (int c = 0; c < 3; c++) {
      digitalWrite(cols[c], LOW);

  for (int l = 0; l < 3; l++) {
      digitalWrite(lins[l], !matrix[l][c]);
  }

  delay(2);

  digitalWrite(cols[c], HIGH);
      for (int l = 0; l < 3; l++) {
          digitalWrite(lins[l], LOW);
      }
  }
  }
}
