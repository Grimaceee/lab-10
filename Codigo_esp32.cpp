#include <Arduino.h>

#define POT_PIN 34          
#define RX_PIN 16         
#define TX_PIN 17          
#define BAUD_RATE 115200   

void setup() {
  // Inicializa la comunicación serial con el PC
  Serial.begin(BAUD_RATE);
  Serial1.begin(BAUD_RATE, SERIAL_8N1, RX_PIN, TX_PIN);
  
  pinMode(POT_PIN, INPUT);
}

void loop() {

  int potValue = analogRead(POT_PIN);

  Serial.print("Valor del potenciómetro: ");
  Serial.println(potValue);
  Serial.println("Esperando datos del STM32...");
  // Enviar el valor al STM32
  Serial1.println(potValue); 
  
  delay(1000);
}
