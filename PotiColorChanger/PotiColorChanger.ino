#include <Adafruit_NeoPixel.h>

#define PIN 13
#define NUMPIXELS 15
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int potPin1 = 26;
int potPin2 = 25;
int potPin3 = 33;
int Value1 = 0;
int Value2 = 0;
int Value3 = 0;

void setup() {
  Serial.begin(9600);
  pixels.begin();
}

void loop() {
  Value1 = analogRead(potPin1);
  Value2 = analogRead(potPin2);
  Value3 = analogRead(potPin3);
  
  Serial.print("ROT_RAW: ");
  Serial.println(Value1);
  Serial.print("GRÜN_RAW: ");
  Serial.println(Value2);
  Serial.print("BLAU_RAW: ");
  Serial.println(Value3);
  delay(100);

  Value1 = map(Value1, 0, 4095, 0, 255);
  Value2 = map(Value2, 0, 4095, 0, 255);
  Value3 = map(Value3, 0, 4095, 0, 255);

  Serial.print("Rot: ");
  Serial.println(Value1);
  Serial.print("Grün: ");
  Serial.println(Value2);
  Serial.print("Blau: ");
  Serial.println(Value3);
  delay(100);

  int r = Value1;
  int g = Value2;
  int b = Value3;
  
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(r, g, b));
  pixels.show();
  delay(100);
}
