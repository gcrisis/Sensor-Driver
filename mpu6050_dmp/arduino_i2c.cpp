#include "arduino_i2c.h"
#include<Wire.h>


int arduino_i2c_write(uint8_t slave_addr,
                     uint8_t reg_addr,
                     unsigned char num,
                     uint8_t const *data)
{
	 if (!num)
        return 0;
	Wire.beginTransmission(slave_addr);
	Wire.write(reg_addr);
	for(unsigned char i=0;i<num;i++)
		Wire.write(*(data+i));
	Wire.endTransmission();
	
	return 0;
}

int arduino_i2c_read(unsigned char slave_addr,unsigned char reg_addr,unsigned char num,unsigned char *data)               
{
	if (!num)
        return 0;
	Wire.beginTransmission(slave_addr);
	Wire.write(reg_addr);
	Wire.endTransmission();
	
	Wire.requestFrom(slave_addr, num);
	while(Wire.available()<num);
	
	for(unsigned char i=0;i<num;i++){
		*(data+i)=Wire.read();
	}
	return 0;
}
/*
void arduino_delay_ms(unsigned int ms){
	  delay(ms);
}
void arduino_get_clock_ms(unsigned long *count){
	*count=millis();
}
*/

