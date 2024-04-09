void setup() {
  Serial.begin(9600);
  Serial.println("Hallo Welt!");
}

void loop() {
  Serial.println("Bist du noch da?");
  delay(2000);
}
