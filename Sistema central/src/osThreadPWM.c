/**
  ***********************************************************************************************************
  * @file    osThreadPWM.c
  * @author  EDESIGN TEAM
  * @version V1.3.0         modificado por JMLG para MDK-ARM V5.0
  * @date    12-Febrero-2015
  * @brief   Archivo de configuracion avanzada automatizada para PWM's.
  *          Este archivo contiene configuraciones para control de PWM's definidos.
  *             
  * 1.  Este archivo provee de Funciones globales que configuran el PWM dependiendo de su valor 
	*     ascendiente, de forma que por cada timer, se toma como la suma del total cada salida posible activa
  *     las funciones de uso son:
	*
  *      - PWM_Start(x,frec): Configura todos los valores necesarios para activar el 
	*                           PWM solicitado, tomando el valor de la tabla de abajo
  *                           el valor de "x"	
	*
  *      - PWM_DutyCycle(x,%): Actualiza el ancho de pulso en que trabajará el PWM
	*	                           Con valores comprendidos entre el 0-99
	*
  *      - Ejemplo : La siguiente Configuracion inicializa el PWM 15 (PD14) a 10Khz a 90 % de su Ciclo de Trabajo
  *                  PWM_Start(15,10000);
  *                  PWM_DutyCycle(15,90);	
	*
  *                   
  * 2. Este archivo configura los PWM's segun lo siguiente:
  *============================================================================================================
  *============================================================================================================
  *                    PWM's Soportados por STM32f407VG6T6
  *------------------------------------------------------------------------------------------------------------
  *        NUMERO DE PWM                          | OUTPUT 
  *------------------------------------------------------------------------------------------------------------
  *        PWM1                                   | PE9
  *------------------------------------------------------------------------------------------------------------
  *        PWM2                                   | PE11
  *------------------------------------------------------------------------------------------------------------
  *        PWM3                                   | PE13
  *------------------------------------------------------------------------------------------------------------
  *        PWM4                                   | PE14
  *------------------------------------------------------------------------------------------------------------
  *        PWM5                                   | PA15
  *------------------------------------------------------------------------------------------------------------
  *        PWM6                                   | PB3
  *------------------------------------------------------------------------------------------------------------
  *        PWM7                                   | PB10
  *------------------------------------------------------------------------------------------------------------
  *        PWM8                                   | PB11
  *------------------------------------------------------------------------------------------------------------
  *        PWM9                                   | PB4
  *------------------------------------------------------------------------------------------------------------
  *        PWM10                                  | PB5
  *------------------------------------------------------------------------------------------------------------
  *        PWM11                                  | PB0
  *------------------------------------------------------------------------------------------------------------
  *        PWM12                                  | PB1
  *------------------------------------------------------------------------------------------------------------
  *        PWM13                                  | PD12
  *------------------------------------------------------------------------------------------------------------
  *        PWM14                                  | PD13
  *------------------------------------------------------------------------------------------------------------
  *        PWM15                                  | PD14
  *------------------------------------------------------------------------------------------------------------
  *        PWM16                                  | PD15
  *------------------------------------------------------------------------------------------------------------
  *        PWM17          	                      | PA0
  *------------------------------------------------------------------------------------------------------------
	*        PWM18                                  | PA1
  *------------------------------------------------------------------------------------------------------------
  *        PWM19                                  | PA2
  *------------------------------------------------------------------------------------------------------------
  *        PWM20                                  | PA3
  *------------------------------------------------------------------------------------------------------------
  *        PWM21                                  | PC6
  *------------------------------------------------------------------------------------------------------------
  *        PWM22                                  | PC7
  *------------------------------------------------------------------------------------------------------------
  *        PWM23                                  | PC8
  *------------------------------------------------------------------------------------------------------------
  *        PWM24                                  | PC9
  *------------------------------------------------------------------------------------------------------------
  *        PWM25                                  | PE5
  *------------------------------------------------------------------------------------------------------------
  *        PWM26                                  | PE6
  *------------------------------------------------------------------------------------------------------------
  *        PWM27                                  | PB8
  *------------------------------------------------------------------------------------------------------------
  *        PWM28          	                      | PB9
  *------------------------------------------------------------------------------------------------------------
  *        PWM29                                  | PB14
  *------------------------------------------------------------------------------------------------------------
  *        PWM30          	                      | PB15
  *------------------------------------------------------------------------------------------------------------
  *============================================================================================================
  *============================================================================================================
  *                    TIMERS ENCARGADOS DEL PWM
  *------------------------------------------------------------------------------------------------------------
  *        PWM                                    | TIMER
  *------------------------------------------------------------------------------------------------------------
  *        PWM1  PWM2  PWM3  PWM4                 | TIM1
  *------------------------------------------------------------------------------------------------------------
  *        PWM5  PWM6  PWM7  PWM8                 | TIM2
  *------------------------------------------------------------------------------------------------------------
  *        PWM9  PWM10 PWM11 PWM12                | TIM3
  *------------------------------------------------------------------------------------------------------------
  *        PWM13 PWM14 PWM15 PWM16                | TIM4
  *------------------------------------------------------------------------------------------------------------
  *        PWM17 PWM18 PWM19 PWM20                | TIM5
  *------------------------------------------------------------------------------------------------------------
  *        PWM21 PWM22 PWM23 PWM24                | TIM8
  *------------------------------------------------------------------------------------------------------------
  *        PWM25 PWM26                            | TIM9
  *------------------------------------------------------------------------------------------------------------
  *        PWM27                                  | TIM10
  *------------------------------------------------------------------------------------------------------------
  *        PWM28                                  | TIM11
  *------------------------------------------------------------------------------------------------------------
  *        PWM29 PWM30                            | TIM12
  *------------------------------------------------------------------------------------------------------------
  *============================================================================================================      
  *************************************************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 EDESIGN</center></h2>
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
#include "osThreadPWM.h"
	
	/** @addtogroup PWM_Control_Conf
  * @{
  */ 

 TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
  TIM_OCInitTypeDef TIM_OCInitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;
	
		
/** @addtogroup Definiciones de Sistema
  * @{
  */ 
	uint32_t FrecuenciaGlobal  = 1000000;
	uint32_t CicloCalculado = 0;
	uint32_t Period = 10;
	
/**
  * @brief  Funcion de Arranque de valores del PWM
  * @param  PWM , Frecuencia
  * @retval Ninguno
  */	
void osThreadPWM_Start(uint32_t PWM, uint32_t Frecuencia){	
 
	  /*Selección del Timer adecuado con sus configuraciones propias*/
			switch (PWM) {
		case 1:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
		  GPIO_PinAFConfig(GPIOE, GPIO_PinSource9, GPIO_AF_TIM1);
			osThreadPWM_Conf_General(GPIOE,PWM,TIM1,1,Frecuencia,1);
			break;
		case 2:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
		  GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_TIM1);
			osThreadPWM_Conf_General(GPIOE,PWM,TIM1,1,Frecuencia,2);
			break;
		case 3:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
		  GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_TIM1);
			osThreadPWM_Conf_General(GPIOE,PWM,TIM1,1,Frecuencia,3);
			break;
		case 4:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
		  GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_TIM1);
			osThreadPWM_Conf_General(GPIOE,PWM,TIM1,1,Frecuencia,4);
			break;
		case 5:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
		  GPIO_PinAFConfig(GPIOA, GPIO_PinSource15, GPIO_AF_TIM2);
			osThreadPWM_Conf_General(GPIOA,PWM,TIM2,2,Frecuencia,1);
			break;
		case 6:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
		  GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_TIM2);
			osThreadPWM_Conf_General(GPIOB,PWM,TIM2,2,Frecuencia,2);
			break;
		case 7:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
		  GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_TIM2);
			osThreadPWM_Conf_General(GPIOB,PWM,TIM2,2,Frecuencia,3);
			break;
		case 8:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
		  GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_TIM2);
			osThreadPWM_Conf_General(GPIOB,PWM,TIM2,2,Frecuencia,4);
			break;
		case 9:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
		  GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_TIM3);
			osThreadPWM_Conf_General(GPIOB,PWM,TIM3,3,Frecuencia,1);
			break;
		case 10:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
		  GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_TIM3);
			osThreadPWM_Conf_General(GPIOB,PWM,TIM3,3,Frecuencia,2);
			break;
		case 11:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
		  GPIO_PinAFConfig(GPIOB, GPIO_PinSource0, GPIO_AF_TIM3);
			osThreadPWM_Conf_General(GPIOB,PWM,TIM3,3,Frecuencia,3);
			break;
		case 12:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
		  GPIO_PinAFConfig(GPIOB, GPIO_PinSource1, GPIO_AF_TIM3);
			osThreadPWM_Conf_General(GPIOB,PWM,TIM3,3,Frecuencia,4);
			break;
		case 13:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
		  GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
			osThreadPWM_Conf_General(GPIOD,PWM,TIM4,4,Frecuencia,1);
			break;
		case 14:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
		  GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);
			osThreadPWM_Conf_General(GPIOD,PWM,TIM4,4,Frecuencia,2);
			break;
		case 15:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
		  GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);
			osThreadPWM_Conf_General(GPIOD,PWM,TIM4,4,Frecuencia,3);
			break;
		case 16:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
		  GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_TIM4);
			osThreadPWM_Conf_General(GPIOD,PWM,TIM4,4,Frecuencia,4);
			break;
		case 17:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
		  GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_TIM5);
			osThreadPWM_Conf_General(GPIOA,PWM,TIM5,5,Frecuencia,1);
			break;
		case 18:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
		  GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_TIM5);
			osThreadPWM_Conf_General(GPIOA,PWM,TIM5,5,Frecuencia,2);
			break;
		case 19:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
		  GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_TIM5);
			osThreadPWM_Conf_General(GPIOA,PWM,TIM5,5,Frecuencia,3);
			break;
		case 20:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
		  GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM5);
			osThreadPWM_Conf_General(GPIOA,PWM,TIM5,5,Frecuencia,4);
			break;
		case 21:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
		  GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM8);
			osThreadPWM_Conf_General(GPIOC,PWM,TIM8,8,Frecuencia,1);
			break;
		case 22:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
		  GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM8);
			osThreadPWM_Conf_General(GPIOC,PWM,TIM8,8,Frecuencia,2);
			break;
		case 23:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
		  GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM8);
			osThreadPWM_Conf_General(GPIOC,PWM,TIM8,8,Frecuencia,3);
			break;
		case 24:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
		  GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_TIM8);
			osThreadPWM_Conf_General(GPIOC,PWM,TIM8,8,Frecuencia,4);
			break;
		case 25:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
		  GPIO_PinAFConfig(GPIOE, GPIO_PinSource5, GPIO_AF_TIM9);
			osThreadPWM_Conf_General(GPIOE,PWM,TIM9,9,Frecuencia,1);
			break;
		case 26:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
		  GPIO_PinAFConfig(GPIOE, GPIO_PinSource6, GPIO_AF_TIM9);
			osThreadPWM_Conf_General(GPIOE,PWM,TIM9,9,Frecuencia,2);
			break;
		case 27:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
		  GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_TIM10);
			osThreadPWM_Conf_General(GPIOB,PWM,TIM10,10,Frecuencia,1);
			break;
		case 28:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
		  GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_TIM11);
			osThreadPWM_Conf_General(GPIOB,PWM,TIM11,11,Frecuencia,1);
			break;
		case 29:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
		  GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_TIM12);
			osThreadPWM_Conf_General(GPIOB,PWM,TIM12,12,Frecuencia,1);
			break;
		case 30:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
		  GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_TIM12);
			osThreadPWM_Conf_General(GPIOB,PWM,TIM12,12,Frecuencia,2);
			break;
		default:
			break;
	}
	
}	

/**
  * @brief  Configuracion general de los timers
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadPWM_Conf_General(GPIO_TypeDef* GPIOx, uint32_t PWM, TIM_TypeDef* TIMx, uint32_t TIMER,uint32_t Frecuencia, uint32_t Channel){

	 uint16_t PrescalerValue = 0;
	
	  /* Se habilitan los buses que carga el timer a configurar*/
	  /* Habilitación de la funcion especial a PWM*/
			switch (TIMER) {
		case 1:
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
		  TIM_CtrlPWMOutputs(TIMx, ENABLE); 
			break;
		case 2:
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
		  break;
		case 3:
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
			break;
		case 4:
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
			break;
		case 5:
		  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
			break;
		case 8:
		  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);
		  TIM_CtrlPWMOutputs(TIMx, ENABLE);
		  Frecuencia = Frecuencia / 2;
			break;
		case 9:
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);
			break;
		case 10:
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10, ENABLE);
			break;
		case 11:
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM11, ENABLE);
			break;
		case 12:
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12, ENABLE);
			break;
		default:
			break;
	}		
	  /* Configuracion del pin de salida para trabajar PWM*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
    GPIO_Init(GPIOx, &GPIO_InitStructure);
		
   
	  /* Configuracion del PREESCALER*/
   
	  PrescalerValue = (uint16_t) ((SystemCoreClock /FrecuenciaGlobal) / 2) - 1;
		TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
		
		/*Cálculo de la variable TIM_Period correpondiente al valor entregado*/
	  Period = ((FrecuenciaGlobal / Frecuencia) - 1);
    TIM_TimeBaseStructure.TIM_Period = Period;
		
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIMx, &TIM_TimeBaseStructure);

    /* Valores correspondientes al PWM*/
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  
    TIM_OCInitStructure.TIM_Pulse = 0;
    TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
    TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
		
		/*Valores Correspondientes al canal del Timer*/
		switch (Channel) {
		case 1:
			TIM_OC1Init(TIMx, &TIM_OCInitStructure);
			TIM_OC1PreloadConfig(TIMx, TIM_OCPreload_Enable);
			break;
		case 2:
			TIM_OC2Init(TIMx, &TIM_OCInitStructure);
			TIM_OC2PreloadConfig(TIMx, TIM_OCPreload_Enable);
			break;
		case 3:
			TIM_OC3Init(TIMx, &TIM_OCInitStructure);
			TIM_OC3PreloadConfig(TIMx, TIM_OCPreload_Enable);
			break;
		case 4:
			TIM_OC4Init(TIMx, &TIM_OCInitStructure);
			TIM_OC4PreloadConfig(TIMx, TIM_OCPreload_Enable);
			break;
		default:
			break;
	}
	
    /* Habilitacion del reloj interno del Timer*/
    TIM_Cmd(TIMx, ENABLE);
   
	}

/**
  * @brief  Calculo del PWM
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadPWM_DutyCycle (uint32_t PWM, uint32_t PorcentajeCiclo){
		
		/*Computo del procentaje del Ciclo de trabajo*/
		
		//if(PorcentajeCiclo == 100) PorcentajeCiclo = 99;
		
		CicloCalculado = ( PorcentajeCiclo * Period) / 100 ; 
		
			switch (PWM) {
		case 1:
			TIM1->CCR1 = CicloCalculado;
			break;
		case 2:
		  TIM1->CCR2 = CicloCalculado;
			break;
		case 3:
		  TIM1->CCR3 = CicloCalculado;
			break;
		case 4:
			TIM1->CCR4 = CicloCalculado; 
			break;
		case 5:
			TIM2->CCR1 = CicloCalculado; 
			break;
		case 6:
			TIM2->CCR2 = CicloCalculado;
			break;
		case 7:
		  TIM2->CCR3 = CicloCalculado;
			break;
		case 8:
			TIM2->CCR4 = CicloCalculado;
			break;
		case 9:
			TIM3->CCR1 = CicloCalculado;
			break;
		case 10:
		  TIM3->CCR2 = CicloCalculado;
			break;
		case 11:
		  TIM3->CCR3 = CicloCalculado;
			break;
		case 12:
			TIM3->CCR4 = CicloCalculado;
			break;
		case 13:
			TIM4->CCR1 = CicloCalculado;
			break;
		case 14:
			TIM4->CCR2 = CicloCalculado;
			break;
		case 15:
			TIM4->CCR3 = CicloCalculado;
			break;
		case 16:
		  TIM4->CCR4 = CicloCalculado;
			break;
		case 17:
			TIM5->CCR1 = CicloCalculado;
			break;
		case 18:
		  TIM5->CCR2 = CicloCalculado;
			break;
		case 19:
			TIM5->CCR3 = CicloCalculado;
			break;
		case 20:
		  TIM5->CCR4 = CicloCalculado;
			break;
		case 21:
			TIM8->CCR1 = CicloCalculado;
			break;
		case 22:
			TIM8->CCR2 = CicloCalculado;
			break;
		case 23:
			TIM8->CCR3 = CicloCalculado;
			break;
		case 24:
			TIM8->CCR4 = CicloCalculado;
			break;
		case 25:
			TIM9->CCR1 = CicloCalculado;
			break;
		case 26:
			TIM9->CCR2 = CicloCalculado;
			break;
		case 27:
		  TIM10->CCR1 = CicloCalculado;
			break;
		case 28:
			TIM11->CCR1 = CicloCalculado;
			break;
		case 29:
		  TIM12->CCR1 = CicloCalculado;
			break;
		case 30:
			TIM12->CCR2 = CicloCalculado;
			break;
		default:
			break;
	}
	
}	

/**
  * @}
  */


/******************* (C) COPYRIGHT 2015 EDESIGN *****FIN DE ARCHIVO****/
