/**
  ******************************************************************************
  * @archivo  Conf
  * @autor    EDESIGN TEAM
  * @version  V1.0.0
  * @fecha    12-Febrero-2015
  * @brief    Archivo de configuracion e inicialización de configuraciones
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
#ifndef __OSTHREADCANBUS_H
#define __OSTHREADCANBUS_H

/* Includes  ------------------------------------------------------------------*/
#include "osThreadDefines.h"

/* Definiciones del canBUS  ---------------------------------------------------*/

#define CAN_FIFO_ID                TAB_CC
#define CAN_FIFO                   CAN_FIFO0
#define CAN_FIFO_IN                CAN_IT_FMP0

/** @addtogroup Prototipo de Funciones
  * @{
  */
	
  	void osThreadCANBUSInit(uint32_t os_CANBUS,uint32_t PinsPack);  
	  void osThreadCANBUS_TxMessage(CAN_TypeDef* CANBUSx, uint8_t ID,  
    uint8_t DAT0,uint8_t DAT1,uint8_t DAT2,uint8_t DAT3,uint8_t DAT4,   
    uint8_t DAT5,uint8_t DAT6,uint8_t DAT7);
		void osThreadCANBUS_CAN1_CALLBACK(CanRxMsg* RxMessage);
		void osThreadCANBUS_CAN2_CALLBACK(CanRxMsg* RxMessage);
		
		void osTreadCanBus_Sender(CAN_TypeDef* CANx,uint32_t ID_RECV, 
    uint32_t Button, uint32_t AC_State, uint32_t SpecialFunc,
    uint32_t SF_State, uint32_t InternalCom,uint32_t Int_Code,  
    uint32_t Error );
		
		void osThreadCANBUS_CAN1_StdFunc(uint32_t DATA1, uint32_t DATA2,uint32_t SENDER);
    void osThreadCANBUS_CAN1_SpecialFunc(uint32_t DATA1, uint32_t DATA2,uint32_t SENDER);
    void osThreadCANBUS_CAN1_InternalCom(uint32_t DATA1, uint32_t DATA2,uint32_t SENDER);
    void osThreadCANBUS_CAN1_Error(uint32_t DATA1,uint32_t SENDER);	
		
		void osThreadCANBUS_CAN1_CAN2_BRIDGE(CanRxMsg* RxMessage,uint32_t SENDER);
		
		void osThreadCANBUS_CAN2_StdFunc(uint32_t DATA1, uint32_t DATA2,uint32_t SENDER);
    void osThreadCANBUS_CAN2_SpecialFunc(uint32_t DATA1, uint32_t DATA2,uint32_t SENDER);
    void osThreadCANBUS_CAN2_InternalCom(uint32_t DATA1, uint32_t DATA2,uint32_t SENDER);
    void osThreadCANBUS_CAN2_Error(uint32_t DATA1,uint32_t SENDER);	
		
		void osThreadCANBUS_CAN2_CAN1_BRIDGE(CanRxMsg* RxMessage,uint32_t SENDER);
		
		
/** @endofgroup Prototipo de Funciones
  * @}
  */    	
	
#endif /* __OSTHREADCANBUS_H */
