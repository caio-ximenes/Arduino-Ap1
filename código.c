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

// Secção do KeyPad

  const byte LINHAS = 4;
  const byte COLUNAS = 4;

  // Mapeamento das teclas 
  char teclas[LINHAS][COLUNAS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
  };

  
  byte pinosLinhas[LINHAS] = {22, 24, 26, 28};
  byte pinosColunas[COLUNAS] = {30, 32, 34, 36};

  
  Keypad teclado = Keypad(makeKeymap(teclas), pinosLinhas, pinosColunas, LINHAS, COLUNAS);


  String entrada =  "";

void setup() {

// Joystick
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);

// Membrana
  Serial.begin(9600);
  Serial.println("Digite algo e precione * para confirmar");
  

}

void loop() {

  char tecla = teclado.getKey(); 
  

  if (tecla) {
    if (tecla == '*') {
      Serial.println(); 
      Serial.print("Entrada confirmada: ");
      Serial.println(entrada);
      entrada = "";
      Serial.println("Digite novamente:");
    } 
    else if (tecla >= '0' && tecla <= '4') {
      entrada += tecla;
      Serial.print(tecla); 
    }
  }
  

}
