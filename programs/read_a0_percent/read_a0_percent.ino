void setup() {
  Serial.begin(9600);
}

void loop() {
  long sensorValue = analogRead(A0);
  int percent = 100*sensorValue/1023;
  Serial.print(percent);
  Serial.println("%");
  delay(200);
}
