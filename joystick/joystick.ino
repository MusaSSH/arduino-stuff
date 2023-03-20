#define BASE_DELAY 10

void setup() {
    Serial.begin(9600);
    pinMode(8, INPUT);
}

void loop() {
    joystick();
    delay(BASE_DELAY);
}

const int joystickDelayC = 50;
int joystickDelay = joystickDelayC;
void joystick() {
    if(joystickDelay > BASE_DELAY) {
        joystickDelay -= BASE_DELAY;
        return;
    }
    joystickDelay = joystickDelayC;
    int x = map(analogRead(A0), 0, 1000, 0, 2);
    int y = map(analogRead(A1), 0, 1000, 0, 2);
    int b = digitalRead(8);

    Serial.print("joy ");
    Serial.print(x);
    Serial.print(" ");
    Serial.print(y);
    Serial.print(" ");
    Serial.print(!b);
    Serial.print("\n");
}