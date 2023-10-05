# Fire_detector_RISCV

## FIRE ALARM
Fire alarms are essential safety devices that serve a crucial role in detecting and alerting people to the presence of fires or smoke in buildings and enclosed spaces. Their primary purpose is to provide early detection, saving lives by alerting occupants to evacuate quickly and safely. These alarms also protect property by minimizing fire damage and facilitating a faster response from emergency services. Compliance with regulations, round-the-clock protection, reduced panic during emergencies, and the ability to wake occupants during sleep are among the many reasons why fire alarms are a vital component of fire safety systems, offering peace of mind and safeguarding lives and property from the devastating impact of fires.

## MATERIAL REQUIRED

- Flame sensor 
- Buzzer
- LED

## HOW DO FLAME SENSORS WORK?
A flame-sensor is one kind of detector which is mainly designed for detecting as well as responding to the occurrence of a fire or flame. The flame detection response can depend on its fitting. It includes an alarm system, a natural gas line, propane & a fire suppression system. This sensor is used in industrial boilers. The main function of this is to give authentication whether the boiler is properly working or not. The response of these sensors is faster as well as more accurate compare with a heat/smoke detector because of its mechanism while detecting the flame.
These sensors include one or more IR receiver diodes. The main purpose of these sensors is to detect IR rays. That is, when there is a fire near this sensor, it can detect the IR rays in the fire (these IR rays are invisible to our eye). Then, it gives us a signal through these sensors. That is, we can get that signal as a digital or analog value.

![Screenshot from 2023-10-05 00-07-02](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/9ffa7071-1f2f-45cc-b249-f415baba64f3)


## BLOCK DIAGRAM

![flowchart](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/07df280f-808f-44c6-b70b-7d8d1711f84a)


## CIRCUIT DIAGRAM

![Screenshot from 2023-10-04 23-37-50](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/aada2bbe-fe30-4125-99a3-76b8dcacef66)

## C CODE
```
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


```


## VERIFICATION OF C CODE:

![Screenshot from 2023-10-04 23-33-17](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/654a33e8-0dd4-4823-969e-b670e030b084)
```
gcc shivangi_code.c
./a.out

```


## ASSEMBLY CODE:

Steps to get assembly code

```
$ /home/shivangi/riscv32-toolchain/bin/riscv32-unknown-elf-gcc -c -mabi=ilp32 -march=rv32im -ffreestanding -o shivangi_code.o shivangi_code.c
$ /home/shivangi/riscv32-toolchain/bin/riscv32-unknown-elf-objdump -d shivangi_code.o > fire_alarm_assembly1.txt

```

```

shivi.o:     file format elf32-littleriscv


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
  34:	70f78793          	add	a5,a5,1807 # 270f <.L7+0x2627>
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
  6c:	00812623          	sw	s0,12(sp)
  70:	01010413          	add	s0,sp,16

00000074 <.L9>:
  74:	000007b7          	lui	a5,0x0
  78:	0007a783          	lw	a5,0(a5) # 0 <delay>
  7c:	06079663          	bnez	a5,e8 <.L7>
  80:	001f7713          	and	a4,t5,1
  84:	000007b7          	lui	a5,0x0
  88:	00e7a023          	sw	a4,0(a5) # 0 <delay>
  8c:	000007b7          	lui	a5,0x0
  90:	00100713          	li	a4,1
  94:	00e7a023          	sw	a4,0(a5) # 0 <delay>
  98:	000007b7          	lui	a5,0x0
  9c:	0007a783          	lw	a5,0(a5) # 0 <delay>
  a0:	00179713          	sll	a4,a5,0x1
  a4:	000007b7          	lui	a5,0x0
  a8:	00e7a023          	sw	a4,0(a5) # 0 <delay>
  ac:	00ef6f33          	or	t5,t5,a4
  b0:	000007b7          	lui	a5,0x0
  b4:	00e7a023          	sw	a4,0(a5) # 0 <delay>
  b8:	000007b7          	lui	a5,0x0
  bc:	00100713          	li	a4,1
  c0:	00e7a023          	sw	a4,0(a5) # 0 <delay>
  c4:	000007b7          	lui	a5,0x0
  c8:	0007a783          	lw	a5,0(a5) # 0 <delay>
  cc:	00279713          	sll	a4,a5,0x2
  d0:	000007b7          	lui	a5,0x0
  d4:	00e7a023          	sw	a4,0(a5) # 0 <delay>
  d8:	00ef6f33          	or	t5,t5,a4
  dc:	000007b7          	lui	a5,0x0
  e0:	00e7a023          	sw	a4,0(a5) # 0 <delay>
  e4:	f91ff06f          	j	74 <.L9>

000000e8 <.L7>:
  e8:	000007b7          	lui	a5,0x0
  ec:	0007a023          	sw	zero,0(a5) # 0 <delay>
  f0:	000007b7          	lui	a5,0x0
  f4:	0007a783          	lw	a5,0(a5) # 0 <delay>
  f8:	00179713          	sll	a4,a5,0x1
  fc:	000007b7          	lui	a5,0x0
 100:	00e7a023          	sw	a4,0(a5) # 0 <delay>
 104:	00ef6f33          	or	t5,t5,a4
 108:	000007b7          	lui	a5,0x0
 10c:	00e7a023          	sw	a4,0(a5) # 0 <delay>
 110:	000007b7          	lui	a5,0x0
 114:	0007a023          	sw	zero,0(a5) # 0 <delay>
 118:	000007b7          	lui	a5,0x0
 11c:	0007a783          	lw	a5,0(a5) # 0 <delay>
 120:	00279713          	sll	a4,a5,0x2
 124:	000007b7          	lui	a5,0x0
 128:	00e7a023          	sw	a4,0(a5) # 0 <delay>
 12c:	00ef6f33          	or	t5,t5,a4
 130:	000007b7          	lui	a5,0x0
 134:	00e7a023          	sw	a4,0(a5) # 0 <delay>
 138:	f3dff06f          	j	74 <.L9>

```


## LISTS OF INSTRUCTIONS THIS CODE CONTAINS:
To count no of different instruction run python.py code on terminal we will get our list of intructions.

![Screenshot from 2023-10-05 22-58-18](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/9b4122a7-74f2-4f09-ab10-70240d21c78f)



```
Number of different instructions: 14
List of unique instructions:
j
bge
nop
lui
ret
li
add
blt
sll
or
bnez
and
lw
sw




```


## ACKNOWLEDMENT

- Kunal Ghosh, VSD Corp. Pvt. Ltd.
- Mayank Kabra
  


## REFERENCES

- https://github.com/SakethGajawada/RISCV-GNU
- https://www.electronicshub.org/arduino-flame-sensor-interface/
- https://www.moryarduino.com/arduino-project/fire-alarm-using-flame-sensor-arduino
