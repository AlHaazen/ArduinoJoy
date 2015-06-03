#include <Arduino.h>

const int data = 2;
const int latch = 3;
const int clock = 4;

const int TICK = 2;

void init_joystick(int data, int latch, int clock)
{
    pinMode(data, INPUT);
    pinMode(clock, OUTPUT);
    pinMode(latch, OUTPUT);
    digitalWrite(clock, HIGH);
}

int get_keys_state_joystick(int data, int latch, int clock)
{
    digitalWrite(latch, HIGH);
    delayMicroseconds(TICK);
    digitalWrite(latch, LOW);

    int keys_state = 0;

    for (int i = 0; i < 8; ++i) {
        delayMicroseconds(TICK);
        digitalWrite(clock, LOW);

        keys_state <<= 1;
        keys_state += digitalRead(data);

        delayMicroseconds(TICK);
        digitalWrite(clock, HIGH);
    }

    return keys_state;
}

void setup()
{
    init_joystick(data, latch, clock);

    Serial.begin(57600);
}

void loop()
{
    int q=get_keys_state_joystick(data, latch, clock);
     Serial.write(q);
}
