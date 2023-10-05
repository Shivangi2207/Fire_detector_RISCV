# Fire_detector_RISCV

## FIRE ALARM
Fire alarms are essential safety devices that serve a crucial role in detecting and alerting people to the presence of fires or smoke in buildings and enclosed spaces. Their primary purpose is to provide early detection, saving lives by alerting occupants to evacuate quickly and safely. These alarms also protect property by minimizing fire damage and facilitating a faster response from emergency services. Compliance with regulations, round-the-clock protection, reduced panic during emergencies, and the ability to wake occupants during sleep are among the many reasons why fire alarms are a vital component of fire safety systems, offering peace of mind and safeguarding lives and property from the devastating impact of fires.

## MATERIAL REQUIRED

- Flame sensor 
- Buzzer
- LED

## How do fire sensors work?
These sensors include one or more IR receiver diodes. The main purpose of these sensors is to detect IR rays. That is, when there is a fire near this sensor, it can detect the IR rays in the fire (these IR rays are invisible to our eye). Then, it gives us a signal through these sensors. That is, we can get that signal as a digital or analog value.

![Screenshot from 2023-10-05 00-07-02](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/9ffa7071-1f2f-45cc-b249-f415baba64f3)

## CIRCUIT DIAGRAM

![Screenshot from 2023-10-04 23-37-50](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/aada2bbe-fe30-4125-99a3-76b8dcacef66)

## C CODE
```
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

```
## VERIFICATION OF C CODE:

![Screenshot from 2023-10-04 23-33-17](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/654a33e8-0dd4-4823-969e-b670e030b084)

## ASSEMBLY CODE:

```
shivangi_code.o:     file format elf32-littleriscv


Disassembly of section .text:

00000000 <delay>:
   0:	fd010113          	add	sp,sp,-48
   4:	02812623          	sw	s0,44(sp)
   8:	03010413          	add	s0,sp,48
   c:	fca42e23          	sw	a0,-36(s0)
  10:	fe042623          	sw	zero,-20(s0)
  14:	0340006f          	j	48 <.L2>

00000018 <.L5>:
  18:	fe042423          	sw	zero,-24(s0)
  1c:	0100006f          	j	2c <.L3>

00000020 <.L4>:
  20:	fe842783          	lw	a5,-24(s0)
  24:	00178793          	add	a5,a5,1
  28:	fef42423          	sw	a5,-24(s0)

0000002c <.L3>:
  2c:	fe842703          	lw	a4,-24(s0)
  30:	000027b7          	lui	a5,0x2
  34:	70f78793          	add	a5,a5,1807 # 270f <.L8+0x265f>
  38:	fee7d4e3          	bge	a5,a4,20 <.L4>
  3c:	fec42783          	lw	a5,-20(s0)
  40:	00178793          	add	a5,a5,1
  44:	fef42623          	sw	a5,-20(s0)

00000048 <.L2>:
  48:	fec42703          	lw	a4,-20(s0)
  4c:	fdc42783          	lw	a5,-36(s0)
  50:	fcf744e3          	blt	a4,a5,18 <.L5>
  54:	00000013          	nop
  58:	00000013          	nop
  5c:	02c12403          	lw	s0,44(sp)
  60:	03010113          	add	sp,sp,48
  64:	00008067          	ret

00000068 <main>:
  68:	ff010113          	add	sp,sp,-16
  6c:	00112623          	sw	ra,12(sp)
  70:	00812423          	sw	s0,8(sp)
  74:	01010413          	add	s0,sp,16

00000078 <.L9>:
  78:	000007b7          	lui	a5,0x0
  7c:	0007a783          	lw	a5,0(a5) # 0 <delay>
  80:	02079063          	bnez	a5,a0 <.L7>
  84:	000007b7          	lui	a5,0x0
  88:	00100713          	li	a4,1
  8c:	00e7a023          	sw	a4,0(a5) # 0 <delay>
  90:	000007b7          	lui	a5,0x0
  94:	00100713          	li	a4,1
  98:	00e7a023          	sw	a4,0(a5) # 0 <delay>
  9c:	0140006f          	j	b0 <.L8>

000000a0 <.L7>:
  a0:	000007b7          	lui	a5,0x0
  a4:	0007a023          	sw	zero,0(a5) # 0 <delay>
  a8:	000007b7          	lui	a5,0x0
  ac:	0007a023          	sw	zero,0(a5) # 0 <delay>

000000b0 <.L8>:
  b0:	3e800513          	li	a0,1000
  b4:	00000097          	auipc	ra,0x0
  b8:	000080e7          	jalr	ra # b4 <.L8+0x4>
  bc:	fbdff06f          	j	78 <.L9>


```


## LISTS OF INSTRUCTIONS THIS CODE CONTAINS:

![Screenshot from 2023-10-05 11-08-58](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/24d1a2cb-60f1-44ed-907b-9dadbb044f2c)

```
Number of different instructions: 13
List of unique instructions:
jalr
sw
auipc
nop
j
bge
bnez
lui
ret
blt
add
li
lw



```
