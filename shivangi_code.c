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

