#include "tft.h"
#include "tft_init.h"
#include "tft_font.h"
#include "tft_pic.h"

extern uint8_t screanSecondx;   //�ڼ��������˵�
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
uint8_t menutxt4[] = "����";
uint8_t menutxt5[] = "English";
uint8_t menutxt6[] = "��";
uint8_t menutxt7[] = "��";

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
				TFT_Fill(0x0 + 16, 0x0 + 41, 0x0 + 53, 0x0 + 43, 0x0909);//��
				TFT_Fill(0x0 + 16, 0x0 + 59, 0x0 + 53, 0x0 + 61, 0x0909);//��
				TFT_Fill(0x0 + 16, 0x0 + 43, 0x0 + 22, 0x0 + 59, 0x0909);
				TFT_Fill(0x0 + 46, 0x0 + 43, 0x0 + 53, 0x0 + 59, 0x0909);
		}
		TFT_ShowChinese(0x0 + 63, 0x0 + 43, "��", 0x001F, (idx==1?0xFFFF:0x0909), 16, 0);
		TFT_ShowChinese(0x0 + 81, 0x0 + 43, "��", 0x001F, (idx==1?0xFFFF:0x0909), 16, 0);
		if(screanMain_idx_o!=idx && screanMain_idx_o==1) {
				TFT_Fill(0x0 + 61, 0x0 + 41, 0x0 + 99, 0x0 + 43, 0x0909);//��
				TFT_Fill(0x0 + 61, 0x0 + 59, 0x0 + 99, 0x0 + 61, 0x0909);//��
				TFT_Fill(0x0 + 61, 0x0 + 43, 0x0 + 63, 0x0 + 59, 0x0909);
				TFT_Fill(0x0 + 79, 0x0 + 43, 0x0 + 81, 0x0 + 59, 0x0909);
				TFT_Fill(0x0 + 96, 0x0 + 43, 0x0 + 99, 0x0 + 59, 0x0909);
		}
		TFT_ShowChinese(0x0 + 108, 0x0 + 43, "��", 0x001F, (idx==2?0xFFFF:0x0909), 16, 0);
		TFT_ShowChinese(0x0 + 126, 0x0 + 43, "��", 0x001F, (idx==2?0xFFFF:0x0909), 16, 0);
		if(screanMain_idx_o!=idx && screanMain_idx_o==2) {
				TFT_Fill(45 + 61, 0x0 + 41, 45 + 99, 0x0 + 43, 0x0909);//��
				TFT_Fill(45 + 61, 0x0 + 59, 45 + 99, 0x0 + 61, 0x0909);//��
				TFT_Fill(45 + 61, 0x0 + 43, 45 + 63, 0x0 + 59, 0x0909);
				TFT_Fill(45 + 79, 0x0 + 43, 45 + 81, 0x0 + 59, 0x0909);
				TFT_Fill(45 + 96, 0x0 + 43, 45 + 99, 0x0 + 59, 0x0909);
		}
		TFT_ShowChinese(0x0 + 18, 0x0 + 105, "��", 0x001F, (idx==3?0xFFFF:0x0909), 16, 0);
		TFT_ShowChinese(0x0 + 36, 0x0 + 105, "��", 0x001F, (idx==3?0xFFFF:0x0909), 16, 0);
		if(screanMain_idx_o!=idx && screanMain_idx_o==3) {
				TFT_Fill(0x0 + 16, 0x0 + 103, 0x0 + 54, 0x0 + 105, 0x0909);//��
				TFT_Fill(0x0 + 16, 0x0 + 121, 0x0 + 54, 0x0 + 123, 0x0909);//��
				TFT_Fill(0x0 + 16, 0x0 + 105, 0x0 + 18, 0x0 + 121, 0x0909);
				TFT_Fill(0x0 + 34, 0x0 + 105, 0x0 + 36, 0x0 + 121, 0x0909);
				TFT_Fill(0x0 + 51, 0x0 + 105, 0x0 + 54, 0x0 + 121, 0x0909);
		}
		TFT_ShowChinese(0x0 + 63, 0x0 + 105, "��", 0x001F, (idx==4?0xFFFF:0x0909), 16, 0);
		TFT_ShowChinese(0x0 + 81, 0x0 + 105, "��", 0x001F, (idx==4?0xFFFF:0x0909), 16, 0);
		if(screanMain_idx_o!=idx && screanMain_idx_o==4) {
				TFT_Fill(45 + 16, 0x0 + 103, 45 + 54, 0x0 + 105, 0x0909);//��
				TFT_Fill(45 + 16, 0x0 + 121, 45 + 54, 0x0 + 123, 0x0909);//��
				TFT_Fill(45 + 16, 0x0 + 105, 45 + 18, 0x0 + 121, 0x0909);
				TFT_Fill(45 + 34, 0x0 + 105, 45 + 36, 0x0 + 121, 0x0909);
				TFT_Fill(45 + 51, 0x0 + 105, 45 + 54, 0x0 + 121, 0x0909);
		}
		TFT_ShowChinese(0x0 + 108, 0x0 + 105, "��", 0x001F, (idx==5?0xFFFF:0x0909), 16, 0);
		TFT_ShowChinese(0x0 + 126, 0x0 + 105, "Ϣ", 0x001F, (idx==5?0xFFFF:0x0909), 16, 0);
		if(screanMain_idx_o!=idx && screanMain_idx_o==5) {
				TFT_Fill(90 + 16, 0x0 + 103, 90 + 54, 0x0 + 105, 0x0909);//��
				TFT_Fill(90 + 16, 0x0 + 121, 90 + 54, 0x0 + 123, 0x0909);//��
				TFT_Fill(90 + 16, 0x0 + 105, 90 + 18, 0x0 + 121, 0x0909);
				TFT_Fill(90 + 34, 0x0 + 105, 90 + 36, 0x0 + 121, 0x0909);
				TFT_Fill(90 + 51, 0x0 + 105, 90 + 54, 0x0 + 121, 0x0909);
		}

		if(idx==0)
		{
				TFT_Fill(0x0 + 16, 0x0 + 41, 0x0 + 53, 0x0 + 43, 0xFFFF);//��
				TFT_Fill(0x0 + 16, 0x0 + 59, 0x0 + 53, 0x0 + 61, 0xFFFF);//��
				TFT_Fill(0x0 + 16, 0x0 + 43, 0x0 + 22, 0x0 + 59, 0xFFFF);
				TFT_Fill(0x0 + 46, 0x0 + 43, 0x0 + 53, 0x0 + 59, 0xFFFF);
		} else if(idx==1)
		{
				TFT_Fill(0x0 + 61, 0x0 + 41, 0x0 + 99, 0x0 + 43, 0xFFFF);//��
				TFT_Fill(0x0 + 61, 0x0 + 59, 0x0 + 99, 0x0 + 61, 0xFFFF);//��
				TFT_Fill(0x0 + 61, 0x0 + 43, 0x0 + 63, 0x0 + 59, 0xFFFF);
				TFT_Fill(0x0 + 79, 0x0 + 43, 0x0 + 81, 0x0 + 59, 0xFFFF);
				TFT_Fill(0x0 + 96, 0x0 + 43, 0x0 + 99, 0x0 + 59, 0xFFFF);
		} else if(idx==2)
		{
				TFT_Fill(45 + 61, 0x0 + 41, 45 + 99, 0x0 + 43, 0xFFFF);//��
				TFT_Fill(45 + 61, 0x0 + 59, 45 + 99, 0x0 + 61, 0xFFFF);//��
				TFT_Fill(45 + 61, 0x0 + 43, 45 + 63, 0x0 + 59, 0xFFFF);
				TFT_Fill(45 + 79, 0x0 + 43, 45 + 81, 0x0 + 59, 0xFFFF);
				TFT_Fill(45 + 96, 0x0 + 43, 45 + 99, 0x0 + 59, 0xFFFF);
		} else if(idx==3)
		{
				TFT_Fill(0x0 + 16, 0x0 + 103, 0x0 + 54, 0x0 + 105, 0xFFFF);//��
				TFT_Fill(0x0 + 16, 0x0 + 121, 0x0 + 54, 0x0 + 123, 0xFFFF);//��
				TFT_Fill(0x0 + 16, 0x0 + 105, 0x0 + 18, 0x0 + 121, 0xFFFF);
				TFT_Fill(0x0 + 34, 0x0 + 105, 0x0 + 36, 0x0 + 121, 0xFFFF);
				TFT_Fill(0x0 + 51, 0x0 + 105, 0x0 + 54, 0x0 + 121, 0xFFFF);
		} else if(idx==4)
		{
				TFT_Fill(45 + 16, 0x0 + 103, 45 + 54, 0x0 + 105, 0xFFFF);//��
				TFT_Fill(45 + 16, 0x0 + 121, 45 + 54, 0x0 + 123, 0xFFFF);//��
				TFT_Fill(45 + 16, 0x0 + 105, 45 + 18, 0x0 + 121, 0xFFFF);
				TFT_Fill(45 + 34, 0x0 + 105, 45 + 36, 0x0 + 121, 0xFFFF);
				TFT_Fill(45 + 51, 0x0 + 105, 45 + 54, 0x0 + 121, 0xFFFF);
		} else if(idx==5)
		{
				TFT_Fill(90 + 16, 0x0 + 103, 90 + 54, 0x0 + 105, 0xFFFF);//��
				TFT_Fill(90 + 16, 0x0 + 121, 90 + 54, 0x0 + 123, 0xFFFF);//��
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
			TFT_Show_Menu_Item(1, "DMXͨ��", valtxttmp, screanSecond_status);
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
		//�˵�ѡ�У�����
		if(idx_item==0)
		{
			Num_To_Txt(menuVal[0][0], valtxt, 3);
			TFT_Show_Menu_Item(0, "DMX��ַ", valtxt, screanSecond_status);
		}
		if(idx_item==1)
		{
			TFT_SecondScreen_Item_DMX_Channel(screanSecond_status);
		}
		
		//ȡ������
		if(screanSecond_idx_o!=idx_item && screanSecond_idx_o==0)
		{
			Num_To_Txt(menuVal[0][0], valtxt, 3);
			TFT_Show_Menu_Item(0, "DMX��ַ", valtxt, 0);
		}
		if(screanSecond_idx_o!=idx_item && screanSecond_idx_o==1)
		{
			TFT_SecondScreen_Item_DMX_Channel(0);
		}
	} else if(screanSecondx==1)
	{
		//�˵�ѡ�У�����
		Num_To_Txt(menuVal[screanSecondx][idx_item], valtxt, 3);
		if(idx_item==0)
		{
			TFT_Show_Menu_Item(0, "����", valtxt, screanSecond_status);
		}
		if(idx_item==1)
		{
			TFT_Show_Menu_Item(1, "������", valtxt, screanSecond_status);
		}
		if(idx_item==2)
		{
			TFT_Show_Menu_Item(2, "��ɫ����", valtxt, screanSecond_status);
		}
		if(idx_item==3)
		{
			TFT_Show_Menu_Item(3, "��ɫ����", valtxt, screanSecond_status);
		}
		if(idx_item==4)
		{
			TFT_Show_Menu_Item(4, "��ɫ����", valtxt, screanSecond_status);
		}
		if(idx_item==5)
		{
			TFT_Show_Menu_Item(0, "��ɫ����", valtxt, screanSecond_status);
		}
		if(idx_item==6)
		{
			TFT_Show_Menu_Item(1, "Ƶ��", valtxt, screanSecond_status);
		}
		if(idx_item==7)
		{
			TFT_Show_Menu_Item(2, "�깦��", valtxt, screanSecond_status);
		}
		if(idx_item==8)
		{
			TFT_Show_Menu_Item(3, "���ٶ�", valtxt, screanSecond_status);
		}
		if(idx_item==9)
		{
			TFT_Show_Menu_Item(4, "��λ", valtxt, screanSecond_status);
		}
		
		//ȡ������
		Num_To_Txt(menuVal[screanSecondx][screanSecond_idx_o], valtxt, 3);
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==0)
		{
			TFT_Show_Menu_Item(0, "����", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==1)
		{
			TFT_Show_Menu_Item(1, "������", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==2)
		{
			TFT_Show_Menu_Item(2, "��ɫ����", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==3)
		{
			TFT_Show_Menu_Item(3, "��ɫ����", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==4)
		{
			TFT_Show_Menu_Item(4, "��ɫ����", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==5)
		{
			TFT_Show_Menu_Item(0, "��ɫ����", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==6)
		{
			TFT_Show_Menu_Item(1, "Ƶ��", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==7)
		{
			TFT_Show_Menu_Item(2, "�깦��", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==8)
		{
			TFT_Show_Menu_Item(3, "���ٶ�", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==9)
		{
			TFT_Show_Menu_Item(4, "��λ", "", 0);
		}
	} else if(screanSecondx==2)
	{
		//�˵�ѡ�У�����
		Num_To_Txt(menuVal[screanSecondx][idx_item], valtxt, 3);
		if(idx_item==0)
		{
			TFT_Show_Menu_Item(0, "���ó���", valtxt, screanSecond_status);
		}
		if(idx_item==1)
		{
			TFT_Show_Menu_Item(1, "�����ٶ�", valtxt, screanSecond_status);
		}
		if(idx_item==2)
		{
			TFT_Show_Menu_Item(2, "����", valtxt, screanSecond_status);
		}
		
		//ȡ������
		Num_To_Txt(menuVal[screanSecondx][screanSecond_idx_o], valtxt, 3);
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==0)
		{
			TFT_Show_Menu_Item(0, "���ó���", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==1)
		{
			TFT_Show_Menu_Item(1, "�����ٶ�", valtxt, 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==2)
		{
			TFT_Show_Menu_Item(2, "����", valtxt, 0);
		}
	} else if(screanSecondx==3)
	{
		//�˵�ѡ�У�����
		if(idx_item==0)
		{
			TFT_Show_Menu_Item(0, "����", (menuVal[screanSecondx][idx_item]?menutxt6:menutxt7), screanSecond_status);
		}
		if(idx_item==1)
		{
			TFT_Show_Menu_Item(1, "����", (menuVal[screanSecondx][idx_item]?menutxt6:menutxt7), screanSecond_status);
		}
		if(idx_item==2)
		{
			Num_To_Txt(menuVal[screanSecondx][idx_item], valtxt, 3);
			TFT_Show_Menu_Item(2, "�ָ�����", valtxt, screanSecond_status);
		}
		
		//ȡ������
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==0)
		{
			TFT_Show_Menu_Item(0, "����", (menuVal[screanSecondx][screanSecond_idx_o]?menutxt6:menutxt7), 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==1)
		{
			TFT_Show_Menu_Item(1, "����", (menuVal[screanSecondx][screanSecond_idx_o]?menutxt6:menutxt7), 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==2)
		{
			Num_To_Txt(menuVal[screanSecondx][screanSecond_idx_o], valtxt, 3);
			TFT_Show_Menu_Item(2, "�ָ�����", valtxt, 0);
		}
	} else if(screanSecondx==4)
	{
		if(idx_item==0)
		{
			TFT_Show_Menu_Item(0, "����", (menuVal[4][0]?menutxt5:menutxt4), screanSecond_status);
		}
	} else if(screanSecondx==5)
	{
		//�˵�ѡ�У�����
		if(idx_item==0)
		{
			TFT_Show_Menu_Item(0, "RF_TFT_8H84Y2364T", "", screanSecond_status);
		}
		if(idx_item==1)
		{
			TFT_Show_Menu_Item(1, "�汾", "V1.0", screanSecond_status);
		}
		if(idx_item==2)
		{
			TFT_Show_Menu_Item(2, "����", "2024/04/25", screanSecond_status);
		}
		if(idx_item==3)
		{
			TFT_Show_Menu_Item(3, "ʱ��", "15:33:20",screanSecond_status);
		}
		if(idx_item==4)
		{
			TFT_Show_Menu_Item(4, "�¶�", "38.2", screanSecond_status);
		}
		
		//ȡ������
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==0)
		{
			TFT_Show_Menu_Item(0, "RF_TFT_8H84Y2364T", "", 1);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==1)
		{
			TFT_Show_Menu_Item(1, "�汾", "V1.0", 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==2)
		{
			TFT_Show_Menu_Item(2, "����", "2024/04/25", 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==3)
		{
			TFT_Show_Menu_Item(3, "ʱ��", "15:33:20", 0);
		}
		if(idx_item!=screanSecond_idx_o && screanSecond_idx_o==4)
		{
			TFT_Show_Menu_Item(4, "�¶�", "38.2", 0);
		}
	}
	
}

void TFT_SecondScreen_Val_Chg(uint8_t dir)
{
	
	if(dir)
	{
		menuVal[screanSecondx][screanSecond_idx]++;
		if(screanSecondx==0 && screanSecond_idx==1)   //DMXͨ��
		{
			if(menuVal[screanSecondx][screanSecond_idx]==3)
			{
				menuVal[screanSecondx][screanSecond_idx] = 0;
			}
			TFT_SecondScreen_Item_DMX_Channel_Val(2);
		} else if(screanSecondx==3 && screanSecond_idx==0)    //����
		{
			if(menuVal[screanSecondx][screanSecond_idx]==2)
			{
				menuVal[screanSecondx][screanSecond_idx] = 0;
			}
			TFT_Show_Menu_Item_Val(screanSecond_idx, (menuVal[screanSecondx][screanSecond_idx]?menutxt6:menutxt7), 2);
		} else if(screanSecondx==3 && screanSecond_idx==1)   //����
		{
			if(menuVal[screanSecondx][screanSecond_idx]==2)
			{
				menuVal[screanSecondx][screanSecond_idx] = 0;
			}
			TFT_Show_Menu_Item_Val(screanSecond_idx, (menuVal[screanSecondx][screanSecond_idx]?menutxt6:menutxt7), 2);
		} else if(screanSecondx==4 && screanSecond_idx==0)   //����
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
		if(screanSecondx==0 && screanSecond_idx==1)   //DMXͨ��
		{
			if(menuVal[screanSecondx][screanSecond_idx]==0)
			{
				menuVal[screanSecondx][screanSecond_idx] = 2;
			} else 
			{
				menuVal[screanSecondx][screanSecond_idx]--;
			}
			TFT_SecondScreen_Item_DMX_Channel_Val(2);
		} else if(screanSecondx==3 && screanSecond_idx==0)    //����
		{
			if(menuVal[screanSecondx][screanSecond_idx]==0)
			{
				menuVal[screanSecondx][screanSecond_idx] = 1;
			} else 
			{
				menuVal[screanSecondx][screanSecond_idx]--;
			}
			TFT_Show_Menu_Item_Val(screanSecond_idx, (menuVal[screanSecondx][screanSecond_idx]?menutxt6:menutxt7), 2);
		} else if(screanSecondx==3 && screanSecond_idx==1)   //����
		{
			if(menuVal[screanSecondx][screanSecond_idx]==0)
			{
				menuVal[screanSecondx][screanSecond_idx] = 1;
			} else 
			{
				menuVal[screanSecondx][screanSecond_idx]--;
			}
			TFT_Show_Menu_Item_Val(screanSecond_idx, (menuVal[screanSecondx][screanSecond_idx]?menutxt6:menutxt7), 2);
		} else if(screanSecondx==4 && screanSecond_idx==0)   //����
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
		TFT_ShowStringx(45, 4, "��ַ����", 0xFFFF, 0x0909, 16, 0);
		TFT_Fill(10, 24, 10 + 141, 24 + 1, 0xFFFF);  //line
		Num_To_Txt(menuVal[0][0], valtxt, 3);
		TFT_Show_Menu_Item(0, "DMX��ַ", valtxt, 1);
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
		TFT_Show_Menu_Item(1, "DMXͨ��", valtxttmp, 0);
		TFT_Show_Menu_Item(2, "", "", 0);
		TFT_Show_Menu_Item(3, "", "", 0);
		TFT_Show_Menu_Item(4, "", "", 0);
	} else if(idx==1)
	{
		if(chg_header)
		{
				TFT_Fill(0x00, 0x00, 0xA0, 0x80, 0x0909);  //clear
				TFT_ShowStringx(63, 4, "�ֶ�", 0xFFFF, 0x0909, 16, 0);
				TFT_Fill(10, 24, 10 + 141, 24 + 1, 0xFFFF);  //line
		}
		if(screanSecond_idx<5) {
			Num_To_Txt(menuVal[1][0], valtxt, 3);
			TFT_Show_Menu_Item(0, "����", valtxt, (screanSecondx2==2?0:1));
			Num_To_Txt(menuVal[1][1], valtxt, 3);
			TFT_Show_Menu_Item(1, "������", valtxt, 0);
			Num_To_Txt(menuVal[1][2], valtxt, 3);
			TFT_Show_Menu_Item(2, "��ɫ����", valtxt, 0);
			Num_To_Txt(menuVal[1][3], valtxt, 3);
			TFT_Show_Menu_Item(3, "��ɫ����", valtxt, 0);
			Num_To_Txt(menuVal[1][4], valtxt, 3);
			TFT_Show_Menu_Item(4, "��ɫ����", valtxt, (screanSecondx2==2?1:0));
		} else   //�ڶ�ҳ
		{
			Num_To_Txt(menuVal[1][0], valtxt, 3);
			TFT_Show_Menu_Item(0, "��ɫ����", valtxt, (screanSecondx2==2?0:1));
			Num_To_Txt(menuVal[1][1], valtxt, 3);
			TFT_Show_Menu_Item(1, "Ƶ��", valtxt, 0);
			Num_To_Txt(menuVal[1][2], valtxt, 3);
			TFT_Show_Menu_Item(2, "�깦��", valtxt, 0);
			Num_To_Txt(menuVal[1][3], valtxt, 3);
			TFT_Show_Menu_Item(3, "���ٶ�", valtxt, 0);
			Num_To_Txt(menuVal[1][4], valtxt, 3);
			TFT_Show_Menu_Item(4, "��λ", "", (screanSecondx2==2?1:0));
		}
	} else if(idx==2)
	{
		TFT_Fill(0x00, 0x00, 0xA0, 0x80, 0x0909);  //clear
		TFT_ShowStringx(63, 4, "����", 0xFFFF, 0x0909, 16, 0);
		TFT_Fill(10, 24, 10 + 141, 24 + 1, 0xFFFF);  //line
		Num_To_Txt(menuVal[2][0], valtxt, 3);
		TFT_Show_Menu_Item(0, "���ó���", valtxt, 1);
		Num_To_Txt(menuVal[2][1], valtxt, 3);
		TFT_Show_Menu_Item(1, "�����ٶ�", valtxt, 0);
		Num_To_Txt(menuVal[2][2], valtxt, 3);
		TFT_Show_Menu_Item(2, "����", valtxt, 0);
		TFT_Show_Menu_Item(3, "", "", 0);
		TFT_Show_Menu_Item(4, "", "", 0);
	} else if(idx==3)
	{
		TFT_Fill(0x00, 0x00, 0xA0, 0x80, 0x0909);  //clear
		TFT_Fill(10, 24, 10 + 141, 24 + 1, 0xFFFF);  //line
		TFT_ShowStringx(63, 4, "����", 0xFFFF, 0x0909, 16, 0);
		TFT_Show_Menu_Item(0, "����", (menuVal[3][0]?menutxt6:menutxt7), 1);
		TFT_Show_Menu_Item(1, "����", (menuVal[3][1]?menutxt6:menutxt7), 0);
		TFT_Show_Menu_Item(2, "�ָ�����", "", 0);
		TFT_Show_Menu_Item(3, "", "", 0);
		TFT_Show_Menu_Item(4, "", "", 0);
	} else if(idx==4)
	{
		TFT_Fill(0x00, 0x00, 0xA0, 0x80, 0x0909);  //clear
		TFT_ShowStringx(63, 4, "����", 0xFFFF, 0x0909, 16, 0);
		TFT_Fill(10, 24, 10 + 141, 24 + 1, 0xFFFF);  //line
		TFT_Show_Menu_Item(0, "����", (menuVal[4][0]?menutxt5:menutxt4), 1);
		TFT_Show_Menu_Item(1, "", "", 0);
		TFT_Show_Menu_Item(2, "", "", 0);
		TFT_Show_Menu_Item(3, "", "", 0);
		TFT_Show_Menu_Item(4, "", "", 0);
	} else if(idx==5)
	{
		TFT_Fill(0x00, 0x00, 0xA0, 0x80, 0x0909);  //clear
		TFT_ShowStringx(63, 4, "��Ϣ", 0xFFFF, 0x0909, 16, 0);
		TFT_Fill(10, 24, 10 + 141, 24 + 1, 0xFFFF);  //line
		TFT_Show_Menu_Item(0, "RF_TFT_8H84Y2364T", "", 1);
		TFT_Show_Menu_Item(1, "�汾", "V1.0", 0);
		TFT_Show_Menu_Item(2, "����", "2024/04/25", 0);
		TFT_Show_Menu_Item(3, "ʱ��", "15:33:20", 0);
		TFT_Show_Menu_Item(4, "�¶�", "38.2", 0);
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
		TFT_Show_Menu_Item(1, "�汾", "V1.0", 0);
		TFT_Show_Menu_Item(2, "����", "2024/04/25", 0);
		TFT_Show_Menu_Item(3, "ʱ��", "15:33:20", 0);
		TFT_Show_Menu_Item(4, "�¶�", "38.2", 0);
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
      ����˵������ָ�����������ɫ
      ������ݣ�xsta,ysta   ��ʼ����
                xend,yend   ��ֹ����
								color       Ҫ������ɫ
      ����ֵ��  ��
******************************************************************************/
void TFT_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color)
{          
	u16 i,j; 
	TFT_Address_Set(xsta,ysta,xend-1,yend-1);//������ʾ��Χ
	for(i=ysta;i<yend;i++)
	{													   	 	
		for(j=xsta;j<xend;j++)
		{
			tft_write_data16(color);
		}
	} 					  	    
}

/******************************************************************************
      ����˵������ָ��λ�û���
      ������ݣ�x,y ��������
                color �����ɫ
      ����ֵ��  ��
******************************************************************************/
void TFT_DrawPoint(u16 x,u16 y,u16 color)
{
	TFT_Address_Set(x,y,x,y);//���ù��λ�� 
	tft_write_data16(color);
} 


/******************************************************************************
      ����˵��������
      ������ݣ�x1,y1   ��ʼ����
                x2,y2   ��ֹ����
                color   �ߵ���ɫ
      ����ֵ��  ��
******************************************************************************/
void TFT_DrawLine(u16 x1,u16 y1,u16 x2,u16 y2,u16 color)
{
	u16 t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance;
	int incx,incy,uRow,uCol;
	delta_x=x2-x1; //������������ 
	delta_y=y2-y1;
	uRow=x1;//�����������
	uCol=y1;
	if(delta_x>0)incx=1; //���õ������� 
	else if (delta_x==0)incx=0;//��ֱ�� 
	else {incx=-1;delta_x=-delta_x;}
	if(delta_y>0)incy=1;
	else if (delta_y==0)incy=0;//ˮƽ�� 
	else {incy=-1;delta_y=-delta_y;}
	if(delta_x>delta_y)distance=delta_x; //ѡȡ�������������� 
	else distance=delta_y;
	for(t=0;t<distance+1;t++)
	{
		TFT_DrawPoint(uRow,uCol,color);//����
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
      ����˵����������
      ������ݣ�x1,y1   ��ʼ����
                x2,y2   ��ֹ����
                color   ���ε���ɫ
      ����ֵ��  ��
******************************************************************************/
void TFT_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2,u16 color)
{
	TFT_DrawLine(x1,y1,x2,y1,color);
	TFT_DrawLine(x1,y1,x1,y2,color);
	TFT_DrawLine(x1,y2,x2,y2,color);
	TFT_DrawLine(x2,y1,x2,y2,color);
}


/******************************************************************************
      ����˵������Բ
      ������ݣ�x0,y0   Բ������
                r       �뾶
                color   Բ����ɫ
      ����ֵ��  ��
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
		if((a*a+b*b)>(r*r))//�ж�Ҫ���ĵ��Ƿ��Զ
		{
			b--;
		}
	}
}

/******************************************************************************
      ����˵������ʾ���ִ�
      ������ݣ�x,y��ʾ����
                *s Ҫ��ʾ�ĺ��ִ�
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ� ��ѡ 16 24 32
                mode:  0�ǵ���ģʽ  1����ģʽ
      ����ֵ��  ��
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
      ����˵������ʾ����12x12����
      ������ݣ�x,y��ʾ����
                *s Ҫ��ʾ�ĺ���
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
                mode:  0�ǵ���ģʽ  1����ģʽ
      ����ֵ��  ��
******************************************************************************/
void TFT_ShowChinese12x12(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode)
{
	u8 i,j,m=0;
	u16 k;
	u16 HZnum;//������Ŀ
	u16 TypefaceNum;//һ���ַ���ռ�ֽڴ�С
	u16 x0=x;
	TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	                         
	HZnum=sizeof(tfont12)/sizeof(typFNT_GB12);	//ͳ�ƺ�����Ŀ
	for(k=0;k<HZnum;k++) 
	{
		if((tfont12[k].Index[0]==*(s))&&(tfont12[k].Index[1]==*(s+1)))
		{ 	
			TFT_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(i=0;i<TypefaceNum;i++)
			{
				for(j=0;j<8;j++)
				{	
					if(!mode)//�ǵ��ӷ�ʽ
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
					else//���ӷ�ʽ
					{
						if(tfont12[k].Msk[i]&(0x01<<j))	TFT_DrawPoint(x,y,fc);//��һ����
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
		continue;  //���ҵ���Ӧ�����ֿ������˳�����ֹ��������ظ�ȡģ����Ӱ��
	}
} 

/******************************************************************************
      ����˵������ʾ����16x16����
      ������ݣ�x,y��ʾ����
                *s Ҫ��ʾ�ĺ���
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
                mode:  0�ǵ���ģʽ  1����ģʽ
      ����ֵ��  ��
******************************************************************************/
void TFT_ShowChinese14x14(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode)
{
	u8 i,j,m=0;
	u16 k;
	u16 HZnum;//������Ŀ
	u16 TypefaceNum;//һ���ַ���ռ�ֽڴ�С
	u16 x0=x;
  TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	HZnum=sizeof(tfont14)/sizeof(typFNT_GB14);	//ͳ�ƺ�����Ŀ
	for(k=0;k<HZnum;k++) 
	{
		if ((tfont14[k].Index[0]==*(s))&&(tfont14[k].Index[1]==*(s+1)))
		{ 	
			TFT_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(i=0;i<TypefaceNum;i++)
			{
				for(j=0;j<8;j++)
				{	
					if(!mode)//�ǵ��ӷ�ʽ
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
					else//���ӷ�ʽ
					{
						if(tfont14[k].Msk[i]&(0x01<<j))	TFT_DrawPoint(x,y,fc);//��һ����
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
		continue;  //���ҵ���Ӧ�����ֿ������˳�����ֹ��������ظ�ȡģ����Ӱ��
	}
} 

void TFT_ShowChinese16x16(u16 x,u16 y,const u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode)
{
	u8 i,j,m=0;
	u16 k;
	u16 HZnum;//������Ŀ
	u16 TypefaceNum;//һ���ַ���ռ�ֽڴ�С
	u16 x0=x;
  TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	HZnum=sizeof(tfont16)/sizeof(typFNT_GB16);	//ͳ�ƺ�����Ŀ
	for(k=0;k<HZnum;k++) 
	{
		if ((tfont16[k].Index[0]==*(s))&&(tfont16[k].Index[1]==*(s+1)))
		{ 	
			TFT_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(i=0;i<TypefaceNum;i++)
			{
				for(j=0;j<8;j++)
				{	
					if(!mode)//�ǵ��ӷ�ʽ
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
					else//���ӷ�ʽ
					{
						if(tfont16[k].Msk[i]&(0x01<<j))	TFT_DrawPoint(x,y,fc);//��һ����
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
		continue;  //���ҵ���Ӧ�����ֿ������˳�����ֹ��������ظ�ȡģ����Ӱ��
	}
} 

/******************************************************************************
      ����˵������ʾ����24x24����
      ������ݣ�x,y��ʾ����
                *s Ҫ��ʾ�ĺ���
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
                mode:  0�ǵ���ģʽ  1����ģʽ
      ����ֵ��  ��
******************************************************************************/
void TFT_ShowChinese24x24(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode)
{
	u8 i,j,m=0;
	u16 k;
	u16 HZnum;//������Ŀ
	u16 TypefaceNum;//һ���ַ���ռ�ֽڴ�С
	u16 x0=x;
	TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	HZnum=sizeof(tfont24)/sizeof(typFNT_GB24);	//ͳ�ƺ�����Ŀ
	for(k=0;k<HZnum;k++) 
	{
		if ((tfont24[k].Index[0]==*(s))&&(tfont24[k].Index[1]==*(s+1)))
		{ 	
			TFT_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(i=0;i<TypefaceNum;i++)
			{
				for(j=0;j<8;j++)
				{	
					if(!mode)//�ǵ��ӷ�ʽ
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
					else//���ӷ�ʽ
					{
						if(tfont24[k].Msk[i]&(0x01<<j))	TFT_DrawPoint(x,y,fc);//��һ����
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
		continue;  //���ҵ���Ӧ�����ֿ������˳�����ֹ��������ظ�ȡģ����Ӱ��
	}
} 

/******************************************************************************
      ����˵������ʾ����32x32����
      ������ݣ�x,y��ʾ����
                *s Ҫ��ʾ�ĺ���
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
                mode:  0�ǵ���ģʽ  1����ģʽ
      ����ֵ��  ��
******************************************************************************/
void TFT_ShowChinese32x32(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode)
{
	u8 i,j,m=0;
	u16 k;
	u16 HZnum;//������Ŀ
	u16 TypefaceNum;//һ���ַ���ռ�ֽڴ�С
	u16 x0=x;
	TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	HZnum=sizeof(tfont32)/sizeof(typFNT_GB32);	//ͳ�ƺ�����Ŀ
	for(k=0;k<HZnum;k++) 
	{
		if ((tfont32[k].Index[0]==*(s))&&(tfont32[k].Index[1]==*(s+1)))
		{ 	
			TFT_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(i=0;i<TypefaceNum;i++)
			{
				for(j=0;j<8;j++)
				{	
					if(!mode)//�ǵ��ӷ�ʽ
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
					else//���ӷ�ʽ
					{
						if(tfont32[k].Msk[i]&(0x01<<j))	TFT_DrawPoint(x,y,fc);//��һ����
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
		continue;  //���ҵ���Ӧ�����ֿ������˳�����ֹ��������ظ�ȡģ����Ӱ��
	}
}


/******************************************************************************
      ����˵������ʾ�����ַ�
      ������ݣ�x,y��ʾ����
                num Ҫ��ʾ���ַ�
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
                mode:  0�ǵ���ģʽ  1����ģʽ
      ����ֵ��  ��
******************************************************************************/
void TFT_ShowChar(u16 x,u16 y,u8 num,u16 fc,u16 bc,u8 sizey,u8 mode)
{
	u8 temp,sizex,t,m=0;
	u16 i,TypefaceNum;//һ���ַ���ռ�ֽڴ�С
	u16 x0=x;
	sizex=sizey/2;
	TypefaceNum=(sizex/8+((sizex%8)?1:0))*sizey;
	num=num-' ';    //�õ�ƫ�ƺ��ֵ
	TFT_Address_Set(x,y,x+sizex-1,y+sizey-1);  //���ù��λ�� 
	for(i=0;i<TypefaceNum;i++)
	{ 
//		if(sizey==12)temp=ascii_1206[num][i];		       //����6x12����
		if(sizey==16)temp=ascii_1608[num][i];		 //����8x16����
//		else if(sizey==24)temp=ascii_2412[num][i];		 //����12x24����
//		else if(sizey==32)temp=ascii_3216[num][i];		 //����16x32����
		else return;
		for(t=0;t<8;t++)
		{
			if(!mode)//�ǵ���ģʽ
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
			else//����ģʽ
			{
				if(temp&(0x01<<t))TFT_DrawPoint(x,y,fc);//��һ����
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
      ����˵������ʾ�ַ���
      ������ݣ�x,y��ʾ����
                *p Ҫ��ʾ���ַ���
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
                mode:  0�ǵ���ģʽ  1����ģʽ
      ����ֵ��  ��
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
      ����˵������ʾ�ַ���  (����)
      ������ݣ�x,y��ʾ����
                *p Ҫ��ʾ���ַ���
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
                mode:  0�ǵ���ģʽ  1����ģʽ
      ����ֵ��  ��
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
      ����˵������ʾ�ַ���  (��Ӣ���)
      ������ݣ�x,y��ʾ����
                *p Ҫ��ʾ���ַ���
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
                mode:  0�ǵ���ģʽ  1����ģʽ
      ����ֵ��  ��
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
      ����˵������ʾ�����ַ��� �����ң�
      ������ݣ�x,y��ʾ����
                *p Ҫ��ʾ���ַ���
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
                mode:  0�ǵ���ģʽ  1����ģʽ
      ����ֵ��  ��
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
      ����˵������ʾ����
      ������ݣ�m������nָ��
      ����ֵ��  ��
******************************************************************************/
u32 mypow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;
	return result;
}


/******************************************************************************
      ����˵������ʾ��������
      ������ݣ�x,y��ʾ����
                num Ҫ��ʾ��������
                len Ҫ��ʾ��λ��
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
      ����ֵ��  ��
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
      ����˵������ʾ��λС������
      ������ݣ�x,y��ʾ����
                num Ҫ��ʾС������
                len Ҫ��ʾ��λ��
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
      ����ֵ��  ��
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
      ����˵������ʾͼƬ
      ������ݣ�x,y�������
                length ͼƬ����
                width  ͼƬ���
                pic[]  ͼƬ����    
      ����ֵ��  ��
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
      ����˵����������ʼ�ͽ�����ַ
      ������ݣ�x1,x2 �����е���ʼ�ͽ�����ַ
                y1,y2 �����е���ʼ�ͽ�����ַ
      ����ֵ��  ��
******************************************************************************/
void TFT_Address_Set( u16 x1, u16 y1, u16 x2, u16 y2 )
{
		tft_write_command( 0x2a ); //�е�ַ����
		tft_write_data16( x1 );
		tft_write_data16( x2 );
		tft_write_command( 0x2b ); //�е�ַ����
		tft_write_data16( y1 );
		tft_write_data16( y2 );
		tft_write_command( 0x2c ); //������д

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
//  ʵ�ֹ���: Gui_DrawLine
//  ����˵��: ���ߺ���
//  ������ע: ���ߺ�����ʹ��Bresenham �����㷨
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
      dx = x1-x0;//����x����
      dy = y1-y0;//����y����

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

    if (dx > dy)//x�������y���룬��ôÿ��x����ֻ��һ���㣬ÿ��y���������ɸ���
    {//���ߵĵ�������x���룬��x���������
      // initialize error term
      error = dy2 - dx; 

      // draw the line
      for (index=0; index <= dx; index++)//Ҫ���ĵ������ᳬ��x����
      {
        //����
        Gui_DrawPoint(x0,y0,Color);
        
        // test if error has overflowed
        if (error >= 0) //�Ƿ���Ҫ����y����ֵ
        {
          error-=dx2;

          // move to next line
          y0+=y_inc;//����y����ֵ
        } // end if error overflowed

        // adjust the error term
        error+=dy2;

        // move to the next pixel
        x0+=x_inc;//x����ֵÿ�λ���󶼵���1
      } // end for
    } // end if |slope| <= 1
    else//y�����x�ᣬ��ÿ��y����ֻ��һ���㣬x�����ɸ���
    {//��y��Ϊ��������
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
//  ʵ�ֹ���: Gui_box
//  ����˵��: �����κ���
//  ������ע: 
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
//��������: ����Ļ��ʾһ͹��İ�ť��
//��    ��: unsigned short x1,y1,x2,y2 ��ť�����ϽǺ����½�����
//��    ��: ��
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
//��������: ����Ļ��ʾһ���µİ�ť��
//��    ��: unsigned short x1,y1,x2,y2 ��ť�����ϽǺ����½�����
//��    ��: ��
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
