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
#ifndef __OSUSERTHREAD_H
#define __OSUSERTHREAD_H

/* Includes  ------------------------------------------------------------------*/
#include "osThreadDefines.h"

/* Definiciones de osUserThread  ---------------------------------------------------*/
#define BUZZER             PA12
#define LED_PUERTA_ABIERTA PA2
#define SUCCIONADOR        PA15
#define LUZ_GAVETAS        PC10
#define LUZ_MESA           PC11
#define INVERSOR           PC12

	#define LED_BUTTON01 PB15
	#define LED_BUTTON02 PB12
	#define LED_BUTTON03 PB11
	#define LED_BUTTON04 PB10
	#define LED_BUTTON05 PA8
	#define LED_BUTTON06 PB13
	#define LED_BUTTON07 PB1
	#define LED_BUTTON08 PA6
	#define LED_BUTTON09 PC9
	#define LED_BUTTON10 PB14
	#define LED_BUTTON11 PC4
	#define LED_BUTTON12 PC5
	#define LED_BUTTON13 PC1
	#define LED_BUTTON14 PC0
	#define LED_BUTTON15 PA4
	#define LED_BUTTON16 PA7
	#define LED_BUTTON17 PC2
	#define LED_BUTTON18 PC3
	#define LED_BUTTON19 PA3
	#define LED_BUTTON20 PA5
	#define LED_BUTTON21 PC6
	#define LED_BUTTON22 PC7
	#define LED_BUTTON23 PC8

typedef struct{
	uint32_t IMG;               /* Nueva imagen en QUERY        */
	uint32_t IMG_CARRIER;       /* Valor de imagen en QUERY     */
  uint32_t IMG_SEG;           /* Seguro de nueva imagen       */
  uint32_t Clear_LCD;         /* Variable de limpieza del LCD */ 
	uint32_t FUSE_SEG;          /* Total de fusibles            */
	uint32_t FUSE;              /* Fusible a mostrar            */
	uint32_t FUSES;             /* Total de fusibles abiertos   */
	uint32_t CRONOMETRO_SEG;    /* Seguro del cronometro        */
	uint8_t  CRONOMETRO_MIN_T;  /* Valor de los minutos         */
	uint8_t  CRONOMETRO_SEG_T;  /* Valor de los segundos        */
	uint8_t  CRONOMETRO_HR_T;   /* Valor de horas               */
	uint32_t CRONOMETRO_STATE;  /* Estado actual del cronometro */
	uint32_t Oxigen_seg;        /* Seguro del texto del oxigeno */ 
	uint32_t Oxigen_level;      /* Porcentaje del nivel oxigeno */
	uint32_t LCD_WAITING;       /* Señal esperando por el LCD   */
	uint32_t Oxigen_LCD;        /* Libreacion del LCD           */
	uint32_t USART_DATA;        /* Variable de dato de funciones en USART    */
	uint32_t USART_CARRIER;     /* Variable de dato de funciones en USART    */
	uint32_t USART_STATUS;      /* Variable de estado de entrada USART       */
}TAB_TRA_STRUCT;


/** @addtogroup Definicion de Salidas para Display
  * @{
  */
		void osUserThread_ClearLCD(void);
		void osUserThread_Refresh_LCD(void);
    void osUserThread_Cronometro(uint32_t FUNCTION);
    void osUserThread_USART_CONTROL(void);
/**                                             
  * @}                                              
  */                                           
                                                
/** @addtogroup Prototipo de Funciones
  * @{
  */ 

    void osUserThread_InitConf(void);
    void osUserThread_vPeriodicTask(void);
		
		void osUserThread_INT0CALLBACK(void);
		void osUserThread_INT1CALLBACK(void);
		void osUserThread_INT2CALLBACK(void);
		void osUserThread_INT3CALLBACK(void);
		void osUserThread_INT4CALLBACK(void);
		void osUserThread_INT5CALLBACK(void);
		void osUserThread_INT6CALLBACK(void);
		void osUserThread_INT7CALLBACK(void);
		void osUserThread_INT8CALLBACK(void);
		void osUserThread_INT9CALLBACK(void);
		void osUserThread_INT10CALLBACK(void);
		void osUserThread_INT11CALLBACK(void);
		void osUserThread_INT12CALLBACK(void);
		void osUserThread_INT13CALLBACK(void);
		void osUserThread_INT14CALLBACK(void);
		void osUserThread_INT15CALLBACK(void);
	
#endif /* __osUserThread_H */
