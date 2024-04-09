void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  int percent = sensorValue/1023*100;
  Serial.print(percent);
  Serial.println("%");
  delay(200);
}
