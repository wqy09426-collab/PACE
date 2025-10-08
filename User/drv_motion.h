#ifndef DRV_MOTION_H
#define DRV_MOTION_H

#include <stdint.h>
#include "alg_pid.h"
#include "drv_can.h"
#include "stm32f4xx_hal.h"
#include "dvc_motor.h"

extern Class_Motor_C620 motor1;
extern Class_Motor_C620 motor2;
extern Class_Motor_C620 motor3;
extern Class_Motor_C620 motor4;
extern Class_Motor_C620 motor5;
extern Class_Motor_C620 motor6;
extern Class_Motor_C620 motor7;
extern Class_Motor_C620 motor8;

void CAN_Motor_Call_Back(Struct_CAN_Rx_Buffer *Rx_Buffer);
void Motor_Forward();
void Motor_Back();
void Motor_Left_Rotation();
void High_Motor_Right_Rotation();
void High_Motor_Left_Rotation();
void Motor_Right_Rotation();
void Motor_Left_Move();
void Motor_Right_Move();
void High_Motor_Forward();
void High_Motor_Back();
void High_Motor_Left_Move();
void High_Motor_Right_Move();
void Motor_Stop();
void Motor_Brake();
void Ball_Shoot();
void Frictiongear_Rotate();
void Angle_Up();
void Angle_Down();
void Claw_Lift_Up();
void Claw_Lift_Down();

#endif
