#include <Wire.h>
#include "ssd1306.h"

// Pins
#define TRIG_PIN D2
#define ECHO_PIN D3
#define BUZZER_PIN D4
#define RED_LED D5
#define GREEN_LED D6

int temp = 24;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.begin(115200);

  Wire.begin(D14, D15);

  ssd1306_128x64_i2c_init();
  ssd1306_setFixedFont(ssd1306xled_font6x8);

  // Static text (printed once)
  ssd1306_clearScreen();
  ssd1306_printFixed(0, 0, "Temp:", STYLE_NORMAL);
  ssd1306_printFixed(0, 10, "Dist:", STYLE_NORMAL);
}

void loop() {

  // Simulated temperature
  temp++;
  if (temp > 30) temp = 20;

  // Ultrasonic
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;

  // ---- UPDATE ONLY VALUES ----

  char buffer[10];

  // Temperature value
  itoa(temp, buffer, 10);
  ssd1306_printFixed(50, 0, "   ", STYLE_NORMAL); // clear old
  ssd1306_printFixed(50, 0, buffer, STYLE_NORMAL);

  // Distance value
  itoa(distance, buffer, 10);
  ssd1306_printFixed(50, 10, "   ", STYLE_NORMAL);
  ssd1306_printFixed(50, 10, buffer, STYLE_NORMAL);

  // ---- ALERT LOGIC ----
  if (distance < 20 || temp < 25) {

    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);

    if (distance < 20)
      ssd1306_printFixed(0, 30, "DANGER!   ", STYLE_NORMAL);

    if (temp < 25)
      ssd1306_printFixed(0, 45, "CHILL!    ", STYLE_NORMAL);
  }
  else {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);

    ssd1306_printFixed(0, 30, "SAFE      ", STYLE_NORMAL);
    ssd1306_printFixed(0, 45, "          ", STYLE_NORMAL);
  }

  delay(500);
}
