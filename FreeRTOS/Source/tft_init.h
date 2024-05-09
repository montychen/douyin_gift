#ifndef _TFT_INIT_H_
#define _TFT_INIT_H_

#include "public.h"

#define TFT_DB0_A GPIO_PIN_6   //A6
#define TFT_DB1 GPIO_PIN_0
#define TFT_DB2 GPIO_PIN_1
#define TFT_DB3 GPIO_PIN_2
#define TFT_DB4 GPIO_PIN_10
#define TFT_DB5 GPIO_PIN_11
#define TFT_DB6_A GPIO_PIN_12   //A12
#define TFT_DB7 GPIO_PIN_4
#define TFT_CS GPIO_PIN_12
#define TFT_RS GPIO_PIN_7
#define TFT_RST GPIO_PIN_6
#define TFT_WR GPIO_PIN_3
#define TFT_RD_A GPIO_PIN_15   //A15
#define TFT_BL GPIO_PIN_8

#define USE_HORIZONTAL 1  //设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏


#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 128
#define LCD_H 160

#else
#define LCD_W 160
#define LCD_H 128
#endif

void tft_gpio_init(void);
void tft_init(void);
void tft_reset(void);
void tft_write_command(u8 cmd);
void tft_write_data8(u8 data);
void tft_write_data16(u16 data);
void tft_senddata(u8 data);

#endif
