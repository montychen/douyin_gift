#include "tft.h"
#include "tft_init.h"
#include "tft_font.h"
#include "tft_pic.h"

extern uint8_t screanSecondx;   //第几个二级菜单
extern uint8_t screanMain_idx_o;
extern uint8_t screanMain_idx;
extern uint8_t screanSecond_x;
extern uint8_t screanSecond_idx_o;
extern uint8_t screanSecond_idx;
extern uint8_t screanSecond_status;
extern uint8_t screanSecondx2;
extern uint8_t menuVal[6][10];

uint8_t menutxt1[] = " 7CH";
uint8_t menutxt2[] = "14CH";
uint8_t menutxt3[] = "21CH";
uint8_t menutxt4[] = "中文";
uint8_t menutxt5[] = "English";
uint8_t menutxt6[] = "开";
uint8_t menutxt7[] = "关";

uint8_t valtxt[6] = {0};
uint8_t *valtxttmp;

void TFT_ShowMainScreen(uint8_t idx)
{
		TFT_Fill(0x00, 0x00, 0xA0, 0x80, 0x0909);  //clear

		TFT_ShowPicture(0x0 + 19, 0x0 + 8, 32, 32, icon1);
		TFT_ShowPicture(0x0 + 64, 0x0 + 8, 32, 32, icon2);
		TFT_ShowPicture(0x0 + 109, 0x0 + 8, 32, 32, icon3);
		TFT_ShowPicture(0x0 + 19, 0x0 + 70, 32, 32, icon4);
		TFT_ShowPicture(0x0 + 64, 0x0 + 70, 32, 32, icon5);
		TFT_ShowPicture(0x0 + 109, 0x0 + 70, 32, 32, icon6);
	
		
	
}

void TFT_ShowMainScreen_txt(uint8_t idx)
{
		TFT_ShowString(0x0 + 22, 0x0 + 43, "DMX", 0x001F, (idx==0?0xFFFF:0x0909), 16, 0);
		if(screanMain_idx_o!=idx && screanMain_idx_o==0) {
				TFT_Fill(0x0 + 16, 0x0 + 41, 0x0 + 53, 0x0 + 43, 0x0909);//横
				TFT_Fill(0x0 + 16, 0x0 + 59, 0x0 + 53, 0x0 + 61, 0x0909);//横
				TFT_Fill(0x0 + 16, 0x0 + 43, 0x0 + 22, 0x0 + 59, 0x0909);
				TFT_Fill(0x0 + 46, 0x0 + 43, 0x0 + 53, 0x0 + 59, 0x0909);
		}
		TFT_ShowChinese(0x0 + 63, 0x0 + 43, "手", 0x001F, (idx==1?0xFFFF:0x0909), 16, 0);
		TFT_ShowChinese(0x0 + 81, 0x0 + 43, "动", 0x001F, (idx==1?0xFFFF:0x0909), 16, 0);
		if(screanMain_idx_o!=idx && screanMain_idx_o==1) {
				TFT_Fill(0x0 + 61, 0x0 + 41, 0x0 + 99, 0x0 + 43, 0x0909);//横
				TFT_Fill(0x0 + 61, 0x0 + 59, 0x0 + 99, 0x0 + 61, 0x0909);//横
				TFT_Fill(0x0 + 61, 0x0 + 43, 0x0 + 63, 0x0 + 59, 0x0909);
				TFT_Fill(0x0 + 79, 0x0 + 43, 0x0 + 81, 0x0 + 59, 0x0909);
				TFT_Fill(0x0 + 96, 0x0 + 43, 0x0 + 99, 0x0 + 59, 0x0909);
		}
		TFT_ShowChinese(0x0 + 108, 0x0 + 43, "自", 0x001F, (idx==2?0xFFFF:0x0909), 16, 0);
		TFT_ShowChinese(0x0 + 126, 0x0 + 43, "走", 0x001F, (idx==2?0xFFFF:0x0909), 16, 0);
		if(screanMain_idx_o!=idx && screanMain_idx_o==2) {
				TFT_Fill(45 + 61, 0x0 + 41, 45 + 99, 0x0 + 43, 0x0909);//横
				TFT_Fill(45 + 61, 0x0 + 59, 45 + 99, 0x0 + 61, 0x0909);//横
				TFT_Fill(45 + 61, 0x0 + 43, 45 + 63, 0x0 + 59, 0x0909);
				TFT_Fill(45 + 79, 0x0 + 43, 45 + 81, 0x0 + 59, 0x0909);
				TFT_Fill(45 + 96, 0x0 + 43, 45 + 99, 0x0 + 59, 0x0909);
		}
		TFT_ShowChinese(0x0 + 18, 0x0 + 105, "设", 0x001F, (idx==3?0xFFFF:0x0909), 16, 0);
		TFT_ShowChinese(0x0 + 36, 0x0 + 105, "置", 0x001F, (idx==3?0xFFFF:0x0909), 16, 0);
		if(screanMain_idx_o!=idx && screanMain_idx_o==3) {
				TFT_Fill(0x0 + 16, 0x0 + 103, 0x0 + 54, 0x0 + 105, 0x0909);//横
				TFT_Fill(0x0 + 16, 0x0 + 121, 0x0 + 54, 0x0 + 123, 0x0909);//横
				TFT_Fill(0x0 + 16, 0x0 + 105, 0x0 + 18, 0x0 + 121, 0x0909);
				TFT_Fill(0x0 + 34, 0x0 + 105, 0x0 + 36, 0x0 + 121, 0x0909);
				TFT_Fill(0x0 + 51, 0x0 + 105, 0x0 + 54, 0x0 + 121, 0x0909);
		}
		TFT_ShowChinese(0x0 + 63, 0x0 + 105, "语", 0x001F, (idx==4?0xFFFF:0x0909), 16, 0);
		TFT_ShowChinese(0x0 + 81, 0x0 + 105, "言", 0x001F, (idx==4?0xFFFF:0x0909), 16, 0);
		if(screanMain_idx_o!=idx && screanMain_idx_o==4) {
				TFT_Fill(45 + 16, 0x0 + 103, 45 + 54, 0x0 + 105, 0x0909);//横
				TFT_Fill(45 + 16, 0x0 + 121, 45 + 54, 0x0 + 123, 0x0909);//横
				TFT_Fill(45 + 16, 0x0 + 105, 45 + 18, 0x0 + 121, 0x0909);
				TFT_Fill(45 + 34, 0x0 + 105, 45 + 36, 0x0 + 121, 0x0909);
				TFT_Fill(45 + 51, 0x0 + 105, 45 + 54, 0x0 + 121, 0x0909);
		}
		TFT_ShowChinese(0x0 + 108, 0x0 + 105, "信", 0x001F, (idx==5?0xFFFF:0x0909), 16, 0);
		TFT_ShowChinese(0x0 + 126, 0x0 + 105, "息", 0x001F, (idx==5?0xFFFF:0x0909), 16, 0);
		if(screanMain_idx_o!=idx && screanMain_idx_o==5) {
				TFT_Fill(90 + 16, 0x0 + 103, 90 + 54, 0x0 + 105, 0x0909);//横
				TFT_Fill(90 + 16, 0x0 + 121, 90 + 54, 0x0 + 123, 0x0909);//横
				TFT_Fill(90 + 16, 0x0 + 105, 90 + 18, 0x0 + 121, 0x0909);
				TFT_Fill(90 + 34, 0x0 + 105, 90 + 36, 0x0 + 121, 0x0909);
				TFT_Fill(90 + 51, 0x0 + 105, 90 + 54, 0x0 + 121, 0x0909);
		}

		if(idx==0)
		{
				TFT_Fill(0x0 + 16, 0x0 + 41, 0x0 + 53, 0x0 + 43, 0xFFFF);//横
				TFT_Fill(0x0 + 16, 0x0 + 59, 0x0 + 53, 0x0 + 61, 0xFFFF);//横
				TFT_Fill(0x0 + 16, 0x0 + 43, 0x0 + 22, 0x0 + 59, 0xFFFF);
				TFT_Fill(0x0 + 46, 0x0 + 43, 0x0 + 53, 0x0 + 59, 0xFFFF);
		} else if(idx==1)
		{
				TFT_Fill(0x0 + 61, 0x0 + 41, 0x0 + 99, 0x0 + 43, 0xFFFF);//横
				TFT_Fill(0x0 + 61, 0x0 + 59, 0x0 + 99, 0x0 + 61, 0xFFFF);//横
				TFT_Fill(0x0 + 61, 0x0 + 43, 0x0 + 63, 0x0 + 59, 0xFFFF);
				TFT_Fill(0x0 + 79, 0x0 + 43, 0x0 + 81, 0x0 + 59, 0xFFFF);
				TFT_Fill(0x0 + 96, 0x0 + 43, 0x0 + 99, 0x0 + 59, 0xFFFF);
		} else if(idx==2)
		{
				TFT_Fill(45 + 61, 0x0 + 41, 45 + 99, 0x0 + 43, 0xFFFF);//横
				TFT_Fill(45 + 61, 0x0 + 59, 45 + 99, 0x0 + 61, 0xFFFF);//横
				TFT_Fill(45 + 61, 0x0 + 43, 45 + 63, 0x0 + 59, 0xFFFF);
				TFT_Fill(45 + 79, 0x0 + 43, 45 + 81, 0x0 + 59, 0xFFFF);
				TFT_Fill(45 + 96, 0x0 + 43, 45 + 99, 0x0 + 59, 0xFFFF);
		} else if(idx==3)
		{
				TFT_Fill(0x0 + 16, 0x0 + 103, 0x0 + 54, 0x0 + 105, 0xFFFF);//横
				TFT_Fill(0x0 + 16, 0x0 + 121, 0x0 + 54, 0x0 + 123, 0xFFFF);//横
				TFT_Fill(0x0 + 16, 0x0 + 105, 0x0 + 18, 0x0 + 121, 0xFFFF);
				TFT_Fill(0x0 + 34, 0x0 + 105, 0x0 + 36, 0x0 + 121, 0xFFFF);
				TFT_Fill(0x0 + 51, 0x0 + 105, 0x0 + 54, 0x0 + 121, 0xFFFF);
		} else if(idx==4)
		{
				TFT_Fill(45 + 16, 0x0 + 103, 45 + 54, 0x0 + 105, 0xFFFF);//横
				TFT_Fill(45 + 16, 0x0 + 121, 45 + 54, 0x0 + 123, 0xFFFF);//横
				TFT_Fill(45 + 16, 0x0 + 105, 45 + 18, 0x0 + 121, 0xFFFF);
				TFT_Fill(45 + 34, 0x0 + 105, 45 + 36, 0x0 + 121, 0xFFFF);
				TFT_Fill(45 + 51, 0x0 + 105, 45 + 54, 0x0 + 121, 0xFFFF);
		} else if(idx==5)
		{
				TFT_Fill(90 + 16, 0x0 + 103, 90 + 54, 0x0 + 105, 0xFFFF);//横
				TFT_Fill(90 + 16, 0x0 + 121, 90 + 54, 0x0 + 123, 0xFFFF);//横
				TFT_Fill(90 + 16, 0x0 + 105, 90 + 18, 0x0 + 121, 0xFFFF);
				TFT_Fill(90 + 34, 0x0 + 105, 90 + 36, 0x0 + 121, 0xFFFF);
				TFT_Fill(90 + 51, 0x0 + 105, 90 + 54, 0x0 + 121, 0xFFFF);
		} 
}


void TFT_ShowSecondScreen1(uint8_t idx)
{
	if(idx==0)
	{
	} else if(idx==1)
	{
	} else if(idx==2)
	{
	} else if(idx==3)
	{
	} else if(idx==4)
	{
	} else if(idx==5)
	{
	}
	
}

void TFT_SecondScreen_Item_DMX_Channel(uint8_t screanSecond_status)
{
			if(menuVal[0][1]==0)
			{
				valtxttmp = menutxt1;
			} else if(menuVal[0][1]==1)
			{
				valtxttmp = menutxt2;
			} else if(menuVal[0][1]==2)
			{
				valtxttmp = menutxt3;
			} 
			TFT_Show_Menu_Item(1, "DMX通道", valtxttmp, screanSecond_status);
}

void TFT_SecondScreen_Item_DMX_Channel_Val(uint8_t screanSecond_status)
{
			if(menuVal[0][1]==0)
			{
				valtxttmp = menutxt1;
			} else if(menuVal[0][1]==1)
			{
				valtxttmp = menutxt2;
			} else if(menuVal[0][1]==2)
			{
				valtxttmp = menutxt3;
			} 
			TFT_Show_Menu_Item_Val(1, valtxttmp, 2);
}

void TFT_SecondScreen_Item_Chg(uint8_t idx_item)
{
	if(screanSecondx==0)
	{
		//菜单选中，高亮
		if(idx_item==0)
		{
			Num_To_Txt(menuVal[0][0], valtxt, 3);
			TFT_Show_Menu_Item(0, "DMX地址", valtxt, screanSecond_status);
		}
		if(idx_item==1)
		{
			TFT_SecondScreen_Item_DMX_Channel(screanSecond_status);
		}
		
		//取消高亮
		if(screanSecond_idx_o!=idx_item && screanSecond_idx_o==0)
		{
			Num_To_Txt(menuVal[0][0], valtxt, 3);
			TFT_Show_Menu_Item(0, "DMX地址", valtxt, 0);
		}
		if(screanSecond_idx_o!=idx_item && screanSecond_idx_o==1)
		{
			TFT_SecondScreen_Item_DMX_Channel(0);
		}
	} else if(screanSecondx==1)
	{
		//菜单选中，高亮
		Num_To_Txt(menuVal[screanSecondx][idx_item], valtxt, 3);
		if(idx_item==0)
		{
			TFT_Show_Menu_Item(0, "方向", valtxt, screanSecond_status);
		}
		if(idx_item==1)
		{
			TFT_Show_Menu_Item(1, "总亮度", valtxt, screanSecond_status);
		}
		if(idx_item==2)
		{
			TFT_Show_Menu_Item(2, "红色亮度", valtxt, screanSecond_status);
		}
		if(idx_item==3)
		{
			TFT_Show_Menu_Item(3, "绿色亮度", valtxt, screanSecond_status);
		}
		if(idx_item==4)
		{
			TFT_Show_Menu_Item(4, "蓝色亮度", valtxt, screanSecond_status);
		}
		if(idx_item==5)
		{
			TFT_Show_Menu_Item(0, "白色亮度", valtxt, screanSecond_status);
		}
		if(idx_item==6)
		{
			TFT_Show_Menu_Item(1, "频闪", valtxt, screanSecond_status);
		}
		if(idx_item==7)
		{
			TFT_Show_Menu_Item(2, "宏功能", valtxt, screanSecond_status);
		}
		if(idx_item==8)
		{
			TFT_Show_Menu_Item(3, "宏速度", valtxt, screanSecond_status);
		}
		if(idx_item==9)
		{
			TFT_Show_Menu_Item(4, "复位", valtxt, screanSecond_status);
		}
		
		//取消高亮
		Num_To_Txt(menuVal[screanSecondx][screanSecond_idx_o], valtxt, 3);
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==0)
		{
			TFT_Show_Menu_Item(0, "方向", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==1)
		{
			TFT_Show_Menu_Item(1, "总亮度", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==2)
		{
			TFT_Show_Menu_Item(2, "红色亮度", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==3)
		{
			TFT_Show_Menu_Item(3, "绿色亮度", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==4)
		{
			TFT_Show_Menu_Item(4, "蓝色亮度", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==5)
		{
			TFT_Show_Menu_Item(0, "白色亮度", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==6)
		{
			TFT_Show_Menu_Item(1, "频闪", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==7)
		{
			TFT_Show_Menu_Item(2, "宏功能", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==8)
		{
			TFT_Show_Menu_Item(3, "宏速度", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==9)
		{
			TFT_Show_Menu_Item(4, "复位", "", 0);
		}
	} else if(screanSecondx==2)
	{
		//菜单选中，高亮
		Num_To_Txt(menuVal[screanSecondx][idx_item], valtxt, 3);
		if(idx_item==0)
		{
			TFT_Show_Menu_Item(0, "内置程序", valtxt, screanSecond_status);
		}
		if(idx_item==1)
		{
			TFT_Show_Menu_Item(1, "程序速度", valtxt, screanSecond_status);
		}
		if(idx_item==2)
		{
			TFT_Show_Menu_Item(2, "测试", valtxt, screanSecond_status);
		}
		
		//取消高亮
		Num_To_Txt(menuVal[screanSecondx][screanSecond_idx_o], valtxt, 3);
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==0)
		{
			TFT_Show_Menu_Item(0, "内置程序", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==1)
		{
			TFT_Show_Menu_Item(1, "程序速度", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==2)
		{
			TFT_Show_Menu_Item(2, "测试", valtxt, 0);
		}
	} else if(screanSecondx==3)
	{
		//菜单选中，高亮
		if(idx_item==0)
		{
			TFT_Show_Menu_Item(0, "倒显", (menuVal[screanSecondx][idx_item]?menutxt6:menutxt7), screanSecond_status);
		}
		if(idx_item==1)
		{
			TFT_Show_Menu_Item(1, "背光", (menuVal[screanSecondx][idx_item]?menutxt6:menutxt7), screanSecond_status);
		}
		if(idx_item==2)
		{
			Num_To_Txt(menuVal[screanSecondx][idx_item], valtxt, 3);
			TFT_Show_Menu_Item(2, "恢复设置", valtxt, screanSecond_status);
		}
		
		//取消高亮
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==0)
		{
			TFT_Show_Menu_Item(0, "倒显", (menuVal[screanSecondx][screanSecond_idx_o]?menutxt6:menutxt7), 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==1)
		{
			TFT_Show_Menu_Item(1, "背光", (menuVal[screanSecondx][screanSecond_idx_o]?menutxt6:menutxt7), 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==2)
		{
			Num_To_Txt(menuVal[screanSecondx][screanSecond_idx_o], valtxt, 3);
			TFT_Show_Menu_Item(2, "恢复设置", valtxt, 0);
		}
	} else if(screanSecondx==4)
	{
		if(idx_item==0)
		{
			TFT_Show_Menu_Item(0, "语言", (menuVal[4][0]?menutxt5:menutxt4), screanSecond_status);
		}
	} else if(screanSecondx==5)
	{
		//菜单选中，高亮
		if(idx_item==0)
		{
			TFT_Show_Menu_Item(0, "RF_TFT_8H84Y2364T", "", screanSecond_status);
		}
		if(idx_item==1)
		{
			TFT_Show_Menu_Item(1, "版本", "V1.0", screanSecond_status);
		}
		if(idx_item==2)
		{
			TFT_Show_Menu_Item(2, "日期", "2024/04/25", screanSecond_status);
		}
		if(idx_item==3)
		{
			TFT_Show_Menu_Item(3, "时间", "15:33:20",screanSecond_status);
		}
		if(idx_item==4)
		{
			TFT_Show_Menu_Item(4, "温度", "38.2", screanSecond_status);
		}
		
		//取消高亮
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==0)
		{
			TFT_Show_Menu_Item(0, "RF_TFT_8H84Y2364T", "", 1);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==1)
		{
			TFT_Show_Menu_Item(1, "版本", "V1.0", 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==2)
		{
			TFT_Show_Menu_Item(2, "日期", "2024/04/25", 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==3)
		{
			TFT_Show_Menu_Item(3, "时间", "15:33:20", 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==4)
		{
			TFT_Show_Menu_Item(4, "温度", "38.2", 0);
		}
	}
	
}

void TFT_SecondScreen_Val_Chg(uint8_t dir)
{
	
	if(dir)
	{
		menuVal[screanSecondx][screanSecond_idx]++;
		if(screanSecondx==0 && screanSecond_idx==1)   //DMX通道
		{
			if(menuVal[screanSecondx][screanSecond_idx]==3)
			{
				menuVal[screanSecondx][screanSecond_idx] = 0;
			}
			TFT_SecondScreen_Item_DMX_Channel_Val(2);
		} else if(screanSecondx==3 && screanSecond_idx==0)    //倒显
		{
			if(menuVal[screanSecondx][screanSecond_idx]==2)
			{
				menuVal[screanSecondx][screanSecond_idx] = 0;
			}
			TFT_Show_Menu_Item_Val(screanSecond_idx, (menuVal[screanSecondx][screanSecond_idx]?menutxt6:menutxt7), 2);
		} else if(screanSecondx==3 && screanSecond_idx==1)   //背光
		{
			if(menuVal[screanSecondx][screanSecond_idx]==2)
			{
				menuVal[screanSecondx][screanSecond_idx] = 0;
			}
			TFT_Show_Menu_Item_Val(screanSecond_idx, (menuVal[screanSecondx][screanSecond_idx]?menutxt6:menutxt7), 2);
		} else if(screanSecondx==4 && screanSecond_idx==0)   //语言
		{
			if(menuVal[screanSecondx][screanSecond_idx]==2)
			{
				menuVal[screanSecondx][screanSecond_idx] = 0;
			}
			TFT_Fill(88, 26, 113, 42, 0x07E0);  //clear
			TFT_Show_Menu_Item_Val(screanSecond_idx, (menuVal[screanSecondx][screanSecond_idx]?menutxt5:menutxt4), 2);
		}else 
		{
				Num_To_Txt(menuVal[screanSecondx][screanSecond_idx], valtxt, 3);
				TFT_Show_Menu_Item_Val((screanSecond_idx>=5?screanSecond_idx-5:screanSecond_idx), valtxt, 2);
		}
	} else {
		if(screanSecondx==0 && screanSecond_idx==1)   //DMX通道
		{
			if(menuVal[screanSecondx][screanSecond_idx]==0)
			{
				menuVal[screanSecondx][screanSecond_idx] = 2;
			} else 
			{
				menuVal[screanSecondx][screanSecond_idx]--;
			}
			TFT_SecondScreen_Item_DMX_Channel_Val(2);
		} else if(screanSecondx==3 && screanSecond_idx==0)    //倒显
		{
			if(menuVal[screanSecondx][screanSecond_idx]==0)
			{
				menuVal[screanSecondx][screanSecond_idx] = 1;
			} else 
			{
				menuVal[screanSecondx][screanSecond_idx]--;
			}
			TFT_Show_Menu_Item_Val(screanSecond_idx, (menuVal[screanSecondx][screanSecond_idx]?menutxt6:menutxt7), 2);
		} else if(screanSecondx==3 && screanSecond_idx==1)   //背光
		{
			if(menuVal[screanSecondx][screanSecond_idx]==0)
			{
				menuVal[screanSecondx][screanSecond_idx] = 1;
			} else 
			{
				menuVal[screanSecondx][screanSecond_idx]--;
			}
			TFT_Show_Menu_Item_Val(screanSecond_idx, (menuVal[screanSecondx][screanSecond_idx]?menutxt6:menutxt7), 2);
		} else if(screanSecondx==4 && screanSecond_idx==0)   //语言
		{
			if(menuVal[screanSecondx][screanSecond_idx]==0)
			{
				menuVal[screanSecondx][screanSecond_idx] = 1;
			} else 
			{
				menuVal[screanSecondx][screanSecond_idx]--;
			}
			TFT_Fill(88, 26, 113, 42, 0x07E0);  //clear
			TFT_Show_Menu_Item_Val(screanSecond_idx, (menuVal[screanSecondx][screanSecond_idx]?menutxt5:menutxt4), 2);
		}else 
		{
			menuVal[screanSecondx][screanSecond_idx]--;
			Num_To_Txt(menuVal[screanSecondx][screanSecond_idx], valtxt, 3);
			TFT_Show_Menu_Item_Val((screanSecond_idx>=5?screanSecond_idx-5:screanSecond_idx), valtxt, 2);
		}
	}
	
	
	
}

void TFT_ShowSecondScreen(uint8_t idx, uint8_t chg_header)
{
	if(idx==0)
	{
		TFT_Fill(0x00, 0x00, 0xA0, 0x80, 0x0909);  //clear
		TFT_ShowStringx(45, 4, "地址设置", 0xFFFF, 0x0909, 16, 0);
		TFT_Fill(10, 24, 10 + 141, 24 + 1, 0xFFFF);  //line
		Num_To_Txt(menuVal[0][0], valtxt, 3);
		TFT_Show_Menu_Item(0, "DMX地址", valtxt, 1);
		if(menuVal[0][1]==0)
		{
			valtxttmp = menutxt1;
		} else if(menuVal[0][1]==1)
		{
			valtxttmp = menutxt2;
		} else if(menuVal[0][1]==2)
		{
			valtxttmp = menutxt3;
		} 
		TFT_Show_Menu_Item(1, "DMX通道", valtxttmp, 0);
		TFT_Show_Menu_Item(2, "", "", 0);
		TFT_Show_Menu_Item(3, "", "", 0);
		TFT_Show_Menu_Item(4, "", "", 0);
	} else if(idx==1)
	{
		if(chg_header)
		{
				TFT_Fill(0x00, 0x00, 0xA0, 0x80, 0x0909);  //clear
				TFT_ShowStringx(63, 4, "手动", 0xFFFF, 0x0909, 16, 0);
				TFT_Fill(10, 24, 10 + 141, 24 + 1, 0xFFFF);  //line
		}
		if(screanSecond_idx<5) {
			Num_To_Txt(menuVal[1][0], valtxt, 3);
			TFT_Show_Menu_Item(0, "方向", valtxt, (screanSecondx2==2?0:1));
			Num_To_Txt(menuVal[1][1], valtxt, 3);
			TFT_Show_Menu_Item(1, "总亮度", valtxt, 0);
			Num_To_Txt(menuVal[1][2], valtxt, 3);
			TFT_Show_Menu_Item(2, "红色亮度", valtxt, 0);
			Num_To_Txt(menuVal[1][3], valtxt, 3);
			TFT_Show_Menu_Item(3, "绿色亮度", valtxt, 0);
			Num_To_Txt(menuVal[1][4], valtxt, 3);
			TFT_Show_Menu_Item(4, "蓝色亮度", valtxt, (screanSecondx2==2?1:0));
		} else   //第二页
		{
			Num_To_Txt(menuVal[1][0], valtxt, 3);
			TFT_Show_Menu_Item(0, "白色亮度", valtxt, (screanSecondx2==2?0:1));
			Num_To_Txt(menuVal[1][1], valtxt, 3);
			TFT_Show_Menu_Item(1, "频闪", valtxt, 0);
			Num_To_Txt(menuVal[1][2], valtxt, 3);
			TFT_Show_Menu_Item(2, "宏功能", valtxt, 0);
			Num_To_Txt(menuVal[1][3], valtxt, 3);
			TFT_Show_Menu_Item(3, "宏速度", valtxt, 0);
			Num_To_Txt(menuVal[1][4], valtxt, 3);
			TFT_Show_Menu_Item(4, "复位", "", (screanSecondx2==2?1:0));
		}
	} else if(idx==2)
	{
		TFT_Fill(0x00, 0x00, 0xA0, 0x80, 0x0909);  //clear
		TFT_ShowStringx(63, 4, "自走", 0xFFFF, 0x0909, 16, 0);
		TFT_Fill(10, 24, 10 + 141, 24 + 1, 0xFFFF);  //line
		Num_To_Txt(menuVal[2][0], valtxt, 3);
		TFT_Show_Menu_Item(0, "内置程序", valtxt, 1);
		Num_To_Txt(menuVal[2][1], valtxt, 3);
		TFT_Show_Menu_Item(1, "程序速度", valtxt, 0);
		Num_To_Txt(menuVal[2][2], valtxt, 3);
		TFT_Show_Menu_Item(2, "测试", valtxt, 0);
		TFT_Show_Menu_Item(3, "", "", 0);
		TFT_Show_Menu_Item(4, "", "", 0);
	} else if(idx==3)
	{
		TFT_Fill(0x00, 0x00, 0xA0, 0x80, 0x0909);  //clear
		TFT_Fill(10, 24, 10 + 141, 24 + 1, 0xFFFF);  //line
		TFT_ShowStringx(63, 4, "设置", 0xFFFF, 0x0909, 16, 0);
		TFT_Show_Menu_Item(0, "倒显", (menuVal[3][0]?menutxt6:menutxt7), 1);
		TFT_Show_Menu_Item(1, "背光", (menuVal[3][1]?menutxt6:menutxt7), 0);
		TFT_Show_Menu_Item(2, "恢复设置", "", 0);
		TFT_Show_Menu_Item(3, "", "", 0);
		TFT_Show_Menu_Item(4, "", "", 0);
	} else if(idx==4)
	{
		TFT_Fill(0x00, 0x00, 0xA0, 0x80, 0x0909);  //clear
		TFT_ShowStringx(63, 4, "语言", 0xFFFF, 0x0909, 16, 0);
		TFT_Fill(10, 24, 10 + 141, 24 + 1, 0xFFFF);  //line
		TFT_Show_Menu_Item(0, "语言", (menuVal[4][0]?menutxt5:menutxt4), 1);
		TFT_Show_Menu_Item(1, "", "", 0);
		TFT_Show_Menu_Item(2, "", "", 0);
		TFT_Show_Menu_Item(3, "", "", 0);
		TFT_Show_Menu_Item(4, "", "", 0);
	} else if(idx==5)
	{
		TFT_Fill(0x00, 0x00, 0xA0, 0x80, 0x0909);  //clear
		TFT_ShowStringx(63, 4, "信息", 0xFFFF, 0x0909, 16, 0);
		TFT_Fill(10, 24, 10 + 141, 24 + 1, 0xFFFF);  //line
		TFT_Show_Menu_Item(0, "RF_TFT_8H84Y2364T", "", 1);
		TFT_Show_Menu_Item(1, "版本", "V1.0", 0);
		TFT_Show_Menu_Item(2, "日期", "2024/04/25", 0);
		TFT_Show_Menu_Item(3, "时间", "15:33:20", 0);
		TFT_Show_Menu_Item(4, "温度", "38.2", 0);
	}
	TFT_Fill(10, 24 + 91, 10 + 141, 24 + 92, 0xFFFF);  //line
	
}

void TFT_ShowSecondScreen2(uint8_t idx)
{
	
}

void TFT_ShowSecondScreen2a_txt(uint8_t idx)
{

}

void TFT_ShowSecondScreen2b_txt(uint8_t idx)
{

}


void TFT_ShowSecondScreen3(uint8_t idx)
{
	
}

void TFT_ShowSecondScreen3_txt(uint8_t idx)
{

}

void TFT_ShowSecondScreen4(uint8_t idx)
{
	
}

void TFT_ShowSecondScreen4_txt(uint8_t idx)
{

}

void TFT_ShowSecondScreen5(uint8_t idx)
{
	
}

void TFT_ShowSecondScreen5_txt(uint8_t idx)
{

}

void TFT_ShowSecondScreen6(uint8_t idx)
{
	
}

void TFT_ShowSecondScreen6_txt(uint8_t idx)
{

		TFT_Fill(10, 24, 10 + 141, 24 + 1, 0xFFFF);  //line
	
		TFT_Show_Menu_Item(0, "RF_TFT_8H84Y2364T", "", 0);
		TFT_Show_Menu_Item(1, "版本", "V1.0", 0);
		TFT_Show_Menu_Item(2, "日期", "2024/04/25", 0);
		TFT_Show_Menu_Item(3, "时间", "15:33:20", 0);
		TFT_Show_Menu_Item(4, "温度", "38.2", 0);
		TFT_Fill(10, 24 + 91, 10 + 141, 24 + 92, 0xFFFF);  //line
}


/**
* status 0:normal, 1:highline, 2:modify
*
*/
void TFT_Show_Menu_Item(uint8_t pos, uint8_t *title, uint8_t *value, uint8_t status)
{
		uint16_t color = 0xFFFF;
		uint8_t dy = 0;
		if(status==1)
		{
			color = 0xFFE0;
		} else if(status==2)
		{
			color = 0x07E0;
		}
		dy = 18*pos;
		TFT_Fill(10, 25 + dy, 10 + 141, 43+dy, color);  //clear     25=24+1   151=10+141  43=25+18
		TFT_ShowStringx(12, 26+dy, title, 0x0909, color, 16, 0);  //12=10+2    26=24+2
		if(*value<0x80)
		{
			TFT_ShowString_R(147, 26+dy, value, 0x0909, color, 16, 0);  //147=159-10-2    26=24+2
		} else
		{
			TFT_ShowChineseString_R(147, 26+dy, value, 0x0909, color, 16, 0);
		}


}

/**
* status 0:normal, 1:highline, 2:modify
*
*/
void TFT_Show_Menu_Item_Val(uint8_t pos, uint8_t *value, uint8_t status)
{
		uint16_t color = 0xFFFF;
		uint8_t dy = 0;
		if(status==1)
		{
			color = 0xFFE0;
		} else if(status==2)
		{
			color = 0x07E0;
		}
		dy = 18*pos;
		if(*value<0x80)
		{
			TFT_ShowString_R(147, 26+dy, value, 0x0909, color, 16, 0);  //147=159-10-2    26=24+2
		} else
		{
			TFT_ShowChineseString_R(147, 26+dy, value, 0x0909, color, 16, 0);
		}


}




/******************************************************************************
      函数说明：在指定区域填充颜色
      入口数据：xsta,ysta   起始坐标
                xend,yend   终止坐标
								color       要填充的颜色
      返回值：  无
******************************************************************************/
void TFT_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color)
{          
	u16 i,j; 
	TFT_Address_Set(xsta,ysta,xend-1,yend-1);//设置显示范围
	for(i=ysta;i<yend;i++)
	{													   	 	
		for(j=xsta;j<xend;j++)
		{
			tft_write_data16(color);
		}
	} 					  	    
}

/******************************************************************************
      函数说明：在指定位置画点
      入口数据：x,y 画点坐标
                color 点的颜色
      返回值：  无
******************************************************************************/
void TFT_DrawPoint(u16 x,u16 y,u16 color)
{
	TFT_Address_Set(x,y,x,y);//设置光标位置 
	tft_write_data16(color);
} 


/******************************************************************************
      函数说明：画线
      入口数据：x1,y1   起始坐标
                x2,y2   终止坐标
                color   线的颜色
      返回值：  无
******************************************************************************/
void TFT_DrawLine(u16 x1,u16 y1,u16 x2,u16 y2,u16 color)
{
	u16 t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance;
	int incx,incy,uRow,uCol;
	delta_x=x2-x1; //计算坐标增量 
	delta_y=y2-y1;
	uRow=x1;//画线起点坐标
	uCol=y1;
	if(delta_x>0)incx=1; //设置单步方向 
	else if (delta_x==0)incx=0;//垂直线 
	else {incx=-1;delta_x=-delta_x;}
	if(delta_y>0)incy=1;
	else if (delta_y==0)incy=0;//水平线 
	else {incy=-1;delta_y=-delta_y;}
	if(delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴 
	else distance=delta_y;
	for(t=0;t<distance+1;t++)
	{
		TFT_DrawPoint(uRow,uCol,color);//画点
		xerr+=delta_x;
		yerr+=delta_y;
		if(xerr>distance)
		{
			xerr-=distance;
			uRow+=incx;
		}
		if(yerr>distance)
		{
			yerr-=distance;
			uCol+=incy;
		}
	}
}


/******************************************************************************
      函数说明：画矩形
      入口数据：x1,y1   起始坐标
                x2,y2   终止坐标
                color   矩形的颜色
      返回值：  无
******************************************************************************/
void TFT_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2,u16 color)
{
	TFT_DrawLine(x1,y1,x2,y1,color);
	TFT_DrawLine(x1,y1,x1,y2,color);
	TFT_DrawLine(x1,y2,x2,y2,color);
	TFT_DrawLine(x2,y1,x2,y2,color);
}


/******************************************************************************
      函数说明：画圆
      入口数据：x0,y0   圆心坐标
                r       半径
                color   圆的颜色
      返回值：  无
******************************************************************************/
void Draw_Circle(u16 x0,u16 y0,u8 r,u16 color)
{
	int a,b;
	a=0;b=r;	  
	while(a<=b)
	{
		TFT_DrawPoint(x0-b,y0-a,color);             //3           
		TFT_DrawPoint(x0+b,y0-a,color);             //0           
		TFT_DrawPoint(x0-a,y0+b,color);             //1                
		TFT_DrawPoint(x0-a,y0-b,color);             //2             
		TFT_DrawPoint(x0+b,y0+a,color);             //4               
		TFT_DrawPoint(x0+a,y0-b,color);             //5
		TFT_DrawPoint(x0+a,y0+b,color);             //6 
		TFT_DrawPoint(x0-b,y0+a,color);             //7
		a++;
		if((a*a+b*b)>(r*r))//判断要画的点是否过远
		{
			b--;
		}
	}
}

/******************************************************************************
      函数说明：显示汉字串
      入口数据：x,y显示坐标
                *s 要显示的汉字串
                fc 字的颜色
                bc 字的背景色
                sizey 字号 可选 16 24 32
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void TFT_ShowChinese(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode)
{
	while(*s!=0)
	{
		if(sizey==12) TFT_ShowChinese12x12(x,y,s,fc,bc,sizey,mode);
		else if(sizey==16) TFT_ShowChinese16x16(x,y,s,fc,bc,sizey,mode);
		else if(sizey==14) TFT_ShowChinese14x14(x,y,s,fc,bc,sizey,mode);
		else if(sizey==24) TFT_ShowChinese24x24(x,y,s,fc,bc,sizey,mode);
		else if(sizey==32) TFT_ShowChinese32x32(x,y,s,fc,bc,sizey,mode);
		else return;
		s+=2;
		x+=sizey;
	}
}

/******************************************************************************
      函数说明：显示单个12x12汉字
      入口数据：x,y显示坐标
                *s 要显示的汉字
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void TFT_ShowChinese12x12(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode)
{
	u8 i,j,m=0;
	u16 k;
	u16 HZnum;//汉字数目
	u16 TypefaceNum;//一个字符所占字节大小
	u16 x0=x;
	TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	                         
	HZnum=sizeof(tfont12)/sizeof(typFNT_GB12);	//统计汉字数目
	for(k=0;k<HZnum;k++) 
	{
		if((tfont12[k].Index[0]==*(s))&&(tfont12[k].Index[1]==*(s+1)))
		{ 	
			TFT_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(i=0;i<TypefaceNum;i++)
			{
				for(j=0;j<8;j++)
				{	
					if(!mode)//非叠加方式
					{
						if(tfont12[k].Msk[i]&(0x01<<j))tft_write_data16(fc);
						else tft_write_data16(bc);
						m++;
						if(m%sizey==0)
						{
							m=0;
							break;
						}
					}
					else//叠加方式
					{
						if(tfont12[k].Msk[i]&(0x01<<j))	TFT_DrawPoint(x,y,fc);//画一个点
						x++;
						if((x-x0)==sizey)
						{
							x=x0;
							y++;
							break;
						}
					}
				}
			}
		}				  	
		continue;  //查找到对应点阵字库立即退出，防止多个汉字重复取模带来影响
	}
} 

/******************************************************************************
      函数说明：显示单个16x16汉字
      入口数据：x,y显示坐标
                *s 要显示的汉字
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void TFT_ShowChinese14x14(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode)
{
	u8 i,j,m=0;
	u16 k;
	u16 HZnum;//汉字数目
	u16 TypefaceNum;//一个字符所占字节大小
	u16 x0=x;
  TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	HZnum=sizeof(tfont14)/sizeof(typFNT_GB14);	//统计汉字数目
	for(k=0;k<HZnum;k++) 
	{
		if ((tfont14[k].Index[0]==*(s))&&(tfont14[k].Index[1]==*(s+1)))
		{ 	
			TFT_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(i=0;i<TypefaceNum;i++)
			{
				for(j=0;j<8;j++)
				{	
					if(!mode)//非叠加方式
					{
						if(tfont14[k].Msk[i]&(0x01<<j))tft_write_data16(fc);
						else tft_write_data16(bc);
						m++;
						if(m%sizey==0)
						{
							m=0;
							break;
						}
					}
					else//叠加方式
					{
						if(tfont14[k].Msk[i]&(0x01<<j))	TFT_DrawPoint(x,y,fc);//画一个点
						x++;
						if((x-x0)==sizey)
						{
							x=x0;
							y++;
							break;
						}
					}
				}
			}
		}				  	
		continue;  //查找到对应点阵字库立即退出，防止多个汉字重复取模带来影响
	}
} 

void TFT_ShowChinese16x16(u16 x,u16 y,const u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode)
{
	u8 i,j,m=0;
	u16 k;
	u16 HZnum;//汉字数目
	u16 TypefaceNum;//一个字符所占字节大小
	u16 x0=x;
  TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	HZnum=sizeof(tfont16)/sizeof(typFNT_GB16);	//统计汉字数目
	for(k=0;k<HZnum;k++) 
	{
		if ((tfont16[k].Index[0]==*(s))&&(tfont16[k].Index[1]==*(s+1)))
		{ 	
			TFT_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(i=0;i<TypefaceNum;i++)
			{
				for(j=0;j<8;j++)
				{	
					if(!mode)//非叠加方式
					{
						if(tfont16[k].Msk[i]&(0x01<<j))tft_write_data16(fc);
						else tft_write_data16(bc);
						m++;
						if(m%sizey==0)
						{
							m=0;
							break;
						}
					}
					else//叠加方式
					{
						if(tfont16[k].Msk[i]&(0x01<<j))	TFT_DrawPoint(x,y,fc);//画一个点
						x++;
						if((x-x0)==sizey)
						{
							x=x0;
							y++;
							break;
						}
					}
				}
			}
		}				  	
		continue;  //查找到对应点阵字库立即退出，防止多个汉字重复取模带来影响
	}
} 

/******************************************************************************
      函数说明：显示单个24x24汉字
      入口数据：x,y显示坐标
                *s 要显示的汉字
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void TFT_ShowChinese24x24(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode)
{
	u8 i,j,m=0;
	u16 k;
	u16 HZnum;//汉字数目
	u16 TypefaceNum;//一个字符所占字节大小
	u16 x0=x;
	TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	HZnum=sizeof(tfont24)/sizeof(typFNT_GB24);	//统计汉字数目
	for(k=0;k<HZnum;k++) 
	{
		if ((tfont24[k].Index[0]==*(s))&&(tfont24[k].Index[1]==*(s+1)))
		{ 	
			TFT_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(i=0;i<TypefaceNum;i++)
			{
				for(j=0;j<8;j++)
				{	
					if(!mode)//非叠加方式
					{
						if(tfont24[k].Msk[i]&(0x01<<j))tft_write_data16(fc);
						else tft_write_data16(bc);
						m++;
						if(m%sizey==0)
						{
							m=0;
							break;
						}
					}
					else//叠加方式
					{
						if(tfont24[k].Msk[i]&(0x01<<j))	TFT_DrawPoint(x,y,fc);//画一个点
						x++;
						if((x-x0)==sizey)
						{
							x=x0;
							y++;
							break;
						}
					}
				}
			}
		}				  	
		continue;  //查找到对应点阵字库立即退出，防止多个汉字重复取模带来影响
	}
} 

/******************************************************************************
      函数说明：显示单个32x32汉字
      入口数据：x,y显示坐标
                *s 要显示的汉字
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void TFT_ShowChinese32x32(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode)
{
	u8 i,j,m=0;
	u16 k;
	u16 HZnum;//汉字数目
	u16 TypefaceNum;//一个字符所占字节大小
	u16 x0=x;
	TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	HZnum=sizeof(tfont32)/sizeof(typFNT_GB32);	//统计汉字数目
	for(k=0;k<HZnum;k++) 
	{
		if ((tfont32[k].Index[0]==*(s))&&(tfont32[k].Index[1]==*(s+1)))
		{ 	
			TFT_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(i=0;i<TypefaceNum;i++)
			{
				for(j=0;j<8;j++)
				{	
					if(!mode)//非叠加方式
					{
						if(tfont32[k].Msk[i]&(0x01<<j))tft_write_data16(fc);
						else tft_write_data16(bc);
						m++;
						if(m%sizey==0)
						{
							m=0;
							break;
						}
					}
					else//叠加方式
					{
						if(tfont32[k].Msk[i]&(0x01<<j))	TFT_DrawPoint(x,y,fc);//画一个点
						x++;
						if((x-x0)==sizey)
						{
							x=x0;
							y++;
							break;
						}
					}
				}
			}
		}				  	
		continue;  //查找到对应点阵字库立即退出，防止多个汉字重复取模带来影响
	}
}


/******************************************************************************
      函数说明：显示单个字符
      入口数据：x,y显示坐标
                num 要显示的字符
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void TFT_ShowChar(u16 x,u16 y,u8 num,u16 fc,u16 bc,u8 sizey,u8 mode)
{
	u8 temp,sizex,t,m=0;
	u16 i,TypefaceNum;//一个字符所占字节大小
	u16 x0=x;
	sizex=sizey/2;
	TypefaceNum=(sizex/8+((sizex%8)?1:0))*sizey;
	num=num-' ';    //得到偏移后的值
	TFT_Address_Set(x,y,x+sizex-1,y+sizey-1);  //设置光标位置 
	for(i=0;i<TypefaceNum;i++)
	{ 
//		if(sizey==12)temp=ascii_1206[num][i];		       //调用6x12字体
		if(sizey==16)temp=ascii_1608[num][i];		 //调用8x16字体
//		else if(sizey==24)temp=ascii_2412[num][i];		 //调用12x24字体
//		else if(sizey==32)temp=ascii_3216[num][i];		 //调用16x32字体
		else return;
		for(t=0;t<8;t++)
		{
			if(!mode)//非叠加模式
			{
				if(temp&(0x01<<t))tft_write_data16(fc);
				else tft_write_data16(bc);
				m++;
				if(m%sizex==0)
				{
					m=0;
					break;
				}
			}
			else//叠加模式
			{
				if(temp&(0x01<<t))TFT_DrawPoint(x,y,fc);//画一个点
				x++;
				if((x-x0)==sizex)
				{
					x=x0;
					y++;
					break;
				}
			}
		}
	}   	 	  
}


/******************************************************************************
      函数说明：显示字符串
      入口数据：x,y显示坐标
                *p 要显示的字符串
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void TFT_ShowString(u16 x,u16 y,const u8 *p,u16 fc,u16 bc,u8 sizey,u8 mode)
{         
	while(*p!='\0')
	{       
		TFT_ShowChar(x,y,*p,fc,bc,sizey,mode);
		x+=sizey/2;
		p++;
	}  
}


/******************************************************************************
      函数说明：显示字符串  (置右)
      入口数据：x,y显示坐标
                *p 要显示的字符串
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void TFT_ShowString_R(u16 x,u16 y,const u8 *p,u16 fc,u16 bc,u8 sizey,u8 mode)
{         
	const uint8_t *p_cur;
	if(*p=='\0') return;
	
	p_cur = p;
	while(*p_cur!='\0')
	{   
		p_cur++;
	}
	p_cur--;
	while(1)
	{       
		x-=sizey/2;
		TFT_ShowChar(x,y,*p_cur,fc,bc,sizey,mode);
		if(p_cur==p) break;
		p_cur--;
	}  
}

/******************************************************************************
      函数说明：显示字符串  (中英混合)
      入口数据：x,y显示坐标
                *p 要显示的字符串
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void TFT_ShowStringx(u16 x,u16 y,const u8 *p,u16 fc,u16 bc,u8 sizey,u8 mode)
{ 
	uint8_t first_char = 1;
	if(*p=='\0') return;
	
	while(*p!='\0')
	{   
		if(*p<0x80)
		{
				TFT_ShowChar(x,y,*p,fc,bc,sizey,mode);
				x+=sizey/2;
				p++;
		} else
		{
			if(first_char==0) x+=2;
			TFT_ShowChinese16x16(x, y, p, fc, bc, sizey, mode);
			x += sizey;
			p += 2;
		}
		first_char = 0;
		
	}  
}

/******************************************************************************
      函数说明：显示中文字符串 （置右）
      入口数据：x,y显示坐标
                *p 要显示的字符串
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void TFT_ShowChineseString_R(u16 x,u16 y,const u8 *p,u16 fc,u16 bc,u8 sizey,u8 mode)
{ 
	uint8_t first_char = 1;
	const uint8_t *p_cur;
	if(*p=='\0') return;

	p_cur = p;
	while(*p_cur!='\0')
	{   
		p_cur += 2;
	}
	p_cur -= 2;
	while(1)
	{ 
		x -= sizey;
		if(first_char==0) x-=2;
		TFT_ShowChinese16x16(x, y, p_cur, fc, bc, sizey, mode);
		if(p_cur==p) break;
		p_cur -= 2;
		first_char = 0;
	}  
}


/******************************************************************************
      函数说明：显示数字
      入口数据：m底数，n指数
      返回值：  无
******************************************************************************/
u32 mypow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;
	return result;
}


/******************************************************************************
      函数说明：显示整数变量
      入口数据：x,y显示坐标
                num 要显示整数变量
                len 要显示的位数
                fc 字的颜色
                bc 字的背景色
                sizey 字号
      返回值：  无
******************************************************************************/
void TFT_ShowIntNum(u16 x,u16 y,u16 num,u8 len,u16 fc,u16 bc,u8 sizey)
{         	
	u8 t,temp;
	u8 enshow=0;
	u8 sizex=sizey/2;
	for(t=0;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				TFT_ShowChar(x+t*sizex,y,' ',fc,bc,sizey,0);
				continue;
			}else enshow=1; 
		 	 
		}
	 	TFT_ShowChar(x+t*sizex,y,temp+48,fc,bc,sizey,0);
	}
} 


/******************************************************************************
      函数说明：显示两位小数变量
      入口数据：x,y显示坐标
                num 要显示小数变量
                len 要显示的位数
                fc 字的颜色
                bc 字的背景色
                sizey 字号
      返回值：  无
******************************************************************************/
void TFT_ShowFloatNum1(u16 x,u16 y,float num,u8 len,u16 fc,u16 bc,u8 sizey)
{         	
	u8 t,temp,sizex;
	u16 num1;
	sizex=sizey/2;
	num1=num*100;
	for(t=0;t<len;t++)
	{
		temp=(num1/mypow(10,len-t-1))%10;
		if(t==(len-2))
		{
			TFT_ShowChar(x+(len-2)*sizex,y,'.',fc,bc,sizey,0);
			t++;
			len+=1;
		}
	 	TFT_ShowChar(x+t*sizex,y,temp+48,fc,bc,sizey,0);
	}
}


/******************************************************************************
      函数说明：显示图片
      入口数据：x,y起点坐标
                length 图片长度
                width  图片宽度
                pic[]  图片数组    
      返回值：  无
******************************************************************************/
void TFT_ShowPicture(u16 x,u16 y,u16 length,u16 width,const u8 pic[])
{
	u16 i,j;
	u32 k=0;
	TFT_Address_Set(x,y,x+length-1,y+width-1);
	for(i=0;i<length;i++)
	{
		for(j=0;j<width;j++)
		{
			tft_write_data8(pic[k*2]);
			tft_write_data8(pic[k*2+1]);
			k++;
		}
	}			
}

/******************************************************************************
      函数说明：设置起始和结束地址
      入口数据：x1,x2 设置列的起始和结束地址
                y1,y2 设置行的起始和结束地址
      返回值：  无
******************************************************************************/
void TFT_Address_Set( u16 x1, u16 y1, u16 x2, u16 y2 )
{
		tft_write_command( 0x2a ); //列地址设置
		tft_write_data16( x1 );
		tft_write_data16( x2 );
		tft_write_command( 0x2b ); //行地址设置
		tft_write_data16( y1 );
		tft_write_data16( y2 );
		tft_write_command( 0x2c ); //储存器写

}

void Num_To_Txt(uint16_t num, uint8_t *p, uint8_t len)
{
	*(p+len) = '\0';
	while(len--)
	{
		*(p+len) = '0' + num%10;
		num /= 10;
	}
}

/*

//==================================================================================================
//  实现功能: Gui_DrawLine
//  函数说明: 画线函数
//  函数备注: 画线函数，使用Bresenham 画线算法
//--------------------------------------------------------------------------------------------------
//  |   -   |   -   |   0   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   
//==================================================================================================
void Gui_DrawLine(unsigned short x0, unsigned short y0,unsigned short x1, unsigned short y1,unsigned short Color)   
{
  int dx,             // difference in x's
      dy,             // difference in y's
      dx2,            // dx,dy * 2
      dy2, 
      x_inc,          // amount in pixel space to move during drawing
      y_inc,          // amount in pixel space to move during drawing
      error,          // the discriminant i.e. error i.e. decision variable
      index;          // used for looping	
	
      Lcd_SetXY(x0,y0);
      dx = x1-x0;//计算x距离
      dy = y1-y0;//计算y距离

      if (dx>=0)
      {
        x_inc = 1;
      }
      else
      {
        x_inc = -1;
        dx    = -dx;  
      } 
      
      if (dy>=0)
      {
        y_inc = 1;
      } 
      else
      {
        y_inc = -1;
        dy    = -dy; 
      } 

      dx2 = dx << 1;
      dy2 = dy << 1;

    if (dx > dy)//x距离大于y距离，那么每个x轴上只有一个点，每个y轴上有若干个点
    {//且线的点数等于x距离，以x轴递增画点
      // initialize error term
      error = dy2 - dx; 

      // draw the line
      for (index=0; index <= dx; index++)//要画的点数不会超过x距离
      {
        //画点
        Gui_DrawPoint(x0,y0,Color);
        
        // test if error has overflowed
        if (error >= 0) //是否需要增加y坐标值
        {
          error-=dx2;

          // move to next line
          y0+=y_inc;//增加y坐标值
        } // end if error overflowed

        // adjust the error term
        error+=dy2;

        // move to the next pixel
        x0+=x_inc;//x坐标值每次画点后都递增1
      } // end for
    } // end if |slope| <= 1
    else//y轴大于x轴，则每个y轴上只有一个点，x轴若干个点
    {//以y轴为递增画点
      // initialize error term
      error = dx2 - dy; 

      // draw the line
      for (index=0; index <= dy; index++)
      {
        // set the pixel
        Gui_DrawPoint(x0,y0,Color);

        // test if error overflowed
        if (error >= 0)
        {
          error-=dy2;

          // move to next line
          x0+=x_inc;
        } // end if error overflowed

        // adjust the error term
        error+=dx2;

        // move to the next pixel
        y0+=y_inc;
      } // end for
    } // end else |slope| > 1
  }

//==================================================================================================
//  实现功能: Gui_box
//  函数说明: 画矩形函数
//  函数备注: 
//--------------------------------------------------------------------------------------------------
//  |   -   |   -   |   0   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   
//==================================================================================================

void Gui_box(unsigned short x, unsigned short y, unsigned short w, unsigned short h,unsigned short bc)
{
	Gui_DrawLine(x,y,x+w,y,0xEF7D);
	Gui_DrawLine(x+w-1,y+1,x+w-1,y+1+h,0x2965);
	Gui_DrawLine(x,y+h,x+w,y+h,0x2965);
	Gui_DrawLine(x,y,x,y+h,0xEF7D);
  Gui_DrawLine(x+1,y+1,x+1+w-2,y+1+h-2,bc);
}

void Gui_box2(unsigned short x,unsigned short y,unsigned short w,unsigned short h, unsigned char mode)
{
	if (mode==0)	 
  {
		Gui_DrawLine(x,y,x+w,y,0xEF7D);
		Gui_DrawLine(x+w-1,y+1,x+w-1,y+1+h,0x2965);
		Gui_DrawLine(x,y+h,x+w,y+h,0x2965);
		Gui_DrawLine(x,y,x,y+h,0xEF7D);
	}
	if (mode==1)	
  {
		Gui_DrawLine(x,y,x+w,y,0x2965);
		Gui_DrawLine(x+w-1,y+1,x+w-1,y+1+h,0xEF7D);
		Gui_DrawLine(x,y+h,x+w,y+h,0xEF7D);
		Gui_DrawLine(x,y,x,y+h,0x2965);
	}
	if (mode==2)	
  {
		Gui_DrawLine(x,y,x+w,y,0xffff);
		Gui_DrawLine(x+w-1,y+1,x+w-1,y+1+h,0xffff);
		Gui_DrawLine(x,y+h,x+w,y+h,0xffff);
		Gui_DrawLine(x,y,x,y+h,0xffff);
	}
}


//==================================================================================================
//功能描述: 在屏幕显示一凸起的按钮框
//输    入: unsigned short x1,y1,x2,y2 按钮框左上角和右下角坐标
//输    出: 无
//==================================================================================================
void DisplayButtonDown(unsigned short x1,unsigned short y1,unsigned short x2,unsigned short y2)
{
	Gui_DrawLine(x1,  y1,  x2,y1, GRAY2);  //H
	Gui_DrawLine(x1+1,y1+1,x2,y1+1, GRAY1);  //H
	Gui_DrawLine(x1,  y1,  x1,y2, GRAY2);  //V
	Gui_DrawLine(x1+1,y1+1,x1+1,y2, GRAY1);  //V
	Gui_DrawLine(x1,  y2,  x2,y2, WHITE);  //H
	Gui_DrawLine(x2,  y1,  x2,y2, WHITE);  //V
}

//==================================================================================================
//功能描述: 在屏幕显示一凹下的按钮框
//输    入: unsigned short x1,y1,x2,y2 按钮框左上角和右下角坐标
//输    出: 无
//==================================================================================================
void DisplayButtonUp(unsigned short x1,unsigned short y1,unsigned short x2,unsigned short y2)
{
	Gui_DrawLine(x1,  y1,  x2,y1, WHITE); //H
	Gui_DrawLine(x1,  y1,  x1,y2, WHITE); //V
	
	Gui_DrawLine(x1+1,y2-1,x2,y2-1, GRAY1);  //H
	Gui_DrawLine(x1,  y2,  x2,y2, GRAY2);  //H
	Gui_DrawLine(x2-1,y1+1,x2-1,y2, GRAY1);  //V
  Gui_DrawLine(x2  ,y1  ,x2,y2, GRAY2); //V
}

*/
