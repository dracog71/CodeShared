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
#ifndef __OSTHREADTIMER_H
#define __OSTHREADTIMER_H

/* Includes  ------------------------------------------------------------------*/
#include "osThreadDefines.h"

/* Definiciones de osThreadTimer  ---------------------------------------------------*/

/** @addtogroup Prototipo de Funciones
  * @{
  */ 
	
	  void osThreadTimer_LED_OFF(void);
		void osThreadTimer_PWM_SOFT(void);
		void osThreadTimer_20_nanoseconds(void);
		void osThreadTimer_PuertaAbierta(void);
		void osThreadTimer_Emergency_Level(void);

/** @addtogroup Prototipo de Funciones
  * @}
  */ 
		
	
#endif /* __OSTHREADTIMER_H */
