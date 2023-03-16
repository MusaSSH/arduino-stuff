void setup() {
  pinMode(12, INPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(11, HIGH);
  delayMicroseconds(10);
  digitalWrite(11, LOW);

  long distance = pulseIn(12, HIGH) / 58.2;
  digitalWrite(10, (distance <= 5));
  digitalWrite(9, (distance <= 10));
  digitalWrite(8, (distance <= 15));
  digitalWrite(7, (distance <= 20));
  digitalWrite(6, (distance <= 25));
  digitalWrite(5, (distance <= 30));
  digitalWrite(4, (distance <= 35));
  digitalWrite(3, (distance <= 40));
  digitalWrite(2, (distance <= 45));

  delay(100);
}
