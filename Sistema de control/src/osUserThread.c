/**
  ******************************************************************************
  * @file    canBUS.c
  * @author  EDESIGN Team
  * @version V1.0
  * @date    18-Agosto-2015
  * @brief   Configuracion de perifericos     
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
  **/
/* Include------------------------------------------------------------------*/
#include "osUserThread.h"

#define MAX_WAIT 3

/* Estructura para valores de tablero delantero */
TAB_TRA_STRUCT TAB_TRA;

/* tiempo de desacttivacion del mensaje de nivel */
uint32_t LEVEL_SEG = MAX_WAIT;

/* Estructura de control externa del RTC */
extern RTC_TimeTypeDef  RTC_TimeStructure;

/**
  * @brief  Funcion de Inicializacion de perifericos estandar y especiales || Control de Estados Iniciales
  * @param  Ninguno
  * @retval Ninguno
  */
		
void osUserThread_InitConf(void){	
	
	/* Proteccion contra memoria */
	 //SetMPU(1);
	
	/* Inicializacion del DISPLAY 16x2 */
	 osThreadLCD16x2_Init();
	
	/* Mantiene un mensaje en pantalla */	  
	 osThreadTimer_BUZZER();
	 osThreadTimer_LCD_Refresh();
	 osThreadTimer_Cronometro();
	 osThreadTimer_Estribo();

	
	/* Inicializacion de registros especiales */
	 osThreadCANBUSInit(os_CANBUS1,CANBUS1_PB8PB9);
	 osThreadUSARTInit(os_USART4,115200,USART4_PA0PA1);
	
	/* Inicializacion de pines de salida */
	 osThreadGPIOInit(BUZZER             ,os_OUT);
	 osThreadGPIOInit(LED_PUERTA_ABIERTA ,os_OUT);
	 osThreadGPIOInit(SUCCIONADOR        ,os_OUT);
	 osThreadGPIOInit(LUZ_GAVETAS        ,os_OUT);
	 osThreadGPIOInit(LUZ_MESA           ,os_OUT);
	 osThreadGPIOInit(INVERSOR           ,os_OUT);
	
	/* Estados iniciales */
	 GPIO_ResetBits(BUZZER);
	 GPIO_ResetBits(LED_PUERTA_ABIERTA);
	
	/* Bandera de limpieza del lcd */
	 TAB_TRA.Clear_LCD = ACTIVE ;
	
	/* Inicializacion de perifericos de salida*/
	osThreadGPIOInit(LED_BUTTON01                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON02                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON03                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON04                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON05                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON06                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON07                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON08                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON09                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON10                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON11                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON12                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON13                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON14                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON15                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON16                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON17                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON18                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON19                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON20                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON21                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON22                  ,os_OUT);
	osThreadGPIOInit(LED_BUTTON23                  ,os_OUT);
	
	/* Inicializacion del RTC */
	osThreadRTC_Enable_RTC();
	
	/* Limpieza de la estructura RTC almacenada */
	TAB_TRA.CRONOMETRO_HR_T  = 0x00;
	TAB_TRA.CRONOMETRO_MIN_T = 0x00;
	TAB_TRA.CRONOMETRO_SEG_T = 0x00;
	
	TAB_TRA.CRONOMETRO_SEG = NO_ACTIVE;
	
  osThreadLCD16x2_Puts(0, 0, "  -GRUPO DESPA- ");
  osThreadLCD16x2_Puts(0, 1, "                ");
}

/**
  * @brief  Thread de funciones periodicas
  * @param  Ninguno
  * @retval Ninguno
  */
void osUserThread_vPeriodicTask(void){
  
  /* SuperLOOP */	
  for( ; ; ) {
		
		/* Imagen Fija en pantalla */
		if (TAB_TRA.Clear_LCD == ACTIVE)
			osUserThread_ClearLCD();
		
		/* Actualizacion del LCD con la funcion deseada */
		if(TAB_TRA.IMG_SEG == ACTIVE )
			osUserThread_Refresh_LCD();
		
		/* Control del USART */
		if(TAB_TRA.USART_STATUS == ACTIVE)
		  osUserThread_USART_CONTROL();
		
		/* Valores del cronometro */
		if(TAB_TRA.CRONOMETRO_SEG == ACTIVE)
			osUserThread_Cronometro(ACTIVE);
	
  }
}

/**
  * @brief  Limpieza de pantalla, se coloca texto fijo
  * @param  Ninguno
  * @retval Ninguno
  */
void osUserThread_ClearLCD(){
	
	 /* Bandera de limpieza del lcd */
	  TAB_TRA.Clear_LCD = NO_ACTIVE ;
	
   /* Conversiones Especiales en Pantalla */
    osThreadLCD16x2_Puts(0, 0, "  -GRUPO DESPA- ");
    osThreadLCD16x2_Puts(0, 1, "                ");
	
	/* Señalizacion de LCD liberado */
   TAB_TRA.LCD_WAITING = NO_ACTIVE;
}

/**
  * @brief  Actualizacion de la funcion activa
  * @param  Ninguno
  * @retval Ninguno
  */
void osUserThread_Refresh_LCD(){

	  /* Reset del LCD */
	  if(TAB_TRA.IMG_CARRIER == ACTIVE){
  	  TIM_Cmd(TIM3, ENABLE);
	    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
  	  TIM3->CNT = 0;
			
	    /* Ahy una imagen para mostrar */
	    TAB_TRA.LCD_WAITING = ACTIVE;
	  }
		
	  /* Impresion del texto seleccionado */
  	switch(TAB_TRA.IMG){ 
		
		case LUZ_ALTA_SEL:                                               //(01)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "    Luz Alta    ");
        osThreadLCD16x2_Puts(0, 1, "                ");
				GPIO_ResetBits(LED_BUTTON01);
				GPIO_SetBits(LED_BUTTON05);
				GPIO_ResetBits(LED_BUTTON09);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON01);
				GPIO_ResetBits(LED_BUTTON05);
			}
			break;
		
		case LUZ_BAJA_SEL:                                               //(02)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "    Luz Baja    ");
        osThreadLCD16x2_Puts(0, 1, "                ");
				GPIO_SetBits(LED_BUTTON01);
				GPIO_ResetBits(LED_BUTTON05);
				GPIO_ResetBits(LED_BUTTON09);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON01);
				GPIO_ResetBits(LED_BUTTON05);
			}
			break;
		
		case PERIMETRAL_SEL:                                             //(03)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "  Perimetrales  ");
        osThreadLCD16x2_Puts(0, 1, "                ");
			}
			break;
		
		case TORRETA_SEL:                                                //(04)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "    Torreta     ");
        osThreadLCD16x2_Puts(0, 1, "                ");
			}
			break;
		
		case LUZ_MESA_SEL:                                               //(05)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "   Luz de mesa  ");
        osThreadLCD16x2_Puts(0, 1, "                ");
				GPIO_SetBits(LED_BUTTON13);
				GPIO_SetBits(LUZ_MESA);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON13);
				GPIO_ResetBits(LUZ_MESA);
			}
			break;
		
		case ESCENA_TRASERA_SEL:                                         //(06)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "     Escena     ");
        osThreadLCD16x2_Puts(0, 1, "     Trasera    ");
				GPIO_SetBits(LED_BUTTON12);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON12);
			}
			break;
		
		case ESTROBOS_SEL:                                               //(07)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "    Estrobos    ");
        osThreadLCD16x2_Puts(0, 1, "                ");
			}
			break;
		
		case FAROS_SEL:                                                  //(08)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "     Faros      ");
        osThreadLCD16x2_Puts(0, 1, "                ");
			}
			break;
		
		case VENTILADOR_ALTA_SEL:                                        //(09)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "   Ventilador   ");
        osThreadLCD16x2_Puts(0, 1, "      Alto      ");
				GPIO_SetBits(LED_BUTTON06);
				GPIO_ResetBits(LED_BUTTON07);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON06);
				GPIO_ResetBits(LED_BUTTON07);
			}
			break;
		
		case VENTILADOR_BAJA_SEL:                                        //(10)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "   Ventilador   ");
        osThreadLCD16x2_Puts(0, 1, "      Bajo      ");
				GPIO_ResetBits(LED_BUTTON06);
				GPIO_SetBits(LED_BUTTON07);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON06);
				GPIO_ResetBits(LED_BUTTON07);
			}
			break;
		
		case EXTRACTOR_ALTA_SEL:                                         //(11)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "    Extractor   ");
        osThreadLCD16x2_Puts(0, 1, "      Alto      ");
				GPIO_SetBits(LED_BUTTON02);
				GPIO_ResetBits(LED_BUTTON03);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON02);
				GPIO_ResetBits(LED_BUTTON03);
			}
			break;
		
		case EXTRACTOR_BAJA_SEL:                                         //(12)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "    Extractor   ");
        osThreadLCD16x2_Puts(0, 1, "      Bajo      ");
				GPIO_ResetBits(LED_BUTTON02);
				GPIO_SetBits(LED_BUTTON03);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON02);
				GPIO_ResetBits(LED_BUTTON03);
			}
			break;
		
		case LUZ_GAVETAS_SEL:                                            //(16)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "    Luz de      ");
        osThreadLCD16x2_Puts(0, 1, "    gavetas     ");
				GPIO_SetBits(LED_BUTTON17);
				GPIO_SetBits(LUZ_GAVETAS);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON17);
				GPIO_ResetBits(LUZ_GAVETAS);
			}
			break;
		
		case ESCENA_DERECHA_SEL:                                         //(17)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "     Escena     ");
        osThreadLCD16x2_Puts(0, 1, "     Derecha    ");
				GPIO_SetBits(LED_BUTTON11);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON11);
			}
			break;
		
		case ESCENA_IZQUIERDA_SEL:                                       //(18)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "     Escena     ");
        osThreadLCD16x2_Puts(0, 1, "    Izquierda   ");
				GPIO_SetBits(LED_BUTTON10);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON10);
			}
			break;
		
		case LUZ_PIEL_SENSIBLE_SEL:                                      //(19)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "     Luz de     ");
        osThreadLCD16x2_Puts(0, 1, "     trauma     ");
				GPIO_ResetBits(LED_BUTTON01);
				GPIO_ResetBits(LED_BUTTON05);
				GPIO_SetBits(LED_BUTTON09);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON09);
			}
			break;
		
		case SUCCIONADOR_SEL:                                            //(20)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "   Succionador  ");
        osThreadLCD16x2_Puts(0, 1, "                ");
				GPIO_SetBits(LED_BUTTON04);
				GPIO_SetBits(SUCCIONADOR);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON04);
				GPIO_ResetBits(SUCCIONADOR);
			}
			break;
		
		case INVERSOR_SEL:                                               //(21)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "    Inversor    ");
        osThreadLCD16x2_Puts(0, 1, "                ");
				GPIO_SetBits(LED_BUTTON08);
				GPIO_SetBits(INVERSOR);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON08);
				GPIO_ResetBits(INVERSOR);
			}
			break;
		
		case ESTABLE_SEL:                                                //(22)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "    Estable     ");
        osThreadLCD16x2_Puts(0, 1, "                ");
				GPIO_SetBits(LED_BUTTON21);
				GPIO_ResetBits(LED_BUTTON22);
				GPIO_ResetBits(LED_BUTTON23);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON21);
				GPIO_ResetBits(LED_BUTTON22);
				GPIO_ResetBits(LED_BUTTON23);
			}
			break;
		
		case CRITICO_SEL:                                                //(23)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "    Critico     ");
        osThreadLCD16x2_Puts(0, 1, "                ");
				GPIO_ResetBits(LED_BUTTON21);
				GPIO_SetBits(LED_BUTTON22);
				GPIO_ResetBits(LED_BUTTON23);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON21);
				GPIO_ResetBits(LED_BUTTON22);
				GPIO_ResetBits(LED_BUTTON23);
			}
			break;
		
		case GRAVE_SEL:                                                  //(24)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "     Grave      ");
        osThreadLCD16x2_Puts(0, 1, "                ");
				GPIO_ResetBits(LED_BUTTON21);
				GPIO_ResetBits(LED_BUTTON22);
				GPIO_SetBits(LED_BUTTON23);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON21);
				GPIO_ResetBits(LED_BUTTON22);
				GPIO_ResetBits(LED_BUTTON23);
			}
			break;
		
		case NIVEL_EMERGENCIA_SEL:                                       //(26)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "     Niveles    ");
        osThreadLCD16x2_Puts(0, 1, "    Emergencia  ");
			}
			break;
		
		case NIVEL_UNO_SEL:                                              //(27)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "     Nivel      ");
        osThreadLCD16x2_Puts(0, 1, "       I        ");
			}
			break;
		
		case NIVEL_DOS_SEL:                                              //(28)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "     Nivel      ");
        osThreadLCD16x2_Puts(0, 1, "      I I       ");
			}
			break;
		
		case NIVEL_TRES_SEL:                                             //(29)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "     Nivel      ");
        osThreadLCD16x2_Puts(0, 1, "      III       ");
			}
			break;
		
		case DIRECCIONADOR_SEL:                                          //(30)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "  Direccionador ");
        osThreadLCD16x2_Puts(0, 1, "                ");
			}
			break;
		
		case SIRENA_SEL:                                                 //(31)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "     Sirena     ");
        osThreadLCD16x2_Puts(0, 1, "                ");
			}
			break;
		
		case WAIL_SEL:                                                   //(32)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "    W A I L     ");
        osThreadLCD16x2_Puts(0, 1, "                ");
			}
			break;
		
		case HI_LO_SEL:                                                  //(33)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "   H I - L O    ");
        osThreadLCD16x2_Puts(0, 1, "                ");
			}
			break;
		
		case VOL_MENOS_SEL:                                              //(34)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "    Volumen     ");
        osThreadLCD16x2_Puts(0, 1, "     menos      ");
			}
			break;
		
		case HORN_SEL:                                                   //(35)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "    H O R N     ");
        osThreadLCD16x2_Puts(0, 1, "                ");
			}
			break;
		
		case YELP_SEL:                                                   //(36)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "    Y E L P     ");
        osThreadLCD16x2_Puts(0, 1, "                ");
			}
			break;
		
		case PSHR_SEL:                                                   //(37)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "    P H S R     ");
        osThreadLCD16x2_Puts(0, 1, "                ");
			}
			else{
        osThreadLCD16x2_Puts(0, 0, "  -GRUPO DESPA- ");
        osThreadLCD16x2_Puts(0, 1, "                ");
			}
			break;
		
		case VOL_MAS_SEL:                                                //(38)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "    Volumen     ");
        osThreadLCD16x2_Puts(0, 1, "      mas       ");
			}
			break;
		
		case CRONOMETRO_SEL:                                             //(39)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "   CRONOMETRO   ");
        osThreadLCD16x2_Puts(0, 1, "       ON       ");
				GPIO_SetBits(LED_BUTTON14);
				
				/* Se habilita el RTC */
				TAB_TRA.CRONOMETRO_SEG = ACTIVE;
				osUserThread_Cronometro(CRONOMETRO_SEL);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON14);
				
				/* Se deshabilita el RTC */
				osUserThread_Cronometro(CRONOMETRO_SEL);
				TAB_TRA.CRONOMETRO_SEG = NO_ACTIVE;
				
				/* Se envía la actualizacion de pantalla */
				osUserThread_ClearLCD();
				
			}
			break;
		
		case REINICIAR_SEL:                                              //(40)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        //osThreadLCD16x2_Puts(0, 0, "    Iniciar     ");
        //osThreadLCD16x2_Puts(0, 1, "                ");
				GPIO_SetBits(LED_BUTTON15);
	      TIM_Cmd(TIM4, ENABLE);
				
				/* Funcion de control RTC iniciar/reiniciar */
				osUserThread_Cronometro(REINICIAR_SEL);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON15);
			}
			break;
		
		case DETENER_SEL:                                                //(41)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        //osThreadLCD16x2_Puts(0, 0, " Detener/Reest  ");
        //osThreadLCD16x2_Puts(0, 1, "                ");
				GPIO_SetBits(LED_BUTTON16);
	      TIM_Cmd(TIM4, ENABLE);
				
				/* Funcion de control RTC iniciar/reiniciar */
				osUserThread_Cronometro(DETENER_SEL);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON16);
			}
			break;
		
		case ESTRIBO_ON_SEL:                                             //(42)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
      osThreadLCD16x2_Puts(0, 0, "    Estribo     ");
      osThreadLCD16x2_Puts(0, 1, "      ON        ");
			}
			break;
		
		case ESTRIBO_FUERA_SEL:                                          //(43)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
      osThreadLCD16x2_Puts(0, 0, "    Estribo     ");
      osThreadLCD16x2_Puts(0, 1, "     Fuera      ");
			}
			break;
		
		case ESTRIBO_DENTRO_SEL:                                         //(44)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
      osThreadLCD16x2_Puts(0, 0, "    Estribo     ");
      osThreadLCD16x2_Puts(0, 1, "     Dentro     ");
			}
			break;
		
		case REVERSA_SEL:                                                //(49)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "     Alarma     ");
        osThreadLCD16x2_Puts(0, 1, "   de Reversa   ");
			}
			break;
		
		case MANUAL_LEFT_FLASHER_SEL:                                    //(77)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "   Direccional  ");
        osThreadLCD16x2_Puts(0, 1, "    Izquierda   ");
			}
			break;
		
		case MANUAL_RIGHT_FLASHER_SEL:                                   //(78)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "   Direccional  ");
        osThreadLCD16x2_Puts(0, 1, "     Derecha    ");
			}
			break;
		
		case MANUAL_STOP_FLASHER_SEL:                                    //(79)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "     S T O P    ");
        osThreadLCD16x2_Puts(0, 1, "                ");
			}
			break;
		
		case FAROS_2_SEL:                                                //(81)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "     Faros      ");
        osThreadLCD16x2_Puts(0, 1, "   de Niebla    ");
			}
			break;
		
		case EFECTOS_DIR_SEL:                                            //(82)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "    Efectos     ");
        osThreadLCD16x2_Puts(0, 1, " Direccionador  ");
			}
			break;
		
		case SECUENCIA_SIRENA_SEL:                                       //(83)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "   Secuencia    ");
        osThreadLCD16x2_Puts(0, 1, "    Sirena      ");
			}
			break;
		
		case SOLENOIDE_SEL:                                              //(84)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "    CARGA DE    ");
        osThreadLCD16x2_Puts(0, 1, "    BATERIAS    ");
			}
			break;
		
		case INTENSITY_UP_SEL:                                           //(86)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "   INTENSIDAD   ");
        osThreadLCD16x2_Puts(0, 1, "      MAS       ");
			}
			break;
		
		case INTENSITY_DOWN_SEL:                                         //(87)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "   INTENSIDAD   ");
        osThreadLCD16x2_Puts(0, 1, "     MENOS      ");
			}
			break;
		
		case AUXILIAR_1_SEL:                                             //(89)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "     AUXILIAR   ");
        osThreadLCD16x2_Puts(0, 1, "        1       ");
				GPIO_SetBits(LED_BUTTON18);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON18);
			}
			break;
		
		case AUXILIAR_2_SEL:                                             //(90)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "     AUXILIAR   ");
        osThreadLCD16x2_Puts(0, 1, "        2       ");
				GPIO_SetBits(LED_BUTTON19);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON19);
			}
			break;
		
		case AUXILIAR_3_SEL:                                             //(91)
			if(TAB_TRA.IMG_CARRIER == ACTIVE){
        osThreadLCD16x2_Puts(0, 0, "     AUXILIAR   ");
        osThreadLCD16x2_Puts(0, 1, "        3       ");
				GPIO_SetBits(LED_BUTTON20);
			}
			if(TAB_TRA.IMG_CARRIER == NO_ACTIVE){
				GPIO_ResetBits(LED_BUTTON20);
			}
			break;
		
		default:
			break;
	}
	
		/* Seguro de imagen en pantalla */
	  TAB_TRA.IMG_SEG     = NO_ACTIVE ;
	  TAB_TRA.IMG         = NO_ACTIVE ;
}

/**
  * @brief  Switch de control del USART
  * @param  Ninguno
  * @retval Ninguno
  */
void osUserThread_USART_CONTROL(){
	
	uint32_t DATA = 0;
	
	switch(TAB_TRA.USART_DATA){
		case BUTTON1:
			  DATA = LUZ_BAJA_SEL;
			break;
		
		case BUTTON2:
			  DATA = EXTRACTOR_ALTA_SEL;
			break;
		
		case BUTTON3:
			  DATA = EXTRACTOR_BAJA_SEL;
			break;
		
		case BUTTON4:
			  DATA = SUCCIONADOR_SEL;
			break;
		
		case BUTTON5:
			  DATA = LUZ_ALTA_SEL;
			break;
		
		case BUTTON6:
			  DATA = VENTILADOR_ALTA_SEL;
			break;
		
		case BUTTON7:
			  DATA = VENTILADOR_BAJA_SEL;
			break;
		
		case BUTTON8:
			  DATA = INVERSOR_SEL;
			break;
		
		case BUTTON9:
			  DATA = LUZ_PIEL_SENSIBLE_SEL; 
			break;
		
		case BUTTON10:
			  DATA = ESCENA_IZQUIERDA_SEL;
			break;
		
		case BUTTON11:
			  DATA = ESCENA_DERECHA_SEL;
			break;
		
		case BUTTON12:
			  DATA = ESCENA_TRASERA_SEL;
			break;
		
		case BUTTON13:
			  DATA = LUZ_MESA_SEL;
			break;
		
		case BUTTON14:
			  DATA = CRONOMETRO_SEL;
			break;
		
		case BUTTON15:
			if(GPIO_ReadInputDataBit(LED_BUTTON14) == 1)
			  DATA = REINICIAR_SEL;
			break;
		
		case BUTTON16:
			if(GPIO_ReadInputDataBit(LED_BUTTON14) == 1)
			  DATA = DETENER_SEL;
			break;
		
		case BUTTON17:
			  DATA = LUZ_GAVETAS_SEL;
			break;
		
		case BUTTON18:
			  DATA = AUXILIAR_1_SEL;
			break;
		
		case BUTTON19:
			  DATA = AUXILIAR_2_SEL;
			break;
		
		case BUTTON20:
			  DATA = AUXILIAR_3_SEL;
			break;
		
		case BUTTON21:
			  DATA = ESTABLE_SEL;
			break;
		
		case BUTTON22:
			  DATA = CRITICO_SEL;
			break;
		
		case BUTTON23:
			  DATA = GRAVE_SEL;
			break;
		
		default:
			break;
	}
	
	if((DATA != 0) && (TAB_TRA.USART_CARRIER == ACTIVE)){
	  /* ITM PORT Message */
	  //printf("DATA %d  STATE %d \r\n",DATA,TAB_TRA.USART_CARRIER);
	
	  /* constructor de mensaje CANBUS */
	  osTreadCanBus_Sender(CAN1,TAB_CC,DATA,ACTIVE,0,0,0,0,0);
	}
	/* Se limpia la bandera del canbus */
	TAB_TRA.USART_STATUS = NO_ACTIVE;
}

/**
  * @brief  Maneja el texto del cronometro
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_Cronometro(uint32_t FUNCTION){	
	
	switch(FUNCTION){
		case CRONOMETRO_SEL:
		
			/* Disable the RTC Clock */
      RCC_RTCCLKCmd(ENABLE);
		
		  /* Wait for RTC APB registers synchronisation */
      RTC_WaitForSynchro();
		
	    /* Limpieza de la estructura RTC almacenada */
	    TAB_TRA.CRONOMETRO_HR_T  = 0x02;
	    TAB_TRA.CRONOMETRO_MIN_T = 0x00;
	    TAB_TRA.CRONOMETRO_SEG_T = 0x00;
		
      RTC_TimeStructure.RTC_H12     = RTC_H12_AM;
		  RTC_TimeStructure.RTC_Hours   = 0x00;
      RTC_TimeStructure.RTC_Minutes = 0x00;
      RTC_TimeStructure.RTC_Seconds = 0x00; 
  
		  /* Set time to RTC */
      RTC_SetTime(RTC_Format_BCD, &RTC_TimeStructure);  
		
		  /* Indicator for the RTC configuration */
      RTC_WriteBackupRegister(RTC_BKP_DR0, 0x32F2);	

      /* Estado actual del cronometro */
      TAB_TRA.CRONOMETRO_STATE = NO_ACTIVE;		
		
			/* Disable the RTC Clock */
      RCC_RTCCLKCmd(DISABLE);

			break;
		
		case REINICIAR_SEL:
			
			if(TAB_TRA.CRONOMETRO_STATE == ACTIVE){
			
			  /* Disable the RTC Clock */
        RCC_RTCCLKCmd(DISABLE);
				TAB_TRA.CRONOMETRO_STATE = NO_ACTIVE;
				
			}
			else if(TAB_TRA.CRONOMETRO_STATE == NO_ACTIVE){
			
			  /* Disable the RTC Clock */
        RCC_RTCCLKCmd(ENABLE);
		
		    /* Wait for RTC APB registers synchronisation */
        RTC_WaitForSynchro();
		
		    /* Estado del cronometro */
		    TAB_TRA.CRONOMETRO_STATE = ACTIVE;
			}
		
			break;
		
		case DETENER_SEL: 
			
			/* Disable the RTC Clock */
      RCC_RTCCLKCmd(ENABLE);
		
		  /* Wait for RTC APB registers synchronisation */
      RTC_WaitForSynchro();
		
	    /* Limpieza de la estructura RTC almacenada */
	    TAB_TRA.CRONOMETRO_HR_T  = 0x02;
	    TAB_TRA.CRONOMETRO_MIN_T = 0x00;
	    TAB_TRA.CRONOMETRO_SEG_T = 0x00;
		
		  RTC_TimeStructure.RTC_Hours   = 0x00;
      RTC_TimeStructure.RTC_Minutes = 0x00;
      RTC_TimeStructure.RTC_Seconds = 0x00; 
  
		  /* Set time to RTC */
      RTC_SetTime(RTC_Format_BCD, &RTC_TimeStructure);  
		
			//if(TAB_TRA.CRONOMETRO_STATE == ACTIVE){
			
			  /* Disable the RTC Clock */
        //RCC_RTCCLKCmd(ENABLE);
				
			//}
			//else{
			
			  /* Disable the RTC Clock */
        RCC_RTCCLKCmd(DISABLE);

        /* Estado actual del cronometro */
        TAB_TRA.CRONOMETRO_STATE = NO_ACTIVE;	
			//}
			
			break;
		
		default:
			break;
	}
	
	/* Se muestra en pantalla la hora */
	osThreadRTC_TimeShow();
}

/************************************************************************/
/*********************** CALLBACKS DE INTERRUPCIONES ********************/
/************************************************************************/

/**
  * @brief  Callback de interrupcion 0
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_INT0CALLBACK(void){
	
  printf("INT0\r\n");
	
}
/**
  * @brief  Callback de interrupcion 1
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_INT1CALLBACK(void){
	
  printf("INT1\r\n");
	
}

/**
  * @brief  Callback de interrupcion 2
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_INT2CALLBACK(void){
	
  printf("INT2\r\n");
	
}

/**
  * @brief  Callback de interrupcion 3
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_INT3CALLBACK(void){
	
  printf("INT3\r\n");
	
}

/**
  * @brief  Callback de interrupcion 4
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_INT4CALLBACK(void){
	
  printf("INT4\r\n");
	
}

/**
  * @brief  Callback de interrupcion 5
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_INT5CALLBACK(void){
	
  printf("INT5\r\n");
	
}

/**
  * @brief  Callback de interrupcion 6
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_INT6CALLBACK(void){
	
  printf("INT6\r\n");
	
}

/**
  * @brief  Callback de interrupcion 7
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_INT7CALLBACK(void){
	
  printf("INT7\r\n");
	
}

/**
  * @brief  Callback de interrupcion 8
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_INT8CALLBACK(void){
	
  printf("INT8\r\n");
	
}

/**
  * @brief  Callback de interrupcion 9
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_INT9CALLBACK(void){
	
  printf("INT9\r\n");
	
}

/**
  * @brief  Callback de interrupcion 10
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_INT10CALLBACK(void){
	
  printf("INT10\r\n");
	
}

/**
  * @brief  Callback de interrupcion 11
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_INT11CALLBACK(void){
	
  printf("INT11\r\n");
	
}

/**
  * @brief  Callback de interrupcion 12
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_INT12CALLBACK(void){
	
  printf("INT12\r\n");USART_puts(USART3,"SR*");
	
}

/**
  * @brief  Callback de interrupcion 13
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_INT13CALLBACK(void){
	
  printf("INT13\r\n");
	
}

/**
  * @brief  Callback de interrupcion 14
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_INT14CALLBACK(void){
	
  printf("INT14\r\n");
	
}

/**
  * @brief  Callback de interrupcion 15
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_INT15CALLBACK(void){
	
  printf("INT15\r\n");
	
}
/******************* (C) COPYRIGHT 2015 EDESIGN *****FIN DE ARCHIVO****/
