#define F_CPU 14745600
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

const int node_del = 110;
const int speed =255;
const int cor_speed =210;
const int c_speed =73;
const int turning_angle = 77;
unsigned char ADC_Value;
const int threshold = 30;
unsigned char Left_black_line = 0;
unsigned char Center_black_line = 0;
unsigned char Right_black_line = 0;
int flag2 = 0; // indicates that the robo is on node and node detection is completed

volatile unsigned long int ShaftCountLeft = 0; //to keep track of left position encoder
volatile unsigned long int ShaftCountRight = 0; //to keep track of right position encoder
volatile unsigned int Degrees; //to accept angle in degrees for turning


int oc,rc,hc;
oc=0;
rc=0;
hc=0;

#include "lcd.h"
#include "utility.h"
#include "buzzer.h"
#include "motion.h"
#include "interrupt.h"
#include "pwm.h"




//Function to initialize ports
void port_init()
{
	adc_pin_config();
	motion_pin_config(); //robot motion pins config
	left_encoder_pin_config(); //left encoder pin config
	right_encoder_pin_config(); //right encoder pin config
	buzzer_pin_config();
}
			
//ISR for right position encoder
ISR(INT5_vect)
{
	ShaftCountRight++;  //increment right shaft position count
}


//ISR for left position encoder
ISR(INT4_vect)
{
	ShaftCountLeft++;  //increment left shaft position count
}

void print_sensor(char row, char coloumn,unsigned char channel)
{
	
	ADC_Value = ADC_Conversion(channel);
	lcd_print(row, coloumn, ADC_Value, 3);
}

//Function to initialize all the devices
void init_devices()
{
	cli(); //Clears the global interrupt
	port_init();  //Initializes all the ports
	left_position_encoder_interrupt_init();
	right_position_encoder_interrupt_init();
	timer5_init();
	adc_init();
	sei();   // Enables the global interrupt
}

int main()
{
	init_devices();
	lcd_set_4bit();
	lcd_init();
	Left_black_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
	Center_black_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
	Right_black_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
	lcd_print(2,1,Left_black_line,3);
	lcd_print(2,4,Center_black_line,3);
	lcd_print(2,9,Right_black_line,3);
	func_init();
	int ncntr=0;
	while(1)
	{

		Left_black_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
		Center_black_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
		Right_black_line = ADC_Conversion(1);	//Getting data of Right WL Sensor

		lcd_print(1,1,oc,3);
		lcd_print(1,4,hc,3);
		lcd_print(1,9,rc,3);
		
		int flag1 = 0;
		if((Center_black_line > 0x20) && ((Left_black_line<0x42)&&(Right_black_line<0x42)))
		{
			forward();
			velocity(speed, speed);
			flag1 = 1;
			if (flag2 == 1)
			{
				//_delay_ms(500);
				flag2 = 0;
			}
		} 
		
		/*
		else if(Right_black_line > 20 && Center_black_line > 20 && Left_black_line < 20){
			stop();
			velocity(170,170);
			back();
			_delay_ms(600);
			velocity(170,170);
			right();
			_delay_ms(300);
			//forward();
			//velocity(speed,speed);
		}
		
		else if(Left_black_line > 20 && Center_black_line > 20 && Right_black_line < 20){
			stop();
			velocity(170,170);
			back();
			_delay_ms(500);
			velocity(170,170);
			left();
			_delay_ms(300);
			//forward();
			//velocity(speed,speed);
		}*/
		
		else if(Right_black_line > threshold && Center_black_line > threshold && Left_black_line < threshold){
			velocity(195,195);
			soft_right_2();
			
		}
		
		else if(Left_black_line > threshold && Center_black_line > threshold && Right_black_line < threshold){
			velocity(195,195);
			soft_left_2();
		}
		
		
		else if (Right_black_line >= threshold && Left_black_line < threshold && Center_black_line < 60 )
		{
			forward();
			velocity(cor_speed, c_speed);
		} else if (Right_black_line < threshold && Left_black_line >= threshold && Center_black_line < 60)
		{
			forward();
			velocity(c_speed, cor_speed);
		}
		
		if (Right_black_line > threshold && Center_black_line > threshold && Left_black_line > threshold && flag2 == 0)
		{	velocity(speed,speed);
			forward();
			ncntr++;
			//stop();
			//buzzer_on();
			//_delay_ms(1000);
			//buzzer_off();
			// forward_mm(); // move robot by some distance
			choice(ncntr);
			
		}
	}
}
