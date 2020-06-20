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
#include "osThreadTESTER.h"
 
/* Estructura de control del Centro de Carga */
extern TAB_CC_STRUCT TAB_CC1;

/* Definicion de limite del buffer */
#define LIMIT_COUNTER 2000

/* Buffers de Testeo */
uint32_t TESTER_COUNTER = 0;
uint32_t TESTER_SAVED = 0;
uint32_t TESTER_BUFFER[LIMIT_COUNTER];
uint32_t DATA_BUFFER[LIMIT_COUNTER];

/**
  * @brief  Configura la funcion de tester
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadTESTER_CONFIG(){
	/* ITM PORT Message */
	printf("Configuracion de TESTER ACTIVE\r\n");
}

/**
  * @brief  Thread de funciones periodicas
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadTESTER_vPeriodicTask(void){
	
	uint32_t i;
	uint32_t PASS = ACTIVE;
	
	/* Reset de todos los valores */
 	osThreadTESTER_OFF_ALL();	
	
	/* Testeo de entradas */
	GPIO_SetBits(EXTRACTOR_ALTA);
	osThreadTESTER_CHECK_DATA(EXTRACTOR_ALTA_SEL);
	
	GPIO_SetBits(VENTILADOR_ALTA);
	osThreadTESTER_CHECK_DATA(VENTILADOR_ALTA_SEL);
	
	GPIO_SetBits(REVERSA);
	osThreadTESTER_CHECK_DATA(REVERSA_SEL);
	
	GPIO_SetBits(ESTROBOS);
	osThreadTESTER_CHECK_DATA(ESTROBOS_SEL);
	
	GPIO_SetBits(ESCENA_TRASERA);
	osThreadTESTER_CHECK_DATA(ESCENA_TRASERA_SEL);
	
	GPIO_SetBits(LUZ_MESA);
	osThreadTESTER_CHECK_DATA(LUZ_MESA_SEL);
	
	GPIO_SetBits(TORRETA);
	osThreadTESTER_CHECK_DATA(TORRETA_SEL);
	
	GPIO_SetBits(PERIMETRALES);
	osThreadTESTER_CHECK_DATA(PERIMETRAL_SEL);
	
	GPIO_SetBits(LUZ_BAJA);
	osThreadTESTER_CHECK_DATA(LUZ_BAJA_SEL);
	
	GPIO_SetBits(LUZ_ALTA);
	osThreadTESTER_CHECK_DATA(LUZ_ALTA_SEL);
	
	GPIO_SetBits(SUCCIONADOR);
	osThreadTESTER_CHECK_DATA(SUCCIONADOR_SEL);
	
	GPIO_SetBits(LUZ_PIEL_SENSIBLE);
	osThreadTESTER_CHECK_DATA(LUZ_PIEL_SENSIBLE_SEL);
	
	GPIO_SetBits(ESCENA_IZQUIERDA);
	osThreadTESTER_CHECK_DATA(ESCENA_IZQUIERDA_SEL);
	
	GPIO_SetBits(ESCENA_DERECHA);
	osThreadTESTER_CHECK_DATA(ESCENA_DERECHA_SEL);
	
	GPIO_SetBits(LUZ_GAVETAS);
	osThreadTESTER_CHECK_DATA(LUZ_GAVETAS_SEL);
	
	GPIO_SetBits(LUZ_ESTACIONADO);
	osThreadTESTER_CHECK_DATA(LUZ_ESTACIONADO_SEL);
	
	GPIO_SetBits(LUZ_ESCENA_PERIMETRAL);
	osThreadTESTER_CHECK_DATA(LUZ_ESCENA_PERIMETRAL_SEL);

	GPIO_SetBits(VOLTAJE_TABLEROS);
	osThreadTESTER_CHECK_DATA(VOLTAJE_TABLEROS_SEL);
	
	/* De salidas sin reelevador */
	osTreadCanBus_Sender(CAN1,TAB_TEST,SOLENOIDE_SEL,ACTIVE,0,0,0,0,0);
	osThreadTESTER_CHECK_DATA(SOLENOIDE_SEL);
	
	osTreadCanBus_Sender(CAN1,TAB_TEST,RADIO_SEL,ACTIVE,0,0,0,0,0);
	osThreadTESTER_CHECK_DATA(RADIO_SEL);
	
	osTreadCanBus_Sender(CAN1,TAB_TEST,TOMA_12_SEL,ACTIVE,0,0,0,0,0);
	osThreadTESTER_CHECK_DATA(TOMA_12_SEL);
	
	osTreadCanBus_Sender(CAN1,TAB_TEST,AIRE_ACONDICIONADO_SEL,ACTIVE,0,0,0,0,0);
	osThreadTESTER_CHECK_DATA(AIRE_ACONDICIONADO_SEL);
	
	osTreadCanBus_Sender(CAN1,TAB_TEST,VOLTAJE_TAB_DELANTERO_SEL,ACTIVE,0,0,0,0,0);
	osThreadTESTER_CHECK_DATA(VOLTAJE_TAB_DELANTERO_SEL);
	
	/* De entradas al DIRECCIONADOR */
	if(TAB_CC1.DIRECCIONADOR_ACT == ACTIVE){
		
		osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,ESTRIBO_ON_SEL,ACTIVE,0,0,0,0,0);
		mainDelay(5000000);
	
		osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,LED_2_SEL,ACTIVE,0,0,0,0,0);
	  osThreadTESTER_CHECK_DATA(LED_2_SEL);
	
		osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,LED_3_SEL,ACTIVE,0,0,0,0,0);
	  osThreadTESTER_CHECK_DATA(LED_3_SEL);
	
		osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,LED_4_SEL,ACTIVE,0,0,0,0,0);
	  osThreadTESTER_CHECK_DATA(LED_4_SEL);
	
		osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,LED_5_SEL,ACTIVE,0,0,0,0,0);
	  osThreadTESTER_CHECK_DATA(LED_5_SEL);
	
		osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,LED_6_SEL,ACTIVE,0,0,0,0,0);
	  osThreadTESTER_CHECK_DATA(LED_6_SEL);
	
		osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,LED_7_SEL,ACTIVE,0,0,0,0,0);
	  osThreadTESTER_CHECK_DATA(LED_7_SEL);
	
		osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,LED_8_SEL,ACTIVE,0,0,0,0,0);
	  osThreadTESTER_CHECK_DATA(LED_8_SEL);
	
		osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,LED_9_SEL,ACTIVE,0,0,0,0,0);
	  osThreadTESTER_CHECK_DATA(LED_9_SEL);
	
		osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,ESTRIBO_FUERA_SEL,ACTIVE,0,0,0,0,0);
	  osThreadTESTER_CHECK_DATA(ESTRIBO_FUERA_SEL);
	
		osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,ESTRIBO_DENTRO_SEL,ACTIVE,0,0,0,0,0);
	  osThreadTESTER_CHECK_DATA(ESTRIBO_DENTRO_SEL);
	
		osTreadCanBus_Sender(CAN1,TAB_TEST,STOP_FLASHER_SEL,ACTIVE,0,0,0,0,0);
	  osThreadTESTER_CHECK_DATA(STOP_FLASHER_SEL);
	
		osTreadCanBus_Sender(CAN1,TAB_TEST,RIGHT_FLASHER_SEL,ACTIVE,0,0,0,0,0);
	  osThreadTESTER_CHECK_DATA(RIGHT_FLASHER_SEL);
	
		osTreadCanBus_Sender(CAN1,TAB_TEST,LEFT_FLASHER_SEL,ACTIVE,0,0,0,0,0);
	  osThreadTESTER_CHECK_DATA(LEFT_FLASHER_SEL);
	
		osTreadCanBus_Sender(CAN1,TAB_TEST,IN_SENSOR_SEL,ACTIVE,0,0,0,0,0);
	  osThreadTESTER_CHECK_DATA(IN_SENSOR_SEL);
	
		osTreadCanBus_Sender(CAN1,TAB_TEST,OUT_SENSOR_SEL,ACTIVE,0,0,0,0,0);
	  osThreadTESTER_CHECK_DATA(OUT_SENSOR_SEL);
		
	}
	
	/* De entradas al CC */  
	osTreadCanBus_Sender(CAN1,TAB_TEST,REVERSA_SEL,ACTIVE,0,0,0,0,0);
	osThreadTESTER_CHECK_INPUT(REVERSA_SEL);
	
	osTreadCanBus_Sender(CAN1,TAB_TEST,PUERTA_TRASERA_SEL,ACTIVE,0,0,0,0,0);
	osThreadTESTER_CHECK_INPUT(PUERTA_TRASERA_SEL);
	
	osTreadCanBus_Sender(CAN1,TAB_TEST,PUERTA_LATERAL_SEL,ACTIVE,0,0,0,0,0);
	osThreadTESTER_CHECK_INPUT(PUERTA_LATERAL_SEL);
	
	
	
	/* Se apaga el direccionador */	
	osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,ESTRIBO_ON_SEL,NO_ACTIVE,0,0,0,0,0);
	
	/* Testea si todas las entradas son correctas */
	for(i=0;i<=TESTER_COUNTER - 1;i++){
			if(TESTER_BUFFER[i] != ACTIVE)
				PASS = NO_ACTIVE;
		}	
	
	if(PASS == ACTIVE){
				osTreadCanBus_Sender(CAN1,TAB_TEST,0,0,ACTIVE,ACTIVE,0,0,0);
		for( ; ; ){
		  //El programa se atora la conexion es correcta
		}
	}
  else{
		for( ; ; ){
		/**
      * @brief    Thread de finalizacion
      * @param    Ninguno
      * @verbatim Thread ciclico de finalizacion, 
		  *           espera a que el tester sea retirado de la linea
		  *           y que el centro de carga sea reiniciado
      */
		for(i=0;i<=TESTER_COUNTER - 1;i++){
			if(TESTER_BUFFER[i] != ACTIVE){
				mainDelay(50000000);
				osTreadCanBus_Sender(CAN1,TAB_TEST,0,0,DATA_BUFFER[i],TESTER_BUFFER[i],0,0,0);
			}
		}
	}
  }	
		

	
}

/**
  * @brief  Testeo de entrada correcta
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadTESTER_CHECK_DATA(uint32_t DATA){
	
	uint32_t TIMEOUT_LIMIT = 50000;
	uint32_t TIMEOUT_COUNTER = 0;
	
	/* Set Ddelay for system waiting */
	mainDelay(5000000);
	
	/* Se envia señal de activacion al tester	*/
	osTreadCanBus_Sender(CAN1,TAB_TEST,ASK_ONLINE,ACTIVE,0,0,0,0,0);
		
	/* Thread de espera de señal */
	while(TIMEOUT_COUNTER <= TIMEOUT_LIMIT){
		
		/* Aumento de la variable COUNTER */
		TIMEOUT_COUNTER++;
		
		/* Nuevo dato en el FIFO */
		if(TAB_CC1.NEW_DATA == ACTIVE){
			
			/* Variable de entrada recursiva */
			TAB_CC1.NEW_DATA = NO_ACTIVE ;
			TIMEOUT_COUNTER = 0;
			
			/* El valor de entrada es diferente al enviado */
			if(TAB_CC1.CARRIER != DATA ){
			  if(TESTER_COUNTER <= LIMIT_COUNTER){
			    TESTER_BUFFER[TESTER_COUNTER] = TAB_CC1.CARRIER;
			    DATA_BUFFER[TESTER_COUNTER] = DATA;
			    TESTER_COUNTER++;
			  }
		  }
			
			/* El valor de entrada es igual al enviado */
		  else{
			  if(TESTER_COUNTER <= LIMIT_COUNTER){
			    TESTER_BUFFER[TESTER_COUNTER] = ACTIVE;
			    DATA_BUFFER[TESTER_COUNTER] = DATA;
			    TESTER_COUNTER++;
				}
		  }
		}
	}
	
	/* Reset de todos los valores */
 	osThreadTESTER_OFF_ALL();	
	
	/* Si no existio señal alguna */
	if(TESTER_COUNTER == TESTER_SAVED){
	  TESTER_BUFFER[TESTER_COUNTER] = NO_ACTIVE;
	  DATA_BUFFER[TESTER_COUNTER] = DATA;
	  TESTER_COUNTER++;
	}
	
	/* Se guardan los valores actuales */
	TESTER_SAVED = TESTER_COUNTER;
}

/**
  * @brief  Testeo de entrada correcta al CC
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadTESTER_CHECK_INPUT(uint32_t DATA){
	
	/* Set Ddelay for system waiting */
	mainDelay(5000000);
	
	if(GPIO_ReadInputDataBit(REVERSA_IN) ==1){
		if(DATA != REVERSA_SEL){
			if(TESTER_COUNTER <= LIMIT_COUNTER){
			  TESTER_BUFFER[TESTER_COUNTER] = REVERSA_SEL;
			  DATA_BUFFER[TESTER_COUNTER] = DATA;
			  TESTER_COUNTER++;
			}
		}
		else{
			  TESTER_BUFFER[TESTER_COUNTER] = ACTIVE;
			  DATA_BUFFER[TESTER_COUNTER] = DATA;
			  TESTER_COUNTER++;
		}
	}
	
	if(GPIO_ReadInputDataBit(PUERTA_TRASERA) ==1){
		if(DATA != PUERTA_TRASERA_SEL){
			if(TESTER_COUNTER <= LIMIT_COUNTER){
			  TESTER_BUFFER[TESTER_COUNTER] = PUERTA_TRASERA_SEL;
			  DATA_BUFFER[TESTER_COUNTER] = DATA;
			  TESTER_COUNTER++;
			}
		}
		else{
			  TESTER_BUFFER[TESTER_COUNTER] = ACTIVE;
			  DATA_BUFFER[TESTER_COUNTER] = DATA;
			  TESTER_COUNTER++;
		}
	}
	
	if(GPIO_ReadInputDataBit(PUERTA_LATERAL) ==1){
		if(DATA != PUERTA_LATERAL_SEL){
			if(TESTER_COUNTER <= 2000){
			  TESTER_BUFFER[TESTER_COUNTER] = PUERTA_LATERAL_SEL;
			  DATA_BUFFER[TESTER_COUNTER] = DATA;
			  TESTER_COUNTER++;
			}
		}
		else{
			  TESTER_BUFFER[TESTER_COUNTER] = ACTIVE;
			  DATA_BUFFER[TESTER_COUNTER] = DATA;
			  TESTER_COUNTER++;
		}
	}
	
	/* Reset de todos los valores */
 	osThreadTESTER_OFF_ALL();	
	
	/* Si no existio señal alguna */
	if(TESTER_COUNTER == TESTER_SAVED){
	  TESTER_BUFFER[TESTER_COUNTER] = NO_ACTIVE;
	  DATA_BUFFER[TESTER_COUNTER] = DATA;
	  TESTER_COUNTER++;
	}
	
	/* Se guardan los valores actuales */
	TESTER_SAVED = TESTER_COUNTER;
}

/**
  * @brief  Thread de funciones periodicas
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadTESTER_OFF_ALL(void){
	
	/* Reset de valores Direccionador en DIRECCIONADOR */
	if(TAB_CC1.DIRECCIONADOR_ACT == ACTIVE){
    osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,LED_2_SEL,NO_ACTIVE,0,0,0,0,0);
		mainDelay(5000);
    osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,LED_3_SEL,NO_ACTIVE,0,0,0,0,0);
		mainDelay(5000);
    osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,LED_4_SEL,NO_ACTIVE,0,0,0,0,0);
		mainDelay(5000);
    osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,LED_5_SEL,NO_ACTIVE,0,0,0,0,0);
		mainDelay(5000);
    osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,LED_6_SEL,NO_ACTIVE,0,0,0,0,0);
		mainDelay(5000);
    osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,LED_7_SEL,NO_ACTIVE,0,0,0,0,0);
		mainDelay(5000);
    osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,LED_8_SEL,NO_ACTIVE,0,0,0,0,0);
		mainDelay(5000);
    osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,LED_9_SEL,NO_ACTIVE,0,0,0,0,0);
		mainDelay(5000);
	}
	
	/* Se resetean todos los reelevadores del CC */
	GPIO_ResetBits(EXTRACTOR_ALTA);
	GPIO_ResetBits(VENTILADOR_ALTA);
	GPIO_ResetBits(ESTROBOS);
	GPIO_ResetBits(REVERSA);
	GPIO_ResetBits(LUZ_ALTA);
	GPIO_ResetBits(LUZ_BAJA);
	GPIO_ResetBits(LUZ_PIEL_SENSIBLE);
	GPIO_ResetBits(LUZ_MESA);
	GPIO_ResetBits(LUZ_GAVETAS);
	GPIO_ResetBits(LUZ_ESCENA_PERIMETRAL);
	GPIO_ResetBits(LUZ_ESTACIONADO);
	GPIO_ResetBits(ESCENA_TRASERA);
	GPIO_ResetBits(ESCENA_DERECHA);
	GPIO_ResetBits(ESCENA_IZQUIERDA);
	GPIO_ResetBits(PERIMETRALES);
	GPIO_ResetBits(TORRETA);
	GPIO_ResetBits(SUCCIONADOR);
	GPIO_ResetBits(VOLTAJE_TABLEROS);
	
	/* Reset de valores del estribo en DIRECCIONADOR */
	if(TAB_CC1.DIRECCIONADOR_ACT == ACTIVE){
    osTreadCanBus_Sender(CAN2,TAB_DIRECCIONADOR,END_TRACE,ACTIVE,0,0,0,0,0);
	}
	
	/* Reset de salidas de control de TESTER a CC */
  osTreadCanBus_Sender(CAN1,TAB_TEST,SOLENOIDE_SEL,NO_ACTIVE,0,0,0,0,0);
	mainDelay(5000);
  osTreadCanBus_Sender(CAN1,TAB_TEST,RADIO_SEL,NO_ACTIVE,0,0,0,0,0);
	mainDelay(5000);
  osTreadCanBus_Sender(CAN1,TAB_TEST,TOMA_12_SEL,NO_ACTIVE,0,0,0,0,0);
	mainDelay(5000);
  osTreadCanBus_Sender(CAN1,TAB_TEST,AIRE_ACONDICIONADO_SEL,NO_ACTIVE,0,0,0,0,0);
	mainDelay(5000);
  osTreadCanBus_Sender(CAN1,TAB_TEST,VOLTAJE_TAB_DELANTERO_SEL,NO_ACTIVE,0,0,0,0,0);
	mainDelay(5000);
  osTreadCanBus_Sender(CAN1,TAB_TEST,STOP_FLASHER_SEL,NO_ACTIVE,0,0,0,0,0);
	mainDelay(5000);
  osTreadCanBus_Sender(CAN1,TAB_TEST,RIGHT_FLASHER_SEL,NO_ACTIVE,0,0,0,0,0);
	mainDelay(5000);
  osTreadCanBus_Sender(CAN1,TAB_TEST,LEFT_FLASHER_SEL,NO_ACTIVE,0,0,0,0,0);
	mainDelay(5000);
  osTreadCanBus_Sender(CAN1,TAB_TEST,PUERTA_TRASERA_SEL,NO_ACTIVE,0,0,0,0,0);
	mainDelay(5000);
  osTreadCanBus_Sender(CAN1,TAB_TEST,PUERTA_LATERAL_SEL,NO_ACTIVE,0,0,0,0,0);
	mainDelay(5000);
  osTreadCanBus_Sender(CAN1,TAB_TEST,REVERSA_SEL,NO_ACTIVE,0,0,0,0,0);
	mainDelay(5000);
  osTreadCanBus_Sender(CAN1,TAB_TEST,IN_SENSOR_SEL,NO_ACTIVE,0,0,0,0,0);
	mainDelay(5000);
  osTreadCanBus_Sender(CAN1,TAB_TEST,OUT_SENSOR_SEL,NO_ACTIVE,0,0,0,0,0);
	mainDelay(5000);
	
	
}
/******************* (C) COPYRIGHT 2015 EDESIGN *****FIN DE ARCHIVO****/
