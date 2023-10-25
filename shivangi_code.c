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
  

  

          
