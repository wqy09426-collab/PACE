#ifndef DRV_COMMUNICATION_H
#define DRV_COMMUNICATION_H

#include "stm32f4xx_hal.h"
#include "drv_uart.h"


void MoveOrder_Call_Back(uint8_t *Buffer, uint16_t Length);

#endif
