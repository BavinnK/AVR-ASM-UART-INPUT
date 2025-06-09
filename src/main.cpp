#include <Arduino.h>
#include <stdlib.h>
#include <avr/io.h> 
#include <avr/pgmspace.h>
const int ledpin=13,buttonpin=12;
int counter=0;
volatile uint8_t x=12,y=20;
extern "C"{
   uint8_t btnReadD12();
   void digitalSetASM(uint8_t port,uint8_t bit);
   void digitalClearASM(uint8_t port,uint8_t bit);
   uint8_t UartTransmit(uint8_t transmit);

}
void setup() {

  digitalSetASM(_SFR_IO_ADDR(DDRB),1<<PB5);
  pinMode(buttonpin,INPUT_PULLUP);

  Serial.begin(115200);

}

void loop() {
  char buff[90];
  int readbut=btnReadD12();
  if(readbut != HIGH){
    digitalSetASM(_SFR_IO_ADDR(PORTB),1<<PB5);
    counter++;
    sprintf(buff,"button pressed! counter=%d\n\0hahahahah finally ",(uint8_t)counter);
    for (int i=0; i<strlen(buff); i++) {
    UartTransmit(buff[i]);
    }
    delay(300);
    digitalClearASM(_SFR_IO_ADDR(PORTB),1<<PB5);
 }

}
