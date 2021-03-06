#ifndef _MPU6050_H_
#define _MPU6050_H_

#define MPU6050ADDR 0x68  //7 bits address

#define SELF_TEST_X  0x0d
#define SELF_TEST_Y  0x0e
#define SELF_TEST_Z  0x0f
#define SELF_TEST_A  0x10
#define SMPLRT_DIV   0x19
#define CONFIG       0X1A
#define GYRO_CONFIG  0X1B
#define ACCEL_CONFIG 0X1C
#define FIFO_EN      0X23
#define I2C_MST_CTRL 0X24
#define I2C_SLV0_ADDR 0X25
#define I2C_SLV0_REG 0X26
#define I2C_SLV0_CTRL 0X27
#define I2C_SLV1_ADDR 0X28
#define I2C_SLV1_REG 0X29
#define I2C_SLV1_CTRL 0X2A
#define I2C_SLV2_ADDR 0X2B
#define I2C_SLV2_REG 0X2C
#define I2C_SLV2_CTRL 0X2D
#define I2C_SLV3_ADDR 0X2E
#define I2C_SLV3_REG 0X2F
#define I2C_SLV3_CTRL 0X30
#define I2C_SLV4_ADDR 0X31
#define I2C_SLV4_REG 0X32
#define I2C_SLV4_DO   0X33
#define I2C_SLV4_CTRL 0X34
#define I2C_SLV4_DI   0X35
#define I2C_MST_STATUS 0X36
#define INT_PIN_CFG   0X37
#define INT_ENABLE    0X38
#define INT_STATUS   0X3A
#define ACCEL_XOUT_H  0X3B
#define ACCEL_XOUT_L 0X3C
#define ACCEL_YOUT_H 0X3D
#define ACCEL_YOUT_L 0X3E
#define ACCEL_ZOUT_H 0X3F
#define ACCEL_ZOUT_L 0X40
#define TEMP_OUT_H  0X41
#define TEMP_OUT_L 0X42
#define GYRO_XOUT_H  0X43
#define GYRO_XOUT_L 0X44
#define GYRO_YOUT_H 0X45
#define GYRO_YOUT_L 0X46
#define GYRO_ZOUT_H 0X47
#define GYRO_ZOUT_L 0X48
#define EXT_SENS_DATA_00 0X49
#define EXT_SENS_DATA_01 0X4A
#define EXT_SENS_DATA_02 0X4B
#define EXT_SENS_DATA_03 0X4C
#define EXT_SENS_DATA_04 0X4D
#define EXT_SENS_DATA_05 0X4E
#define EXT_SENS_DATA_06 0X4F
#define EXT_SENS_DATA_07 0X50
#define EXT_SENS_DATA_08 0X51
#define EXT_SENS_DATA_09 0X52
#define EXT_SENS_DATA_10 0X53
#define EXT_SENS_DATA_11 0X54
#define EXT_SENS_DATA_12 0X55
#define EXT_SENS_DATA_13 0X56
#define EXT_SENS_DATA_14 0X57
#define EXT_SENS_DATA_15 0X58
#define EXT_SENS_DATA_16 0X59
#define EXT_SENS_DATA_17 0X5A
#define EXT_SENS_DATA_18 0X5B
#define EXT_SENS_DATA_19 0X5C
#define EXT_SENS_DATA_20 0X5D
#define EXT_SENS_DATA_21 0X5E
#define EXT_SENS_DATA_22 0X5F
#define EXT_SENS_DATA_23 0X60
#define I2C_SLV0_DO 0X63
#define I2C_SLV1_DO 0X64
#define I2C_SLV2_DO 0X65
#define I2C_SLV3_DO 0X66
#define I2C_MST_DELAY_CTRL 0X67
#define SIGNAL_PATH_RESET 0X68
#define USER_CTRL 0X6A
#define PWR_MGMT_1 0X6B
#define PWR_MGMT_2 0X6C
#define FIFO_COUNTH 0X72
#define FIFO_COUNTL 0X73
#define FIFO_R_W  0X74
#define WHO_AM_I 0X75

class MPU6050{
	typedef struct vector{
		double x,y,z;
	}vector;
	private:
	public:
		vector gyro;
		vector accel;
		float temperature;
		void temp();
		void GetAccelXYZ();
		void GetGyroXYZ();
		void GetTemperature();
};

#endif
