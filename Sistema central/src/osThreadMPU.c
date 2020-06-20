/**
  ******************************************************************************
  * @file    osThreadMPU.c
  * @author  EDESIGN TEAM
  * @version V1.0.0
  * @date    10-Octubre-2016
  * @brief   Este archivo provee de un firmware con funciones para manejar el MPU.
  *
 @verbatim
    
 ===============================================================================
                     ##### Como usar este driver #####
 ===============================================================================
    [..] Este driver provee funciones para :
            
       (#) Proteccion contra lectura de la memoria
	
                   
 @endverbatim      
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 EDESIGN DE MEXICO</center></h2>
  *
	* EL PRESENTE SOFTWARE ES SOLO PARA GUIARSE CON INFORMACION DE CODIGO QUE APUNTA
	* A FUNCIONES YA IMPLEMENTADAS PARA AHORRAR TIEMPO DE PROGRAMACION .
	* COMO RESULTADO EDESIGN AHORRARA TIEMPO DE DESARROLLO.
	* EDESIGN NO SE HACE RESPONSABLE POR EL DAÑO DIRECTO, INDIRECTO O SECUENCIAL
	* DE ESTE CODIGO SI ES USADO SIN AUTORIZACION EXPLICITA DE LA EMPRESA.
  *
  ******************************************************************************
  */

/* Inclusiones-------------------------------------------------------------------------*/

#include "osThreadMPU.h"

/**
  * @brief  Configura la Proteccion contra lectura y escritura MPU (Memory Protection Unit)
  * @param  None
  * @retval None
  */
void SetMPU(uint32_t SEL){
	if (!FLASH_OB_GetRDP () == SET){
	  FLASH_OB_Unlock ();
		
		/* Selecciona el nivel de proteccion */
		switch (SEL){
		  case 0:
				FLASH_OB_RDPConfig(OB_RDP_Level_0);
		 	  break;
				 
			case 1:
				FLASH_OB_RDPConfig(OB_RDP_Level_1);
				break;
				 
			case 2:
				//FLASH_OB_RDPConfig(OB_RDP_Level_2);
				break;
				 
			default:
				break;
		}
			 
	  FLASH_OB_BORConfig(OB_BOR_LEVEL3);
	  FLASH_OB_Launch();
	  FLASH_OB_Lock ();
	}
}

/******************* (C) COPYRIGHT 2015 EDESIGN JMLG *****FIN DE ARCHIVO****/
