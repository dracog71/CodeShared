/**
  ******************************************************************************
  * @archivo  CanBus
  * @autor    EDESIGN TEAM
  * @version  V1.0.0
  * @fecha    28-Mayo-2015
  * @brief    Archivo de configuracion e inicialización de CanBus
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
	
	/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __as1107_H
#define __as1107_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include <stm32f4xx_spi.h>
#include "stm32f4xx_can.h"
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_gpio.h"

/* Definiciones del display  */
#define AS1107_Dig0_Address 0x01
#define AS1107_Dig1_Address 0x02
#define AS1107_Dig2_Address 0x03
#define AS1107_Dig3_Address 0x04
#define AS1107_Dig4_Address 0x05
#define AS1107_Dig5_Address 0x06
#define AS1107_Dig6_Address 0x07
#define AS1107_Dig7_Address 0x08
#define AS1107_DecodeMode_Address 0x09
#define AS1107_Intensity_Address 0x0A
#define AS1107_ScanLimit_Address 0x0B
#define AS1107_Direccion_Apagado 0x0C
#define AS1107_Feature_Address 0x0E
#define AS1107_Direccion_DisplayTest 0x0F

#define AS1107_DispTest_Normal 0x00
#define AS1107_DispTest_Test 0x01
#define AS1107_Intensity_Max 0x0F
#define AS1107_ScanLimit_Disp0 0x00
#define AS1107_Shutdown_ShutReset 0x00
#define AS1107_Shutdown_ShutRemain 0x80
#define AS1107_Shutdown_NormalReset 0x01
#define AS1107_Shutdown_NormalRemain 0x81

#define SPI1_NSS_High GPIO_SetBits(GPIOA,GPIO_Pin_4);
#define SPI1_NSS_Low GPIO_ResetBits(GPIOA,GPIO_Pin_4);
/*#define SPI1_NSS_High2 GPIO_SetBits(GPIOA,GPIO_Pin_1);
#define SPI1_NSS_Low2 GPIO_ResetBits(GPIOA,GPIO_Pin_1);*/

/* Macro exportadas ------------------------------------------------------------*/
/*Funciones exportadas ------------------------------------------------------- */

void osThreadAS1107_Init (void);
void osThreadAS1107_Config(void);
void osThreadAS1107_Delay(u32 nCount);
void osThreadAS1107_Send(uint8_t addr, uint8_t data);

#endif /* __as1107_H */

/******************* (C) COPYRIGHT 2015 EDESIGN *****FIN DE ARCHIVO****/
