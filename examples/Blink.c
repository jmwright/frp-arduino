// This file is automatically generated.

#include <avr/io.h>
#include <stdbool.h>

static void clock();

static void stream_1(unsigned int input_0);

static void stream_2(bool input_0);

static void clock() {
  static unsigned int temp0 = 0U;
  temp0++;
  stream_1(temp0);
}

static void stream_1(unsigned int input_0) {
  bool temp1;
  temp1 = (input_0) % 2 == 0;
  stream_2(temp1);
}

static void stream_2(bool input_0) {
  if (input_0) {
    PORTB |= 0x20U;
  } else {
    PORTB &= ~(0x20U);
  }
}

int main(void) {
  TCCR1B = (1 << CS12) | (1 << CS10);
  DDRB |= 0x20U;
  while (1) {
    if (TCNT1 >= 10000) {
      TCNT1 = 0;
      clock();
    }
  }
  return 0;
}
