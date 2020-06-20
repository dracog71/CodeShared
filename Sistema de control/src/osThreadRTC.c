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

#include "osThreadRTC.h"  

/* Private variables ---------------------------------------------------------*/
RTC_TimeTypeDef  RTC_TimeStructure;
RTC_InitTypeDef  RTC_InitStructure;
RTC_DateTypeDef  RTC_DateStructure;
 
__IO uint32_t uwAsynchPrediv = 0;
__IO uint32_t uwSynchPrediv = 0;

/* Estructura para valores de tablero delantero */
extern TAB_TRA_STRUCT TAB_TRA;

/**
  * @brief  Configura el Reloj en Tiempo Real)
  * @param  None
  * @retval None
  */
void osThreadRTC_Enable_RTC(){
  
  /* Enable the PWR clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);

  /* Allow access to RTC */
  PWR_BackupAccessCmd(ENABLE);
    
  /* Enable the LSE OSC */
  RCC_LSEConfig(RCC_LSE_ON);

  /* Wait till LSE is ready */  
  while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET)
  {
  }

  /* Select the RTC Clock Source */
  RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
  /* ck_spre(1Hz) = RTCCLK(LSE) /(uwAsynchPrediv + 1)*(uwSynchPrediv + 1)*/
  uwSynchPrediv = 0xFF;
  uwAsynchPrediv = 0x7F;

  /* Enable the RTC Clock */
  RCC_RTCCLKCmd(ENABLE);

  /* Wait for RTC APB registers synchronisation */
  RTC_WaitForSynchro();
  
  /* Configure the RTC data register and RTC prescaler */
  RTC_InitStructure.RTC_AsynchPrediv = uwAsynchPrediv;
  RTC_InitStructure.RTC_SynchPrediv = uwSynchPrediv;
  RTC_InitStructure.RTC_HourFormat = RTC_HourFormat_24;
  RTC_Init(&RTC_InitStructure);
  
  /* Set the date: Friday January 11th 2013 */
  RTC_DateStructure.RTC_Year = 0x13;
  RTC_DateStructure.RTC_Month = RTC_Month_January;
  RTC_DateStructure.RTC_Date = 0x11;
  RTC_DateStructure.RTC_WeekDay = RTC_Weekday_Saturday;
  RTC_SetDate(RTC_Format_BCD, &RTC_DateStructure);
  
  /* Set the time to 05h 20mn 00s AM */
  RTC_TimeStructure.RTC_H12     = RTC_H12_AM;
  RTC_TimeStructure.RTC_Hours   = 0x05;
  RTC_TimeStructure.RTC_Minutes = 0x20;
  RTC_TimeStructure.RTC_Seconds = 0x00; 
  
  RTC_SetTime(RTC_Format_BCD, &RTC_TimeStructure);   
  
  /* Indicator for the RTC configuration */
  RTC_WriteBackupRegister(RTC_BKP_DR0, 0x32F2);	
 
   /* Enable the RTC Clock */
  RCC_RTCCLKCmd(DISABLE);
}

/**
  * @brief  Display the current time.
  * @param  None
  * @retval None
  */
void osThreadRTC_TimeShow(void)
{
  char showtime[50] = {0};
	
  /* Get the current Time */
  RTC_GetTime(RTC_Format_BIN, &RTC_TimeStructure);
	
	if((RTC_TimeStructure.RTC_Hours   != TAB_TRA.CRONOMETRO_HR_T ) || 
		 (RTC_TimeStructure.RTC_Minutes != TAB_TRA.CRONOMETRO_MIN_T) ||
	   (RTC_TimeStructure.RTC_Seconds != TAB_TRA.CRONOMETRO_SEG_T)){
			 
			 
			printf("Entrada a actualizacio\r\n");
			 
		/* Se transfieren los nuevos valores */	 
		TAB_TRA.CRONOMETRO_HR_T  = RTC_TimeStructure.RTC_Hours;
		TAB_TRA.CRONOMETRO_MIN_T = RTC_TimeStructure.RTC_Minutes;
		TAB_TRA.CRONOMETRO_SEG_T = RTC_TimeStructure.RTC_Seconds;
	
    /* Display time Format : hh:mm:ss */
    sprintf(showtime,"   -%0.2d:%0.2d:%0.2d-",RTC_TimeStructure.RTC_Hours, RTC_TimeStructure.RTC_Minutes, RTC_TimeStructure.RTC_Seconds);
	
	  /* Se habilita la pantalla */
	  TAB_TRA.CRONOMETRO_SEG = NO_ACTIVE;
	
	  /* Muestreo en pantalla */
	  osThreadLCD16x2_Puts(0, 0, "   CRONOMETRO   ");
    osThreadLCD16x2_Puts(0, 1, showtime);
	
	  /* Se deshabilita la pantalla */
	  TAB_TRA.CRONOMETRO_SEG = ACTIVE;
	}
}

/******************* (C) COPYRIGHT 2015 EDESIGN JMLG *****FIN DE ARCHIVO****/
