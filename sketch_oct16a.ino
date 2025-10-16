#include <Keypad.h>
#include <MFRC522.h>
#include <SPI.h>
#define PINO_RST 23
#define PINO_SDA 22

MFRC522 rfid(PINO_SDA, PINO_RST);


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





bool alarme(){
  if (lerInfra() == 1) {  
    for (int i = 0; i < 50; i++) {
      digitalWrite(saidaBuzzer, LOW);  
      delay(100);                       
      digitalWrite(saidaBuzzer, HIGH);  
      delay(100);                       
    }
    return true;
  } else {
    digitalWrite(saidaBuzzer, LOW);  
    return false;     
  }
}
// Som que se faz ao selecionar a função.
bool somSelecionarFuncao(){
  int movimento = lerMovimento(); 

  if (movimento == 1 || movimento == 3 || movimento == 4) {
    digitalWrite(saidaBuzzer, HIGH);
    delay(200);
    digitalWrite(saidaBuzzer, LOW);  
    delay(100);
    digitalWrite(saidaBuzzer, HIGH);
    delay(100);
    digitalWrite(saidaBuzzer, LOW);
    return true;  
  } 
  else if(movimento == 2){
    digitalWrite(saidaBuzzer, HIGH);
    delay(250);
    digitalWrite(saidaBuzzer, LOW);
    return true;


  }
  else {
    digitalWrite(saidaBuzzer, LOW);
    return false;  
  }
}

bool recepcao(){
  Serial.println("Seja bem vindo ao sistema Security Door!");
  for(int i = 0; i<50; i++){
    Serial.print("=");
    delay(100);
  };
  Serial.println("=");
  delay(200);
  Serial.println("Sistema iniciado. Use o joystick para escolher o modo.");
  return true;

}

//Modo de monitoramento contínuo. FALTA SENSOR SONICO .
bool monitoramentoContinuo() {
  int sair = 0;  

  while (sair != 2) { 
    sair = lerMovimento();  

    if (lerInfra() == 1) {
      Serial.println("Alguém está entrando");
    } else {
      Serial.println("Ninguém está entrando");
    }
    delay(2000);
  }
  return false;
}






//Secção do infravermelho
int lerInfra(){
  return !digitalRead(sensorInfra);
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
//Buzzer
  pinMode(saidaBuzzer,OUTPUT);
//Sensor Infra
  pinMode(sensorInfra,INPUT);

// Joystick
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);


// Membrana
  Serial.begin(9600);
  




  

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





