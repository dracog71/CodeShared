/**
******************************************************************************
* @archivo  MASTER WORKSPACE
* @autor    EDESIGN TEAM
* @version  V1.0.0
* @fecha    ____________
* @brief    Cuerpo principal MAIN
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

/* Inclusiones------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"     // Todo lo relacionado con GPIO's
#include "stm32f4xx_rcc.h"      // Todo lo relacionado con los relojes de perifericos
/* Includes usados para imprimir en pantalla un mensaje (debug) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Include de conmutador de cabeceras y definiciones globales dinamicas */
#include "osThreadDefines.h"


void mainDelay(__IO uint32_t nCount);


#define ITM_Port8(n)    (*((volatile unsigned char *)(0xE0000000+4*n)))  // Direccion de conversion 8 bits a 32 bits
#define ITM_Port16(n)   (*((volatile unsigned short*)(0xE0000000+4*n)))  // Direccion de conversion 16 bits a 32 bits
#define ITM_Port32(n)   (*((volatile unsigned long *)(0xE0000000+4*n)))  // Direccion de conversion 32 bits a 32 bits

#define DEMCR           (*((volatile unsigned long *)(0xE000EDFC)))      // Direccion del puerto a usar
#define TRCENA          0x01000000                                       // Numero del puerto a usar 

struct __FILE { int handle; };    // Estructura que maneja la cadena
FILE __stdout;                    // Tipo de salida a pantalla
FILE __stdin;                     // Tipo de entrada a funcion

int fputc(int ch, FILE *f) {      // se pasa como argumento al cadena a enviar   
	if (DEMCR & TRCENA) {         // Funcion que revisa si toda la cadena ha sido enviada, de otra forma
		while (ITM_Port32(0) == 0);  // envia el siguiente caracter hasta que el buffer se vacia
		ITM_Port8(0) = ch;           // caracter a enviar

	}
	return(ch);    // regresa 0 si se envio de forma correcta 1 si la comunicacion fallo 
}
int main(void){
	/*!< En este punto las propiedades del microcontrolador ya fueron configuradas,
	esto se hace a través de la funcion SystemInit() que es llamada desde el archivo
	startup (startup_stm32f4xx.s) antes de apuntar a la aplicacion main.
	Para modificar por default las configuracionies de la funcionm SystemInit(), refierase al
	archivo system_stm32f4xx.c
	*/
	
	/* ITM Port Message */
	printf("Inicio Correcto de startup_stm32f4xx.s\r\n");
  
	/* Inicializacion y Estado Inicial de perifericos */
	osUserThread_InitConf();
	
	/* ITM Port Message */
	printf("Configuraciones correctas\r\n");
	
  /* Loop Infinito */	
	while (1)
	{
		/* Funcion periodica */
		osUserThread_vPeriodicTask();
		
		//osThreadRTC_TimeShow();
		//mainDelay(5000000);
		
	}
}


/**
  * @brief  Delay 
  * @param  Ninguno
  * @retval Ninguno
  */
void mainDelay(__IO uint32_t nCount)
{	
    while(nCount--);
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reporta el nombre del archivo y la linea del archivo donde
  * el parametro "assert" fue activado
  * @param  archivo: puntero al nombre del archivo 
  * @param  line: linea del error "assert"
  * @retval ninguno
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* El usuario puede agregar su propia implementacion de reporte de nombre de archivo y linea,
     ejemplo: printf("Valor de parametro incorrecto : archivo %s en linea %d\r\n", file, line) */

  /* Loop infinito */

  while (1)
  {
  }
}
#endif
/******************* (C) COPYRIGHT 2015 EDESIGN  *****FIN DE ARCHIVO****/
