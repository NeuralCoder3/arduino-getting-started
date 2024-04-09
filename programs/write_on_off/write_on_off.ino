void setup() {
  pinMode(2, OUTPUT);
}

int on=1, off = 19;
void loop() {
  for(int i=0;i<1000;){
    digitalWrite(2, HIGH);
    delay(on);
    digitalWrite(2, LOW);
    delay(off);
    i+=on+off;
  }
  digitalWrite(2, LOW);
  delay(1000);
}
