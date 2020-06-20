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
#ifndef __OSTHREADPROTOCOL_H
#define __OSTHREADPROTOCOL_H


/* Definiciones del canBUS  ---------------------------------------------------*/
/** @addtogroup Definiciones de Protocolo Canbus
  * @{
  */
	typedef enum{
		TAB_CC  = 0,         //(00)
		TAB_NE0,
		TAB_DELANTERO,       //(02)  
		TAB_NE1,
		TAB_TRASERO,         //(04)
		TAB_NE2,              
		TAB_DIRECCIONADOR,   //(06)
	 	TAB_NE3,
		TAB_CRONOMETRO,      //(08)
		TAB_NE4,
		TAB_SIRENA,          //(10)
		TAB_NE5,
		TAB_TEST,            //(12)
	}TABLEROS;

  typedef enum{
		INITIAL_SEL = 0,              //(00)
		LUZ_ALTA_SEL,                 //(01)
		LUZ_BAJA_SEL,                 //(02)
		PERIMETRAL_SEL,               //(03)
		TORRETA_SEL,                  //(04)     
		LUZ_MESA_SEL,                 //(05)
		ESCENA_TRASERA_SEL,           //(06)
		ESTROBOS_SEL,                 //(07)
		FAROS_SEL,                    //(08)
		VENTILADOR_ALTA_SEL,          //(09)
		VENTILADOR_BAJA_SEL,          //(10)
		EXTRACTOR_ALTA_SEL,           //(11)
		EXTRACTOR_BAJA_SEL,           //(12)
		VOLTAJE_TABLEROS_SEL,         //(13)
		LUZ_ESCENA_PERIMETRAL_SEL,    //(14)
		LUZ_ESTACIONADO_SEL,          //(15) 
		LUZ_GAVETAS_SEL,              //(16) 
		ESCENA_DERECHA_SEL,           //(17)
		ESCENA_IZQUIERDA_SEL,         //(18)
		LUZ_PIEL_SENSIBLE_SEL,        //(19)
		SUCCIONADOR_SEL,              //(20)
		INVERSOR_SEL,                 //(21) 
		ESTABLE_SEL,                  //(22) 
		CRITICO_SEL,                  //(23)
		GRAVE_SEL,                    //(24)
		LUZ_PUERTA_SEL,               //(25)
		NIVEL_EMERGENCIA_SEL,         //(26) 
		NIVEL_UNO_SEL,                //(27) 
		NIVEL_DOS_SEL,                //(28)
		NIVEL_TRES_SEL,               //(29) 
		DIRECCIONADOR_SEL,            //(30)
		SIRENA_SEL,                   //(31) 
		WAIL_SEL,                     //(32) 
		HI_LO_SEL,                    //(33)
		VOL_MENOS_SEL,                //(34)
		HORN_SEL,                     //(35) 
		YELP_SEL,                     //(36)
		PSHR_SEL,                     //(37)
		VOL_MAS_SEL,                  //(38)
		CRONOMETRO_SEL,               //(39) 
		REINICIAR_SEL,                //(40)
		DETENER_SEL,                  //(41)
		ESTRIBO_ON_SEL,               //(42)    
		ESTRIBO_FUERA_SEL,            //(43)
		ESTRIBO_DENTRO_SEL,           //(44)
		END_TRACE,                    //(45)   Stop del Estribo
		ACTIVE,                       //(46)   Estado activado
		NO_ACTIVE,                    //(47)   Estado desactivado 
		NO_STATUS,                    //(48)   Estado iniciale
    REVERSA_SEL,                  //(49)   Reversa seleccionado
		TOGGLE,                       //(50)   Cambio de estado de los leds de puerta abierta
		/* DE SENSORES */
		OUT_SENSOR_SEL,               //(51)   Sensor de Estribo fuera
		IN_SENSOR_SEL,	              //(52)   Sensor de Estribo Dentro
    LEFT_FLASHER_SEL,             //(53)   Direccional Izquierda
    RIGHT_FLASHER_SEL,            //(54)   Direccional Derecha
    STOP_FLASHER_SEL,             //(55)   Stop del Auto		
		/* DE LEDS DEL DIRECCIONADOR */
		LED_1_SEL,                    //(56)
		LED_2_SEL,                    //(57)
		LED_3_SEL,                    //(58)
		LED_4_SEL,                    //(59)
		LED_5_SEL,                    //(60)
		LED_6_SEL,                    //(61)
		LED_7_SEL,                    //(62)
		LED_8_SEL,                    //(63)
		LED_9_SEL,                    //(64)
		LED_10_SEL,                   //(65)
		ALL_LED_SEL,                  //(66)
		/* DEL MICROFONO */
		MICRO_SEL,                    //(67)
		CLAXON_SEL,                   //(68) 
		/* DEL TEST DE CC Y ARNES */
		SOLENOIDE_SEL,                //(69)
		RADIO_SEL,                    //(70)
		TOMA_12_SEL,                  //(71)
		AIRE_ACONDICIONADO_SEL,       //(72)
		VOLTAJE_TAB_DELANTERO_SEL,    //(73)
		PUERTA_TRASERA_SEL,           //(74)
    PUERTA_LATERAL_SEL,           //(75)		
		ASK_ONLINE,                   //(76) 
		/* De funcion manual DIRECCIONADOR */
    MANUAL_LEFT_FLASHER_SEL,      //(77)   Direccional Izquierda
    MANUAL_RIGHT_FLASHER_SEL,     //(78)   Direccional Derecha
    MANUAL_STOP_FLASHER_SEL,      //(79)   Stop del Auto		
		/* Aditamento del nivel de oxigeno */
		OXIGENO_SEL,                  //(80)
		/* Funciones adicionales */
	  FAROS_2_SEL,                  //(81) 
	  /* Funcion de efectos de direccionador */
	  EFECTOS_DIR_SEL,              //(82)
	  /* Funcion de secuencia de sirena */
	  SECUENCIA_SIRENA_SEL,         //(83)
	  /* Funcion de secuencia de sirena */
	  CARGA_BATERIAS_SEL,           //(84)
	  /* Funcion agregada de intermitentes */
		INTERMITENTES_FLASHER_SEL,    //(85)
		INTENSITY_UP_SEL,             //(86)
    INTENSITY_DOWN_SEL,	          //(87)	
		/* Funciones agregadas del tablero delantero */
		EMERGENCIA_DEL_REDUCIDO_SEL,  //(88)
		AUXILIAR_1_SEL,               //(89)
		AUXILIAR_2_SEL,               //(90)
		AUXILIAR_3_SEL,               //(91)
	  /* Funcion de BROADCAST */
	  BROADCAST = 255,              //(255)
	}FUNC_ENUM;

  /* Enumeracion de canBUS */
  typedef enum{
	  Init_canBUS_ENUM = 0,
	  BUZZER_OP = 100,
	  Puerta_Abierta,
		Y_STATE,
  }canBUS_ENUM;   

/** @endofgroup Prototipo de Funciones
  * @}
  */   
	
#endif /* __OSTHREADPROTOCOL_H */
