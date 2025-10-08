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
/*΢����ʱ���� */


void user_delay_ms(uint16_t ms) 
{ 
    for(; ms > 0; ms--) 
    { 
        user_delay_us(1000); 
    } 
} 

/*������ʱ���� */



void step_motor_volt_init()
{
	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_0,GPIO_PIN_SET); 
	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_2,GPIO_PIN_SET); 

}
/*�򿪲����������ʹ�ܵ�ѹ*/




void paw_rise()
{
	HAL_GPIO_WritePin(GPIOH,GPIO_PIN_11,GPIO_PIN_SET); 
	/*���������������*/
	
	for (int paw_i = 0 ; paw_i<52000 ; paw_i++)
	{
		
		GPIOH->ODR ^= GPIO_PIN_12;
		user_delay_us(30);
        
		GPIOH->ODR ^= GPIO_PIN_12;       
		user_delay_us(30);
		
	}	
	/*�����������*/	
	
}
/*���������ת����צ����*/



void paw_decline()
{
	
	HAL_GPIO_WritePin(GPIOH,GPIO_PIN_11,GPIO_PIN_RESET); 
	/*���������������*/
	
	for (int paw_i = 0 ; paw_i<40000 ; paw_i++)
	{
		
		GPIOH->ODR ^= GPIO_PIN_12;
		user_delay_us(30);
        
		GPIOH->ODR ^= GPIO_PIN_12;       
		user_delay_us(30);
		
	}	
	/*�����������*/	
	
}
/*���������ת����צ�½�*/




void paw_out()
{
	HAL_GPIO_WritePin(GPIOH,GPIO_PIN_10,GPIO_PIN_RESET); 
	/*����������צ*/
	
}
/*����צ*/


void paw_in()
{
	HAL_GPIO_WritePin(GPIOH,GPIO_PIN_10,GPIO_PIN_SET); 
	/*�������պ���צ*/	
}
/*�պ���צ*/	




void paw_dierction_out()
{
	__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,775);
	/*��צ����*/
	
	__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,1775);
	/*��צ����*/
	
}
/*������ת��צ��λ�ÿ��ƣ�*/


void paw_dierction_in()
{

	__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,775);
	/*��צ����*/
	
	__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,1775);
	/*��צ����*/
	
}
/*������ת��צ��λ�ÿ��ƣ�*/



void ball_motor_rise()
{
	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_6,GPIO_PIN_RESET);
	/*���������������*/
	
	
	for (int ball_motor_i = 0 ; ball_motor_i<1000 ; ball_motor_i++)
	{
		
		GPIOI->ODR ^= GPIO_PIN_7;
		user_delay_us(30);
        
		GPIOI->ODR ^= GPIO_PIN_7;       
		user_delay_us(30);
		
	}	
	/*�����������*/	
	
}
/*ȡ���������*/


void ball_motor_decline()
{
	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_6,GPIO_PIN_SET);
	/*���������������*/
	
	for (int ball_motor_i = 0 ; ball_motor_i<1000 ; ball_motor_i++)
	{
		
		GPIOI->ODR ^= GPIO_PIN_7;
		user_delay_us(30);
        
		GPIOI->ODR ^= GPIO_PIN_7;       
		user_delay_us(30);
		
	}	
	/*�����������*/	
	
}
/*ȡ���������*/


void ball_sweep_on()
{
	
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,775);
	/*ɨ��*/

}
/*ɨ�����*/


void ball_sweep_off()
{

	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,775);
	/*��λ*/


}
/*ɨ������λ*/


void ball_suction_on()
{

	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_15,GPIO_PIN_SET);
	/*�򿪵�ŷ���������ձ�*/

}
/*��������*/


void ball_suction_off()
{

	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_15,GPIO_PIN_RESET);
	/*�رյ�ŷ����ر���ձ�*/

}
/*���̷���*/


void ball_shoot_on()
{
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_SET);
	/*�򿪵�ŷ�,�����쳤*/

}
/*����*/


void ball_shoot_off()
{
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_RESET);
	/*�رյ�ŷ�,�����ջ�*/

}
/*׼������*/





void clamp_up()
{
	paw_in();
	user_delay_ms(300);
	paw_rise();

}
/*�н����磬����*/

void clamp_down()
{
	paw_decline();
	user_delay_ms(300);
	paw_out();
}
/*�½����ɿ�����*/

/*ע��clamp_down�г̳��Ұ�������צ��*/








