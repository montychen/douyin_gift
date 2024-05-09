#include "Board.h"
#include "DMX.h"


uint8_t rxDataBufUSART2[DMX_BUF_SIZE] = {0};

u16 ADDR_Counter;
u16 databuff;
u8 status;
u8 DMX_Break = 0;

uint16_t DMX512_menu1_data = 1;
uint16_t DMX512_menu1_data_size = 10;

u8 RDM_recFinish = 0;

extern uint16_t uart_val;

/*!
 * @brief       USARTS Initialization
 *
 * @param       None
 *
 * @retval      None
 */
void USART_Init(void)
{
    APM_MINI_COMInit(COM1);
    //APM_MINI_COMInit(COM2);
	
		//RCM_EnableAHBPeriphClock(RCM_AHB_PERIPH_GPIOB);

		GPIO_Config_T GPIO_InitStructure;
		GPIO_InitStructure.pin= (GPIO_PIN_4);
    GPIO_InitStructure.mode = GPIO_MODE_OUT;
    GPIO_InitStructure.outtype = GPIO_OUT_TYPE_PP;
    GPIO_InitStructure.speed = GPIO_SPEED_50MHz;
    GPIO_InitStructure.pupd = GPIO_PUPD_PU;	
		GPIO_Config(GPIOB,&GPIO_InitStructure);
		GPIO_WriteBitValue(GPIOB, GPIO_PIN_4, Bit_RESET);

//		GPIO_InitStructure.pin= (GPIO_PIN_2);
//    GPIO_InitStructure.mode = GPIO_MODE_IN;
//    GPIO_InitStructure.outtype = GPIO_OUT_TYPE_PP;
//    GPIO_InitStructure.speed = GPIO_SPEED_50MHz;
//    GPIO_InitStructure.pupd = GPIO_PUPD_NO;	
//		GPIO_Config(GPIOA,&GPIO_InitStructure);
//		//GPIO_WriteBitValue(GPIOA, GPIO_PIN_2, Bit_SET);

//		GPIO_InitStructure.pin= (GPIO_PIN_3);
//    GPIO_InitStructure.mode = GPIO_MODE_IN;
//    GPIO_InitStructure.outtype = 0;
//    GPIO_InitStructure.speed = GPIO_SPEED_50MHz;
//    GPIO_InitStructure.pupd = GPIO_PUPD_NO;	
//		GPIO_Config(GPIOA,&GPIO_InitStructure);
		
    Delay2(0x7FFF);

    /* Disable USART1 RXBNE interrput */
//    USART_DisableInterrupt(MINI_COM1, USART_INT_RXBNEIE);
//    USART_DisableInterrupt(MINI_COM2, USART_INT_RXBNEIE);

    /* Disable USART2 RXBNE interrput */
    USART_ClearStatusFlag(MINI_COM1, USART_FLAG_RXBNE);
//    USART_ClearStatusFlag(MINI_COM2, USART_FLAG_RXBNE);
}

void USART1_IRQHandler(void)
{
    if (USART_ReadStatusFlag(MINI_COM1, USART_FLAG_RXBNE) == RESET)
    {
    } else {
				rxDataBufUSART2[0] = USART_RxData(MINI_COM1);
				if(rxDataBufUSART2[0]>'0' && rxDataBufUSART2[0]<='9')
				{
					uart_val += (rxDataBufUSART2[0] - '0');
					uart_val = uart_val;
				}
		}
}


