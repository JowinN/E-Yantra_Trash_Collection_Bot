#include "garbage_detection.h"


int check_line(){
	if(!(Left_black_line<0x42)&&!(Right_black_line<0x42)){
		return 1;
	}
	else{
		return 0;
	}
}

void func_init(void){
	if(!(Left_black_line<0x42)&&!(Right_black_line<0x42)){
		buzzer_on();
		_delay_ms(400);
		buzzer_off();
		_delay_ms(400);
		buzzer_on();
		_delay_ms(400);
		buzzer_off();
		_delay_ms(400);
		buzzer_on();
		_delay_ms(800);
		buzzer_off();
		velocity(200, 200);
		forward();
		flag2 = 1;
		while(Right_black_line > 20 && Center_black_line > 20 && Left_black_line > 20 ){
			Left_black_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
			Center_black_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
			Right_black_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
		}
		_delay_ms(150);
		
	}
	else{
		//while(check_line()==0);
		//_delay_ms(2500);
	}

}

void fnode(){
	
	velocity(speed,speed);
	forward();
	flag2 = 1;
	while(Right_black_line > 20 && Center_black_line > 20 && Left_black_line > 20 ){
		Left_black_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
		Center_black_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
		Right_black_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
	}
	
}

void bit_forward(){
	velocity(speed,speed);
	forward();
	
	while(Right_black_line > 20 && Center_black_line > 20 && Left_black_line > 20 ){
		Left_black_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
		Center_black_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
		Right_black_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
	}
	_delay_ms(145);
}

void node(){
	stop();
	buzzer_on();
	_delay_ms(1000);
	buzzer_off();
	flag2 = 1;
	
}

int node_dust =0;

void choice(int k) {
	switch(k) {
		case 4:
		case 5:
		case 13:
		case 14:
		velocity(speed,speed);
		soft_left_degrees(turning_angle);
		break;

		case 9:
		case 10:
		velocity(speed, speed);
		soft_right_degrees(turning_angle);
		break;

		case 1:
		case 18:
		velocity(speed, speed);
		forward();
		flag2 = 1;
		while(Right_black_line > 20 && Center_black_line > 20 && Left_black_line > 20 ){
			Left_black_line = ADC_Conversion(3);	//Getting data of Left WL Sensor
			Center_black_line = ADC_Conversion(2);	//Getting data of Center WL Sensor
			Right_black_line = ADC_Conversion(1);	//Getting data of Right WL Sensor
		}
		
		break;

		case 8:
		_delay_ms(node_del);
		stop();
		_delay_ms(400);
		if(check_garbage_left()==1){
			oc++;
			node();
			_delay_ms(1000);
		}
		if(check_garbage_right()==1){
			oc++;
			node();
		}
		bit_forward();
		break;
		case 11:
		_delay_ms(node_del);
		stop();
		_delay_ms(400);
		if(check_garbage_right()==1){
			oc++;
			node();
		}
		
		bit_forward();
		
		
		break;
		case 2:
		_delay_ms(node_del);
		stop();
		_delay_ms(400);
		if(check_garbage_left()==1){
			rc++;
			node();
		}
		bit_forward();
		
		break;
		case 3:
		_delay_ms(node_del);
		stop();
		_delay_ms(400);
		if(check_garbage_left()==1){
			rc++;
			node();
		}
		
		bit_forward();
		
		
		break;
		case 7:
		_delay_ms(node_del);
		stop();
		_delay_ms(400);
		if(check_garbage_left()==1){
			rc++;
			node();
			_delay_ms(1000);
		}
		if(check_garbage_right()==1){
			rc++;
			node();
		}
		bit_forward();

		break;
		case 6:
		_delay_ms(node_del);
		stop();
		_delay_ms(400);
		if(check_garbage_left()==1){
			hc++;
			node();
			_delay_ms(1000);
		}
		if(check_garbage_right()==1){
			hc++;
			node();
		}
		bit_forward();
		
		break;
		case 12:
		_delay_ms(node_del);
		stop();
		_delay_ms(400);
		if(check_garbage_right()==1){
			hc++;
			node();
		}
		bit_forward();
		
		
		break;
		case 15:
		stop();
		while(oc-->0){
			buzzer_on();
			_delay_ms(1000);
			buzzer_off();
			_delay_ms(1000);
		}
		fnode();
		break;
		case 16:
		stop();
		while(hc-->0){
			buzzer_on();
			_delay_ms(1000);
			buzzer_off();
			_delay_ms(1000);
		}
		fnode();
		break;
		case 17:
		stop();
		while(rc-->0){
			buzzer_on();
			_delay_ms(1000);
			buzzer_off();
			_delay_ms(1000);
		}
		fnode();
		break;
		case 19:
		stop();
		while(1);
		break;
		default:
		// Handle unexpected values if necessary
		break;
	}
}

