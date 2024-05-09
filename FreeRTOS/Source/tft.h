#ifndef _TFT_H_
#define _TFT_H_

#include "public.h"



//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE           	 0x001F  
#define BRED             0XF81F
#define GRED 			       0XFFE0
#define GBLUE			       0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			     0XBC40 //棕色
#define BRRED 			     0XFC07 //棕红色
#define GRAY  			     0X8430 //灰色
#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
#define LIGHTGREEN     	 0X841F //浅绿色
#define LGRAY 			     0XC618 //浅灰色(PANNEL),窗体背景色
#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)


void TFT_clear(void);
void TFT_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color);//指定区域填充颜色
void TFT_DrawPoint(u16 x,u16 y,u16 color);//在指定位置画一个点
void TFT_DrawLine(u16 x1,u16 y1,u16 x2,u16 y2,u16 color);//在指定位置画一条线
void TFT_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2,u16 color);//在指定位置画一个矩形
void Draw_Circle(u16 x0,u16 y0,u8 r,u16 color);//在指定位置画一个圆

void TFT_ShowChinese(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//显示汉字串
void TFT_ShowChinese12x12(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//显示单个12x12汉字
void TFT_ShowChinese14x14(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//显示单个14x14汉字
void TFT_ShowChinese16x16(u16 x,u16 y,const u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//显示单个16x16汉字
void TFT_ShowChinese24x24(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//显示单个24x24汉字
void TFT_ShowChinese32x32(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//显示单个32x32汉字

void TFT_ShowChar(u16 x,u16 y,u8 num,u16 fc,u16 bc,u8 sizey,u8 mode);//显示一个字符
void TFT_ShowString(u16 x,u16 y,const u8 *p,u16 fc,u16 bc,u8 sizey,u8 mode);//显示字符串
void TFT_ShowString_R(u16 x,u16 y,const u8 *p,u16 fc,u16 bc,u8 sizey,u8 mode);
void TFT_ShowStringx(u16 x,u16 y,const u8 *p,u16 fc,u16 bc,u8 sizey,u8 mode);//显示字符串(中英)
void TFT_ShowChineseString_R(u16 x,u16 y,const u8 *p,u16 fc,u16 bc,u8 sizey,u8 mode);

u32 mypow(u8 m,u8 n);//求幂
void TFT_ShowIntNum(u16 x,u16 y,u16 num,u8 len,u16 fc,u16 bc,u8 sizey);//显示整数变量
void TFT_ShowFloatNum1(u16 x,u16 y,float num,u8 len,u16 fc,u16 bc,u8 sizey);//显示两位小数变量

void TFT_ShowPicture(u16 x,u16 y,u16 length,u16 width,const u8 pic[]);//显示图片
void TFT_Address_Set( u16 x1, u16 y1, u16 x2, u16 y2 );

void TFT_ShowMainScreen(uint8_t idx);
void TFT_ShowMainScreen_txt(uint8_t idx);


void TFT_ShowSecondScreen(uint8_t idx, uint8_t chg_header);
void TFT_SecondScreen_Item_Chg(uint8_t idx);
void TFT_SecondScreen_Val_Chg(uint8_t dir);



void TFT_ShowSecondScreen1_txt(uint8_t idx);
void TFT_ShowSecondScreen2(uint8_t idx);
void TFT_ShowSecondScreen2a_txt(uint8_t idx);
void TFT_ShowSecondScreen2b_txt(uint8_t idx);
void TFT_ShowSecondScreen3(uint8_t idx);
void TFT_ShowSecondScreen3_txt(uint8_t idx);
void TFT_ShowSecondScreen4(uint8_t idx);
void TFT_ShowSecondScreen4_txt(uint8_t idx);
void TFT_ShowSecondScreen5(uint8_t idx);
void TFT_ShowSecondScreen5_txt(uint8_t idx);
void TFT_ShowSecondScreen6(uint8_t idx);
void TFT_ShowSecondScreen6_txt(uint8_t idx);
void TFT_Show_Menu_Item(uint8_t pos, uint8_t *title, uint8_t *value, uint8_t status);
void TFT_Show_Menu_Item_Val(uint8_t pos, uint8_t *value, uint8_t status);
void Num_To_Txt(uint16_t num, uint8_t *p, uint8_t len);


#endif
