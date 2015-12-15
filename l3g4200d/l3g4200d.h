#ifndef _L3G4200D_H_
#define _L3G4200D_H_
#include "arduino.h"
#define L3G4200DADDR 0X69 //7 bits address

#define	WHO_AM_I		0X0F 		
#define	CTRL_REG1		0X20
#define	CTRL_REG2		0X21
#define	CTRL_REG3		0X22
#define	CTRL_REG4		0X23
#define	CTRL_REG5		0X24
#define	REFERENCE		0X25
#define	OUT_TEMP		0X26
#define	STATUS_REG		0X27
#define	OUT_X_L			0X28
#define	OUT_X_H			0X29
#define	OUT_Y_L			0X2A
#define	OUT_Y_H			0X2B
#define	OUT_Z_L			0X2C
#define	OUT_Z_H			0X2D
#define	FIFO_CTRL_REG	0X2E
#define	FIFO_SRC_REG	0X2F
#define	INT1_CFG		0X30
#define	INT1_SRC		0X31
#define	INT1_TSH_XH		0X32
#define	INT1_TSH_XL		0X33
#define	INT1_TSH_YH		0X34
#define	INT1_TSH_YL		0X35
#define	INT1_TSH_ZH		0X36
#define	INT1_TSH_ZL		0X37
#define INT1_DURATION	0X38

class L3G4200D
{
	public:
		typedef struct vector
		{
			float x, y, z;
		} vector;
		
		vector g; // gyro angular velocity readings

		void enableDefault(void);
		
		void writeReg(byte reg, byte value);
		byte readReg(byte reg);
		
		void read(void);
		
		// vector functions
		static void vector_cross(const vector *a, const vector *b, vector *out);
		static float vector_dot(const vector *a,const vector *b);
		static void vector_normalize(vector *a);
};
#endif
