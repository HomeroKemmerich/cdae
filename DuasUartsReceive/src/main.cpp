/*
Engenharia de Computação - UPF
Comunicação de Dados em Aplicações Embarcadas
Marcelo Trindade Rebonatto
22/08/2023
Programa com comunicação serial entre dois kits eps32 - Receive
*/
#include <Arduino.h>

#define RXD2 16
#define TXD2 17

char c;
// put function declarations here:

void setup() {
    delay(1000);                   // Tempo para verificar a inicialização no terminal
    Serial.begin(9600);                                   // Inicializa para comunicação com Teclado e Monitor
    //Serial1.begin(9600, SERIAL_8N1, RXD2, TXD2);
    Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
    Serial.println("");
    Serial.println("Recebe e mostra");
    Serial.println("Serial Txd is on pin: " + String(TX));  // Inicializa para comunicação com outra UART
    Serial.println("Serial Rxd is on pin: " + String(RX));
    Serial.println("Serial Txd2 is on pin: " + String(TXD2));  // Inicializa para comunicação com outra UART
    Serial.println("Serial Rxd2 is on pin: " + String(RXD2));
}

void loop() {
  // put your main code here, to run repeatedly:
  while (!Serial2.available());            //Busy wait aguardando algo na serial2

  c = Serial2.read();       // Recebe o caracter digitado na entrada de dados 
  Serial.println("Chegou " + String(c));
  
}

// put function definitions here: