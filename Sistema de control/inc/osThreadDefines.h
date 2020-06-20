/**
  ******************************************************************************
  * @archivo  _______________
  * @autor    EDESIGN TEAM
  * @version  V1.0.0
  * @fecha    ______________
  * @brief    ______________
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
#ifndef __OSTHREADEFINES_H
#define __OSTHREADEFINES_H

/* Includes  ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"     // Todo lo relacionado con GPIO's
#include "stm32f4xx_rcc.h"      // Todo lo relacionado con los relojes de perifericos
#include "stm32f4xx_can.h"      // Todo lo relacionado con los relojes de perifericos
#include "stm32f4xx_rtc.h"      // Todo lo relacionado con los relojes de perifericos

/* Includes usados para imprimir en pantalla un mensaje (debug) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definiciones del osX ---------------------------------------------------*/
#include "OsThreadUSART.h"
#include "osThreadGPIO.h"
#include "osThreadCANBUS.h"
#include "osUserThread.h"
#include "osThreadTimer.h"
#include "osThreadPWM.h"
#include "osThreadMPU.h"

/* Configuracion de perifericos externos */
#include "osThreadLCD16x2.h"
#include "osThreadProtocol.h"
#include "osThreadPWM.h"

/* Reloj en tiempo real */
#include "osThreadRTC.h"

/* Definiciones externas */
extern void mainDelay(__IO uint32_t nCount);

/**
  *@addtogroup USART_Definitions
	*@{
	*/
  #define MAX_STRLEN 13 
	#define EOL_USART1 '*'
	#define EOL_USART2 '*'
	#define EOL_USART3 '*' // 0x89//
	#define EOL_UART4  0x2A
	#define EOL_UART5  '*'
	#define EOL_USART6 '*'
/**
  *@addtogroup USART
	*@{
	*/
	#define os_USART1  11
  #define os_USART2  12
  #define os_USART3  13
  #define os_USART4  14
  #define os_USART5  15
  #define os_USART6  16
/**
	*@}  
  */
	
/**
  *@addtogroup PinsPack USART1
	*@{
	*/
	#define USART1_PA9PA10  1101
  #define USART1_PA9PB7   1102
  #define USART1_PB6PA10  1103
  #define USART1_PB6PB7   1104
/**
	*@}  
  */
	
/**
  *@addtogroup PinsPack USART2
	*@{
	*/
	#define USART2_PA2PA3   1201
  #define USART2_PA2PD6   1202
  #define USART2_PD5PA3   1203
  #define USART2_PD5PD6   1204
/**
	*@}  
  */
	
/**
  *@addtogroup PinsPack USART3
	*@{
	*/
	#define USART3_PB10PB11  1301
  #define USART3_PB10PC11  1302
  #define USART3_PB10PD9   1303
  #define USART3_PC10PB11  1304
  #define USART3_PC10PC11  1305
  #define USART3_PC10PD9   1306
  #define USART3_PD8PD9    1307
  #define USART3_PD8PB11   1308
  #define USART3_PD8PC11   1309
/**
	*@}  
  */
	
/**
  *@addtogroup PinsPack USART4
	*@{
	*/
  #define USART4_PA0PA1    1401
  #define USART4_PA0PC11   1402
  #define USART4_PC10PA1   1403
  #define USART4_PC10PC11  1404
/**
	*@}  
  */
	
/**
  *@addtogroup PinsPack USART5
	*@{
	*/
  #define USART5_PC12PD2   1501
/**
	*@}  
  */
	
/**
  *@addtogroup PinsPack USART6
	*@{
	*/
  #define USART6_PC6PC7   1601
  #define USART6_PC6PG14  1602
  #define USART6_PG9PC7   1603
  #define USART6_PG9PG14  1604
/**
	*@}  
  */

/**
  *@addtogroup CANBUS
	*@{
	*/
  #define os_CANBUS1  21
  #define os_CANBUS2  22
/**
	*@}  
  */
	
/**
  *@addtogroup PinsPack CANBUS1
	*@{
	*/
  #define CANBUS1_PD1PD0   2101
  #define CANBUS1_PB8PB9   2102
/**
	*@}  
  */

/**
  *@addtogroup PinsPack CANBUS2
	*@{
	*/
  #define CANBUS2_PB6PB5   2201
/**
	*@}  
  */
	
/**
  *@addtogroup CAN_Prescaler CANBUSx
	*@{
	*/
  //#define CANBUS_Prescaler  1     /* 2000 kbit/s*/
	//#define CANBUS_Prescaler  2     /* 1000 kbit/s*/
	#define CANBUS_Prescaler  4     /* 500  kbit/s*/
	//#define CANBUS_Prescaler  5     /* 400  kbit/s*/
	//#define CANBUS_Prescaler  8     /* 250  kbit/s*/
	//#define CANBUS_Prescaler  10    /* 200  kbit/s*/
	//#define CANBUS_Prescaler  16    /* 125  kbit/s*/
	//#define CANBUS_Prescaler  20    /* 100  kbit/s*/
	//#define CANBUS_Prescaler  40    /* 50   kbit/s*/
	//#define CANBUS_Prescaler  80    /* 40   kbit/s*/
	//#define CANBUS_Prescaler  200   /* 10   kbit/s*/
	//#define CANBUS_Prescaler  1023  /* 1    kbit/s*/
/**
	*@}  
  */

/**
  *@addtogroup SPI
	*@{
	*/
  #define os_SPI1  31
  #define os_SPI2  32
  #define os_SPI3  33
/**
	*@}  
  */

/**
  *@addtogroup SPI1 //SPIx_ MISO MOSI SCK NSS//
	*@{
	*/
  #define SPI1_PA6PA7PA5PA4  3101
  #define SPI1_PA6PA7PA5PA15 3102
  #define SPI1_PA6PA7PB3PA4  3103
  #define SPI1_PA6PA7PB3PA15 3104
  #define SPI1_PA6PB5PB3PA4  3105
  #define SPI1_PA6PB5PB3PA15 3106
  #define SPI1_PA6PB5PA5PA4  3107
  #define SPI1_PA6PB5PA5PA15 3108
  #define SPI1_PB4PA7PA5PA4  3108
  #define SPI1_PB4PA7PA5PA15 3110
  #define SPI1_PB4PA7PB3PA4  3111
  #define SPI1_PB4PA7PB3PA15 3112
  #define SPI1_PB4PB5PA5PA4  3113
  #define SPI1_PB4PB5PA5PA15 3114
  #define SPI1_PB4PB5PB3PA4  3115
  #define SPI1_PB4PB5PB3PA15 3116
/**
	*@}  
  */	
	
/**
  *@addtogroup SPI2 //SPIx_ MISO MOSI SCK NSS//SPI1_PB14PB15PB13PB12 MISO=PB14 MOSI=PB15 SCK=PB13 NSS=PB12
	*@{
	*/
  #define SPI2_PB14PB15PB13PB12 3201
  #define SPI2_PB14PB15PB13PB9  3202
  #define SPI2_PB14PB15PB10PB12 3203
  #define SPI2_PB14PB15PB10PB9  3204
  #define SPI2_PB14PC3PB13PB12  3205
  #define SPI2_PB14PC3PB13PB9   3206
  #define SPI2_PB14PC3PB10PB12  3207
  #define SPI2_PB14PC3PB10PB9   3208
  #define SPI2_PC2PB15PB13PB12  3209
  #define SPI2_PC2PB15PB13PB9   3210
  #define SPI2_PC2PB15PB10PB12  3211
  #define SPI2_PC2PB15PB10PB19  3212
  #define SPI2_PC2PC3PB13PB12   3213
  #define SPI2_PC2PC3PB13PB9    3214
  #define SPI2_PC2PC3PB10PB12   3215
  #define SPI2_PC2PC3PB10PB9    3216
/**
	*@}  
  */	
	
/**
  *@addtogroup SPI3 //SPIx_ MISO MOSI SCK NSS//
	*@{
	*/
  #define SPI3_PB4PB5PB3PA4     3301
  #define SPI3_PB4PB5PB3PA15    3302
  #define SPI3_PB4PB5PC10PA4    3303
  #define SPI3_PB4PB5PC10PA15   3304
  #define SPI3_PB4PC12PB3PA4    3305
  #define SPI3_PB4PC12PB3PA15   3306
  #define SPI3_PB4PC12PC10PA4   3307
  #define SPI3_PB4PC12PC10PA15  3308
  #define SPI3_PC11PB5PB3PA4    3309
  #define SPI3_PC11PB5PB3PA15   3310
  #define SPI3_PC11PB5PC10PA4   3311
  #define SPI3_PC11PB5PC10PA15  3312
  #define SPI3_PC11PC12PB3PA4   3313
  #define SPI3_PC11PC12PB3PA15  3314
  #define SPI3_PC11PC12PC10PA4  3315
  #define SPI3_PC11PC12PC10PA15 3316
/**
	*@}  
  */
	
/**
  *@addtogroup GPIOA
	*@{
	*/
  #define PA0 GPIOA, GPIO_Pin_0
  #define PA1 GPIOA, GPIO_Pin_1
  #define PA2 GPIOA, GPIO_Pin_2
  #define PA3 GPIOA, GPIO_Pin_3
	#define PA4 GPIOA, GPIO_Pin_4
	#define PA5 GPIOA, GPIO_Pin_5
	#define PA6 GPIOA, GPIO_Pin_6
	#define PA7 GPIOA, GPIO_Pin_7
	#define PA8 GPIOA, GPIO_Pin_8
	#define PA9 GPIOA, GPIO_Pin_9
	#define PA10 GPIOA, GPIO_Pin_10
	#define PA11 GPIOA, GPIO_Pin_11
	#define PA12 GPIOA, GPIO_Pin_12
	#define PA13 GPIOA, GPIO_Pin_13
	#define PA14 GPIOA, GPIO_Pin_14
	#define PA15 GPIOA, GPIO_Pin_15
/**
	*@}  
  */	

/**
  *@addtogroup GPIOB
	*@{
	*/
	#define PB0 GPIOB, GPIO_Pin_0
	#define PB1 GPIOB, GPIO_Pin_1
	#define PB2 GPIOB, GPIO_Pin_2
	#define PB3 GPIOB, GPIO_Pin_3
	#define PB4 GPIOB, GPIO_Pin_4
	#define PB5 GPIOB, GPIO_Pin_5
	#define PB6 GPIOB, GPIO_Pin_6
	#define PB7 GPIOB, GPIO_Pin_7
	#define PB8 GPIOB, GPIO_Pin_8
	#define PB9 GPIOB, GPIO_Pin_9
	#define PB10 GPIOB, GPIO_Pin_10
	#define PB11 GPIOB, GPIO_Pin_11
	#define PB12 GPIOB, GPIO_Pin_12
	#define PB13 GPIOB, GPIO_Pin_13
	#define PB14 GPIOB, GPIO_Pin_14
	#define PB15 GPIOB, GPIO_Pin_15
/**
	*@}  
  */	

/**
  *@addtogroup GPIOC
	*@{
	*/
	#define PC0 GPIOC, GPIO_Pin_0
	#define PC1 GPIOC, GPIO_Pin_1
	#define PC2 GPIOC, GPIO_Pin_2
	#define PC3 GPIOC, GPIO_Pin_3
	#define PC4 GPIOC, GPIO_Pin_4
	#define PC5 GPIOC, GPIO_Pin_5
	#define PC6 GPIOC, GPIO_Pin_6
	#define PC7 GPIOC, GPIO_Pin_7
	#define PC8 GPIOC, GPIO_Pin_8
	#define PC9 GPIOC, GPIO_Pin_9
	#define PC10 GPIOC, GPIO_Pin_10
	#define PC11 GPIOC, GPIO_Pin_11
	#define PC12 GPIOC, GPIO_Pin_12
	#define PC13 GPIOC, GPIO_Pin_13
	#define PC14 GPIOC, GPIO_Pin_14
	#define PC15 GPIOC, GPIO_Pin_15
/**
	*@}  
  */	

/**
  *@addtogroup GPIOD
	*@{
	*/
	#define PD0 GPIOD, GPIO_Pin_0
	#define PD1 GPIOD, GPIO_Pin_1
	#define PD2 GPIOD, GPIO_Pin_2
	#define PD3 GPIOD, GPIO_Pin_3
	#define PD4 GPIOD, GPIO_Pin_4
	#define PD5 GPIOD, GPIO_Pin_5
	#define PD6 GPIOD, GPIO_Pin_6
	#define PD7 GPIOD, GPIO_Pin_7
	#define PD8 GPIOD, GPIO_Pin_8
	#define PD9 GPIOD, GPIO_Pin_9
	#define PD10 GPIOD, GPIO_Pin_10
	#define PD11 GPIOD, GPIO_Pin_11
	#define PD12 GPIOD, GPIO_Pin_12
	#define PD13 GPIOD, GPIO_Pin_13
	#define PD14 GPIOD, GPIO_Pin_14
	#define PD15 GPIOD, GPIO_Pin_15
/**
	*@}  
  */	

/**
  *@addtogroup GPIOE
	*@{
	*/
	#define PE0 GPIOE, GPIO_Pin_0
	#define PE1 GPIOE, GPIO_Pin_1
	#define PE2 GPIOE, GPIO_Pin_2
	#define PE3 GPIOE, GPIO_Pin_3
	#define PE4 GPIOE, GPIO_Pin_4
	#define PE5 GPIOE, GPIO_Pin_5
	#define PE6 GPIOE, GPIO_Pin_6
	#define PE7 GPIOE, GPIO_Pin_7
	#define PE8 GPIOE, GPIO_Pin_8
	#define PE9 GPIOE, GPIO_Pin_9
	#define PE10 GPIOE, GPIO_Pin_10
	#define PE11 GPIOE, GPIO_Pin_11
	#define PE12 GPIOE, GPIO_Pin_12
	#define PE13 GPIOE, GPIO_Pin_13
	#define PE14 GPIOE, GPIO_Pin_14
	#define PE15 GPIOE, GPIO_Pin_15
/**
	*@}  
  */	

/**
  *@addtogroup GPIOF
	*@{
	*/
	#define PF0 GPIOF, GPIO_Pin_0
	#define PF1 GPIOF, GPIO_Pin_1
	#define PF2 GPIOF, GPIO_Pin_2
	#define PF3 GPIOF, GPIO_Pin_3
	#define PF4 GPIOF, GPIO_Pin_4
	#define PF5 GPIOF, GPIO_Pin_5
	#define PF6 GPIOF, GPIO_Pin_6
	#define PF7 GPIOF, GPIO_Pin_7
	#define PF8 GPIOF, GPIO_Pin_8
	#define PF9 GPIOF, GPIO_Pin_9
	#define PF10 GPIOF, GPIO_Pin_10
	#define PF11 GPIOF, GPIO_Pin_11
	#define PF12 GPIOF, GPIO_Pin_12
	#define PF13 GPIOF, GPIO_Pin_13
	#define PF14 GPIOF, GPIO_Pin_14
	#define PF15 GPIOF, GPIO_Pin_15
/**
	*@}  
  */	

/**
  *@addtogroup GPIOG
	*@{
	*/
	#define PG0 GPIOG, GPIO_Pin_0
	#define PG1 GPIOG, GPIO_Pin_1
	#define PG2 GPIOG, GPIO_Pin_2
	#define PG3 GPIOG, GPIO_Pin_3
	#define PG4 GPIOG, GPIO_Pin_4
	#define PG5 GPIOG, GPIO_Pin_5
	#define PG6 GPIOG, GPIO_Pin_6
	#define PG7 GPIOG, GPIO_Pin_7
	#define PG8 GPIOG, GPIO_Pin_8
	#define PG9 GPIOG, GPIO_Pin_9
	#define PG10 GPIOG, GPIO_Pin_10
	#define PG11 GPIOG, GPIO_Pin_11
	#define PG12 GPIOG, GPIO_Pin_12
	#define PG13 GPIOG, GPIO_Pin_13
	#define PG14 GPIOG, GPIO_Pin_14
	#define PG15 GPIOG, GPIO_Pin_15
/**
	*@}  
  */	

/**
  *@addtogroup GPIO CONTROL
	*@{
	*/
  #define os_IN  34
	#define os_OUT 35
	#define os_INT 36
	#define os_AN  37
	#define TRUE    1
	#define FALSE   0
/**
	*@}  
  */	
	
/**
  *@addtogroup ADC1 Canales
	*@{
	*/
  #define ADC1_CH0      PA0,  ADC_Channel_0
	#define ADC1_CH1      PA1,  ADC_Channel_1
	#define ADC1_CH2      PA2,  ADC_Channel_2
	#define ADC1_CH3      PA3,  ADC_Channel_3
	#define ADC1_CH4      PA4,  ADC_Channel_4
	#define ADC1_CH5      PA5,  ADC_Channel_5
	#define ADC1_CH6      PA6,  ADC_Channel_6
	#define ADC1_CH7      PA7,  ADC_Channel_7
	#define ADC1_CH8      PB0,  ADC_Channel_8
	#define ADC1_CH9      PB1,  ADC_Channel_9
	#define ADC1_CH10     PC0,  ADC_Channel_10
	#define ADC1_CH11     PC1,  ADC_Channel_11
	#define ADC1_CH12     PC2,  ADC_Channel_12
	#define ADC1_CH13     PC3,  ADC_Channel_13
	#define ADC1_CH14     PC4,  ADC_Channel_14
	#define ADC1_CH15     PC5,  ADC_Channel_15
/**
	*@}  
  */

/**
  *@addtogroup ADC2 Canales
	*@{
	*/
  #define ADC2_CH0      PA0,  ADC_Channel_0
	#define ADC2_CH1      PA1,  ADC_Channel_1
	#define ADC2_CH2      PA2,  ADC_Channel_2
	#define ADC2_CH3      PA3,  ADC_Channel_3
	#define ADC2_CH4      PA4,  ADC_Channel_4
	#define ADC2_CH5      PA5,  ADC_Channel_5
	#define ADC2_CH6      PA6,  ADC_Channel_6
	#define ADC2_CH7      PA7,  ADC_Channel_7
	#define ADC2_CH8      PB0,  ADC_Channel_8
	#define ADC2_CH9      PB1,  ADC_Channel_9
	#define ADC2_CH10     PC0,  ADC_Channel_10
	#define ADC2_CH11     PC1,  ADC_Channel_11
	#define ADC2_CH12     PC2,  ADC_Channel_12
	#define ADC2_CH13     PC3,  ADC_Channel_13
	#define ADC2_CH14     PC4,  ADC_Channel_14
	#define ADC2_CH15     PC5,  ADC_Channel_15
/**
	*@}  
  */
	
/**
  *@addtogroup ADC3 Canales
	*@{
	*/
  #define ADC3_CH0      PA0,  ADC_Channel_0
	#define ADC3_CH1      PA1,  ADC_Channel_1
	#define ADC3_CH2      PA2,  ADC_Channel_2
	#define ADC3_CH3      PA3,  ADC_Channel_3
	#define ADC3_CH4      PF6,  ADC_Channel_4
	#define ADC3_CH5      PF7,  ADC_Channel_5
	#define ADC3_CH6      PF8,  ADC_Channel_6
	#define ADC3_CH7      PF9,  ADC_Channel_7
	#define ADC3_CH8      PF10, ADC_Channel_8
	#define ADC3_CH9      PF3,  ADC_Channel_9
	#define ADC3_CH10     PC0,  ADC_Channel_10
	#define ADC3_CH11     PC1,  ADC_Channel_11
	#define ADC3_CH12     PC2,  ADC_Channel_12
	#define ADC3_CH13     PC3,  ADC_Channel_13
	#define ADC3_CH14     PF4,  ADC_Channel_14
	#define ADC3_CH15     PF5,  ADC_Channel_15
/**
	*@}  
  */

/**
  *@addtogroup ADC DMA
	*@{
	*/
  #define DMA_ADC1_1  ADC1,DMA2_Stream0, DMA_Channel_0
  #define DMA_ADC1_2  ADC1,DMA2_Stream4, DMA_Channel_0
	
  #define DMA_ADC2_1  ADC2,DMA2_Stream2, DMA_Channel_1
  #define DMA_ADC2_2  ADC2,DMA2_Stream3, DMA_Channel_1
  
	#define DMA_ADC3_1  ADC3,DMA2_Stream0, DMA_Channel_2
  #define DMA_ADC3_2  ADC3,DMA2_Stream1, DMA_Channel_2
/**
	*@}  
  */	


	
#endif /* __OSTHREADDEFINES_H */
