/**
 * @file alg_pid.h
 * @author yssickjgd (1345578933@qq.com)
 * @brief PID算法
 * @version 0.1
 * @date 2022-05-03
 *
 * @copyright USTC-RoboWalker (c) 2022
 *
 */

#ifndef ALG_PID_H
#define ALG_PID_H

/* Includes ------------------------------------------------------------------*/

#include <stdint.h>
#include "drv_math.h"

/* Exported macros -----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/**
 * @brief 微分先行
 *
 */
typedef enum
{
    PID_D_First_DISABLE = 0,
    PID_D_First_ENABLE,
} Enum_PID_D_First;

/**
 * @brief Reusable, PID算法
 *
 */
typedef struct
{
    //初始化相关常量

    // PID计时器周期, s
    float D_T;
    //死区, Error在其绝对值内不输出
    Enum_PID_D_First D_First;

    //常量

    //内部变量

    //之前的当前值
    float Pre_Now;
    //之前的目标值
    float Pre_Target;
    //之前的输出值
    float Pre_Out;
    //前向误差
    float Pre_Error;

    //读变量

    //输出值
    float Out;

    //写变量

    // PID的P
    float K_P;
    // PID的I
    float K_I;
    // PID的D
    float K_D;
    //前馈
    float K_F;

    //积分限幅, 0为不限制
    float I_Out_Max;
    //输出限幅, 0为不限制
    float Out_Max;

    //变速积分定速内段阈值, 0为不限制
    float I_Variable_Speed_A;
    //变速积分变速区间, 0为不限制
    float I_Variable_Speed_B;
    //积分分离阈值，需为正数, 0为不限制
    float I_Separate_Threshold;

    //目标值
    float Target;
    //当前值
    float Now;

    //读写变量

    //积分值
    float Integral_Error;

} PID_t;

// Function prototypes for PID operations
void PID_Init(PID_t *pid, float __K_P, float __K_I, float __K_D, float __K_F, float __I_Out_Max, float __Out_Max, float __D_T, float __Dead_Zone, float __I_Variable_Speed_A, float __I_Variable_Speed_B, float __I_Separate_Threshold, Enum_PID_D_First __D_First);
float PID_Get_Integral_Error(PID_t *pid);
float PID_Get_Out(PID_t *pid);

void PID_Set_K_P(PID_t *pid, float __K_P);
void PID_Set_K_I(PID_t *pid, float __K_I);
void PID_Set_K_D(PID_t *pid, float __K_D);
void PID_Set_K_F(PID_t *pid, float __K_F);
void PID_Set_I_Out_Max(PID_t *pid, float __I_Out_Max);
void PID_Set_Out_Max(PID_t *pid, float __Out_Max);
void PID_Set_I_Variable_Speed_A(PID_t *pid, float __Variable_Speed_I_A);
void PID_Set_I_Variable_Speed_B(PID_t *pid, float __Variable_Speed_I_B);
void PID_Set_I_Separate_Threshold(PID_t *pid, float __I_Separate_Threshold);
void PID_Set_Target(PID_t *pid, float __Target);
void PID_Set_Now(PID_t *pid, float __Now);
void PID_Set_Integral_Error(PID_t *pid, float __Integral_Error);

void PID_TIM_Adjust_PeriodElapsedCallback(PID_t *pid);

/* Exported variables --------------------------------------------------------*/

/* Exported function declarations --------------------------------------------*/

#endif

/************************ COPYRIGHT(C) USTC-ROBOWALKER **************************/
