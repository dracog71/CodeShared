/**
  ******************************************************************************
  * @file    OSTHREADTIMER.c
  * @author  EDESIGN TEAM
  * @version V1.3.0        
  * @date    24-Febrero-2015
  * @brief   ________________________________________________________________
  *          ________________________________________________________________ 
  ****************************************************************************** 
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */
	
		/* Incluside------------------------------------------------------------------*/
#include "osThreadTimer.h"

 TIM_TimeBaseInitTypeDef TIM_BaseStruct;


 /**
  * @brief  Timer de cambio de Puerta Abierta 
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadTimer_BUZZER()
{
	  TIM_TimeBaseInitTypeDef timerInitStructure; 
    NVIC_InitTypeDef nvicStructure;
	
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    timerInitStructure.TIM_Prescaler = 100;
    timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    timerInitStructure.TIM_Period = 8999;
    timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    timerInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &timerInitStructure);
	
    TIM_Cmd(TIM2, ENABLE);
	  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	
    nvicStructure.NVIC_IRQChannel = TIM2_IRQn;
    nvicStructure.NVIC_IRQChannelPreemptionPriority = 0;
    nvicStructure.NVIC_IRQChannelSubPriority = 1;
    nvicStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvicStructure);
}

/**
  * @brief  Timer de actualizacion de mensaje en pantalla
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadTimer_LCD_Refresh()
{
	  TIM_TimeBaseInitTypeDef timerInitStructure; 
    NVIC_InitTypeDef nvicStructure;
	
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    timerInitStructure.TIM_Prescaler = 40000;
    timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    timerInitStructure.TIM_Period = 10000;
    timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    timerInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM3, &timerInitStructure);
	
    TIM_Cmd(TIM3, ENABLE);
	  TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	
    nvicStructure.NVIC_IRQChannel = TIM3_IRQn;
    nvicStructure.NVIC_IRQChannelPreemptionPriority = 0;
    nvicStructure.NVIC_IRQChannelSubPriority = 1;
    nvicStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvicStructure);
}
 
/**
  * @brief  Timer de cambio de Puerta Abierta 
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadTimer_Cronometro()
{
	  TIM_TimeBaseInitTypeDef timerInitStructure; 
    NVIC_InitTypeDef nvicStructure;
	
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
    timerInitStructure.TIM_Prescaler = 100;
    timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    timerInitStructure.TIM_Period = 8999;
    timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    timerInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM4, &timerInitStructure);
	
    TIM_Cmd(TIM4, ENABLE);
	  TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
	
	
    nvicStructure.NVIC_IRQChannel = TIM4_IRQn;
    nvicStructure.NVIC_IRQChannelPreemptionPriority = 0;
    nvicStructure.NVIC_IRQChannelSubPriority = 1;
    nvicStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvicStructure);
}


/**
  * @brief  Timer de cambio de Puerta Abierta 
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadTimer_Estribo()
{
	  TIM_TimeBaseInitTypeDef timerInitStructure; 
    NVIC_InitTypeDef nvicStructure;
	
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
    timerInitStructure.TIM_Prescaler = 100;
    timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    timerInitStructure.TIM_Period = 8999;
    timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    timerInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM5, &timerInitStructure);
	
    TIM_Cmd(TIM5, ENABLE);
	  TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
	
	
    nvicStructure.NVIC_IRQChannel = TIM5_IRQn;
    nvicStructure.NVIC_IRQChannelPreemptionPriority = 0;
    nvicStructure.NVIC_IRQChannelSubPriority = 1;
    nvicStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvicStructure);
}

/******************* (C) COPYRIGHT 2015 EDESIGN *****FIN DE ARCHIVO****/
