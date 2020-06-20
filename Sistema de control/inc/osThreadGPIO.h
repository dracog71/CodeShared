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
#ifndef __OSTHREADGPIO_H
#define __OSTHREADGPIO_H

/* Includes  ------------------------------------------------------------------*/
#include "osThreadDefines.h"

/* Definiciones de osThreadGPIO  ---------------------------------------------------*/
#define osThreadGPIO_USART  100111
#define osThreadGPIO_INPUT  os_IN
#define osThreadGPIO_OUTPUT os_OUT
#define osThreadGPIO_INT    os_INT
#define osThreadGPIO_ANALOG os_AN
#define osThreadGPIO_CANBUS 100121 

/** @addtogroup Definicion de pines para osThreadGPIO
  * @{
  */ 
	         
     static __INLINE void ON (GPIO_TypeDef * GPIOx, uint16_t Pin) {GPIO_SetBits  (GPIOx,Pin);}
     static __INLINE void OFF(GPIO_TypeDef * GPIOx, uint16_t Pin) {GPIO_ResetBits(GPIOx,Pin);}
     static __INLINE uint8_t STATE(GPIO_TypeDef * GPIOx, uint16_t Pin){return GPIO_ReadInputDataBit(GPIOx, Pin);}
	
/** 
  * @}
  */ 

/** @addtogroup Prototipo de Funciones
  * @{
  */ 
	
	   void osThreadGPIOInitFunc(uint32_t Fun_Alt,uint32_t PinsPack);
     void osThreadGPIOInitUSART(uint32_t Funcion, uint32_t PinsPack);
     void osThreadGPIOInitCANBUS(uint32_t CANBUS, uint32_t PinsPack);
		 void osThreadGPIOInit(GPIO_TypeDef * GPIOx, uint16_t Pin, uint32_t Func);
		 void osThreadGPIOInitINT(GPIO_TypeDef * GPIOx, uint16_t Pin);
	
/** @addtogroup Prototipo de Funciones
  * @}
  */ 
		
	
#endif /* __OSTHREADGPIO_H */
