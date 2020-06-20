/**
  ******************************************************************************
  * @archivo  osThreadGPIO
  * @autor    EDESIGN TEAM
  * @version  V1.0.0
  * @fecha    20/Enero/2015
  * @brief    Control de inicializacion y ajustes de GPIO's
  ******************************************************************************
  * @atencion
  *
	* EL PRESENTE SOFTWARE ES SOLO PARA GUIARSE CON INFORMACION DE CODIGO QUE APUNTA
	* A FUNCIONES YA IMPLEMENTADAS PARA AHORRAR TIEMPO DE PROGRAMACION .
	* COMO RESULTADO EDESIGN AHORRARA TIEMPO DE DESARROLLO.
	* EDESIGN NO SE HACE RESPONSABLE POR EL DAÑO DIRECTO, INDIRECTO O SECUENCIAL
	* DE ESTE CODIGO SI ES USADO SIN AUTORIZACION EXPLICITA DE LA EMPRESA.
  * <h2><center>&copy; COPYRIGHT 2015 EDESIGN </center></h2>
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion --------------------------------------*/
#ifndef __OSTHREADCC_H
#define __OSTHREADCC_H

/* Includes  ------------------------------------------------------------------*/
#include "osThreadDefines.h"

/* Definiciones de osThreadTimer  ---------------------------------------------------*/

/** @addtogroup Prototipo de Funciones
  * @{
  */ 
	 void osThreadCC_LUZ_ALTA_SEL(uint32_t STATE);
	 void osThreadCC_LUZ_BAJA_SEL(uint32_t STATE);
	 void osThreadCC_PERIMETRAL_SEL(uint32_t STATE);
	 void osThreadCC_TORRETA_SEL(uint32_t STATE);
	 void osThreadCC_LUZ_MESA_SEL(uint32_t STATE);
	 void osThreadCC_ESCENA_TRASERA_SEL(uint32_t STATE);
	 void osThreadCC_ESTROBOS_SEL(uint32_t STATE);
	 void osThreadCC_FAROS_SEL(uint32_t STATE);
	 void osThreadCC_VENTILADOR_ALTA_SEL(uint32_t STATE);
	 void osThreadCC_VENTILADOR_BAJA_SEL(uint32_t STATE);
	 void osThreadCC_EXTRACTOR_ALTA_SEL(uint32_t STATE);
	 void osThreadCC_EXTRACTOR_BAJA_SEL(uint32_t STATE);
	 void osThreadCC_VOLTAJE_TABLEROS_SEL(uint32_t STATE);
	 void osThreadCC_LUZ_ESCENA_PERIMETRAL_SEL(uint32_t STATE);
	 void osThreadCC_LUZ_ESTACIONADO_SEL(uint32_t STATE);
	 void osThreadCC_LUZ_GAVETAS_SEL(uint32_t STATE);
	 void osThreadCC_ESCENA_DERECHA_SEL(uint32_t STATE);
	 void osThreadCC_ESCENA_IZQUIERDA_SEL(uint32_t STATE);
	 void osThreadCC_LUZ_PIEL_SENSIBLE_SEL(uint32_t STATE);
	 void osThreadCC_SUCCIONADOR_SEL(uint32_t STATE);
	 void osThreadCC_INVERSOR_SEL(uint32_t STATE);
	 void osThreadCC_ESTABLE_SEL(uint32_t STATE);
	 void osThreadCC_CRITICO_SEL(uint32_t STATE);
	 void osThreadCC_GRAVE_SEL(uint32_t STATE);
	 void osThreadCC_LUZ_PUERTA_SEL(uint32_t STATE);
	 void osThreadCC_NIVEL_EMERGENCIA_SEL(uint32_t STATE);
	 void osThreadCC_NIVEL_UNO_SEL(uint32_t STATE);
	 void osThreadCC_NIVEL_DOS_SEL(uint32_t STATE);
	 void osThreadCC_NIVEL_TRES_SEL(uint32_t STATE);
	 void osThreadCC_DIRECCIONADOR_SEL(uint32_t STATE);
	 void osThreadCC_SIRENA_SEL(uint32_t STATE);
	 void osThreadCC_WAIL_SEL(uint32_t STATE);
	 void osThreadCC_HI_LO_SEL(uint32_t STATE);
	 void osThreadCC_VOL_MENOS_SEL(uint32_t STATE);
	 void osThreadCC_HORN_SEL(uint32_t STATE);
	 void osThreadCC_YELP_SEL(uint32_t STATE);
	 void osThreadCC_PSHR_SEL(uint32_t STATE);
	 void osThreadCC_VOL_MAS_SEL(uint32_t STATE);
	 void osThreadCC_CRONOMETRO_SEL(uint32_t STATE);
	 void osThreadCC_REINICIAR_SEL(uint32_t STATE);
	 void osThreadCC_DETENER_SEL(uint32_t STATE);
	 void osThreadCC_ESTRIBO_ON_SEL(uint32_t STATE );
	 void osThreadCC_ESTRIBO_FUERA_SEL(uint32_t STATE);
	 void osThreadCC_ESTRIBO_DENTRO_SEL(uint32_t STATE);
	 void osThreadCC_REVERSA_SEL(uint32_t STATE);
	 void osThreadCC_OUT_SENSOR(void);
	 void osThreadCC_IN_SENSOR(void);
	 void osThreadCC_Emergency(void);
	 void osThreadCC_Emergency_1(void);
	 void osThreadCC_Emergency_2(void);
	 void osThreadCC_Emergency_3(void);
	 void osThreadCC_Emergengy_OFF(uint32_t Level);
	 void osThreadCC_LEFT_FLASHER(void);
	 void osThreadCC_RIGHT_FLASHER(void);
	 void osThreadCC_STOP_FLASHER(uint32_t STATE);
	 void osThreadCC_FLASHER(void);
	 void osThreadCC_MICRO_SEL(uint32_t STATE);
	 void osThreadCC_CLAXON_SEL(uint32_t STATE);
	 void osThreadCC_TAB_TRASERO_CONTROL(uint32_t CARRIER,uint32_t STATE);
	 void osThreadCC_CRONOMETRO(void);
	 void osThreadCC_MANUAL_LEFT_FLASHER(uint32_t STATE);
	 void osThreadCC_MANUAL_RIGHT_FLASHER(uint32_t STATE);
	 void osThreadCC_MANUAL_STOP_FLASHER(uint32_t STATE);
	 void osThreadCC_FAROS_2_SEL(uint32_t STATE);
	 void osThreadCC_EFECTOS_DIR_SEL(uint32_t STATE);
	 void osThreadCC_SECUENCIA_SIRENA_SEL(uint32_t STATE);
	 void osThreadCC_USART_CONTROL(uint32_t CARRIER, uint32_t STATE);
	 void osThreadCC_USART_SENDSTRING(USART_TypeDef* USARTx,char STRING[50]);
	 void osThreadCC_Directional_Sequence(void);
	 void osThreadCC_INTERMITENTES_FLASHER_SEL(void);
	 void osThreadCC_AUXILIAR_1_SEL(uint32_t STATE);
	 void osThreadCC_AUXILIAR_2_SEL(uint32_t STATE);
	 void osThreadCC_AUXILIAR_3_SEL(uint32_t STATE);
	 void osThreadCC_EMERGENCIA_DEL_REDUCIDO_SEL(uint32_t STATE);

/** @addtogroup Prototipo de Funciones
  * @}
  */ 
		
	
#endif /* __OSTHREADCC_H */
