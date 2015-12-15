#ifndef _BMP085_H_
#define _BMP085_H_

#include <arduino.h>

#define BMP085ADDR 0x77	//7 bits address

#define	AC1		0XAA
#define AC1_H	0XAA
#define AC1_L	0XAB
#define	AC2		0XAC
#define	AC2_H	0XAC	
#define	AC2_L	0XAD
#define	AC3		0XAE
#define	AC3_H	0XAE
#define	AC3_L	0XAF
#define	AC4		0XB0
#define	AC4_H	0XB0
#define	AC4_L	0XB1
#define	AC5		0XB2
#define	AC5_H	0XB2
#define	AC5_L	0XB3
#define	AC6		0XB4	
#define	AC6_H	0XB4
#define	AC6_L	0XB5
#define	B1		0XB6
#define	B1_H	0XB6
#define	B1_L	0XB7
#define	B2		0XB8
#define	B2_H	0XB8
#define	B2_L	0XB9
#define	MB		0XBA
#define	MB_H	0XBA
#define	MB_L	0XBB
#define	MC		0XBC
#define	MC_H	0XBC
#define	MC_L	0XBD
#define	MD		0XBE
#define	MD_H	0XBE
#define	MD_L	0XBF
#define CTL		0XF4
#define	MSB		0XF6
#define	LSB		0XF7
#define	XLSB	0XF8
const unsigned char OSS=0;

class BMP085 {
	private:
	// Calibration values
		int 			ac1;
		int 			ac2; 
		int 			ac3; 
		unsigned int 	ac4;
		unsigned int 	ac5;
		unsigned int 	ac6;
		int 			b1; 
		int 			b2;
		int 			mb;
		int 			mc;
		int 			md;
		long 			b5; 
		
		unsigned int 	ReadUT();
		unsigned long 	ReadUP();
		int 			Read2Reg(unsigned char address);
	public:
		void 	GetCalParam();
		short	GetTemperature();
		long 	GetPressure();
	
};
#endif
