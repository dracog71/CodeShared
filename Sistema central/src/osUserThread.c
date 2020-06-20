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

/* Estructura de control del Centro de Carga */
TAB_CC_STRUCT TAB_CC1;

/* Tiempo de espera para fusibles */
uint32_t FUSE_TIME_OUT = 50000;

/* tiempo de espera de respuesta */
uint32_t COMM_TIME_OUT = 5;
uint32_t TIME_TIME_OUT = 50000;

/* Tiempo de respuesta a la entrada */
uint32_t TIME_IN_CNT = 5000;

/* Estructura de control de versiones */
VERSION_STRUCT VERSION;

/* Seguro de activacion del solenoide */
uint32_t SOLENOIDE_CNT = 0;

/**
  * @brief  Funcion de Inicializacion de perifericos estandar y especiales || Control de Estados Iniciales
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_InitConf(void){
	/* Proteccion contra memoria */
	 //SetMPU(1);
	
  /* Se inicializa la salida de voltajes */
	  osThreadGPIOInit(VOLTAJE_TABLEROS                ,os_OUT);	
			
	/* Se activan los Voltajes de tableros */
	 GPIO_SetBits(VOLTAJE_TABLEROS);
	
	/* Inicializacion de registros especiales */
	  osThreadCANBUSInit(os_CANBUS1,CANBUS1_PB8PB9);       //canBUS1 Init
		osThreadUSARTInit(os_USART4,9600,USART4_PA0PA1); //USART   Init

	/* Inicializacion de perifericos de salida*/
	  osThreadGPIOInit(LUZ_BAJA                        ,os_OUT);
	  osThreadGPIOInit(LUZ_ALTA                        ,os_OUT);
	  osThreadGPIOInit(ESTROBOS                        ,os_OUT);
	  osThreadGPIOInit(REVERSA                         ,os_OUT);
	  osThreadGPIOInit(PERIMETRAL                      ,os_OUT);
	  osThreadGPIOInit(TORRETA                         ,os_OUT);
	  osThreadGPIOInit(LUZ_ESCENA_PERIMETRAL           ,os_OUT);
	  osThreadGPIOInit(ESCENA_DERECHA                  ,os_OUT);
	  osThreadGPIOInit(ESCENA_TRASERA                  ,os_OUT);
	  osThreadGPIOInit(ESCENA_IZQUIERDA                ,os_OUT);

/* DIRECCIONADOR */
	  osThreadGPIOInit(DIR2                            ,os_OUT);
	  osThreadGPIOInit(DIR3                            ,os_OUT);
	  osThreadGPIOInit(DIR4                            ,os_OUT);
	  osThreadGPIOInit(DIR5                            ,os_OUT);
	  osThreadGPIOInit(DIR6                            ,os_OUT);
	  osThreadGPIOInit(DIR7                            ,os_OUT);
	  osThreadGPIOInit(DIR8                            ,os_OUT);
	  osThreadGPIOInit(DIR9                            ,os_OUT);
/*****************/

	  osThreadGPIOInit(LUZ_ESTACIONADO                 ,os_OUT);
	  osThreadGPIOInit(EXTRACTOR_ALTA                  ,os_OUT);
	  osThreadGPIOInit(EXTRACTOR_BAJA                  ,os_OUT);
	  osThreadGPIOInit(VENTILADOR_ALTA                 ,os_OUT);
	  osThreadGPIOInit(VENTILADOR_BAJA                 ,os_OUT);
	  osThreadGPIOInit(LUZ_PIEL_SENSIBLE               ,os_OUT);
	
	/* Inicializacion de Interrupcion */
	  osThreadGPIOInit(DIR_IZQ                         ,os_IN);
		osThreadGPIOInit(FRENO                           ,os_IN);
		osThreadGPIOInit(DIR_DER                         ,os_IN);
		osThreadGPIOInit(REVERSA_IN                      ,os_IN);
		osThreadGPIOInit(PUERTA_TRASERA                  ,os_IN);
		osThreadGPIOInit(PUERTA_LATERAL                  ,os_IN);
		
	/* Control sobre el solenoide */	
		osThreadGPIOInit(SOLENOIDE                       ,os_IN);
	
	  //osThreadGPIOInit(LED_DIR_IZQ                    ,os_OUT);
	  //osThreadGPIOInit(LED_FRENO                      ,os_OUT);
	  //osThreadGPIOInit(LED_DIR_DER                    ,os_OUT);
	  osThreadGPIOInit(LED_REVERSA_IN                 ,os_OUT);
	  osThreadGPIOInit(LED_PUERTA_TRASERA             ,os_OUT);
	  osThreadGPIOInit(LED_PUERTA_LATERAL             ,os_OUT);
 	  osThreadGPIOInit(TEST_MICRO                     ,os_OUT);
 	  osThreadGPIOInit(SIRENA_OUTPUT_TRIGGER          ,os_OUT);
		
	/* Control de KEY del bluetooth */
 	  osThreadGPIOInit(UART_MODE                      ,os_OUT);
		
	/* Modo de comandos AT */
	  BLU_CMD_MODE;
	  //BLU_DATA_MODE;
		
	/* Variable de control USART */
	 TAB_CC1.USART_INPUT = NO_ACTIVE;	
	
  /* Comunicacion con bluetooth */	
	 printf("Comunicacion a 9600\r\n");
	 osThreadCC_USART_SENDSTRING(UART4,"AT");
	 osThreadCC_USART_SENDSTRING(UART4,"AT");
	 osThreadCC_USART_SENDSTRING(UART4,"AT");	 
	 
	/* estabilizacion y primer mensaje */
	 mainDelay(1000000);
	 osTreadCanBus_Sender(CAN1,TAB_DELANTERO,BROADCAST,NO_ACTIVE,0,0,0,0,0);
	 osTreadCanBus_Sender(CAN1,TAB_TRASERO,BROADCAST,NO_ACTIVE,0,0,0,0,0);
	 osTreadCanBus_Sender(CAN1,TAB_SIRENA,BROADCAST,NO_ACTIVE,0,0,0,0,0);
	 mainDelay(1000000);
}

/**
  * @brief  Configura todas las funciones para Master Centro de Carga
  * @param  Ninguno
  * @retval Ninguno
  */
void osUserThread_MASTER_CONFIG(){
	int i;
	
	/* Timer de control de leds */
	 osThreadTimer_LED_OFF();

	/* Timer de funciones de Emergencia */
	 osThreadTimer_Emergency_Level();
	 
	/* Timer de Puerta Abierta */
	 osThreadTimer_PuertaAbierta();
	
	/* Control de valores iniciales */
	 TAB_CC1.SEG_PUERTA_LATERAL = NO_ACTIVE;
	 TAB_CC1.SEG_PUERTA_TRASERA = NO_ACTIVE;
	 TAB_CC1.SEG_REVERSA        = NO_ACTIVE;
	 TAB_CC1.SEG_DIR_IZQ        = NO_ACTIVE;
	 TAB_CC1.SEG_DIR_DER        = NO_ACTIVE;
	 TAB_CC1.SEG_DIR_STOP       = NO_ACTIVE;
	 TAB_CC1.SEG_INTERMITENTES  = NO_ACTIVE;
	 
	/* Estabilizacion de todo el sistema */
	 mainDelay(10000000);
	 
	/* Nivel inicial de la sirena */
	 TAB_CC1.MICRO_LEVEL = 80;
	 TAB_CC1.HORN_COUNTER = 0;
		
	/* Limpieza de la estructura de botones */
	 for(i=0;i<=199;i++)
		 TAB_CC1.SAVED_BUFFER[i] = NO_ACTIVE;
	
	/* Se resetean los valores del solenoide */
	 TAB_CC1.SOLENOIDE_SEG = ACTIVE;
	
	/* Se activa de manera inicial la alarma de reversa */
	 TAB_CC1.SAVED_BUFFER[REVERSA_SEL] = NO_ACTIVE;
	 TAB_CC1.STATUS = ACTIVE;
	 osThreadCC_REVERSA_SEL(NO_ACTIVE);
	 
	/* Valor inicial de efectos direccionador */ 
	 TAB_CC1.EFECTO_SELECTED = EFECTO_APAGADO;
	 
	/* NTmer control de efectos */
	 osThreadTimer_20_nanoseconds();
	 
	/* Control obre los efectos del direccionador */
	 TAB_CC1.EFECTO_SELECTED = EFECTO_APAGADO;
	 TAB_CC1.FLASHER_CARRIER = NO_ACTIVE;
	 
	/* PWM por software */
	 osThreadTimer_PWM_SOFT();
	 
	/* Se carga el valor inicial de la intensidad de leds */
	 TAB_CC1.LED_INTENSITY = 25;
	 
	/* Se carga valor inicial de efectos */
   TAB_CC1.DIRECCIONAL_EFFECT = DIRECCIONAL_EFFECT_1;	
	 
	/* Stop inicial a 0 */
	 TAB_CC1.STOP_CARRIER = NO_ACTIVE;
}

/**
  * @brief  Thread de funciones periodicas
  * @param  Ninguno
  * @retval Ninguno
  */
void osUserThread_vPeriodicTask(void){
	 
	for( ; ; ){
	
	  /* Control de niveles de emergencia */
	  if((TAB_CC1.EmergencyLevel != INITIAL_SEL) && (TAB_CC1.Emergency_Seg != NO_ACTIVE))
		  osThreadCC_Emergency();
		
		/* Lectura de la puerta*/
		  osUserThread_DOOR_STATUS();
		
		/* Control de relevadores */
		if(TAB_CC1.NEW_DATA == ACTIVE)
		  osUserThread_Relee_Control();
		
		/* Control de luces */
		if(TAB_CC1.EFECTO_SEG == ACTIVE)
	    osThreadCC_Directional_Sequence();
		
		/* Lectura del SOLENOIDE */
		 osUserThread_SOLENOIDE();
		
	}
}

/**
  * @brief  Control de puerta abierta
  * @param  Ninguno
  * @retval Ninguno
  */
void osUserThread_DOOR_STATUS(){
	
	/* Control de PUERTA LATERAL y ESCENA_DERECHA */
  if ((GPIO_ReadInputDataBit(PUERTA_LATERAL) == 0) && (TAB_CC1.SEG_PUERTA_LATERAL == NO_ACTIVE)){
		
		/* control del indicador */
		GPIO_SetBits(LED_PUERTA_LATERAL);
		
		if(TAB_CC1.SEG_PUERTA_TRASERA == NO_ACTIVE)
	  osThreadCC_LUZ_PUERTA_SEL(ACTIVE);
		
    osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(ACTIVE);
		GPIO_SetBits(ESCENA_DERECHA);
		GPIO_SetBits(LUZ_BAJA);
		TAB_CC1.SEG_PUERTA_LATERAL = ACTIVE;
		
		/*printf("OUT_SENSOR_SEL %d  IN_SENSOR_SEL %d\r\n",TAB_CC1.SAVED_BUFFER[OUT_SENSOR_SEL],TAB_CC1.SAVED_BUFFER[IN_SENSOR_SEL]);
		if((TAB_CC1.SAVED_BUFFER[ESTRIBO_ON_SEL] == ACTIVE) && (TAB_CC1.SAVED_BUFFER[OUT_SENSOR_SEL] == NO_ACTIVE))
	    osTreadCanBus_Sender(CAN1,TAB_DIRECCIONADOR,ESTRIBO_FUERA_SEL,ACTIVE,0,0,0,0,0);*/
		
	}
	
	
	if ((GPIO_ReadInputDataBit(PUERTA_LATERAL) == 1) && (TAB_CC1.SEG_PUERTA_LATERAL == ACTIVE)){
		
		/* control del indicador */
		GPIO_ResetBits(LED_PUERTA_LATERAL);
		
		TAB_CC1.SEG_PUERTA_LATERAL = NO_ACTIVE;
		
		if(TAB_CC1.SAVED_BUFFER[ESCENA_DERECHA_SEL] == NO_ACTIVE)
	    GPIO_ResetBits(ESCENA_DERECHA);
		osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(NO_ACTIVE);
		
		if((TAB_CC1.SAVED_BUFFER[LUZ_BAJA_SEL] == NO_ACTIVE) && (GPIO_ReadInputDataBit(PUERTA_TRASERA) == 1))
	    GPIO_ResetBits(LUZ_BAJA);
		
		if (GPIO_ReadInputDataBit(PUERTA_TRASERA) == 1)
		  osThreadCC_LUZ_PUERTA_SEL(NO_ACTIVE);
		
		/* Checa si el estribo se encuentra fuera de posiscion  */
		/*if(TAB_CC1.SAVED_BUFFER[IN_SENSOR_SEL] == NO_ACTIVE){
			osTreadCanBus_Sender(CAN1,TAB_DIRECCIONADOR,ESTRIBO_ON_SEL,ACTIVE,0,0,0,0,0);
			mainDelay(5000000);
			TAB_CC1.NEW_DATA = NO_ACTIVE;
	    osTreadCanBus_Sender(CAN1,TAB_DIRECCIONADOR,ESTRIBO_DENTRO_SEL,ACTIVE,0,0,0,0,0);
		}*/
	}

	/* Control de PUERTA TRASERA y ESCENA_TRASERA */
  if ((GPIO_ReadInputDataBit(PUERTA_TRASERA) == 0) && (TAB_CC1.SEG_PUERTA_TRASERA == NO_ACTIVE)){
		
		/* control del indicador */
		GPIO_SetBits(LED_PUERTA_TRASERA);
		
		if(TAB_CC1.SEG_PUERTA_LATERAL == NO_ACTIVE)
	    osThreadCC_LUZ_PUERTA_SEL(ACTIVE);
		
		osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(ACTIVE);
		GPIO_SetBits(ESCENA_TRASERA);
		GPIO_SetBits(LUZ_BAJA);
		TAB_CC1.SEG_PUERTA_TRASERA = ACTIVE;
		
	}
	
	if ((GPIO_ReadInputDataBit(PUERTA_TRASERA) == 1) && (TAB_CC1.SEG_PUERTA_TRASERA == ACTIVE)){
		
		/* control del indicador */
		GPIO_ResetBits(LED_PUERTA_TRASERA);
		
		TAB_CC1.SEG_PUERTA_TRASERA = NO_ACTIVE;
		
		if(TAB_CC1.SAVED_BUFFER[ESCENA_TRASERA_SEL] == NO_ACTIVE)
	    GPIO_ResetBits(ESCENA_TRASERA);
		
		osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(NO_ACTIVE);
		
		if((TAB_CC1.SAVED_BUFFER[LUZ_BAJA_SEL] == NO_ACTIVE) && (GPIO_ReadInputDataBit(PUERTA_LATERAL) == 1))
	    GPIO_ResetBits(LUZ_BAJA);
		
		if (GPIO_ReadInputDataBit(PUERTA_LATERAL) == 1)
		  osThreadCC_LUZ_PUERTA_SEL(NO_ACTIVE);
		
	}
	
	/* Control de la reversa */
  if ((GPIO_ReadInputDataBit(REVERSA_IN) == 0) && (TAB_CC1.SEG_REVERSA == NO_ACTIVE)){
		
		/* control del indicador */
		GPIO_SetBits(LED_REVERSA_IN);
		
		TAB_CC1.SEG_REVERSA = ACTIVE;
		if(TAB_CC1.SAVED_BUFFER[REVERSA_SEL] == ACTIVE)
			GPIO_SetBits(REVERSA);
	}
	
  if ((GPIO_ReadInputDataBit(REVERSA_IN) == 1) && (TAB_CC1.SEG_REVERSA == ACTIVE)){
		
		/* control del indicador */
		GPIO_ResetBits(LED_REVERSA_IN);
		
		TAB_CC1.SEG_REVERSA = NO_ACTIVE;
		GPIO_ResetBits(REVERSA);
	}
	
	/* Control de intermitentes */
	if ((GPIO_ReadInputDataBit(DIR_IZQ) == 0) && (GPIO_ReadInputDataBit(DIR_DER) == 0) && (TAB_CC1.SEG_INTERMITENTES == NO_ACTIVE) && (TAB_CC1.SEG_DIR_STOP == NO_ACTIVE)){
		
	  /* Control de direccionales */
		GPIO_SetBits(LED_DIR_IZQ);
		GPIO_SetBits(LED_DIR_DER);
	
		/* Thread del flasher */
		osThreadCC_INTERMITENTES_FLASHER_SEL();
	}
	
	/* Control de la direccional IZQ */
  if ((GPIO_ReadInputDataBit(DIR_IZQ) == 0) && (TAB_CC1.SEG_DIR_IZQ == NO_ACTIVE) && (TAB_CC1.SEG_INTERMITENTES == NO_ACTIVE) && (TAB_CC1.SEG_DIR_STOP == NO_ACTIVE)){
		
		/* Se aumenta la variable */
		if(TAB_CC1.CNT_DIR_IZQ <= TIME_IN_CNT){
		  TAB_CC1.CNT_DIR_IZQ++; 
	  }
		else{
		  /* control del indicador */
		  GPIO_SetBits(LED_DIR_IZQ);
		  TAB_CC1.SEG_DIR_IZQ = ACTIVE;
			
		  /* Thread del flasher */
		  osThreadCC_LEFT_FLASHER();
		}
	}
	
  if ((GPIO_ReadInputDataBit(DIR_IZQ) == 1) && (TAB_CC1.SEG_DIR_IZQ == ACTIVE) && (TAB_CC1.SEG_INTERMITENTES == NO_ACTIVE) && (TAB_CC1.SEG_DIR_STOP == NO_ACTIVE)){
		
		/* Se resetea la variable  */
		TAB_CC1.CNT_DIR_IZQ = 0;
		
		/* control del indicador */
		GPIO_ResetBits(LED_DIR_IZQ);
		TAB_CC1.SEG_DIR_IZQ = NO_ACTIVE;

	}
	
	/* Control de la direccional DER */
  if ((GPIO_ReadInputDataBit(DIR_DER) == 0) && (TAB_CC1.SEG_DIR_DER == NO_ACTIVE) && (TAB_CC1.SEG_INTERMITENTES == NO_ACTIVE) && (TAB_CC1.SEG_DIR_STOP == NO_ACTIVE)){
				
		/* Se aumenta la variable */
		if(TAB_CC1.CNT_DIR_DER <= TIME_IN_CNT){
		  TAB_CC1.CNT_DIR_DER++; 
	  }
		else{
		  /* control del indicador */
		  GPIO_SetBits(LED_DIR_DER);
		  TAB_CC1.SEG_DIR_DER = ACTIVE;
		
		  /* Thread del flasher */
		  osThreadCC_RIGHT_FLASHER();
		}
	}
	
  if ((GPIO_ReadInputDataBit(DIR_DER) == 1) && (TAB_CC1.SEG_DIR_DER == ACTIVE) && (TAB_CC1.SEG_INTERMITENTES == NO_ACTIVE) && (TAB_CC1.SEG_DIR_STOP == NO_ACTIVE)){
				
		/* Se resetea la variable  */
		TAB_CC1.CNT_DIR_DER = 0;
		
		/* control del indicador */
		GPIO_ResetBits(LED_DIR_DER);
		TAB_CC1.SEG_DIR_DER = NO_ACTIVE;

	}
	
	/* Control de la direccional STOP */
  if (GPIO_ReadInputDataBit(FRENO) == 0){
		
		/* Variable de control desactivacion del freno */
		TAB_CC1.SEG_STOP_OFF = 0;
		
		if(TAB_CC1.SEG_DIR_STOP == NO_ACTIVE){
			
		  /* control del indicador */
		  GPIO_SetBits(LED_FRENO);
		  TAB_CC1.SEG_DIR_STOP = ACTIVE;
		
		  /* Thread del flasher */
		  osThreadCC_STOP_FLASHER(ACTIVE);
		}
	}
	
  else if (GPIO_ReadInputDataBit(FRENO) == 1){
		
		if (TAB_CC1.SEG_STOP_OFF <= MAX_SEG_STOP){
			
		  /* Aumento de variable freno */
		  TAB_CC1.SEG_STOP_OFF++;
			
		}
		 else if(TAB_CC1.SEG_DIR_STOP == ACTIVE){
		
		  /* Cambio de variable  */
		  TAB_CC1.SEG_DIR_STOP = NO_ACTIVE;
		
		  /* control del indicador */
		  GPIO_ResetBits(LED_FRENO);

		  /* Thread del flasher */
		  osThreadCC_STOP_FLASHER(NO_ACTIVE);
		 }
	}
}

/**
  * @brief  Control de Luz Escena como Perimetral
  * @param  Ninguno
  * @retval Ninguno
  */


void osUserThread_Relee_Control(){

	switch(TAB_CC1.CARRIER){
		case LUZ_ALTA_SEL:                        //(1)
			osThreadCC_LUZ_ALTA_SEL(ACTIVE);
			break;

		case LUZ_BAJA_SEL:                        //(2)
			osThreadCC_LUZ_BAJA_SEL(ACTIVE);
			break;
		
		case PERIMETRAL_SEL:                      //(3)
			osThreadCC_PERIMETRAL_SEL(ACTIVE);
			break;
		
		case TORRETA_SEL:                         //(4)
			osThreadCC_TORRETA_SEL(ACTIVE);
			break;
		
		case LUZ_MESA_SEL:                        //(5)
			osThreadCC_LUZ_MESA_SEL(ACTIVE);
			break;
		
		case ESCENA_TRASERA_SEL:                  //(6)
			osThreadCC_ESCENA_TRASERA_SEL(ACTIVE);
			break;
		
		case ESTROBOS_SEL:                        //(7)
			osThreadCC_ESTROBOS_SEL(ACTIVE);
			break;
		
		case FAROS_SEL:                           //(8)
			osThreadCC_FAROS_SEL(ACTIVE);
			break;
		
		case VENTILADOR_ALTA_SEL:                 //(9)
			osThreadCC_VENTILADOR_ALTA_SEL(ACTIVE);
			break;
		
		case VENTILADOR_BAJA_SEL:                 //(10)
			osThreadCC_VENTILADOR_BAJA_SEL(ACTIVE);
			break;
		
		case EXTRACTOR_ALTA_SEL:                  //(11)
			osThreadCC_EXTRACTOR_ALTA_SEL(ACTIVE);
			break;
		
		case EXTRACTOR_BAJA_SEL:                  //(12)
			osThreadCC_EXTRACTOR_BAJA_SEL(ACTIVE);
			break;
		
		case VOLTAJE_TABLEROS_SEL:                //(13)
			osThreadCC_VOLTAJE_TABLEROS_SEL(ACTIVE);
			break;
		
		case LUZ_ESCENA_PERIMETRAL_SEL:           //(14)
			osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(ACTIVE);
			break;
		
		case LUZ_ESTACIONADO_SEL:                 //(15)
			osThreadCC_LUZ_ESTACIONADO_SEL(ACTIVE);
			break;
		
		case LUZ_GAVETAS_SEL:                     //(16)
			osThreadCC_LUZ_GAVETAS_SEL(ACTIVE);
			break;
		
		case ESCENA_DERECHA_SEL:                  //(17)
			osThreadCC_ESCENA_DERECHA_SEL(ACTIVE);
			break;
		
		case ESCENA_IZQUIERDA_SEL:                //(18)
			osThreadCC_ESCENA_IZQUIERDA_SEL(ACTIVE);
			break;
		
		case LUZ_PIEL_SENSIBLE_SEL:               //(19)
			osThreadCC_LUZ_PIEL_SENSIBLE_SEL(ACTIVE);
			break;
		
		case SUCCIONADOR_SEL:                     //(20)
			osThreadCC_SUCCIONADOR_SEL(ACTIVE);
			break;
		
		case INVERSOR_SEL:                        //(21)
			osThreadCC_INVERSOR_SEL(ACTIVE);
			break;
		
		case ESTABLE_SEL:                         //(22)
			osThreadCC_ESTABLE_SEL(ACTIVE);
			break;
		
		case CRITICO_SEL:                         //(23)
			osThreadCC_CRITICO_SEL(ACTIVE);
			break;
		
		case GRAVE_SEL:                           //(24)
			osThreadCC_GRAVE_SEL(ACTIVE);
			break;
		
		case LUZ_PUERTA_SEL:                      //(25)
			osThreadCC_LUZ_PUERTA_SEL(ACTIVE);
			break;
		
		case NIVEL_EMERGENCIA_SEL:                //(26)
			osThreadCC_NIVEL_EMERGENCIA_SEL(TAB_CC1.STATUS);
			break;
		
		case NIVEL_UNO_SEL:                       //(27)
			osThreadCC_NIVEL_UNO_SEL(ACTIVE);
			break;
		
		case NIVEL_DOS_SEL:                       //(28)
			osThreadCC_NIVEL_DOS_SEL(ACTIVE);
			break;
		
		case NIVEL_TRES_SEL:                      //(29)
			osThreadCC_NIVEL_TRES_SEL(ACTIVE);
			break;
		
		case DIRECCIONADOR_SEL:                   //(30)
			osThreadCC_DIRECCIONADOR_SEL(ACTIVE);
			break;
		
		case SIRENA_SEL:                          //(31)
			osThreadCC_SIRENA_SEL(ACTIVE);
			break;
		
		case WAIL_SEL:                            //(32)
			osThreadCC_WAIL_SEL(ACTIVE);
			break;
		
		case HI_LO_SEL:                           //(33)
			//osThreadCC_HI_LO_SEL(ACTIVE);  // <-- Se deshabilito Hi LO por consumo de corriente
			break;
		
		case VOL_MENOS_SEL:                       //(34)
			osThreadCC_VOL_MENOS_SEL(ACTIVE);
			break;
		
		case HORN_SEL:                            //(35)
			osThreadCC_HORN_SEL(ACTIVE);
			break;
		
		case YELP_SEL:                            //(36)
			osThreadCC_YELP_SEL(ACTIVE);
			break;
		
		case PSHR_SEL:                            //(37)
			osThreadCC_PSHR_SEL(ACTIVE);
			break;
		
		case VOL_MAS_SEL:                         //(38)
			osThreadCC_VOL_MAS_SEL(ACTIVE);
			break;
		
		case CRONOMETRO_SEL:                      //(39)
			osThreadCC_CRONOMETRO_SEL(ACTIVE);
			break;
		
		case REINICIAR_SEL:                       //(40)
			osThreadCC_REINICIAR_SEL(ACTIVE);
			break;
		
		case DETENER_SEL:                         //(41)
			osThreadCC_DETENER_SEL(ACTIVE);
			break;
		
		case ESTRIBO_ON_SEL:                      //(42)
			osThreadCC_ESTRIBO_ON_SEL(ACTIVE);
			break;
		
		case ESTRIBO_FUERA_SEL:                   //(43)
			osThreadCC_ESTRIBO_FUERA_SEL(ACTIVE);
			break;
		
		case ESTRIBO_DENTRO_SEL:                  //(44)
			osThreadCC_ESTRIBO_DENTRO_SEL(ACTIVE);
			break;
		
		case REVERSA_SEL:                         //(49)
			osThreadCC_REVERSA_SEL(ACTIVE);
			break;
		
		case OUT_SENSOR_SEL:                      //(51)
			osThreadCC_OUT_SENSOR();
			break;
		
		case IN_SENSOR_SEL:                       //(52)
			osThreadCC_IN_SENSOR();
			break;
		
		case LEFT_FLASHER_SEL:                    //(53)
			osThreadCC_LEFT_FLASHER();
			break;
		
		case RIGHT_FLASHER_SEL:                   //(54)
			osThreadCC_RIGHT_FLASHER();
			break;
		
		case STOP_FLASHER_SEL:                    //(55)
			osThreadCC_STOP_FLASHER(TAB_CC1.STATUS);
			break;
		
		case MICRO_SEL:                           //(67)
			osThreadCC_MICRO_SEL(TAB_CC1.STATUS);
			break;
		
		case CLAXON_SEL:                          //(68)
			osThreadCC_CLAXON_SEL(TAB_CC1.STATUS);
			break;
		
		case MANUAL_LEFT_FLASHER_SEL:             //(77)
			osThreadCC_MANUAL_LEFT_FLASHER(TAB_CC1.STATUS);
			break;
		
		case MANUAL_RIGHT_FLASHER_SEL:            //(78)
			osThreadCC_MANUAL_RIGHT_FLASHER(TAB_CC1.STATUS);
			break;
		
		case MANUAL_STOP_FLASHER_SEL:             //(79)
			osThreadCC_MANUAL_STOP_FLASHER(TAB_CC1.STATUS);
			break;
		
		case FAROS_2_SEL:                         //(81)
			osThreadCC_FAROS_2_SEL(ACTIVE);
			break;
		
		case EFECTOS_DIR_SEL:                     //(82)
			osThreadCC_EFECTOS_DIR_SEL(ACTIVE);
			break;
		
		case SECUENCIA_SIRENA_SEL:                //(83)
			osThreadCC_SECUENCIA_SIRENA_SEL(ACTIVE);
			break;
		
		case EMERGENCIA_DEL_REDUCIDO_SEL:         //(83)
			osThreadCC_EMERGENCIA_DEL_REDUCIDO_SEL(ACTIVE);
			break;
		
		case AUXILIAR_1_SEL:                      //(83)
			osThreadCC_AUXILIAR_1_SEL(ACTIVE);
			break;
		
		case AUXILIAR_2_SEL:                      //(83)
			osThreadCC_AUXILIAR_2_SEL(ACTIVE);
			break;
		
		case AUXILIAR_3_SEL:                      //(83)
			osThreadCC_AUXILIAR_3_SEL(ACTIVE);
			break;
		
		default:
			break;
	}
	
		
	/* Variable de entrada recursiva */
	TAB_CC1.NEW_DATA = NO_ACTIVE;
	TAB_CC1.CAN_SENDER = NO_ACTIVE;
}

/**
  * @brief  Reporte del estado del solenoide
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_SOLENOIDE(){
  uint32_t SOLENOIDE_MAX_CNT = 50000;
	
	/* Control de activacion del SOLENOIDE */
	if(GPIO_ReadInputDataBit(SOLENOIDE) == 0) {
		/* Seguro de activacion del solenoide */
		if(SOLENOIDE_CNT <= SOLENOIDE_MAX_CNT){
	    SOLENOIDE_CNT++;
		}
		
	  if((TAB_CC1.SOLENOIDE_SEG == NO_ACTIVE) && (SOLENOIDE_CNT >= SOLENOIDE_MAX_CNT)){
		  /* Variable de entrada recursiva */
		   TAB_CC1.SOLENOIDE_SEG = ACTIVE;
	  
		  /* Constructor CANbus */
	     osTreadCanBus_Sender(CAN1,TAB_TRASERO,SOLENOIDE_SEL,ACTIVE,0,0,0,0,0);
	     osTreadCanBus_Sender(CAN1,TAB_DELANTERO,CARGA_BATERIAS_SEL,ACTIVE,0,0,0,0,0);
		}
	}
	
	/* Control de desactivacion del SOLENOIDE */
	if(GPIO_ReadInputDataBit(SOLENOIDE) == 1) {
		/* Seguro de activacion del solenoide */
		SOLENOIDE_CNT = 0;
		
		if(TAB_CC1.SOLENOIDE_SEG == ACTIVE){
		  /* Variable de entrada recursiva */
		  TAB_CC1.SOLENOIDE_SEG = NO_ACTIVE;
		}
	}
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
	printf("PUERTA_TRASERA\r\n");

}

/**
  * @brief  Callback de interrupcion 4
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_INT4CALLBACK(void){
	
  printf("INT4\r\n");
	printf("PUERTA_LATERAL\r\n");
	
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
	
  printf("INT12\r\n");
	
}

/**
  * @brief  Callback de interrupcion 13
  * @param  Ninguno
  * @retval Ninguno
  */	
void osUserThread_INT13CALLBACK(void){
	
  printf("ESTRIBO_FUERA\r\n");
	
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
