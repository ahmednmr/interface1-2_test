/*
 * i2c.h
 *
 *  Created on: Mar 25, 2019
 *      Author: Nmr
 */

#ifndef I2C_H_
#define I2C_H_


#define F_SCL 100000UL // SCL frequency
#define Prescaler 1
#define TWBR_val ((((F_CPU / F_SCL) / Prescaler) - 16 ) / 2)

void TWI_Init(void);
void TWI_Start(void);
void TWI_SendAddress(uint8_t address);
void TWI_SendData(uint8_t data);
void TWI_ReceiveData_ACK(uint8_t * pu8RxData);
void TWI_ReceiveData_NACK(uint8_t * pu8RxData);
void TWI_Stop(void);
uint8_t  TWI_Read8(uint8_t DeviceAdd, uint8_t memory_location);
uint16_t TWI_Read16(uint8_t DeviceAdd,uint8_t memory_location);
void  TWI_Write8(uint8_t DeviceAdd, uint8_t memory_location, uint8_t DataByte);


#endif /* I2C_H_ */
