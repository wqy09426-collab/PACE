#include "stm32f4xx_hal.h"
#include "Delay.h"

// 假设外部提供了微秒延时函数，如果没有就先用 HAL_Delay 替代


// 设置SCL线电平
void MyI2C_W_SCL(uint8_t BitValue)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, BitValue ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_Delay(10);
}

// 设置SDA线电平
void MyI2C_W_SDA(uint8_t BitValue)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, BitValue ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_Delay(10);
}

// 读取SDA线电平
uint8_t MyI2C_R_SDA(void)
{
    uint8_t BitValue;
    BitValue = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);
    HAL_Delay(10);
    return BitValue;
}

// 初始化 I2C 使用的 GPIO（PA0=SCL，PA1=SDA）
void MyI2C_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // 开启 GPIOA 时钟
    __HAL_RCC_GPIOA_CLK_ENABLE();

    // 配置 PB10 和 PB11 为开漏输出（Open Drain），模拟I2C需求
    GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // 初始拉高
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
}

void MyI2C_Start(void)
{
	MyI2C_W_SDA(1);
	MyI2C_W_SCL(1);
	MyI2C_W_SDA(0);
	MyI2C_W_SCL(0);
}

void MyI2C_Stop(void)
{
	MyI2C_W_SDA(0);
	MyI2C_W_SCL(1);
	MyI2C_W_SDA(1);
}

void MyI2C_SendByte(uint8_t Byte)
{
	uint8_t i;
	for (i = 0; i < 8; i ++)
	{
		MyI2C_W_SDA(Byte & (0x80 >> i));
		MyI2C_W_SCL(1);
		MyI2C_W_SCL(0);
	}
}

uint8_t MyI2C_ReceiveByte(void)
{
	uint8_t i, Byte = 0x00;
	MyI2C_W_SDA(1);
	for (i = 0; i < 8; i ++)
	{
		MyI2C_W_SCL(1);
		if (MyI2C_R_SDA() == 1){Byte |= (0x80 >> i);}
		MyI2C_W_SCL(0);
	}
	return Byte;
}

void MyI2C_SendAck(uint8_t AckBit)
{
	MyI2C_W_SDA(AckBit);
	 Delay_us(5);
	MyI2C_W_SCL(1);
	 Delay_us(5);
	MyI2C_W_SCL(0);
}

uint8_t MyI2C_ReceiveAck(void)
{
	uint8_t AckBit;
	MyI2C_W_SDA(1);
	 Delay_us(5);
	MyI2C_W_SCL(1);
	 Delay_us(5);
	AckBit = MyI2C_R_SDA();
	 Delay_us(5);
	MyI2C_W_SCL(0);
	return AckBit;
}
