/**
******************************************************************************
* @archivo  Interrupciones
* @autor    EDESIGN TEAM
* @version  V1.0.0
* @fecha    18-Junio-2015
* @brief    stm32f4xxx_it.h
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

/* Definicion para prevenir una inclusion recursiva --------------------------*/
#ifndef __OSTHREADIT_IT_H
#define __OSTHREADIT_IT_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Inclusion de definiciones globales */	 
#include "osThreadDefines.h"

/* Definicion para debugeo de errores */
#define ASMDEBUG
	 
/** @addtogroup Seccion_Funciones_Externas
  * @{
  */
    void NMI_Handler(void);
    void MemManage_Handler(void);
    void BusFault_Handler(void);
    void UsageFault_Handler(void);
    void SVC_Handler(void);
    void DebugMon_Handler(void);
    void PendSV_Handler(void);
	  void SysTick_Handler(void);
    void printErrorMsg(const char * errMsg);
	 
	  void USART1_IRQHandler(void);
		void USART2_IRQHandler(void);
		void USART3_IRQHandler(void);
		void UART4_IRQHandler(void);
		void UART5_IRQHandler(void);
		void USART6_IRQHandler(void);
	 
	  void CAN1_RX0_IRQHandler(void);
		void CAN2_RX0_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif /* __OSTHREADIT_IT_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
