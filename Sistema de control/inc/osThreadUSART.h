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
 
/* Enumeracion de botones */
  typedef enum{
	  BUTTON0,
	  BUTTON1,
	  BUTTON2,
	  BUTTON3,
	  BUTTON4,
	  BUTTON5,
	  BUTTON6,
	  BUTTON7,
	  BUTTON8,
  	BUTTON9,
 	  BUTTON10,
  	BUTTON11,
	  BUTTON12,
	  BUTTON13,
	  BUTTON14,
	  BUTTON15,
	  BUTTON16,
	  BUTTON17,
	  BUTTON18,
	  BUTTON19,
	  BUTTON20,
	  BUTTON21,
	  BUTTON22,
	  BUTTON23,
  }BUTTONS_ENUM; 
	/* Definiciones del xxxx  ---------------------------------------------------*/

/** @addtogroup Prototipo de Funciones
  * @{
  */ 
	
  void osThreadUSARTInit(uint32_t os_USART,uint32_t Baudrate,uint32_t PinsPack);
	void USART_HEX(USART_TypeDef* USARTx, uint16_t  DATA);
	void USART_puts(USART_TypeDef* USARTx, volatile char *s);
	void osThreadUSART4Callback(char recibido[50]);
	
	void osThreadUSART_Dec_AS1107(uint32_t Fila, uint32_t Val, uint32_t SEND);
	void osThreadUSART_CANBUS_DEC_AS(uint32_t Button, uint32_t STATE);
	void osThreadUSART_ClearBuffers(void);
	void osThreadUSART_Passtrough(void);
	void osThreadUSART_Semaphore(uint32_t Val);
	void osThreadUSART_Ventilador(uint32_t Val);
	void osThreadUSART_Extractor(uint32_t Val);
	void osThreadUSART_Luces(uint32_t Val);
	void osThreadUSART_Cronometro(uint32_t Val);
	void osThreadUSART_Estribo(uint32_t Val);
	void osThreadUSART_Turn_Off_Cronometro(void);
	void osThreadUsart_AS1107_LedControl(uint32_t Fila, uint32_t Val, uint32_t SEND);
	
/** @addtogroup Prototipo de Funciones
  * @}
  */ 
		
	
#endif /* __OSTHREADUSART_H */
