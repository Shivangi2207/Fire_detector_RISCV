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


## GPIO
x30[0] is an input pin to detect flame from flame sensor.

x30[1] is an output pin used to indicate about the  flame detection using buzzer.

x30[2] is an output pin used to indicate about the flame detection using led.


## C CODE
```
//#include <stdio.h>



int main (){
       
        int Flame;
	int buzzer =0;
	int buzzer_reg = buzzer *2;
	
	int led = 0;
	int led_reg = led*4;
      
	
       asm volatile(
	"or x30, x30, %0\n\t" 
	"or x30, x30, %1\n\t" 
	:
	:"r"(buzzer_reg), "r"(led_reg)
	:"x30"
	);
	
	
	
      while(1){
	
	
     asm volatile(
       "andi %0, x30, 1\n\t"

        :"=r"(Flame)
        :
        :
        );
        
		if(Flame == 1)
		{
		// Flame = digital_read(0);
		//buzzer = digitalwrite(1);
		// led = digitalwrite(1);
		//printf("Flame is detected");
		buzzer = 1;
	        led=1;
		}
		
	else{
	
	// Flame= digital_read(1);
	// buzzer= digitalwrite(0);
	//printf("Flame not detected");
	        
	        buzzer = 0;
		led=0;
		
	}
	
	buzzer_reg = buzzer *2;
	led_reg = led*4;
    
    asm volatile(
	"or x30, x30, %0\n\t" 
	"or x30, x30, %1\n\t" 
	:
	:"r"(buzzer_reg), "r"(led_reg)
	:"x30"
	);
	
	
	}
	
	return 0;
	
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
/home/shivangi/riscv32-toolchain/bin/riscv32-unknown-elf-gcc -march=rv32i -mabi=ilp32 -ffreestanding -nostdlib -o ./out shivangi_code.c
/home/shivangi/riscv32-toolchain/bin/riscv32-unknown-elf-objdump -d -r out > fire_alarm_assembly.txt

```

```

out:     file format elf32-littleriscv


Disassembly of section .text:

00010074 <main>:
   10074:	ff010113          	add	sp,sp,-16
   10078:	00112623          	sw	ra,12(sp)
   1007c:	00812423          	sw	s0,8(sp)
   10080:	01010413          	add	s0,sp,16
   10084:	0c8000ef          	jal	1014c <Flame_detected>
   10088:	ffdff06f          	j	10084 <main+0x10>

0001008c <Flame_monitor>:
   1008c:	fd010113          	add	sp,sp,-48
   10090:	02812623          	sw	s0,44(sp)
   10094:	03010413          	add	s0,sp,48
   10098:	fe042623          	sw	zero,-20(s0)
   1009c:	fec42783          	lw	a5,-20(s0)
   100a0:	00179793          	sll	a5,a5,0x1
   100a4:	fef42423          	sw	a5,-24(s0)
   100a8:	fe042223          	sw	zero,-28(s0)
   100ac:	fe442783          	lw	a5,-28(s0)
   100b0:	00279793          	sll	a5,a5,0x2
   100b4:	fef42023          	sw	a5,-32(s0)
   100b8:	001f7793          	and	a5,t5,1
   100bc:	fcf42e23          	sw	a5,-36(s0)
   100c0:	fe842783          	lw	a5,-24(s0)
   100c4:	00ff6f33          	or	t5,t5,a5
   100c8:	fe042783          	lw	a5,-32(s0)
   100cc:	00ff6f33          	or	t5,t5,a5
   100d0:	fdc42703          	lw	a4,-36(s0)
   100d4:	00100793          	li	a5,1
   100d8:	04f71063          	bne	a4,a5,10118 <Flame_monitor+0x8c>
   100dc:	00100793          	li	a5,1
   100e0:	fef42623          	sw	a5,-20(s0)
   100e4:	fec42783          	lw	a5,-20(s0)
   100e8:	00179793          	sll	a5,a5,0x1
   100ec:	fef42423          	sw	a5,-24(s0)
   100f0:	00100793          	li	a5,1
   100f4:	fef42223          	sw	a5,-28(s0)
   100f8:	fe442783          	lw	a5,-28(s0)
   100fc:	00279793          	sll	a5,a5,0x2
   10100:	fef42023          	sw	a5,-32(s0)
   10104:	fe842783          	lw	a5,-24(s0)
   10108:	00ff6f33          	or	t5,t5,a5
   1010c:	fe042783          	lw	a5,-32(s0)
   10110:	00ff6f33          	or	t5,t5,a5
   10114:	fbdff06f          	j	100d0 <Flame_monitor+0x44>
   10118:	fe042623          	sw	zero,-20(s0)
   1011c:	fec42783          	lw	a5,-20(s0)
   10120:	00179793          	sll	a5,a5,0x1
   10124:	fef42423          	sw	a5,-24(s0)
   10128:	fe042223          	sw	zero,-28(s0)
   1012c:	fe442783          	lw	a5,-28(s0)
   10130:	00279793          	sll	a5,a5,0x2
   10134:	fef42023          	sw	a5,-32(s0)
   10138:	fe842783          	lw	a5,-24(s0)
   1013c:	00ff6f33          	or	t5,t5,a5
   10140:	fe042783          	lw	a5,-32(s0)
   10144:	00ff6f33          	or	t5,t5,a5
   10148:	f89ff06f          	j	100d0 <Flame_monitor+0x44>

0001014c <Flame_detected>:
   1014c:	ff010113          	add	sp,sp,-16
   10150:	00112623          	sw	ra,12(sp)
   10154:	00812423          	sw	s0,8(sp)
   10158:	01010413          	add	s0,sp,16
   1015c:	f31ff0ef          	jal	1008c <Flame_monitor>
   10160:	00000013          	nop
   10164:	00c12083          	lw	ra,12(sp)
   10168:	00812403          	lw	s0,8(sp)
   1016c:	01010113          	add	sp,sp,16
   10170:	00008067          	ret
```


## LISTS OF INSTRUCTIONS THIS CODE CONTAINS:
To count no of different instruction run python.py code on terminal we will get our list of intructions.


![Screenshot from 2023-10-09 19-39-09](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/136794a4-4c6f-4592-8d1e-c919e58d2ceb)


```
Number of different instructions: 12
List of unique instructions:
jal
or
j
sll
li
add
sw
and
lw
ret
bne
nop





```


## ACKNOWLEDMENT

- Kunal Ghosh, VSD Corp. Pvt. Ltd.
- Mayank Kabra
  


## REFERENCES

- https://github.com/SakethGajawada/RISCV-GNU
- https://www.electronicshub.org/arduino-flame-sensor-interface/
- https://www.moryarduino.com/arduino-project/fire-alarm-using-flame-sensor-arduino
