int trigPin = 2;
int echoPin = 3;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  for (int i = 4; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
  }

  Serial.begin(9600);
}

void loop()
{
  long distance = measureDistance();

  Serial.println(distance);
  for (int i = 1; i <= 10; i++)
  {
    digitalWrite(i + 3, (distance > i * 5));
  }

  delay(100);
}

long measureDistance()
{
  long duration, distance;

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 52.8;

  return distance;
}