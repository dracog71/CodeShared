/**
  ******************************************************************************
  * @file    OSTHREADUSART.c
  * @author  EDESIGN TEAM
  * @version V1.3.0        
  * @date    24-Febrero-2015
  * @brief   ________________________________________________________________
  *          ________________________________________________________________ 
  ****************************************************************************** 
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */
	
/* Incluside------------------------------------------------------------------*/
#include "OsThreadUSART.h"

/* Definicion tipo */	
USART_InitTypeDef USART_InitStruct; 

/* Estructura para valores de tablero delantero */
extern TAB_TRA_STRUCT TAB_TRA;
	
/**
  * @brief  Inicializacion usart
  * @param  
  * @retval 
  */
void osThreadUSARTInit(
	uint32_t os_USART,                /* Definicion tipo USART a la que se aplicará la configuracion */
  uint32_t Baudrate,uint32_t PinsPack   /* Definicion tipo GPIO Rx/Tx del USART a configurar */
  ){
	
	NVIC_InitTypeDef NVIC_InitStructure;	
	USART_TypeDef* USARTx;	
  uint8_t NVIC_IRQChannel;  
		
		 switch(os_USART)
		 {
			 case os_USART1:
				 RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); //Habilita el reloj APB2 para la USART1
				 osThreadGPIOInitFunc(os_USART1,PinsPack);              //Inicializa pines para USART1
			   USARTx = USART1;                                       //Asigna USART correspondiente
			   NVIC_IRQChannel = USART1_IRQn;                         //
			   break;
			 
			 case os_USART2:
				 RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); //Habilita el reloj APB1 para la USART2
				 osThreadGPIOInitFunc(os_USART2,PinsPack);              //Inicializa pines para USART1
			   USARTx = USART2;                                       //Asigna USART correspondiente
			   NVIC_IRQChannel = USART2_IRQn;
			   break;
				
			 case os_USART3:
				 RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE); //Habilita el reloj APB1 para la USART3
				 osThreadGPIOInitFunc(os_USART3,PinsPack);              //Inicializa pines para USART1
			   USARTx = USART3;                                       //Asigna USART correspondiente
			   NVIC_IRQChannel = USART3_IRQn;
			   break;
				 
			 case os_USART4:
				 RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE); //Habilita el reloj APB1 para la USART4
				 osThreadGPIOInitFunc(os_USART4,PinsPack);             //Inicializa pines para USART1
			   USARTx = UART4;                                       //Asigna USART correspondiente
			   NVIC_IRQChannel = UART4_IRQn;
			   break;
					
			 case os_USART5:
				 RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE); //Habilita el reloj APB1 para la USART5
				 osThreadGPIOInitFunc(os_USART5,PinsPack);             //Inicializa pines para USART1
			   USARTx = UART5;                                       //Asigna USART correspondiente
			   NVIC_IRQChannel = UART5_IRQn;
			   break;
					 
			 case os_USART6:
				 RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);//Habilita el reloj APB2 para la USART6
				 osThreadGPIOInitFunc(os_USART6,PinsPack);//Inicializa pines para USART1
			   USARTx = USART6;//Asigna USART correspondiente
			   NVIC_IRQChannel = USART6_IRQn;
			   break;
		 }
			 
		USART_InitStruct.USART_BaudRate = Baudrate;				                           //Asigna Bautrate
	 	USART_InitStruct.USART_WordLength = USART_WordLength_8b;                     //
		USART_InitStruct.USART_StopBits = USART_StopBits_1;		                       //Bit de parada 1     
		USART_InitStruct.USART_Parity = USART_Parity_No;	                           //Sin bit de paridad
		USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //Sin contro de flujo
		USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;                 //Modo fullduplex
	  USART_Init(USARTx, &USART_InitStruct);				

    
	  USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE); /* Configuracion de la interrupcion USARTx */

	  NVIC_InitStructure.NVIC_IRQChannel = NVIC_IRQChannel;		
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 
	  NVIC_Init(&NVIC_InitStructure);		

	 
	  USART_Cmd(USARTx, ENABLE); /* Activacion del reloj USARTx */
	
}
	
/**
  * @brief  Envio de un dato HEX por USARTx
  * @param  Ninguno
  * @retval Ninguno
  */
void USART_HEX(
	USART_TypeDef* USARTx,   /* Definicion tipo de USART a enviar */ 
  uint16_t  DATA           /* Dato en hexadecimal a enviar (solo uno) */
  ){

		// Ciclo de espera hasta que el registro este vacio
		while( !(USARTx->SR & 0x00000040) );
		USART_SendData(USARTx, DATA);
		
}

/**
  * @brief  Envio de un dato ASCII por USART2
  * @param  Ninguno
  * @retval Ninguno
  */
void USART_puts(
	 USART_TypeDef* USARTx,   /* Definicion tipo del USART a enviar el dato */
   volatile char *s         /* Cadena de caracteres a enviar */
	 ){

	  while(*s){
		// wait until data register is empty
		     while( !(USARTx->SR & 0x00000040) );
		     USART_SendData(USARTx, *s);
		     *s++;
	       }
}

	 
/**
  * @}
  */

/**
  * @brief  Callback de USART
  * @param  Cadena de valores recibidos por usart
  * @retval 
  */
void osThreadUSART4Callback(
  char recibido[50]          /* string recibido por el usart*/
  ){
	
		/* Selector de comunicacion */
		uint32_t SWITCH[35];
		
		/* Reacondicionamiento de señal */
		SWITCH[0x00] = BUTTON20;
		SWITCH[0x01] = BUTTON16;
		SWITCH[0x02] = BUTTON12;
		SWITCH[0x03] = BUTTON8;
		SWITCH[0x04] = BUTTON4;
		SWITCH[0x05] = BUTTON18;
		SWITCH[0x06] = BUTTON14;
		SWITCH[0x07] = BUTTON10;
		SWITCH[0x08] = BUTTON6;
		SWITCH[0x09] = BUTTON2;
		SWITCH[0x10] = BUTTON19;
		SWITCH[0x11] = BUTTON15;
		SWITCH[0x12] = BUTTON11;
		SWITCH[0x13] = BUTTON7;
		SWITCH[0x14] = BUTTON3;
		SWITCH[0x15] = BUTTON17;
		SWITCH[0x16] = BUTTON13;
		SWITCH[0x17] = BUTTON9;
		SWITCH[0x18] = BUTTON5;
		SWITCH[0x19] = BUTTON1;
		SWITCH[0x20] = BUTTON21;
		SWITCH[0x21] = BUTTON22;
		SWITCH[0x22] = BUTTON23;
		
		//printf("ATMEL %d | %d | \r\n",SWITCH[recibido[0]],recibido[1]);	
		
	/* Transferencia de valores */
	TAB_TRA.USART_DATA    = SWITCH[recibido[0]];
	TAB_TRA.USART_CARRIER = (recibido[1] == 1)? ACTIVE: NO_ACTIVE;	
		
	/* Nuevo dato en espera */
	TAB_TRA.USART_STATUS  = ACTIVE;

}
	
/******************* (C) COPYRIGHT 2015 EDESIGN *****FIN DE ARCHIVO****/
