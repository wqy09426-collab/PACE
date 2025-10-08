#ifndef DRV_ACT_H
#define DRV_ACT_H


#include "stm32f4xx_hal.h"
#include "tim.h"
#include "gpio.h"


void user_delay_us(uint16_t us);
void user_delay_ms(uint16_t ms);
void step_motor_volt_init();

void paw_rise();
void paw_decline();
void paw_out();
void paw_in();
void paw_dierction_out();
void paw_dierction_in();

void ball_motor_rise();
void ball_motor_decline();

void ball_sweep_on();
void ball_sweep_off();

void ball_suction_on();
void ball_suction_off();

void ball_shoot_on();
void ball_shoot_off();

void clamp_up();
void clamp_down();



#endif
