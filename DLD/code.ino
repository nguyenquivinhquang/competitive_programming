const int 3;
#define out OUTPUT
#define in INPUT
void setup()
{
    pinMode(led, out);
    Serial.begin(9600);
}
void loop()
{
    int sensor_value = analogRead(A0);
    Serial.println(sensor_value);
    if (sensor_value < 340)
        digitalWrite(led, HIGH);
    else digitalWrite(led, LOW);
}