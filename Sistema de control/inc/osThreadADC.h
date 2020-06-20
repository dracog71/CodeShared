/**
  ******************************************************************************
  * @archivo  Conf
  * @autor    EDESIGN TEAM
  * @version  V1.0.0
  * @fecha    12-Febrero-2015
  * @brief    Archivo de configuracion e inicialización de configuraciones
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
#ifndef __OSTHREADADC_H
#define __OSTHREADADC_H

/* Includes  ------------------------------------------------------------------*/
#include "osThreadDefines.h"

/** @addtogroup Prototipo de Funciones
  * @{
  */ 
     void osThreadADCInit(
	     GPIO_TypeDef * GPIOx,               /* Definicion del puerto que se desea configurar */
       uint16_t Pin,                       /* Pin sobre el cual se aplican las configuraciones */
       uint8_t ADC_Channel_x,              /* Canal del ADC que se desea configurar */
	     ADC_TypeDef* ADCx,                  /* ADC al que se desea apuntar */                                
       DMA_Stream_TypeDef* DMAy_Streamx,   /* DMA Y Stream donde se guardará la conversion */
	     uint32_t DMA_Channel_x 	            /* Canal del DMA donde se ubica el ADC a configurar */ 
       );
     uint32_t osThreadADCReadADC(uint32_t ADCx);
#endif /* __OSTHREADADC_H */
