#define out OUTPUT
#define in INPUT

const int led = 8;

int A = 7;
int B = 6;
int C;

int AStatus = 0;
int BStatus = 0;


void setup()
{
    pinMode(led, out);
    Serial.begin(9600);
    
    //pinMode(Cout, OUTPUT);
    pinMode(A, INPUT);
    pinMode(B, INPUT);

}
void loop()
{
    int sensor_value = analogRead(A0);
    //Serial.println(sensor_value);

    AStatus = digitalRead(A);
    BStatus = digitalRead(B);
   
    if (sensor_value < 120)
        C = 1; else C = 0;
//    Serial.println(AStatus);
//    Serial.println(BStatus + 3);
      Serial.println(C);
    if ((!C && !BStatus)|| (AStatus&& C))
        digitalWrite(led, HIGH);
    else digitalWrite(led, LOW);
}
