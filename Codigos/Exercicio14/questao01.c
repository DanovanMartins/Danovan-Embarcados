// Escreva um código em C para gerar uma onda quadrada de 1 Hz em um pino GPIO do Raspberry Pi.

#include <stdio.h>
#include <wiringPi.h>

int main (void){
    wiringPiSetup ();
    pinMode (0, OUTPUT);

    for(;;){
        digitalWrite(0, HIGH);
        delay(500);
        digitalWrite(0,LOW);
        delay(500);
    }
    return 0;
}
