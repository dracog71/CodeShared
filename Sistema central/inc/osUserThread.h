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
	
/* Estructura de control del Centro de Carga */
typedef struct{
	uint32_t NEW_DATA;             /* Nuevo dato en el FIFO                               */
	uint32_t CARRIER;              /* Valor de entrada en el FIFO                         */
	uint32_t STATUS;               /* Estado de la funcion del FIFO                       */
	uint32_t SAVED_BUFFER[200];    /* Almacena los valores alteriones                     */
	uint32_t EmergencyLevel;       /* control del nivel de emergencia actual              */
	uint32_t Emergency_Seg;        /* Seguro de entrada recursiva a niveled de emergencia */
	uint32_t Emergency_state;      /* Control de funciones de niveles de emergencia       */
	uint32_t SEG_PUERTA_LATERAL;   /* Control de señal de encendido enviada               */
	uint32_t SEG_PUERTA_TRASERA;   /* Control de señal de encendido enviada               */
	uint32_t SEG_REVERSA;          /* Seguro de la reversa                                */
	uint32_t FLASHER_CARRIER;      /* Control seleccionado para el flasher                */
  uint32_t STOP_CARRIER;         /* Variable de control del stop manual                 */	
	uint32_t MICRO_LEVEL;          /* Nivel de volumen microfono                          */
	uint32_t HORN_COUNTER;         /* Cambio entre audios de sirena                       */
	uint32_t TESTER_ACTIVE;        /* Señal de activacion de tester                       */
	uint32_t TESTER_COUNTER;       /* Contador del TIMEOUT para TESTER                    */
	uint32_t DIRECCIONADOR_ACT;    /* Señal de  Direccionador activo                      */
	uint32_t DIR_COUNTER;          /* contador de TIMEOUT para DIRECCIONADOR              */ 
	uint32_t CRONOMETRO_ACTIVE;    /* Señal de  Direccionador activo                      */
	uint32_t CRONOMETRO_COUNTER;   /* contador de TOIMEOUT para DIRECCIONADOR             */ 
	uint32_t SIREN_ACTIVE;         /* Señal de  SIRENA activa                             */
	uint32_t SIREN_COUNTER;        /* contador de TOIMEOUT para Sirena                    */ 
	uint32_t CRONOMETRO_SEG;       /* Seguro de funcion cronometro                        */
	uint32_t CRONOMETRO_STATE;     /* Estado del cronometro                               */
	uint32_t USART_INPUT;          /* Si el estado es de entrada del USART                */
	uint32_t SOLENOIDE_SEG;        /* Seguro del solenoide                                */
	uint32_t CAN_SENDER;           /* Sender del canbus                                   */ 
	uint32_t SEG_DIR_IZQ;          /* Seguro de la direccional izq                        */ 
	uint32_t SEG_DIR_DER;          /* Seguro de la direccional der                        */ 
	uint32_t SEG_DIR_STOP;         /* Seguro de la direccional stop                       */ 
	uint32_t SEG_STOP_OFF;         /* Variable de conteo para deshabilitar el freno       */
	uint32_t CNT_DIR_IZQ;          /* Contador de entrada no recursiva                    */
	uint32_t CNT_DIR_DER;          /* Contador de entrada no recursiva                    */
	uint32_t CNT_DIR_STOP;         /* Contador de entrada no recursiva                    */
	uint32_t SEG_INTERMITENTES;    /* Seguro de ambas señales activas                     */
	uint32_t EFECTO_SELECTED;      /* Valor del efecto actual seleccionado                */
	uint32_t EFECTO_SEG;           /* Seguro de cambio de efecto                          */
	uint32_t EFECTO_COUNTER;       /* Counter del efecto actual                           */
	uint32_t PWM_BUFFER[10];       /* Buffer de control de leds                           */
	uint32_t LED_INTENSITY;        /* Intensidad del brillo de los leds direccionador     */
	uint32_t DIRECCIONAL_EFFECT;   /* Variable de almacenamiento de efecto seleccionado   */
}TAB_CC_STRUCT;


/* Estructura de control de versiones */
typedef struct{
	uint32_t FUSE_READ;          /* Version con lectura de fusibles                     */
	uint32_t SIRENA;             /* Version con control de sirena                       */
	uint32_t ESTRIBO;            /* Version con control de estribo                      */
	uint32_t DIRECCIONADOR;      /* Version con control de direccionador                */
	uint32_t BLUETOOTH;          /* Version con control por bluetooth                   */
}VERSION_STRUCT;


/* Definiciones tipo del Bluetooth */
#define UART_MODE        PB14
 
#define BLU_CMD_MODE     GPIO_ResetBits(PB14)
#define BLU_DATA_MODE    GPIO_SetBits(PB14)

/* Variable de conteo Máximo */
#define MAX_VAL             5000000
#define MAX_SEG_STOP        5000

/* Definiciones de osUserThread  ---------------------------------------------------*/


/** @addtogroup Defincion de Niveles de emergencia
  * @{
  */ 
	
/**                                             
  * @}                                              
  */	
	
/** @addtogroup Definicion de Salidas
  * @{
  */ 

#define LUZ_BAJA                          PC12 
#define LUZ_ALTA                          PC11 
#define ESTROBOS                          PC10 
#define REVERSA                           PA15 
#define PERIMETRAL                        PA12 
#define VOLTAJE_TABLEROS                  PA11 
#define TORRETA                           PA10 
#define LUZ_ESCENA_PERIMETRAL             PA7 
#define ESCENA_DERECHA                    PA6 
#define ESCENA_TRASERA                    PA5 
#define ESCENA_IZQUIERDA                  PA4 

/* DIRECCIONADOR */
  #define DIR2                            PC4
  #define DIR3                            PA3
  #define DIR4                            PA2
  #define DIR5                            PC2
  #define DIR6                            PC1
  #define DIR7                            PC0
  #define DIR8                            PC15
  #define DIR9                            PC14
/*****************/

#define LUZ_ESTACIONADO                   PC13 
#define EXTRACTOR_ALTA                    PB4
#define EXTRACTOR_BAJA                    PB5 
#define VENTILADOR_ALTA                   PB7
#define VENTILADOR_BAJA                   PB6
#define LUZ_PIEL_SENSIBLE                 PD2   

/**                                             
  * @}                                              
  */                                           
                                                   
/** @addtogroup Defincion de Interrupciones
  * @{
  */ 
#define DIR_IZQ                             PC5    //INTERRUPCION0
#define FRENO                               PB1    //ENTRADA SOLENOIDE
#define DIR_DER                             PB10   //INTERRUPCION1
#define REVERSA_IN                          PB11   //INTERRUPCION2
#define PUERTA_TRASERA                      PB12   //INTERRUPCION3
#define PUERTA_LATERAL                      PB13   //INTERRUPCION4
#define SOLENOIDE                           PB15   //INTERRUPCION4
/**  
  * @}
  */ 
	
	/** @addtogroup Defincion de LEDS indicadores
  * @{
  */ 
#define LED_DIR_IZQ                         PA9    //INTERRUPCION0
#define LED_FRENO                           PA8    //ENTRADA SOLENOIDE
#define LED_DIR_DER                         PC9    //INTERRUPCION1
#define LED_REVERSA_IN                      PC8    //INTERRUPCION2
#define LED_PUERTA_TRASERA                  PC7    //INTERRUPCION3
#define LED_PUERTA_LATERAL                  PC6    //INTERRUPCION4
#define TEST_MICRO                          PB0    //INTERRUPCION4


#define SIRENA_OUTPUT_TRIGGER               PC13   //Señalizacion extra de sirena
/**  
  * @}
  */ 
/** @addtogroup Prototipo de Funciones
  * @{
  */ 

    void osUserThread_InitConf(void);
    void osUserThread_vPeriodicTask(void);

		/* Funciones de Master */
    void osUserThread_MASTER_CONFIG(void);
		void osUserThread_Relee_Control(void);
		void osUserThread_DOOR_STATUS(void);
		void osUserThread_SOLENOIDE(void);
	
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
