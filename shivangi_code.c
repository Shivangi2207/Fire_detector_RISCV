//#include <stdio.h>
//#include <wiringPi.h> // For Raspberry Pi GPIO control
//#include <unistd.h>

const int buzzerPin = 1; // GPIO pin for the buzzer (adjust for your setup)
const int flamePin = 2;
const int ledpin =3;// GPIO pin for the flame sensor (adjust for your setup)
int Flame = 0; // Assume HIGH (no flame) initially
int buzzer = 0;
int led = 0;

void delay(int milliseconds) {
    for (int i = 0; i < milliseconds; i++) {
        for (int j = 0; j < 10000; j++) {
            // Adjust the loop count based on your microcontroller's speed
        }
    }
}



int main() {
  //  wiringPiSetupGpio(); // Initialize the wiringPi library

//    pinMode(buzzerPin, OUTPUT);
  //  pinMode(flamePin, INPUT);
 // pinMode(ledpin,OUTPUT); 
  

    while (1) {
        
        if (Flame == 0) { // LOW indicates fire detection
          // printf("Fire is Detected\n");
           // digitalWrite(buzzerPin, HIGH);
           buzzer =1 ;
           led = 1;
        } else {
          // printf("No Fire is Detected\n");
           // digitalWrite(buzzerPin, LOW);
           buzzer =0;
           led = 0;
        }
        
        delay(1000); // Sleep for 100 milliseconds (adjust as needed)
    }

    return 0;
}
