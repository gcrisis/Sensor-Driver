#include<Wire.h>
#include "hmc5883l.h"

void HMC5883L::EnableHMC5883L(){
		Wire.beginTransmission(HMC5883LADDR); //open communication with HMC5883
		Wire.write(MODE); //select mode register
		Wire.write(0x00); //continuous measurement mode
		Wire.endTransmission();
}

void HMC5883L::GetCompassXYZ(){
		Wire.beginTransmission(HMC5883LADDR);
		Wire.write(X_H); //select register 3, X MSB register
		Wire.endTransmission();
		Wire.requestFrom(HMC5883LADDR,6);
		
		while(Wire.available()<6);
		
		compass.x=Wire.read()<<8;
		compass.x|=Wire.read();
		compass.y=Wire.read()<<8;
		compass.y|=Wire.read();
		compass.z=Wire.read()<<8;
		compass.z|=Wire.read();		
		
}