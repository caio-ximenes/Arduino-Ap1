#include <Keypad.h>

int saidaBuzzer = 2;
int echoUltra = 6;
int triggerUltra = 7;
int sensorInfra = 8;
int xJoystick = A0;
int yJoystick = A1;
int ledAlarme = 5;

int lerMovimento(){
  //Cima
  if ((analogRead(xJoystick)) <= 100){
    return 1;

  }
  //Baixo
  if ((analogRead(xJoystick)) >= 600){
    return 2;

  }
  //Direita
  if ((analogRead(yJoystick)) <= 100){
    return 3;

  }
  //Esquerda
  if ((analogRead(yJoystick)) >= 600){
    return 4;

  }
  //Posição inicial
  if((analogRead(A0)) < 600 && (analogRead(A0)) > 500 && (analogRead(A1)) < 600 && (analogRead(A1)) > 500  ){
    return 0;
  }
}


void setup() {

// Joystick
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);

// Membrana
  pinMode(22, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(28, OUTPUT);

  pinMode(30, INPUT);
  pinMode(32, INPUT);
  pinMode(34, INPUT);
  pinMode(36, INPUT);

  Serial.begin(9600);
  

}

void loop() {

  for (int ti = 22; ti<30; ti++){

  }

  digitalWrite(22, LOW);
  digitalWrite(24, LOW);
  digitalWrite(26,LOW);
  digitalWrite(28, LOW);
  digitalWrite(ti, HIGH);


  
 
  

}
