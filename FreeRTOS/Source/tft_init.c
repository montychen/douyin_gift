#include "tft_init.h"


void tft_gpio_init(void) {
		GPIO_Config_T GPIO_InitStructure;
		GPIO_InitStructure.pin= (TFT_DB0_A | TFT_DB6_A | TFT_RD_A);
    GPIO_InitStructure.mode = GPIO_MODE_OUT;
    GPIO_InitStructure.outtype = GPIO_OUT_TYPE_PP;
    GPIO_InitStructure.speed = GPIO_SPEED_50MHz;
    GPIO_InitStructure.pupd = GPIO_PUPD_NO;	
		GPIO_Config(GPIOA,&GPIO_InitStructure);
		GPIO_InitStructure.pin= (TFT_DB1 | TFT_DB2 | TFT_DB3 | TFT_DB4 | TFT_DB5 | TFT_DB7 | TFT_CS | TFT_RS | TFT_RST | TFT_WR | TFT_BL);
    GPIO_InitStructure.mode = GPIO_MODE_OUT;
    GPIO_InitStructure.outtype = GPIO_OUT_TYPE_PP;
    GPIO_InitStructure.speed = GPIO_SPEED_50MHz;
    GPIO_InitStructure.pupd = GPIO_PUPD_NO;	
		GPIO_Config(GPIOB,&GPIO_InitStructure);
	
		GPIO_WriteBitValue(GPIOB, TFT_BL, Bit_SET);
		
}

void tft_init(void) {
		//------ Initialization Code  --------------//
		//---ST7735S Reset Sequence--------//
		GPIO_WriteBitValue(GPIOB, TFT_RST, Bit_RESET);
		Delay2(5000);	// Delay 1 ms
		GPIO_WriteBitValue(GPIOB, TFT_RST, Bit_SET);
		Delay2(50000);	// Delay 10 ms
		//-------------------------------End ST7735S Reset Sequence --------------------------------------//
		Delay2(100000);	// 150ms This delay time is necessary
		tft_write_command(0x11); //Sleep out
		Delay2(100000); //Delay 120ms
		//------------------------------------ST7735S Frame Rate-----------------------------------------//
		tft_write_command(0xB1);
		tft_write_data8(0x05);
		tft_write_data8(0x3C);
		tft_write_data8(0x3C);
		tft_write_command(0xB2);
		tft_write_data8(0x05);
		tft_write_data8(0x3C);
		tft_write_data8(0x3C);
		tft_write_command(0xB3);
		tft_write_data8(0x05);
		tft_write_data8(0x3C);
		tft_write_data8(0x3C);
		tft_write_data8(0x05);
		tft_write_data8(0x3C);
		tft_write_data8(0x3C);
		//------------------------------------End ST7735S Frame Rate-----------------------------------------//
		tft_write_command(0xB4); //Dot inversion
		tft_write_data8(0x03);
		//------------------------------------ST7735S Power Sequence-----------------------------------------//
		tft_write_command(0xC0);
		tft_write_data8(0x28);
		tft_write_data8(0x08);
		tft_write_data8(0x04);
		tft_write_command(0xC1);
		tft_write_data8(0XC0);
		tft_write_command(0xC2);
		tft_write_data8(0x0D);
		tft_write_data8(0x00);
		tft_write_command(0xC3);
		tft_write_data8(0x8D);
		tft_write_data8(0x2A);
		tft_write_command(0xC4);
		tft_write_data8(0x8D);
		tft_write_data8(0xEE);
		//---------------------------------End ST7735S Power Sequence-------------------------------------//
		tft_write_command(0xC5); //VCOM
		tft_write_data8(0x12);

		//tft_write_command(0xC7); //VCOM
		//tft_write_data8(0x1f);

		tft_write_command(0x36); //MX, MY, RGB mode
		tft_write_data8(0x68);//00,08 ,C8 
		//------------------------------------ST7735S Gamma Sequence-----------------------------------------//
		tft_write_command(0xE0);
		tft_write_data8(0x04);
		tft_write_data8(0x22);
		tft_write_data8(0x07);
		tft_write_data8(0x0A);
		tft_write_data8(0x2E);
		tft_write_data8(0x30);
		tft_write_data8(0x25);
		tft_write_data8(0x2A);
		tft_write_data8(0x28);
		tft_write_data8(0x26);
		tft_write_data8(0x2E);
		tft_write_data8(0x3A);
		tft_write_data8(0x00);
		tft_write_data8(0x01);
		tft_write_data8(0x03);
		tft_write_data8(0x13);
		tft_write_command(0xE1);
		tft_write_data8(0x04);
		tft_write_data8(0x16);
		tft_write_data8(0x06);
		tft_write_data8(0x0D);
		tft_write_data8(0x2D);
		tft_write_data8(0x26);
		tft_write_data8(0x23);
		tft_write_data8(0x27);
		tft_write_data8(0x27);
		tft_write_data8(0x25);
		tft_write_data8(0x2D);
		tft_write_data8(0x3B);
		tft_write_data8(0x00);
		tft_write_data8(0x01);
		tft_write_data8(0x04);
		tft_write_data8(0x13);
		//------------------------------------End ST7735S Gamma Sequence-----------------------------------------//
		tft_write_command(0x3A); //65k mode
		tft_write_data8(0x05);

		tft_write_command(0x2A);	//X Address Setup
		tft_write_data8(0x00);
		tft_write_data8(0x00);
		tft_write_data8(0x00);
		tft_write_data8(0x7f);

		tft_write_command(0x2B);	//Y Address Setup
		tft_write_data8(0x00);
		tft_write_data8(0x00);
		tft_write_data8(0x00);
		tft_write_data8(0x9f);

		tft_write_command(0x29); //Display on
		
//		tft_write_command(0x2C);
//		for(int i=0;i<2000;i++) tft_write_data16(0xF00F);


}

void tft_reset(void) {
}

void tft_write_command(u8 cmd) {
		GPIO_WriteBitValue(GPIOA, TFT_RD_A, Bit_SET);
		GPIO_WriteBitValue(GPIOB, TFT_RS, Bit_RESET);
		GPIO_WriteBitValue(GPIOB, TFT_CS, Bit_RESET);
	
		GPIO_WriteBitValue(GPIOB, TFT_WR, Bit_RESET);
		tft_senddata(cmd);
		GPIO_WriteBitValue(GPIOB, TFT_WR, Bit_SET);
		GPIO_WriteBitValue(GPIOB, TFT_CS, Bit_SET);

}

void tft_write_data8(u8 data) {
		GPIO_WriteBitValue(GPIOA, TFT_RD_A, Bit_SET);
		GPIO_WriteBitValue(GPIOB, TFT_RS, Bit_SET);
		GPIO_WriteBitValue(GPIOB, TFT_CS, Bit_RESET);
	
		tft_senddata(data);
		GPIO_WriteBitValue(GPIOB, TFT_WR, Bit_RESET);
		GPIO_WriteBitValue(GPIOB, TFT_WR, Bit_SET);
		GPIO_WriteBitValue(GPIOB, TFT_CS, Bit_SET);
}

void tft_write_data16(u16 data) {
//		GPIO_WriteBitValue(GPIOA, TFT_RD_A, Bit_SET);
//		GPIO_WriteBitValue(GPIOB, TFT_RS, Bit_SET);
//		GPIO_WriteBitValue(GPIOB, TFT_CS, Bit_RESET);
//	
//		GPIO_WriteBitValue(GPIOB, TFT_WR, Bit_RESET);
//		tft_senddata(data>>8 & 0xFF);
//		GPIO_WriteBitValue(GPIOB, TFT_WR, Bit_SET);
//		GPIO_WriteBitValue(GPIOB, TFT_CS, Bit_SET);

//	
//		GPIO_WriteBitValue(GPIOA, TFT_RD_A, Bit_SET);
//		GPIO_WriteBitValue(GPIOB, TFT_RS, Bit_SET);
//		GPIO_WriteBitValue(GPIOB, TFT_CS, Bit_RESET);
//	
//		GPIO_WriteBitValue(GPIOB, TFT_WR, Bit_RESET);
//		tft_senddata(data);
//		GPIO_WriteBitValue(GPIOB, TFT_WR, Bit_SET);
//		GPIO_WriteBitValue(GPIOB, TFT_CS, Bit_SET);

		tft_write_data8(data>>8 & 0xFF);
		tft_write_data8(data);
}

void tft_senddata(u8 data) {
		GPIO_WriteBitValue(GPIOA, TFT_DB0_A, (data & 0x01)?Bit_SET:Bit_RESET);
		GPIO_WriteBitValue(GPIOB, TFT_DB1, (data & 0x02)?Bit_SET:Bit_RESET);
		GPIO_WriteBitValue(GPIOB, TFT_DB2, (data & 0x04)?Bit_SET:Bit_RESET);
		GPIO_WriteBitValue(GPIOB, TFT_DB3, (data & 0x08)?Bit_SET:Bit_RESET);
		GPIO_WriteBitValue(GPIOB, TFT_DB4, (data & 0x10)?Bit_SET:Bit_RESET);
		GPIO_WriteBitValue(GPIOB, TFT_DB5, (data & 0x20)?Bit_SET:Bit_RESET);
		GPIO_WriteBitValue(GPIOA, TFT_DB6_A, (data & 0x40)?Bit_SET:Bit_RESET);
		GPIO_WriteBitValue(GPIOB, TFT_DB7, (data & 0x80)?Bit_SET:Bit_RESET);
}


