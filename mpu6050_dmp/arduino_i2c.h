/*
 $License:
    Copyright (C) 2011 InvenSense Corporation, All Rights Reserved.
 $
 */
/******************************************************************************
 * $Id: arduino_i2c.h $
 *****************************************************************************/
/**
 *  
 *
 *  @{
 *      @file       arduino_i2c.h
 *      @brief      Serial communication functions needed by eMPL to
 *                  communicate to the MPU devices.
 *      @details    
 *
 *                 
 *                  
 */
#ifndef _ARDUINO_I2C_H_
#define _ARDUINO_I2C_H_
#include<Arduino.h>
#define MPU6050


/* The following functions must be defined for this platform:
 * i2c_write(unsigned char slave_addr, unsigned char reg_addr,
 *      unsigned char length, unsigned char const *data)
 * i2c_read(unsigned char slave_addr, unsigned char reg_addr,
 *      unsigned char length, unsigned char *data)
 * delay_ms(unsigned long num_ms)
 * get_ms(unsigned long *count)
 * reg_int_cb(void (*cb)(void), unsigned char port, unsigned char pin)
 * labs(long x)
 * fabsf(float x)
 * min(int a, int b)
 */
#define i2c_write   arduino_i2c_write
#define i2c_read    arduino_i2c_read
#define delay_ms    delay
//#define get_ms      arduino_get_clock_ms
static inline void get_ms(unsigned long *count){
  *count = millis();
}
static inline int reg_int_cb(struct int_param_s *int_param)
{
  ////TODO: Setup arduino interrupt
}
#define log_i(...)     do {} while (0)
#define log_e(...)     do {} while (0)

/* fabs is for doubles. fabsf is for floats. */
#define labs(x) ((x>0) ? x : -x)
#define fabsf(x) labs(x)  
#define min(a,b) ((a<b)?a:b)


#ifdef __cplusplus
extern "C"
{
#endif

/**
 *  @brief	Set up the I2C port and configure the Arduino as the master.
 *  @return	0 if successful.
 */
//int msp430_i2c_enable(void);
/**
 *  @brief  Disable I2C communication.
 *  This function will disable the I2C hardware and should be called prior to
 *  entering low-power mode.
 *  @return 0 if successful.
 */
//int msp430_i2c_disable(void);
/**
 *  @brief      Write to a device register.
 *
 *  @param[in]  slave_addr  Slave address of device.
 *  @param[in]  reg_addr	Slave register to be written to.
 *  @param[in]  length      Number of bytes to write.
 *  @param[out] data        Data to be written to register.
 *
 *  @return     0 if successful.
 */
int arduino_i2c_write(uint8_t slave_addr,
                     uint8_t reg_addr,
                     uint8_t num,
                     uint8_t const *data);
/**
 *  @brief      Read from a device.
 *
 *  @param[in]  slave_addr  Slave address of device.
 *  @param[in]  reg_addr	Slave register to be read from.
 *  @param[in]  length      Number of bytes to read.
 *  @param[out] data        Data from register.
 *
 *  @return     0 if successful.
 */
int arduino_i2c_read(unsigned char slave_addr,
                    unsigned char reg_addr,
                    unsigned char num,
                    unsigned char *data);

//void arduino_delay_ms(unsigned int ms);
//void arduino_get_clock_ms(unsigned long *count);


#ifdef __cplusplus
}
#endif

#endif  /* _ARDUINO_I2C_H_ */

/**
 * @}
 */
