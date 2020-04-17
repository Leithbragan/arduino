
#define SW 2
#define LED 9

volatile boolean flag = false;
int data = LOW;
void setup() {
  pinMode(SW, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(0, button, FALLING);
}

void button() {
  flag = !flag;
  
}

void loop() {
  Serial.println(digitalRead(LED));
   if (flag) {
    flag = false;
    data = !data;
    digitalWrite(LED, data);
   } 
   
}
