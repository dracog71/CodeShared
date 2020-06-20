/**
  ******************************************************************************
  * @archivo  MASTER WORKSPACE
  * @autor    EDESIGN TEAM
  * @version  V1.0.0
  * @fecha    17-Junio-2015
  * @brief    Sd_Control
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

/* Definicion para prevenir una inclusion recursiva --------------------------*/

#ifndef __OSTHREADSD_H
#define __OSTHREADSD_H

/* Includes ------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stm32f4xx.h"


/** @addtogroup Definciones Internas
  * @{
  */ 	
	
/**  
  * @}
  */ 
	
/* Definiciones privadas-------------------------------------------------------*/

    void osThreadSD_FILE_READ(char *File, uint32_t SELECTED,uint32_t STATE);
    void osThreadSD_Init(void);
		void osThreadSD_BackUp(uint32_t SELECTED,uint32_t STATE);
    void osThreadSD_LCDText(char LCD_Text[500]);
	
#endif /* __SD_CONTROL_H */

/******************* (C) COPYRIGHT 2015 EDESIGN JMLG *****FIN DE ARCHIVO****/
