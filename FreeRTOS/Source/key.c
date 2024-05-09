#include "key.h"


extern uint8_t screanMain_idx_o;
extern uint8_t screanMain_idx;



void Key_Init(void)
{
    GPIO_Config_T gpioConfig;
    /* RCM Enable*/
    RCM_EnableAHBPeriphClock(RCM_AHB_PERIPH_GPIOB);
    RCM_EnableAHBPeriphClock(RCM_AHB_PERIPH_GPIOC);
    RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_SYSCFG);
    /* GPIO Configuration */
    gpioConfig.pin = GPIO_PIN_9;
    gpioConfig.mode = GPIO_MODE_IN;
    gpioConfig.pupd = GPIO_PUPD_PU;
    gpioConfig.speed = GPIO_SPEED_50MHz;
    GPIO_Config(GPIOB, &gpioConfig);
    gpioConfig.pin = GPIO_PIN_13 | GPIO_PIN_14;
    gpioConfig.mode = GPIO_MODE_IN;
    gpioConfig.pupd = GPIO_PUPD_PU;
    gpioConfig.speed = GPIO_SPEED_50MHz;
    GPIO_Config(GPIOC, &gpioConfig);


}


/*!
 * @brief       ADC_Isr
 *
 * @param       None
 *
 * @retval      None
 *
 * @note        This function need to put into ADC1_IRQHandler in apm32f0xx_int.c
 */
void Key_ADC_Isr()
{
    uint32_t adcData = 0;
    uint32_t voltage = 0;

    if (ADC_ReadIntFlag(ADC_INT_FLAG_CS) == SET)
    {
        ADC_ClearIntFlag(ADC_INT_FLAG_CS);
        /* Read ADC Conversion value */
        adcData = ADC_ReadConversionValue();
        /*  voltage(mV) =  adcData * (3300mV / 4095) */
        //voltage = (adcData * 3300) / 4095;
        /* output to serial port */
        //printf("\r\n volatage : %d  mV\r\n", voltage);
    }
}


u16 Key_ADC_GetValue(void)
{
		uint16_t retry = 0;
		while (!ADC_ReadStatusFlag(ADC_FLAG_ADRDY))
		{
				retry++;
				if(retry>200) return 5000;
		}
		retry = 0;
		ADC_StartConversion();
		while(ADC_ReadStatusFlag(ADC_FLAG_CC) == RESET)
		{
				retry++;
				if(retry>200) return 5000;
		}
		return ADC_ReadConversionValue();
		
}

u16 adc_key_remove_shake(void)
{
		u16 key_data;	
		key_data=Key_ADC_GetValue();		
    if(key_data<300000)                             
              return key1;
    else if(key_data>1000 && key_data<1100)        
            return key2;
    else if(key_data>1200 && key_data<1960)       
              return key3;
    else if(key_data>2000 && key_data<3000)     
            return key4;
    else
            return 0XFF;
}

