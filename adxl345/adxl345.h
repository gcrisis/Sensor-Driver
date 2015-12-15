#ifndef _ADXL345_H_
#define _ADXL345_H_

#define ADXL345ADDR    	0x53 //7 bits address

#define DEVID       	0x00
#define THRESH_TAP  	0X1D
#define OFSX	    	0X1E
#define OFSY			0X1F
#define OFSZ			0X20
#define	DUR				0X21
#define	LATENT			0X22
#define	WINDOW			0X23
#define	THRESH_ACT		0X24
#define	THRESH_INACT	0X25
#define	TIME_INACT		0X26
#define	ACT_INACT_CTL	0X27
#define	THRESH_FF		0X28
#define	TIME_FF			0X29
#define	TAP_AXES		0X2A
#define	ACT_TAP_STATUS	0X2B
#define	BW_RATE			0X2C
#define	POWER_CTL		0X2D
#define	INT_ENABLE		0X2E
#define	INT_MAP			0X2F
#define	INT_SOURCE		0X30
#define	DATA_FORMAT		0X31
#define	DATAX0			0X32
#define	DATAX1			0X33
#define	DATAY0			0X34
#define	DATAY1			0X35
#define	DATAZ0			0X36
#define	DATAZ1			0X37
#define	FIFO_CTL		0X38
#define	FIFO_STATUS		0X39

class ADXL345{
	typedef struct vector{
		double x,y,z;
	}vector;
	
	private:
		
	public:
		vector accel;
		void EnableAdxl345();
		void GetAccelXYZ();
};
#endif	
