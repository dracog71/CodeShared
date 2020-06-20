/*
	******************************************************************************
  * @file    osThreadLCD16x2.c
  * @author  EDESIGN TEAM
  * @version V1.3.0         modificado por JMLG para MDK-ARM V5.0
  * @date    24-Febrero-2015
  * @brief   Archivo de configuracion avanzada automatizada para LCD 16 x 2.
  *          Este archivo contiene configuraciones para control LCD definidos.
  *            
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
	
/* Inclusiones------------------------------------------------------------------*/
#include "osThreadLCD16x2.h"
#include "osThreadDefines.h"

/* Estructura para valores de tablero delantero */
extern TAB_TRA_STRUCT TAB_TRA;

/* Valores del display posiscion x y ------------------------------------------*/
uint8_t Filas    = 2 ;
uint8_t Columnas = 16;
uint8_t x_actual     ;
uint8_t y_actual     ;
	
/**
  * @brief  Inicializacion del LCD 16x2
  * @param  None
  * @retval None
  */
	void osThreadLCD16x2_Init(){
		
		//Inicializacion de los pines
		osThreadLCD16x2_GPIO_Config_Out();
		
	  GPIO_SetBits(LCD_LED);
		
		osThreadLCD16x2_Delay(400000);
		
		osThreadLCD16x2_Cmd(LCD_RETURNHOME );
		osThreadLCD16x2_Delay(40000);
		
		osThreadLCD16x2_Cmd(LCD_FUNCTIONSET);
		osThreadLCD16x2_Delay(40000);
		
		osThreadLCD16x2_Cmd(LCD_DISPLAYON );
		osThreadLCD16x2_Delay(40000);
		
		osThreadLCD16x2_Cmd(LCD_CLEARDISPLAY );
		osThreadLCD16x2_Delay(40000);
		
		osThreadLCD16x2_Cmd(LCD_ENTRYMODESET);
		osThreadLCD16x2_Delay(40000);
		
		
	}
	
	
	/**
* @brief  Inicializacion de los pines del LCD 16x2
* @param  Ninguno
* @retval Ninguno
*/
void osThreadLCD16x2_GPIO_Config_Out() {
	
	/* Inicializacion de pines de salida */
	 osThreadGPIOInit(LCD_RS       ,os_OUT);
	 osThreadGPIOInit(LCD_RW       ,os_OUT);
	 osThreadGPIOInit(LCD_EN       ,os_OUT);
	 osThreadGPIOInit(LCD_D4       ,os_OUT);
	 osThreadGPIOInit(LCD_D5       ,os_OUT);
	 osThreadGPIOInit(LCD_D6       ,os_OUT);
	 osThreadGPIOInit(LCD_D7       ,os_OUT);
	 osThreadGPIOInit(LCD_LED      ,os_OUT);
	
}
	
/**
  * @brief  osThreadLCD16x2_Cmd4bit
  * @param  Dato a enviar por 4 bits
  * @retval Ninguno
  */
void osThreadLCD16x2_Cmd4bit(uint8_t cmd) {
	
	/* Set output port */
	(cmd & 0x08) ? GPIO_SetBits(LCD_D7) : GPIO_ResetBits(LCD_D7);
	(cmd & 0x04) ? GPIO_SetBits(LCD_D6) : GPIO_ResetBits(LCD_D6);
	(cmd & 0x02) ? GPIO_SetBits(LCD_D5) : GPIO_ResetBits(LCD_D5);
	(cmd & 0x01) ? GPIO_SetBits(LCD_D4) : GPIO_ResetBits(LCD_D4);
	
	GPIO_SetBits(LCD_EN);
	osThreadLCD16x2_Delay(1500);
	GPIO_ResetBits(LCD_EN);
	osThreadLCD16x2_Delay(1500);
}

/**
  * @brief  osThreadLCD16x2_Cmd
  * @param  Dato de control comando
  * @retval Ninguno
  */
void osThreadLCD16x2_Cmd(uint8_t cmd) {
	/* Modo de Comando */
	GPIO_ResetBits(LCD_RS);
	
	/* Nibble alto*/
	osThreadLCD16x2_Cmd4bit(cmd >> 4);
	
	/* Nibble bajo */
	osThreadLCD16x2_Cmd4bit(cmd & 0x0F);
}

/**
  * @brief  osThreadLCD16x2_Data
  * @param  Dato de control de Dato 
  * @retval Ninguno
  */
void osThreadLCD16x2_Data(uint8_t data) {
	/* Modo de datos */
	GPIO_SetBits(LCD_RS);
	
	/* High nibble */
	osThreadLCD16x2_Cmd4bit(data >> 4);
	/* Low nibble */
	osThreadLCD16x2_Cmd4bit(data & 0x0F);
}

/**
  * @brief  osThreadLCD16x2_Puts
  * @param  Envia al LCD  el dato *str
  * @retval Ninguno
  */
void osThreadLCD16x2_Puts(uint8_t x, uint8_t y, char* str)
{
	uint32_t Counter = 0;
	
	/* Si el cronometro se encuentra activo */
	if(TAB_TRA.CRONOMETRO_SEG == NO_ACTIVE){

	  osThreadLCD16x2_CursorSet(x, y);
	  while (*str) {
		  if (x_actual >= Columnas) {
			  x_actual = 0;
			  y_actual++;
			  osThreadLCD16x2_CursorSet(x_actual,y_actual);
		  }
		  /*if (*str == '\n') {
			  y_actual++;
			  osThreadLCD16x2_CursorSet(x_actual, y_actual);
		  } else if (*str == '\r') {
			  osThreadLCD16x2_CursorSet(0, y_actual);
		  }*/
		  else {
			  osThreadLCD16x2_Data(*str);
			  x_actual++;
		  }
		  str++;
		  Counter++;
		  if(Counter >=15) break;
	  }
  }
}

void osThreadLCD16x2_CursorSet(uint8_t col, uint8_t fila) {
	uint8_t fila_offsets[] = {0x00, 0x40, 0x14, 0x54};
	
	/* Ir al inicio */
	if (fila >= Filas) {
		fila = 0;
	}
	
	/* Setar fila y columna actual */
	x_actual = col;
	y_actual = fila;
	
	/* Setear locacion del cursor */
	osThreadLCD16x2_Cmd(LCD_SETDDRAMADDR | (col + fila_offsets[fila]));
}
/**
  * @brief  Delay 
  * @param  No. de ciclos
  * @retval Ninguno
  */
void osThreadLCD16x2_Delay(uint32_t nCount)
{	
	//nCount = nCount *100;
    while(nCount--);
}
/******************* (C) COPYRIGHT 2015 EDESIGN *****FIN DE ARCHIVO****/

