#include "adxl345.h"
#include <Wire.h>

uint8_t ADXL345::GetID(){
	Wire.beginTransmission(ADXL345ADDR);
	Wire.write(DEVID); 
	Wire.endTransmission();
	Wire.requestFrom(ADXL345ADDR, 1);

	while (Wire.available() < 1);
	return Wire.read();
}
void ADXL345::EnableADXL345(){
		Wire.beginTransmission(ADXL345ADDR);
		Wire.write(POWER_CTL);
		Wire.write(8);                //measuring enable
		Wire.endTransmission();     // stop transmitting
}

void ADXL345::GetAccelXYZ(){
	Wire.beginTransmission(ADXL345ADDR);
	Wire.write(DATAX0); 
	Wire.endTransmission();
	Wire.requestFrom(ADXL345ADDR, 6);

	while (Wire.available() < 6);
	uint8_t x0=Wire.read();
	uint8_t x1=Wire.read();
	uint8_t y0=Wire.read();
	uint8_t y1=Wire.read();
	uint8_t z0=Wire.read();
	uint8_t z1=Wire.read();
	
	accel.x=(x1<<8|x0)/256.0;
	accel.y=(y1<<8|y0)/256.0;
	accel.z=(z1<<8|z0)/256.0;
}
