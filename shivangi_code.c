//#include <stdio.h>
void Flame_detected();
void  Flame_monitor();


int main (){
	while(1){
	Flame_detected();
	}
	return 0;
}

void Flame_monitor(){
	int Flame;
	int buzzer =0;
	int buzzer_reg = buzzer *2;
	
	int led = 0;
	int led_reg = led*4;
	
	
        asm volatile(
        "andi %0, x30, 1\n\t"

        :"=r"(Flame)
        :
        :
        );
        
        asm volatile(
	"or x30, x30, %0\n\t" 
	:
	:"r"(buzzer_reg)
	:"x30"
	);
	
	asm volatile(
	"or x30, x30, %0\n\t" 
	:
	:"r"(led_reg)
	:"x30"
	);
	
	while(1){
		if(Flame == 1){
		// Flame = digital_read(0);
		//buzzer = digitalwrite(1);
		// led = digitalwrite(1);
		//printf("Flame is detected");
		buzzer = 1;
		buzzer_reg=buzzer*2;
		
		led=1;
		led_reg=led*4;
		
	  asm volatile(
	"or x30, x30, %0\n\t" 
	:
	:"r"(buzzer_reg)
	:"x30"
	);
          asm volatile(
	  "or x30, x30,%0 \n\t"
          :
	  :"r"(led_reg)
         :"x30"
          );
		
		}
		
	else{
	// Flame= digital_read(1);
	// buzzer= digitalwrite(0);
	//printf("Flame not detected");
	buzzer = 0;
		buzzer_reg=buzzer*2;
		
		led=0;
		led_reg=led*4;
		
	  asm volatile(
	"or x30, x30, %0\n\t" 
	:
	:"r"(buzzer_reg)
	:"x30"
	);
          
          asm volatile(
	  "or x30, x30,%0 \n\t"
          :
	  :"r"(led_reg)
          :"x30"
          );
	
	
		
	}
	}

	
}

void Flame_detected(){
	Flame_monitor();
}
