#include "motor.h"

#define XXXval 1800


const uint16_t stepval[720] = {0,3,5,8,10,13,16,18,21,24,26,29,31,34,37,39,42,44,47,50,52,55,58,60,63,65,68,71,73,76,78,81,84,86,89,92,94
,97,99,102,105,107,110,112,115,118,120,123,125,128,131,133,136,138,141,144,146,149,151,154,157,159,162,164
,167,170,172,175,177,180,183,185,188,190,193,195,198,201,203,206,208,211,214,216,219,221,224,226,229,232,234
,237,239,242,244,247,249,252,255,257,260,262,265,267,270,272,275,278,280,283,285,288,290,293,295,298,300,303
,306,308,311,313,316,318,321,323,326,328,331,333,336,338,341,343,346,348,351,353,356,358,361,363,366,368,371
,373,376,378,381,383,386,388,391,393,396,398,401,403,406,408,410,413,415,418,420,423,425,428,430,432,435,437
,440,442,445,447,450,452,454,457,459,462,464,466,469,471,474,476,478,481,483,486,488,490,493,495,498,500,502
,505,507,510,512,514,517,519,521,524,526,528,531,533,535,538,540,542,545,547,549,552,554,556,559,561,563,566
,568,570,573,575,577,579,582,584,586,589,591,593,595,598,600,602,605,607,609,611,614,616,618,620,623,625,627
,629,631,634,636,638,640,643,645,647,649,651,654,656,658,660,662,665,667,669,671,673,675,678,680,682,684,686
,688,690,693,695,697,699,701,703,705,707,710,712,714,716,718,720,722,724,726,728,731,733,735,737,739,741,743
,745,747,749,751,753,755,757,759,761,763,765,767,769,771,773,775,777,779,781,783,785,787,789,791,793,795,797
,799,801,803,805,807,809,811,813,815,816,818,820,822,824,826,828,830,832,834,835,837,839,841,843,845,847,849
,850,852,854,856,858,860,861,863,865,867,869,870,872,874,876,878,879,881,883,885,886,888,890,892,894,895,897
,899,900,902,904,906,907,909,911,912,914,916,918,919,921,923,924,926,928,929,931,933,934,936,937,939,941,942
,944,946,947,949,950,952,954,955,957,958,960,962,963,965,966,968,969,971,972,974,975,977,978,980,981,983,984
,986,987,989,990,992,993,995,996,998,999,1001,1002,1004,1005,1006,1008,1009,1011,1012,1013,1015,1016,1018,1019
,1020,1022,1023,1025,1026,1027,1029,1030,1031,1033,1034,1035,1037,1038,1039,1041,1042,1043,1044,1046,1047
,1048,1050,1051,1052,1053,1055,1056,1057,1058,1060,1061,1062,1063,1064,1066,1067,1068,1069,1070,1072,1073
,1074,1075,1076,1077,1079,1080,1081,1082,1083,1084,1085,1086,1088,1089,1090,1091,1092,1093,1094,1095,1096
,1097,1098,1099,1100,1102,1103,1104,1105,1106,1107,1108,1109,1110,1111,1112,1113,1114,1115,1116,1117,1117
,1118,1119,1120,1121,1122,1123,1124,1125,1126,1127,1128,1129,1129,1130,1131,1132,1133,1134,1135,1135,1136
,1137,1138,1139,1140,1140,1141,1142,1143,1144,1144,1145,1146,1147,1148,1148,1149,1150,1151,1151,1152,1153
,1154,1154,1155,1156,1156,1157,1158,1158,1159,1160,1160,1161,1162,1162,1163,1164,1164,1165,1166,1166,1167
,1167,1168,1169,1169,1170,1170,1171,1172,1172,1173,1173,1174,1174,1175,1175,1176,1176,1177,1177,1178,1178
,1179,1179,1180,1180,1181,1181,1182,1182,1183,1183,1184,1184,1184,1185,1185,1186,1186,1186,1187,1187,1188
,1188,1188,1189,1189,1189,1190,1190,1190,1191,1191,1191,1192,1192,1192,1193,1193,1193,1193,1194,1194,1194
,1194,1195,1195,1195,1195,1196,1196,1196,1196,1197,1197,1197,1197,1197,1197,1198,1198,1198,1198,1198,1198
,1198,1199,1199,1199,1199,1199,1199,1199,1199,1199,1200,1200,1200,1200,1200,1200,1200,1200,1200,1200,1200
,1200,1200};



static uint32_t dcount = 0;
uint16_t Timer1Counter1=0;

void motor_leftright(void) {
		for(dcount=0;dcount<280;dcount++) {
			ministep = 360;
			step_val_rate = 60;
			step_start = 0;
			step_num = 4;
			motor_dir = 0;
			motor_run();
		}
		Delay2(940000);
		for(dcount=0;dcount<280;dcount++) {
			ministep = 360;
			step_val_rate = 60;
			step_start = 0;
			step_num = 4;
			motor_dir = 1;
			motor_run();
		}

}

void motor_left(uint16_t s, uint16_t r, uint16_t t) {
		for(dcount=0;dcount<t;dcount++) {
			ministep = s;
			step_val_rate = r;
			step_start = 0;
			step_num = 4;
			motor_dir = 0;
			motor_run();
		}

}

void motor_right(uint16_t s, uint16_t r, uint16_t t) {
		for(dcount=0;dcount<t;dcount++) {
			ministep = s;
			step_val_rate = r;
			step_start = 0;
			step_num = 4;
			motor_dir = 1;
			motor_run();
		}

}

void motor_gpio_init(void)
{
		GPIO_Config_T GPIO_InitStructure;
 		RCM_EnableAHBPeriphClock(RCM_AHB_PERIPH_GPIOA);
		RCM_EnableAHBPeriphClock(RCM_AHB_PERIPH_GPIOB);
		RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_TMR1);
	
		//timer1
		GPIO_InitStructure.pin= (GPIO_PIN_11 | GPIO_PIN_10);
    GPIO_InitStructure.mode = GPIO_MODE_AF;
    GPIO_InitStructure.outtype = GPIO_OUT_TYPE_PP;
    GPIO_InitStructure.speed = GPIO_SPEED_50MHz;
    GPIO_InitStructure.pupd = GPIO_PUPD_NO;	
		GPIO_Config(GPIOA,&GPIO_InitStructure);
	
		GPIO_ConfigPinAF(GPIOA, GPIO_PIN_SOURCE_10, GPIO_AF_PIN2); 
		GPIO_ConfigPinAF(GPIOA, GPIO_PIN_SOURCE_11, GPIO_AF_PIN2); 
		
		GPIO_InitStructure.pin=GPIO_PIN_13;
    GPIO_InitStructure.mode = GPIO_MODE_OUT;
    GPIO_InitStructure.outtype = GPIO_OUT_TYPE_PP;
    GPIO_InitStructure.speed = GPIO_SPEED_50MHz;
    GPIO_InitStructure.pupd = GPIO_PUPD_NO;	
		GPIO_Config(GPIOB,&GPIO_InitStructure);

}


void motor_run(void) {
	
		timeout1 =250000;
		step_num_c = 0;
		
		if(ministep<2880) {
			stepstage1 = ministep >> 2;
			stepstage2 = ministep >> 1;
			stepstage3 = stepstage1 * 3;
			stepstage4 = ministep;
		} else {
			stepstage1 = 720;
			stepstage2 = 1440;
			stepstage3 = 2160;
			stepstage4 = 2880;
		}
		step_jump = 2880.0/ministep;   //720/ （ministep/4)
		if(step_jump>=1) {
			step_repeat = 1;
		} else {
			step_jump = 1;
			step_repeat = ministep/2880;  //ministep/720/4
		}
		
		step_val_tmp = (XXXval * step_val_rate) >> 7;
		if(step_start==0) {
			ministep_c = 0;
			step_val1 = XXXval;
			step_val2 = XXXval + step_val_tmp;
		} else if(step_start==1) {
			ministep_c = stepstage1;
			if(motor_dir) {
				step_val1 = XXXval - step_val_tmp;
			} else {
				step_val1 = XXXval + step_val_tmp;
			}
			step_val2 = XXXval;
		} else if(step_start==2) {
			ministep_c = stepstage2;
			step_val1 = XXXval;
			step_val2 = XXXval - step_val_tmp;
		} else if(step_start==3) {
			ministep_c = stepstage3;
			if(motor_dir) {
				step_val1 = XXXval + step_val_tmp;
			} else {
				step_val1 = XXXval - step_val_tmp;
			}
			step_val2 = XXXval;
		}
		
		while(--timeout1>0) {
					
				TMR_SetCompare4(TMR1, step_val1);
				TMR_SetCompare3(TMR1, step_val2);

				ministep_c++;
				if(ministep_c==stepstage1 || ministep_c==stepstage2 || ministep_c==stepstage3 || ministep_c==stepstage4) {  //待优化查bug
					step_num_c++;
					if(step_num_c>=step_num) {
						break;
					}
				}
				if(ministep_c>stepstage4-1) {
					ministep_c = 0;
					
					//if(key>36000 && stepi>speed) stepi--;
					//if(key<1400 && stepi<12) stepi++;
				}
				
//					if(key>46000 && (step1 == 0 || step1 == 45 || step1 == 90 || step1 == 135) && stepi>speed) stepi--;
//					if(key<1400 && (step1 == 0 || step1 == 45 || step1 == 90 || step1 == 135) && stepi<14) stepi++;
					
				if(ministep_c>=stepstage3) {
					step_val_idx = stepstage4 - 1 - ministep_c;
					if(step_jump>1) step_val_idx *= step_jump;
					step_val_tmp = (stepval[step_val_idx] * step_val_rate) >> 7;
					step_val1 = (motor_dir?(XXXval + step_val_tmp): (XXXval - step_val_tmp));     // >>7 除以128
					step_val_idx = ministep_c - stepstage3;
					if(step_jump>1) step_val_idx *= step_jump;
					step_val2 = XXXval + ((stepval[step_val_idx] * step_val_rate) >> 7);  
				} else if(ministep_c>=stepstage2) {
					step_val_idx = ministep_c - stepstage2;
					if(step_jump>1) step_val_idx *= step_jump;
					step_val_tmp = (stepval[step_val_idx] * step_val_rate) >> 7;
					step_val1 = (motor_dir?XXXval + step_val_tmp: XXXval - step_val_tmp);
					step_val_idx = stepstage3 - 1 - ministep_c;
					if(step_jump>1) step_val_idx *= step_jump;
					step_val2 = XXXval - ((stepval[step_val_idx] * step_val_rate) >> 7);   //179 - (ministep_c + 45)
				} else if(ministep_c>=stepstage1) {
					step_val_idx = stepstage2 - 1 - ministep_c;
					if(step_jump>1) step_val_idx *= step_jump;
					step_val_tmp = (stepval[step_val_idx] * step_val_rate) >> 7;
					step_val1 = (motor_dir?XXXval - step_val_tmp: XXXval + step_val_tmp);
					step_val_idx = ministep_c - stepstage1;
					if(step_jump>1) step_val_idx *= step_jump;
					step_val2 = XXXval - ((stepval[step_val_idx] * step_val_rate) >> 7);   //ministep_c+45 - 90
				} else {
					step_val_idx = ministep_c;
					if(step_jump>1) step_val_idx *= step_jump;
					step_val_tmp = (stepval[step_val_idx] * step_val_rate) >> 7;
					step_val1 = (motor_dir?XXXval - step_val_tmp: XXXval + step_val_tmp);
					step_val_idx = stepstage1 - 1 - ministep_c;
					if(step_jump>1) step_val_idx *= step_jump;
					step_val2 = XXXval + ((stepval[step_val_idx] * step_val_rate) >> 7);   //89 - (ministep_c+45)
				}

				while(Timer1Counter1<step_repeat) {}
				Timer1Counter1 = 0;
				

		}
}

int motor_timer_init() {
	TMR_TimeBase_T timeBaseConfig;
	TMR_OCConfig_T OCcongigStruct;

	TMR_ConfigInternalClock(TMR1);
	
	TMR_ConfigTimeBaseStruct(&timeBaseConfig);
	timeBaseConfig.counterMode = TMR_COUNTER_MODE_UP;
	timeBaseConfig.period = 3600;  //autoreload  //1000 //2400
	timeBaseConfig.div = 0;
	TMR_ConfigTimeBase(TMR1, &timeBaseConfig);

//	GPIO_ConfigPinRemap(GPIO_PARTIAL_REMAP_TMR1);	
	TMR_EnableAUTOReload(TMR1);
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
	TMR_OC3Config(TMR1, &OCcongigStruct);
	OCcongigStruct.OC_Mode = TMR_OC_MODE_PWM1;
	OCcongigStruct.OC_Polarity = TMR_OC_POLARITY_HIGH;
	OCcongigStruct.OC_OutputState = TMR_OUTPUT_STATE_ENABLE;
	OCcongigStruct.OC_NPolarity = TMR_OC_NPOLARITY_LOW;
	OCcongigStruct.OC_OutputNState = TMR_OUTPUT_NSTATE_DISABLE;
	OCcongigStruct.OC_Idlestate = TMR_OCIDLESTATE_RESET;
	OCcongigStruct.OC_NIdlestate = TMR_OCNIDLESTATE_RESET;
	OCcongigStruct.Pulse = 0x2df;  //CC1
	TMR_OC4Config(TMR1, &OCcongigStruct);
	
	
	
	TMR_EnablePWMOutputs(TMR1);
	
	TMR_ClearIntFlag(TMR1, TMR_INT_FLAG_UPDATE);
	TMR_ClearIntFlag(TMR1, TMR_INT_FLAG_CH3);
  TMR_EnableInterrupt(TMR1, TMR_INT_UPDATE);					//开启中断
  TMR_EnableInterrupt(TMR1, TMR_INT_CH3);					//开启中断
	
	//NVIC_EnableIRQRequest(TMR1_CC_IRQn, 5);			//定时器1
	NVIC_EnableIRQRequest(TMR1_BRK_UP_TRG_COM_IRQn, 5);			//定时器1

	
	return 0;
}

void TMR1_BRK_UP_TRG_COM_IRQHandler(void)
{
	
	if(TMR_ReadIntFlag(TMR1, TMR_INT_FLAG_CH3) == SET)
  { 
		
		Timer1Counter1++;
		
		TMR_ClearIntFlag(TMR1, TMR_INT_FLAG_CH3);
  }
	if(TMR_ReadIntFlag(TMR1, TMR_INT_FLAG_UPDATE) == SET)
  { 
		
		//Timer1Counter++;
		
		TMR_ClearIntFlag(TMR1, TMR_INT_FLAG_UPDATE);
  }
}
