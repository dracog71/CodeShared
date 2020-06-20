/**
  ******************************************************************************
  * @file    canBUS.c
  * @author  EDESIGN Team
  * @version V1.0
  * @date    18-Agosto-2015
  * @brief   Configuracion de perifericos     
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
  **/
/* Include------------------------------------------------------------------*/
#include "osThreadCANBUS.h"
	
  CAN_InitTypeDef       CAN_InitStructure;
	CAN_FilterInitTypeDef CAN_FilterInitStructure;
	
/* Estructura de control del Centro de Carga */
extern TAB_CC_STRUCT TAB_CC1;
	
/**
  * @brief  Inicializacion del CANBUS
  * @param  Ninguno
  * @retval Ninguno
  */
		
		void osThreadCANBUSInit(
	  uint32_t os_CANBUS,  /* Definicion tipo CANBUS a la que se aplicará la configuracion */
    uint32_t PinsPack   /* Definicion tipo GPIO Rx/Tx del CANBUS a configurar */
  ){
		
		NVIC_InitTypeDef      NVIC_InitStructure;
	  CAN_TypeDef* CANBUSx;
	  uint8_t NVIC_IRQChannel;

		/* Cambio de variable entre integer a definicion tipo CanBUS */
		switch(os_CANBUS)
		 {
			 case os_CANBUS1:
				 osThreadGPIOInitFunc(os_CANBUS1,PinsPack);            /* Configuracion de pines para canBUS */
			   CANBUSx = CAN1;                                       /* Se define el periferico a configurar */
			   NVIC_IRQChannel = CAN1_RX0_IRQn;                      /* Se define el nombre del handler de interrupcion */ 
			   RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);  /* Se habilita el reloj del canBUS */
			   CAN_FilterInitStructure.CAN_FilterNumber         = 13; 
			   break;
			 
			 case os_CANBUS2:
				 osThreadGPIOInitFunc(os_CANBUS2,PinsPack);            /* Configuracion de pines para canBUS */
			   CANBUSx = CAN2;                                       /* Se define el periferico a configurar */
			   NVIC_IRQChannel = CAN2_RX0_IRQn;                      /* Se define el nombre del handler de interrupcion */ 
			   RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN2, ENABLE);  /* Se habilita el reloj del canBUS */
			   CAN_FilterInitStructure.CAN_FilterNumber         = 27; 
			   break;

		 }
		
  
  CAN_DeInit(CANBUSx);                           /* CANBUSx reset */

  CAN_InitStructure.CAN_TTCM = DISABLE;         /* Modo de comunicacion por disparo de tiempo = DESHABILITADO */
  CAN_InitStructure.CAN_ABOM = DISABLE;         /* Manejo de auto-apagado autmatico = DESHABILITADO           */
  CAN_InitStructure.CAN_AWUM = DISABLE;         /* Modo de auto-encendido = DESHABILITADO                     */
  CAN_InitStructure.CAN_NART = DISABLE;         /* Modo de retransmicion non-automatic = DESHABILITADO        */
  CAN_InitStructure.CAN_RFLM = DISABLE;          /* Modo bloqueado del FIFO CanMsgReceive  = DESHABILITADO     */ 
  CAN_InitStructure.CAN_TXFP = DISABLE;          /* Prioridad FIFO de transmicion = DESHABILITADO              */
  CAN_InitStructure.CAN_Mode = CAN_Mode_Normal; /* CAN_Mode_Normal                                            */
  CAN_InitStructure.CAN_SJW  = CAN_SJW_1tq;     /* ancho de salto de sincronizacion = 1                       */
  CAN_InitStructure.CAN_BS1  = CAN_BS1_14tq;    /* 14                                                         */ 
  CAN_InitStructure.CAN_BS2  = CAN_BS2_6tq;     /* 6                                                          */
  CAN_InitStructure.CAN_Prescaler=CANBUS_Prescaler;            /* osThreadDefines */   
		 
	/* Inicializacion del Canbus */	 
  CAN_Init(CANBUSx, &CAN_InitStructure);
 
  CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_FIFO;
  CAN_FilterInitStructure.CAN_FilterMode           = CAN_FilterMode_IdMask;
  CAN_FilterInitStructure.CAN_FilterScale          = CAN_FilterScale_16bit;
  CAN_FilterInitStructure.CAN_FilterIdHigh         = 0x0000;
  CAN_FilterInitStructure.CAN_FilterIdLow          = 0x0000;
  CAN_FilterInitStructure.CAN_FilterMaskIdHigh     = 0x0000;
  CAN_FilterInitStructure.CAN_FilterMaskIdLow      = 0x0000;
  CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_FIFO_ID;
  CAN_FilterInitStructure.CAN_FilterActivation     = ENABLE;
  CAN_FilterInit(&CAN_FilterInitStructure);	
	
  NVIC_InitStructure.NVIC_IRQChannel = NVIC_IRQChannel;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 255;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	//FIFO Interrupcion de mensaje pendiente 
	CAN_ITConfig(CANBUSx, CAN_IT_FMP0, ENABLE);
	CAN_ITConfig(CANBUSx, CAN_IT_FMP1, ENABLE);
	//FIFO Interrupcion completa
	CAN_ITConfig(CANBUSx, CAN_IT_FF0, ENABLE);
	CAN_ITConfig(CANBUSx, CAN_IT_FF1, ENABLE);
	//FIFO  Interrupcion de overrun 
	CAN_ITConfig(CANBUSx, CAN_IT_FOV0, ENABLE);
	CAN_ITConfig(CANBUSx, CAN_IT_FOV1, ENABLE);	
}	

/**
  * @brief  Inicializacion del CANBUS
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadCANBUS_TxMessage(CAN_TypeDef* CANBUSx, uint8_t ID,
                             	uint8_t DAT0,
															uint8_t DAT1, 
															uint8_t DAT2,
															uint8_t DAT3,
															uint8_t DAT4,
															uint8_t DAT5,
															uint8_t DAT6,
															uint8_t DAT7)
{
	uint8_t TransmitMailbox = 0;
	uint8_t lastError4 = CAN_GetLastErrorCode(CAN1);
  CanTxMsg TxMessage;
	uint32_t i = 0;

  /* Mensage CAN a ser enviado*/
  TxMessage.StdId = ID;
  TxMessage.ExtId = 0x00;
  TxMessage.RTR = CAN_RTR_DATA;
  TxMessage.IDE = CAN_ID_STD;
  TxMessage.DLC = 8;
  TxMessage.Data[0] = DAT0;
	TxMessage.Data[1] = DAT1;
	TxMessage.Data[2] = DAT2;
	TxMessage.Data[3] = DAT3;
	TxMessage.Data[4] = DAT4;
	TxMessage.Data[5] = DAT5;
	TxMessage.Data[6] = DAT6;
	TxMessage.Data[7] = DAT7;

  TransmitMailbox = CAN_Transmit(CANBUSx, &TxMessage);

	while ((CAN_TransmitStatus(CANBUSx, TransmitMailbox) != CANTXOK) && (i != 0xFFFF)) i++;
}

/**
  * @brief  Constructor de la cadena de envio CANBUS
  * @param  None
  * @retval None
  */
void osTreadCanBus_Sender(CAN_TypeDef* CANx,    // Definicion tipo de CANBUS 
	                        uint32_t ID_RECV,     // ID de recepcion  
                          uint32_t Button,      // ID del Botón a enviar
                          uint32_t AC_State,       // Valor del estado 
                          uint32_t SpecialFunc, // ID de la Funcion especial 
                          uint32_t SF_State,       // Estado de la funcion especial
                          uint32_t InternalCom, // ID de Comunicacion interna
                          uint32_t Int_Code,    // Codigo de comunicacion interna
                          uint32_t Error        // ID del error
                          ){
														
  /* Constructor de cadena completa entre el sistema  */
	osThreadCANBUS_TxMessage(CANx,ID_RECV,Button,AC_State,SpecialFunc,SF_State,InternalCom,Int_Code,Error,CAN_FIFO_ID);

	/* Thread de mensaje recibido exitosamente */
	mainDelay(5000);					
}
													
/**
  * @brief  Handler de recepcion de CanBUS
  * @param  None
  * @retval None
  */
void osThreadCANBUS_CAN1_CALLBACK(CanRxMsg* RxMessage){
 
	printf("Valores de recepcion CAN 1 ID = %d Dato recibido %d %d %d %d %d %d ",RxMessage->StdId, RxMessage->Data[0], RxMessage->Data[1], RxMessage->Data[2], RxMessage->Data[3],RxMessage->Data[4], RxMessage->Data[5]);
	printf("Sender = %d\r\n ",RxMessage->Data[7]);
	
	/* Manejo de funciones Estandar */
	if ((RxMessage->Data[0] > 0) && (RxMessage->StdId == CAN_FIFO_ID))
	    osThreadCANBUS_CAN1_StdFunc(RxMessage->Data[0],RxMessage->Data[1],RxMessage->Data[7]);

	/* Manejo de Funciones Especiales */
	if ((RxMessage->Data[2] > 0) && (RxMessage->StdId == CAN_FIFO_ID))
	    osThreadCANBUS_CAN1_SpecialFunc(RxMessage->Data[2],RxMessage->Data[3],RxMessage->Data[7]);
			
	/* Manejo de comunicaciones internas */
	if ((RxMessage->Data[4] > 0) && (RxMessage->StdId == CAN_FIFO_ID))
	    osThreadCANBUS_CAN1_InternalCom(RxMessage->Data[4],RxMessage->Data[5],RxMessage->Data[7]); 
			
	/* Manejo de errores */
	if ((RxMessage->Data[6] > 0) && (RxMessage->StdId == CAN_FIFO_ID))
	    osThreadCANBUS_CAN1_Error(RxMessage->Data[6],RxMessage->Data[7]); 
	
	/* Bridge entre CAN1 y CAN2*/
	if (RxMessage->StdId ==127 )
	    osThreadCANBUS_CAN1_CAN2_BRIDGE(RxMessage,RxMessage->Data[7]); 
}


/**
  * @brief  Handler de recepcion de CanBUS Funciones Estandar
  * @param  None
  * @retval None
  */
void osThreadCANBUS_CAN1_StdFunc(uint32_t DATA1, uint32_t DATA2,uint32_t SENDER){
	/* Se tranfiere la imagen a mostrar en el LCD */
	TAB_CC1.NEW_DATA   = ACTIVE ;
	TAB_CC1.CARRIER    = DATA1;
	TAB_CC1.STATUS     = DATA2;
	TAB_CC1.CAN_SENDER = SENDER;
	
}
/**
  * @brief  Handler de recepcion de CanBUS Funciones Especiales
  * @param  None
  * @retval None
  */
void osThreadCANBUS_CAN1_SpecialFunc(uint32_t DATA1, uint32_t DATA2,uint32_t SENDER){

}
/**
  * @brief  Handler de recepcion de CanBUS Comunicacion Interna
  * @param  None
  * @retval None
  */
void osThreadCANBUS_CAN1_InternalCom(uint32_t DATA1, uint32_t DATA2,uint32_t SENDER){

	/* Detecta si TEST o DIRECCIONADOR responde */
	switch(DATA1){
		case ASK_ONLINE:
			if(DATA2 == ACTIVE){
				if(SENDER == TAB_TEST)
		      TAB_CC1.TESTER_ACTIVE = ACTIVE; 
				
				if(SENDER == TAB_CRONOMETRO)
		      TAB_CC1.CRONOMETRO_ACTIVE = ACTIVE; 
				
				if(SENDER == TAB_SIRENA)
		      TAB_CC1.SIREN_ACTIVE = ACTIVE;  
			}
			break;
		
		default:
			break;
	}
}
/**
  * @brief  Handler de recepcion de CanBUS Manejo de Errores internos
  * @param  None
  * @retval None
  */
void osThreadCANBUS_CAN1_Error(uint32_t DATA1,uint32_t SENDER){
	
}

/**
  * @brief  Puente entre CAN1 y CAN2
  * @param  None
  * @retval None
  */
void osThreadCANBUS_CAN1_CAN2_BRIDGE(CanRxMsg* RxMessage,uint32_t SENDER){
	
	/* Transferencia del Buffer del CN1 al CAN2 */
	osTreadCanBus_Sender(CAN2,6,RxMessage->Data[0],RxMessage->Data[1],RxMessage->Data[2] ,RxMessage->Data[3]
	,RxMessage->Data[4],RxMessage->Data[5],SENDER);
}

/**
  * @brief  Encendido de los niveles de emergencia
  * @param  None
  * @retval None
  */
void osThreadCANBUS1_EmergecyLevel(uint32_t LEVEL, uint32_t STATE){
	
}

/**
  * @brief  Handler de recepcion de CanBUS
  * @param  None
  * @retval None
  */
void osThreadCANBUS_CAN2_CALLBACK(CanRxMsg* RxMessage){
 
	printf("Valores de recepcion CAN 2 ID = %d Dato recibido %d %d %d %d %d %d ",RxMessage->StdId, RxMessage->Data[0], RxMessage->Data[1], RxMessage->Data[2], RxMessage->Data[3],RxMessage->Data[4], RxMessage->Data[5]);
	printf("Sender = %d\r\n ",RxMessage->Data[7]);
	
	/* Manejo de funciones Estandar */
	if ((RxMessage->Data[0] > 0) && (RxMessage->StdId == CAN_FIFO_ID))
	    osThreadCANBUS_CAN2_StdFunc(RxMessage->Data[0],RxMessage->Data[1],RxMessage->Data[7]);

	/* Manejo de Funciones Especiales */
	if ((RxMessage->Data[2] > 0) && (RxMessage->StdId == CAN_FIFO_ID))
	    osThreadCANBUS_CAN2_SpecialFunc(RxMessage->Data[2],RxMessage->Data[3],RxMessage->Data[7]);
			
	/* Manejo de comunicaciones internas */
	if ((RxMessage->Data[4] > 0) && (RxMessage->StdId == CAN_FIFO_ID))
	    osThreadCANBUS_CAN2_InternalCom(RxMessage->Data[4],RxMessage->Data[5],RxMessage->Data[7]); 
			
	/* Manejo de errores */
	if ((RxMessage->Data[6] > 0) && (RxMessage->StdId == CAN_FIFO_ID))
	    osThreadCANBUS_CAN2_Error(RxMessage->Data[6],RxMessage->Data[7]); 
	
	/* Bridge entre CAN1 y CAN2*/
	if (RxMessage->StdId ==127 )
	    osThreadCANBUS_CAN2_CAN1_BRIDGE(RxMessage,RxMessage->Data[6]); 
}

/**
  * @brief  Handler de recepcion de CanBUS Funciones Estandar
  * @param  None
  * @retval None
  */
void osThreadCANBUS_CAN2_StdFunc(uint32_t DATA1, uint32_t DATA2,uint32_t SENDER){	
		/* Se tranfiere la imagen a mostrar en el LCD */
	TAB_CC1.NEW_DATA = ACTIVE ;
	TAB_CC1.CARRIER  = DATA1;
	TAB_CC1.STATUS   = DATA2;

}
/**
  * @brief  Handler de recepcion de CanBUS Funciones Especiales
  * @param  None
  * @retval None
  */
void osThreadCANBUS_CAN2_SpecialFunc(uint32_t DATA1, uint32_t DATA2,uint32_t SENDER){
	
}
/**
  * @brief  Handler de recepcion de CanBUS Comunicacion Interna
  * @param  None
  * @retval None
  */
void osThreadCANBUS_CAN2_InternalCom(uint32_t DATA1, uint32_t DATA2,uint32_t SENDER){

	/* Detecta si TEST o DIRECCIONADOR responde */
	switch(DATA1){
		case ASK_ONLINE:
			if(DATA2 == ACTIVE)
			  TAB_CC1.DIRECCIONADOR_ACT = ACTIVE;
			break;
		
		default:
			break;
	}
}
/**
  * @brief  Handler de recepcion de CanBUS Manejo de Errores internos
  * @param  None
  * @retval None
  */
void osThreadCANBUS_CAN2_Error(uint32_t DATA1,uint32_t SENDER){
	
}

/**
  * @brief  Puente entre CAN1 y CAN2
  * @param  None
  * @retval None
  */
void osThreadCANBUS_CAN2_CAN1_BRIDGE(CanRxMsg* RxMessage,uint32_t SENDER){
	
	/* Transferencia del Buffer del CN1 al CAN2 */
	osTreadCanBus_Sender(CAN1,SENDER,RxMessage->Data[0],RxMessage->Data[1],RxMessage->Data[2] ,RxMessage->Data[3]
	,RxMessage->Data[4],RxMessage->Data[5],SENDER);
}

/******************* (C) COPYRIGHT 2015 EDESIGN *****FIN DE ARCHIVO****/
