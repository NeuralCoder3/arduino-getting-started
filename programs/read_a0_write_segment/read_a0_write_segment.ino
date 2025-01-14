#include "TM1637Display.h"

// read A0
// clk D2
// DIO D3d

#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);

/*
const uint8_t PERCENT[] = {
  0, 0, 0,
  SEG_B | SEG_G | SEG_E
};
*/
  
void setup() {
  Serial.begin(9600);
  display.setBrightness(0x08);
  uint8_t data[] = {0,0,0,0};
  display.setSegments(data);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.print(sensorValue);
  Serial.println("");
  //display.showNumberDec(4217, true);
  //display.setBrightness(0x0f);
  int percent = map(sensorValue,0,1024,0,100);
  //display.showNumberDec(percent, false, 3, 0);
  //display.setSegments(PERCENT);
  uint8_t data[] = {0,0,0,0};
  for(int i = 2; i >= 0; i--) {
    data[i] = display.encodeDigit(percent%10);
    if (i==0 && percent == 0)
      data[i] = 0;
    percent /= 10;
  }
  data[3] = SEG_B | SEG_G | SEG_E;
  display.setSegments(data);
  delay(200);
}

/*

#define TEST_DELAY   2000

const uint8_t SEG_DONE[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
  };

void loop()
{
  int k;
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  display.setBrightness(0x0f);
  
  // All segments on
  display.setSegments(data);
  delay(TEST_DELAY);
  
  // Selectively set different digits
  data[0] = 0b01001001;
  data[1] = display.encodeDigit(1);
  data[2] = display.encodeDigit(2);
  data[3] = display.encodeDigit(3);
  
  for(k = 3; k >= 0; k--) {
  display.setSegments(data, 1, k);
  delay(TEST_DELAY);
  }
  
  display.setSegments(data+2, 2, 2);
  delay(TEST_DELAY);
  
  display.setSegments(data+2, 2, 1);
  delay(TEST_DELAY);
  
  display.setSegments(data+1, 3, 1);
  delay(TEST_DELAY);
 
  
  // Show decimal numbers with/without leading zeros
  bool lz = false;
  for (uint8_t z = 0; z < 2; z++) {
  for(k = 0; k < 10000; k += k*4 + 7) {
    display.showNumberDec(k, lz);
    delay(TEST_DELAY);
  }
  lz = true;
  }
  
  // Show decimal number whose length is smaller than 4
  for(k = 0; k < 4; k++)
  data[k] = 0;
  display.setSegments(data);
  
  display.showNumberDec(153, false, 3, 1);
  delay(TEST_DELAY);
  display.showNumberDec(22, false, 2, 2);
  delay(TEST_DELAY);
  display.showNumberDec(0, true, 1, 3);
  delay(TEST_DELAY);
  display.showNumberDec(0, true, 1, 2);
  delay(TEST_DELAY);
  display.showNumberDec(0, true, 1, 1);
  delay(TEST_DELAY);
  display.showNumberDec(0, true, 1, 0);
  delay(TEST_DELAY);

  // Brightness Test
  for(k = 0; k < 4; k++)
  data[k] = 0xff;
  for(k = 0; k < 16; k++) {
    display.setBrightness(k);
    display.setSegments(data);
    delay(TEST_DELAY);
  }
    
  // Done!
  display.setSegments(SEG_DONE);
  
  while(1);
}
*/
