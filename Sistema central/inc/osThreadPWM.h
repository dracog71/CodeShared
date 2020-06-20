/**
  ******************************************************************************
  * @archivo  osThreadPWM
  * @autor    EDESIGN TEAM
  * @version  V1.0.0
  * @fecha    12-Febrero-2015
  * @brief    Archivo de configuracion e inicialización de PWM's
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

#ifndef _osThreadPWM_H_
#define _osThreadPWM_H_

/* Includes  ------------------------------------------------------------------*/
#include "osThreadDefines.h"

/* Exported functions ------------------------------------------------------- */
	/** @addtogroup Prototipo de Funciones
  * @{
  */ 
	void osThreadPWM_Conf_General(GPIO_TypeDef* GPIOx, uint32_t PWM, TIM_TypeDef* TIMx, uint32_t TIMER,uint32_t Frecuencia, uint32_t Channel);
	void osThreadPWM_Start(uint32_t PWM, uint32_t Frecuencia);
	void osThreadPWM_DutyCycle (uint32_t PWM, uint32_t PorcentajeCiclo);

#endif /* _osThreadPWM_H_ */
