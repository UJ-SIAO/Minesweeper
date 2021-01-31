  /**
  ******************************************************************************
  * @file    GUI_App.c
  * @author  MCD Application Team
  * @brief   Simple demo drawing "Hello world"  
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright © 2018 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
#include "GUI_App.h"
#include "GUI.h"
#include "stm32746g_discovery_ts.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery.h"
#include "DIALOG.h"
extern  WM_HWIN CreateWindow(void);
extern int second;
extern int min;
extern int start;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim;
int presecond=30;
GUI_PID_STATE GUI_touch;  
	TS_StateTypeDef pre_touch;    
	TS_StateTypeDef touch;
 int boom_number;	

void GRAPHICS_MainTask(void) {

  /* 2- Create a Window using GUIBuilder */
		CreateWindow();
//CreateGame();
/* USER CODE BEGIN GRAPHICS_MainTask */
 
	WM_HWIN      hItem;
	WM_MESSAGE * pMsg;
	char value[20]; 
	GUI_touch.Layer = 0;
 /* User can implement his graphic application here */
/* USER CODE END GRAPHICS_MainTask */
  while(1)
{
	BSP_TS_GetState(&touch);                
	if ((touch.touchX[0] != 0) && (touch.touchY[0] != 0))
	{
		pre_touch.touchX[0] = touch.touchX[0];
		pre_touch.touchY[0] = touch.touchY[0];
	}
	if(second!=presecond|| touch.touchDetected)
		GUI_touch.Pressed = 1;  
	else
		GUI_touch.Pressed = 0; 
	GUI_touch.x = pre_touch.touchX[0];
	GUI_touch.y = pre_touch.touchY[0];
	GUI_TOUCH_StoreStateEx(&GUI_touch);
	/*if(start){
	hItem = WM_GetDialogItem(pMsg->hWin, (0x800+0x92));
	sprintf(value,"%02d : %02d",min , second);
  EDIT_SetText(hItem, value);
  EDIT_SetFont(hItem, GUI_FONT_24_1);
  EDIT_SetTextAlign(hItem, GUI_TA_CENTER | GUI_TA_VCENTER);
	}*/
	presecond = second;
	GUI_Delay(10);
		
	
}
}

/*************************** End of file ****************************/
