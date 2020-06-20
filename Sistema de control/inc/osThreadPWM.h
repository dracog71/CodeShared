/**
  ******************************************************************************
  * @archivo  MASTER WORKSPACE
  * @autor    EDESIGN TEAM
  * @version  V2.0.0
  * @fecha    16-Diciembre-2016
  * @brief    osThreadPWM
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
/* Inclusiones */
#include "osThreadDefines.h"

/* Definicion para prevenir una inclusion recursiva --------------------------*/
#ifndef __OSTHREADPWM_H
#define __OSTHREADPWM_H

/* Enumeracion de PWM */
typedef enum{
	PWM0,
	PWM1,
	PWM2,
	PWM3,
	PWM4,
	PWM5,
	PWM6,
	PWM7,
	PWM8,
	PWM9,
	PWM10,
	PWM11,
	PWM12,
	PWM13,
	PWM14,
	PWM15,
	PWM16,
	PWM17,
	PWM18,
	PWM19,
	PWM20,
	PWM21,
	PWM22,
	PWM23,
	PWM24,
	PWM25,
	PWM26,
	PWM27,
	PWM28,
	PWM29,
	PWM30,
}PWM_ENUM;

/** @addtogroup Prototipo de Funciones
  * @{
  */ 
    void osThreadPWM_Conf_General(GPIO_TypeDef* GPIOx, uint32_t PWM, TIM_TypeDef* TIMx, 
			                              uint32_t TIMER,uint32_t Frecuencia, uint32_t Channel);
	  void osThreadPWM_START(uint32_t PWM, uint32_t Frecuencia);
	  void osThreadPWM_DutyCicle(uint32_t PWM, uint32_t PorcentajeCiclo);
/** @endofgroup Prototipo de Funciones
  * @}
  */ 
#endif /* __OSTHREADPWM_H */
/******************* (C) COPYRIGHT 2015 EDESIGN JMLG *****FIN DE ARCHIVO****/
