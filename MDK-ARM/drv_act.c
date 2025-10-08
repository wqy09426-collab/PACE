#include "drv_act.h"


void user_delay_us(uint16_t us) 
{ 
	for(; us > 0; us--) 
	{ 
		for(uint8_t i = 50; i > 0; i--) 
		{ 
				; 
		} 
	} 
} 
/*微秒延时函数 */


void user_delay_ms(uint16_t ms) 
{ 
    for(; ms > 0; ms--) 
    { 
        user_delay_us(1000); 
    } 
} 

/*毫秒延时函数 */



void step_motor_volt_init()
{
	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_0,GPIO_PIN_SET); 
	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_2,GPIO_PIN_SET); 

}
/*打开步进电机驱动使能电压*/




void paw_rise()
{
	HAL_GPIO_WritePin(GPIOH,GPIO_PIN_11,GPIO_PIN_SET); 
	/*步进电机方向设置*/
	
	for (int paw_i = 0 ; paw_i<52000 ; paw_i++)
	{
		
		GPIOH->ODR ^= GPIO_PIN_12;
		user_delay_us(30);
        
		GPIOH->ODR ^= GPIO_PIN_12;       
		user_delay_us(30);
		
	}	
	/*步进电机脉冲*/	
	
}
/*步进电机正转，夹爪上升*/



void paw_decline()
{
	
	HAL_GPIO_WritePin(GPIOH,GPIO_PIN_11,GPIO_PIN_RESET); 
	/*步进电机方向设置*/
	
	for (int paw_i = 0 ; paw_i<40000 ; paw_i++)
	{
		
		GPIOH->ODR ^= GPIO_PIN_12;
		user_delay_us(30);
        
		GPIOH->ODR ^= GPIO_PIN_12;       
		user_delay_us(30);
		
	}	
	/*步进电机脉冲*/	
	
}
/*步进电机反转，夹爪下降*/




void paw_out()
{
	HAL_GPIO_WritePin(GPIOH,GPIO_PIN_10,GPIO_PIN_RESET); 
	/*放气，打开气爪*/
	
}
/*打开气爪*/


void paw_in()
{
	HAL_GPIO_WritePin(GPIOH,GPIO_PIN_10,GPIO_PIN_SET); 
	/*充气，闭合气爪*/	
}
/*闭合气爪*/	




void paw_dierction_out()
{
	__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,775);
	/*左爪向外*/
	
	__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,1775);
	/*右爪向外*/
	
}
/*向外旋转气爪（位置控制）*/


void paw_dierction_in()
{

	__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,775);
	/*左爪向内*/
	
	__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,1775);
	/*右爪向内*/
	
}
/*向内旋转气爪（位置控制）*/



void ball_motor_rise()
{
	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_6,GPIO_PIN_RESET);
	/*步进电机方向设置*/
	
	
	for (int ball_motor_i = 0 ; ball_motor_i<1000 ; ball_motor_i++)
	{
		
		GPIOI->ODR ^= GPIO_PIN_7;
		user_delay_us(30);
        
		GPIOI->ODR ^= GPIO_PIN_7;       
		user_delay_us(30);
		
	}	
	/*步进电机脉冲*/	
	
}
/*取球机构仰起*/


void ball_motor_decline()
{
	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_6,GPIO_PIN_SET);
	/*步进电机方向设置*/
	
	for (int ball_motor_i = 0 ; ball_motor_i<1000 ; ball_motor_i++)
	{
		
		GPIOI->ODR ^= GPIO_PIN_7;
		user_delay_us(30);
        
		GPIOI->ODR ^= GPIO_PIN_7;       
		user_delay_us(30);
		
	}	
	/*步进电机脉冲*/	
	
}
/*取球机构俯下*/


void ball_sweep_on()
{
	
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,775);
	/*扫球*/

}
/*扫球进筐*/


void ball_sweep_off()
{

	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,775);
	/*归位*/


}
/*扫球器归位*/


void ball_suction_on()
{

	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_15,GPIO_PIN_SET);
	/*打开电磁阀，开启真空泵*/

}
/*吸盘吸球*/


void ball_suction_off()
{

	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_15,GPIO_PIN_RESET);
	/*关闭电磁阀，关闭真空泵*/

}
/*吸盘放球*/


void ball_shoot_on()
{
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_SET);
	/*打开电磁阀,气缸伸长*/

}
/*射球*/


void ball_shoot_off()
{
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_RESET);
	/*关闭电磁阀,气缸收回*/

}
/*准备射球*/





void clamp_up()
{
	paw_in();
	user_delay_ms(300);
	paw_rise();

}
/*夹紧秧苗，上升*/

void clamp_down()
{
	paw_decline();
	user_delay_ms(300);
	paw_out();
}
/*下降，松开秧苗*/

/*注：clamp_down行程长且包含了松爪！*/








