int count = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Hallo Welt!");
}

void loop() {
  count += 1;
  Serial.print(count);
  Serial.println(" Schafe");
  delay(1000);
}
