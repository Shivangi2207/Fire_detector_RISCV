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
![WhatsApp Image 2023-10-27 at 16 36 17](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/b77212e5-7cf1-452d-9be1-f128d13f84cf)



## CIRCUIT DIAGRAM

![Screenshot from 2023-10-04 23-37-50](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/aada2bbe-fe30-4125-99a3-76b8dcacef66)


## GPIO
x30[0] is an input pin to reset the device if it is 1 only then our device will work.

x30[1] is an input pin to detect flame from flame sensor.

x30[2] is an output pin used to indicate about the  flame detection using buzzer.

x30[3] is an output pin used to indicate about the flame detection using led.


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
	
	 

         //flag = 1;
      if (flag) {

              //flame = digital_read(0);

              printf("entered if case \n");

             

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
 

              //flame=0;
	        if(flame==0){
             
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
   100a8:	fd842783          	lw	a5,-40(s0)
   100ac:	fe078ae3          	beqz	a5,100a0 <main+0x4c>
   100b0:	002f7793          	andi	a5,t5,2
   100b4:	fcf42a23          	sw	a5,-44(s0)
   100b8:	fd442783          	lw	a5,-44(s0)
   100bc:	00079c63          	bnez	a5,100d4 <main+0x80>
   100c0:	00100793          	li	a5,1
   100c4:	fef42623          	sw	a5,-20(s0)
   100c8:	00100793          	li	a5,1
   100cc:	fef42423          	sw	a5,-24(s0)
   100d0:	00c0006f          	j	100dc <main+0x88>
   100d4:	fe042623          	sw	zero,-20(s0)
   100d8:	fe042423          	sw	zero,-24(s0)
   100dc:	fec42783          	lw	a5,-20(s0)
   100e0:	00279793          	slli	a5,a5,0x2
   100e4:	fef42223          	sw	a5,-28(s0)
   100e8:	fe842783          	lw	a5,-24(s0)
   100ec:	00379793          	slli	a5,a5,0x3
   100f0:	fef42023          	sw	a5,-32(s0)
   100f4:	fe442783          	lw	a5,-28(s0)
   100f8:	fe042703          	lw	a4,-32(s0)
   100fc:	fdc42683          	lw	a3,-36(s0)
   10100:	00df7f33          	and	t5,t5,a3
   10104:	00ff6f33          	or	t5,t5,a5
   10108:	00ef6f33          	or	t5,t5,a4
   1010c:	f95ff06f          	j	100a0 <main+0x4c>





```


## LISTS OF INSTRUCTIONS THIS CODE CONTAINS:
To count no of different instruction run python.py code on terminal we will get our list of intructions.

![Screenshot from 2023-10-27 15-56-02](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/3f555b59-8e73-484a-b044-7ee6814d726d)


```
Number of different instructions: 11
List of unique instructions:
addi
slli
sw
beqz
or
li
j
lw
bnez
andi
and






```

## Simulation using spike:

Following commands are used to simulate using spike

```
riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -ffreestanding -o out fire_alarm.c
spike pk out
```
## RESULTS:
When  flag input and sensor both are set to 1 and 0 respectively then both led and buzzer should turn on. After performing the masking operation the t5 value is set to 12 (i.e 1100 in binary) as inputs are being masked .
t1 case is when both input and outputs are reset to 0 ,
t2 case is when it entered whie (1) ,
t3 case is when it entered the if case because we set flag to 1 ,
t4 case is obtained when else case is satisfied, in this case we set flame to 1 so we are not entering into it so we are getting 0 ,
t5 case we are getting 12 that means 1100 which tells that are  funtionality is correct as we should get led and buzzer set to 1 and this is what we are getting  ,

hence funtionality is verified




![image](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/d5171f16-867f-4309-b51a-afa87fc4fdf8)


flag =0 , so it is not entering into the loop

![image](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/742098c0-fffe-4ef8-b38d-b3a00439f1d3)


flag = 1, flame =1, so we are getting proper output by getting 0 values of led and buzzer. So here we are getting t4 value as it is etering in else loop as flame is set to 0.

![image](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/b1d6e349-9988-4f9d-a77d-6e3440c95eb5)



flag=1, flame =0, so we are getting proper out by getting 1 values of led and buzzer and here we are getting t5 value to be 12 that is both led and buzzer is on .


## Functional Simulation:

After spike simulation I have done functionality simulation using GTKWave and matched the output for different combination of inputs with the desired outputs.
For INPUTS flag = 1 and flame =0 (i.e 01) OUTPUTS should be 11 that means flame sensor detected fire and led and buzzer turn on (i.e 11).

![Screenshot from 2023-10-28 10-46-22](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/b5b374fa-28ed-46f8-aac6-352daa21e4ef)


For INPUT 10 OUTPUT should be 00

![Screenshot from 2023-10-28 10-52-51](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/1ef36ee7-76c2-4e0e-990f-0618ddd0af30)

For INPUT 00 OUTPUT should be 00
![Screenshot from 2023-10-28 10-51-02](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/1f64f1e6-c865-406b-b4f0-0b9d63d3a0e6)



For INPUT 11 OUTPUTS should be 00

![Screenshot from 2023-10-28 10-41-52](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/62707ce8-bad9-485e-ad2f-933b3d822929)


## Verification of instruction:

The very first instruction of my assembly code is addi	sp,sp,-48 .The assembly language instruction "addi sp, sp, -48" in the RISC-V architecture subtracts 48 from the stack pointer (sp), effectively reserving 48 bytes of space on the stack for local variables or other data within a function. This is a common operation at the beginning of a function to set up a stack frame, and it's typically followed by a corresponding "addi sp, sp, 48" instruction at the end of the function to release the allocated space when the function call is finished.

![Screenshot from 2023-10-31 18-37-14](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/4c48ff75-e32f-45bf-8cd3-71545549f8f8)

Next we have slli a5,a5,0x2


![Screenshot from 2023-10-31 18-41-50](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/76d3f0b2-ec97-45b7-a783-1740278f9fed)

Next we have "002f7793" andi a5,t5,2

![Screenshot from 2023-11-02 22-49-05](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/a9437e22-3403-48a2-8ec5-04847e0916a8)


At every "f95ff06f" instruction output is updated to 11 i.e J operation

![Screenshot from 2023-11-02 22-41-23](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/8bebb3a5-8304-4001-ae55-6b2b707dea3d)

At every   "00ff6f33"   instruction output is resetting to 00  i.e   or t5,t5,a5 instruction is being performed

![Screenshot from 2023-11-02 22-50-42](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/6443894d-a69f-4cad-8150-8d1f5c7a97b4)


## Gate Level Simulation (GLS)

In GLS i have used "sky130_fd_sc_hd__tt_025C_1v80_256.lib" library which is been integrated with sram cell. To generate the netlist following commands are used.

```
$ yosys
yosys> read_liberty -lib lib/sky130_fd_sc_hd__tt_025C_1v80_256.lib
yosys> read_verilog processor.v
yosys> synth -top wrapper
yosys> dfflibmap -liberty lib/sky130_fd_sc_hd__tt_025C_1v80_256.lib
yosys> abc -liberty lib/sky130_fd_sc_hd__tt_025C_1v80_256.lib
yosys> write_verilog synth_asic.v


```

![Screenshot from 2023-10-31 12-46-26](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/0c7829a2-285b-4eb3-a97b-1ada4afa27fc)

In the above figure we can see that 2 SRAM Cells is mapped into the netlist. to validate the UART functionality in this netlist, we ensure that in the "processor.v" file, the variable "writing_inst_done" is set to 1 to exclude the UART module during simulation, followed by the following steps:
```
$ yosys
yosys> read_liberty -lib lib/sky130_fd_sc_hd__tt_025C_1v80_256.lib
yosys> read_verilog processor.v
yosys> synth -top wrapper
yosys> dfflibmap -liberty lib/sky130_fd_sc_hd__tt_025C_1v80_256.lib
yosys> abc -liberty lib/sky130_fd_sc_hd__tt_025C_1v80_256.lib
yosys> write_verilog synth_test.v

```
This will create the functionality for uart.

Now to verify the functionality of GLS we will run following command.

```
iverilog -o test testbench.v synth_test.v sky130_sram_1kbyte_1rw1r_32x256_8.v sky130_fd_sc_hd.v primitives.v
./test
gtkwave waveform.vcd &

```

## CASE 1: when INPUTS are 01 then output will be 11

![Screenshot from 2023-10-31 18-05-09](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/4f615f71-01c4-46e5-8d02-f951185b6550)

## CASE 2: when INPUTS are 11 the output will be 00

![Screenshot from 2023-10-31 18-09-32](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/5da8bf8e-d8fd-4e12-8ab0-07aa1c7268b5)

## CASE 3: when INPUTS are 10 the output will be 00

![Screenshot from 2023-10-31 18-12-53](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/b3d285f3-661f-4487-a056-c4a10bfb2e42)

## CASE 3: when INPUTS are 00 the output will be 00


![Screenshot from 2023-10-31 18-15-07](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/da045c49-9c52-4ddb-97a3-c95c391f8897)

# PHYSICAL DESIGN:


![Screenshot from 2023-11-14 23-00-18](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/0edc9767-612f-45e3-a550-65ed7997ffe7)


 - Synthesis:
        Generate gate-level netlist using Yosys.
        Perform cell mapping with ABC.
        Conduct pre-layout static timing analysis using OpenSTA.

  - Floorplanning:
        Define core area, cell sites, and tracks with init_fp.
        Place macro input and output ports using ioplacer.
        Generate power distribution network (pdn).

  - Placement:
        Execute global placement with RePLace.
        Perform detailed placement for component legalization using OpenDP.

   - Clock Tree Synthesis (CTS):
        Synthesize the clock tree with TritonCTS.

  -  Routing:
        Conduct global routing to generate a guide file for the detailed router with FastRoute.
        Perform detailed routing using TritonRoute.

  -  GDSII Generation:
        Stream out the final GDSII layout file from the routed DEF using Magic.


# OpenLane:
OpenLane is an automated RTL to GDSII flow based on several components including OpenROAD, Yosys, Magic, Netgen, CVC, SPEF-Extractor, KLayout and a number of custom scripts for design exploration and optimization. The flow performs all ASIC implementation steps from RTL all the way down to GDSII.
- https://github.com/The-OpenROAD-Project/OpenLane

# MAGIC:

Magic is a popular open-source VLSI (Very Large Scale Integration) layout tool used in ASIC (Application-Specific Integrated Circuit) design. It is primarily employed for the physical design phase, allowing engineers to create, edit, and analyze the layout of integrated circuits. Here are some key aspects of the Magic tool in ASIC design:
-  Layout Editing:
        Magic is an open-source tool used for creating and editing the physical layout of integrated circuits during the ASIC design process.

-  GDSII Support:
        It supports the GDSII file format, facilitating the import and export of layouts, which is essential for compatibility with other design tools and manufacturing processes.

-  Design Rule Checking (DRC):
        Magic includes DRC features, allowing designers to check if the layout adheres to specified design rules and constraints, ensuring manufacturability.

-  LVS Checks:
        The tool supports Layout versus Schematic (LVS) checks, helping verify the consistency between the physical layout and the intended circuit schematic.

  - Open-Source Nature:
        Magic is open-source, fostering a collaborative community and enabling customization and extension of its functionality.

## Preparing Design

First we make a separate folder of our design in the Openlane folder and include all the neccessary files in the folder named src and also add confic.jason files and make the changes accourding to our code.
now in terminal go to the Openlane directory and run following code. 

```
make mount
%./flow.tcl -interactive
% package require openlane 0.9
% prep -design project -verbose 99


```
![Screenshot from 2023-11-14 20-59-02](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/95473c30-143a-43d2-823d-45a113604e8a)

## SYNTHESIS
The primary goal of synthesis is to convert the abstract description of a digital circuit into a netlist, which is a list of logic gates and their interconnections.

To synthesize the code run the following command.

```
run_synthesis
```
![Screenshot from 2023-11-14 21-00-02](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/6f5aec04-8580-4571-81ab-3177627de148)

Statistics after synthesis:


![Screenshot from 2023-11-14 22-00-52](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/933fbc08-bda7-40cc-aa9c-7c89e43e897b)

# Floorplan:

Floorplan includes determining the core area where major functional blocks will be placed, setting up cell sites and tracks for routing, and strategically positioning input and output ports for efficient connectivity. The floorplan serves as a blueprint for the physical implementation of the design, taking into account factors like power distribution and signal integrity. Effective floorplanning in ASIC design helps optimize the layout for performance, minimize signal delays, and adhere to design constraints such as area and power specifications. This initial layout plan provides a foundation for subsequent stages in the ASIC design flow, including placement, routing, and ultimately, the generation of the final GDSII layout for fabrication.


Commands to run floorplan

```
run_floorplan
```
Post the floorplan run, a .def file will have been created within the results/floorplan directory. We may review floorplan files by checking the floorplan.tcl.


![Screenshot from 2023-11-14 21-00-35](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/392fce02-6627-4586-a607-e1155a1db9a0)


Commands to invoke magic

```
magic -T /home/shivangi/OpenLane/vsdstdcelldesign/libs/sky130A.tech lef read /home/shivangi/OpenLane/designs/processor_designs/runs/RUN_2023.11.14_14.01.41/tmp/merged.nom.lef def read /home/shivangi/OpenLane/designs/processor_designs/runs/RUN_2023.11.14_14.01.41/results/floorplan/wrapper.def &

```

![Screenshot from 2023-11-14 21-16-53](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/0333fc24-8001-48fd-8b62-a93b6de363dd)

## Die area (Post floorplan)
![Screenshot from 2023-11-14 22-07-19](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/271d931f-99aa-451b-bfc5-b5ef1f2f8ee0)

## Core area (post floorplan)

![Screenshot from 2023-11-14 22-07-37](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/d4a54967-6486-4c75-84b4-883ada3ed3f0)

# Placement:



- Global placement, also known as initial placement or coarse placement, aims to establish a rough placement of logical elements (cells) on the chip's layout canvas. The primary objective of global placement is to get an approximate positioning of cells before fine-tuning them in the detailed placement stage.

- Detailed placement, often referred to as legalization and optimization, is the stage where the rough placement from global placement is refined to meet specific design objectives and constraints more accurately.


```
run_placement
```

![Screenshot from 2023-11-14 21-00-49](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/f2ef7f6f-5f51-44cb-87d3-b21a16ea815e)

The design can be viewed on magic within results/placement directory:

Magic command
```
magic -T /home/shivangi/OpenLane/vsdstdcelldesign/libs/sky130A.tech lef read /home/shivangi/OpenLane/designs/processor_designs/runs/RUN_2023.11.14_14.01.41/tmp/merged.nom.lef def read /home/shivangi/OpenLane/designs/processor_designs/runs/RUN_2023.11.14_14.01.41/results/placement/wrapper.def &

```

![Screenshot from 2023-11-14 21-20-00](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/14bebe61-2605-4440-8be2-9a75f587e723)

# CTS:

Clock tree synteshsis is used to create the clock distribution network that is used to deliver the clock to all sequential elements. The main goal is to create a network with minimal skew across the chip. H-trees are a common network topology that is used to achieve this goal.
As a result, CTS is used to balance the skew and reduce insertion latency. Before Clock Tree Synthesis, all clock pins were driven by a single clock source. Clock tree synthesis includes both clock tree construction and clock tree balance.Clock tree inverters may be used to create a clock tree that maintains the correct transition (duty cycle), and clock tree buffers (CTB) can balance the clock tree to fulfill the skew and latency requirements.

```
run_cts
```
![Screenshot from 2023-11-14 21-00-58](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/523b3d2e-c9dd-4fdf-b3df-0dbd7a5ef0f4)

## Timing report:

![image](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/4924b63b-dc2d-4eaf-b3cb-0757ac535c34)




## Area report:
![image](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/0432c0fb-57d1-4e68-8595-c0f2de36b496)



## Skew report:
![image](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/e564f49e-43b3-4a9f-9a60-469b6a00d5d3)



## Power report:

![image](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/20b3fc07-3119-41b4-8bc2-db8e74337d68)



# ROUTING:
Routing refers to the process of determining and establishing the physical paths that connect various components and interconnects within the chip. This step follows the placement phase in the design flow. During routing, the goal is to create a network of wires or metal traces to establish connections between different functional blocks, such as logic gates, memory cells, and other elements.

There are typically two main types of routing:

- Global Routing:
        In this phase, high-level connections between major blocks or regions of the chip are established. Global routing defines the overall paths and general connectivity.

- Detailed Routing:
        Once the global routes are established, detailed routing is performed to finalize the specific paths of the connections, considering the available resources, signal timing, and avoiding any design rule violations.
```
run_routing
```
![Screenshot from 2023-11-30 00-04-18](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/0746e113-450e-4a73-8197-d72d98b45548)

```
magic -T /home/shivangi/OpenLane/vsdstdcelldesign/libs/sky130A.tech lef read /home/shivangi/OpenLane/designs/processor_designs/runs/RUN_2023.11.14_14.01.41/tmp/merged.nom.lef def read /home/shivangi/OpenLane/designs/processor_designs/runs/RUN_2023.11.14_14.01.41/results/routing/wrapper.def &

```

## Layout after routing:

![Screenshot from 2023-11-14 21-21-31](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/82e2c61b-e2ff-4201-b758-94b0b91ff64f)


![Screenshot from 2023-11-14 21-22-50](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/83f6a0ce-b32e-406d-bd5e-09e29be29961)

## Area of design:


![Screenshot from 2023-11-14 21-24-09](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/c68de762-2dc7-4b26-a333-7bcf26460fa1)

## Post_routing Timing Reports:

![image](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/5238b8c1-a265-4213-a107-5986d4f0a69d)

![image](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/2ab0c88a-a669-45a9-bd8c-fe0f3e6d3b6f)



## Post_routing Area Reports

![image](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/40896907-9c39-46ec-8b74-cc9fa91ef2c9)



## Post_routing Power Reports
![image](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/a6b618fe-0400-49b1-832a-7d7feb3a2eca)



## Here drc violation is zero:

![image](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/eb27cd44-ddab-4de3-ad84-2606fa9d0dc5)



# Performance Calculation:

Given a Clock period of 40ns in Json file , setup slack we got after routing is 8.87ns
```
                              1
Max Performance =  ------------------------
                     clock period - slack(setup)

```
```
Max Performance = 0.0321 Ghz

```

# EXTRAS:



![image](https://github.com/Shivangi2207/Fire_detector_RISCV/assets/140998647/f0e2899a-2145-4cec-840b-e90a0fa49883)


# OpenLane Interactive Flow:

```
cd Desktop/OpenLane/ 

./flow.tcl -interactive
package require openlane 0.9
prep -design picorv32a
run_synthesis
run_floorplan
run_placement
run_cts
gen_pdn
run_routing
run_magic
run_magic_spice_export
run_magic_drc
run_antenna_check


```

## ACKNOWLEDMENT

- Kunal Ghosh, VSD Corp. Pvt. Ltd.
- Mayank Kabra (Founder, Chipcron Pvt. Ltd.)
  


## REFERENCES

- https://github.com/SakethGajawada/RISCV-GNU
- https://github.com/The-OpenROAD-Project/OpenLane
  
- https://www.electronicshub.org/arduino-flame-sensor-interface/
- https://www.moryarduino.com/arduino-project/fire-alarm-using-flame-sensor-arduino
