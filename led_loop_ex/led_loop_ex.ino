int timer=100;
int L1=2;
int L2=3;
int L3=4;
int leds[]={L1,L2,L3};
int ledCount=3;

void setup() {
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(leds[thisLed], OUTPUT);
  }

}

void loop() {
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    digitalWrite(leds[thisLed], HIGH);
    delay(timer);
    digitalWrite(leds[thisLed], LOW);
  }
}
