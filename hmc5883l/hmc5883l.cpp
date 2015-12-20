#include<Wire.h>
#include<Math.h>
#include<Arduino.h>
#include "hmc5883l.h"

/*  初始化配置：
 *   寄存器A：平均采样数、连续模式输出速率、测量配置
 *   寄存器B：增益
 *   寄存器MODE：传感器模式[连续、单次、空闲]
*/
bool HMC5883L::EnableHMC5883L(){
		Wire.beginTransmission(HMC5883LADDR); //open communication with HMC5883
		Wire.write(CRA);  //
		Wire.write(0x70);
    Wire.write(0x20);//
    Wire.write(0x00); //continuous measurement mode
		Wire.endTransmission();
   return true;
}
/*  读取XYZ原始值
 *   ！！！注意读取顺序x->z->y
*/
bool HMC5883L::GetCompassXYZ(){
		Wire.beginTransmission(HMC5883LADDR);
		Wire.write(X_H); //select register 3, X MSB register
		Wire.endTransmission();
		Wire.requestFrom(HMC5883LADDR,6);
		
		while(Wire.available()<6);
		
		compass.x=Wire.read()<<8;
		compass.x|=Wire.read();
		compass.z=Wire.read()<<8;
		compass.z|=Wire.read();
		compass.y=Wire.read()<<8;
		compass.y|=Wire.read();		
		return true;
}
/*  计算方向(与x轴的夹角，x轴指向南为正)
 *  ！！！此方法计算的指向不准确，没有考虑倾斜和地磁偏角，也没有考虑测量值的偏差，后续改进。
*/
bool HMC5883L::GetHeading(){
   heading = atan2((double)compass.y,(double)compass.x);
  // Correct for when signs are reversed.
  if(heading < 0)
    heading += 2*PI;
 
  heading = heading * 180/PI;
 // headingDegrees += MagnetcDeclination; the magnetc-declination angle 

  return true;
}
/*HMC5883L的自测，具体还不知道怎么用，预留
 * 
*/
bool HMC5883L::SelfTest(){
  return true;
  }
