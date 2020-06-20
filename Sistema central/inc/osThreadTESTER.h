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
#ifndef __OSTHREADTESTER_H
#define __OSTHREADTESTER_H

/* Includes  ------------------------------------------------------------------*/
#include "osThreadDefines.h"

/* Definiciones de osThreadTimer  ---------------------------------------------------*/

/** @addtogroup Prototipo de Funciones
  * @{
  */ 
	
   void osThreadTESTER_CONFIG(void);
	 void osThreadTESTER_vPeriodicTask(void);
	 void osThreadTESTER_OFF_ALL(void);
	 void osThreadTESTER_CHECK_DATA(uint32_t DATA);
	 void osThreadTESTER_CHECK_INPUT(uint32_t DATA);
	 
/** @addtogroup Prototipo de Funciones
  * @}
  */ 
		
	
#endif /* __OSTHREADTESTER_H */
