/*
  This circuit has a common catode RGB Led and a button
  here are the wirings
  * NodeMCU -> VIN to + 
  * NodeMCU -> GND to - 
  * NodeMCU -> D2~ to Led Red  (resistor 330 ohms)
  * NodeMCU -> D5~ to Led Green(resistor 330 ohms)
  * NodeMCU -> D6~ to Led Blue (resistor 330 ohms)
  * Led RGB -> Cátodo to GND
  * Button  -> In to NodeMCU D1
  * Button  -> Out to GND

  The circuit does the following
  * On/Off status
  * Color change status, just like christmas tree leds

  I created the function custom_color(R,G,B)
  optimizing in less code quantity
  
  the function takes and assign the 3 values needed 
  for RGB colors
*/

int led_R = D2;
int led_G = D5;
int led_B = D6;

int mode = 0;
void setup() {
  pinMode(led_R, OUTPUT);
  pinMode(led_G, OUTPUT);
  pinMode(led_B, OUTPUT);

  pinMode(D1, INPUT_PULLUP);
}

void loop() {

  if(digitalRead(D1) == LOW){
    mode = mode +1;
    delay(400);
  }

  switch(mode) {
    case 1:
      custom_color(255,0,0);
      break;
    case 2:
      custom_color(0,255,0);
      break;
    case 3:
      custom_color(0,0,255);
      break;
    case 4:
      custom_color(120, 0, 120);
      break;
    case 5:
      mode = 0;
      break;
    default:
      custom_color(0,0,0);
      break;
  }
}

void custom_color(int R, int G, int B){
  analogWrite(led_R, R);
  analogWrite(led_G, G);
  analogWrite(led_B, B);
}