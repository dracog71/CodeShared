 /*
	******************************************************************************
  * @file    as1107.c
  * @author  EDESIGN TEAM
  * @version V1.3.0         modificado por JMLG para MDK-ARM V5.0
  * @date    28-Mayo-2015
  * @brief   Archivo de configuracion avanzada automatizada para USB.
  *          Este archivo contiene configuraciones para control USB definidos.
  *             
  * 1.  Este archivo provee de Funciones globales que configuran el CanBus
  *     las funciones de uso son:
  *      - USB_Start:    Configura todos los valores necesarios para activar el 
	*                      USB	
  *      - MensajeUSB:   Método de envío de caracteres ASCII	
	*     Ejemplo:  Inicializa el USB y envía el STRING "HOLA"      
	*                      USB_Start();
	*                      MensajeUSB("HOLA\r\n");	
  *=============================================================================      
  ****************************************************************************** 
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 EDESIGN</center></h2>
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

#include "osThreadDefines.h"
	
		/**
  * @brief  Variables de inicializacion .
  * @param  None
  * @retval None
*/
	
	uint16_t sendData;
  uint8_t Int = 0x00;
	
/**
  * @brief  Funcion de arranque AS1107.
  * @param  None
  * @retval None
*/

void osThreadAS1107_Init(){
		
		osThreadAS1107_Config();
		osThreadAS1107_Delay(300);
    osThreadAS1107_Send(AS1107_Direccion_Apagado,AS1107_Shutdown_NormalReset);
    osThreadAS1107_Delay(100);
    osThreadAS1107_Send(AS1107_Direccion_DisplayTest,AS1107_DispTest_Test);
    osThreadAS1107_Delay(0x3ffff);
    osThreadAS1107_Send(AS1107_Direccion_DisplayTest,AS1107_DispTest_Normal);
    osThreadAS1107_Send(0x0C,0x01); //Reset Normal
    osThreadAS1107_Send(0x09,0x00); //Tipo de envío 0xFF
    osThreadAS1107_Send(0x0A,0xFF);// intensidad 0x90
    osThreadAS1107_Send(0x0B,0x07); // limite de escaneo 0x07
    osThreadAS1107_Send(0x0E,0x04); //Feature 0x04->HEX 0x00->CODE-B
		
		osThreadAS1107_Send(0x01, 0x00);
		osThreadAS1107_Send(0x02, 0x00);
		osThreadAS1107_Send(0x03, 0x00);
		osThreadAS1107_Send(0x04, 0x00);
		osThreadAS1107_Send(0x05, 0x00);
		osThreadAS1107_Send(0x06, 0x00);
		osThreadAS1107_Send(0x07, 0x00);
		osThreadAS1107_Send(0x08, 0x00);
		
		/* Limpieza de Buffers de control */
		osThreadUSART_ClearBuffers();
		 
	}
	
/**
  * @brief  Funcion de Configuracion SPI.
  * @param  None
  * @retval None
*/
	
void osThreadAS1107_Config()
{
     SPI_InitTypeDef SPI_InitStructure;
		 GPIO_InitTypeDef GPIO_InitStructure;

     RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
     /* Configure SPI_MASTER pins: SCK and MOSI ---------------------------------*/
     /* Configure SCK and MOSI pins as Alternate Function Push Pull */
     GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
     GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
     GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
     GPIO_Init(GPIOA , &GPIO_InitStructure);
	
	   // connect SPI1 pins to SPI alternate function
	   GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
	   GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);
	   GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
	
	   RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE); 
     /* SPI_MASTER configuration ------------------------------------------------*/
     SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;;
     SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
     SPI_InitStructure.SPI_DataSize = SPI_DataSize_16b;
     SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
     SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
     SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
     SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2; //SPI_BaudRatePrescaler_4;
     SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
     SPI_InitStructure.SPI_CRCPolynomial = 7;
     SPI_Init(SPI1, &SPI_InitStructure);
     /* Enable SPI_MASTER TXE interrupt */
     //SPI_I2S_ITConfig(SPI_MASTER, SPI_I2S_IT_TXE, ENABLE);
     SPI_SSOutputCmd(SPI1, ENABLE);

     /*Configure PA.4(NSS)--------------------------------------------*/
     GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
     GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
     GPIO_Init(GPIOA, &GPIO_InitStructure);

     SPI_Cmd(SPI1,ENABLE);
}

	/**
  * @brief  Funcion de escritura  al AS1107.
  * @param  None
  * @retval None
*/
void osThreadAS1107_Send(uint8_t addr, uint8_t data)
{
     sendData =addr<<8 | data;
     SPI1_NSS_Low;
     SPI_I2S_SendData(SPI1,sendData);
     while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);
     osThreadAS1107_Delay(50);
     SPI1_NSS_High;
}

/**
  * @brief  Retardo de choque en comunicación.
  * @param  None
  * @retval None
*/

void osThreadAS1107_Delay(u32 nCount)
{	
     for(; nCount != 0; nCount--);
}




/******************* (C) COPYRIGHT 2015 EDESIGN *****FIN DE ARCHIVO****/
