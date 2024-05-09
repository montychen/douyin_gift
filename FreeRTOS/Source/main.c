/*!
 * @file       main.c
 *
 * @brief      Main program body
 *
 * @version    V1.0.0
 *
 * @date       2022-09-20
 *
 * @attention
 *
 *  Copyright (C) 2022 Geehy Semiconductor
 *
 *  You may not use this file except in compliance with the
 *  GEEHY COPYRIGHT NOTICE (GEEHY SOFTWARE PACKAGE LICENSE).
 *
 *  The program is only for reference, which is distributed in the hope
 *  that it will be useful and instructional for customers to develop
 *  their software. Unless required by applicable law or agreed to in
 *  writing, the program is distributed on an "AS IS" BASIS, WITHOUT
 *  ANY WARRANTY OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the GEEHY SOFTWARE PACKAGE LICENSE for the governing permissions
 *  and limitations under the License.
 */

/* Includes */
#include "main.h"
#include "Board.h"

/* FreeRTOS includes */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "list.h"
#include "key.h"
#include "motor.h"
#include "DMX.h"
#include "serv.h"

/** @addtogroup Examples
  * @{
*/

/** @addtogroup FreeRTOS
  * @{
*/

/** @defgroup FreeRTOS_Macros Macros
  @{
  */


/**@} end of group FreeRTOS_Macros */


/** @defgroup FreeRTOS_Enumerations Enumerations
  @{
  */

/**@} end of group FreeRTOS_Enumerations */

/** @defgroup FreeRTOS_Structures Structures
  @{
  */

/**@} end of group FreeRTOS_Structures */

/** @defgroup FreeRTOS_Variables Variables
  @{
  */

/**@} end of group FreeRTOS_Variables */

/** @defgroup FreeRTOS_Functions Functions
  @{
  */

/* USART1 receive buffer */
//uint8_t rxDataBufUSART1[DATA_BUF_SIZE] = {0};
/* USART1 transmit buffer */
//uint8_t txDataBufUSART1[DATA_BUF_SIZE] = {0};

/* USART2 receive buffer */
//uint8_t rxDataBufUSART2[DATA_BUF_SIZE] = {0};
/* USART2 transmit buffer */

/* USART Write data */
void USART_Write(USART_T* usart, uint8_t* dat);

/* Delay */
void Delay(uint32_t count);
/* Buffer compare*/
BOOL BufferCompare(uint8_t* buf1, uint8_t* buf2, uint8_t size);

/* Task handle */
static TaskHandle_t xHandleTaskLedToggle = NULL;
static TaskHandle_t xHandleTaskKey = NULL;
static TaskHandle_t xHandleTaskMotor = NULL;
static TaskHandle_t xHandleTaskUart1 = NULL;
static TaskHandle_t xHandleTaskServ = NULL;

/* User create task */
static void UserTaskCreate(void);

/* Led toggle task */
void vTaskLedToggle(void* pvParameters);
/* Usart test task */
void vTaskKey(void* pvParameters);
void vTaskTft(void* pvParameters);
void vTaskMotor(void* pvParameters);
void vTaskUart1(void* pvParameters);
void vTaskServ(void* pvParameters);

uint8_t screanMain_idx_o = 0;
uint8_t screanMain_idx = 0;
uint8_t screanSecondx = 0;   //第几个二级菜单
uint8_t screanSecond_idx_o = 0;
uint8_t screanSecond_idx = 0;
uint8_t screanSecond_status = 1;  //正常，编辑
uint8_t screanSecondx2 = 0;   //第几个二级菜单的第二页

const uint8_t screanSecond_Title_Num[6] = {2,10,3,3,1,5};


uint8_t key1_press = 0;
uint8_t key2_press = 0;
uint8_t key3_press = 0;
uint8_t keyup_press = 0;
uint8_t keydown_longpress = 0;
uint8_t keyenter_longpress = 0;
uint8_t keyhome_longpress = 0;
uint8_t keyup_longpress = 0;
uint8_t keydown_up = 0;
uint8_t keyenter_up = 0;
uint8_t keyhome_up = 0;
uint8_t keyup_up = 0;

uint8_t menuVal[6][10] = {0};

uint16_t uart_val = 0;


/*!
 * @brief       Main program
 *
 * @param       None
 *
 * @retval      None
 */
int main(void)
{
//    APM_MINI_LEDInit(LED2);
//    APM_MINI_LEDInit(LED3);
		int tmp = 0;
		motor_gpio_init();
		motor_timer_init();
		Serv_Gpio_Init();
		Serv_Timer_Init();
		Key_Init();

    /* USART Initialization */
    USART_Init();

    /* User create task */
    UserTaskCreate();

    /* Startup FreeRTOS */
    vTaskStartScheduler();

    while (1);
}

/*!
 * @brief       User Create Task
 *
 * @param       None
 *
 * @retval      None
 */
static void UserTaskCreate(void)
{
//    xTaskCreate(vTaskLedToggle,
//                "TaskLedToggle",
//                128,
//                NULL,
//                0,
//                &xHandleTaskLedToggle);

    xTaskCreate(vTaskKey,
                "TaskKey",
                128,
                NULL,
                2,
                &xHandleTaskKey);

		xTaskCreate(vTaskMotor,
                "TaskMotor",
                128,
                NULL,
                2,
                &xHandleTaskMotor);

		xTaskCreate(vTaskServ,
                "TaskServ",
                128,
                NULL,
                2,
                &xHandleTaskServ);

		xTaskCreate(vTaskUart1,
                "TaskUart1",
                128,
                NULL,
                2,
                &xHandleTaskUart1);
}

/*!
 * @brief       Led toggle task
 *
 * @param       pvParameters - passed into the task function as the function parameters
 *
 * @retval      None
 */
void vTaskLedToggle(void* pvParameters)
{
    while (1)
    {
        /* Toggle LED2 */
        APM_MINI_LEDToggle(LED2);
        /* Task blocking time Delay */
        vTaskDelay(500);
    }
}

void vTaskMotor(void* pvParameters)
{
		int dcount = 0, run = 0;
//		uint8_t buf[10] = {1,2,3,4,5,6,7,8,9,0};
		GPIO_WriteBitValue(GPIOB,GPIO_PIN_13,Bit_SET);
		TMR_Enable(TMR1);
		
		
		m_cur_dir = 0;
		m_cur_pos = 0;
		m_cur_stepnum = 0;
		motor_right(360, 50, 300);
		motor_left(360, 50, 30);
		
		GPIO_WriteBitValue(GPIOB,GPIO_PIN_13,Bit_RESET);
    while (1)
    {
				//motor_leftright();
			
			if(key1_press) {
				if(run==0) {
					run = 1;
					GPIO_WriteBitValue(GPIOB,GPIO_PIN_13,Bit_SET);
				} else {
					run = 0;
					GPIO_WriteBitValue(GPIOB,GPIO_PIN_13,Bit_RESET);
				}
				vTaskDelay(211);
				key1_press = 0;
			}
			if(run)
			{
				if(dcount==0)
				{		
					motor_left(140, 50, 300);
					dcount = 1;
				} else {
					motor_right(140, 50, 300);
					dcount = 0;
				}
			}
					//key1_press = 0;
				//}
				//if(key2_press) {
					//key2_press = 0;

				//}
				
				vTaskDelay(111);
    }
}

void vTaskServ(void* pvParameters)
{
		int serv_step = 0;
		TMR_Enable(TMR15);
		
		TMR_SetCompare1(TMR15, SERV1_IN);  //CC1
		TMR_SetCompare2(TMR15, SERV2_IN);  //CC1
		
    while (1)
    {
			serv_step = 0;
			if(key3_press || uart_val>0)
			{
				for(serv_step=0;serv_step<4;serv_step++)
				{
					if(serv_step==0)
					{
							TMR_SetCompare1(TMR15, SERV1_OUT);  //CC1
							TMR_SetCompare2(TMR15, SERV2_IN);  //CC1
					} else if(serv_step==1)
					{
							TMR_SetCompare1(TMR15, SERV1_IN);  //CC1
							TMR_SetCompare2(TMR15, SERV2_IN);  //CC1
					} else if(serv_step==2)
					{
							TMR_SetCompare1(TMR15, SERV1_IN);  //CC1
							TMR_SetCompare2(TMR15, SERV2_OUT);  //CC1
					} else if(serv_step==3)
					{
							TMR_SetCompare1(TMR15, SERV1_IN);  //CC1
							TMR_SetCompare2(TMR15, SERV2_IN);  //CC1
					}
					vTaskDelay(200);
				}
				key3_press=0;
				if(uart_val>0) uart_val--;
				serv_step = 0;
			}
//				serv_step++;
//				if(serv_step>=4) serv_step = 0;
				vTaskDelay(100);
    }
}

void vTaskUart1(void* pvParameters)
{
	
		int timeout = 0;
		static int val = 0;
		while (1)
    {
				timeout = 0;
//        if (USART_ReadStatusFlag(MINI_COM1, USART_FLAG_RXBNE) == RESET)
//        {
//        } else {
//						val = USART_RxData(MINI_COM1);				
//						USART_ClearStatusFlag(MINI_COM1, USART_FLAG_RXBNE);
//						if(val>'0' && val<='9')
//						uart_val += (val - '0');
//				}

				vTaskDelay(50);
    }
}


//					//get   A10   6D0   360    0
void vTaskKey(void* pvParameters)
{
		//static u16 adcData[5];
		static u16 keyData_o = 0x5000;
		static u16 keyData1 = 0;
		static u16 keyData2 = 0;
		static u16 keyData3 = 0;
		static u16 retry = 0;
		static u8 keyData_i = 0;
    while (1)
    {
				if(GPIO_ReadInputBit(GPIOC, GPIO_PIN_13)==0)
				{
					keyData1++;
					if(keyData1>6) key1_press = 1;
				} else {
					keyData1 = 0;
				}
				if(GPIO_ReadInputBit(GPIOC, GPIO_PIN_14)==0)
				{
					keyData2++;
					if(keyData2>6) key2_press = 1;
				} else {
					keyData2 = 0;
				}
				if(GPIO_ReadInputBit(GPIOB, GPIO_PIN_9)==0)
				{
					keyData3++;
					if(keyData3>6) key3_press = 1;
				} else {
					keyData3 = 0;
				}
					
				vTaskDelay(40);
				
		}
}

/*!
 * @brief       Led toggle task
 *
 * @param       pvParameters - passed into the task function as the function parameters
 *
 * @retval      None
 */
void vTaskUsartTest(void* pvParameters)
{

}

/*!
 * @brief       Compares two buffers
 *
 * @param       buf1:    First buffer to be compared
 *
 * @param       buf1:    Second buffer to be compared
 *
 * @param       size:    Buffer size
 *
 * @retval      Return SET if buf1 = buf2. If not then return RESET
 */
BOOL BufferCompare(uint8_t* buf1, uint8_t* buf2, uint8_t size)
{
    uint8_t i;

    for (i = 0; i < size; i++)
    {
        if (buf1[i] != buf2[i])
        {
            return FALSE;
        }
    }

    return TRUE;
}

/*!
 * @brief       Delay
 *
 * @param       count:  delay count
 *
 * @retval      None
 */
void Delay(uint32_t count)
{
    volatile uint32_t delay = count;
    while (delay--);
}

/**@} end of group FreeRTOS_Functions */
/**@} end of group FreeRTOS */
/**@} end of group Examples */

