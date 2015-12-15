#ifndef _HMC5883L_H_
#define _HMC5883L_H_

#define HMC5883LADDR 0x1E //7 bits address

#define CRA 	0x00
#define CRB 	0x01
#define MODE 	0x02
#define X_H 	0x03
#define X_L 	0x04
#define Z_H		0x05
#define Z_L 	0x06
#define Y_H 	0x07
#define Y_L 	0x08
#define STATUS 	0x09
#define IRA 	0x0A
#define IRB 	0x0B
#define IRC 	0x0C

class HMC5883L{
	typedef struct vector{
		int x,y,z;
	}vector;
	private:
	
	public:
		vector compass;
		void EnableHMC5883L();
		void GetCompassXYZ();
};
#endif