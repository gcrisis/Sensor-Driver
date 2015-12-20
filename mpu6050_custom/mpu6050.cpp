#include<Wire.h>
#include "mpu6050.h"

void MPU6050::GetAccelXYZ(){
		Wire.beginTransmission(MPU6050ADDR);
		Wire.write(ACCEL_XOUT_H); //select register 3, X MSB register
		Wire.endTransmission();
		Wire.requestFrom(MPU6050ADDR,6);
		
		while(Wire.available()<6);
		
		accel.x=Wire.read()<<8;
		accel.x+=Wire.read();
		accel.y=Wire.read()<<8;
		accel.y+=Wire.read();
		accel.z=Wire.read()<<8;
		accel.z+=Wire.read();	
		accel.x=(short)accel.x/32768.0*16;
		accel.y=(short)accel.y/32768.0*16;
		accel.z=(short)accel.z/32768.0*16;
		
}

void MPU6050::GetGyroXYZ(){
		Wire.beginTransmission(MPU6050ADDR);
		Wire.write(GYRO_XOUT_H); //select register 3, X MSB register
		Wire.endTransmission();
		Wire.requestFrom(MPU6050ADDR,6);
		
		while(Wire.available()<6);
		
		gyro.x=Wire.read()<<8;
		gyro.x+=Wire.read();
		gyro.y=Wire.read()<<8;
		gyro.y+=Wire.read();
		gyro.z=Wire.read()<<8;
		gyro.z+=Wire.read();	
		gyro.x=(short)gyro.x/32768.0*2000;
		gyro.y=(short)gyro.y/32768.0*2000;
		gyro.z=(short)gyro.z/32768.0*2000;
	
}

void MPU6050::GetTemperature(){
		Wire.beginTransmission(MPU6050ADDR);
		Wire.write(TEMP_OUT_H); 
		Wire.endTransmission();
		Wire.requestFrom(MPU6050ADDR,2);
		
		while(Wire.available()<2);
		
		temperature=Wire.read()<<8;
		temperature+=Wire.read();
		temperature=(short)temperature/340.0+36.25;
}
void MPU6050::temp(){
	
}
