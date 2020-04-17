#define VRX 0
#define LED 9


void setup() {
  
}

void loop() {
   int data = analogRead(VRX);
   data = map(data, 0, 1023, 0, 255);
   data = constrain(data, 0, 255);
   analogWrite(LED, data);

   
}
