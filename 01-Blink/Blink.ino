int led_R = D2;
int led_G = D5;
int led_B = D6;
void setup() {
  pinMode(led_R, OUTPUT);
  pinMode(led_G, OUTPUT);
  pinMode(led_B, OUTPUT);
}

void loop() {
  custom_color(120, 0, 120);
  delay(3000);
  custom_color(0, 0, 0);
  delay(3000);
}

void custom_color(int R, int G, int B){
  analogWrite(led_R, R);
  analogWrite(led_G, G);
  analogWrite(led_B, B);
}