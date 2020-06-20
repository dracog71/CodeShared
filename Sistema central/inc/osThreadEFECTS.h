/**
  ******************************************************************************
  * @archivo  osThreadPWM
  * @autor    EDESIGN TEAM
  * @version  V1.0.0
  * @fecha    12-Febrero-2015
  * @brief    Archivo de configuracion e inicialización de PWM's
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

#ifndef _osThreadEFECTS_H_
#define _osThreadEFECTS_H_

/* Includes  ------------------------------------------------------------------*/
#include "osThreadDefines.h"

typedef enum{
	EFECTO_APAGADO = 0,
	EFECTO_1,
	EFECTO_2,
	EFECTO_3,
	EFECTO_4,
	EFECTO_5,
	EFECTO_6,
	EFECTO_7,
	EFECTO_8,
	EFECTO_9,
	EFECTO_10,
	EFECTO_11,
	EFECTO_12,
	EFECTO_13,
	EFECTO_14,
	EFECTO_FINAL,
	FASE1,
	FASE2,
	FASE3,
	FASE4,
	EFECTO_MANUAL_LEFT_FLASHER,
	EFECTO_MANUAL_RIGHT_FLASHER,
	EFECTO_MANUAL_STOP_FLASHER,
	EFECTO_LEFT_FLASHER,
	EFECTO_RIGHT_FLASHER,
	EFECTO_INTERMITENTES_FLASHER,
	EFECTO_STOP_FLASHER_ON,
	EFECTO_STOP_FLASHER_OFF,
	EFECTO_NIVEL_EMERGENCIA,
	EFECTO_EMERGENCIA_REINICIAR,
	/* De control de efectos */
	DIRECCIONAL_EFFECT_1,
	DIRECCIONAL_EFFECT_2,
	DIRECCIONAL_EFFECT_3,
	DIRECCIONAL_EFFECT_4,
	DIRECCIONAL_EFFECT_1B,
	DIRECCIONAL_EFFECT_2B,
	DIRECCIONAL_EFFECT_3B,
	DIRECCIONAL_EFFECT_4B,
	/*DIRECCIONAL_EFFECT_5,
	DIRECCIONAL_EFFECT_5B,
	DIRECCIONAL_EFFECT_6,
	DIRECCIONAL_EFFECT_6B,
	DIRECCIONAL_EFFECT_7,
	DIRECCIONAL_EFFECT_7B,
	DIRECCIONAL_EFFECT_8,
	DIRECCIONAL_EFFECT_8B,
	DIRECCIONAL_EFFECT_9,
	DIRECCIONAL_EFFECT_9B,
	DIRECCIONAL_EFFECT_10,
	DIRECCIONAL_EFFECT_10B,*/
	DIRECCIONAL_EFFECT_FINAL,
}EFECTOS_ENUM;

/* Exported functions ------------------------------------------------------- */
	/** @addtogroup Prototipo de Funciones
  * @{
  */ 
	
	 void osThreadEFECTS_Directional_Sequence_change(uint32_t FASE, uint32_t STATE);
	 void osThreadEFECTS_Directional_EFECTO_1(void);
	 void osThreadEFECTS_Directional_EFECTO_2(void);
	 void osThreadEFECTS_Directional_EFECTO_3(void);
	 void osThreadEFECTS_Directional_EFECTO_4(void);
	 void osThreadEFECTS_Directional_EFECTO_5(void);
	 void osThreadEFECTS_Directional_EFECTO_6(void);
	 void osThreadEFECTS_Directional_EFECTO_7(void);
	 void osThreadEFECTS_Directional_EFECTO_8(void);
	 void osThreadEFECTS_Directional_EFECTO_9(void);
	 void osThreadEFECTS_Directional_EFECTO_10(void);
	 void osThreadEFECTS_Directional_EFECTO_11(void);
	 void osThreadEFECTS_Directional_EFECTO_12(void);
	 void osThreadEFECTS_Directional_EFECTO_13(void);
	 void osThreadEFECTS_Directional_EFECTO_14(void);
	 void osThreadEFECTS_LED_CONTROL(uint32_t LED, uint32_t STATE);
	 
	 /* Efectos 1 */
	 void osThreadEFECTS_EFECTO_LEFT_1(void);
	 void osThreadEFECTS_EFECTO_RIGHT_1(void);
	 void osThreadEFECTS_EFECTO_INTERMITENTES_1(void);
	 void osThreadEFECTS_EFECTO_STOP_1(void);
	 void osThreadEFECTS_EFECTO_STOP_1B(void);
	 void osThreadEFECTS_EFECTO_STOP_FLASHER_ON_1(void);
	 
	 /* Efectos 2 */
	 void osThreadEFECTS_EFECTO_LEFT_2(void);
	 void osThreadEFECTS_EFECTO_RIGHT_2(void);
	 void osThreadEFECTS_EFECTO_INTERMITENTES_2(void);
	 void osThreadEFECTS_EFECTO_STOP_2(void);
	 void osThreadEFECTS_EFECTO_STOP_2B(void);
	 void osThreadEFECTS_EFECTO_STOP_FLASHER_ON_2(void);
	 
	 /* Efectos 3 */
	 void osThreadEFECTS_EFECTO_LEFT_3(void);
	 void osThreadEFECTS_EFECTO_RIGHT_3(void);
	 void osThreadEFECTS_EFECTO_INTERMITENTES_3(void);
	 void osThreadEFECTS_EFECTO_STOP_3(void);
	 void osThreadEFECTS_EFECTO_STOP_3B(void);
	 void osThreadEFECTS_EFECTO_STOP_FLASHER_ON_3(void);
	 
	 /* Efectos 4 */
	 void osThreadEFECTS_EFECTO_LEFT_4(void);
	 void osThreadEFECTS_EFECTO_RIGHT_4(void);
	 void osThreadEFECTS_EFECTO_INTERMITENTES_4(void);
	 void osThreadEFECTS_EFECTO_STOP_4(void);
	 void osThreadEFECTS_EFECTO_STOP_4B(void);
	 void osThreadEFECTS_EFECTO_STOP_FLASHER_ON_4(void);
	 
	 /* Efectos 5 */
	 void osThreadEFECTS_EFECTO_LEFT_5(void);
	 void osThreadEFECTS_EFECTO_RIGHT_5(void);
	 void osThreadEFECTS_EFECTO_INTERMITENTES_5(void);
	 void osThreadEFECTS_EFECTO_STOP_5(void);
	 void osThreadEFECTS_EFECTO_STOP_5B(void);
	 void osThreadEFECTS_EFECTO_STOP_FLASHER_ON_5(void);
	 
	 void osThreadEFECTS_EFECTO_STOP_FLASHER_OFF(void);
	 void osThreadEFECTS_DIRECTIONAL_EFFECTS_SELECTOR(void);
	 
/** @addtogroup Prototipo de Funciones
  * @}
  */ 

#endif /* _osThreadEFECTS_H_ */
