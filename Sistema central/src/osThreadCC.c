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
#include "osThreadCC.h"
 
/* Estructura de control del Centro de Carga */
extern TAB_CC_STRUCT TAB_CC1;

/* Variable de conteo */
uint32_t CC_i;

/**
  * @brief  Control de LUZ_ALTA_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(01)
  */
void osThreadCC_LUZ_ALTA_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[LUZ_ALTA_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[LUZ_ALTA_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,LUZ_ALTA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		GPIO_SetBits(LUZ_ALTA);
		GPIO_ResetBits(LUZ_BAJA);
		GPIO_ResetBits(LUZ_PIEL_SENSIBLE);
		
		/* Se apaga la luz baja */
		TAB_CC1.SAVED_BUFFER[LUZ_BAJA_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[LUZ_PIEL_SENSIBLE_SEL] = NO_ACTIVE;
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(LUZ_ALTA_SEL,TAB_CC1.SAVED_BUFFER[LUZ_ALTA_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[LUZ_ALTA_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[LUZ_ALTA_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,LUZ_ALTA_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		GPIO_ResetBits(LUZ_ALTA);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(LUZ_ALTA_SEL,TAB_CC1.SAVED_BUFFER[LUZ_ALTA_SEL]);
	}
	
}

/**
  * @brief  Control de LUZ_BAJA_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(02)
  */
void osThreadCC_LUZ_BAJA_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[LUZ_BAJA_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[LUZ_BAJA_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,LUZ_BAJA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		GPIO_ResetBits(LUZ_ALTA);
		GPIO_SetBits(LUZ_BAJA);
		GPIO_ResetBits(LUZ_PIEL_SENSIBLE);
		
		/* Se apaga la luz alta */
		TAB_CC1.SAVED_BUFFER[LUZ_ALTA_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[LUZ_PIEL_SENSIBLE_SEL] = NO_ACTIVE;
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(LUZ_BAJA_SEL,TAB_CC1.SAVED_BUFFER[LUZ_BAJA_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[LUZ_BAJA_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[LUZ_BAJA_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,LUZ_BAJA_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		if((TAB_CC1.SEG_PUERTA_LATERAL == NO_ACTIVE) && (TAB_CC1.SEG_PUERTA_TRASERA == NO_ACTIVE))
		  GPIO_ResetBits(LUZ_BAJA);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(LUZ_BAJA_SEL,TAB_CC1.SAVED_BUFFER[LUZ_BAJA_SEL]);
	}
}

/**
  * @brief  Control de PERIMETRAL_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(03)
  */
void osThreadCC_PERIMETRAL_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[PERIMETRAL_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[PERIMETRAL_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,PERIMETRAL_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		osThreadCC_TAB_TRASERO_CONTROL(PERIMETRAL_SEL,ACTIVE);
		GPIO_SetBits(PERIMETRAL);
		osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(ACTIVE);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(PERIMETRAL_SEL,TAB_CC1.SAVED_BUFFER[PERIMETRAL_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[PERIMETRAL_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[PERIMETRAL_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,PERIMETRAL_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		GPIO_ResetBits(PERIMETRAL);
		osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(NO_ACTIVE);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(PERIMETRAL_SEL,TAB_CC1.SAVED_BUFFER[PERIMETRAL_SEL]);
	}
	
}

/**
  * @brief  Control de TORRETA_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(04)
  */
void osThreadCC_TORRETA_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[TORRETA_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[TORRETA_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,TORRETA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		osThreadCC_TAB_TRASERO_CONTROL(TORRETA_SEL,ACTIVE);
		GPIO_SetBits(TORRETA);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(TORRETA_SEL,TAB_CC1.SAVED_BUFFER[TORRETA_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[TORRETA_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[TORRETA_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,TORRETA_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		GPIO_ResetBits(TORRETA);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(TORRETA_SEL,TAB_CC1.SAVED_BUFFER[TORRETA_SEL]);
	}
	
}

/**
  * @brief  Control de LUZ_MESA_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(05)
  */
void osThreadCC_LUZ_MESA_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[LUZ_MESA_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[LUZ_MESA_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,LUZ_MESA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(LUZ_MESA_SEL,TAB_CC1.SAVED_BUFFER[LUZ_MESA_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[LUZ_MESA_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[LUZ_MESA_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,LUZ_MESA_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(LUZ_MESA_SEL,TAB_CC1.SAVED_BUFFER[LUZ_MESA_SEL]);
	}
	
}

/**
  * @brief  Control de ESCENA_TRASERA_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(06)
  */
void osThreadCC_ESCENA_TRASERA_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[ESCENA_TRASERA_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[ESCENA_TRASERA_SEL] = ACTIVE;
		
		/* Dependiendo del Sender, se  envía el buzzer */
		switch(TAB_CC1.CAN_SENDER){
			case TAB_DELANTERO:
		      osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ESCENA_TRASERA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		      osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESCENA_TRASERA_SEL,ACTIVE,0,0,0,0,0);
				break;
			
			case TAB_TRASERO:
		      osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ESCENA_TRASERA_SEL,ACTIVE,0,0,0,0,0);
		      osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESCENA_TRASERA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
				break;
			
			default:
				break;
		}
		
		GPIO_SetBits(ESCENA_TRASERA);
		osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(ACTIVE);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(ESCENA_TRASERA_SEL,TAB_CC1.SAVED_BUFFER[ESCENA_TRASERA_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[ESCENA_TRASERA_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[ESCENA_TRASERA_SEL] = NO_ACTIVE;
		
		/* Dependiendo del Sender, se  envía el buzzer */
		switch(TAB_CC1.CAN_SENDER){
			case TAB_DELANTERO:
		      osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ESCENA_TRASERA_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		      osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESCENA_TRASERA_SEL,NO_ACTIVE,0,0,0,0,0);
				break;
			
			case TAB_TRASERO:
		      osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ESCENA_TRASERA_SEL,NO_ACTIVE,0,0,0,0,0);
		      osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESCENA_TRASERA_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
				break;
			
			default:
				break;
		}
		
		if(TAB_CC1.SEG_PUERTA_TRASERA == NO_ACTIVE)
		  GPIO_ResetBits(ESCENA_TRASERA);
		osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(NO_ACTIVE);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(ESCENA_TRASERA_SEL,TAB_CC1.SAVED_BUFFER[ESCENA_TRASERA_SEL]);
	}
	
}

/**
  * @brief  Control de ESTROBOS_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(07)
  */
void osThreadCC_ESTROBOS_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[ESTROBOS_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[ESTROBOS_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ESTROBOS_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		osThreadCC_TAB_TRASERO_CONTROL(ESTROBOS_SEL,ACTIVE);
		GPIO_SetBits(ESTROBOS);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(ESTROBOS_SEL,TAB_CC1.SAVED_BUFFER[ESTROBOS_SEL]);
	}		
		
	else if((TAB_CC1.SAVED_BUFFER[ESTROBOS_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[ESTROBOS_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ESTROBOS_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		GPIO_ResetBits(ESTROBOS);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(ESTROBOS_SEL,TAB_CC1.SAVED_BUFFER[ESTROBOS_SEL]);
	}
	
}


/**
  * @brief  Control de FAROS_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(08)
  */
void osThreadCC_FAROS_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[FAROS_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[FAROS_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,FAROS_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		osThreadCC_TAB_TRASERO_CONTROL(FAROS_SEL,ACTIVE);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(FAROS_SEL,TAB_CC1.SAVED_BUFFER[FAROS_SEL]);
	}		
		
	else if((TAB_CC1.SAVED_BUFFER[FAROS_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[FAROS_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,FAROS_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(FAROS_SEL,TAB_CC1.SAVED_BUFFER[FAROS_SEL]);
	}
	
}

/**
  * @brief  Control de VENTILADOR_ALTA_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(09)
  */
void osThreadCC_VENTILADOR_ALTA_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[VENTILADOR_ALTA_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[VENTILADOR_ALTA_SEL] = ACTIVE;
		TAB_CC1.SAVED_BUFFER[VENTILADOR_BAJA_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,VENTILADOR_ALTA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		GPIO_SetBits(VENTILADOR_ALTA);
		GPIO_ResetBits(VENTILADOR_BAJA);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(VENTILADOR_ALTA_SEL,TAB_CC1.SAVED_BUFFER[VENTILADOR_ALTA_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[VENTILADOR_ALTA_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[VENTILADOR_ALTA_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[VENTILADOR_BAJA_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,VENTILADOR_ALTA_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		GPIO_ResetBits(VENTILADOR_ALTA);
		GPIO_ResetBits(VENTILADOR_BAJA);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(VENTILADOR_ALTA_SEL,TAB_CC1.SAVED_BUFFER[VENTILADOR_ALTA_SEL]);
	}
	
}

/**
  * @brief  Control de VENTILADOR_BAJA_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(10)
  */
void osThreadCC_VENTILADOR_BAJA_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[VENTILADOR_BAJA_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[VENTILADOR_ALTA_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[VENTILADOR_BAJA_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,VENTILADOR_BAJA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		GPIO_ResetBits(VENTILADOR_ALTA);
		GPIO_SetBits(VENTILADOR_BAJA);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(VENTILADOR_BAJA_SEL,TAB_CC1.SAVED_BUFFER[VENTILADOR_BAJA_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[VENTILADOR_BAJA_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[VENTILADOR_ALTA_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[VENTILADOR_BAJA_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,VENTILADOR_BAJA_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		GPIO_ResetBits(VENTILADOR_ALTA);
		GPIO_ResetBits(VENTILADOR_BAJA);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(VENTILADOR_BAJA_SEL,TAB_CC1.SAVED_BUFFER[VENTILADOR_BAJA_SEL]);
	}
	
}

/**
  * @brief  Control de EXTRACTOR_ALTA_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(11)
  */
void osThreadCC_EXTRACTOR_ALTA_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[EXTRACTOR_ALTA_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[EXTRACTOR_ALTA_SEL] = ACTIVE;
		TAB_CC1.SAVED_BUFFER[EXTRACTOR_BAJA_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,EXTRACTOR_ALTA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		GPIO_SetBits(EXTRACTOR_ALTA);
		GPIO_ResetBits(EXTRACTOR_BAJA);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(EXTRACTOR_ALTA_SEL,TAB_CC1.SAVED_BUFFER[EXTRACTOR_ALTA_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[EXTRACTOR_ALTA_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[EXTRACTOR_ALTA_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[EXTRACTOR_BAJA_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,EXTRACTOR_ALTA_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		GPIO_ResetBits(EXTRACTOR_ALTA);
		GPIO_ResetBits(EXTRACTOR_BAJA);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(EXTRACTOR_ALTA_SEL,TAB_CC1.SAVED_BUFFER[EXTRACTOR_ALTA_SEL]);
	}
	
}

/**
  * @brief  Control de EXTRACTOR_BAJA_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(12)
  */
void osThreadCC_EXTRACTOR_BAJA_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[EXTRACTOR_BAJA_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[EXTRACTOR_ALTA_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[EXTRACTOR_BAJA_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,EXTRACTOR_BAJA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		GPIO_ResetBits(EXTRACTOR_ALTA);
		GPIO_SetBits(EXTRACTOR_BAJA);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(EXTRACTOR_BAJA_SEL,TAB_CC1.SAVED_BUFFER[EXTRACTOR_BAJA_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[EXTRACTOR_BAJA_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[EXTRACTOR_ALTA_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[EXTRACTOR_BAJA_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,EXTRACTOR_BAJA_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		GPIO_ResetBits(EXTRACTOR_ALTA);
		GPIO_ResetBits(EXTRACTOR_BAJA);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(EXTRACTOR_BAJA_SEL,TAB_CC1.SAVED_BUFFER[EXTRACTOR_BAJA_SEL]);
	}
	
}

/**
  * @brief  Control de AMPLIFICADOR_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(13)
  */
void osThreadCC_VOLTAJE_TABLEROS_SEL(uint32_t STATE){
}

/**
  * @brief  Control de LUZ_ESCENA_PERIMETRAL_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(14)
  */
void osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(uint32_t STATE){
	if(STATE == ACTIVE){
		GPIO_SetBits(LUZ_ESCENA_PERIMETRAL);
	}
	else if(STATE == NO_ACTIVE){
		if((TAB_CC1.SAVED_BUFFER[ESCENA_TRASERA_SEL]   == NO_ACTIVE) &&
			 (TAB_CC1.SAVED_BUFFER[LUZ_ESTACIONADO_SEL]  == NO_ACTIVE) &&
		   (TAB_CC1.SAVED_BUFFER[ESCENA_DERECHA_SEL]   == NO_ACTIVE) &&
		   (TAB_CC1.SAVED_BUFFER[ESCENA_IZQUIERDA_SEL] == NO_ACTIVE) &&
		   (TAB_CC1.SAVED_BUFFER[PERIMETRAL_SEL]       == NO_ACTIVE) &&
		   (TAB_CC1.SEG_PUERTA_TRASERA                 == NO_ACTIVE) &&
		   (TAB_CC1.SEG_PUERTA_LATERAL                 == NO_ACTIVE) &&
		   (TAB_CC1.SAVED_BUFFER[LUZ_ESTACIONADO_SEL]  == NO_ACTIVE)){
		     GPIO_ResetBits(LUZ_ESCENA_PERIMETRAL);
			 }
	}
}

/**
  * @brief  Control de LUZ_ESTACIONADO_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(15)
  */
void osThreadCC_LUZ_ESTACIONADO_SEL(uint32_t STATE){
	if(STATE == ACTIVE){
		osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(ACTIVE);
		GPIO_SetBits(LUZ_ESTACIONADO);
		TAB_CC1.SAVED_BUFFER[LUZ_ESTACIONADO_SEL] = ACTIVE;
	}
	else if(STATE == NO_ACTIVE){
		GPIO_ResetBits(LUZ_ESTACIONADO);
		TAB_CC1.SAVED_BUFFER[LUZ_ESTACIONADO_SEL] = NO_ACTIVE;
		osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(NO_ACTIVE);
	}
}

/**
  * @brief  Control de LUZ_GAVETAS_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(16)
  */
void osThreadCC_LUZ_GAVETAS_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[LUZ_GAVETAS_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[LUZ_GAVETAS_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,LUZ_GAVETAS_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(LUZ_GAVETAS_SEL,TAB_CC1.SAVED_BUFFER[LUZ_GAVETAS_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[LUZ_GAVETAS_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[LUZ_GAVETAS_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,LUZ_GAVETAS_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(LUZ_GAVETAS_SEL,TAB_CC1.SAVED_BUFFER[LUZ_GAVETAS_SEL]);
	}
	
}

/**
  * @brief  Control de ESCENA_DERECHA_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(17)
  */
void osThreadCC_ESCENA_DERECHA_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[ESCENA_DERECHA_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[ESCENA_DERECHA_SEL] = ACTIVE;
		
		/* Dependiendo del Sender, se  envía el buzzer */
		switch(TAB_CC1.CAN_SENDER){
			case TAB_DELANTERO:
		      osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ESCENA_DERECHA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		      osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESCENA_DERECHA_SEL,ACTIVE,0,0,0,0,0);
				break;
			
			case TAB_TRASERO:
		      osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ESCENA_DERECHA_SEL,ACTIVE,0,0,0,0,0);
		      osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESCENA_DERECHA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
				break;
			
			default:
				break;
		}
		
		GPIO_SetBits(ESCENA_DERECHA);
		osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(ACTIVE);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(ESCENA_DERECHA_SEL,TAB_CC1.SAVED_BUFFER[ESCENA_DERECHA_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[ESCENA_DERECHA_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[ESCENA_DERECHA_SEL] = NO_ACTIVE;
		
		/* Dependiendo del Sender, se  envía el buzzer */
		switch(TAB_CC1.CAN_SENDER){
			case TAB_DELANTERO:
		      osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ESCENA_DERECHA_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		      osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESCENA_DERECHA_SEL,NO_ACTIVE,0,0,0,0,0);
				break;
			
			case TAB_TRASERO:
		      osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ESCENA_DERECHA_SEL,NO_ACTIVE,0,0,0,0,0);
		      osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESCENA_DERECHA_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
				break;
			
			default:
				break;
		}
		
		if(TAB_CC1.SEG_PUERTA_LATERAL == NO_ACTIVE)
		  GPIO_ResetBits(ESCENA_DERECHA);
		osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(NO_ACTIVE);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(ESCENA_DERECHA_SEL,TAB_CC1.SAVED_BUFFER[ESCENA_DERECHA_SEL]);
	}
	
}

/**
  * @brief  Control de ESCENA_IZQUIERDA_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(18)
  */
void osThreadCC_ESCENA_IZQUIERDA_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[ESCENA_IZQUIERDA_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[ESCENA_IZQUIERDA_SEL] = ACTIVE;
		
		/* Dependiendo del Sender, se  envía el buzzer */
		switch(TAB_CC1.CAN_SENDER){
			case TAB_DELANTERO:
		      osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ESCENA_IZQUIERDA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		      osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESCENA_IZQUIERDA_SEL,ACTIVE,0,0,0,0,0);
				break;
			
			case TAB_TRASERO:
		      osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ESCENA_IZQUIERDA_SEL,ACTIVE,0,0,0,0,0);
		      osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESCENA_IZQUIERDA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
				break;
			
			default:
				break;
		}
		
		GPIO_SetBits(ESCENA_IZQUIERDA);
		osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(ACTIVE);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(ESCENA_IZQUIERDA_SEL,TAB_CC1.SAVED_BUFFER[ESCENA_IZQUIERDA_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[ESCENA_IZQUIERDA_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[ESCENA_IZQUIERDA_SEL] = NO_ACTIVE;
		
		/* Dependiendo del Sender, se  envía el buzzer */
		switch(TAB_CC1.CAN_SENDER){
			case TAB_DELANTERO:
		      osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ESCENA_IZQUIERDA_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		      osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESCENA_IZQUIERDA_SEL,NO_ACTIVE,0,0,0,0,0);
				break;
			
			case TAB_TRASERO:
		      osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ESCENA_IZQUIERDA_SEL,NO_ACTIVE,0,0,0,0,0);
		      osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESCENA_IZQUIERDA_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
				break;
			
			default:
				break;
		}
		
		GPIO_ResetBits(ESCENA_IZQUIERDA);
		osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(NO_ACTIVE);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(ESCENA_IZQUIERDA_SEL,TAB_CC1.SAVED_BUFFER[ESCENA_IZQUIERDA_SEL]);
	}
	
}

/**
  * @brief  Control de LUZ_PIEL_SENSIBLE_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(19)
  */
void osThreadCC_LUZ_PIEL_SENSIBLE_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[LUZ_PIEL_SENSIBLE_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[LUZ_PIEL_SENSIBLE_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,LUZ_PIEL_SENSIBLE_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		GPIO_SetBits(LUZ_PIEL_SENSIBLE);
		GPIO_ResetBits(LUZ_ALTA);
		GPIO_ResetBits(LUZ_BAJA);
		
		/* Se apaga la luz alta */
		TAB_CC1.SAVED_BUFFER[LUZ_ALTA_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[LUZ_BAJA_SEL] = NO_ACTIVE;
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(LUZ_PIEL_SENSIBLE_SEL,TAB_CC1.SAVED_BUFFER[LUZ_PIEL_SENSIBLE_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[LUZ_PIEL_SENSIBLE_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[LUZ_PIEL_SENSIBLE_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,LUZ_PIEL_SENSIBLE_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		GPIO_ResetBits(LUZ_PIEL_SENSIBLE);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(LUZ_PIEL_SENSIBLE_SEL,TAB_CC1.SAVED_BUFFER[LUZ_PIEL_SENSIBLE_SEL]);
	}
	
}

/**
  * @brief  Control de SUCCIONADOR_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(20)
  */
void osThreadCC_SUCCIONADOR_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[SUCCIONADOR_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[SUCCIONADOR_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,SUCCIONADOR_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(SUCCIONADOR_SEL,TAB_CC1.SAVED_BUFFER[SUCCIONADOR_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[SUCCIONADOR_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[SUCCIONADOR_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,SUCCIONADOR_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(SUCCIONADOR_SEL,TAB_CC1.SAVED_BUFFER[SUCCIONADOR_SEL]);
	}
	
}

/**
  * @brief  Control de INVERSOR_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(21)
  */
void osThreadCC_INVERSOR_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[INVERSOR_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[INVERSOR_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,INVERSOR_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(INVERSOR_SEL,TAB_CC1.SAVED_BUFFER[INVERSOR_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[INVERSOR_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[INVERSOR_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,INVERSOR_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(INVERSOR_SEL,TAB_CC1.SAVED_BUFFER[INVERSOR_SEL]);
	}
	
}

/**
  * @brief  Control de ESTABLE_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(22)
  */
void osThreadCC_ESTABLE_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[ESTABLE_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[ESTABLE_SEL] = ACTIVE;
		TAB_CC1.SAVED_BUFFER[CRITICO_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[GRAVE_SEL]   = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ESTABLE_SEL,ACTIVE,0,0,0,0,0);
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESTABLE_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(ESTABLE_SEL,TAB_CC1.SAVED_BUFFER[ESTABLE_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[ESTABLE_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[ESTABLE_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[CRITICO_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[GRAVE_SEL]   = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ESTABLE_SEL,NO_ACTIVE,0,0,0,0,0);
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESTABLE_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(ESTABLE_SEL,TAB_CC1.SAVED_BUFFER[ESTABLE_SEL]);
	}
	
}

/**
  * @brief  Control de CRITICO_SEL          
  * @param  Ninguno
  * @retval Ninguno                                                                         //(23)
  */
void osThreadCC_CRITICO_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[CRITICO_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[ESTABLE_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[CRITICO_SEL] = ACTIVE;
		TAB_CC1.SAVED_BUFFER[GRAVE_SEL]   = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,CRITICO_SEL,ACTIVE,0,0,0,0,0);
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,CRITICO_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(CRITICO_SEL,TAB_CC1.SAVED_BUFFER[CRITICO_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[CRITICO_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[ESTABLE_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[CRITICO_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[GRAVE_SEL]   = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,CRITICO_SEL,NO_ACTIVE,0,0,0,0,0);
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,CRITICO_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(CRITICO_SEL,TAB_CC1.SAVED_BUFFER[CRITICO_SEL]);
	}
	
}

/**
  * @brief  Control de GRAVE_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(24)
  */
void osThreadCC_GRAVE_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[GRAVE_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[ESTABLE_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[CRITICO_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[GRAVE_SEL]   = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,GRAVE_SEL,ACTIVE,0,0,0,0,0);
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,GRAVE_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(GRAVE_SEL,TAB_CC1.SAVED_BUFFER[GRAVE_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[GRAVE_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[ESTABLE_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[CRITICO_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[GRAVE_SEL]   = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,GRAVE_SEL,NO_ACTIVE,0,0,0,0,0);
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,GRAVE_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(GRAVE_SEL,TAB_CC1.SAVED_BUFFER[GRAVE_SEL]);
	}
	
}

/**
  * @brief  Control de LUZ_PUERTA_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(25)
  */
void osThreadCC_LUZ_PUERTA_SEL(uint32_t STATE){
	switch (STATE){
		
		case ACTIVE:
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,0,0,0,0,Puerta_Abierta,ACTIVE,0);
		  osTreadCanBus_Sender(CAN1,TAB_TRASERO,0,0,0,0,Puerta_Abierta,ACTIVE,0);
		
		  TAB_CC1.SAVED_BUFFER[LUZ_PUERTA_SEL] = ACTIVE;
		
		  TIM7->CNT = 0;
      TIM_Cmd(TIM7, ENABLE);
	    TIM_ITConfig(TIM7, TIM_IT_Update, ENABLE);
		
		  /* Envío al Bluetooth */
		  osThreadCC_USART_CONTROL(LUZ_PUERTA_SEL,TAB_CC1.SAVED_BUFFER[LUZ_PUERTA_SEL]);
			break;
		
		case NO_ACTIVE:
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,0,0,0,0,Puerta_Abierta,NO_ACTIVE,0);
		  osTreadCanBus_Sender(CAN1,TAB_TRASERO,0,0,0,0,Puerta_Abierta,NO_ACTIVE,0);
		
		  TAB_CC1.SAVED_BUFFER[LUZ_PUERTA_SEL] = NO_ACTIVE;
		
      TIM_Cmd(TIM7, DISABLE);
	    TIM_ITConfig(TIM7, TIM_IT_Update, DISABLE);
		
		  /* Envío al Bluetooth */
		  osThreadCC_USART_CONTROL(LUZ_PUERTA_SEL,TAB_CC1.SAVED_BUFFER[LUZ_PUERTA_SEL]);
			break;
		
		case TOGGLE: 
			
			if(TAB_CC1.SAVED_BUFFER[LUZ_PUERTA_SEL] == NO_ACTIVE){
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,0,0,0,0,Puerta_Abierta,ACTIVE,0);
		    osTreadCanBus_Sender(CAN1,TAB_TRASERO,0,0,0,0,Puerta_Abierta,ACTIVE,0);
		
		    TAB_CC1.SAVED_BUFFER[LUZ_PUERTA_SEL] = ACTIVE;
		
		    /* Envío al Bluetooth */
		    osThreadCC_USART_CONTROL(LUZ_PUERTA_SEL,TAB_CC1.SAVED_BUFFER[LUZ_PUERTA_SEL]);
			}
			else{
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,0,0,0,0,Puerta_Abierta,NO_ACTIVE,0);
		    osTreadCanBus_Sender(CAN1,TAB_TRASERO,0,0,0,0,Puerta_Abierta,NO_ACTIVE,0);
		
		    TAB_CC1.SAVED_BUFFER[LUZ_PUERTA_SEL] = NO_ACTIVE;
		
		    /* Envío al Bluetooth */
		    osThreadCC_USART_CONTROL(LUZ_PUERTA_SEL,TAB_CC1.SAVED_BUFFER[LUZ_PUERTA_SEL]);
			}
			break;
		
		default:
			break;
		
	}
}

/**
  * @brief  Control de NIVEL_EMERGENCIA_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(26)
  */
void osThreadCC_NIVEL_EMERGENCIA_SEL(uint32_t STATE){
	
	if(TAB_CC1.SAVED_BUFFER[NIVEL_EMERGENCIA_SEL] == NO_ACTIVE){
		TAB_CC1.SAVED_BUFFER[NIVEL_EMERGENCIA_SEL] = ACTIVE;
		TAB_CC1.SAVED_BUFFER[NIVEL_UNO_SEL]  = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[NIVEL_DOS_SEL]  = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[NIVEL_TRES_SEL] = NO_ACTIVE;
		osThreadCC_TAB_TRASERO_CONTROL(NIVEL_EMERGENCIA_SEL,ACTIVE);
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,NIVEL_EMERGENCIA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(NIVEL_EMERGENCIA_SEL,TAB_CC1.SAVED_BUFFER[NIVEL_EMERGENCIA_SEL]);
	}		
			
	else if(TAB_CC1.SAVED_BUFFER[NIVEL_EMERGENCIA_SEL] == ACTIVE){
		TIM_Cmd(TIM5, DISABLE);
	  TIM_ITConfig(TIM5, TIM_IT_Update, DISABLE);
		osThreadCC_Emergengy_OFF(INITIAL_SEL);
		TAB_CC1.SAVED_BUFFER[NIVEL_EMERGENCIA_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[NIVEL_UNO_SEL]  = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[NIVEL_DOS_SEL]  = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[NIVEL_TRES_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,NIVEL_EMERGENCIA_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		TAB_CC1.EmergencyLevel = INITIAL_SEL;
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(NIVEL_EMERGENCIA_SEL,TAB_CC1.SAVED_BUFFER[NIVEL_EMERGENCIA_SEL]);
	}
	
}

/**
  * @brief  Control de NIVEL_UNO_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(27)
  */
void osThreadCC_NIVEL_UNO_SEL(uint32_t STATE){
	
		if((TAB_CC1.SAVED_BUFFER[NIVEL_EMERGENCIA_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE) && (TAB_CC1.SAVED_BUFFER[NIVEL_UNO_SEL] == NO_ACTIVE)){

		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,NIVEL_UNO_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		  osThreadCC_TAB_TRASERO_CONTROL(NIVEL_UNO_SEL,ACTIVE);
			mainDelay(500000);
			TAB_CC1.SAVED_BUFFER[NIVEL_UNO_SEL]  = ACTIVE;
		  TAB_CC1.SAVED_BUFFER[NIVEL_DOS_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[NIVEL_TRES_SEL] = NO_ACTIVE;
			osThreadCC_Emergengy_OFF(NIVEL_UNO_SEL);
			mainDelay(500000);
			TAB_CC1.EmergencyLevel = NIVEL_UNO_SEL;
			TAB_CC1.Emergency_state = 3;
			TAB_CC1.Emergency_Seg = ACTIVE;
      TIM_Cmd(TIM5, ENABLE);
	    TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
		
		  /* Envío al Bluetooth */
		  osThreadCC_USART_CONTROL(NIVEL_UNO_SEL,TAB_CC1.SAVED_BUFFER[NIVEL_UNO_SEL]);
		}
		
}

/**
  * @brief  Control de NIVEL_DOS_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(28)
  */
void osThreadCC_NIVEL_DOS_SEL(uint32_t STATE){
	
		if((TAB_CC1.SAVED_BUFFER[NIVEL_EMERGENCIA_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE) && (TAB_CC1.SAVED_BUFFER[NIVEL_DOS_SEL] == NO_ACTIVE)){
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,NIVEL_DOS_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		  osThreadCC_TAB_TRASERO_CONTROL(NIVEL_DOS_SEL,ACTIVE);
			mainDelay(500000);
			TAB_CC1.SAVED_BUFFER[NIVEL_UNO_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[NIVEL_DOS_SEL]  = ACTIVE;
		  TAB_CC1.SAVED_BUFFER[NIVEL_TRES_SEL] = NO_ACTIVE;
			osThreadCC_Emergengy_OFF(NIVEL_DOS_SEL);
			mainDelay(500000);
			TAB_CC1.EmergencyLevel = NIVEL_DOS_SEL;
			TAB_CC1.Emergency_state = 8;
			TAB_CC1.Emergency_Seg = ACTIVE;
      TIM_Cmd(TIM5, ENABLE);
	    TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
		
	  	/* Envío al Bluetooth */
	  	osThreadCC_USART_CONTROL(NIVEL_DOS_SEL,TAB_CC1.SAVED_BUFFER[NIVEL_DOS_SEL]);
		}
		
}

/**
  * @brief  Control de NIVEL_TRES_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(29)
  */
void osThreadCC_NIVEL_TRES_SEL(uint32_t STATE){
	
		if((TAB_CC1.SAVED_BUFFER[NIVEL_EMERGENCIA_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE) && (TAB_CC1.SAVED_BUFFER[NIVEL_TRES_SEL] == NO_ACTIVE)){
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,NIVEL_TRES_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		  osThreadCC_TAB_TRASERO_CONTROL(NIVEL_TRES_SEL,ACTIVE);
			mainDelay(500000);
			TAB_CC1.SAVED_BUFFER[NIVEL_UNO_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[NIVEL_DOS_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[NIVEL_TRES_SEL] = ACTIVE;
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,NIVEL_UNO_SEL,NO_ACTIVE,0,0,0,0,0);
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,NIVEL_DOS_SEL,NO_ACTIVE,0,0,0,0,0);
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,NIVEL_TRES_SEL,ACTIVE,0,0,0,0,0);
			TAB_CC1.EmergencyLevel = NIVEL_TRES_SEL;
			TAB_CC1.Emergency_state = 9;
			TAB_CC1.Emergency_Seg = ACTIVE;
      TIM_Cmd(TIM5, ENABLE);
	    TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
		
	  	/* Envío al Bluetooth */
	  	osThreadCC_USART_CONTROL(NIVEL_TRES_SEL,TAB_CC1.SAVED_BUFFER[NIVEL_TRES_SEL]);
		}
		
}

/**
  * @brief  Control de DIRECCIONADOR_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(30)
  */
void osThreadCC_DIRECCIONADOR_SEL(uint32_t STATE){

	if((TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		
		/* Se apagan todos los leds */
		osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
		
		TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,DIRECCIONADOR_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		osThreadCC_TAB_TRASERO_CONTROL(DIRECCIONADOR_SEL,ACTIVE); 
		
		/* Se desactiva el Timer */
		TIM_Cmd(TIM4, ENABLE);
	  TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
		TIM4->CNT = 0;
			
		/* Contorl de estados internos */
		TAB_CC1.SAVED_BUFFER[MANUAL_LEFT_FLASHER_SEL]  = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[MANUAL_RIGHT_FLASHER_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[MANUAL_STOP_FLASHER_SEL]  = NO_ACTIVE;
			
		TAB_CC1.SAVED_BUFFER[LEFT_FLASHER_SEL]  = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[RIGHT_FLASHER_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[STOP_FLASHER_SEL]  = NO_ACTIVE;
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(DIRECCIONADOR_SEL,TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL]);
			
		/* Valores a 0 */
		TAB_CC1.FLASHER_CARRIER = NO_ACTIVE;		
			
		/* Seguro de STOP Activado */
		TAB_CC1.STOP_CARRIER = NO_ACTIVE;
		
		/* Control obre los efectos del direccionador */
	  TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
		
		/* Cambio de estado del efecto */
		TAB_CC1.EFECTO_SEG = NO_ACTIVE;
		
		/* Estabilizacion del sistema */
		mainDelay(5000);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		
		/* Se apagan todos los leds */
		osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
		
		TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,DIRECCIONADOR_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(DIRECCIONADOR_SEL,TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL]);
			
		/* Valores a 0 */
		TAB_CC1.FLASHER_CARRIER = NO_ACTIVE;
			
		/* Seguro de STOP Activado */
		TAB_CC1.STOP_CARRIER = NO_ACTIVE;
		
		/* Se desactiva el Timer */
		TIM_Cmd(TIM4, ENABLE);
	  TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
		TIM4->CNT = 0;
		
		/* Control obre los efectos del direccionador */
	  TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
		
		/* Cambio de estado del efecto */
		TAB_CC1.EFECTO_SEG = NO_ACTIVE;
		
		/* Estabilizacion del sistema */
		mainDelay(5000);
	}
  
	
}

/**
  * @brief  Control de SIRENA_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(31)
  */
void osThreadCC_SIRENA_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[SIRENA_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){

		TAB_CC1.SAVED_BUFFER[SIRENA_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,SIRENA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		osThreadCC_TAB_TRASERO_CONTROL(SIRENA_SEL,ACTIVE);
		osTreadCanBus_Sender(CAN1,TAB_SIRENA,SIRENA_SEL,ACTIVE,0,0,0,0,0);
		
	  /* Envío al Bluetooth */
	  osThreadCC_USART_CONTROL(SIRENA_SEL,TAB_CC1.SAVED_BUFFER[SIRENA_SEL]);
		
		/* Se resetean los efectos */
		TAB_CC1.HORN_COUNTER = 0;
		
		/* Esternal Trigger de sirena */
		GPIO_SetBits(SIRENA_OUTPUT_TRIGGER);
	}		
	 		
	else if((TAB_CC1.SAVED_BUFFER[SIRENA_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,SIRENA_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		osTreadCanBus_Sender(CAN1,TAB_SIRENA,SIRENA_SEL,NO_ACTIVE,0,0,0,0,0);
		TAB_CC1.SAVED_BUFFER[SIRENA_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[WAIL_SEL]  = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[HI_LO_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[HORN_SEL]  = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[YELP_SEL]  = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[PSHR_SEL]  = NO_ACTIVE;
		
	  /* Envío al Bluetooth */
	  osThreadCC_USART_CONTROL(SIRENA_SEL,TAB_CC1.SAVED_BUFFER[SIRENA_SEL]);
		
		/* Esternal Trigger de sirena */
		GPIO_ResetBits(SIRENA_OUTPUT_TRIGGER);
	}
}

/**
  * @brief  Control de WAIL_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(32)
  */
void osThreadCC_WAIL_SEL(uint32_t STATE){
	
	if(TAB_CC1.SAVED_BUFFER[SIRENA_SEL] == ACTIVE){
		if((TAB_CC1.SAVED_BUFFER[WAIL_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){			
		  osTreadCanBus_Sender(CAN1,TAB_SIRENA,WAIL_SEL,ACTIVE,0,0,0,0,0);
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,WAIL_SEL,ACTIVE,0,0,0,0,0);
		  osThreadCC_TAB_TRASERO_CONTROL(WAIL_SEL,ACTIVE);
		  TAB_CC1.SAVED_BUFFER[WAIL_SEL]  = ACTIVE;
		  TAB_CC1.SAVED_BUFFER[HI_LO_SEL] = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[YELP_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[PSHR_SEL]  = NO_ACTIVE;
			TAB_CC1.HORN_COUNTER = 1;
		
	    /* Envío al Bluetooth */
	    osThreadCC_USART_CONTROL(WAIL_SEL,TAB_CC1.SAVED_BUFFER[WAIL_SEL]);
		}
			
	  else if((TAB_CC1.SAVED_BUFFER[WAIL_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		  osTreadCanBus_Sender(CAN1,TAB_SIRENA,WAIL_SEL,NO_ACTIVE,0,0,0,0,0);
		  TAB_CC1.SAVED_BUFFER[WAIL_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[HI_LO_SEL] = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[YELP_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[PSHR_SEL]  = NO_ACTIVE;
			TAB_CC1.HORN_COUNTER = 0;
		
	    /* Envío al Bluetooth */
	    osThreadCC_USART_CONTROL(WAIL_SEL,TAB_CC1.SAVED_BUFFER[WAIL_SEL]);
			
	  }
	}
	
}

/**
  * @brief  Control de HI_LO_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(33)
  */
void osThreadCC_HI_LO_SEL(uint32_t STATE){
	
	if(TAB_CC1.SAVED_BUFFER[SIRENA_SEL] == ACTIVE){
		if((TAB_CC1.SAVED_BUFFER[HI_LO_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		  osTreadCanBus_Sender(CAN1,TAB_SIRENA,HI_LO_SEL,ACTIVE,0,0,0,0,0);
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,HI_LO_SEL,ACTIVE,0,0,0,0,0);
		  osThreadCC_TAB_TRASERO_CONTROL(HI_LO_SEL,ACTIVE);
		  TAB_CC1.SAVED_BUFFER[WAIL_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[HI_LO_SEL] = ACTIVE;
		  TAB_CC1.SAVED_BUFFER[YELP_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[PSHR_SEL]  = NO_ACTIVE;
			TAB_CC1.HORN_COUNTER = 3;
		
	    /* Envío al Bluetooth */
	    osThreadCC_USART_CONTROL(HI_LO_SEL,TAB_CC1.SAVED_BUFFER[HI_LO_SEL]);
		}
			
	  else if((TAB_CC1.SAVED_BUFFER[HI_LO_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		  osTreadCanBus_Sender(CAN1,TAB_SIRENA,HI_LO_SEL,NO_ACTIVE,0,0,0,0,0);
		  TAB_CC1.SAVED_BUFFER[WAIL_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[HI_LO_SEL] = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[YELP_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[PSHR_SEL]  = NO_ACTIVE;
			TAB_CC1.HORN_COUNTER = 0;
		
	    /* Envío al Bluetooth */
	    osThreadCC_USART_CONTROL(HI_LO_SEL,TAB_CC1.SAVED_BUFFER[HI_LO_SEL]);
			
	  }
	}
}

/**
  * @brief  Control de VOL_MENOS_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(34)
  */
void osThreadCC_VOL_MENOS_SEL(uint32_t STATE){
	
	printf("VOL_MENOS_SEL \r\n");
	
	if((TAB_CC1.SAVED_BUFFER[MICRO_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE) && (TAB_CC1.MICRO_LEVEL > 60)){
		TAB_CC1.MICRO_LEVEL = TAB_CC1.MICRO_LEVEL - 5;
		osThreadCC_TAB_TRASERO_CONTROL(VOL_MENOS_SEL,ACTIVE);
		osTreadCanBus_Sender(CAN1,TAB_SIRENA,VOL_MENOS_SEL,TAB_CC1.MICRO_LEVEL,0,0,0,0,0);
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,VOL_MENOS_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);

	  /* Envío al Bluetooth */
	  osThreadCC_USART_CONTROL(VOL_MENOS_SEL,TAB_CC1.SAVED_BUFFER[VOL_MENOS_SEL]);
	}	
	else if(TAB_CC1.SAVED_BUFFER[MICRO_SEL] == NO_ACTIVE){
		switch(TAB_CC1.LED_INTENSITY){
			
			case 25:
				/* Reporte a tableros */
		    osThreadCC_TAB_TRASERO_CONTROL(INTENSITY_DOWN_SEL,ACTIVE);
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,INTENSITY_DOWN_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
			
			  /* Se aumenta el valor de la intensidad */
			  TAB_CC1.LED_INTENSITY = 5;
				break;
			
			case 60:
				/* Reporte a tableros */
		    osThreadCC_TAB_TRASERO_CONTROL(INTENSITY_DOWN_SEL,ACTIVE);
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,INTENSITY_DOWN_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
			
			  /* Se aumenta el valor de la intensidad */
			  TAB_CC1.LED_INTENSITY = 25;
				break;
			
			case 95:
				/* Reporte a tableros */
		    osThreadCC_TAB_TRASERO_CONTROL(INTENSITY_DOWN_SEL,ACTIVE);
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,INTENSITY_DOWN_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
			
			  /* Se aumenta el valor de la intensidad */
			  TAB_CC1.LED_INTENSITY = 60;
				break;
			
			default:
				break;
		}
	}
}

/**
  * @brief  Control de HORN_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(35)
  */
void osThreadCC_HORN_SEL(uint32_t STATE){
	
	if(TAB_CC1.SAVED_BUFFER[SIRENA_SEL] == ACTIVE){
	
		if((TAB_CC1.SAVED_BUFFER[HORN_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
			TAB_CC1.SAVED_BUFFER[HORN_SEL]  = ACTIVE;	
		  osTreadCanBus_Sender(CAN1,TAB_SIRENA,HORN_SEL,ACTIVE,0,0,0,0,0);
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,HORN_SEL,ACTIVE,0,0,BUZZER_OP,ACTIVE,0);
		  osThreadCC_TAB_TRASERO_CONTROL(HORN_SEL,ACTIVE);
		
	    /* Envío al Bluetooth */
	    osThreadCC_USART_CONTROL(HORN_SEL,TAB_CC1.SAVED_BUFFER[HORN_SEL]);
		}
			
	  else if((TAB_CC1.SAVED_BUFFER[HORN_SEL] == ACTIVE) && (TAB_CC1.STATUS == NO_ACTIVE)){
		  TAB_CC1.SAVED_BUFFER[HORN_SEL]  = NO_ACTIVE;
			
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,HORN_SEL,NO_ACTIVE,0,0,0,0,0);
		
	    /* Envío al Bluetooth */
	    osThreadCC_USART_CONTROL(HORN_SEL,TAB_CC1.SAVED_BUFFER[HORN_SEL]);
			
			/* Se recupera el audio anterior */
		  if(TAB_CC1.SAVED_BUFFER[WAIL_SEL]  == ACTIVE){
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,WAIL_SEL,ACTIVE,0,0,0,0,0);
		    osTreadCanBus_Sender(CAN1,TAB_SIRENA,WAIL_SEL,ACTIVE,0,0,0,0,0);
		
	      /* Envío al Bluetooth */
	      osThreadCC_USART_CONTROL(WAIL_SEL,TAB_CC1.SAVED_BUFFER[WAIL_SEL]);
			}
		  else if(TAB_CC1.SAVED_BUFFER[HI_LO_SEL] == ACTIVE){
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,HI_LO_SEL,ACTIVE,0,0,0,0,0);
		    osTreadCanBus_Sender(CAN1,TAB_SIRENA,HI_LO_SEL,ACTIVE,0,0,0,0,0);
		
	      /* Envío al Bluetooth */
	      osThreadCC_USART_CONTROL(HI_LO_SEL,TAB_CC1.SAVED_BUFFER[HI_LO_SEL]);
			}
		  else if(TAB_CC1.SAVED_BUFFER[YELP_SEL]  == ACTIVE){
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,YELP_SEL,ACTIVE,0,0,0,0,0);
		    osTreadCanBus_Sender(CAN1,TAB_SIRENA,YELP_SEL,ACTIVE,0,0,0,0,0);
		
	      /* Envío al Bluetooth */
	      osThreadCC_USART_CONTROL(YELP_SEL,TAB_CC1.SAVED_BUFFER[YELP_SEL]);
			}
		  else if(TAB_CC1.SAVED_BUFFER[PSHR_SEL]  == ACTIVE){
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,PSHR_SEL,ACTIVE,0,0,0,0,0);
		    osTreadCanBus_Sender(CAN1,TAB_SIRENA,PSHR_SEL,ACTIVE,0,0,0,0,0);
		
	      /* Envío al Bluetooth */
	      osThreadCC_USART_CONTROL(PSHR_SEL,TAB_CC1.SAVED_BUFFER[PSHR_SEL]);
			}
			else{		
		    osTreadCanBus_Sender(CAN1,TAB_SIRENA,HORN_SEL,NO_ACTIVE,0,0,0,0,0);
			}
	  }
	}
}

/**
  * @brief  Control de YELP_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(36)
  */
void osThreadCC_YELP_SEL(uint32_t STATE){
	
	if(TAB_CC1.SAVED_BUFFER[SIRENA_SEL] == ACTIVE){
		if((TAB_CC1.SAVED_BUFFER[YELP_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		  osTreadCanBus_Sender(CAN1,TAB_SIRENA,YELP_SEL,ACTIVE,0,0,0,0,0);
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,YELP_SEL,ACTIVE,0,0,0,0,0);
		  osThreadCC_TAB_TRASERO_CONTROL(YELP_SEL,ACTIVE);
		  TAB_CC1.SAVED_BUFFER[WAIL_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[HI_LO_SEL] = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[YELP_SEL]  = ACTIVE;
		  TAB_CC1.SAVED_BUFFER[PSHR_SEL]  = NO_ACTIVE;
			TAB_CC1.HORN_COUNTER = 2;
		
	    /* Envío al Bluetooth */
	    osThreadCC_USART_CONTROL(YELP_SEL,TAB_CC1.SAVED_BUFFER[YELP_SEL]);
		}
			
	  else if((TAB_CC1.SAVED_BUFFER[YELP_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		  osTreadCanBus_Sender(CAN1,TAB_SIRENA,YELP_SEL,NO_ACTIVE,0,0,0,0,0);
		  TAB_CC1.SAVED_BUFFER[WAIL_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[HI_LO_SEL] = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[YELP_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[PSHR_SEL]  = NO_ACTIVE;
			TAB_CC1.HORN_COUNTER = 0;
		
	    /* Envío al Bluetooth */
	    osThreadCC_USART_CONTROL(YELP_SEL,TAB_CC1.SAVED_BUFFER[YELP_SEL]);
			
	  }
	}
	

}

/**
  * @brief  Control de PSHR_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(37)
  */
void osThreadCC_PSHR_SEL(uint32_t STATE){
	
	if(TAB_CC1.SAVED_BUFFER[SIRENA_SEL] == ACTIVE){
		if((TAB_CC1.SAVED_BUFFER[PSHR_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		  osTreadCanBus_Sender(CAN1,TAB_SIRENA,PSHR_SEL,ACTIVE,0,0,0,0,0);
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,PSHR_SEL,ACTIVE,0,0,0,0,0);
		  osThreadCC_TAB_TRASERO_CONTROL(PSHR_SEL,ACTIVE);
		  TAB_CC1.SAVED_BUFFER[WAIL_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[HI_LO_SEL] = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[HORN_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[YELP_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[PSHR_SEL]  = ACTIVE;
			TAB_CC1.HORN_COUNTER = 5;
		
	    /* Envío al Bluetooth */
	    osThreadCC_USART_CONTROL(PSHR_SEL,TAB_CC1.SAVED_BUFFER[PSHR_SEL]);
		}
			
	  else if((TAB_CC1.SAVED_BUFFER[PSHR_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		  osTreadCanBus_Sender(CAN1,TAB_SIRENA,PSHR_SEL,NO_ACTIVE,0,0,0,0,0);
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,PSHR_SEL,NO_ACTIVE,0,0,0,0,0);
		  osThreadCC_TAB_TRASERO_CONTROL(PSHR_SEL,NO_ACTIVE);
		  TAB_CC1.SAVED_BUFFER[WAIL_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[HI_LO_SEL] = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[HORN_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[YELP_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[PSHR_SEL]  = NO_ACTIVE;
			TAB_CC1.HORN_COUNTER = 0;
		
	    /* Envío al Bluetooth */
	    osThreadCC_USART_CONTROL(PSHR_SEL,TAB_CC1.SAVED_BUFFER[PSHR_SEL]);
			
	  }
	}
	
		
}

/**
  * @brief  Control de VOL_MAS_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(38)
  */
void osThreadCC_VOL_MAS_SEL(uint32_t STATE){
	
	printf("VOL_MAS_SEL \r\n");
	
	if((TAB_CC1.SAVED_BUFFER[MICRO_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE) && (TAB_CC1.MICRO_LEVEL < 100)){
		TAB_CC1.MICRO_LEVEL = TAB_CC1.MICRO_LEVEL + 5;
		osThreadCC_TAB_TRASERO_CONTROL(VOL_MAS_SEL,ACTIVE);
		osTreadCanBus_Sender(CAN1,TAB_SIRENA,VOL_MAS_SEL,TAB_CC1.MICRO_LEVEL,0,0,0,0,0);
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,VOL_MAS_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		
	  /* Envío al Bluetooth */
	  osThreadCC_USART_CONTROL(VOL_MAS_SEL,TAB_CC1.SAVED_BUFFER[VOL_MAS_SEL]);
	}	
	else if(TAB_CC1.SAVED_BUFFER[MICRO_SEL] == NO_ACTIVE){
		switch(TAB_CC1.LED_INTENSITY){
			
			case 5:
				/* Reporte a tableros */
		    osThreadCC_TAB_TRASERO_CONTROL(INTENSITY_UP_SEL,ACTIVE);
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,INTENSITY_UP_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
			
			  /* Se aumenta el valor de la intensidad */
			  TAB_CC1.LED_INTENSITY = 25;
				break;
			
			case 25:
				/* Reporte a tableros */
		    osThreadCC_TAB_TRASERO_CONTROL(INTENSITY_UP_SEL,ACTIVE);
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,INTENSITY_UP_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
			
			  /* Se aumenta el valor de la intensidad */
			  TAB_CC1.LED_INTENSITY = 60;
				break;
			
			case 60:
				/* Reporte a tableros */
		    osThreadCC_TAB_TRASERO_CONTROL(INTENSITY_UP_SEL,ACTIVE);
		    osTreadCanBus_Sender(CAN1,TAB_DELANTERO,INTENSITY_UP_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
			
			  /* Se aumenta el valor de la intensidad */
			  TAB_CC1.LED_INTENSITY = 95;
				break;
			
			default:
				break;
		}
	}
}

/**
  * @brief  Control de CRONOMETRO_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(39)
  */
void osThreadCC_CRONOMETRO_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[CRONOMETRO_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
	  TAB_CC1.SAVED_BUFFER[CRONOMETRO_SEL] = ACTIVE;
	  osTreadCanBus_Sender(CAN1,TAB_TRASERO,CRONOMETRO_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		
	  /* Envío al Bluetooth */
	  osThreadCC_USART_CONTROL(CRONOMETRO_SEL,TAB_CC1.SAVED_BUFFER[CRONOMETRO_SEL]);
		
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[CRONOMETRO_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
	  TAB_CC1.SAVED_BUFFER[CRONOMETRO_SEL] = NO_ACTIVE;
	  osTreadCanBus_Sender(CAN1,TAB_TRASERO,CRONOMETRO_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);

	  /* Envío al Bluetooth */
	  osThreadCC_USART_CONTROL(CRONOMETRO_SEL,TAB_CC1.SAVED_BUFFER[CRONOMETRO_SEL]);
		
	}
	
}

/**
  * @brief  Control de REINICIAR_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(40)
  */
void osThreadCC_REINICIAR_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[CRONOMETRO_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,REINICIAR_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		
	  /* Envío al Bluetooth */
	  osThreadCC_USART_CONTROL(REINICIAR_SEL,ACTIVE);
	
	}		

}

/**
  * @brief  Control de DETENER_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(41)
  */
void osThreadCC_DETENER_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[CRONOMETRO_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,DETENER_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		
	  /* Envío al Bluetooth */
	  osThreadCC_USART_CONTROL(DETENER_SEL,ACTIVE);
		
	}		
}

/**
  * @brief  Control de ESTRIBO_ON_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(42)
  */
void osThreadCC_ESTRIBO_ON_SEL(uint32_t STATE){

	if((TAB_CC1.SAVED_BUFFER[ESTRIBO_ON_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
	  TAB_CC1.SAVED_BUFFER[ESTRIBO_ON_SEL] = ACTIVE;
	  osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESTRIBO_ON_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		
	  /* Envío al Bluetooth */
	  osThreadCC_USART_CONTROL(ESTRIBO_ON_SEL,TAB_CC1.SAVED_BUFFER[ESTRIBO_ON_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[ESTRIBO_ON_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
	  TAB_CC1.SAVED_BUFFER[ESTRIBO_ON_SEL] = NO_ACTIVE;
	  osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESTRIBO_ON_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);

	  /* Envío al Bluetooth */
	  osThreadCC_USART_CONTROL(ESTRIBO_ON_SEL,TAB_CC1.SAVED_BUFFER[ESTRIBO_ON_SEL]);
	}
  
}

/**
  * @brief  Control de ESTRIBO_FUERA_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(43)
  */
void osThreadCC_ESTRIBO_FUERA_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[ESTRIBO_ON_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE) && (GPIO_ReadInputDataBit(PUERTA_LATERAL) == 0) 
		&& (TAB_CC1.SAVED_BUFFER[OUT_SENSOR_SEL] == NO_ACTIVE)){
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESTRIBO_FUERA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		
	  /* Envío al Bluetooth */
	  osThreadCC_USART_CONTROL(ESTRIBO_FUERA_SEL,ACTIVE);
	}		
	
}

/**
  * @brief  Control de ESTRIBO_DENTRO_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(44)
  */
void osThreadCC_ESTRIBO_DENTRO_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[ESTRIBO_ON_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE) && (GPIO_ReadInputDataBit(PUERTA_LATERAL) == 0)
		&& (TAB_CC1.SAVED_BUFFER[IN_SENSOR_SEL] == NO_ACTIVE)){
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESTRIBO_DENTRO_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		
	  /* Envío al Bluetooth */
	  osThreadCC_USART_CONTROL(ESTRIBO_DENTRO_SEL,ACTIVE);
	}		
	
}

/**
  * @brief  Control de REVERSA_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(49)
  */
void osThreadCC_REVERSA_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[REVERSA_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[REVERSA_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,REVERSA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		osThreadCC_TAB_TRASERO_CONTROL(REVERSA_SEL,ACTIVE);

		if(TAB_CC1.SEG_REVERSA == ACTIVE)
		  GPIO_SetBits(REVERSA);
		
	  /* Envío al Bluetooth */
	  osThreadCC_USART_CONTROL(REVERSA_SEL,TAB_CC1.SAVED_BUFFER[REVERSA_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[REVERSA_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[REVERSA_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,REVERSA_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		GPIO_ResetBits(REVERSA);
		
	  /* Envío al Bluetooth */
	  osThreadCC_USART_CONTROL(REVERSA_SEL,TAB_CC1.SAVED_BUFFER[REVERSA_SEL]);
	}
	
}

/**
  * @brief  Control de OUT_SENSOR_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(51)
  */
void osThreadCC_OUT_SENSOR(){
	
	if(TAB_CC1.STATUS == ACTIVE){
	  osTreadCanBus_Sender(CAN1,TAB_DIRECCIONADOR,END_TRACE,ACTIVE,0,0,0,0,0);
		TAB_CC1.SAVED_BUFFER[OUT_SENSOR_SEL] = ACTIVE;
		TAB_CC1.SAVED_BUFFER[IN_SENSOR_SEL] = NO_ACTIVE;
  }
	
}

/**
  * @brief  Control de IN_SENSOR_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(52)
  */
void osThreadCC_IN_SENSOR(){
	
	if(TAB_CC1.STATUS == ACTIVE){
	  osTreadCanBus_Sender(CAN1,TAB_DIRECCIONADOR,END_TRACE,ACTIVE,0,0,0,0,0);
		TAB_CC1.SAVED_BUFFER[OUT_SENSOR_SEL] = NO_ACTIVE;
		TAB_CC1.SAVED_BUFFER[IN_SENSOR_SEL]  = ACTIVE;
		
		if((TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == NO_ACTIVE ) && (TAB_CC1.SAVED_BUFFER[ESTRIBO_ON_SEL] == NO_ACTIVE)){
			if((TAB_CC1.FLASHER_CARRIER != MANUAL_LEFT_FLASHER_SEL ) && 
				 (TAB_CC1.FLASHER_CARRIER != MANUAL_RIGHT_FLASHER_SEL) &&
			   (TAB_CC1.FLASHER_CARRIER != MANUAL_STOP_FLASHER_SEL )){
	      osTreadCanBus_Sender(CAN1,TAB_DIRECCIONADOR,ESTRIBO_ON_SEL,NO_ACTIVE,0,0,0,0,0);
			}
		}
  }
}

/**
  * @brief  switch de aceptacion niveles de emergencia
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadCC_Emergency(){
	
	/* Seleccion del nivel de emergencia */
	switch(TAB_CC1.EmergencyLevel){
		case NIVEL_UNO_SEL:
			osThreadCC_Emergency_1();
			break;
		
		case NIVEL_DOS_SEL:
			osThreadCC_Emergency_2();
			break;
		
		case NIVEL_TRES_SEL:
			osThreadCC_Emergency_3();
			break;
		
		case INITIAL_SEL:
			osThreadCC_Emergengy_OFF(INITIAL_SEL);
			break;
		
		default:
			break;
	}
	
		/* Variable de prevencion de entrada recursiva */
	TAB_CC1.Emergency_Seg = NO_ACTIVE;
	
}

/**
  * @brief  Nivel de Emergencia 1
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadCC_Emergency_1(){
	
	/* Variable de entrada */
	TAB_CC1.STATUS = ACTIVE;
	
	switch(TAB_CC1.Emergency_state){
		
		case 0: 
			/* Se desactiva el timer */
			TIM_Cmd(TIM5, DISABLE);
	    TIM_ITConfig(TIM5, TIM_IT_Update, DISABLE);
		  TAB_CC1.EmergencyLevel = INITIAL_SEL;
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,NIVEL_UNO_SEL,ACTIVE,0,0,0,0,0);
		  osThreadCC_TAB_TRASERO_CONTROL(NIVEL_UNO_SEL,ACTIVE);
		  break;
		
		case 1:
			/* Control sobre los FAROS */
			TAB_CC1.SAVED_BUFFER[FAROS_SEL] = NO_ACTIVE;
		  osThreadCC_FAROS_SEL(NO_ACTIVE);
			break;
		
		case 2:  
			/* Control sobre luces de estacionado */
		  osThreadCC_LUZ_ESTACIONADO_SEL(ACTIVE);
			break;
		
		case 3:
			break;
		
		default:
			break;
	}
}

/**
  * @brief  Nivel de Emergencia 2
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadCC_Emergency_2(){
	
	/* Variable de entrada */
	TAB_CC1.STATUS = ACTIVE;

	switch(TAB_CC1.Emergency_state){
			
	  case 0:
			/* Se desactiva el timer */
      TIM_Cmd(TIM5, DISABLE);
	    TIM_ITConfig(TIM5, TIM_IT_Update, DISABLE);
		  TAB_CC1.EmergencyLevel = INITIAL_SEL;
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,NIVEL_DOS_SEL,ACTIVE,0,0,0,0,0);
		  osThreadCC_TAB_TRASERO_CONTROL(NIVEL_DOS_SEL,ACTIVE);
			break;
		
		case 1:
			/* Control sobre los FAROS */
			TAB_CC1.SAVED_BUFFER[FAROS_2_SEL] = NO_ACTIVE;
		  osThreadCC_FAROS_2_SEL(NO_ACTIVE);
			break;
		
		case 2:
			/* Control sobre los FAROS */
			TAB_CC1.SAVED_BUFFER[FAROS_SEL] = NO_ACTIVE;
		  osThreadCC_FAROS_SEL(NO_ACTIVE);
			break;
		
		case 3:
			/* Control sobre los ESTROBOS */
			TAB_CC1.SAVED_BUFFER[ESTROBOS_SEL] = NO_ACTIVE;
		  osThreadCC_ESTROBOS_SEL(NO_ACTIVE);
		  break;
		
		case 4:
			/* Control sobre PERIMETRALES */
			TAB_CC1.SAVED_BUFFER[PERIMETRAL_SEL] = NO_ACTIVE;
		  osThreadCC_PERIMETRAL_SEL(NO_ACTIVE);
			break;
		
		case 5:
			/* Control sobre TORRETA */
			TAB_CC1.SAVED_BUFFER[TORRETA_SEL] = NO_ACTIVE;
		  osThreadCC_TORRETA_SEL(NO_ACTIVE);
			break;
			
		case 6:
			/* Control sobre luces de estacionado */
		  osThreadCC_LUZ_ESTACIONADO_SEL(NO_ACTIVE);
		break;
		
		case 7:
			/* Control del Direccionador */
	    TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] = NO_ACTIVE;
		  osThreadCC_DIRECCIONADOR_SEL(NO_ACTIVE);
			break;
		
		case 8:
			break;
		
		default:
			break;
	}
}

/**
  * @brief  Nivel de Emergencia 3
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadCC_Emergency_3(){
	
	/* Variable de entrada */
	TAB_CC1.STATUS = ACTIVE;
	
	switch(TAB_CC1.Emergency_state){
			
	  case 0:
			/* Se desactiva el timer */
      TIM_Cmd(TIM5, DISABLE);
	    TIM_ITConfig(TIM5, TIM_IT_Update, DISABLE);
		  TAB_CC1.EmergencyLevel = INITIAL_SEL;
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,NIVEL_TRES_SEL,ACTIVE,0,0,0,0,0);
		  osThreadCC_TAB_TRASERO_CONTROL(NIVEL_TRES_SEL,ACTIVE);
			break;
		
		case 1:
			/* Control sobre los FAROS */
			TAB_CC1.SAVED_BUFFER[FAROS_SEL] = NO_ACTIVE;
		  osThreadCC_FAROS_SEL(NO_ACTIVE);
			break;
		
		case 2:
			/* Control sobre los ESTROBOS */
			TAB_CC1.SAVED_BUFFER[ESTROBOS_SEL] = NO_ACTIVE;
		  osThreadCC_ESTROBOS_SEL(NO_ACTIVE);
			break;
		
		case 3:
			/* Control sobre TORRETA */
			TAB_CC1.SAVED_BUFFER[TORRETA_SEL] = NO_ACTIVE;
		  osThreadCC_TORRETA_SEL(NO_ACTIVE);
			break;
		
		case 4:
			/* Control sobre PERIMETRALES */
			TAB_CC1.SAVED_BUFFER[PERIMETRAL_SEL] = NO_ACTIVE;
		  osThreadCC_PERIMETRAL_SEL(NO_ACTIVE);
			break;
		
		case 5:
			/* Control sobre sirena */
			TAB_CC1.SAVED_BUFFER[WAIL_SEL] = NO_ACTIVE;
		  osThreadCC_WAIL_SEL(NO_ACTIVE);
			break;
		
		case 6:
			/* Control sobre sirena */
			TAB_CC1.SAVED_BUFFER[SIRENA_SEL] = NO_ACTIVE;
		  osThreadCC_SIRENA_SEL(NO_ACTIVE);
		
			break;
			
		case 7:
			/* control sobre luces de estacionado */
		  osThreadCC_LUZ_ESTACIONADO_SEL(NO_ACTIVE);
			break;
		
		case 8:
			/* Control del Direccionador */
	    TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] = NO_ACTIVE;
		  osThreadCC_DIRECCIONADOR_SEL(NO_ACTIVE);
	    TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] = ACTIVE;
		  osThreadCC_DIRECCIONADOR_SEL(NO_ACTIVE);
		
			/* Control obre los efectos del direccionador */
	    TAB_CC1.EFECTO_SELECTED = EFECTO_NIVEL_EMERGENCIA;
			break;
		
		case 9:
			break;
		
		default:
			break;
	}
}

/**
  * @brief  Nivel de Emergencia Apagado
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadCC_Emergengy_OFF(uint32_t Level){
	
	/* Variable de entrada */
	TAB_CC1.STATUS = ACTIVE; 
	
	switch (Level){
		case NIVEL_UNO_SEL:
			
		  /* Control de la sirena */
		  TAB_CC1.SAVED_BUFFER[SIRENA_SEL] = ACTIVE;
		  osThreadCC_SIRENA_SEL(NO_ACTIVE);
		
			/* Control sobre PERIMETRALES */
			TAB_CC1.SAVED_BUFFER[PERIMETRAL_SEL] = ACTIVE;
		  osThreadCC_PERIMETRAL_SEL(NO_ACTIVE);
		
		  /* Control sobre los ESTROBOS */
			TAB_CC1.SAVED_BUFFER[ESTROBOS_SEL] = ACTIVE;
		  osThreadCC_ESTROBOS_SEL(NO_ACTIVE);
		 
		  /* Control de la Torreta */
		  TAB_CC1.SAVED_BUFFER[TORRETA_SEL] = ACTIVE;
		  osThreadCC_TORRETA_SEL(NO_ACTIVE);
		
			/* Control del Direccionador */
	    TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] = ACTIVE;
		  osThreadCC_DIRECCIONADOR_SEL(NO_ACTIVE);
	    
			break;
		
		case NIVEL_DOS_SEL:
	    
		  /* Control de la sirena */
		  TAB_CC1.SAVED_BUFFER[SIRENA_SEL] = ACTIVE;
		  osThreadCC_SIRENA_SEL(NO_ACTIVE);
			break;
		
		case INITIAL_SEL:
			
		  /* Control de los faros de niebla */
		  TAB_CC1.SAVED_BUFFER[FAROS_2_SEL] = ACTIVE;
		  osThreadCC_FAROS_2_SEL(NO_ACTIVE);
			
		  /* Control de la sirena */
		  TAB_CC1.SAVED_BUFFER[SIRENA_SEL] = ACTIVE;
		  osThreadCC_SIRENA_SEL(NO_ACTIVE);
		
			/* Luz de estacionado */
		  osThreadCC_LUZ_ESTACIONADO_SEL(NO_ACTIVE);
		
			/* Control sobre PREIMETRALES */
			TAB_CC1.SAVED_BUFFER[PERIMETRAL_SEL] = ACTIVE;
		  osThreadCC_PERIMETRAL_SEL(NO_ACTIVE);
		
			/* Control sobre FAROS Y ESTROBOS */
			TAB_CC1.SAVED_BUFFER[ESTROBOS_SEL] = ACTIVE;
		  osThreadCC_ESTROBOS_SEL(NO_ACTIVE);
		
			TAB_CC1.SAVED_BUFFER[FAROS_SEL] = ACTIVE;
		  osThreadCC_FAROS_SEL(NO_ACTIVE);
		 
		  /* Control de la Torreta */
		  TAB_CC1.SAVED_BUFFER[TORRETA_SEL] = ACTIVE;
		  osThreadCC_TORRETA_SEL(NO_ACTIVE);
		 
		  /* Control de la DIRECCIONADOR */
		  TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] = ACTIVE;
		  osThreadCC_DIRECCIONADOR_SEL(NO_ACTIVE);
			
			/* Luz Perimetral */
		  osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(NO_ACTIVE);
			break;
			
		case EMERGENCIA_DEL_REDUCIDO_SEL:
			
		  /* Control de los faros de niebla */
		  TAB_CC1.SAVED_BUFFER[FAROS_2_SEL] = ACTIVE;
		  osThreadCC_FAROS_2_SEL(NO_ACTIVE);
		
			/* Luz de estacionado */
		  osThreadCC_LUZ_ESTACIONADO_SEL(NO_ACTIVE);
		
			/* Control sobre PREIMETRALES */
			TAB_CC1.SAVED_BUFFER[PERIMETRAL_SEL] = ACTIVE;
		  osThreadCC_PERIMETRAL_SEL(NO_ACTIVE);
		
			/* Control sobre FAROS Y ESTROBOS */
			TAB_CC1.SAVED_BUFFER[ESTROBOS_SEL] = ACTIVE;
		  osThreadCC_ESTROBOS_SEL(NO_ACTIVE);
		
			TAB_CC1.SAVED_BUFFER[FAROS_SEL] = ACTIVE;
		  osThreadCC_FAROS_SEL(NO_ACTIVE);
		 
		  /* Control de la Torreta */
		  TAB_CC1.SAVED_BUFFER[TORRETA_SEL] = ACTIVE;
		  osThreadCC_TORRETA_SEL(NO_ACTIVE);
		 
		  /* Control de la DIRECCIONADOR */
		  TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] = ACTIVE;
		  osThreadCC_DIRECCIONADOR_SEL(NO_ACTIVE);
			
			/* Luz Perimetral */
		  osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(NO_ACTIVE);
			break;
		
		default:
			break;
	}
}

/**
  * @brief  Control de LEFT_FLASHER_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(53)
  */
void osThreadCC_LEFT_FLASHER(void){
	
	if((TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == ACTIVE) && (TAB_CC1.SAVED_BUFFER[STOP_FLASHER_SEL] == NO_ACTIVE)){
		
    /* Espera a que la funcion termine */
    if((TAB_CC1.FLASHER_CARRIER == NO_ACTIVE) && (TAB_CC1.STOP_CARRIER == NO_ACTIVE)){		
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ALL_LED_SEL,NO_ACTIVE,0,0,0,0,0);
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
		
			/* Control sobre los buffers */
			TAB_CC1.EFECTO_COUNTER = 0;
			TAB_CC1.EFECTO_SELECTED = EFECTO_LEFT_FLASHER;
			
		  TIM_Cmd(TIM4, ENABLE);
	    TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
		  TIM4->CNT = 0;
			
		  TAB_CC1.FLASHER_CARRIER = LEFT_FLASHER_SEL;
		}
	}
}

/**
  * @brief  Control de RIGHT_FLASHER_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(54)
  */
void osThreadCC_RIGHT_FLASHER(void){
  if((TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == ACTIVE) && (TAB_CC1.SAVED_BUFFER[STOP_FLASHER_SEL] == NO_ACTIVE)){
		
    /* Espera a que la funcion termine */
    if((TAB_CC1.FLASHER_CARRIER == NO_ACTIVE) &&(TAB_CC1.STOP_CARRIER == NO_ACTIVE)){	
			
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ALL_LED_SEL,NO_ACTIVE,0,0,0,0,0);
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			
			/* Control sobre los buffers */
			TAB_CC1.EFECTO_COUNTER = 0;
			TAB_CC1.EFECTO_SELECTED = EFECTO_RIGHT_FLASHER;
      
			/* Activacion del timer para control de luces leds */
		  TIM_Cmd(TIM4, ENABLE);
	    TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
		  TIM4->CNT = 0;
		  TAB_CC1.FLASHER_CARRIER = RIGHT_FLASHER_SEL;
		}
	}
}

/**
  * @brief  Control de STOP_FLASHER_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(55)
  */
void osThreadCC_STOP_FLASHER(uint32_t STATE){
	
  if(TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == ACTIVE){
	
		if(STATE == ACTIVE){
	 
			if(TAB_CC1.STOP_CARRIER == NO_ACTIVE){
			/* Control sobre los buffers */
	    TAB_CC1.SAVED_BUFFER[STOP_FLASHER_SEL] = ACTIVE;
			TAB_CC1.EFECTO_COUNTER = 0;
			TAB_CC1.EFECTO_SELECTED = EFECTO_STOP_FLASHER_ON;
			
	    /* Se detiene el timer */
      TIM_Cmd(TIM4, ENABLE);
	    TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
			TIM4->CNT = 0; 
			
			/* Se apagan todas las luces leds */
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ALL_LED_SEL,NO_ACTIVE,0,0,0,0,0);
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			}
			else if(TAB_CC1.STOP_CARRIER == TOGGLE){
			  /* Control sobre los buffers */
	      TAB_CC1.SAVED_BUFFER[STOP_FLASHER_SEL] = ACTIVE;
			}
		
		}
		else if((STATE == NO_ACTIVE) && (TAB_CC1.SAVED_BUFFER[STOP_FLASHER_SEL] == ACTIVE)){
	
			/* Control sobre los buffers */
	    TAB_CC1.SAVED_BUFFER[STOP_FLASHER_SEL] = NO_ACTIVE;
			
			if(TAB_CC1.STOP_CARRIER == ACTIVE){
				TAB_CC1.EFECTO_COUNTER = 0;
				TAB_CC1.EFECTO_SELECTED = EFECTO_STOP_FLASHER_OFF;
			
	      /* Se detiene el timer */
        TIM_Cmd(TIM4, ENABLE);
	      TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
			  TIM4->CNT = 0; 
			}
		}
	}
}

/** @brief  Control del MICRO_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(66)
  */
void osThreadCC_MICRO_SEL(uint32_t STATE){
	
	if(TAB_CC1.SAVED_BUFFER[SIRENA_SEL] == ACTIVE){
	
		if(STATE == ACTIVE){
		  TAB_CC1.SAVED_BUFFER[MICRO_SEL] = ACTIVE;
		
	    /* Envío al Bluetooth */
	    osThreadCC_USART_CONTROL(MICRO_SEL,TAB_CC1.SAVED_BUFFER[MICRO_SEL]);
		}
			
	  else if(STATE == NO_ACTIVE){
		  TAB_CC1.SAVED_BUFFER[MICRO_SEL] = NO_ACTIVE;
		
	    /* Envío al Bluetooth */
	    osThreadCC_USART_CONTROL(MICRO_SEL,TAB_CC1.SAVED_BUFFER[MICRO_SEL]);
	  }
	}
}

/** @brief  Control del CLAXON_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(68)
  */
void osThreadCC_CLAXON_SEL(uint32_t STATE){

	if(TAB_CC1.STATUS == ACTIVE){	
		switch(TAB_CC1.HORN_COUNTER){
			case 0:
			  /* Control sobre sirena */
			  TAB_CC1.SAVED_BUFFER[WAIL_SEL] = NO_ACTIVE;
			  TAB_CC1.STATUS = ACTIVE;
		    osThreadCC_WAIL_SEL(NO_ACTIVE); printf("WAIL\r\n");
				break;
			
			case 1:
			  /* Control sobre sirena */
			  TAB_CC1.SAVED_BUFFER[YELP_SEL] = NO_ACTIVE;
			  TAB_CC1.STATUS = ACTIVE;
		    osThreadCC_YELP_SEL(NO_ACTIVE);printf("YELP\r\n");
			  break;
			
			case 2:
				
			  /* Control sobre sirena */
			  TAB_CC1.STATUS = ACTIVE;
			  TAB_CC1.SAVED_BUFFER[HI_LO_SEL] = NO_ACTIVE;
		    osThreadCC_HI_LO_SEL(NO_ACTIVE);printf("HILO\r\n");
				break;
		
			case 3:
			  /* Control sobre sirena */
			  TAB_CC1.SAVED_BUFFER[PSHR_SEL] = NO_ACTIVE;
			  TAB_CC1.STATUS = ACTIVE;
		    osThreadCC_PSHR_SEL(NO_ACTIVE);printf("PSHR\r\n");
				break;
		
			case 4:
			  /* Control sobre sirena */
			  TAB_CC1.STATUS = ACTIVE;
			  TAB_CC1.SAVED_BUFFER[PSHR_SEL] = ACTIVE;
		    osThreadCC_PSHR_SEL(NO_ACTIVE);
				break;
			
			case 5:
			  /* Control sobre sirena */
			  TAB_CC1.SAVED_BUFFER[WAIL_SEL] = ACTIVE;
			  TAB_CC1.STATUS = ACTIVE;
		    osThreadCC_WAIL_SEL(NO_ACTIVE);
				break;
			
			default:
				break;
		}
	}
}

/**
  * @brief  Control de MANUAL_LEFT_FLASHER_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(77)
  */
void osThreadCC_MANUAL_LEFT_FLASHER(uint32_t STATE){
	
	if(TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == NO_ACTIVE){
		if((TAB_CC1.SAVED_BUFFER[MANUAL_LEFT_FLASHER_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){		
			
			/* Se apagan todos los leds */
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			
		  /* Control obre los efectos del direccionador */
	    TAB_CC1.EFECTO_SELECTED = EFECTO_MANUAL_LEFT_FLASHER;
			TAB_CC1.EFECTO_COUNTER  = 0;
			
		  /* Se apagan los controles manuales */
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,MANUAL_LEFT_FLASHER_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
			
			/* Reporte al tablero trasero */
		  osThreadCC_TAB_TRASERO_CONTROL(MANUAL_LEFT_FLASHER_SEL,ACTIVE);
		
		  /* Se activa el timer */
      TIM_Cmd(TIM4, ENABLE);
      TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
			TIM4->CNT = 0;
			
		  /* Contorl de estados internos */
		  TAB_CC1.SAVED_BUFFER[MANUAL_LEFT_FLASHER_SEL]  = ACTIVE;
		  TAB_CC1.SAVED_BUFFER[MANUAL_RIGHT_FLASHER_SEL] = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[MANUAL_STOP_FLASHER_SEL]  = NO_ACTIVE;
		
	    /* Envío al Bluetooth */
	    osThreadCC_USART_CONTROL(MANUAL_LEFT_FLASHER_SEL,TAB_CC1.SAVED_BUFFER[MANUAL_LEFT_FLASHER_SEL]);
		
		  /* Cambio de estado del efecto */
		  TAB_CC1.EFECTO_SEG = NO_ACTIVE;
		
		  /* Estabilizacion del sistema */
		  mainDelay(5000);

		}
			
	  else if((TAB_CC1.SAVED_BUFFER[MANUAL_LEFT_FLASHER_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){		
			
		  /* Control obre los efectos del direccionador */
	    TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
			
		  /* Se apagan los controles manuales */
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,MANUAL_LEFT_FLASHER_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
			
		  /* Contorl de estados internos */
		  TAB_CC1.SAVED_BUFFER[MANUAL_LEFT_FLASHER_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[MANUAL_RIGHT_FLASHER_SEL] = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[MANUAL_STOP_FLASHER_SEL]  = NO_ACTIVE;
			
	    /* nvío al Bluetooth */
	    osThreadCC_USART_CONTROL(MANUAL_LEFT_FLASHER_SEL,TAB_CC1.SAVED_BUFFER[MANUAL_LEFT_FLASHER_SEL]);
		
		  /* Cambio de estado del efecto */
		  TAB_CC1.EFECTO_SEG = NO_ACTIVE;
		
		  /* Estabilizacion del sistema */
		  mainDelay(5000);

	  }
	}
  
}

/**
  * @brief  Control de MANUAL_RIGHT_FLASHER_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(78)
  */
void osThreadCC_MANUAL_RIGHT_FLASHER(uint32_t STATE){
	
	if(TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == NO_ACTIVE){
		if((TAB_CC1.SAVED_BUFFER[MANUAL_RIGHT_FLASHER_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){	
			
			/* Se apagan todos los leds */
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			
		  /* Control obre los efectos del direccionador */
	    TAB_CC1.EFECTO_SELECTED = EFECTO_MANUAL_RIGHT_FLASHER;
			TAB_CC1.EFECTO_COUNTER  = 0;
			
		  /* Se apagan los controles manuales */
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,MANUAL_RIGHT_FLASHER_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
			
			/* Reporte al tablero trasero */
		  osThreadCC_TAB_TRASERO_CONTROL(MANUAL_RIGHT_FLASHER_SEL,ACTIVE);
		
		  /* Se activa el timer */
      TIM_Cmd(TIM4, ENABLE);
      TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
			TIM4->CNT = 0;
			
		  /* Contorl de estados internos */
		  TAB_CC1.SAVED_BUFFER[MANUAL_LEFT_FLASHER_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[MANUAL_RIGHT_FLASHER_SEL] = ACTIVE;
		  TAB_CC1.SAVED_BUFFER[MANUAL_STOP_FLASHER_SEL]  = NO_ACTIVE;
		
	    /* Envío al Bluetooth */
	    osThreadCC_USART_CONTROL(MANUAL_RIGHT_FLASHER_SEL,TAB_CC1.SAVED_BUFFER[MANUAL_RIGHT_FLASHER_SEL]);
		
		  /* Cambio de estado del efecto */
		  TAB_CC1.EFECTO_SEG = NO_ACTIVE;
		
		  /* Estabilizacion del sistema */
		  mainDelay(5000);

		}
			
	  else if((TAB_CC1.SAVED_BUFFER[MANUAL_RIGHT_FLASHER_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){		
			
		  /* Control obre los efectos del direccionador */
	    TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
			
		  /* Se apagan los controles manuales */
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,MANUAL_RIGHT_FLASHER_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
			
		  /* Contorl de estados internos */
		  TAB_CC1.SAVED_BUFFER[MANUAL_LEFT_FLASHER_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[MANUAL_RIGHT_FLASHER_SEL] = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[MANUAL_STOP_FLASHER_SEL]  = NO_ACTIVE;
			
	    /* nvío al Bluetooth */
	    osThreadCC_USART_CONTROL(MANUAL_RIGHT_FLASHER_SEL,TAB_CC1.SAVED_BUFFER[MANUAL_RIGHT_FLASHER_SEL]);
		
		  /* Cambio de estado del efecto */
		  TAB_CC1.EFECTO_SEG = NO_ACTIVE;
		
		  /* Estabilizacion del sistema */
		  mainDelay(5000);

	  }
	}
}


/**
  * @brief  Control de MANUAL_STOP_FLASHER_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(79)
  */
void osThreadCC_MANUAL_STOP_FLASHER(uint32_t STATE){
	
	if(TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == NO_ACTIVE){
		if((TAB_CC1.SAVED_BUFFER[MANUAL_STOP_FLASHER_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){	
			
			/* Se apagan todos los leds */
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			
		  /* Control obre los efectos del direccionador */
	    TAB_CC1.EFECTO_SELECTED = EFECTO_MANUAL_STOP_FLASHER;
			TAB_CC1.EFECTO_COUNTER  = 0;
			
		  /* Se apagan los controles manuales */
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,MANUAL_STOP_FLASHER_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
			
			/* Reporte al tablero trasero */
		  osThreadCC_TAB_TRASERO_CONTROL(MANUAL_STOP_FLASHER_SEL,ACTIVE);
		
		  /* Se activa el timer */
      TIM_Cmd(TIM4, ENABLE);
      TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
			TIM4->CNT = 0;
			
		  /* Contorl de estados internos */
		  TAB_CC1.SAVED_BUFFER[MANUAL_LEFT_FLASHER_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[MANUAL_RIGHT_FLASHER_SEL] = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[MANUAL_STOP_FLASHER_SEL]  = ACTIVE;
	
	    /* Envío al Bluetooth */
	    osThreadCC_USART_CONTROL(MANUAL_STOP_FLASHER_SEL,TAB_CC1.SAVED_BUFFER[MANUAL_STOP_FLASHER_SEL]);
		
		  /* Cambio de estado del efecto */
		  TAB_CC1.EFECTO_SEG = NO_ACTIVE;
		
		  /* Estabilizacion del sistema */
		  mainDelay(5000);

		}
			
	  else if((TAB_CC1.SAVED_BUFFER[MANUAL_STOP_FLASHER_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){		
			
		  /* Control obre los efectos del direccionador */
	    TAB_CC1.EFECTO_SELECTED = EFECTO_FINAL;
			
		  /* Se apagan los controles manuales */
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,MANUAL_STOP_FLASHER_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
			
		  /* Contorl de estados internos */
		  TAB_CC1.SAVED_BUFFER[MANUAL_LEFT_FLASHER_SEL]  = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[MANUAL_RIGHT_FLASHER_SEL] = NO_ACTIVE;
		  TAB_CC1.SAVED_BUFFER[MANUAL_STOP_FLASHER_SEL]  = NO_ACTIVE;
			
	    /* nvío al Bluetooth */
	    osThreadCC_USART_CONTROL(MANUAL_STOP_FLASHER_SEL,TAB_CC1.SAVED_BUFFER[MANUAL_STOP_FLASHER_SEL]);
		
		  /* Cambio de estado del efecto */
		  TAB_CC1.EFECTO_SEG = NO_ACTIVE;
		
		  /* Estabilizacion del sistema */
		  mainDelay(5000);

	  }
	}
}

/**
  * @brief  Control de FAROS_2_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(81)
  */
void osThreadCC_FAROS_2_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[FAROS_2_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[FAROS_2_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,FAROS_2_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
		osThreadCC_TAB_TRASERO_CONTROL(FAROS_2_SEL,ACTIVE);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(FAROS_2_SEL,TAB_CC1.SAVED_BUFFER[FAROS_2_SEL]);
	}		
		
	else if((TAB_CC1.SAVED_BUFFER[FAROS_2_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		TAB_CC1.SAVED_BUFFER[FAROS_2_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,FAROS_2_SEL,NO_ACTIVE,0,0,BUZZER_OP,STATE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(FAROS_2_SEL,TAB_CC1.SAVED_BUFFER[FAROS_2_SEL]);
	}
	
}

/**
  * @brief  Control de EFECTOS_DIR_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(82)
  */
void osThreadCC_EFECTOS_DIR_SEL(uint32_t STATE){
	
	
		
	/* Se apagan los controles manuales */
	osTreadCanBus_Sender(CAN1,TAB_DELANTERO,EFECTOS_DIR_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
			
	/* Reporte al tablero trasero */
	osThreadCC_TAB_TRASERO_CONTROL(EFECTOS_DIR_SEL,ACTIVE);
	
	/* Si el STOP no se encuentra activo */
	if(TAB_CC1.STOP_CARRIER == NO_ACTIVE){
		/* Counter a 0 */
	  TAB_CC1.EFECTO_COUNTER = 0; 
		
		/* Se apagan todas las luces leds */
	  osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
	}
		  
	/* Dependiendo de la funcion seleccionada se activa el control de secuencia */
	if((TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL]       == NO_ACTIVE) && 
		(TAB_CC1.SAVED_BUFFER[MANUAL_LEFT_FLASHER_SEL]  == NO_ACTIVE) &&
	  (TAB_CC1.SAVED_BUFFER[MANUAL_RIGHT_FLASHER_SEL] == NO_ACTIVE) &&
	  (TAB_CC1.SAVED_BUFFER[MANUAL_STOP_FLASHER_SEL]  == NO_ACTIVE)){
			
	    /* Se aumenta la variable del efecto */
	    TAB_CC1.EFECTO_SELECTED++;
			
			/* Se activa el timer */
      TIM_Cmd(TIM4, ENABLE);
      TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
	    TIM4->CNT = 0;
	}
	else {
	    /* Se aumenta la variable del efecto */
	     TAB_CC1.DIRECCIONAL_EFFECT++;
	}		
		
	/* Cambio de estado del efecto */
	 TAB_CC1.EFECTO_SEG = NO_ACTIVE;
		
	/* Estabilizacion del sistema */
	 mainDelay(5000);
	
}

/**
  * @brief  Control de SECUENCIA_SIRENA_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(83)
  */
void osThreadCC_SECUENCIA_SIRENA_SEL(uint32_t STATE){
	
	if(TAB_CC1.SAVED_BUFFER[SIRENA_SEL] == ACTIVE){
		
		  /* Se apagan los controles manuales */
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,SECUENCIA_SIRENA_SEL,ACTIVE,0,0,BUZZER_OP,STATE,0);
			
			/* Reporte al tablero trasero */
		  //osThreadCC_TAB_TRASERO_CONTROL(SECUENCIA_SIRENA_SEL,ACTIVE);
		
		  /* Estabilizacion de la señal canbus */
		  mainDelay(5000);
		
		  /* Se transfiere el dato al cambio de audios */
		  osThreadCC_CLAXON_SEL(STATE);
	}
}

/**
  * @brief  Control de INTERMITENTES_FLASHER_SEL
  * @param  Ninguno
  * @retval Ninguno                                                                         //(85)
  */
void osThreadCC_INTERMITENTES_FLASHER_SEL(void){
  if((TAB_CC1.SAVED_BUFFER[DIRECCIONADOR_SEL] == ACTIVE) && (TAB_CC1.SAVED_BUFFER[STOP_FLASHER_SEL] == NO_ACTIVE)){
		
    /* Espera a que la funcion termine */
    if((TAB_CC1.FLASHER_CARRIER == NO_ACTIVE) && (TAB_CC1.STOP_CARRIER == NO_ACTIVE)){
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ALL_LED_SEL,NO_ACTIVE,0,0,0,0,0);
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
			
			/* control del indicador */
		  TAB_CC1.SEG_INTERMITENTES = ACTIVE;
			 
			/* Control sobre los buffers */
			TAB_CC1.EFECTO_COUNTER = 0;
			TAB_CC1.EFECTO_SELECTED = EFECTO_INTERMITENTES_FLASHER;
      
			/* Activacion del timer para control de luces leds */
		  TIM_Cmd(TIM4, ENABLE);
	    TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
		  TIM4->CNT = 0;
		  TAB_CC1.FLASHER_CARRIER = INTERMITENTES_FLASHER_SEL;	
		}
	}
}

/**
  * @brief  Control de EMERGENCIA_DEL_REDUCIDO_SEL          
  * @param  Ninguno
  * @retval Ninguno                                                                         //(88)
  */
void osThreadCC_EMERGENCIA_DEL_REDUCIDO_SEL(uint32_t STATE){
	
	int i;
	
	if((TAB_CC1.SAVED_BUFFER[EMERGENCIA_DEL_REDUCIDO_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		
		TAB_CC1.SAVED_BUFFER[EMERGENCIA_DEL_REDUCIDO_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,EMERGENCIA_DEL_REDUCIDO_SEL,ACTIVE,0,0,BUZZER_OP,ACTIVE,0);
		
		osThreadCC_TAB_TRASERO_CONTROL(EMERGENCIA_DEL_REDUCIDO_SEL,ACTIVE);
		mainDelay(500000);
		TAB_CC1.EmergencyLevel = NIVEL_DOS_SEL;
		TAB_CC1.Emergency_state = 8;
		TAB_CC1.Emergency_Seg = ACTIVE;
    TIM_Cmd(TIM5, ENABLE);
	  TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(EMERGENCIA_DEL_REDUCIDO_SEL,TAB_CC1.SAVED_BUFFER[EMERGENCIA_DEL_REDUCIDO_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[EMERGENCIA_DEL_REDUCIDO_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		
		TAB_CC1.SAVED_BUFFER[EMERGENCIA_DEL_REDUCIDO_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_DELANTERO,EMERGENCIA_DEL_REDUCIDO_SEL,NO_ACTIVE,0,0,BUZZER_OP,ACTIVE,0);
		
		TIM_Cmd(TIM5, DISABLE);
	  TIM_ITConfig(TIM5, TIM_IT_Update, DISABLE);
		
		/* Estabilizacion del sistema */
		for(i=0;i<=1000000;i++);
		
		osThreadCC_Emergengy_OFF(EMERGENCIA_DEL_REDUCIDO_SEL);
		TAB_CC1.EmergencyLevel = INITIAL_SEL;
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(EMERGENCIA_DEL_REDUCIDO_SEL,TAB_CC1.SAVED_BUFFER[EMERGENCIA_DEL_REDUCIDO_SEL]);
		
	}
	
}

/**
  * @brief  Control de AUXILIAR_1_SEL          
  * @param  Ninguno
  * @retval Ninguno                                                                         //(89)
  */
void osThreadCC_AUXILIAR_1_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[AUXILIAR_1_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		
		TAB_CC1.SAVED_BUFFER[AUXILIAR_1_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,AUXILIAR_1_SEL,ACTIVE,0,0,BUZZER_OP,ACTIVE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(AUXILIAR_1_SEL,TAB_CC1.SAVED_BUFFER[AUXILIAR_1_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[AUXILIAR_1_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		
		TAB_CC1.SAVED_BUFFER[AUXILIAR_1_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,AUXILIAR_1_SEL,NO_ACTIVE,0,0,BUZZER_OP,ACTIVE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(AUXILIAR_1_SEL,TAB_CC1.SAVED_BUFFER[AUXILIAR_1_SEL]);
		
	}
	
}

/**
  * @brief  Control de AUXILIAR_2_SEL          
  * @param  Ninguno
  * @retval Ninguno                                                                         //(90)
  */
void osThreadCC_AUXILIAR_2_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[AUXILIAR_2_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		
		TAB_CC1.SAVED_BUFFER[AUXILIAR_2_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,AUXILIAR_2_SEL,ACTIVE,0,0,BUZZER_OP,ACTIVE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(AUXILIAR_2_SEL,TAB_CC1.SAVED_BUFFER[AUXILIAR_2_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[AUXILIAR_2_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		
		TAB_CC1.SAVED_BUFFER[AUXILIAR_2_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,AUXILIAR_2_SEL,NO_ACTIVE,0,0,BUZZER_OP,ACTIVE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(AUXILIAR_2_SEL,TAB_CC1.SAVED_BUFFER[AUXILIAR_2_SEL]);
		
	}
	
}

/**
  * @brief  Control de AUXILIAR_3_SEL          
  * @param  Ninguno
  * @retval Ninguno                                                                         //(91)
  */
void osThreadCC_AUXILIAR_3_SEL(uint32_t STATE){
	
	if((TAB_CC1.SAVED_BUFFER[AUXILIAR_3_SEL] == NO_ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		
		TAB_CC1.SAVED_BUFFER[AUXILIAR_3_SEL] = ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,AUXILIAR_3_SEL,ACTIVE,0,0,BUZZER_OP,ACTIVE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(AUXILIAR_3_SEL,TAB_CC1.SAVED_BUFFER[AUXILIAR_3_SEL]);
	}		
			
	else if((TAB_CC1.SAVED_BUFFER[AUXILIAR_3_SEL] == ACTIVE) && (TAB_CC1.STATUS == ACTIVE)){
		
		TAB_CC1.SAVED_BUFFER[AUXILIAR_3_SEL] = NO_ACTIVE;
		osTreadCanBus_Sender(CAN1,TAB_TRASERO,AUXILIAR_3_SEL,NO_ACTIVE,0,0,BUZZER_OP,ACTIVE,0);
		
		/* Envío al Bluetooth */
		osThreadCC_USART_CONTROL(AUXILIAR_3_SEL,TAB_CC1.SAVED_BUFFER[AUXILIAR_3_SEL]);
		
	}
	
}

/** @brief  Control de secuencia de luces
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadCC_Directional_Sequence(){
	 
	/* Variable de entrada recursiva */
	TAB_CC1.EFECTO_SEG = NO_ACTIVE;
	
	/* Aumento de variable efecto */
	TAB_CC1.EFECTO_COUNTER++;
	
	switch(TAB_CC1.EFECTO_SELECTED){
		case EFECTO_1:
			osThreadEFECTS_Directional_EFECTO_1();
			break;
		
		case EFECTO_2:
			osThreadEFECTS_Directional_EFECTO_2();
			break;
		
		case EFECTO_3:
			osThreadEFECTS_Directional_EFECTO_3();
			break;
		
		case EFECTO_4:
			osThreadEFECTS_Directional_EFECTO_4();
			break;
		
		case EFECTO_5:
			osThreadEFECTS_Directional_EFECTO_5();
			break;
		
		case EFECTO_6:
			osThreadEFECTS_Directional_EFECTO_6();
			break;
		
		case EFECTO_7:
			osThreadEFECTS_Directional_EFECTO_7();
			break;
		
		case EFECTO_8:
		  osThreadEFECTS_Directional_EFECTO_8();
			break;
		
		case EFECTO_9:
			osThreadEFECTS_Directional_EFECTO_9();
			break;
		
		case EFECTO_10:
			osThreadEFECTS_Directional_EFECTO_10();
			break;
		
		case EFECTO_11:
			osThreadEFECTS_Directional_EFECTO_11();
			break;
		
		case EFECTO_12:
			osThreadEFECTS_Directional_EFECTO_12();
			break;
		
		case EFECTO_13:
			osThreadEFECTS_Directional_EFECTO_13();
			break;
		
		case EFECTO_14:
			osThreadEFECTS_Directional_EFECTO_14();
			break;
		
		case EFECTO_FINAL:
			
		  /* Se aumenta la variable del efecto */
		  TAB_CC1.EFECTO_SELECTED = EFECTO_APAGADO;
			
		  /* Envio de apagado de leds a todos los sitemas */
		  osTreadCanBus_Sender(CAN1,TAB_DELANTERO,ALL_LED_SEL,NO_ACTIVE,0,0,0,0,0);
			osThreadEFECTS_LED_CONTROL(ALL_LED_SEL,NO_ACTIVE);
		   
		  /* Se activa el timer */
      TIM_Cmd(TIM4, DISABLE);
      TIM_ITConfig(TIM4, TIM_IT_Update, DISABLE);
		  TIM4->CNT = 0;
		
		  /* Se liberan las direccionales */
		  TAB_CC1.FLASHER_CARRIER = NO_ACTIVE;
	
			/* control del indicador */
		  TAB_CC1.SEG_INTERMITENTES = NO_ACTIVE;
		
		  /* Cambio de estado del efecto */
		  TAB_CC1.EFECTO_SEG = NO_ACTIVE;
		
		  /* Estabilizacion del sistema */
		  mainDelay(5000);
			break;
		
		case EFECTO_STOP_FLASHER_OFF:
			osThreadEFECTS_EFECTO_STOP_FLASHER_OFF();
			break;
		
		case EFECTO_NIVEL_EMERGENCIA:
			osThreadEFECTS_EFECTO_STOP_1B();
			break;
		
		case EFECTO_EMERGENCIA_REINICIAR:
			TAB_CC1.EFECTO_COUNTER = 0;
			TAB_CC1.EFECTO_SELECTED = EFECTO_1;
			break;
		
		default:
			osThreadEFECTS_DIRECTIONAL_EFFECTS_SELECTOR();
			break;
	}
}

/** @brief  Control del tablero trasero
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadCC_TAB_TRASERO_CONTROL(uint32_t CARRIER,uint32_t STATE){
	
	/* Se repite la señal al tablero trasero */
  osTreadCanBus_Sender(CAN1,TAB_TRASERO,CARRIER,STATE,0,0,0,0,0);
	
}

/** @brief  Control de los estados del USART
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadCC_USART_CONTROL(uint32_t CARRIER, uint32_t STATE){
	  
	//printf("CARRIER = %d  |  STATE = %d\r\n",CARRIER,STATE);
	
	/* Se construye el menaje de salida para control bluetooth */
	//BLU_DATA_MODE;
	BLU_CMD_MODE;  // Este si va
	USART_HEX(UART4,'|');
	USART_HEX(UART4,CARRIER);
	USART_HEX(UART4,STATE);
	USART_HEX(UART4,'|');
	//BLU_CMD_MODE;

	
	/* Variable de entrada recursiva a beep del tablero */
	TAB_CC1.USART_INPUT = NO_ACTIVE;	
	
}

/** @brief  Construye el mensaje a enviar por el usart
  * @param  Ninguno
  * @retval Ninguno                                                             
  */
void osThreadCC_USART_SENDSTRING(USART_TypeDef* USARTx,char STRING[50]){
	/* Se construye el menaje de salida para control bluetooth */
	 BLU_DATA_MODE;
	 USART_puts(USARTx,STRING);
	 USART_HEX(USARTx,0x0D);
	 USART_HEX(USARTx,0x0A);
	 BLU_CMD_MODE; 
	
	/* Estabilizacion del sistema */
	 //mainDelay(5000);
}

/******************* (C) COPYRIGHT 2015 EDESIGN *****FIN DE ARCHIVO****/
