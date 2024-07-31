#include "adc.h"

// IR Threshold to detect the garbage box
const unsigned char ir_threshold=125;
unsigned char left_ir,right_ir;

//checking left garbage
int check_garbage_left(){
	left_ir=ADC_Conversion(4);
	if(left_ir<ir_threshold){
		return 1;
	}
	else{
		return 0;
	}
}

//checking right garbage
int check_garbage_right(){
	right_ir=ADC_Conversion(8);
	if(right_ir<ir_threshold){
		return 1;
	}
	else{
		return 0;
	}
}