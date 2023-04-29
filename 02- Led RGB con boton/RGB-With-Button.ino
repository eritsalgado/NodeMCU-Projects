/*
  Este circuito tiene un led RGB y un botón, se utilizan los siguientes cables:
  * NodeMCU -> VIN a + 
  * NodeMCU -> GND a - 
  * NodeMCU -> D2~ a Led Red  (con resistencia 330ohms)
  * NodeMCU -> D5~ a Led Green(con resistencia 330ohms)
  * NodeMCU -> D6~ a Led Blue (con resistencia 330ohms)
  * Led RGB -> Cátodo a GND
  * Button  -> In a NodeMCU D1
  * Button  -> Out a GND

  En el ciclo se controla lo siguiente:
  * Apagado
  * Encendido con control de colores

  Se cuenta con la funcion custom_color(R,G,B)
  para optimizar la cantidad de código
  toma los 3 valores del led RGB y los asigna
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