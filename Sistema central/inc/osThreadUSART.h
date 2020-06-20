/**
  ******************************************************************************
  * @archivo  _______________
  * @autor    EDESIGN TEAM
  * @version  V1.0.0
  * @fecha    ______________
  * @brief    ______________
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
#ifndef __OSTHREADUSART_H
#define __OSTHREADUSART_H

/* Includes  ------------------------------------------------------------------*/
#include "osThreadDefines.h"

/* Definiciones del USART  ---------------------------------------------------*/

/** @addtogroup Prototipo de Funciones
  * @{
  */ 
	
  void osThreadUSARTInit(uint32_t os_USART,uint32_t Baudrate,uint32_t PinsPack);
	void USART_HEX(USART_TypeDef* USARTx, uint16_t  DATA);
	void USART_puts(USART_TypeDef* USARTx, volatile char *s);
	void osThreadUSART3Callback(char recibido[50]);
	
/** @addtogroup Prototipo de Funciones
  * @}
  */ 
		
	
#endif /* __OSTHREADUSART_H */
