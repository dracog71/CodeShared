/**
*****************************************************************************
**
**  File        : stm32f4xx_it.c
**
**  Abstract    : Main Interrupt Service Routines.
**                This file provides template for all exceptions handler and
**                peripherals interrupt service routine.
**
**  Environment : Atollic TrueSTUDIO(R)
**                STMicroelectronics STM32F4xx Standard Peripherals Library
**
**  Distribution: The file is distributed “as is,” without any warranty
**                of any kind.
**
**  (c)Copyright Atollic AB.
**  You may use this file as-is or modify it according to the needs of your
**  project. Distribution of this file (unmodified or modified) is not
**  permitted. Atollic AB permit registered Atollic TrueSTUDIO(R) users the
**  rights to distribute the assembled, compiled & linked contents of this
**  file as part of an application binary file, provided that it is built
**  using the Atollic TrueSTUDIO(R) toolchain.
**
**
*****************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

char received_string[MAX_STRLEN+1]; 

/* Estructura de control del Centro de Carga */
extern TAB_CC_STRUCT TAB_CC1;

uint32_t Counter = 0;

/**
  * @brief  Esta funcion maneja la excepcion NMI.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

 /* @brief  Esta funcion maneja la excepcion Hard Fault. 
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Loop infinito cuando una excepcion Hard Fault ocurre */
  static char msg[80];
	
  printErrorMsg("In Hard Fault Handler\n");
	
  sprintf(msg, "SCB->HFSR = 0x%08x\n", SCB->HFSR);
	
	printErrorMsg(msg);
	
  //#ifdef ASMDEBUG
   __asm volatile("BKPT #01"); 
	//#endif
	
	while (1)
  {
  }
}

/**
  * @brief  Esta funcion maneja la excepcion Memory Manage.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Loop infinito cuando una excepcion Memory Manage ocurre */
	
	printf("MemManage_Handler\r\n");
	
	if((SCB -> CFSR & (1 << 0)) != 0) 
		{
      printErrorMsg("IACCVIOL\n");
    }

	if((SCB -> CFSR & (1 << 1)) != 0) 
		{
      printErrorMsg("DACCVIOL\n");
    }

 // (SCB -> CFSR) && (1 << 2)  -> reserved
		
	if((SCB -> CFSR & (1 << 3)) != 0) 
		{
      printErrorMsg("MUNSTKERR\n");
    }

	if((SCB -> CFSR & (1 << 4)) != 0) 
		{
      printErrorMsg("MSTKERR\n");
    }

	if((SCB -> CFSR & (1 << 5)) != 0) 
		{
      printErrorMsg("MLSPERR\n");
    }
		
  // (SCB -> CFSR) && (1 << 6)  -> reserved
		
	if((SCB -> CFSR & (1 << 7)) != 0) 
		{
      printErrorMsg("MMARVALID\n");
    }

  #ifdef ASMDEBUG
   __asm volatile("BKPT #01"); 
	#endif
	
  while (1)
  {
  }
}

/**
  * @brief  Esta funcion maneja la excepcion Bus Fault.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Loop infinito cuando una excepcion Bus Fault ocurre */
	
	printf("BusFault_Handler\r\n");
	
	if((SCB -> CFSR & (1 << 8)) != 0) 
		{
      printErrorMsg("IBUSERR\n");
    }

	if((SCB -> CFSR & (1 << 9)) != 0) 
		{
      printErrorMsg("PRECISERR\n");
    }

	if((SCB -> CFSR & (1 << 10)) != 0) 
		{
      printErrorMsg("IMPRECISERR\n");
    }

	if((SCB -> CFSR & (1 << 11)) != 0) 
		{
      printErrorMsg("UNSTKERR\n");
    }

	if((SCB -> CFSR & (1 << 12)) != 0) 
		{
      printErrorMsg("STKERR\n");
    }

	if((SCB -> CFSR & (1 << 13)) != 0) 
		{
      printErrorMsg("LSPERR\n");
    }

	// (SCB -> CFSR) && (1 << 14)  -> reserved
		
	if((SCB -> CFSR & (1 << 15)) != 0) 
		{
      printErrorMsg("BFARVALID\n");
    }

		
  #ifdef ASMDEBUG
   __asm volatile("BKPT #01"); 
	#endif
	
	while (1)
  {
  }
}

/**
  * @brief  Esta funcion maneja la excepcion Usage Fault.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Loop infinito cuando una excepcion Usage Fault ocurre */
	
	printf("UsageFault_Handler\r\n");

		if((SCB -> CFSR & (1 << 16)) != 0) 
		{
      printErrorMsg("UNDEFINST\n");
    }

	if((SCB -> CFSR & (1 << 17)) != 0) 
		{
      printErrorMsg("INVSTATE\n");
    }

	if((SCB -> CFSR & (1 << 18)) != 0) 
		{
      printErrorMsg("INVPC\n");
    }

	if((SCB -> CFSR & (1 << 19)) != 0) 
		{
      printErrorMsg("NOCP\n");
    }

 // (SCB -> CFSR) && (1 << 20|21|22|23)  -> reserved
		
	if((SCB -> CFSR & (1 << 24)) != 0) 
		{
      printErrorMsg("UNALIGNED\n");
    }
	
	if((SCB -> CFSR & (1 << 25)) != 0) 
		{
      printErrorMsg("DIVBYZERO\n");
    }
		
  // (SCB -> CFSR) && (1 << 26|27|28|29|30	)  -> reserved		
		
	#ifdef ASMDEBUG
   __asm volatile("BKPT #01"); 
	#endif
	
  while (1)
  {
  }
}

/**
  * @brief  Esta funcion maneja la excepcions SVCall.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  Esta funcion maneja la excepcion Debug Monitor.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  Esta funcion maneja la excepcion PendSVC.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  Esta funcion maneja la excepcion SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

void SDIO_IRQHandler()
{
  //SD_ProcessIRQSrc();
}


/*void DMA2_Stream3_IRQHandler()
{
    SD_ProcessDMAIRQ();
}*/
/******************************************************************************/
/*                  Handlers de Interrupcion de STM32F4xx                     */
/*  Se añaden aqui los handlers de interrupcion de las funciones programadas  */
/*  para los nombres de los handlers de interrupcion disponibles refierase al */
/*  archivo (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  Esta funcion maneja la interupcion PPP request.
  * @param  None
  * @retval None
  */
void PPP_IRQHandler(void)
{
}

/**
  * @brief  Instrumented Trace Macrocell Message.
  * @param  const char * errMsg
  * @retval None
  */
void printErrorMsg(const char * errMsg)
{
   while(*errMsg != NULL ){
      ITM_SendChar(*errMsg);
      ++errMsg;
   }
}

/*******************************************************************************************/
/*************************   INTERRUPCIONES DE USART ***************************************/
/*******************************************************************************************/

/**
  * @brief  Handler del USART1 (Mensage recibido )
  * @param  None
  * @retval None
  */
void USART1_IRQHandler(void){

	//Checa si el flag de interrupcion del USART1 se activo
	if( USART_GetITStatus(USART1, USART_IT_RXNE) ){

		/* Este contador es usado para determinar la longitud del string */
		static uint8_t cnt1 = 0; 
	  /* el caracter del registro de dato del USART1 es guardado en t1 */
		char t1 = USART1->DR; 

		/*Checa si el caracter recibido no es el EOL del USART1
		 * o si la longitud máxima para el string se ha alcanzado
		 */
		if( (t1 != EOL_USART1) && (cnt1 < MAX_STRLEN) ){
			received_string[cnt1] = t1;
			cnt1++;
		}
		else{ 
			/* resetea el contador del caracter e imprime el string recibido, a su vez lo envia al callback */
			cnt1 = 0;
			//OS_USART_CALLBACK(received_string);
			memset(received_string, 0, sizeof(received_string ));
		}
	}
}

/**
  * @brief  Handler del USART2 (Mensage recibido )
  * @param  None
  * @retval None
  */
void USART2_IRQHandler(void){

	//Checa si el flag de interrupcion del USART2 se activo
	if( USART_GetITStatus(USART2, USART_IT_RXNE) ){

		/* Este contador es usado para determinar la longitud del string */
		static uint8_t cnt2 = 0; 
		/* el caracter del registro de dato del USART2 es guardado en t2 */
		char t2 = USART2->DR; 

		/*Checa si el caracter recibido no es el EOL del USART2
		 * o si la longitud máxima para el string se ha alcanzado
		 */
		if( (t2 != EOL_USART2) && (cnt2 < MAX_STRLEN) ){
			received_string[cnt2] = t2;
			cnt2++;
		}
		else{ 
			/* resetea el contador del caracter e imprime el string recibido, a su vez lo envia al callback */
			cnt2 = 0;
			//OS_USART_CALLBACK(received_string);
			memset(received_string, 0, sizeof(received_string ));
		}
	}
}

/**
  * @brief  Handler del USART3 (Mensage recibido )
  * @param  None
  * @retval None
  */
void USART3_IRQHandler(void){

	//Checa si el flag de interrupcion del USART3 se activo
	if( USART_GetITStatus(USART3, USART_IT_RXNE) ){

		/* Este contador es usado para determinar la longitud del string */
		static uint8_t cnt3 = 0; 
		/* el caracter del registro de dato del USART3 es guardado en t3 */
		char t3 = USART3->DR; 

		/*Checa si el caracter recibido no es el EOL del USART3
		 * o si la longitud máxima para el string se ha alcanzado
		 */
		if( (t3 != EOL_USART3) && (cnt3 < MAX_STRLEN) ){
			received_string[cnt3] = t3;
			cnt3++;
		}
		else{ 
			/* resetea el contador del caracter e imprime el string recibido, a su vez lo envia al callback */
			cnt3 = 0;
			//osThreadUSART3Callback(received_string);
			memset(received_string, 0, sizeof(received_string ));
		}
	}
}

/**
  * @brief  Handler del USART3 (Mensage recibido )
  * @param  None
  * @retval None
  */
void UART4_IRQHandler(void){

	//Checa si el flag de interrupcion del USARTx se activo
	if( USART_GetITStatus(UART4, USART_IT_RXNE) ){

		/* Este contador es usado para determinar la longitud del string */
		static uint8_t cnt4 = 0; 
		/* el caracter del registro de dato del UART4 es guardado en t4 */
		char t4 = UART4->DR; 

		/*Checa si el caracter recibido no es el EOL del UART4
		 * o si la longitud máxima para el string se ha alcanzado
		 */
		if( (t4 != EOL_UART4) && (cnt4 < MAX_STRLEN) ){
			received_string[cnt4] = t4;
			cnt4++;
		}
		else{ 
			/* resetea el contador del caracter e imprime el string recibido, a su vez lo envia al callback */
			cnt4 = 0;
			osThreadUSART3Callback(received_string);
			memset(received_string, 0, sizeof(received_string ));
		}
	}
}

/**
  * @brief  Handler del UART5 (Mensage recibido )
  * @param  None
  * @retval None
  */
void UART5_IRQHandler(void){

	//Checa si el flag de interrupcion del UART5 se activo
	if( USART_GetITStatus(UART5, USART_IT_RXNE) ){

		/* Este contador es usado para determinar la longitud del string */
		static uint8_t cnt5 = 0; 
		/* el caracter del registro de dato del USARTx es guardado en t5 */
		char t5 = UART5->DR; 

		/*Checa si el caracter recibido no es el EOL del UART5
		 * o si la longitud máxima para el string se ha alcanzado
		 */
		if( (t5 != EOL_UART5) && (cnt5 < MAX_STRLEN) ){
			received_string[cnt5] = t5;
			cnt5++;
		}
		else{ 
			/* resetea el contador del caracter e imprime el string recibido, a su vez lo envia al callback */
			cnt5 = 0;
			//OS_USART_CALLBACK(received_string);
			memset(received_string, 0, sizeof(received_string ));
		}
	}
}

/**
  * @brief  Handler del USART6 (Mensage recibido )
  * @param  None
  * @retval None
  */
void USART6_IRQHandler(void){

	/* Checa si el flag de interrupcion del USART6 se activo */
	if( USART_GetITStatus(USART6, USART_IT_RXNE) ){

		/* Este contador es usado para determinar la longitud del string */
		static uint8_t cnt6 = 0;                                   
		/* el caracter del registro de dato del USARTx es guardado en t6 */
		char t6 = USART6->DR;                                      

		/*Checa si el caracter recibido no es el EOL del USARTx
		 * o si la longitud máxima para el string se ha alcanzado
		 */
		if( (t6 != EOL_USART6) && (cnt6 < MAX_STRLEN) ){
			received_string[cnt6] = t6;
			cnt6++;
		}
		else{                                                     
			/* resetea el contador del caracter e imprime el string recibido, a su vez lo envia al callback */
			cnt6 = 0;
			//OS_USART_CALLBACK(received_string);
			memset(received_string, 0, sizeof(received_string ));
		}
	}
}

/*******************************************************************************************/
/*************************   INTERRUPCIONES DE CANBUS **************************************/
/*******************************************************************************************/

/**
  * @brief  Esta funcion maneja el mensage de entrada CanBUS1
  * @param  None
  * @retval None
  */
void CAN1_RX0_IRQHandler(void)
{
	/* Definicion tipo de mensage canBUS */
	CanRxMsg RxMessage;
	
	/* Limpieza de valores para recibir nuevos del bus */
	RxMessage.StdId = 0x00;    // ID Standar
	RxMessage.ExtId = 0x00;    // ID Extendido
	RxMessage.IDE = 0;
	RxMessage.DLC = 0;         // Longitud del mensage
	RxMessage.FMI = 0;
	RxMessage.Data[0] = 0x00;  // Vaciado de valores al buffer Data
	RxMessage.Data[1] = 0x00;
	RxMessage.Data[2] = 0x00;
	RxMessage.Data[3] = 0x00;
	RxMessage.Data[4] = 0x00;
	RxMessage.Data[5] = 0x00;
	RxMessage.Data[6] = 0x00;
  RxMessage.Data[7] = 0x00;
	
	/* Recepcion de un nuevo mensaje canBUS */
	CAN_Receive(CAN1, CAN_FIFO0, &RxMessage);
	
	/* CALBACK del canBUS1 */
	if((RxMessage.StdId == CAN_FIFO_ID) || (RxMessage.StdId == 127) || (RxMessage.StdId == 255))
    osThreadCANBUS_CAN1_CALLBACK(&RxMessage);
	
	/* Se limpia el flag de interrupcion */
	CAN_ClearITPendingBit(CAN1,CAN_IT_FMP0);  
}

/**
  * @brief  Esta funcion maneja el mensage de entrada CanBUS 2
  * @param  None
  * @retval None
  */ 
void CAN2_RX0_IRQHandler(void)
{
	/* Definicion tipo de mensage canBUS */
	CanRxMsg RxMessage;
	
	/* Limpieza de valores para recibir nuevos del bus */
	RxMessage.StdId = 0x00;   // ID Standar
	RxMessage.ExtId = 0x00;   // ID Extendido
	RxMessage.IDE = 0;
	RxMessage.DLC = 0;        // Longitud del mensage
	RxMessage.FMI = 0;
	RxMessage.Data[0] = 0x00; // Vaciado de valores al buffer Data
	RxMessage.Data[1] = 0x00;
	RxMessage.Data[2] = 0x00;
	RxMessage.Data[3] = 0x00;
	RxMessage.Data[4] = 0x00;
	RxMessage.Data[5] = 0x00;
	RxMessage.Data[6] = 0x00;
  RxMessage.Data[7] = 0x00;

	/* Recepcion de un nuevo mensaje canBUS */
	CAN_Receive(CAN2, CAN_FIFO0, &RxMessage);
	
	/* CALBACK del canBUS2 */
	if((RxMessage.StdId == CAN_FIFO_ID) || (RxMessage.StdId == 127) || (RxMessage.StdId == 255))
    osThreadCANBUS_CAN2_CALLBACK(&RxMessage);
	
	/* Se limpia el flag de interrupcion */
	CAN_ClearITPendingBit(CAN2,CAN_IT_FMP0);  
}

/*******************************************************************************************/
/*************************   INTERRUPCIONES DE PUERTOS *************************************/
/*******************************************************************************************/

/**
* @brief  Configuracion de Interrupcion en Pin0
* @param  Ninguno
* @retval Ninguno
*/
void EXTI0_IRQHandler(void) {
    /* Se asegura que la bandera de interrupcion se activó */
    if (EXTI_GetITStatus(EXTI_Line0) != RESET) {
        
			  /* CALLBACK DE INTERRUPCION 0 */
        osUserThread_INT0CALLBACK();
        /* Se limpia la bandera de interrupcion */
        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}

/**
* @brief  Configuracion de Interrupcion en Pin1
* @param  Ninguno
* @retval Ninguno
*/
void EXTI1_IRQHandler(void) {
    /* Se asegura que la bandera de interrupcion se activó */
    if (EXTI_GetITStatus(EXTI_Line1) != RESET) {
        
			  /* CALLBACK DE INTERRUPCION 1 */
        osUserThread_INT1CALLBACK();
        /* Se limpia la bandera de interrupcion */
        EXTI_ClearITPendingBit(EXTI_Line1);
    }
}

/**
* @brief  Configuracion de Interrupcion en Pin2
* @param  Ninguno
* @retval Ninguno
*/
void EXTI2_IRQHandler(void) {
    /* Se asegura que la bandera de interrupcion se activó */
    if (EXTI_GetITStatus(EXTI_Line2) != RESET) {
        
			  /* CALLBACK DE INTERRUPCION 2 */
        osUserThread_INT2CALLBACK();
        /* Se limpia la bandera de interrupcion */
        EXTI_ClearITPendingBit(EXTI_Line2);
    }
}

/**
* @brief  Configuracion de Interrupcion en Pin0
* @param  Ninguno
* @retval Ninguno
*/
void EXTI3_IRQHandler(void) {
    /* Se asegura que la bandera de interrupcion se activó */
    if (EXTI_GetITStatus(EXTI_Line3) != RESET) {
        
			  /* CALLBACK DE INTERRUPCION 3 */
        osUserThread_INT3CALLBACK();
        /* Se limpia la bandera de interrupcion */
        EXTI_ClearITPendingBit(EXTI_Line3);
    }
}

/**
* @brief  Configuracion de Interrupcion en Pin4
* @param  Ninguno
* @retval Ninguno
*/
void EXTI4_IRQHandler(void) {
    /* Se asegura que la bandera de interrupcion se activó */
    if (EXTI_GetITStatus(EXTI_Line4) != RESET) {
        
			  /* CALLBACK DE INTERRUPCION 4 */
        osUserThread_INT4CALLBACK();
        /* Se limpia la bandera de interrupcion */
        EXTI_ClearITPendingBit(EXTI_Line4);
    }
}

/**
* @brief  Configuracion de Interrupcion en Pin0
* @param  Ninguno
* @retval Ninguno
*/
void EXTI9_5_IRQHandler(void) {
    /* Se asegura que la bandera de interrupcion se activó */
    if (EXTI_GetITStatus(EXTI_Line5) != RESET) {
        
			  /* CALLBACK DE INTERRUPCION 5 */
        osUserThread_INT5CALLBACK();
        /* Se limpia la bandera de interrupcion */
        EXTI_ClearITPendingBit(EXTI_Line5);
    }
		
    /* Se asegura que la bandera de interrupcion se activó */
    if (EXTI_GetITStatus(EXTI_Line6) != RESET) {
        
			  /* CALLBACK DE INTERRUPCION 6 */
        osUserThread_INT6CALLBACK();
        /* Se limpia la bandera de interrupcion */
        EXTI_ClearITPendingBit(EXTI_Line6);
    }
		
    /* Se asegura que la bandera de interrupcion se activó */
    if (EXTI_GetITStatus(EXTI_Line7) != RESET) {
        
			  /* CALLBACK DE INTERRUPCION 7 */
        osUserThread_INT7CALLBACK();
        /* Se limpia la bandera de interrupcion */
        EXTI_ClearITPendingBit(EXTI_Line7);
    }
		
    /* Se asegura que la bandera de interrupcion se activó */
    if (EXTI_GetITStatus(EXTI_Line8) != RESET) {
        
			  /* CALLBACK DE INTERRUPCION 8 */
        osUserThread_INT8CALLBACK();
        /* Se limpia la bandera de interrupcion */
        EXTI_ClearITPendingBit(EXTI_Line8);
    }
		
    /* Se asegura que la bandera de interrupcion se activó */
    if (EXTI_GetITStatus(EXTI_Line9) != RESET) {
        
			  /* CALLBACK DE INTERRUPCION 9 */
        osUserThread_INT9CALLBACK();
        /* Se limpia la bandera de interrupcion */
        EXTI_ClearITPendingBit(EXTI_Line9);
    }
}

/**
* @brief  Configuracion de Interrupcion en Pin0
* @param  Ninguno
* @retval Ninguno
*/
void EXTI15_10_IRQHandler(void) {
    /* Se asegura que la bandera de interrupcion se activó */
    if (EXTI_GetITStatus(EXTI_Line10) != RESET) {
        
			  /* CALLBACK DE INTERRUPCION 10 */
        osUserThread_INT10CALLBACK();
        /* Se limpia la bandera de interrupcion */
        EXTI_ClearITPendingBit(EXTI_Line10);
    }
		
    /* Se asegura que la bandera de interrupcion se activó */
    if (EXTI_GetITStatus(EXTI_Line11) != RESET) {
        
			  /* CALLBACK DE INTERRUPCION 11 */
        osUserThread_INT11CALLBACK();
        /* Se limpia la bandera de interrupcion */
        EXTI_ClearITPendingBit(EXTI_Line11);
    }
		
    /* Se asegura que la bandera de interrupcion se activó */
    if (EXTI_GetITStatus(EXTI_Line12) != RESET) {
        
			  /* CALLBACK DE INTERRUPCION 12 */
        osUserThread_INT12CALLBACK();
        /* Se limpia la bandera de interrupcion */
        EXTI_ClearITPendingBit(EXTI_Line12);
    }
		
    /* Se asegura que la bandera de interrupcion se activó */
    if (EXTI_GetITStatus(EXTI_Line13) != RESET) {
        
			  /* CALLBACK DE INTERRUPCION 13 */
        osUserThread_INT13CALLBACK();
        /* Se limpia la bandera de interrupcion */
        EXTI_ClearITPendingBit(EXTI_Line13);
    }
		
    /* Se asegura que la bandera de interrupcion se activó */
    if (EXTI_GetITStatus(EXTI_Line14) != RESET) {
        
			  /* CALLBACK DE INTERRUPCION 14 */
        osUserThread_INT14CALLBACK();
        /* Se limpia la bandera de interrupcion */
        EXTI_ClearITPendingBit(EXTI_Line14);
    }
		
    /* Se asegura que la bandera de interrupcion se activó */
    if (EXTI_GetITStatus(EXTI_Line15) != RESET) {
        
			  /* CALLBACK DE INTERRUPCION 15 */
        osUserThread_INT15CALLBACK();
        /* Se limpia la bandera de interrupcion */
        EXTI_ClearITPendingBit(EXTI_Line15);
    }
}

/**
* @brief  Handler del Timer 2
* @param  Ninguno
* @retval Ninguno
*/
void TIM2_IRQHandler()
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET){
			     
			/* Se limpia el flag de interrupcion */
			 TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
			
			/* Constructor de mensaje canBUS */
		  osTreadCanBus_Sender(CAN1,TAB_TRASERO,REINICIAR_SEL,NO_ACTIVE,0,0,0,0,0);
		  osTreadCanBus_Sender(CAN1,TAB_TRASERO,DETENER_SEL,NO_ACTIVE,0,0,0,0,0);
		  osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESTRIBO_FUERA_SEL,NO_ACTIVE,0,0,0,0,0);
		  osTreadCanBus_Sender(CAN1,TAB_TRASERO,ESTRIBO_DENTRO_SEL,NO_ACTIVE,0,0,0,0,0);
		
	    /* Envío al Bluetooth */
	    osThreadCC_USART_CONTROL(REINICIAR_SEL,NO_ACTIVE);
	    osThreadCC_USART_CONTROL(DETENER_SEL,NO_ACTIVE);
	    osThreadCC_USART_CONTROL(ESTRIBO_FUERA_SEL,NO_ACTIVE);
	    osThreadCC_USART_CONTROL(ESTRIBO_DENTRO_SEL,NO_ACTIVE);
			
			/* Se deshabilita el timer */
       TIM_Cmd(TIM2, DISABLE);
	     TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);
			
		}
}

/**
* @brief  Handler del Timer 3
* @param  Ninguno
* @retval Ninguno
*/

void TIM3_IRQHandler()
{
    if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET){
		 
			Counter++;
			
			if(Counter == 1){
				if (TAB_CC1.PWM_BUFFER[2] == ACTIVE) GPIO_SetBits(DIR2);
				if (TAB_CC1.PWM_BUFFER[3] == ACTIVE) GPIO_SetBits(DIR3);
				if (TAB_CC1.PWM_BUFFER[4] == ACTIVE) GPIO_SetBits(DIR4);
				if (TAB_CC1.PWM_BUFFER[5] == ACTIVE) GPIO_SetBits(DIR5);
				if (TAB_CC1.PWM_BUFFER[6] == ACTIVE) GPIO_SetBits(DIR6);
				if (TAB_CC1.PWM_BUFFER[7] == ACTIVE) GPIO_SetBits(DIR7);
				if (TAB_CC1.PWM_BUFFER[8] == ACTIVE) GPIO_SetBits(DIR8);
				if (TAB_CC1.PWM_BUFFER[9] == ACTIVE) GPIO_SetBits(DIR9);
			}
			else if(Counter == TAB_CC1.LED_INTENSITY){
				if (TAB_CC1.PWM_BUFFER[2] == ACTIVE) GPIO_ResetBits(DIR2);
				if (TAB_CC1.PWM_BUFFER[3] == ACTIVE) GPIO_ResetBits(DIR3);
				if (TAB_CC1.PWM_BUFFER[4] == ACTIVE) GPIO_ResetBits(DIR4);
				if (TAB_CC1.PWM_BUFFER[5] == ACTIVE) GPIO_ResetBits(DIR5);
				if (TAB_CC1.PWM_BUFFER[6] == ACTIVE) GPIO_ResetBits(DIR6);
				if (TAB_CC1.PWM_BUFFER[7] == ACTIVE) GPIO_ResetBits(DIR7);
				if (TAB_CC1.PWM_BUFFER[8] == ACTIVE) GPIO_ResetBits(DIR8);
				if (TAB_CC1.PWM_BUFFER[9] == ACTIVE) GPIO_ResetBits(DIR9);
			}
			else if(Counter>=100){
				Counter = 0;
			}
			/* Se limpia el flag de interrupcion */
			 TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
			
		}
}

/**
* @brief  Handler del Timer 4
* @param  Ninguno
* @retval Ninguno
*/
void TIM4_IRQHandler()
{
    if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET){

			/* Se limpia el flag de interrupcion */
			 TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
			
			/* Se activa bandera de cambio */
			TAB_CC1.EFECTO_SEG = ACTIVE;
			
		}
}

/**
* @brief  Handler del Timer 5
* @param  Ninguno
* @retval Ninguno
*/
void TIM5_IRQHandler()
{
    if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)
    {
        TIM_ClearITPendingBit(TIM5, TIM_IT_Update);
			
			  /* Incremento de variable de control */
			  TAB_CC1.Emergency_state--;
			
			  /* Variable de estado interrupcion activa */
			  TAB_CC1.Emergency_Seg = ACTIVE;

		}
}

/**
* @brief  Handler del Timer 6
* @param  Ninguno
* @retval Ninguno
*/
void TIM6_DAC_IRQHandler()
{
    if (TIM_GetITStatus(TIM6, TIM_IT_Update) != RESET)
    {

		}
}

/**
* @brief  Handler del Timer 7
* @param  Ninguno
* @retval Ninguno
*/
void TIM7_IRQHandler()
{
    if (TIM_GetITStatus(TIM7, TIM_IT_Update) != RESET)
    {
        TIM_ClearITPendingBit(TIM7, TIM_IT_Update);
			
			  /* Se envia la peticion de cambio a la puerta */
			  osThreadCC_LUZ_PUERTA_SEL(TOGGLE);
			
		}
}

/**
* @brief  Handler del Timer 9
* @param  Ninguno
* @retval Ninguno
*/
void TIM1_BRK_TIM9_IRQHandler()
{
    if (TIM_GetITStatus(TIM9, TIM_IT_Update) != RESET)
    {
      TIM_ClearITPendingBit(TIM9, TIM_IT_Update);
			
		}
}

/**
* @brief  Handler del Timer 10
* @param  Ninguno
* @retval Ninguno
*/
void TIM1_UP_TIM10_IRQHandler()
{
    if (TIM_GetITStatus(TIM10, TIM_IT_Update) != RESET)
    {
      TIM_ClearITPendingBit(TIM10, TIM_IT_Update);
			
		}
		
		if (TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET)
    {
      TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
		}
} 
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
