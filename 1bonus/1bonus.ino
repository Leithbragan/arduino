
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
  action('p');
  action('b');
  action('p');
  delay(1000);
}

void action(char type) {
  if (type == 'p') {
     signal_a(300);
  } else if (type == 'b') {
     signal_a(600);
  }
}

void signal_a(int time_a) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(2, 1);
    delay(time_a);
    digitalWrite(2, 0);
    delay(time_a);
  }
}
