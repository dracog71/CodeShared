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
	
	** Enable clock for TIM4 **
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
  **	
	TIM4 is connected to APB1 bus, which has on F407 device 42MHz clock 				
	But, timer has internal PLL, which double this frequency for timer, up to 84MHz 	
	Remember: Not each timer is connected to APB1, there are also timers connected 	
	on APB2, which works at 84MHz by default, and internal PLL increase 				
	this to up to 168MHz 															
	
	Set timer prescaller 
	Timer count frequency is set with 
	
	timer_tick_frequency = Timer_default_frequency / (prescaller_set + 1)		
	
	In our case, we want a max frequency for timer, so we set prescaller to 0 		
	And our timer will have tick frequency		
	
	timer_tick_frequency = 84000000 / (0 + 1) = 84000000 
  **	
	TIM_BaseStruct.TIM_Prescaler = 0;
	** Count up **
    TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
  **
	Set timer period when it have reset
	First you have to know max value for timer
	In our case it is 16bit = 65535
	To get your frequency for PWM, equation is simple
	
	PWM_frequency = timer_tick_frequency / (TIM_Period + 1)
	
	If you know your PWM frequency you want to have timer period set correct
	
	TIM_Period = timer_tick_frequency / PWM_frequency - 1
	
	In our case, for 10Khz PWM_frequency, set Period to
	
	TIM_Period = 84000000 / 10000 - 1 = 8399
	
	If you get TIM_Period larger than max timer value (in our case 65535),
	you have to choose larger prescaler and slow down timer tick frequency
  *
    TIM_BaseStruct.TIM_Period = 8399; * 10kHz PWM *
    TIM_BaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_BaseStruct.TIM_RepetitionCounter = 0;
	* Initialize TIM4 *
    TIM_TimeBaseInit(TIM4, &TIM_BaseStruct);
	* Start count on TIM4 *
    TIM_Cmd(TIM4, ENABLE);

  */
	
		/* Incluside------------------------------------------------------------------*/
#include "osThreadTimer.h"

 TIM_TimeBaseInitTypeDef TIM_BaseStruct;

/**
  * @brief  Timer de control de apagado de leds
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadTimer_LED_OFF()
{
	  TIM_TimeBaseInitTypeDef timerInitStructure; 
    NVIC_InitTypeDef nvicStructure;
	
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    timerInitStructure.TIM_Prescaler = 1000;
    timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    timerInitStructure.TIM_Period = 5000;
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
  * @brief  Configuracion de relojes del timer 3
  * @retval Ninguno
  */
void osThreadTimer_PWM_SOFT(){
	 
	NVIC_InitTypeDef nvicStructure;

	/* Habilitar reloj para TIM4*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	
	TIM_BaseStruct.TIM_Prescaler = 3;   // Segundos 10000
  TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_BaseStruct.TIM_Period = 2500; //1679; /* 50 2500  8399*/
  TIM_BaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_BaseStruct.TIM_RepetitionCounter = 0;
	
	/* Initializar TIM3 */
  TIM_TimeBaseInit(TIM3, &TIM_BaseStruct);
	
	/* Comenzar conteo en TIM3 */
  TIM_Cmd(TIM3,ENABLE);
  TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

  /* Temporizador a cero */	
	TIM3->CNT = 0;
	
  nvicStructure.NVIC_IRQChannel = TIM3_IRQn;
  nvicStructure.NVIC_IRQChannelPreemptionPriority = 0;
  nvicStructure.NVIC_IRQChannelSubPriority = 1;
  nvicStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&nvicStructure);
}

/**
  * @brief  Configuracion de relores del timer 4
  * @retval Ninguno
  */
void osThreadTimer_20_nanoseconds(){
	 
	NVIC_InitTypeDef nvicStructure;

	/* Habilitar reloj para TIM4*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);	
	TIM_BaseStruct.TIM_Prescaler = 9;   // Segundos 10000
  TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_BaseStruct.TIM_Period = 8399; //1679; /* 50 2500  8399*/
  TIM_BaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_BaseStruct.TIM_RepetitionCounter = 0;
	
	/* Initializar TIM4 */
  TIM_TimeBaseInit(TIM4, &TIM_BaseStruct);
	
	/* Comenzar conteo en TIM4 */
  TIM_Cmd(TIM4,DISABLE);
  TIM_ITConfig(TIM4, TIM_IT_Update, DISABLE);

  /* Temporizador a cero */	
	TIM4->CNT = 0;
	
  nvicStructure.NVIC_IRQChannel = TIM4_IRQn;
  nvicStructure.NVIC_IRQChannelPreemptionPriority = 0;
  nvicStructure.NVIC_IRQChannelSubPriority = 1;
  nvicStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&nvicStructure);
}

/**
  * @brief  Timer de cambio de botones 
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadTimer_Emergency_Level()
{
	  TIM_TimeBaseInitTypeDef timerInitStructure; 
    NVIC_InitTypeDef nvicStructure;
	
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
    timerInitStructure.TIM_Prescaler = 10000;
    timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    timerInitStructure.TIM_Period = 2500; //2500
    timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    timerInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM5, &timerInitStructure);
    //TIM_Cmd(TIM5, ENABLE);
	
	  //TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
	
    nvicStructure.NVIC_IRQChannel = TIM5_IRQn;
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
void osThreadTimer_PuertaAbierta()
{
	  TIM_TimeBaseInitTypeDef timerInitStructure; 
    NVIC_InitTypeDef nvicStructure;
	
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);
    timerInitStructure.TIM_Prescaler = 10000;;
    timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    timerInitStructure.TIM_Period = 2500;
    timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    timerInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM7, &timerInitStructure);
    //TIM_Cmd(TIM7, ENABLE);
	
	  //TIM_ITConfig(TIM7, TIM_IT_Update, ENABLE);
	
	
    nvicStructure.NVIC_IRQChannel = TIM7_IRQn;
    nvicStructure.NVIC_IRQChannelPreemptionPriority = 0;
    nvicStructure.NVIC_IRQChannelSubPriority = 1;
    nvicStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvicStructure);
}

/******************* (C) COPYRIGHT 2015 EDESIGN *****FIN DE ARCHIVO****/
