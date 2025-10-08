#include "drv_communication.h"
#include "stm32f405xx.h"
uint8_t tx_buffer[9] = {0xAB};
uint8_t rx_buffer[10];
uint8_t MoveOrder = 0;

GPIO_PinState Char2GPIO_State(char message){
	if (message=='0'){
	return GPIO_PIN_SET;
	}
	else{
	return GPIO_PIN_RESET;
	}
}

void Trans_LED_Status(){
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, Char2GPIO_State(rx_buffer[0]));
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_2, Char2GPIO_State(rx_buffer[1]));
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_3, Char2GPIO_State(rx_buffer[2]));
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_4, Char2GPIO_State(rx_buffer[3]));
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_5, Char2GPIO_State(rx_buffer[4]));
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, Char2GPIO_State(rx_buffer[5]));
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, Char2GPIO_State(rx_buffer[6]));
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_8, Char2GPIO_State(rx_buffer[7]));

}


void MoveOrder_Call_Back(uint8_t *Buffer, uint16_t Length)
{
    if ((rx_buffer[0] == '0')&&(rx_buffer[1] == '0')&&(rx_buffer[2] == '0')&&(rx_buffer[3] == '0')&&(rx_buffer[4] == '0')&&(rx_buffer[5] == '0')&&(rx_buffer[6] == '0')&&(rx_buffer[7] == '0'))
    {
			
		Trans_LED_Status();
		MoveOrder = 1;
 //Brake
	}
	else if ((rx_buffer[0] == '0')&&(rx_buffer[1] == '0')&&(rx_buffer[2] == '0')&&(rx_buffer[3] == '0')&&(rx_buffer[4] == '0')&&(rx_buffer[5] == '0')&&(rx_buffer[6] == '0')&&(rx_buffer[7] == '1'))
    {
	Trans_LED_Status();
        MoveOrder = 2; //Forward
    
    }
	else if ((rx_buffer[0] == '0')&&(rx_buffer[1] == '0')&&(rx_buffer[2] == '0')&&(rx_buffer[3] == '0')&&(rx_buffer[4] == '0')&&(rx_buffer[5] == '0')&&(rx_buffer[6] == '1')&&(rx_buffer[7] == '0'))
    {
		Trans_LED_Status();
        MoveOrder = 3; //Back
    
    }
	else if ((rx_buffer[0] == '0')&&(rx_buffer[1] == '0')&&(rx_buffer[2] == '0')&&(rx_buffer[3] == '0')&&(rx_buffer[4] == '0')&&(rx_buffer[5] == '0')&&(rx_buffer[6] == '1')&&(rx_buffer[7] == '1'))
    {
		Trans_LED_Status();
        MoveOrder = 4; //Left_Rotation
	}
	else if ((rx_buffer[0] == '0')&&(rx_buffer[1] == '0')&&(rx_buffer[2] == '0')&&(rx_buffer[3] == '0')&&(rx_buffer[4] == '0')&&(rx_buffer[5] == '1')&&(rx_buffer[6] == '0')&&(rx_buffer[7] == '0'))
    {
	Trans_LED_Status();
        MoveOrder = 5; //Right_Rotation
	}
	else if ((rx_buffer[0] == '0')&&(rx_buffer[1] == '0')&&(rx_buffer[2] == '0')&&(rx_buffer[3] == '0')&&(rx_buffer[4] == '0')&&(rx_buffer[5] == '1')&&(rx_buffer[6] == '0')&&(rx_buffer[7] == '1'))
    {
	Trans_LED_Status();
        MoveOrder = 6; //Left_Move
	}
	else if ((rx_buffer[0] == '0')&&(rx_buffer[1] == '0')&&(rx_buffer[2] == '0')&&(rx_buffer[3] == '0')&&(rx_buffer[4] == '0')&&(rx_buffer[5] == '1')&&(rx_buffer[6] == '1')&&(rx_buffer[7] == '0'))
    {
	Trans_LED_Status();
        MoveOrder = 7; //Right_Move
	}
	else if ((rx_buffer[0] == '0')&&(rx_buffer[1] == '0')&&(rx_buffer[2] == '0')&&(rx_buffer[3] == '0')&&(rx_buffer[4] == '0')&&(rx_buffer[5] == '1')&&(rx_buffer[6] == '1')&&(rx_buffer[7] == '1'))
    {
	Trans_LED_Status();
        MoveOrder = 8; //Stop
	}
	else if ((rx_buffer[0] == '0')&&(rx_buffer[1] == '0')&&(rx_buffer[2] == '0')&&(rx_buffer[3] == '0')&&(rx_buffer[4] == '1')&&(rx_buffer[5] == '0')&&(rx_buffer[6] == '0')&&(rx_buffer[7] == '0'))
    {
	Trans_LED_Status();
        MoveOrder = 9; //Paw_Close
	}
	else if ((rx_buffer[0] == '0')&&(rx_buffer[1] == '0')&&(rx_buffer[2] == '0')&&(rx_buffer[3] == '0')&&(rx_buffer[4] == '1')&&(rx_buffer[5] == '0')&&(rx_buffer[6] == '0')&&(rx_buffer[7] == '1'))
    {
	Trans_LED_Status();
        MoveOrder = 10; //Paw_Open
	}

	else if ((rx_buffer[0] == '0')&&(rx_buffer[1] == '0')&&(rx_buffer[2] == '0')&&(rx_buffer[3] == '0')&&(rx_buffer[4] == '1')&&(rx_buffer[5] == '0')&&(rx_buffer[6] == '1')&&(rx_buffer[7] == '0'))
    {
	Trans_LED_Status();
        MoveOrder = 11; //paw_rise
	}
	else if ((rx_buffer[0] == '0')&&(rx_buffer[1] == '0')&&(rx_buffer[2] == '0')&&(rx_buffer[3] == '0')&&(rx_buffer[4] == '1')&&(rx_buffer[5] == '0')&&(rx_buffer[6] == '1')&&(rx_buffer[7] == '1'))
    {
	Trans_LED_Status();
        MoveOrder = 12; //paw_decline
	}
	else if ((rx_buffer[0] == '1')&&(rx_buffer[1] == '0')&&(rx_buffer[2] == '0')&&(rx_buffer[3] == '0')&&(rx_buffer[4] == '0')&&(rx_buffer[5] == '0')&&(rx_buffer[6] == '0')&&(rx_buffer[7] == '1'))
    {
	Trans_LED_Status();
        MoveOrder = 13; //High_Forward
    }
	else if ((rx_buffer[0] == '1')&&(rx_buffer[1] == '0')&&(rx_buffer[2] == '0')&&(rx_buffer[3] == '0')&&(rx_buffer[4] == '0')&&(rx_buffer[5] == '0')&&(rx_buffer[6] == '1')&&(rx_buffer[7] == '0'))
    {
		Trans_LED_Status();
        MoveOrder = 14; //High_Back
    }
	else if ((rx_buffer[0] == '1')&&(rx_buffer[1] == '0')&&(rx_buffer[2] == '0')&&(rx_buffer[3] == '0')&&(rx_buffer[4] == '0')&&(rx_buffer[5] == '1')&&(rx_buffer[6] == '0')&&(rx_buffer[7] == '1'))
    {
	Trans_LED_Status();
        MoveOrder = 15; //High_Left_Move
	}
	else if ((rx_buffer[0] == '1')&&(rx_buffer[1] == '0')&&(rx_buffer[2] == '0')&&(rx_buffer[3] == '0')&&(rx_buffer[4] == '0')&&(rx_buffer[5] == '1')&&(rx_buffer[6] == '1')&&(rx_buffer[7] == '0'))
    {
	Trans_LED_Status();
        MoveOrder = 16; //High_Right_Move
	}
  else if ((rx_buffer[0] == '1')&&(rx_buffer[1] == '0')&&(rx_buffer[2] == '0')&&(rx_buffer[3] == '0')&&(rx_buffer[4] == '0')&&(rx_buffer[5] == '0')&&(rx_buffer[6] == '1')&&(rx_buffer[7] == '1'))
    {
	Trans_LED_Status();
        MoveOrder = 16; //High_Right_Move
	}		
  else if ((rx_buffer[0] == '1')&&(rx_buffer[1] == '0')&&(rx_buffer[2] == '0')&&(rx_buffer[3] == '0')&&(rx_buffer[4] == '0')&&(rx_buffer[5] == '1')&&(rx_buffer[6] == '0')&&(rx_buffer[7] == '0'))
    {
	Trans_LED_Status();
        MoveOrder = 16; //High_Right_Move
	}			
		
}

