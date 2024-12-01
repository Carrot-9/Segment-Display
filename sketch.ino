#include <avr/io.h> 
#include<util/delay.h>

int main(void) {

  // pins
DDRD |= (1<<PD2);
DDRD |= (1<<PD3);
DDRD |= (1<<PD4);
DDRD |= (1<<PD5);
DDRD |= (1<<PD6);
DDRB |= (1<<PB0);
DDRB |= (1<<PB1);

loop();

}

int Digit(int digit) {

  // a top-horizontal
  if (digit != 1 || digit != 4) {
    PORTD = 0b00000100;
  }

  // b top-right vertical 
  if (digit != 5 || digit != 6 ) {
    PORTD = 0b00001000;
  }

  // c bottom-right vertical
  if (digit != 2) {
    PORTD = 0b00010000;
  }

  // d bottom horizontal
  if (digit != 1 || digit != 4 || digit != 7 || digit != 9) {
    PORTD = 0b00100000;
  }

  // e bottom-left vertical
  if (digit == 0 || digit == 2 || digit == 6 || digit == 8) {
    PORTD = 0b01000000;
  }

  // f top-left vertical 
  if (digit != 1 || digit != 2 || digit != 3 || digit != 7) {
    PORTB = 0b00000001;
  }

  // g middle horizontal
  if (digit != 1 || digit != 7 ) {
    PORTB = 0b00000010;
  }
}

void loop() {
  while (true) {
    int j = 0;
    for(int i=j; i < 10; i++) {
      Digit(i);
      _delay_ms (1000);
    }
  }
}



