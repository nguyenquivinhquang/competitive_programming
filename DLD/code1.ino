//set pin numbers
int A = 3;
int B = 4;
const int Cout = 7; 
int AStatus = 0;
int BStatus = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(Cout, OUTPUT);
  pinMode(A, INPUT);
  pinMode(B, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  AStatus = digitalRead(A);
  BStatus = digitalRead(B);

  if (AStatus == HIGH && BStatus == HIGH) {
    digitalWrite(Cout, HIGH);
  } else {
    digitalWrite(Cout,LOW);
  }
}