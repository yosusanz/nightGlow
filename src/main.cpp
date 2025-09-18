// ----------------------------
// NightGlow - Automatic Bed Lights
// Author: Yosu Sanz Iriarte
// ----------------------------

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <NewPing.h>

// Ultrasonic sensor pins
#define TRIG_PIN_1 14
#define ECHO_PIN_1 13
#define TRIG_PIN_2 17
#define ECHO_PIN_2 16

// Sensors configuration
const uint16_t SONAR_MAX_DISTANCE = 200;
const uint16_t PERSON_DETECTION_DISTANCE = 120;

// Light sensor
#define LIGHT_SENSOR_PIN 34

// LED strip configuration
#define LED_DATA_PIN 5
const uint16_t NUM_LEDS = 64;
const uint8_t LED_BRIGHTNESS = 64;
const uint8_t LED_COLOR_R = 255;
const uint8_t LED_COLOR_G = 65;
const uint8_t LED_COLOR_B = 0;

// Timings
const unsigned long LIGHT_ON_DURATION = 1000UL * 120;
uint8_t timesPersonDetected = 0;


Adafruit_NeoPixel strip(NUM_LEDS, LED_DATA_PIN, NEO_GRB + NEO_KHZ800);
NewPing sonar1(TRIG_PIN_1, ECHO_PIN_1, SONAR_MAX_DISTANCE);
NewPing sonar2(TRIG_PIN_2, ECHO_PIN_2, SONAR_MAX_DISTANCE);

void setup() {
	Serial.begin(115200);
	pinMode(LIGHT_SENSOR_PIN, INPUT);

	strip.begin();
	strip.setBrightness(LED_BRIGHTNESS);
	strip.show();
}

void fadeIn() {
	for (int bLevel = 0; bLevel <= LED_BRIGHTNESS; bLevel++) {
		strip.setBrightness(bLevel);
		for (int i = 0; i < NUM_LEDS; i++) {
			strip.setPixelColor(i, strip.Color(LED_COLOR_R, LED_COLOR_G, LED_COLOR_B));
		}
		strip.show();

		delay(15);
	}
}

void fadeOut() {
	for (int bLevel = LED_BRIGHTNESS; bLevel >= 0; bLevel--) {
		strip.setBrightness(bLevel);
		strip.show();

		delay(15);
	}

	strip.clear();
	strip.show();
}

void loop() {
	int lightSensorValue = digitalRead(LIGHT_SENSOR_PIN);
	
	if (lightSensorValue == HIGH) {
		unsigned int distance1  = sonar1.ping_cm();
		unsigned int distance2  = sonar2.ping_cm();

		bool isPersonDetected = ( 
									(distance1  > 5 && distance1 < PERSON_DETECTION_DISTANCE) ||
									(distance2  > 5 && distance2 < PERSON_DETECTION_DISTANCE)
								);

		if (isPersonDetected) {
			timesPersonDetected++;

			if (timesPersonDetected >= 5) {
				fadeIn();
				delay(LIGHT_ON_DURATION);
				fadeOut();
				timesPersonDetected = 0;
			}
		} else {
			timesPersonDetected = 0;
		}
	}
	
	delay(100);
}