int led_R = D2;
int led_G = D5;
int led_B = D6;
int blueValue = 0;

void custom_color(int R, int G, int B){
  analogWrite(led_R, R);
  analogWrite(led_G, G);
  analogWrite(led_B, B);
}

void BlinkWifiLed(){
  blueValue = (blueValue == 0) ? 255 : 0;
  analogWrite(led_B, blueValue);
}