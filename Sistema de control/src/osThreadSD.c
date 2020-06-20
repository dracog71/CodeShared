/**
  ******************************************************************************
  * @file    sd_control.c
  * @author  EDESIGN TEAM
  * @version V1.0.0
  * @date    18-Junio-2015
  * @brief   Este archivo provee de un firmware con funciones para manejar la SD.
  *
 @verbatim
    
 ===============================================================================
                     ##### Como usar este driver #####
 ===============================================================================
    [..] Este driver provee funciones para :
            
       (#) Leer un archivo y obtener su buffer
			 
			 (#) Crear un archivo y re-escribir todo su contenido
                   
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

#include "osThreadSD.h"
#include "osThreadDefines.h"

#include "diskio.h"
#include "ff.h"
#include "stm32f4_discovery_sdio_sd.h"

FRESULT res;  /* Variable usada para obtener el resultado de Funciones en FatFs. ------*/
FILINFO fno;  /* Variable que obtiene los datos almacenados del sistema de ficheros. --*/
FIL fil;      /* Varioable que apunta al sistema de archivos. -------------------------*/
DIR dir;      /* Variable que apunta al directorio del fichero. -----------------------*/
FATFS fs32;   /* Variable usada para declarar el tipo de fichero. ---------------------*/
char* path;   /* Path al que apuntara FatFs. ------------------------------------------*/ 
char *fn;     /* Esta funcion es asumiendo que la cfg no se Unicode. ------------------*/

char Buffer[500];
UINT BytesRead;


/**
  * @brief  Usada para declarar el uso de archivos con nombres largos 
  * @param  Ninguno
  * @retval Ninguno
  */
#if _USE_LFN
    static char lfn[_MAX_LFN + 1];
    fno.lfname = lfn;
    fno.lfsize = sizeof lfn;
#endif

/**
  * @brief  Habilita el vector NVIC de Interrupcion para SDIO
  * @param  Ninguno
  * @retval Ninguno
  */
void osThreadSD_Init(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* Configura el prellenado de los bits de prioridad del NVIC */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

  NVIC_InitStructure.NVIC_IRQChannel = SDIO_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	/* Configura el vector de Interrupcion de falla en BUS BusFault_Handler */
	//SCB ->SHCSR |= SCB_SHCSR_BUSFAULTENA_Msk;
	//NVIC_SetPriority(BusFault_IRQn,1);
	
	/* Configura el vector de Interrupcion de falla en Manejo de Memoria MemoryManagement_Handler */
	//SCB ->SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk;
	//NVIC_SetPriority(MemoryManagement_IRQn,2);
	
	/* Configura el vector de Interrupcion de falla en Error de Uso UsageFault_Handler */
	//SCB ->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk;
	//NVIC_SetPriority(UsageFault_IRQn,3);
}
/**
  * @brief  Funcion de lectura de archivos en directorio FAT32
  * @param  String del archivo a leer
  * @retval uint16_t valor total del buffer, SD_File_Array [] buffer de datos 
  */
void osThreadSD_FILE_READ(char *File, uint32_t SELECTED,uint32_t STATE){
	
	  memset(&fs32, 0, sizeof(FATFS));
	
	  res = f_mount(0, &fs32); printf("Valor de f_mount %d\r\n",res);
	
	  res = f_open(&fil, File, FA_READ); printf("Valor de f_open %d\r\n",res); 
	
	  if (res == FR_OK) { 
			
			res = f_read(&fil, Buffer, sizeof(Buffer),&BytesRead);
	
		  //printf("Buffer de lectura %s\r\n",Buffer), 
			
		  osThreadSD_LCDText(Buffer) ,  res = f_close(&fil);
			
		}

		else{
			
		  printf("El archivo %s no se pudo leer o no existe\r\n",File);
		
	    osThreadSD_BackUp(SELECTED,STATE);
			
		}
		
		res = f_close(&fil);
			
}

/**
  * @brief  Backup por falla de SD
  * @param  String del archivo a leer
  * @retval Ninguno
  */
void osThreadSD_BackUp(uint32_t SELECTED,uint32_t STATE){
		/* Incremento de variable por timer */
	switch (SELECTED){
		
		case ESTABLE_SEL:
      osThreadLCD16x2_Puts(0, 0, "    Estable     ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case CRITICO_SEL:
      osThreadLCD16x2_Puts(0, 0, "    Critico     ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case GRAVE_SEL:
      osThreadLCD16x2_Puts(0, 0, "     Grave      ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case LUZ_BAJA_SEL:
      osThreadLCD16x2_Puts(0, 0, "    Luz Baja    ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case EXTRACTOR_ALTA_SEL:
      osThreadLCD16x2_Puts(0, 0, "    Extractor   ");
      osThreadLCD16x2_Puts(0, 1, "      Alto      ");
			break;
		
		case EXTRACTOR_BAJA_SEL:
      osThreadLCD16x2_Puts(0, 0, "    Extractor   ");
      osThreadLCD16x2_Puts(0, 1, "      Bajo      ");
			break;
		
		case LUZ_MESA_SEL:
      osThreadLCD16x2_Puts(0, 0, "   Luz de mesa  ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case LUZ_ALTA_SEL:
      osThreadLCD16x2_Puts(0, 0, "    Luz Alta    ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case VENTILADOR_ALTA_SEL:
      osThreadLCD16x2_Puts(0, 0, "   Ventilador   ");
      osThreadLCD16x2_Puts(0, 1, "      Alto      ");
			break;
		
		case VENTILADOR_BAJA_SEL:
      osThreadLCD16x2_Puts(0, 0, "   Ventilador   ");
      osThreadLCD16x2_Puts(0, 1, "      Bajo      ");
			break;
		
		case LUZ_GAVETAS_SEL:
      osThreadLCD16x2_Puts(0, 0, "    Luz de      ");
      osThreadLCD16x2_Puts(0, 1, "    gavetas     ");
			break;
		
		case LUZ_PIEL_SENSIBLE_SEL:
      osThreadLCD16x2_Puts(0, 0, "   Luz de Piel  ");
      osThreadLCD16x2_Puts(0, 1, "    sensible    ");
			break;
		
		case CRONOMETRO_SEL:
      osThreadLCD16x2_Puts(0, 0, "   CRONOMETRO   ");
      osThreadLCD16x2_Puts(0, 1, "       ON       ");
			break;
		
		case REINICIAR_SEL:
      osThreadLCD16x2_Puts(0, 0, "    Iniciar     ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case DETENER_SEL:
      osThreadLCD16x2_Puts(0, 0, " Detener/Reest  ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case SUCCIONADOR_SEL:
      osThreadLCD16x2_Puts(0, 0, "   Succionador  ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case ESTRIBO_ON_SEL:
      osThreadLCD16x2_Puts(0, 0, "    Estribo     ");
      osThreadLCD16x2_Puts(0, 1, "      ON        ");
			break;
		
		case ESTRIBO_FUERA_SEL:
      osThreadLCD16x2_Puts(0, 0, "    Estribo     ");
      osThreadLCD16x2_Puts(0, 1, "     Fuera      ");
			break;
		
		case ESTRIBO_DENTRO_SEL:
      osThreadLCD16x2_Puts(0, 0, "    Estribo     ");
      osThreadLCD16x2_Puts(0, 1, "     Dentro     ");
			break;
		
		case INVERSOR_SEL:
      osThreadLCD16x2_Puts(0, 0, "    Inversor    ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case NIVEL_EMERGENCIA_SEL:
      osThreadLCD16x2_Puts(0, 0, "     Niveles    ");
      osThreadLCD16x2_Puts(0, 1, "    Emergencia  ");
			break;
		
		case NIVEL_UNO_SEL:
      osThreadLCD16x2_Puts(0, 0, "      Nivel     ");
      osThreadLCD16x2_Puts(0, 1, "        I       ");
			break;
		
		case NIVEL_DOS_SEL:
      osThreadLCD16x2_Puts(0, 0, "      Nivel     ");
      osThreadLCD16x2_Puts(0, 1, "       I I      ");
			break;
		
		case NIVEL_TRES_SEL:
      osThreadLCD16x2_Puts(0, 0, "      Nivel     ");
      osThreadLCD16x2_Puts(0, 1, "       III      ");
			break;
		
		case DIRECCIONADOR_SEL:
      osThreadLCD16x2_Puts(0, 0, "  Direccionador ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case ESCENA_DERECHA_SEL:
      osThreadLCD16x2_Puts(0, 0, "     Escena     ");
      osThreadLCD16x2_Puts(0, 1, "     Derecha    ");
			break;
		
		case ESCENA_TRASERA_SEL:
      osThreadLCD16x2_Puts(0, 0, "     Escena     ");
      osThreadLCD16x2_Puts(0, 1, "     Trasera    ");
			break;
		
		case ESCENA_IZQUIERDA_SEL:
      osThreadLCD16x2_Puts(0, 0, "     Escena     ");
      osThreadLCD16x2_Puts(0, 1, "    Izquierda   ");
			break;
		
		case PERIMETRAL_SEL:
      osThreadLCD16x2_Puts(0, 0, "  Perimetrales  ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case TORRETA_SEL:
      osThreadLCD16x2_Puts(0, 0, "    Torreta     ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case ESTROBOS_SEL:
      osThreadLCD16x2_Puts(0, 0, "    Estrobos    ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case FAROS_SEL:
      osThreadLCD16x2_Puts(0, 0, "     Faros      ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case REVERSA_SEL:
      osThreadLCD16x2_Puts(0, 0, "    Reversa     ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case SIRENA_SEL:
      osThreadLCD16x2_Puts(0, 0, "     Sirena     ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case WAIL_SEL:
      osThreadLCD16x2_Puts(0, 0, "    W A I L     ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case HI_LO_SEL:
      osThreadLCD16x2_Puts(0, 0, "    H I - L O   ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case VOL_MENOS_SEL:
      osThreadLCD16x2_Puts(0, 0, "    Volumen     ");
      osThreadLCD16x2_Puts(0, 1, "     menos      ");
			break;
		
		case HORN_SEL:
      osThreadLCD16x2_Puts(0, 0, "    H O R N     ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case YELP_SEL:
      osThreadLCD16x2_Puts(0, 0, "    Y E L P     ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case PSHR_SEL:
      osThreadLCD16x2_Puts(0, 0, "    P H S R     ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case VOL_MAS_SEL:
      osThreadLCD16x2_Puts(0, 0, "    Volumen     ");
      osThreadLCD16x2_Puts(0, 1, "      mas       ");
			break;
		
		case MANUAL_LEFT_FLASHER_SEL:
      osThreadLCD16x2_Puts(0, 0, "   Direccional  ");
      osThreadLCD16x2_Puts(0, 1, "    Izquierda   ");
			break;
		
		case MANUAL_RIGHT_FLASHER_SEL:
      osThreadLCD16x2_Puts(0, 0, "   Direccional  ");
      osThreadLCD16x2_Puts(0, 1, "     Derecha    ");
			break;
		
		case MANUAL_STOP_FLASHER_SEL:
      osThreadLCD16x2_Puts(0, 0, "     S T O P    ");
      osThreadLCD16x2_Puts(0, 1, "                ");
			break;
		
		case SOLENOIDE_SEL:
			if(STATE == ACTIVE){
      osThreadLCD16x2_Puts(0, 0, "    SOLENOIDE   ");
      osThreadLCD16x2_Puts(0, 1, "     ACTIVADO   ");
			}
			else if (STATE == NO_ACTIVE){
      osThreadLCD16x2_Puts(0, 0, "    SOLENOIDE   ");
      osThreadLCD16x2_Puts(0, 1, "   DESACTIVADO  ");
			}
			break;
		
		default:
			break;
	}
	
}
/**
  * @brief  Funcion de actualizacion de pantalla
  * @param  uint16_t valor total del buffer, SD_File_Array [] buffer de datos 
  * @retval Ninguno
  */
void osThreadSD_LCDText(char LCD_Text[500]){
	
	uint32_t i,j,k,w;
	char Volatile_Text[16];
	
	/* Limpieza del LCD */
	osThreadLCD16x2_Puts(0, 0, "                ");
	osThreadLCD16x2_Puts(0, 1, "                ");
	
	/* Se obtiene el principio de la primer cadena */
	for(i=0;i<=300;i++){
		if(LCD_Text[i]=='"') {
			i++;
			j=i;
			i=300;
		}
	}

	/* Se obtiene la cadena a imprimierse en la primer linea */
	for(i=j,w=0;i<=j+15;i++,w++)
	  Volatile_Text[w]= LCD_Text[i];

	/* Se envia la cadena q mostrar */
	osThreadLCD16x2_Puts(0,0,Volatile_Text);

	/* Se obtiene el principio de la segunda cadena */
	for(k=i,j=0;k<=500;k++){
		if(LCD_Text[k]=='"') j++;
		if(j==2) {
			k++;
			i=k;
			k=500;
		}
	}

	/* Se obtiene la cadena a imprimierse en la primer linea */
	for(j=i,w=0;j<=i+15;j++,w++)
		Volatile_Text[w]= LCD_Text[j];

	/* Se envia la cadena q mostrar */
	osThreadLCD16x2_Puts(0, 1,Volatile_Text);
	

}
/******************* (C) COPYRIGHT 2015 EDESIGN JMLG *****FIN DE ARCHIVO****/
