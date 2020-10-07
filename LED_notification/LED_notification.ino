unsigned long previousMillis = 0;
const long interval = 5000;

void setup() {
  Serial.begin(250000);
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(D8, INPUT);
  previousMillis = millis();
}

// the loop function runs over and over again forever
void loop() {
  unsigned long currentMillis = millis();
  int val = digitalRead(D8);
  if(val == HIGH)
  {
    previousMillis = millis();
    digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on by making the voltage LOW
    Serial.println("Ok  - Captured ");
  }
  else if(val==LOW && currentMillis - previousMillis >= interval)
  {
    digitalWrite(LED_BUILTIN, LOW);  // Turn the LED off by making the voltage HIGH
    Serial.println("Not - Captured ");
  }
  delay(350);
}
