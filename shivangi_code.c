#include <stdio.h>
//#include <wiringPi.h> // For Raspberry Pi GPIO control
//#include <unistd.h>

const int buzzerPin = 1; // GPIO pin for the buzzer (adjust for your setup)
const int flamePin = 2;
const int ledpin =3;// GPIO pin for the flame sensor (adjust for your setup)
int Flame =0; // Assume HIGH (no flame) initially
int buzzer =1;
int led =1 ;
int buzzer_reg ;
int led_reg ;

void delay(int milliseconds) {
    for (int i = 0; i < milliseconds; i++) {
        for (int j = 0; j < 10000; j++) {
            // Adjust the loop count based on your microcontroller's speed
        }
    }
}



void main() {
  //  wiringPiSetupGpio(); // Initialize the wiringPi library

//    pinMode(buzzerPin, OUTPUT);
  //  pinMode(flamePin, INPUT);
 // pinMode(ledpin,OUTPUT); 
  

    while (1) {
        
        if (Flame == 0) { // LOW indicates fire detection
          // printf("Fire is Detected\n");
        //  Flame  = digital_read (0);
           // digitalWrite(buzzerPin, HIGH);
           //digitalWrite(ledpin, HIGH);
           asm(
        	"andi %0, x30, 1\n\t"
        	:"=r"(Flame));
         // buzzer = digitalwrite(1);
         // printf("Buzzer is on,fire detected ");
         buzzer =1;
          	buzzer_reg = buzzer*2;
        	asm(
        	"or x30, x30,%0 \n\t"
        	:"=r"(buzzer_reg));
        
          led = 1;
          led_reg = led*4;
          asm(
        	"or x30, x30,%0 \n\t"
        	:"=r"(led_reg));
          
        } 
        else {
          // printf("No Fire is Detected\n");
         //  buzzer= digitalWrite(0);
           buzzer =0;
           buzzer_reg = buzzer*2;
        	asm(
        	"or x30, x30,%0 \n\t"
        	:"=r"(buzzer_reg));
        	
       // led= digitalWrite(0);
        
          led = 0;
          led_reg = led*4;
          asm(
        	"or x30, x30,%0 \n\t"
        	:"=r"(led_reg));
          
        } 
        }
        
        delay(1000); // Sleep for 100 milliseconds (adjust as needed)
    }

