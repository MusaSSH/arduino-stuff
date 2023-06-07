unsigned int val = 0;

bool buttonLastState = LOW;

void setup()
{
    for (int i = 2; i <= 9; i++)
    {
        pinMode(i, OUTPUT);
    }

    pinMode(10, INPUT_PULLUP);

    Serial.begin(9600);
}

void loop()
{
    int buttonState = digitalRead(10);
    if (buttonState == LOW && buttonLastState == HIGH)
    {
        val++;
    }

    buttonLastState = buttonState;

    digitalWrite(9, (val & 1));
    digitalWrite(8, (val & 2));
    digitalWrite(7, (val & 4));
    digitalWrite(6, (val & 8));
    digitalWrite(5, (val & 16));
    digitalWrite(4, (val & 32));
    digitalWrite(3, (val & 64));
    digitalWrite(2, (val & 128));

    String msg = "{0}{1}{2}{3}{4}{5}{6}{7} = {8}";
    msg.replace("{0}", String(bool(val & 128)));
    msg.replace("{1}", String(bool(val & 64)));
    msg.replace("{2}", String(bool(val & 32)));
    msg.replace("{3}", String(bool(val & 16)));
    msg.replace("{4}", String(bool(val & 8)));
    msg.replace("{5}", String(bool(val & 4)));
    msg.replace("{6}", String(bool(val & 2)));
    msg.replace("{7}", String(bool(val & 1)));
    msg.replace("{8}", String(val));

    Serial.println(msg.c_str());
}