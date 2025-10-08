#include "stm32f4xx_hal.h"
#include "Timer.h"

extern TIM_HandleTypeDef htim2;

void Timer_Init(void)
{
    // 启用 TIM2 时钟
    __HAL_RCC_TIM2_CLK_ENABLE();

    // 定时器基础配置
    htim2.Instance = TIM2;
    htim2.Init.Prescaler = 7200 - 1;       // 预分频系数
    htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim2.Init.Period = 50 - 1;            // 自动重载值
    htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim2.Init.RepetitionCounter = 0;
    HAL_TIM_Base_Init(&htim2);

    // 清除更新中断标志
    __HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);

    // 启用更新中断
    __HAL_TIM_ENABLE_IT(&htim2, TIM_IT_UPDATE);

    // 中断优先级配置
    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_2);
    HAL_NVIC_SetPriority(TIM2_IRQn, 2, 1);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);

    // 启动定时器
    HAL_TIM_Base_Start_IT(&htim2);
}
