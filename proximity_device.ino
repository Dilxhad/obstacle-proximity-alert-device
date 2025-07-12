#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER_PIN 8

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration;
  float distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 20000); // 20 ms timeout

  if (duration == 0) {
    digitalWrite(BUZZER_PIN, LOW); // No echo
    Serial.println(0); // Plot zero
    
  } else {
    distance = duration * 0.034 / 2;

    if (distance > 0 && distance <= 100) {
      int beepDelay = map(distance, 100, 0, 400, 50);

      digitalWrite(BUZZER_PIN, HIGH);
      delay(50); // Beep duration
      digitalWrite(BUZZER_PIN, LOW);
      delay(beepDelay);
      Serial.println(distance); // Send data for Radar Plot
      
    } else {
      digitalWrite(BUZZER_PIN, LOW); // Out of range
      Serial.println(0); // Plot zero
    }
  }
}
