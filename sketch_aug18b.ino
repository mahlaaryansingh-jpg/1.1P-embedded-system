const int buttonPin = 2;
const int porchLight = 3;
const int hallwayLight = 4;

void setup()
{
    pinMode(buttonPin, INPUT_PULLUP);

    pinMode(porchLight, OUTPUT);
    pinMode(hallwayLight, OUTPUT);

    digitalWrite(porchLight, LOW);
    digitalWrite(hallwayLight, LOW);
}

void loop()
{
    if (digitalRead(buttonPin) == LOW)
    {
        digitalWrite(porchLight, HIGH);
        digitalWrite(hallwayLight, HIGH);

        delay(2000);
        digitalWrite(porchLight, LOW);
        delay(2000);
        digitalWrite(hallwayLight, LOW);
        while (digitalRead(buttonPin) == LOW)
        {
            delay(10);
        }
    }
}