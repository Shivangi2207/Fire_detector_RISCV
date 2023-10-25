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
 #include <stdio.h>
#include<stdlib.h>

int main() {

  
      int flag;//Replace with GPIO pin connected to switch pin 
      int flame;// Replace with the GPIO pin connected to sensor's digital out pin
      int buzzer=0; // Replace with the GPIO pin connected to the buzzer
      int buzzer_reg = buzzer*4;
      int led=0; //Replace with GPIO pin connected to the LED
      int led_reg = led *8;
      int mask = 0xFFFFFFF3;
     // int t1,t2,t3,t4,t5;

  
    	    
 asm volatile(
	
	"and x30, x30, %2\n\t"	 
	"or x30, x30, %0\n\t" 
	"or x30, x30, %1\n\t"
	:
	:"r"(buzzer_reg), "r"(led_reg), "r"(mask)
	:"x30"
      );


	/*
	 asm volatile(
		"addi x30, x30, 0\n\t"
		:"=r"(t1)
		:
		:"x30"
	);
	
	
 	printf("test_case1 = %d\n",t1);
        printf("flame = %d, flag=%d, buzzer = %d, led=%d\n", flame, flag, buzzer_reg,led_reg);
        
	printf("Entering while 1 loop\n");
	
	*/
	
    	
//int j;
//for(j=0;j<1;j++)

  while(1) 
  {
 


   

	  asm volatile(
        	"andi %0, x30, 1\n\t"
	        :"=r"(flag)
		:
		:
 	);

  

	/*asm volatile(
    	"addi %0, x30, 0\n\t"
    	:"=r"(t2)
    	:
    	:"x30"
    	);
    	printf("test_case2 = %d\n",t2);
        
	*/ 
	
	 

         flag = 1;
      if (flag) {

              //flame = digital_read(0);

              printf("entered in for loop\n");

             

		asm volatile(
        		"andi %0, x30, 2\n\t"
			:"=r"(flame)
        		:
        		:
	 	);

  
  
 	     /*   asm volatile(
    		  "addi %0, x30, 0\n\t"
    		  :"=r"(t3)
    		  :
    		  :"x30"
    		);
	        printf("test_case3 = %d\n",t3);
	
*/
 

              flame=1;
	        if(flame){
             
              // buzzer = digitalwrite(1);
              // led = digitalwrite(1);
            // printf("Buzzer is ON\n");
	
	            buzzer = 1;
	            led = 1;
  	
	  } 

	  
	  else {
          
          
                    

              // buzzer = digitalWrite(1)
              // led = digitalWrite(1)
              //printf("Buzzer is OFF\n");

	    buzzer = 0;
	    led=0;	
	    
  /* asm volatile(
    	"addi %0, x30, 0\n\t"
    	:"=r"(t4)
    	:
    	:"x30"
    	);
    	printf("test_case4 = %d\n",t4);
    	
    	
	   
            }
	*/ 
	    
	  


 // updating register values
    
	buzzer_reg = buzzer*4;
	led_reg = led*8;


	asm volatile(
	    "and x30, x30, %2\n\t"
	    "or x30, x30, %0 \n\t"
            "or x30, x30, %1 \n\t"
	    :
	    :"r"(buzzer_reg), "r"(led_reg), "r"(mask)
            :"x30"
          );	 
          
          
          
          
          
  /*asm volatile(
    	"addi %0, x30, 0\n\t"
    	:"=r"(t5)
    	:
    	:"x30"
    	);
    	printf("test_case5 = %d\n",t5);
    printf("flame = %d, flag=%d,buzzer = %d,  led=%d\n",flame, flag ,buzzer_reg,led_reg);

*/

        }

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
/home/shivangi/riscv32-toolchain/bin/riscv64-unkown-elf-gcc -march=rv32i -mabi=ilp32 -ffreestanding -nostdlib -o ./out shivangi_code.c
/home/shivangi/riscv32-toolchain/bin/riscv64-unknown-elf-objdump -d  -r out > fire_alarm_assembly.txt
```

```



out:     file format elf32-littleriscv


Disassembly of section .text:

00010054 <main>:
   10054:	fd010113          	addi	sp,sp,-48
   10058:	02812623          	sw	s0,44(sp)
   1005c:	03010413          	addi	s0,sp,48
   10060:	fe042623          	sw	zero,-20(s0)
   10064:	fec42783          	lw	a5,-20(s0)
   10068:	00279793          	slli	a5,a5,0x2
   1006c:	fef42223          	sw	a5,-28(s0)
   10070:	fe042423          	sw	zero,-24(s0)
   10074:	fe842783          	lw	a5,-24(s0)
   10078:	00379793          	slli	a5,a5,0x3
   1007c:	fef42023          	sw	a5,-32(s0)
   10080:	ff300793          	li	a5,-13
   10084:	fcf42e23          	sw	a5,-36(s0)
   10088:	fe442783          	lw	a5,-28(s0)
   1008c:	fe042703          	lw	a4,-32(s0)
   10090:	fdc42683          	lw	a3,-36(s0)
   10094:	00df7f33          	and	t5,t5,a3
   10098:	00ff6f33          	or	t5,t5,a5
   1009c:	00ef6f33          	or	t5,t5,a4
   100a0:	001f7793          	andi	a5,t5,1
   100a4:	fcf42c23          	sw	a5,-40(s0)
   100a8:	00100793          	li	a5,1
   100ac:	fcf42c23          	sw	a5,-40(s0)
   100b0:	fd842783          	lw	a5,-40(s0)
   100b4:	fe0786e3          	beqz	a5,100a0 <main+0x4c>
   100b8:	002f7793          	andi	a5,t5,2
   100bc:	fcf42a23          	sw	a5,-44(s0)
   100c0:	00100793          	li	a5,1
   100c4:	fcf42a23          	sw	a5,-44(s0)
   100c8:	fd442783          	lw	a5,-44(s0)
   100cc:	00078c63          	beqz	a5,100e4 <main+0x90>
   100d0:	00100793          	li	a5,1
   100d4:	fef42623          	sw	a5,-20(s0)
   100d8:	00100793          	li	a5,1
   100dc:	fef42423          	sw	a5,-24(s0)
   100e0:	00c0006f          	j	100ec <main+0x98>
   100e4:	fe042623          	sw	zero,-20(s0)
   100e8:	fe042423          	sw	zero,-24(s0)
   100ec:	fec42783          	lw	a5,-20(s0)
   100f0:	00279793          	slli	a5,a5,0x2
   100f4:	fef42223          	sw	a5,-28(s0)
   100f8:	fe842783          	lw	a5,-24(s0)
   100fc:	00379793          	slli	a5,a5,0x3
   10100:	fef42023          	sw	a5,-32(s0)
   10104:	fe442783          	lw	a5,-28(s0)
   10108:	fe042703          	lw	a4,-32(s0)
   1010c:	fdc42683          	lw	a3,-36(s0)
   10110:	00df7f33          	and	t5,t5,a3
   10114:	00ff6f33          	or	t5,t5,a5
   10118:	00ef6f33          	or	t5,t5,a4
   1011c:	f85ff06f          	j	100a0 <main+0x4c>


```


## LISTS OF INSTRUCTIONS THIS CODE CONTAINS:
To count no of different instruction run python.py code on terminal we will get our list of intructions.

![Screenshot from 2023-10-25 16-47-42](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/d534f327-5cb6-4d33-9433-9392537ec1d2)


```
Number of different instructions: 10
List of unique instructions:
addi
sw
beqz
lw
andi
j
or
slli
and
li





```

## Simulation using spike:

Following commands are used to simulate using spike

```
riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -ffreestanding -o out fire_alarm.c
spike pk out
```
## RESULTS:
When  flag input and sensor both are set to 1 then both led and buzzer should turn on. After performing the masking operation the t5 value is set to 12 (i.e 1100 in binary) as inpi\uts are being masked .
t1 case is when both input and outputs are reset to 0 ,
t2 case is when it entered whie (1) ,
t3 case is when it entered the if case because we set flag to 1 ,
t4 case is obtained when else case is satisfied, in this case we set flame to 1 so we are not entering into it so we are getting 0 ,
t5 case we are getting 12 that means 1100 which tells that are  funtionality is correct as we should get led and buzzer set to 1 and this is what we are getting  ,

hence funtionality is verified




![image(1)](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/2e2770e7-8518-4bb1-a9ac-1cf8914888a2)

flag =0 , so it is not entering into the loop

![image(2)](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/cb963d78-78ab-4779-9fe6-d2494998a003)

flag = 1, flame =0, so we are getting proper output by getting 0 values of led and buzzer. So here we are getting t4 value as it is etering in else loop as flame is set to 0.

![image](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/b6332f0e-9fe3-4edd-86e8-715c141d5319)

flag=1, flame =1, so we are getting proper out by getting 1 values of led and buzzer and here we are getting t5 value to be 12 that is both led and buzzer is on .






## ACKNOWLEDMENT

- Kunal Ghosh, VSD Corp. Pvt. Ltd.
- Mayank Kabra
  


## REFERENCES

- https://github.com/SakethGajawada/RISCV-GNU
- https://www.electronicshub.org/arduino-flame-sensor-interface/
- https://www.moryarduino.com/arduino-project/fire-alarm-using-flame-sensor-arduino
