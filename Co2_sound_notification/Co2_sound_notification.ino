unsigned long previousMillis = 0;
const long interval = 1000 * 10;

int melody[] =    {262, 294, 330, 349, 392, 440, 494, 523};

void sound_alarm()
{
  for (int i = 0; i < 8; i++) {
    tone(D1, melody[i], 250);
    delay(400);
    noTone(D1);
    }
}

int getCo2()
{
  int value = analogRead(A0);
  Serial.println(value);
  return value;
}

void setup() {
  Serial.begin(250000);
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(D8, INPUT);
  pinMode(D1, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(D4, OUTPUT);
  digitalWrite(D4, LOW);
  previousMillis = millis();
}

// the loop function runs over and over again forever
void loop() {
  unsigned long currentMillis = millis();
  int val = digitalRead(D8);
  if(val == LOW)
  {
    previousMillis = millis();
    digitalWrite(LED_BUILTIN, HIGH);   // Turn the LED off by making the voltage HIGH
    Serial.println("Not - Captured ");
  }
  else if(val==HIGH && ( currentMillis - previousMillis >= interval || getCo2()>105) )
  {
    digitalWrite(LED_BUILTIN, LOW); // Turn the LED on by making the voltage LOW
    sound_alarm();
    Serial.println("Ok  - Captured ");
  }
  delay(350);
}
