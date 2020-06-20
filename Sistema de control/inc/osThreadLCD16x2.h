/**
  ******************************************************************************
  * @archivo  osThreadLCD16x2
  * @autor    EDESIGN TEAM
  * @version  V1.0.0
  * @fecha    11-Noviembre-2015
  * @brief    Archivo de configuracion e inicialización de USB
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


#ifndef _USB_H_
#define _USB_H_

/* Inclusiones------------------------------------------------------------------*/
#include "stm32f4xx.h"

/**********************  CONTROL  *********************************************/
#define LCD_RS                PC13   //  Register Select
#define LCD_RW                PA10   //  Read/Write
#define LCD_EN                PA9   //  Enable

//#define LCD_D0                LCD_RW_Port, LCD_D0_Pin   //  DATA 0
//#define LCD_D1                LCD_EN_Port, LCD_D1_Pin   //  DATA 1
//#define LCD_D2                LCD_RW_Port, LCD_D2_Pin   //  DATA 2
//#define LCD_D3                LCD_EN_Port, LCD_D3_Pin   //  DATA 3
#define LCD_D4                PB4   //  DATA 4
#define LCD_D5                PB5   //  DATA 5
#define LCD_D6                PB6   //  DATA 6
#define LCD_D7                PB7   //  DATA 7

#define LCD_LED               PD2                //  Register Select

/**
 * @brief  Setea el valor del pin
 * @note   Definida como macro para obtener la maxima velocidad usando acceso a los registros 
 * @param  GPIOx: GPIOx PORT 
 * @param  GPIO_Pin: GPIO pin(s). Se pueden seleccionar varios con el operador | (OR) 
 * @param  Estado: Si el parametro es 0 el pin ira a nivel bajo, de otra forma sera alto
 * @retval Ninguno
 */
 
#define LCD_SetPinVal(GPIOx, GPIO_Pin, Estado)	((Estado) ? GPIO_SetBits(GPIOx, GPIO_Pin) : GPIO_ResetBits(GPIOx, GPIO_Pin))

/*************************** Comandos  ******************************/
#define LCD_CLEARDISPLAY        0x01
#define LCD_RETURNHOME          0x02
#define LCD_ENTRYMODESET        0x06
#define LCD_DISPLAYCONTROL      0x08
#define LCD_CURSORSHIFT         0x10
#define LCD_FUNCTIONSET         0x28
#define LCD_SETCGRAMADDR        0x40
#define LCD_SETDDRAMADDR        0x80

/*************** Banderas para el tipo de modo de entrada  **************/
#define LCD_ENTRYRIGHT          0x00
#define LCD_ENTRYLEFT           0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

/******************** Control del display ON/OFF  *******************/
#define LCD_DISPLAYON           0x0C  
#define LCD_CURSORON            0x07
#define LCD_BLINKON             0x15

/******************** Control del puntero **************************/
#define LCD_DISPLAYMOVE         0x08
#define LCD_CURSORMOVE          0x00
#define LCD_MOVERIGHT           0x04
#define LCD_MOVELEFT            0x00

/****************** Seteo de funciones ****************************/
#define LCD_8BITMODE            0x10
#define LCD_4BITMODE            0x28
#define LCD_2LINE               0x80
#define LCD_1LINE               0x00
#define LCD_5x10DOTS            0x04
#define LCD_5x8DOTS             0x00
/* Definiciones privadas-------------------------------------------------------*/
		
/** @addgroup Seccion_Funciones_Privadas
  * @{
	*/
		
    void osThreadLCD16x2_Init(void);
		void osThreadLCD16x2_GPIO_Config_Out(void);
    void osThreadLCD16x2_Delay(uint32_t nCount);		
		void osThreadLCD16x2_Cmd4bit(uint8_t cmd);
		void osThreadLCD16x2_Cmd(uint8_t cmd);
		void osThreadLCD16x2_Clear(void);
    void osThreadLCD16x2_Data(uint8_t data);
    void osThreadLCD16x2_CursorSet(uint8_t col, uint8_t row);
	  void osThreadLCD16x2_Puts(uint8_t x, uint8_t y, char* str);
		void osThreadLCD16x2_DisplayOn(void); 

#endif /* _USB_H_ */

/* */
	
/******************* (C) COPYRIGHT 2015 EDESIGN *****FIN DE ARCHIVO****/
