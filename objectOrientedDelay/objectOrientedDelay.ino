#define BASE_DELAY 10

class LED1 {
    public:
        int pin;
        int state = 0;
        int delayTime;
        int delayTimeLeft;
        LED1(int pin, int delayTime) :
            pin(pin),
            delayTime(delayTime),
            delayTimeLeft(delayTime)
        {}

        void setup()
        {
            pinMode(pin, OUTPUT);
        }

        void loop()
        {
            if (delayTimeLeft > 0) {
                delayTimeLeft -= BASE_DELAY;
                return;
            }
            delayTimeLeft = delayTime;

            digitalWrite(pin, state = !state);
        }
};

class LED2 {
    public:
        int pin;
        int state = 0;
        int delayTime;
        int delayTimeLeft;
        LED2(int pin, int delayTime) :
            pin(pin),
            delayTime(delayTime),
            delayTimeLeft(delayTime)
        {}

        void setup()
        {
            pinMode(pin, OUTPUT);
        }

        void loop()
        {
            if (delayTimeLeft > 0) {
                delayTimeLeft -= BASE_DELAY;
                return;
            }
            delayTimeLeft = delayTime;

            digitalWrite(pin, state = !state);
        }
};

LED1 l1(8, 1000);
LED2 l2(9, 500);

void setup() {
    l1.setup();
    l2.setup();
}

void loop() {
    l1.loop();
    l2.loop();
    delay(BASE_DELAY);
}