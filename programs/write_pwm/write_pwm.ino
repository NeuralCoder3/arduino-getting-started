void setup() {
  pinMode(2, OUTPUT);
}

int on=1, off = 19;
void loop() {
  analogWrite(3, 25);
  delay(1000);
  digitalWrite(3, LOW);
  delay(1000);
}
