#include "serv.h"




void Serv_Gpio_Init(void)
{
		GPIO_Config_T GPIO_InitStructure;
		RCM_EnableAHBPeriphClock(RCM_AHB_PERIPH_GPIOA);
		RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_TMR15);
	

		//timer15
		GPIO_InitStructure.pin= (GPIO_PIN_2 | GPIO_PIN_3);
    GPIO_InitStructure.mode = GPIO_MODE_AF;
    GPIO_InitStructure.outtype = GPIO_OUT_TYPE_PP;
    GPIO_InitStructure.speed = GPIO_SPEED_50MHz;
    GPIO_InitStructure.pupd = GPIO_PUPD_NO;	
		GPIO_Config(GPIOA,&GPIO_InitStructure);
		GPIO_ConfigPinAF(GPIOA, GPIO_PIN_SOURCE_2, GPIO_AF_PIN0); 
		GPIO_ConfigPinAF(GPIOA, GPIO_PIN_SOURCE_3, GPIO_AF_PIN0); 


}
										
void Serv_Timer_Init(void) {
	TMR_TimeBase_T timeBaseConfig;
	TMR_OCConfig_T OCcongigStruct;

	TMR_ConfigInternalClock(TMR15);
	
	TMR_ConfigTimeBaseStruct(&timeBaseConfig);
	timeBaseConfig.counterMode = TMR_COUNTER_MODE_UP;
	timeBaseConfig.period = 20000;  //autoreload  //50Hz
	timeBaseConfig.div = 47;  // /48 = 1M
	TMR_ConfigTimeBase(TMR15, &timeBaseConfig);

//	GPIO_ConfigPinRemap(GPIO_PARTIAL_REMAP_TMR1);	
	TMR_EnableAUTOReload(TMR15);
	//TMR_SetCompare1(TMR1, 0x88);  //CC1
	//TMR_SetCounter(TMR1, 0x5fff);
	
	OCcongigStruct.OC_Mode = TMR_OC_MODE_PWM1;
	OCcongigStruct.OC_Polarity = TMR_OC_POLARITY_HIGH;
	OCcongigStruct.OC_OutputState = TMR_OUTPUT_STATE_ENABLE;
	OCcongigStruct.OC_NPolarity = TMR_OC_NPOLARITY_LOW;
	OCcongigStruct.OC_OutputNState = TMR_OUTPUT_NSTATE_DISABLE;
	OCcongigStruct.OC_Idlestate = TMR_OCIDLESTATE_RESET;
	OCcongigStruct.OC_NIdlestate = TMR_OCNIDLESTATE_RESET;
	OCcongigStruct.Pulse = 0x2df;  //CC1
	TMR_OC1Config(TMR15, &OCcongigStruct);
	OCcongigStruct.OC_Mode = TMR_OC_MODE_PWM1;
	OCcongigStruct.OC_Polarity = TMR_OC_POLARITY_HIGH;
	OCcongigStruct.OC_OutputState = TMR_OUTPUT_STATE_ENABLE;
	OCcongigStruct.OC_NPolarity = TMR_OC_NPOLARITY_LOW;
	OCcongigStruct.OC_OutputNState = TMR_OUTPUT_NSTATE_DISABLE;
	OCcongigStruct.OC_Idlestate = TMR_OCIDLESTATE_RESET;
	OCcongigStruct.OC_NIdlestate = TMR_OCNIDLESTATE_RESET;
	OCcongigStruct.Pulse = 0x2df;  //CC1
	TMR_OC2Config(TMR15, &OCcongigStruct);
	
	
	
	TMR_EnablePWMOutputs(TMR15);
	
	//TMR_ClearIntFlag(TMR15, TMR_INT_FLAG_UPDATE);
	//TMR_ClearIntFlag(TMR15, TMR_INT_FLAG_CH3);
  //TMR_EnableInterrupt(TMR15, TMR_INT_UPDATE);					//开启中断
  //TMR_EnableInterrupt(TMR15, TMR_INT_CH3);					//开启中断
	
	//NVIC_EnableIRQRequest(TMR1_CC_IRQn, 5);			//定时器1
	//NVIC_EnableIRQRequest(TMR1_BRK_UP_TRG_COM_IRQn, 5);			//定时器1

}


