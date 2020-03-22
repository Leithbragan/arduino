
boolean flag = 1;
unsigned long last = 0;
void setup() {
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(A5, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (millis()- last > 250) { 
    digitalWrite(4, flag);
   last = millis();
   flag = !flag;
  }
}
